/*
  xsns_114_mt6701.ino - MT6701 Tasmota support for Hall based angle position sensor

  inspired by
  https://github.com/S-LABc/MT6701-Arduino-Library
  Copyright (c) 2022 Roman Sklyar S-LAB (MIT License)

  Copyright (C) 2023  Lukas Zimmermann

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef USE_I2C
#ifdef USE_MT6701
/*********************************************************************************************\
 * MT6701 - Hall based rotary position sensor from MagnTek
 * https://www.magntek.com.cn/upload/MT6701_Rev.1.8.pdf
 *
 * This sensor offers an angle reading of an applied magnetic field with a resolution of 14 bits.
 * The sensor can output an incremental encoder signal, an analog angle output value or a PWM
 * encoded angle value. Depending on the chip package (the number of pins) it offers varying
 * options.
 * This driver is meant to only read the angle via I2C so the other output options are not
 * relevant and are not implemented.
 * As this driver communicates with the sensor through I2C the mode pin of the sensor chip
 * needs to be set to high (or left open).
 *
 * The sensor can be configured to increase angle value when turning clockwise or
 * counterclockwise.
 *
 * The sensor can detect rapid changes in absolute magnetic field as it happens when a magnet
 * is moved nearer of further away. This can be used as a push button signal.
 * As this push button signal is output to a pin and cannot be read out via I2C it is not
 * used here.
 * It would be possible though to connect the push button output to a GPIO pin and treat it
 * as a normal switch.
 *
 * Settings can be written to an integrated EEPROM. But for this to work properly a supply
 * voltage from 4.5 to 5 V is needed. In the Tasmota environment a supply voltage of 3.3 V
 * is very probably used, in which case the EEPROM programming should not be used.
 * It is unknown what happens if EEPROM is programmed with a supply voltage below 4.5 V.
 * This probably may destroy the factory programmed values in EEPROM which are not meant
 * to be changed by users.
 *
 * This driver is intended to make use of an MT6701 sensor to sense the wind direction in
 * a wind vane. So it reports the measured angle as "WindDir" and does some statistics to
 * dampen the variations in wind direction.
 *
 * I2C Address: 0x06 (the datasheet mentions that it may be programmed to use 0x46 instead
 *                    which would collide with PCA9685, XI2C_1.
 *                    0x46 address is not supported here.)
 *
\*********************************************************************************************/

#define XSNS_114                                114
#define XI2C_86                                 86        // See I2CDEVICES.md

#define MT6701_ADDRESS                          (0x06)    // 0000110

#define D_WINDDIR_NAME "WindDir"

// strings for use in message generation
// should go to tasmota/include/i18n.h and tasmota/language/en_GB.h
#define D_JSON_ANGLE "Angle"
const char JSON_SNS_ANGLE[] PROGMEM = ",\"%s\":{\"" D_JSON_ANGLE "\":%d}";

#define D_ANGLE "Angle"
//#define D_UNIT_ANGLE "deg"
#define D_LOG_MT6701 "MT6701: "          // MT6701 sensor

#ifdef USE_WEBSERVER
const char HTTP_SNS_ANGLE[] PROGMEM =
   "{s}" D_WINDDIR_NAME " %s " D_ANGLE "{m}%d " D_UNIT_ANGLE "{e}";
#endif // USE_WEBSERVER

const char MT6701_CONF_RESPONSE[] PROGMEM = "{\"MT6701_CONF\":{\"%s\":%s}}";

const char mt6701_name[] = D_WINDDIR_NAME;

