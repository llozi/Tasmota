/*
  xnrg_08_sdm230.ino - Eastron SDM230-Modbus energy meter support for Tasmota

  Copyright (C) 2021  Gennaro Tortone and Theo Arends

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

#ifdef USE_ENERGY_SENSOR
#ifdef USE_SDM230
/*********************************************************************************************\
 * Eastron SDM230 Modbus energy meter
 *
 * Based on: https://github.com/reaper7/SDM_Energy_Meter and https://github.com/nmakel/sdm_modbus
\*********************************************************************************************/

#define XNRG_21             21

// can be user defined in my_user_config.h
#ifndef SDM230_SPEED
  #define SDM230_SPEED      2400    // default SDM230 Modbus address
#endif
// can be user defined in my_user_config.h
#ifndef SDM230_ADDR
  #define SDM230_ADDR       1       // default SDM120 Modbus address
#endif

#include <TasmotaModbus.h>
TasmotaModbus *Sdm230Modbus;

const uint16_t sdm230_start_addresses[] {
  0x0000,   // SDM230_VOLTAGE                             [V]
  0x0006,   // SDM230_CURRENT                             [A]
  0x000C,   // SDM230_POWER (Active)                      [W]
  0x0012,   // SDM230_POWER (Apparent) G                  [VA]
  0x0018,   // SDM230_POWER (Reactive)                    [VAr]
  0x001E,   // SDM230_POWER_FACTOR 
  0x0046,   // SDM230_FREQUENCY                           [Hz]
  0X004A,   // SDM230_EXPORT_ACTIVE                       [kWh]
  0X0180,   // SDM230_RESETTABLE_TOTAL_ENERGY_ACTIVE      [kWh]
  0X0056,   // SDM230_MAXIMUM_TOTAL_DEMAND_POWER_ACTIVE   [W]
  0x0024,   // SDM230_PHASE ANGLE                         [Degree]
#ifdef SDM230_IMPORT
  0X0048,   // SDM230_IMPORT_ACTIVE                       [kWh]
#endif  // SDM230_IMPORT
  0X0156,   // SDM230_TOTAL_ENERGY_ACTIVE                 [kWh]

//  0X0158,   // SDM230_TOTAL_ENERGY_REACTIVE               [kVArh]
//  0X0182,   // SDM230_RESETTABLE_TOTAL_ENERGY_REACTIVE    [kVArh]
//  0X004C,   // SDM230_IMPORT_REACTIVE                     [kVArh]
//  0X004E,   // SDM230_EXPORT_REACTIVE                     [kVArh]
//  0X0054,   // SDM230_TOTAL_DEMAND_POWER_ACTIVE           [W]
//  0X0058,   // SDM230_IMPORT_DEMAND_POWER_ACTIVE          [W]
//  0X005A,   // SDM230_MAXIMUM_IMPORT_DEMAND_POWER_ACTIVE  [W]
//  0X005C,   // SDM230_EXPORT_DEMAND_POWER_ACTIVE          [W]
//  0X005E,   // SDM230_MAXIMUM_EXPORT_DEMAND_POWER_ACTIVE  [W]
//  0X0102,   // SDM230_TOTAL_DEMAND_CURRENT                [A]
//  0X0108,   // SDM230_MAXIMUM_TOTAL_DEMAND_CURRENT        [A]
};

struct SDM230 {
  float resettable_total_energy = 0;
  float maximum_total_demand_power = 0;
  float phase_angle = 0;
  uint8_t read_state = 0;
  uint8_t send_retry = 0;
} Sdm230;

/*********************************************************************************************/

