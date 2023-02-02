/*
  xnrg_24_biopdu.ino - BioPDU-625x12 (based on xnrg_05_pzem_ac.ino)
    Biomine 625x12 Custom Board
    6 x Independent PZEM-004V3 Modbus AC energy sensor
    3bit serial switch
    Integrated MCP23008

  Template {"NAME":"Olimex ESP32-PoE-BioPDU","GPIO":[1,10081,10082,1,10016,1,0,0,5536,640,1,1,608,0,5600,0,0,0,0,5568,0,0,0,0,0,0,0,0,1,10080,1,1,10048,0,0,1],"FLAG":0,"BASE":1}

  Copyright (C) 2021       Theo Arends
  Copyright (C) 2022-2023  Fabrizio Amodio

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

#if defined(USE_ENERGY_SENSOR_ESP32) && defined(USE_I2C)
#ifdef USE_BIOPDU

#define XNRG_24 24

#undef ENERGY_MAX_PHASES
#define ENERGY_MAX_PHASES         6        // BioPDU support max six phases/channels

#undef ENERGY_GUI_MAX_COLS
#define ENERGY_GUI_MAX_COLS       6        // [EnergyCols] Number of GUI data columns - Preffered 6

#undef ENERGY_GUI_DISPLAY_MODE
#define ENERGY_GUI_DISPLAY_MODE   ENERGY_DISPLAY_TABS // [EnergyDisplay] 1 = Rotate if over EnergyCols, 2 = Rotate only powered on if over EnergyCols, 3 = Use tabs if over EnergyCols

const uint8_t BIOPDU_DEVICE_ADDRESS = 0x01; // PZEM default address
const uint32_t BIOPDU_STABILIZE = 30;       // Number of seconds to stabilize configuration

#include <TasmotaModbus.h>
TasmotaModbus *BioPduModbus;

struct BIOPDU
{
  float energy = 0;
  float last_energy = 0;
  uint8_t send_retry = 0;
  uint8_t phase = 0;
  uint8_t address = 0;
  uint8_t address_step = ADDR_IDLE;
  uint8_t pins = 0;
  uint8_t current_mux = 99;
} BioPdu;

void BioPduSetPins(uint8_t current)
{
  if (BioPdu.current_mux != current)
  {
    for (uint8_t p = 0; p < BioPdu.pins; p++)
    {
      digitalWrite(Pin(GPIO_BIOPDU_BIT, p), (current + 1) & (1 << p) ? 1 : 0);
    }
    BioPdu.current_mux = current;
  }
}

void BioPduEverySecond(void)
{
  static uint32_t lastms = 0;

  if (millis() >= lastms + 1000)
  {
    lastms = millis();
    EnergyUpdateTotal();
  }
}

void BioPduEvery250ms(void)
{
  bool data_ready = BioPduModbus->ReceiveReady();

  if (data_ready)
  {
    uint8_t buffer[30]; // At least 5 + (2 * 10) = 25

    uint8_t registers = 10;
    if (ADDR_RECEIVE == BioPdu.address_step)
    {
      registers = 2; // Need 1 byte extra as response is F8 06 00 02 00 01 FD A3
      BioPdu.address_step--;
    }
    uint8_t error = BioPduModbus->ReceiveBuffer(buffer, registers);
    AddLogBuffer(LOG_LEVEL_DEBUG_MORE, buffer, BioPduModbus->ReceiveCount());

    if (error)
    {
      AddLog(LOG_LEVEL_DEBUG, PSTR("PDU: phase %d error %d"), BioPdu.phase, error);
    }
    else
    {
      Energy->data_valid[BioPdu.phase] = 0;
      if (10 == registers)
      {

        //           0     1     2     3     4     5     6     7     8     9           = ModBus register
        //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24  = Buffer index
        // Id Cc Sz Volt- Current---- Power------ Energy----- Frequ PFact Alarm Crc--
        // 01 04 14 08 D1 00 6C 00 00 00 F4 00 00 00 26 00 00 01 F4 00 64 00 00 51 34
        // 01 04 14 08 CE 00 22 00 00 00 00 00 00 00 02 00 00 01 F4 00 00 00 00 33 FE
        Energy->voltage[BioPdu.phase] = (float)((buffer[3] << 8) + buffer[4]) / 10.0f;                                                     // 6553.0 V
        Energy->current[BioPdu.phase] = (float)((buffer[7] << 24) + (buffer[8] << 16) + (buffer[5] << 8) + buffer[6]) / 1000.0f;           // 4294967.000 A
        Energy->active_power[BioPdu.phase] = (float)((buffer[11] << 24) + (buffer[12] << 16) + (buffer[9] << 8) + buffer[10]) / 10.0f;     // 429496729.0 W
        Energy->frequency[BioPdu.phase] = (float)((buffer[17] << 8) + buffer[18]) / 10.0f;                                                 // 50.0 Hz
        Energy->power_factor[BioPdu.phase] = (float)((buffer[19] << 8) + buffer[20]) / 100.0f;                                             // 1.00
        Energy->import_active[BioPdu.phase] = (float)((buffer[15] << 24) + (buffer[16] << 16) + (buffer[13] << 8) + buffer[14]) / 1000.0f; // 4294967.295 kWh

        // AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("PDU: ph=%d v=%2_f c=%4_f ap=%2_f f=%2_f pf=%3_f ia=%4_f"), 
        //   BioPdu.phase,
        //   &Energy->voltage[BioPdu.phase],
        //   &Energy->current[BioPdu.phase],
        //   &Energy->active_power[BioPdu.phase],
        //   &Energy->frequency[BioPdu.phase],
        //   &Energy->power_factor[BioPdu.phase],
        //   &Energy->import_active[BioPdu.phase]
        //   );
      }
    }
  }

  // AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("PDU: ph=%d st=%d dr=%d sr=%d"), BioPdu.phase, BioPdu.address_step, data_ready, BioPdu.send_retry);

  if (0 == BioPdu.send_retry || data_ready)
  {
    if (ADDR_SEND == BioPdu.address_step)
    {
      BioPduModbus->Send(0xF8, 0x06, 0x0002, (uint16_t)BioPdu.address);
      BioPdu.address_step--;
    }
    else
    {
      uint8_t gpio = MCP230xx_readGPIO(0);

      BioPdu.send_retry = 1 /*ENERGY_WATCHDOG*/;
      for (uint8_t p = 0; p < Energy->phase_count; p++)
      {
        if (++BioPdu.phase == Energy->phase_count)
        {
          BioPdu.phase = 0;
        }

        if ((gpio >> (BioPdu.phase + 1)) & 1)
        {
          BioPduSetPins(BioPdu.phase);

          delay(1);

          uint8_t res = BioPduModbus->Send(BIOPDU_DEVICE_ADDRESS /*+ BioPdu.phase*/, 0x04, 0, 10);
          if (res != 0)
          {
            AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("PDU: phase %d modbus_error="), BioPdu.phase, res);
          }
          break;
        }
        else
        {
          // AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("PDU: phase %d not read"), BioPdu.phase);
        }
      }
    }
  }
  else
  {
    BioPdu.send_retry--;
    if ((Energy->phase_count > 1) && (0 == BioPdu.send_retry) && (TasmotaGlobal.uptime < BIOPDU_STABILIZE))
    {
      // Energy->phase_count--; // Decrement phases if no response after retry within 30 seconds after restart
      //  if (TasmotaGlobal.discovery_counter)
      //  {
      //    TasmotaGlobal.discovery_counter += ENERGY_WATCHDOG + 1; // Don't send Discovery yet, delay by 4s + 1s
      //  }
    }
  }
}

