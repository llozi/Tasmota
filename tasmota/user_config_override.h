/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

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

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

// Here follow my own configurations

#ifdef FIRMWARE_SIEVJU

/*********************************************************************************************\
 * - After initial load any change here only take effect if CFG_HOLDER is changed too
\*********************************************************************************************/
// -- Master parameter control --------------------
#if defined CFG_HOLDER
#undef CFG_HOLDER
#endif
#define CFG_HOLDER             4617              // [Reset 1] Change this value (max 32000) to load SECTION1 configuration parameters to flash
                                                 // If following define is disabled it increases configuration corruption detection BUT
                                                 // it only allows firmware upgrades starting from version 6.6.0.11

// -- Project -------------------------------------
#undef PROJECT
#define PROJECT                "sievju"         // PROJECT is used as the default topic delimiter

// -- Wifi settings  ---------------
#include "user_config_wifi.h"

#undef WIFI_CONFIG_TOOL
#define WIFI_CONFIG_TOOL       WIFI_MANAGER      // [WifiConfig] Default tool if Wi-Fi fails to connect (default option: 4 - WIFI_RETRY)
                                                 // The configuration can be changed after first setup using WifiConfig 0, 2, 4, 5, 6 and 7.
// -- Logging--------------------------------------
#undef SYS_LOG_LEVEL
#define SYS_LOG_LEVEL          LOG_LEVEL_NONE    // [SysLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef SERIAL_LOG_LEVEL
#define SERIAL_LOG_LEVEL       LOG_LEVEL_INFO    // [SerialLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef MQTT_LOG_LEVEL
#define MQTT_LOG_LEVEL         LOG_LEVEL_NONE    // [MqttLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef WEB_LOG_LEVEL
#define WEB_LOG_LEVEL          LOG_LEVEL_INFO    // [WebLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)

// -- HTTP ----------------------------------------
#undef FRIENDLY_NAME
#define FRIENDLY_NAME          "Sievju"         // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

#undef WEB_SERVER
#define WEB_SERVER             2                 // [WebServer] Web server (0 = Off, 1 = Start as User, 2 = Start as Admin)
#include "user_config_web_login.h" 
#undef GUI_SHOW_HOSTNAME
#define GUI_SHOW_HOSTNAME      true              // [SetOption53] Show hostname and IP address in GUI main menu
#undef USE_EMULATION_HUE                         // Enable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
#undef USE_EMULATION_WEMO                        // Enable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)

// -- Location ------------------------------------
#include "user_config_location.h" 

// -- Ota -----------------------------------------
#include "user_config_ota.h"

// -- Setup my own MQTT settings  ---------------
#include "user_config_mqtt.h"

#undef  MQTT_PORT
#define MQTT_PORT              8883             // [MqttPort] MQTT port

#ifndef USE_MQTT_TLS
#define USE_MQTT_TLS
#define USE_MQTT_TLS_CA_CERT
#define USE_MQTT_AWS_IOT                       // Needed for full certificate validation, otherwise TLSKey commands are not available
#define USE_MQTT_TLS_FORCE_EC_CIPHER
#define INCLUDE_LOCAL_CERT
#define OMIT_AWS_CERT
#define OMIT_LETS_ENCRYPT_CERT
#endif
#undef MQTT_TLS_ENABLED
#define MQTT_TLS_ENABLED       true             // [SetOption103] Enable TLS mode (requires TLS version)
#undef MQTT_TLS_FINGERPRINT
#define MQTT_TLS_FINGERPRINT   true             // [SetOption132] Force TLS fingerprint validation instead of CA (requires TLS version)

// -- MQTT - Telemetry ----------------------------
#undef TELE_PERIOD
#define TELE_PERIOD            30               // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)
#undef TELE_ON_POWER
#define TELE_ON_POWER          false            // [SetOption59] send tele/STATE together with stat/RESULT (false = Disable, true = Enable)

// -- Ping ----------------------------------------
#define USE_PING                                // Enable Ping command (+2k code)

// -- HTTP Options --------------------------------
#define GUI_NOSHOW_MODULE      false            // [SetOption141] Do not show module name in GUI main menu
#define GUI_NOSHOW_DEVICENAME  false            // [SetOption163] Do not show device name in GUI main menu
#define GUI_SHOW_HOSTNAME      true             // [SetOption53] Show hostname and IP address in GUI main menu
#define GUI_NOSHOW_STATETEXT   false            // [SetOption161] Do not show power state text in GUI


// -- My own hardware/function Specific configs ---

#ifdef FIRMWARE_IR_CONTROLLER
#include "user_config_undef_most.h"
#include "user_config_ir_remote.h"
#endif  // FIRMWARE_IR_CONTROLLER

#ifdef FIRMWARE_MINI_RELAY
#include "user_config_undef_most.h"
#include "user_config_mini_relay.h"
#endif  // FIRMWARE_MINI_RELAY

#ifdef FIRMWARE_SIEVJU_ESP32CAM
#include "user_config_undef_most.h"
#include "user_config_esp32-cam.h"
#endif  // FIRMWARE_SIEVJU_ESP32CAM

#ifdef FIRMWARE_SIEVJU_ESP32_DEVKITC
#include "user_config_undef_most.h"
#include "user_config_esp32_devkitc.h"               
#endif  // FIRMWARE_SIEVJU_ESP32_DEVKITC
                                                 
#ifdef FIRMWARE_SIEVJU_ESP32_VIFTER
#include "user_config_undef_most.h"
#include "user_config_esp32_vifter.h"
#endif // FIRMWARE_SIEVJU_ESP32_VIFTER

#endif  // FIRMWARE_SIEVJU

#endif  // _USER_CONFIG_OVERRIDE_H_