void SDM230Every250ms(void)
{
  bool data_ready = Sdm230Modbus->ReceiveReady();

  if (data_ready) {
    uint8_t buffer[14];  // At least 5 + (2 * 2) = 9

    uint32_t error = Sdm230Modbus->ReceiveBuffer(buffer, 2);
    AddLogBuffer(LOG_LEVEL_DEBUG_MORE, buffer, Sdm230Modbus->ReceiveCount());

    if (error) {
      AddLog(LOG_LEVEL_DEBUG, PSTR("SDM: SDM230 error %d"), error);
    } else {
      Energy.data_valid[0] = 0;

      //  0  1  2  3  4  5  6  7  8
      // SA FC BC Fh Fl Sh Sl Cl Ch
      // 01 04 04 43 66 33 34 1B 38 = 230.2 Volt
      float value;
      ((uint8_t*)&value)[3] = buffer[3];   // Get float values
      ((uint8_t*)&value)[2] = buffer[4];
      ((uint8_t*)&value)[1] = buffer[5];
      ((uint8_t*)&value)[0] = buffer[6];

      switch(Sdm230.read_state) {
        case 0:
          Energy.voltage[0] = value;          // 230.2 V
          break;

        case 1:
          Energy.current[0]  = value;         // 1.260 A
          break;

        case 2:
          Energy.active_power[0] = value;     // -196.3 W
          break;

        case 3:
          Energy.apparent_power[0] = value;   // 223.4 VA
          break;

        case 4:
          Energy.reactive_power[0] = value;   // 92.2
          break;

        case 5:
          Energy.power_factor[0] = value;     // -0.91
          break;

        case 6:
          Energy.frequency[0] = value;        // 50.0 Hz
          break;

        case 7:
          Energy.export_active[0] = value;    // 478.492 kWh
          break;

        case 8:
          Sdm230.resettable_total_energy = value;  
          break;

        case 9:
          Sdm230.maximum_total_demand_power  = value;  
          break;

        case 10:
          Sdm230.phase_angle = value;      // 0.00 Deg
          break;

        case 11:
          Energy.import_active[0] = value;     // 6.216 kWh 
          break;

        case 12:
          EnergyUpdateTotal();
          //Energy.export_active[0] = value;    // 484.708 kWh = import_active + export_active
          break;
      }

      Sdm230.read_state++;
      if (sizeof(sdm230_start_addresses)/2 == Sdm230.read_state) {
        Sdm230.read_state = 0;
      }
    }
  } // end data ready

  if (0 == Sdm230.send_retry || data_ready) {
    Sdm230.send_retry = 5;
    Sdm230Modbus->Send(SDM230_ADDR, 0x04, sdm230_start_addresses[Sdm230.read_state], 2);
  } else {
    Sdm230.send_retry--;
  }
}

void Sdm230SnsInit(void)
{
  Sdm230Modbus = new TasmotaModbus(Pin(GPIO_SDM230_RX), Pin(GPIO_SDM230_TX));
  uint8_t result = Sdm230Modbus->Begin(SDM230_SPEED);
  if (result) {
    if (2 == result) { ClaimSerial(); }
  } else {
    TasmotaGlobal.energy_driver = ENERGY_NONE;
  }
}

void Sdm230DrvInit(void)
{
  if (PinUsed(GPIO_SDM230_RX) && PinUsed(GPIO_SDM230_TX)) {
    TasmotaGlobal.energy_driver = XNRG_21;
  }
}

void Sdm230Reset(void)
{
  Sdm230.resettable_total_energy = 0;
  Sdm230.maximum_total_demand_power = 0;
  Sdm230.phase_angle = 0;
}

#ifdef USE_WEBSERVER
const char HTTP_ENERGY_SDM230[] PROGMEM =
  "{s}" D_RESETTABLE_TOTAL_ACTIVE "{m}%s " D_UNIT_KILOWATTHOUR "{e}"
  "{s}" D_MAX_POWER "{m}%s " D_UNIT_WATT "{e}"
  "{s}" D_PHASE_ANGLE "{m}%s " D_UNIT_ANGLE "{e}";
#endif  // USE_WEBSERVER

void Sdm230Show(bool json)
{
  char resettable_energy_chr[FLOATSZ];
  dtostrfd(Sdm230.resettable_total_energy, Settings->flag2.energy_resolution, resettable_energy_chr);
  char maximum_demand_chr[FLOATSZ];
  dtostrfd(Sdm230.maximum_total_demand_power, Settings->flag2.wattage_resolution, maximum_demand_chr);
  char phase_angle_chr[FLOATSZ];
  dtostrfd(Sdm230.phase_angle, 2, phase_angle_chr);

  if (json) {
    ResponseAppend_P(PSTR(",\"" D_JSON_RESETTABLE_TOTAL_ACTIVE "\":%s,\"" D_JSON_POWERMAX "\":%s,\"" D_JSON_PHASE_ANGLE "\":%s"),
      resettable_energy_chr, maximum_demand_chr, phase_angle_chr);
#ifdef USE_WEBSERVER
  } else {
    WSContentSend_PD(HTTP_ENERGY_SDM230, resettable_energy_chr, maximum_demand_chr, phase_angle_chr);
#endif  // USE_WEBSERVER
  }
}

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xnrg21(uint8_t function)
{
  bool result = false;

  switch (function) {
    case FUNC_EVERY_250_MSECOND:
      SDM230Every250ms();
      break;
    case FUNC_JSON_APPEND:
      Sdm230Show(1);
      break;
#ifdef USE_WEBSERVER
    case FUNC_WEB_SENSOR:
      Sdm230Show(0);
      break;
#endif  // USE_WEBSERVER
    case FUNC_ENERGY_RESET:
      Sdm230Reset();
      break;
    case FUNC_INIT:
      Sdm230SnsInit();
      break;
    case FUNC_PRE_INIT:
      Sdm230DrvInit();
      break;
  }
  return result;
}

#endif  // USE_SDM230
#endif  // USE_ENERGY_SENSOR