void BioPduSnsInit(void)
{
  BioPduModbus = new TasmotaModbus(Pin(GPIO_BIOPDU_PZEM016_RX), Pin(GPIO_BIOPDU_PZEM0XX_TX));
  uint8_t result = BioPduModbus->Begin(9600);
  if (result)
  {
    if (2 == result)
    {
      ClaimSerial();
    }
    BioPdu.phase = Energy->phase_count - 1;
  }
  else
  {
    TasmotaGlobal.energy_driver = ENERGY_NONE;
  }
}

void BioPduDrvInit(void)
{
  if (PinUsed(GPIO_BIOPDU_PZEM016_RX) && PinUsed(GPIO_BIOPDU_PZEM0XX_TX) && PinUsed(GPIO_BIOPDU_BIT))
  {
    TasmotaGlobal.energy_driver = XNRG_24;

    Energy->voltage_common = false;
    Energy->frequency_common = false;

    AddLog(LOG_LEVEL_DEBUG, PSTR("PDU: checking pins"));

    for (uint8_t p = 0; p < 3; p++)
    {
      if (PinUsed(GPIO_BIOPDU_BIT, p))
      {
        pinMode(Pin(GPIO_BIOPDU_BIT, p), OUTPUT);
        digitalWrite(Pin(GPIO_BIOPDU_BIT, p), 0);

        AddLog(LOG_LEVEL_DEBUG, PSTR("PDU: Add GPIO %d/%d for pin %d"), GPIO_BIOPDU_BIT, p, BioPdu.pins);

        BioPdu.pins++;
      }
      else
      {
        break;
      }
    }

    Energy->phase_count = std::min((uint8_t)(pow(2, BioPdu.pins) - 1), (uint8_t)ENERGY_MAX_PHASES); // Start off with 6 phases

    AddLog(LOG_LEVEL_DEBUG, PSTR("PDU: number of pins=%d, max_phase=%d"), BioPdu.pins, Energy->phase_count);
  }
}

bool BioPduCommand(void)
{
  bool serviced = true;

  if (CMND_MODULEADDRESS == Energy->command_code)
  {
    BioPdu.address = XdrvMailbox.payload; // Valid addresses are 1, 2 and 3
    BioPdu.address_step = ADDR_SEND;
  }
  else
    serviced = false; // Unknown command

  return serviced;
}

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xnrg24(uint32_t function)
{
  bool result = false;

  switch (function)
  {
  case FUNC_EVERY_250_MSECOND:
    if (TasmotaGlobal.uptime > 4)
    {
      BioPduEvery250ms();
    } // Fix start up issue #5875
    break;
  case FUNC_ENERGY_EVERY_SECOND:
    if (TasmotaGlobal.uptime > BIOPDU_STABILIZE)
    {
      BioPduEverySecond();
    }
    break;
  case FUNC_COMMAND:
    result = BioPduCommand();
    break;
  case FUNC_INIT:
    BioPduSnsInit();
    break;
  case FUNC_PRE_INIT:
    BioPduDrvInit();
    break;
  }
  return result;
}

#endif // USE_BIOPDU
#endif // USE_ENERGY_SENSOR
