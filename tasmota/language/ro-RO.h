/*
  ro-RO.h - localization for Romanian - Romania and Moldova for Tasmota

  Copyright (C) 2020  Augustin Marti

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

#ifndef _LANGUAGE_RO_RO_H_
#define _LANGUAGE_RO_RO_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v8.1.0.10
\*********************************************************************/

//#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)
// https://www.science.co.il/language/Locale-codes.php
#define LANGUAGE_LCID 2072
// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "ro"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "-"
#define D_MONTH_DAY_SEPARATOR "-"
#define D_DATE_TIME_SEPARATOR "T"
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "DumLunMarMieJoiVinSâm"
#define D_MONTH3LIST "IanFebMarAprMaiIunIulAugSepOctNoeDec"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR "."

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Calitatea aerului"
#define D_AP "AP"                    // Access Point
#define D_AS "as"
#define D_AUTO "AUTO"
#define D_BLINK "Blink"
#define D_BLINKOFF "BlinkOff"
#define D_BOOT_COUNT "Boot Count"
#define D_BRIGHTLIGHT "Strălucire"
#define D_BSSID "BSSId"
#define D_BUTTON "Buton"
#define D_BY "de"                    // Written by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CHANNEL "Canal"
#define D_CO2 "Dioxid de carbon"
#define D_CODE "cod"                // Button code
#define D_COLDLIGHT "Rece"
#define D_COMMAND "Comandă"
#define D_CONNECTED "Conectat"
#define D_CORS_DOMAIN "Domeniu CORS"
#define D_COUNT "Numărătoare"
#define D_COUNTER "Contor"
#define D_CT_POWER "Putere Transformată"
#define D_CURRENT "Curent"          // As in Voltage and Current
#define D_DATA "Date"
#define D_DARKLIGHT "Întunecat"
#define D_DEBUG "Depanare"
#define D_DISABLED "Dezactivat"
#define D_DISTANCE "Distanță"
#define D_DNS_SERVER "Server DNS"
#define D_DONE "Terminat"
#define D_DST_TIME "DST"
#define D_ECO2 "eCO₂"
#define D_EMULATION "Emulație"
#define D_ENABLED "Abilitat"
#define D_ERASE "Șterge"
#define D_ERROR "Eroare"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "Eșuat"
#define D_FALLBACK "Rezervă"
#define D_FALLBACK_TOPIC "Listă de rezervă"
#define D_FALSE "Fals"
#define D_FILE "Fișier"
#define D_FLOW_RATE "Debit"
#define D_FREE_MEMORY "Memorie Liberă"
#define D_FREQUENCY "Frecvență"
#define D_GAS "Gaz"
#define D_GATEWAY "Gateway"
#define D_GROUP "Grup"
#define D_HOST "Gazdă"
#define D_HOSTNAME "Hostname"
#define D_HUMIDITY "Umiditate"
#define D_ILLUMINANCE "Iluminare"
#define D_IMMEDIATE "imediat"      // Button immediate
#define D_INDEX "Index"
#define D_INFO "Info"
#define D_INFRARED "Infraroșu"
#define D_INITIALIZED "Inițializat"
#define D_IP_ADDRESS "Adresă IP"
#define D_LIGHT "Lumină"
#define D_LWT "LWT"
#define D_MODULE "Modul"
#define D_MOISTURE "Umezeală"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "selectare multiplă"
#define D_NOISE "Zgomot"
#define D_NONE "Lipsă"
#define D_OFF "Închis"
#define D_OFFLINE "Offline"
#define D_OK "Ok"
#define D_ON "Aprins"
#define D_ONLINE "Online"
#define D_PASSWORD "Parolă"
#define D_PORT "Port"
#define D_POWER_FACTOR "Factor de Putere"
#define D_POWERUSAGE "Putere"
#define D_POWERUSAGE_ACTIVE "Putere Activă"
#define D_POWERUSAGE_APPARENT "Putere Aparentă"
#define D_POWERUSAGE_REACTIVE "Putere Reactivă"
#define D_PRESSURE "Presiune"
#define D_PRESSUREATSEALEVEL "Presiune atmosferică"
#define D_PROGRAM_FLASH_SIZE "Mărimea Programului Flash"
#define D_PROGRAM_SIZE "Mărimea Programului"
#define D_PROJECT "Proiect"
#define D_RAIN "Ploaie"
#define D_RANGE "Distanță"
#define D_RECEIVED "Primit"
#define D_RESTART "Restart"
#define D_RESTARTING "Restartare"
#define D_RESTART_REASON "Motiv Restartare"
#define D_RESTORE "Restaurare"
#define D_RETAINED "Păstrare"
#define D_RULE "Regulă"
#define D_SAVE "Salvare"
#define D_SENSOR "Senzor"
#define D_SSID "SSId"
#define D_START "Start"
#define D_STD_TIME "STD"
#define D_STOP "Stop"
#define D_SUBNET_MASK "Subnet Mask"
#define D_SUBSCRIBE_TO "Înscriere la"
#define D_UNSUBSCRIBE_FROM "Renunțare de la"
#define D_SUCCESSFUL "Succes"
#define D_SUNRISE "Răsărit"
#define D_SUNSET "Apus"
#define D_TEMPERATURE "Temperatură"
#define D_TO "la"
#define D_TOGGLE "Comută"
#define D_TOPIC "Topic"
#define D_TOTAL_USAGE "Folosință totală"
#define D_TRANSMIT "Transmitere"
#define D_TRUE "Adevărat"
#define D_TVOC "TVOC"
#define D_UPGRADE "actualizare"
#define D_UPLOAD "Încarcare"
#define D_UPTIME "Folosință"
#define D_USER "Utilizator"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "Index UV"
#define D_UV_INDEX_1 "Mic"
#define D_UV_INDEX_2 "Mediu"
#define D_UV_INDEX_3 "Mare"
#define D_UV_INDEX_4 "Pericol"
#define D_UV_INDEX_5 "ArdereL1/2"
#define D_UV_INDEX_6 "ArdereL3"
#define D_UV_INDEX_7 "În afara intervalului"         // Out of Range
#define D_UV_LEVEL "Nivel UV"
#define D_UV_POWER "Putere UV"
#define D_VERSION "Versiune"
#define D_VOLTAGE "Voltaj"
#define D_WEIGHT "Greutate"
#define D_WARMLIGHT "Cald"
#define D_WEB_SERVER "Server Web"