/*=== Sensor register addresses ===*/
// Angle Data Register
#define MT6701_I2C_ANGLE_DATA_REG_H         0x03
#define MT6701_I2C_ANGLE_DATA_REG_L         0x04
/* not implemented
// UVW_MUX (on QFN package only)
const uint8_t MT6701_I2C_EEPROM_UVW_MUX_REG = 0x25;
const uint8_t MT6701_I2C_EEPROM_UVW_MUX_BIT = 7;
// ABZ_MUX
const uint8_t MT6701_I2C_EEPROM_ABZ_MUX_REG = 0x29;
const uint8_t MT6701_I2C_EEPROM_ABZ_MUX_BIT = 6;
*/
// DIR
#define MT6701_I2C_EEPROM_DIR_REG  0x29
#define MT6701_I2C_EEPROM_DIR_BIT  1
/* not implemented
// UVW_RES
const uint8_t MT6701_I2C_EEPROM_UVW_RES_REG   = 0x30;
const uint8_t MT6701_I2C_EEPROM_UVW_MUX_BIT_S = 4;
// ABZ_RES
const uint8_t MT6701_I2C_EEPROM_ABZ_RES_REG_H = 0x30;
const uint8_t MT6701_I2C_EEPROM_ABZ_RES_REG_L = 0x31;
const uint8_t MT6701_I2C_EEPROM_ABZ_MUX_BIT_S = 0;
// HYST
const uint8_t MT6701_I2C_EEPROM_HYST_REG_H = 0x32;
const uint8_t MT6701_I2C_EEPROM_HYST_REG_L = 0x34;
// Z_PULSE_WIDTH
const uint8_t MT6701_I2C_EEPROM_Z_PULSE_WIDTH_REG   = 0x32;
const uint8_t MT6701_I2C_EEPROM_Z_PULSE_WIDTH_BIT_S = 4;
// ZERO
#define MT6701_I2C_EEPROM_ZERO_REG_H  0x32
#define MT6701_I2C_EEPROM_ZERO_REG_L  0x33
// PWM_FREQ
const uint8_t MT6701_I2C_EEPROM_PWM_FREQ_REG = 0x38;
const uint8_t MT6701_I2C_EEPROM_PWM_FREQ_BIT = 7;
// PWM_POL
const uint8_t MT6701_I2C_EEPROM_PWM_POL_REG = 0x38;
const uint8_t MT6701_I2C_EEPROM_PWM_POL_BIT = 6;
// OUT_MODE
const uint8_t MT6701_I2C_EEPROM_OUT_MODE_REG = 0x38;
const uint8_t MT6701_I2C_EEPROM_OUT_MODE_BIT = 5;
// A_START
const uint8_t MT6701_I2C_EEPROM_A_START_REG_H = 0x3E;
const uint8_t MT6701_I2C_EEPROM_A_START_REG_L = 0x3F;
// A_STOP
const uint8_t MT6701_I2C_EEPROM_A_STOP_REG_H = 0x3E;
const uint8_t MT6701_I2C_EEPROM_A_STOP_REG_L = 0x40;
const uint8_t MT6701_I2C_EEPROM_A_STOP_BIT_S = 4;
*/
// 7.2 EEPROM Programming
#define MT6701_I2C_EEPROM_PROG_KEY_REG    0x09
#define MT6701_I2C_EEPROM_PROG_KEY_VALUE  0xB3
#define MT6701_I2C_EEPROM_PROG_CMD_REG    0x0A
#define MT6701_I2C_EEPROM_PROG_CMD_VALUE  0x05


uint8_t mt6701_found = 0;
uint8_t mt6701_valid = 0;
uint16_t mt6701_raw_angle;
float mt6701_rad_angle = 0;
float mt6701_deg_angle = 0;
float mt6701_avg_rad_angle = 0;
float mt6701_avg_deg_angle = 0;
float  mt6701_avg_sigma = 0;

// for Yamartino directional statistics method
float mt6701_sum_sin = 0;
float mt6701_sum_cos = 0;
uint32_t mt6701_sample_cnt = 0;
uint32_t mt6701_sample_num = 0;

#define RAD_TO_DEG 57.295779513082320876798154814105

/*****************************************************************************
* Check if sensor is connected on I2C address.
* There is no secure way to find out whether the device responding under
* MT6701_ADDRESS is really an MT6701, so we only check whether there is a
* response when trying to read from some registers.
* An option would be to try to write to some of the registers and check whether
* the written data can be read back. Not shure whether that would be helpful.
*/
bool mt6701Detect(void) {
  uint8_t high_byte;
  uint8_t low_byte;
  if (I2cValidRead8(&high_byte, MT6701_ADDRESS, MT6701_I2C_ANGLE_DATA_REG_H)
      && I2cValidRead8(&low_byte, MT6701_ADDRESS, MT6701_I2C_ANGLE_DATA_REG_L)) {
    mt6701_found = true;
    // Log sensor found
    AddLog(LOG_LEVEL_INFO, PSTR(D_LOG_I2C D_LOG_MT6701 D_FOUND_AT " 0x%X"), MT6701_ADDRESS);

    // do some initializations to the sensor here
    // maybe setting the positive rotation direction.

    return true;

  } else {
    mt6701_found = false;
    AddLog(LOG_LEVEL_INFO, PSTR(D_LOG_I2C D_LOG_MT6701 "No sensor found"));

    return false;
  }
}

