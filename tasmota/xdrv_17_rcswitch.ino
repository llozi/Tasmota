/*
  xdrv_17_rcswitch.ino - RF transceiver using RcSwitch library for Tasmota

  Copyright (C) 2020  Theo Arends

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
#include <Arduino.h>
#include "my_user_config.h"  

// doesn't pickup defines while editing without this 
// dunno if this is unique to my enviroment or everyone experiences it ..
#ifdef USE_RC_SWITCH
/*********************************************************************************************\
 * RF send and receive using RCSwitch library https://github.com/sui77/rc-switch/
\*********************************************************************************************/

#define XDRV_17             17

#define D_JSON_RF_PROTOCOL "Protocol"
#define D_JSON_RF_BITS "Bits"
#define D_JSON_RF_DATA "Data"

#define D_CMND_RFSEND "RFSend"
#define D_JSON_RF_PULSE "Pulse"
#define D_JSON_RF_REPEAT "Repeat"

const char kRfSendCommands[] PROGMEM = "|" D_CMND_RFSEND; // No prefix
  

void (* const RfSendCommand[])(void) PROGMEM = {
  &CmndRfSend };

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

#define RF_TIME_AVOID_DUPLICATE 1000  // Milliseconds

uint32_t rf_lasttime = 0;

void RfReceiveCheck(void)
{
  if (mySwitch.available()) {

    unsigned long data = mySwitch.getReceivedValue();
    unsigned int bits = mySwitch.getReceivedBitlength();
    int protocol = mySwitch.getReceivedProtocol();
    int delay = mySwitch.getReceivedDelay();

    AddLog_P(LOG_LEVEL_DEBUG, PSTR("RFR: Data 0x%lX (%u), Bits %d, Protocol %d, Delay %d"), data, data, bits, protocol, delay);

    uint32_t now = millis();
    if ((now - rf_lasttime > RF_TIME_AVOID_DUPLICATE) && (data > 0)) {
      rf_lasttime = now;

      char stemp[16];
      if (Settings.flag.rf_receive_decimal) {      // SetOption28 - RF receive data format (0 = hexadecimal, 1 = decimal)
        snprintf_P(stemp, sizeof(stemp), PSTR("%u"), (uint32_t)data);
      } else {
        snprintf_P(stemp, sizeof(stemp), PSTR("\"0x%lX\""), (uint32_t)data);
      }
      ResponseTime_P(PSTR(",\"" D_JSON_RFRECEIVED "\":{\"" D_JSON_RF_DATA "\":%s,\"" D_JSON_RF_BITS "\":%d,\"" D_JSON_RF_PROTOCOL "\":%d,\"" D_JSON_RF_PULSE "\":%d}}"),
        stemp, bits, protocol, delay);
      MqttPublishPrefixTopicRulesProcess_P(RESULT_OR_TELE, PSTR(D_JSON_RFRECEIVED));
#ifdef USE_DOMOTICZ
      DomoticzSensor(DZ_COUNT, data);  // Send data as Domoticz Counter value
#endif  // USE_DOMOTICZ
    }
    mySwitch.resetAvailable();
  }
}

void RfInit(void)
{
  if (PinUsed(GPIO_RFSEND)) {
    mySwitch.enableTransmit(Pin(GPIO_RFSEND));
  }
  if (PinUsed(GPIO_RFRECV)) {
    pinMode( Pin(GPIO_RFRECV), INPUT);
    mySwitch.enableReceive(Pin(GPIO_RFRECV));
#ifdef BAZMODS 
  mySwitch.enabled_protocol_mask.longs.high32 =  Settings.ex_adc_param1;
  mySwitch.enabled_protocol_mask.longs.low32 = Settings.ex_adc_param2;
#endif
  }
}

/*********************************************************************************************\
 * Commands
\*********************************************************************************************/