// tasmota.ino
#define D_WARNING_MINIMAL_VERSION "ATENȚIE Această versiune nu suportă setări permanente"
#define D_LEVEL_10 "nivel 1-0"
#define D_LEVEL_01 "nivel 0-1"
#define D_SERIAL_LOGGING_DISABLED "Logare serială dezactivată"
#define D_SYSLOG_LOGGING_REENABLED "Logare Syslog activată"

#define D_SET_BAUDRATE_TO "Setare Baudrate la"
#define D_RECEIVED_TOPIC "Listă Primită"
#define D_DATA_SIZE "Mărime Date"
#define D_ANALOG_INPUT "Analog"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Circuit blocat"
#define D_WPS_FAILED_WITH_STATUS "status WPSconfig EȘUAT"
#define D_ACTIVE_FOR_3_MINUTES "activ pentru 3 minute"
#define D_FAILED_TO_START "start eșuat"
#define D_PATCH_ISSUE_2186 "emitere patch 2186"
#define D_CONNECTING_TO_AP "Conectare la AP"
#define D_IN_MODE "in mode"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "Conexiune eșuată, lipsă primire adresă IP"
#define D_CONNECT_FAILED_AP_NOT_REACHED "Conexiune eșuată,nu s-a găsit AP"
#define D_CONNECT_FAILED_WRONG_PASSWORD "Conexiune eșuată,parolă greșită AP"
#define D_CONNECT_FAILED_AP_TIMEOUT "Conexiune eșuată,expirare timp AP"
#define D_ATTEMPTING_CONNECTION "Conectare in curs ..."
#define D_CHECKING_CONNECTION "Verificare conexiune..."
#define D_QUERY_DONE "Query terminat. Servicii MQTT găsite"
#define D_MQTT_SERVICE_FOUND "Servicii MQTT găsite"
#define D_FOUND_AT "Găsite la"
#define D_SYSLOG_HOST_NOT_FOUND "Lipsă gazdă Syslog"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Salvat pe flash la"
#define D_LOADED_FROM_FLASH_AT "Încărcat din flash la"
#define D_USE_DEFAULTS "Folosește setari fabrica"
#define D_ERASED_SECTOR "Sector șters"

// xdrv_02_webserver.ino
#define D_NOSCRIPT "Pentru a folosi Tasmota, vă rugăm abilitați JavaScript"
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "firmware MINIMAL<br>vă rugăm actualizați"
#define D_WEBSERVER_ACTIVE_ON "Server Web activ"
#define D_WITH_IP_ADDRESS "cu adresa IP "
#define D_WEBSERVER_STOPPED "Server Web oprit"
#define D_FILE_NOT_FOUND "Lipsă fișier"
#define D_REDIRECTED "Redirecționat la captive portal"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifimanager set AccessPoint cu păstrare Stație"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifimanager set AccessPoint"
#define D_TRYING_TO_CONNECT "Încercare conectare la rețea"