/*****************************************************************************
* Sample MT6701 sensor
*/
bool mt6701Read_angle(void) {
  uint8_t high_byte;
  uint8_t low_byte;

  // Read the two raw angle registers
  if (I2cValidRead8(&high_byte, MT6701_ADDRESS, MT6701_I2C_ANGLE_DATA_REG_H)
      && I2cValidRead8(&low_byte, MT6701_ADDRESS, MT6701_I2C_ANGLE_DATA_REG_L)) {
    mt6701_raw_angle = (high_byte << 6) | (low_byte >> 2);
    mt6701_deg_angle = float(mt6701_raw_angle) * 360.0f / 16384.0f; // sensor full rotation is 2^14
    mt6701_valid = 1;
    return true;
  } else {
    mt6701_valid = 0;
    return false;
  }
}


/*****************************************************************************
* Sample MT6701 sensor whenever a FUNC_EVERY_SECOND callback arrives,
* Sum up the angle sample's sine and cosine for averaging using the
* Yamartino method.
*/
void mt6701EverySecond(void) {
  if (mt6701Read_angle()) {
    /*
    if (mt6701_angle > mt6701_max_angle) mt6701_max_angle = mt6701_angle;
    if (mt6701_angle < mt6701_min_angle) mt6701_min_angle = mt6701_angle;
    */
    mt6701_rad_angle = mt6701_raw_angle * (float)f_twopi / 16384.0f; // sensor full rotation is 2^14
    mt6701_sum_sin += sin(mt6701_rad_angle);
    mt6701_sum_cos += cos(mt6701_rad_angle);
    mt6701_sample_cnt++;
    AddLog(LOG_LEVEL_DEBUG, PSTR(D_LOG_MT6701 "%d"), mt6701_raw_angle);
  }

  if (TasmotaGlobal.uptime % 60 == 0) {
    // every minute
    // Filter multiple samples to get an average wind direction using Yamartino
    // method, see https://en.wikipedia.org/wiki/Yamartino_method
    // also see Directional statistics article:
    // https://en.wikipedia.org/wiki/Directional_statistics

    // calculate mean
    mt6701_avg_rad_angle = atan2(mt6701_sum_cos / mt6701_sample_cnt, mt6701_sum_sin / mt6701_sample_cnt);
    mt6701_avg_deg_angle = mt6701_avg_rad_angle * (float)RAD_TO_DEG;
    // calculate variance
    float eps = sqrt(1.0f - (sq(mt6701_sum_sin) + sq(mt6701_sum_cos)));
    mt6701_avg_sigma = asin(eps) * (1.0f + (2.0f / sqrt(3.0f) - 1.0f) * pow(eps, 3.0f));
    
    // reset statistics
    mt6701_sample_num = mt6701_sample_cnt;
    mt6701_sample_cnt = 0;
    mt6701_sum_cos = 0;
    mt6701_sum_sin = 0;

    // TODO: make dependent of Settings->tele_period instead of sending
    //       every minute.
    //       Maybe send whenever wind direction changes more than a certain
    //       amount
    MqttPublishTeleperiodSensor();
  }
}

/*****************************************************************************
* Produce JSON or HTTP string and send to respective network channel.
*/
void mt6701Show(bool json) {
  //char angle_str[8];
  //char moment_angle_str[8];
  char windrose_str[4];

  if (mt6701_valid) {
    
    if (json) {
      ResponseAppend_P(PSTR(",\"" D_WINDDIR_NAME "\":{\"" D_JSON_ANGLE "\":{\"MeanDir\":%2_f,\"Variance\":%4_f,\"SampleCnt\":%d,\"MomentDir\":%2_f}}"),
                       mt6701_avg_deg_angle, sq(mt6701_avg_sigma), mt6701_sample_num, mt6701_deg_angle);

#ifdef USE_WEBSERVER
    } else {
      // show value for angle on web-server
      if ((mt6701_avg_deg_angle >= 360 - 22.5) || mt6701_avg_deg_angle < 22.5) {
        strcpy(windrose_str, "N");
      } else if (mt6701_avg_deg_angle >= 22.5 && mt6701_avg_deg_angle < 90 - 22.5) {
        strcpy(windrose_str, "NE");
      } else if (mt6701_avg_deg_angle >= 90 - 22.5 && mt6701_avg_deg_angle < 90 + 22.5) {
        strcpy(windrose_str, "E");
      } else if (mt6701_avg_deg_angle >= 135 - 22.5 && mt6701_avg_deg_angle < 135 + 22.5) {
        strcpy(windrose_str, "SE");
      } else if (mt6701_avg_deg_angle >= 180 - 22.5 && mt6701_avg_deg_angle < 180 + 22.5) {
        strcpy(windrose_str, "S");
      } else if (mt6701_avg_deg_angle >= 225 - 22.5 && mt6701_avg_deg_angle < 225 + 22.5) {
        strcpy(windrose_str, "SW");
      } else if (mt6701_avg_deg_angle >= 270 - 22.5 && mt6701_avg_deg_angle < 270 + 22.5) {
        strcpy(windrose_str, "W");
      } else if (mt6701_avg_deg_angle >= 315 - 22.5 && mt6701_avg_deg_angle < 315 + 22.5) {
        strcpy(windrose_str, "NW");
      }

      WSContentSend_PD(HTTP_SNS_ANGLE, windrose_str, mt6701_avg_deg_angle);
#endif  // USE_WEBSERVER
    }
  }
}

