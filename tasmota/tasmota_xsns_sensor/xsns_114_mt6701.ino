/*
  xsns_114_mt6701.ino - MT6701 Tasmota support for Hall based angle position sensor

  based on
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
 * I2C Address: 0x06
 *
\*********************************************************************************************/

#define XSNS_114                                114
#define XI2C_86                                 86        // See I2CDEVICES.md

#define MT6701_ADDRESS                          (0x06)    // 0000110

uint8_t mt6701_found = 0;

bool mt6701Init(void)
{
  Wire.beginTransmission(MT6701_ADDRESS);
  Wire.endTransmission();
  delay(1);

  Wire.beginTransmission(MT6701_ADDRESS); // start transmission
  if (Wire.endTransmission(1) != 0) {
    return false;
  }
  return true;
}

void mt6701Detect(void)
{
  if (mt6701Init()) {
    if (!mt6701_found) {
      AddLog(LOG_LEVEL_INFO, S_LOG_I2C_FOUND_AT, AM2320_types, MT6701_ADDRESS);
    } else {
      AddLog(LOG_LEVEL_DEBUG, S_LOG_I2C_FOUND_AT, AM2320_types, MT6701_ADDRESS);
    }
    mt6701_found = 3;
  } else {
    if (mt6701_found) { mt6701_found--; }
  }
}


void mt6701EverySecond(void)
{
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
bool Xsns114(byte callback_id) {

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
        break;
#ifdef USE_WEBSERVER
      case FUNC_WEB_APPEND:
        break;
#endif // USE_WEBSERVER
      case FUNC_SAVE_BEFORE_RESTART:
        break;
      case FUNC_COMMAND:
        break;
    }
  }

  // Return success in case of successful command callback
  return result;
}

#endif  // USE_MT6701
#endif  // USE_I2C