#define D_RESTART_IN "Restart în"
#define D_SECONDS "secunde"
#define D_DEVICE_WILL_RESTART "echipamentul va reporni în cateva secunde"
#define D_BUTTON_TOGGLE "Comutare"
#define D_CONFIGURATION "Configurație"
#define D_INFORMATION "Informație"
#define D_FIRMWARE_UPGRADE "Actualizare Firmware"
#define D_CONSOLE "Consolă"
#define D_CONFIRM_RESTART "Confirmare Restart"

#define D_CONFIGURE_MODULE "Configurare Modul"
#define D_CONFIGURE_WIFI "Configurare WiFi"
#define D_CONFIGURE_MQTT "Configurare MQTT"
#define D_CONFIGURE_DOMOTICZ "Configurare Domoticz"
#define D_CONFIGURE_LOGGING "Configurare Logging"
#define D_CONFIGURE_OTHER "Altă configurare"
#define D_CONFIRM_RESET_CONFIGURATION "Confirmă Reset Configurare"
#define D_RESET_CONFIGURATION "Reseteaza Configurare"
#define D_BACKUP_CONFIGURATION "Backup Configurare"
#define D_RESTORE_CONFIGURATION "Restaurează Configurație"
#define D_MAIN_MENU "Meniu Principal"

#define D_MODULE_PARAMETERS "Parametri modul"
#define D_MODULE_TYPE "Tip modul"
#define D_PULLUP_ENABLE "Fără Buton/Întrerupător"
#define D_ADC "ADC"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Intrare Serială"
#define D_SERIAL_OUT "Ieșire Serială"

#define D_WIFI_PARAMETERS "Parameteri Wifi"
#define D_SCAN_FOR_WIFI_NETWORKS "Scanare rețele wifi"
#define D_SCAN_DONE "Scanare terminată"
#define D_NO_NETWORKS_FOUND "Lipsă rețele găsite"
#define D_REFRESH_TO_SCAN_AGAIN "Refresh pentru o nouă scanare"
#define D_DUPLICATE_ACCESSPOINT "Clonează AccessPoint"
#define D_SKIPPING_LOW_QUALITY "Omite,joasă calitate"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "AP1 SSId"
#define D_AP1_PASSWORD "Parolă AP1"
#define D_AP2_SSID "AP2 SSId"
#define D_AP2_PASSWORD "Parolă AP2"

#define D_MQTT_PARAMETERS "parametri MQTT"
#define D_CLIENT "Client"
#define D_FULL_TOPIC "Full Topic"

#define D_LOGGING_PARAMETERS "parametri Logging"
#define D_SERIAL_LOG_LEVEL "Nivel Serial log"
#define D_MQTT_LOG_LEVEL "Nivel Mqtt log"
#define D_WEB_LOG_LEVEL "Nivel Web log"
#define D_SYS_LOG_LEVEL "Nivel Syslog"
#define D_MORE_DEBUG "Depanare detailată"
#define D_SYSLOG_HOST "Syslog Gazdă "
#define D_SYSLOG_PORT "Syslog port"
#define D_TELEMETRY_PERIOD "Perioadă Telemetrie"

#define D_OTHER_PARAMETERS "Alți paramatri"
#define D_TEMPLATE "Template"
#define D_ACTIVATE "Activare"
#define D_WEB_ADMIN_PASSWORD "Parolă Web Admin"
#define D_MQTT_ENABLE "Abilitare MQTT"
#define D_FRIENDLY_NAME "Friendly Name"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "echipament unic"
#define D_MULTI_DEVICE "echipament multiplu"

#define D_CONFIGURE_TEMPLATE "Configurare Template"
#define D_TEMPLATE_PARAMETERS "Parametri Template"
#define D_TEMPLATE_NAME "Nume"
#define D_BASE_TYPE "Bazat pe"
#define D_TEMPLATE_FLAGS "Opțiuni"

#define D_SAVE_CONFIGURATION "Salvează configurația"
#define D_CONFIGURATION_SAVED "Configurația salvată"
#define D_CONFIGURATION_RESET "Configurația resetată"

#define D_PROGRAM_VERSION "Versiunea Program"
#define D_BUILD_DATE_AND_TIME "Creare Data & Timp"
#define D_CORE_AND_SDK_VERSION "Versiunea Core/SDK"
#define D_FLASH_WRITE_COUNT "Spațiu Flash scris"
#define D_MAC_ADDRESS "Adresă MAC"
#define D_MQTT_HOST "Gazdă MQTT"
#define D_MQTT_PORT "Port MQTT"
#define D_MQTT_CLIENT "Client MQTT"
#define D_MQTT_USER "Uilizator MQTT"
#define D_MQTT_TOPIC "Listă MQTT"
#define D_MQTT_GROUP_TOPIC "Listă Grup MQTT"
#define D_MQTT_FULL_TOPIC "Listă Întreagă MQTT"
#define D_MDNS_DISCOVERY "Descoperă mDNS"
#define D_MDNS_ADVERTISE "Publică mDNS"
#define D_ESP_CHIP_ID "ESP Chip Id"
#define D_FLASH_CHIP_ID "Flash Chip Id"
#define D_FLASH_CHIP_SIZE "Mărime Flash"
#define D_FREE_PROGRAM_SPACE "Spațiu Disponibil Program"

