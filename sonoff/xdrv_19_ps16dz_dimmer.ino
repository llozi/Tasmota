/*
  xdrv_19_ps16dz_dimmer.ino - PS_16_DZ dimmer support for Sonoff-Tasmota

  Copyright (C) 2018 Joel Stein and Theo Arends

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

#ifdef USE_PS_16_DZ

#define XDRV_19                19

#define PS16DZ_BUFFER_SIZE     256

#include <TasmotaSerial.h>

TasmotaSerial *PS16DZSerial = nullptr;

boolean ps16dz_ignore_dim = false;            // Flag to skip serial send to prevent looping when processing inbound states from the faceplate interaction

boolean ps16dz_power = false;
uint8_t ps16dz_bright = 0;
uint64_t ps16dz_seq = 0;

char ps16dz_tx_buffer[PS16DZ_BUFFER_SIZE];         // Serial transmit buffer
char ps16dz_rx_buffer[PS16DZ_BUFFER_SIZE];         // Serial receive buffer
int ps16dz_byte_counter = 0;

/*********************************************************************************************\
 * Internal Functions
\*********************************************************************************************/


size_t print_uint64_t(uint64_t number)
{
    size_t n = 0;
    unsigned char buf[21];
    uint8_t i = 0;

    if (number == 0)
    {
        n += snprintf_P(ps16dz_tx_buffer, sizeof(ps16dz_tx_buffer), PSTR( "%s%c"), ps16dz_tx_buffer, (char)'0');
        return n;
    }

    while (number > 0)
    {
        uint64_t q = number/10;
        buf[i++] = number - q*10;
        number = q;
    }

    for (; i > 0; i--)
    n += snprintf_P(ps16dz_tx_buffer, sizeof(ps16dz_tx_buffer), PSTR( "%s%c"), ps16dz_tx_buffer, (char) ('0' + buf[i - 1]));

    return n;
}

uint64_t getTimestamp(void)
{
    return (((uint64_t)LocalTime()) * 1000) + (millis()%1000);
}

boolean PS16DZSetPower(void)
{
  boolean status = false;

  uint8_t rpower = XdrvMailbox.index;
  int16_t source = XdrvMailbox.payload;

  if (source != SRC_SWITCH && PS16DZSerial) {  // ignore to prevent loop from pushing state from faceplate interaction

    snprintf_P(ps16dz_tx_buffer, sizeof(ps16dz_tx_buffer), PSTR( "AT+UPDATE=\"sequence\":\""));
    ps16dz_seq = getTimestamp();
    print_uint64_t(ps16dz_seq);
    snprintf_P(ps16dz_tx_buffer, sizeof(ps16dz_tx_buffer), PSTR( "%s\",\"switch\":\"%s\""), ps16dz_tx_buffer, rpower?"on":"off");
    snprintf_P(log_data, sizeof(log_data), PSTR( "PSZ: Send serial command: %s"), ps16dz_tx_buffer );
    AddLog(LOG_LEVEL_DEBUG);
    
    PS16DZSerial->print(ps16dz_tx_buffer);
    PS16DZSerial->write(0x1B);
    PS16DZSerial->flush();

    status = true;
  }
  return status;
}

void PS16DZSerialDuty(uint8_t duty)
{
  if (duty > 0 && !ps16dz_ignore_dim && PS16DZSerial) {
    if (duty < 25) {
      duty = 25;  // dimming acts odd below 25(10%) - this mirrors the threshold set on the faceplate itself
    }

    snprintf_P(ps16dz_tx_buffer, sizeof(ps16dz_tx_buffer), PSTR( "AT+UPDATE=\"sequence\":\""));
    ps16dz_seq = getTimestamp();
    print_uint64_t(ps16dz_seq);
    snprintf_P(ps16dz_tx_buffer, sizeof(ps16dz_tx_buffer), PSTR( "%s\",\"bright\":\"%d\""), ps16dz_tx_buffer, round(duty * (100. / 255.)));
    snprintf_P(log_data, sizeof(log_data), PSTR( "PSZ: Send serial command: %s"), ps16dz_tx_buffer );
    AddLog(LOG_LEVEL_DEBUG);
    
    PS16DZSerial->print(ps16dz_tx_buffer);
    PS16DZSerial->write(0x1B);
    PS16DZSerial->flush();

  } else {
    ps16dz_ignore_dim = false;  // reset flag

    snprintf_P(log_data, sizeof(log_data), PSTR( "PSZ: Send Dim Level skipped due to 0 or already set. Value=%d"), duty);
    AddLog(LOG_LEVEL_DEBUG);

  }
}

void PS16DZResetWifi(void)
{
  if (!Settings.flag.button_restrict) {
    char scmnd[20];
    snprintf_P(scmnd, sizeof(scmnd), D_CMND_WIFICONFIG " %d", 2);
    ExecuteCommand(scmnd, SRC_BUTTON);
  }
}

/*********************************************************************************************\
 * API Functions
\*********************************************************************************************/

boolean PS16DZModuleSelected(void)
{
  light_type = LT_SERIAL1;
  return true;
}