#ifdef BAZMODS
void CmndRfRxProtocol(void){
  uint64_t thisbit;
 // AddLog_P(LOG_LEVEL_INFO, PSTR("RFR: index:%d usridx:%d data_len:%d data:%s"),XdrvMailbox.index, XdrvMailbox.usridx, XdrvMailbox.data_len,XdrvMailbox.data);
 // AddLog_P(LOG_LEVEL_INFO, PSTR("RFR: test data_len >0"));
  //if (XdrvMailbox.data_len > 0) {
   // AddLog_P(LOG_LEVEL_INFO, PSTR("RFR: test usridx ==1"));  
    if (XdrvMailbox.usridx==1) {  
 //     AddLog_P(LOG_LEVEL_INFO, PSTR("RFR: test payload >=0")); 
      if(XdrvMailbox.payload >=0){
        thisbit = (1ULL << (XdrvMailbox.index-1) );
        if(XdrvMailbox.payload &1){
          mySwitch.enabled_protocol_mask.value |= thisbit;
        }else{
          mySwitch.enabled_protocol_mask.value &= ~thisbit;
        }
      }
    }else{
  //    AddLog_P(LOG_LEVEL_INFO, PSTR("RFR: test for a"));
      if(XdrvMailbox.data[0]=='a'){
  //      AddLog_P(LOG_LEVEL_INFO, PSTR("RFR: set mask all"));
        mySwitch.enabled_protocol_mask.value=  (1ULL << mySwitch.getNumProtos())-1 ;
      }else{
  //      AddLog_P(LOG_LEVEL_INFO, PSTR("RFR: set mask with value"));
        mySwitch.enabled_protocol_mask.value = strtoull(XdrvMailbox.data,nullptr, 0);
      }   
    }
    Settings.ex_adc_param1 = mySwitch.enabled_protocol_mask.longs.high32;
    Settings.ex_adc_param2 = mySwitch.enabled_protocol_mask.longs.low32;
  //}
  ResponseClear();
  ResponseAppend_P(PSTR("{\"" D_CMND_RFRXPROTOCOL "\":"));
  ResponseAppend_P(PSTR("\""));
  bool gotone = false;
  thisbit=1;
  for (int i=0;i<mySwitch.getNumProtos();i++){
  //  ResponseAppend_P(PSTR("%s%s%d"), (i) ? "," : "",(mySwitch.enabled_protocol_mask.value & thisbit) ? "" : "!", i+1);
    if(mySwitch.enabled_protocol_mask.value & thisbit){
      ResponseAppend_P(PSTR("%s%d"), (gotone) ? "," : "", i+1); 
      gotone = true;
    }
    thisbit <<=1;
  }
  if(!gotone)ResponseAppend_P(PSTR("None Enabled"));
  ResponseAppend_P(PSTR("\""));
  ResponseJsonEnd();

}
#endif
void CmndRfSend(void)
{
  bool error = false;

  if (XdrvMailbox.data_len) {
    unsigned long long data = 0;	// unsigned long long  => support payload >32bit
    unsigned int bits = 24;
    int protocol = 1;
    int repeat = 10;
    int pulse = 350;

    JsonParser parser(XdrvMailbox.data);
    JsonParserObject root = parser.getRootObject();
    if (root) {
      // RFsend {"data":0x501014,"bits":24,"protocol":1,"repeat":10,"pulse":350}
      char parm_uc[10];
      data = root.getULong(PSTR(D_JSON_RF_DATA), data);	// read payload data even >32bit
      bits = root.getUInt(PSTR(D_JSON_RF_BITS), bits);
      protocol = root.getInt(PSTR(D_JSON_RF_PROTOCOL), protocol);
      repeat = root.getInt(PSTR(D_JSON_RF_REPEAT), repeat);
      pulse = root.getInt(PSTR(D_JSON_RF_PULSE), pulse);
    } else {
      //  RFsend data, bits, protocol, repeat, pulse
      char *p;
      uint8_t i = 0;
      for (char *str = strtok_r(XdrvMailbox.data, ", ", &p); str && i < 5; str = strtok_r(nullptr, ", ", &p)) {
        switch (i++) {
        case 0:
          data = strtoul(str, nullptr, 0);  // Allow decimal (5246996) and hexadecimal (0x501014) input
          break;
        case 1:
          bits = atoi(str);
          break;
        case 2:
          protocol = atoi(str);
          break;
        case 3:
          repeat = atoi(str);
          break;
        case 4:
          pulse = atoi(str);
        }
      }
    }

    if (!protocol) { protocol = 1; }
    mySwitch.setProtocol(protocol);
    if (!pulse) { pulse = 350; }      // Default pulse length for protocol 1
    mySwitch.setPulseLength(pulse);
    if (!repeat) { repeat = 10; }     // Default at init
    mySwitch.setRepeatTransmit(repeat);
    if (!bits) { bits = 24; }         // Default 24 bits
    if (data) {
      mySwitch.send(data, bits);
      ResponseCmndDone();
    } else {
      error = true;
    }
  } else {
    error = true;
  }
  if (error) {
    Response_P(PSTR("{\"" D_CMND_RFSEND "\":\"" D_JSON_NO " " D_JSON_RF_DATA ", " D_JSON_RF_BITS ", " D_JSON_RF_PROTOCOL ", " D_JSON_RF_REPEAT " " D_JSON_OR " " D_JSON_RF_PULSE "\"}"));
  }
}

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xdrv17(uint8_t function)
{
  bool result = false;

  if (PinUsed(GPIO_RFSEND) || PinUsed(GPIO_RFRECV)) {
    switch (function) {
      case FUNC_EVERY_50_MSECOND:
        if (PinUsed(GPIO_RFRECV)) {
          RfReceiveCheck();
        }
        break;
      case FUNC_COMMAND:
        if (PinUsed(GPIO_RFSEND)) {
          result = DecodeCommand(kRfSendCommands, RfSendCommand);
        }
        break;
      case FUNC_INIT:
        RfInit();
        break;
    }
  }
  return result;
}

#endif  // USE_RC_SWITCH