#define D_UPGRADE_BY_WEBSERVER "Actualizat de web server"
#define D_OTA_URL "OTA Url"
#define D_START_UPGRADE "Porneste actualizare"
#define D_UPGRADE_BY_FILE_UPLOAD "Actualizare cu încărcare fișier"
#define D_UPLOAD_STARTED "Încărcare începută"
#define D_UPGRADE_STARTED "Actualizare începută"
#define D_UPLOAD_DONE "Încărcare terminată"
#define D_UPLOAD_ERR_1 "Nici un fișier selectat"
#define D_UPLOAD_ERR_2 "Spațiu insuficient"
#define D_UPLOAD_ERR_3 "Magic byte nu este 0xE9"
#define D_UPLOAD_ERR_4 "Dimensiunea programului este mai mare decât mărimea memoriei"
#define D_UPLOAD_ERR_5 "Încărcare buffer necomparabil"
#define D_UPLOAD_ERR_6 "Încărcare eșuată. Abilitează logging 3"
#define D_UPLOAD_ERR_7 "Încărcare aulată"
#define D_UPLOAD_ERR_8 "Fișier invalid"
#define D_UPLOAD_ERR_9 "Fișier prea mare"
#define D_UPLOAD_ERR_10 "Inițiere chip RF eșuată"
#define D_UPLOAD_ERR_11 "Ștergere chip RF eșuată"
#define D_UPLOAD_ERR_12 "Scriere chip RF eșuată"
#define D_UPLOAD_ERR_13 "Decodare RF firmware eșuată"
#define D_UPLOAD_ERR_14 "Incompatibil"
#define D_UPLOAD_ERROR_CODE "Încărcare cod eroare"

#define D_ENTER_COMMAND "Introdu comandă"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Abilitează weblog 2 dacă există răspunsul așteptat"
#define D_NEED_USER_AND_PASSWORD "Necesită utilizator=<nume utilizator>&parolă=<parolă>"

// xdrv_01_mqtt.ino
#define D_FINGERPRINT "Verifică amprenta TLS..."
#define D_TLS_CONNECT_FAILED_TO "Conexiune TLS eșuată"
#define D_RETRY_IN "Reâncearcă în"
#define D_VERIFIED "Verificat folosind amprenta"
#define D_INSECURE "Conexiune nesigură din cauza amprentei eșuate"
#define D_CONNECT_FAILED_TO "Eșuare conectare la"

// xplg_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast dezabilitat"
#define D_MULTICAST_REJOINED "Multicast (re)conectat"
#define D_MULTICAST_JOIN_FAILED "Multicast conectare eșuată"
#define D_FAILED_TO_SEND_RESPONSE "Trimitere răspuns eșuată"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo eveniment basic"
#define D_WEMO_EVENT_SERVICE "WeMo service eveniment"
#define D_WEMO_META_SERVICE "WeMo meta service"
#define D_WEMO_SETUP "Configurare WeMo"
#define D_RESPONSE_SENT "Răspuns trimis"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Configurare Hue"
#define D_HUE_API_NOT_IMPLEMENTED "Hue API neimplementat"
#define D_HUE_API "Hue API"
#define D_HUE_POST_ARGS "Hue POST args"
#define D_3_RESPONSE_PACKETS_SENT "3 pachete de răspuns trimise"

// xdrv_07_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Parametri Domoticz"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Key idx"
#define D_DOMOTICZ_SWITCH_IDX "Întrerupator idx"
#define D_DOMOTICZ_SENSOR_IDX "Senzor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,U!mid"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Umid,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Putere,Energie"
  #define D_DOMOTICZ_ILLUMINANCE "Iluminare"
  #define D_DOMOTICZ_COUNT "Contor/PM1"
  #define D_DOMOTICZ_VOLTAGE "Voltaj/PM2.5"
  #define D_DOMOTICZ_CURRENT "Curent/PM10"
  #define D_DOMOTICZ_AIRQUALITY "Calitatea Aerului"
  #define D_DOMOTICZ_P1_SMART_METER "P1SmartMeter"