/*****************************************************************************
* Process commands as delivered from FUNC_COMMAND callback.
*/
bool mt6701_Command(void) {
  bool serviced = true;
  uint8_t paramcount = 0;
  if (XdrvMailbox.data_len > 0) {
    paramcount = 1;
  } else {
    return false;
  }

  char argument[XdrvMailbox.data_len];
  // scan the parameter string to convert it to a standard form and count the
  // number of delimeted elements
  for (uint32_t ca = 0; ca < XdrvMailbox.data_len; ca++) {
    if ((' ' == XdrvMailbox.data[ca]) || ('=' == XdrvMailbox.data[ca])) { XdrvMailbox.data[ca] = ','; }
    if (',' == XdrvMailbox.data[ca]) { paramcount++; }
  }
  UpperCase(XdrvMailbox.data, XdrvMailbox.data);

  if (!strcmp(ArgV(argument, 1), "DIR"))  {
    if (paramcount > 1) {
      if (!strcmp(ArgV(argument, 2), "CW")) {
        //Settings->mt6701_dir = 0;
        //Response_P(MT6701_CONF_RESPONSE, "DIR", Settings->mt6701_dir);   // "{\"MT6701_CONF\":{\"%s\":%s}}"
        return true;
      }
      if (!strcmp(ArgV(argument, 2), "CCW")) {
        //Settings->mt6701_dir = 0;
        //Response_P(MT6701_CONF_RESPONSE, "DIR", Settings->mt6701_dir);   // "{\"MT6701_CONF\":{\"%s\":%s}}"
      } else {
        return false;
      }

    } else { // No parameter was given for DIR so we return the current configured value
      //Response_P((MT6701_CONF_RESPONSE, "DIR", Settings->mt6701_dir ? "CCW" : "CW");   // "{\"MT6701_CONF\":{\"%s\":%s}}"
      return true;
    }
  }

  return serviced;
}


/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

/**
 * The callback function Xsns114() interfaces Tasmota with the MT6701 sensor driver.
 *
 * It provides the Tasmota callback IDs.
 *
 * @param   byte    callback_id  Tasmota function ID.
 * @return  boolean              Return value.
 * @pre     None.
 * @post    None.
 *
 */
bool Xsns114(uint32_t callback_id) {

  // Set return value to `false`
  bool result = false;

  // Check if there is another I2C driver enabled with the same address range id
  if (!I2cEnabled(XI2C_86)) { return false; }

  // Check which callback ID is called by Tasmota
  if (callback_id == FUNC_INIT) {
    mt6701Detect();
  } else if (mt6701_found) {
    switch (callback_id) {
      case FUNC_EVERY_50_MSECOND:
        break;
      case FUNC_EVERY_SECOND:
        mt6701EverySecond();
        break;
      case FUNC_JSON_APPEND:
         mt6701Show(1);
        break;
#ifdef USE_WEBSERVER
      case FUNC_WEB_SENSOR:
         mt6701Show(0);
        break;
#endif // USE_WEBSERVER
      case FUNC_SAVE_BEFORE_RESTART:
        break;
      case FUNC_COMMAND:
        result = mt6701_Command();
        break;
    }
  }

  // Return success in case of successful command callback
  return result;
}

#endif  // USE_MT6701
#endif  // USE_I2C