void PS16DZInit(void)
{
  PS16DZSerial = new TasmotaSerial(pin[GPIO_RXD], pin[GPIO_TXD], 2);
  if (PS16DZSerial->begin(19200)) {
    if (PS16DZSerial->hardwareSerial()) { ClaimSerial(); }
  }
}

void PS16DZSerialInput(void)
{
  char scmnd[20];
  while (PS16DZSerial->available()) {
    yield();
    //ps16dz_command = PS16DZSerial->readStringUntil(0x1B); 
    byte serial_in_byte = PS16DZSerial->read();
    if (serial_in_byte != 0x1B){
      if (ps16dz_byte_counter || (!ps16dz_byte_counter && serial_in_byte == 'A'));
      ps16dz_rx_buffer[ps16dz_byte_counter++] = serial_in_byte;
    }
    else {
      ps16dz_rx_buffer[ps16dz_byte_counter++] = 0x00;
      snprintf_P(log_data, sizeof(log_data), PSTR("PSZ: command received: %s"), ps16dz_rx_buffer);
      AddLog(LOG_LEVEL_DEBUG);
      if(!strncmp(ps16dz_rx_buffer+3, "UPDATE", 6) || !strncmp(ps16dz_rx_buffer+3, "RESULT", 6)) {
        char *end_str;
        char *string = ps16dz_rx_buffer+10;
        char* token = strtok_r(string, ",", &end_str);
        while (token != NULL) {
          char* end_token;
          snprintf_P(log_data, sizeof(log_data), PSTR("PSZ: token = %s"), token);
          AddLog(LOG_LEVEL_DEBUG);
          char* token2 = strtok_r(token, ":", &end_token);
          char* token3 = strtok_r(NULL, ":", &end_token);
          if(!strncmp(token2, "\"switch\"", 8)){
            ps16dz_power = !strncmp(token3, "\"on\"", 4)?true:false;
            snprintf_P(log_data, sizeof(log_data), PSTR("PSZ: power received: %s"), token3);
            AddLog(LOG_LEVEL_DEBUG);
            if((power || Settings.light_dimmer > 0) && (power !=ps16dz_power)) {
              ExecuteCommandPower(1, ps16dz_power, SRC_SWITCH);  // send SRC_SWITCH? to use as flag to prevent loop from inbound states from faceplate interaction
            }
          }
          else if(!strncmp(token2, "\"bright\"", 8)){
            ps16dz_bright = atoi(token3);
            snprintf_P(log_data, sizeof(log_data), PSTR("PSZ: brightness received: %d"), ps16dz_bright);
            AddLog(LOG_LEVEL_DEBUG);
            if(power && ps16dz_bright > 0) {

              snprintf_P(scmnd, sizeof(scmnd), PSTR(D_CMND_DIMMER " %d"), ps16dz_bright );

              snprintf_P(log_data, sizeof(log_data), PSTR("PSZ: Send CMND_DIMMER_STR=%s"), scmnd );
              AddLog(LOG_LEVEL_DEBUG);

              ps16dz_ignore_dim = true;
              ExecuteCommand(scmnd, SRC_SWITCH);
            }
          }
          else if(!strncmp(token2, "\"sequence\"", 10)){
            //ps16dz_seq = strtoull(token3+1, NULL, 10);
            snprintf_P(log_data, sizeof(log_data), PSTR("PSZ: sequence received: %s"), token3);
            AddLog(LOG_LEVEL_DEBUG);
          }  
          token = strtok_r(NULL, ",", &end_str);
        }
      }
      else if(!strncmp(ps16dz_rx_buffer+3, "SETTING", 7)) {
        snprintf_P(log_data, sizeof(log_data), PSTR("PSZ: Reset"));
        AddLog(LOG_LEVEL_DEBUG);
        PS16DZResetWifi();
      }
      memset(ps16dz_rx_buffer, 0, sizeof(ps16dz_rx_buffer));
      ps16dz_byte_counter = 0;

      snprintf_P(ps16dz_tx_buffer, sizeof(ps16dz_tx_buffer), PSTR( "AT+SEND=ok"));
      snprintf_P(log_data, sizeof(log_data), PSTR( "PSZ: Send serial command: %s"), ps16dz_tx_buffer );
      AddLog(LOG_LEVEL_DEBUG);

      PS16DZSerial->print(ps16dz_tx_buffer);
      PS16DZSerial->write(0x1B);
      PS16DZSerial->flush();
    }
  }
}



/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

boolean Xdrv19(byte function)
{
  boolean result = false;

  if (PS_16_DZ == Settings.module) {
    switch (function) {
      case FUNC_MODULE_INIT:
        result = PS16DZModuleSelected();
        break;
      case FUNC_INIT:
        PS16DZInit();
        break;
      case FUNC_LOOP:
        if (PS16DZSerial) { PS16DZSerialInput(); }
        break;
      case FUNC_SET_DEVICE_POWER:
        result = PS16DZSetPower();
        break;
    }
  }
  return result;
}

#endif  // USE_PS_16_DZ