#define D_DOMOTICZ_UPDATE_TIMER "Actualizare Cronometrare"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Configurare Cronometrare"
#define D_TIMER_PARAMETERS "Parameteri Cronometrare"
#define D_TIMER_ENABLE "Abilitează Cronometrare"
#define D_TIMER_ARM "Arm"
#define D_TIMER_TIME "Timp"
#define D_TIMER_DAYS "Zile"
#define D_TIMER_REPEAT "Repetă"
#define D_TIMER_OUTPUT "Ieșire"
#define D_TIMER_ACTION "Acțiune"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Configurare KNX"
#define D_KNX_PARAMETERS "Parameteri KNX"
#define D_KNX_GENERAL_CONFIG "General"
#define D_KNX_PHYSICAL_ADDRESS "Adresă fizică"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "(Trebuie să fie unică în rețeaua KNX)"
#define D_KNX_ENABLE "Abilitează KNX"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Data de trimis la adresele grupului"
#define D_ADD "Adaugă"
#define D_DELETE "Șterge"
#define D_REPLY "Răspunde"
#define D_KNX_GROUP_ADDRESS_TO_READ "Datele primite pentru adresele grupului"
#define D_RECEIVED_FROM "Primit de la"
#define D_KNX_COMMAND_WRITE "Scrie"
#define D_KNX_COMMAND_READ "Citește"
#define D_KNX_COMMAND_OTHER "Altele"
#define D_SENT_TO "trimite la"
#define D_KNX_WARNING "Adresa grupului ( 0 / 0 / 0 ) este rezervată și nu se poate folosi."
#define D_KNX_ENHANCEMENT "Îmbunătățire Communicație"
#define D_KNX_TX_SLOT "KNX TX"
#define D_KNX_RX_SLOT "KNX RX"

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Energia de Azi"
#define D_ENERGY_YESTERDAY "Energia de Ieri"
#define D_ENERGY_TOTAL "Energia Totală"

// xdrv_27_shutter.ino
#define D_OPEN "Deschide"
#define D_CLOSE "Inchide"
#define D_DOMOTICZ_SHUTTER "Shutter"

// xdrv_28_pcf8574.ino
#define D_CONFIGURE_PCF8574 "Configurează PCF8574"
#define D_PCF8574_PARAMETERS "Parameteri PCF8574"
#define D_INVERT_PORTS "Inversează Porturile"
#define D_DEVICE "echipament"
#define D_DEVICE_INPUT "Intrare"
#define D_DEVICE_OUTPUT "Ieșire"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Senzor ocupat"
#define D_SENSOR_CRC_ERROR "Eroare senzor CRC"
#define D_SENSORS_FOUND "Descoperit senzor"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Timp expirat așteptare pentru"
#define D_START_SIGNAL_LOW "Semnal inițiere mic"
#define D_START_SIGNAL_HIGH "Semnal inițiere mare"
#define D_PULSE "puls"
#define D_CHECKSUM_FAILURE "Eroare Checksum"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Senzorul nu a primit comanda ACK"
#define D_SHT1X_FOUND " Descoperit SHT1X"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Particule"

// xsns_32_mpu6050.ino
#define D_AX_AXIS "Accel.Axa-X"
#define D_AY_AXIS "Accel.Axa-Y"
#define D_AZ_AXIS "Accel.Axa-Z"
#define D_GX_AXIS "Gyro Axa-X"
#define D_GY_AXIS "Gyro Axa-Y"
#define D_GZ_AXIS "Gyro Axa-Z"

// xsns_34_hx711.ino
#define D_HX_CAL_REMOVE "Elimină greutatea"
#define D_HX_CAL_REFERENCE "Așează greutatea de referință"
#define D_HX_CAL_DONE "Calibrat"
#define D_HX_CAL_FAIL "Eroare Calibrare"
#define D_RESET_HX711 "Reset Balanța"
#define D_CONFIGURE_HX711 "Configurare Balanța"
#define D_HX711_PARAMETERS "Parametri Balanța"
#define D_ITEM_WEIGHT "Greutatea obiectului"
#define D_REFERENCE_WEIGHT "Greutatea de referință"
#define D_CALIBRATE "Calibrează"
#define D_CALIBRATION "Execută Calibrarea"

//xsns_35_tx20.ino
#define D_TX20_WIND_DIRECTION "Direcția vântului"
#define D_TX20_WIND_SPEED "Viteza vântului"
#define D_TX20_WIND_SPEED_MIN "Viteza vântului Min"
#define D_TX20_WIND_SPEED_MAX "Viteza vântului Max"
#define D_TX20_NORTH "N"
#define D_TX20_EAST "E"
#define D_TX20_SOUTH "S"
#define D_TX20_WEST "V"

// xsns_53_sml.ino 
#define D_TPWRIN "Energy Total-In"
#define D_TPWROUT "Energy Total-Out"
#define D_TPWRCURR "Active Power-In/Out"
#define D_TPWRCURR1 "Active Power-In p1"
#define D_TPWRCURR2 "Active Power-In p2"
#define D_TPWRCURR3 "Active Power-In p3"
#define D_Strom_L1 "Current L1"
#define D_Strom_L2 "Current L2"
#define D_Strom_L3 "Current L3"
#define D_Spannung_L1 "Voltage L1"
#define D_Spannung_L2 "Voltage L2"
#define D_Spannung_L3 "Voltage L3"
#define D_METERNR "Meter_number"
#define D_METERSID "Service ID"
#define D_GasIN "Counter"
#define D_H2oIN "Counter"
#define D_StL1L2L3 "Current L1+L2+L3"
#define D_SpL1L2L3 "Voltage L1+L2+L3/3"

// tasmota_template.h - keep them as short as possible to be able to fit them in GUI drop down box
#define D_SENSOR_NONE          "Fără"
#define D_SENSOR_USER          "Utilizator"
#define D_SENSOR_DHT11         "DHT11"
#define D_SENSOR_AM2301        "AM2301"
#define D_SENSOR_SI7021        "SI7021"
#define D_SENSOR_DS18X20       "DS18x20"
#define D_SENSOR_I2C_SCL       "I2C SCL"
#define D_SENSOR_I2C_SDA       "I2C SDA"
#define D_SENSOR_WS2812        "WS2812"
#define D_SENSOR_DFR562        "MP3 Player"
#define D_SENSOR_IRSEND        "IRsend"
#define D_SENSOR_SWITCH        "Întrerupator"     // Suffix "1"
#define D_SENSOR_BUTTON        "Buton"     // Suffix "1"
#define D_SENSOR_RELAY         "Releu"      // Suffix "1i"
#define D_SENSOR_LED           "Led"        // Suffix "1i"
#define D_SENSOR_LED_LINK      "LedLink"    // Suffix "i"
#define D_SENSOR_PWM           "PWM"        // Suffix "1"
#define D_SENSOR_COUNTER       "Contor"    // Suffix "1"
#define D_SENSOR_IRRECV        "IRrecv"
#define D_SENSOR_MHZ_RX        "MHZ Rx"
#define D_SENSOR_MHZ_TX        "MHZ Tx"
#define D_SENSOR_PZEM004_RX    "PZEM004 Rx"
#define D_SENSOR_PZEM016_RX    "PZEM016 Rx"
#define D_SENSOR_PZEM017_RX    "PZEM017 Rx"
#define D_SENSOR_PZEM0XX_TX    "PZEM0XX Tx"
#define D_SENSOR_SAIR_RX       "SAir Rx"
#define D_SENSOR_SAIR_TX       "SAir Tx"
#define D_SENSOR_SPI_CS        "SPI CS"
#define D_SENSOR_SPI_DC        "SPI DC"
#define D_SENSOR_SPI_MISO      "SPI MISO"
#define D_SENSOR_SPI_MOSI      "SPI MOSI"
#define D_SENSOR_SPI_CLK       "SPI CLK"
#define D_SENSOR_BACKLIGHT     "Backlight"
#define D_SENSOR_PMS5003       "PMS5003"
#define D_SENSOR_SDS0X1_RX     "SDS0X1 Rx"
#define D_SENSOR_SDS0X1_TX     "SDS0X1 Tx"
#define D_SENSOR_HPMA_RX       "HPMA Rx"
#define D_SENSOR_HPMA_TX       "HPMA Tx"
#define D_SENSOR_SBR_RX        "SerBr Rx"
#define D_SENSOR_SBR_TX        "SerBr Tx"
#define D_SENSOR_SR04_TRIG     "SR04 Tri/TX"
#define D_SENSOR_SR04_ECHO     "SR04 Ech/RX"
#define D_SENSOR_SDM120_TX     "SDMx20 Tx"
#define D_SENSOR_SDM120_RX     "SDMx20 Rx"
#define D_SENSOR_SDM630_TX     "SDM630 Tx"
#define D_SENSOR_SDM630_RX     "SDM630 Rx"
#define D_SENSOR_TM1638_CLK    "TM16 CLK"
#define D_SENSOR_TM1638_DIO    "TM16 DIO"
#define D_SENSOR_TM1638_STB    "TM16 STB"
#define D_SENSOR_HX711_SCK     "HX711 SCK"
#define D_SENSOR_HX711_DAT     "HX711 DAT"
#define D_SENSOR_TX2X_TX       "TX2x"
#define D_SENSOR_RFSEND        "RFSend"
#define D_SENSOR_RFRECV        "RFrecv"
#define D_SENSOR_TUYA_TX       "Tuya Tx"
#define D_SENSOR_TUYA_RX       "Tuya Rx"
#define D_SENSOR_MGC3130_XFER  "MGC3130 Xfr"
#define D_SENSOR_MGC3130_RESET "MGC3130 Rst"
#define D_SENSOR_SSPI_MISO     "SSPI MISO"
#define D_SENSOR_SSPI_MOSI     "SSPI MOSI"
#define D_SENSOR_SSPI_SCLK     "SSPI SCLK"
#define D_SENSOR_SSPI_CS       "SSPI CS"
#define D_SENSOR_SSPI_DC       "SSPI DC"
#define D_SENSOR_RF_SENSOR     "RF Sensor"
#define D_SENSOR_AZ_RX         "AZ Rx"
#define D_SENSOR_AZ_TX         "AZ Tx"
#define D_SENSOR_MAX31855_CS   "MX31855 CS"
#define D_SENSOR_MAX31855_CLK  "MX31855 CLK"
#define D_SENSOR_MAX31855_DO   "MX31855 DO"
#define D_SENSOR_NRG_SEL       "HLWBL SEL"  // Suffix "i"
#define D_SENSOR_NRG_CF1       "HLWBL CF1"
#define D_SENSOR_HLW_CF        "HLW8012 CF"
#define D_SENSOR_HJL_CF        "BL0937 CF"
#define D_SENSOR_MCP39F5_TX    "MCP39F5 Tx"
#define D_SENSOR_MCP39F5_RX    "MCP39F5 Rx"
#define D_SENSOR_MCP39F5_RST   "MCP39F5 Rst"
#define D_SENSOR_CSE7766_TX    "CSE7766 Tx"
#define D_SENSOR_CSE7766_RX    "CSE7766 Rx"
#define D_SENSOR_PN532_TX      "PN532 Tx"
#define D_SENSOR_PN532_RX      "PN532 Rx"
#define D_SENSOR_SM16716_CLK   "SM16716 CLK"
#define D_SENSOR_SM16716_DAT   "SM16716 DAT"
#define D_SENSOR_SM16716_POWER "SM16716 PWR"
#define D_SENSOR_MY92X1_DI     "MY92x1 DI"
#define D_SENSOR_MY92X1_DCKI   "MY92x1 DCKI"
#define D_SENSOR_ARIRFRCV      "ALux IrRcv"
#define D_SENSOR_ARIRFSEL      "ALux IrSel"
#define D_SENSOR_TXD           "Serial Tx"
#define D_SENSOR_RXD           "Serial Rx"
#define D_SENSOR_ROTARY        "Rotary"     // Suffix "1A"
#define D_SENSOR_HRE_CLOCK     "HRE Clock"
#define D_SENSOR_HRE_DATA      "HRE Data"
#define D_SENSOR_ADE7953_IRQ   "ADE7953 IRQ"
#define D_SENSOR_BUZZER        "Buzzer"
#define D_SENSOR_OLED_RESET    "OLED Reset"
#define D_SENSOR_ZIGBEE_TXD    "Zigbee Tx"
#define D_SENSOR_ZIGBEE_RXD    "Zigbee Rx"
#define D_SENSOR_SOLAXX1_TX    "SolaxX1 Tx"
#define D_SENSOR_SOLAXX1_RX    "SolaxX1 Rx"
#define D_SENSOR_IBEACON_TX    "iBeacon TX"
#define D_SENSOR_IBEACON_RX    "iBeacon RX"
#define D_SENSOR_RDM6300_RX    "RDM6300 RX"
#define D_SENSOR_CC1101_CS     "CC1101 CS"
#define D_SENSOR_A4988_DIR     "A4988 DIR"
#define D_SENSOR_A4988_STP     "A4988 STP"
#define D_SENSOR_A4988_ENA     "A4988 ENA"
#define D_SENSOR_A4988_MS1     "A4988 MS1"
#define D_SENSOR_A4988_MS2     "A4988 MS2"
#define D_SENSOR_A4988_MS3     "A4988 MS3"
#define D_SENSOR_DDS2382_TX    "DDS238-2 Tx"
#define D_SENSOR_DDS2382_RX    "DDS238-2 Rx"
#define D_SENSOR_DDSU666_TX    "DDSU666 Tx"
#define D_SENSOR_DDSU666_RX    "DDSU666 Rx"
#define D_SENSOR_SM2135_CLK    "SM2135 Clk"
#define D_SENSOR_SM2135_DAT    "SM2135 Dat"
#define D_SENSOR_DEEPSLEEP     "DeepSleep"
#define D_SENSOR_EXS_ENABLE    "EXS Enable"
#define D_SENSOR_SLAVE_TX    "Slave TX"
#define D_SENSOR_SLAVE_RX    "Slave RX"
#define D_SENSOR_SLAVE_RESET "Slave RST"
#define D_SENSOR_GPS_RX        "GPS RX"
#define D_SENSOR_GPS_TX        "GPS TX"
#define D_SENSOR_HM10_RX       "HM10 RX"
#define D_SENSOR_HM10_TX       "HM10 TX"
#define D_SENSOR_LE01MR_RX     "LE-01MR Rx"
#define D_SENSOR_LE01MR_TX     "LE-01MR Tx"
#define D_SENSOR_CC1101_GDO0   "CC1101 GDO0"
#define D_SENSOR_CC1101_GDO2   "CC1101 GDO2"
#define D_SENSOR_HRXL_RX       "HRXL Rx"

// Units
#define D_UNIT_AMPERE "A"
#define D_UNIT_CENTIMETER "cm"
#define D_UNIT_HERTZ "Hz"
#define D_UNIT_HOUR "h"
#define D_UNIT_GALLONS "gal"
#define D_UNIT_GALLONS_PER_MIN "g/m"
#define D_UNIT_INCREMENTS "inc"
#define D_UNIT_KILOGRAM "kg"
#define D_UNIT_KILOMETER_PER_HOUR "km/h"  // or "km/h"
#define D_UNIT_KILOOHM "kΩ"
#define D_UNIT_KILOWATTHOUR "kWh"
#define D_UNIT_LUX "lx"
#define D_UNIT_MICROGRAM_PER_CUBIC_METER "µg/m³"
#define D_UNIT_MICROMETER "µm"
#define D_UNIT_MICROSECOND "µs"
#define D_UNIT_MILLIAMPERE "mA"
#define D_UNIT_MILLIMETER "mm"
#define D_UNIT_MILLIMETER_MERCURY "mmHg"
#define D_UNIT_MILLISECOND "ms"
#define D_UNIT_MINUTE "Min"
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "sec"
#define D_UNIT_SECTORS "sectors"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "Wh"
#define D_UNIT_WATT_METER_QUADRAT "W/m²"

//SDM220, SDM120, LE01MR
#define D_PHASE_ANGLE     "Unghi de fază"
#define D_IMPORT_ACTIVE   "Import Activ"
#define D_EXPORT_ACTIVE   "Export Activ"
#define D_IMPORT_REACTIVE "Import Reactiv"
#define D_EXPORT_REACTIVE "Export Reactiv"
#define D_TOTAL_REACTIVE  "Total Reactiv"
#define D_UNIT_KWARH      "kVArh"
#define D_UNIT_ANGLE      "Deg"
#define D_TOTAL_ACTIVE    "Total Activ"

//SOLAXX1
#define D_PV1_VOLTAGE     "PV1 Voltaj"
#define D_PV1_CURRENT     "PV1 Curent"
#define D_PV1_POWER       "PV1 Putere"
#define D_PV2_VOLTAGE     "PV2 Voltaj"
#define D_PV2_CURRENT     "PV2 Curent"
#define D_PV2_POWER       "PV2 Putere"
#define D_SOLAR_POWER     "Putere Solară"
#define D_INVERTER_POWER  "Invertor Putere"
#define D_STATUS          "Status"
#define D_WAITING         "Așteptare"
#define D_CHECKING        "Verificare"
#define D_WORKING         "Lucrează"
#define D_FAILURE         "Eroare"
#define D_SOLAX_ERROR_0   "Fără cod de eroare"
#define D_SOLAX_ERROR_1   "Eroare zona"
#define D_SOLAX_ERROR_2   "Eroare zona voltaj"
#define D_SOLAX_ERROR_3   "Eroare zona frecvență"
#define D_SOLAX_ERROR_4   "Pv Eroare Voltaj"
#define D_SOLAX_ERROR_5   "Eroare Isolație"
#define D_SOLAX_ERROR_6   "Eroare temperatură ridicată"
#define D_SOLAX_ERROR_7   "Eroare ventilator"
#define D_SOLAX_ERROR_8   "Eroare alt echipament"

//xdrv_10_scripter.ino
#define D_CONFIGURE_SCRIPT     "Configurare script"
#define D_SCRIPT               "editează script"
#define D_SDCARD_UPLOAD        "Încarcă fișier"
#define D_SDCARD_DIR           "director sd card"
#define D_UPL_DONE             "Terminat"
#define D_SCRIPT_CHARS_LEFT    "caractere rămase"
#define D_SCRIPT_CHARS_NO_MORE "caractere terminate"
#define D_SCRIPT_DOWNLOAD      "Descarcă"
#define D_SCRIPT_ENABLE        "abilitează script"
#define D_SCRIPT_UPLOAD        "Încarcă"
#define D_SCRIPT_UPLOAD_FILES  "Încarcă fișiere"

#endif  // _LANGUAGE_RO_RO_H_
