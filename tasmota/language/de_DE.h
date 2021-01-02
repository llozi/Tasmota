/*
  de-DE.h - localization for German - Germany for Tasmota

  Copyright (C) 2021  VinceMasuka

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

#ifndef _LANGUAGE_DE_DE_H_
#define _LANGUAGE_DE_DE_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v9.2.0.1
\*********************************************************************/

//#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)

#define LANGUAGE_LCID 1031
// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "de"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "."
#define D_MONTH_DAY_SEPARATOR "."
#define D_DATE_TIME_SEPARATOR " "
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "So Mo Di Mi Do Fr Sa "
#define D_MONTH3LIST "JanFebMärAprMaiJunJulAugSepOktNovDez"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR "."

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Luftqualität"
#define D_AP "AP"                    // Access Point
#define D_AS "als"
#define D_AUTO "AUTO"
#define D_BATT "Batt"                // Short for Battery
#define D_BLINK "Blinken"
#define D_BLINKOFF "BlinkenAus"
#define D_BOOT_COUNT "Anzahl Startvorgänge"
#define D_BRIGHTLIGHT "hell"
#define D_BSSID "BSSId"
#define D_BUTTON "Knopf"
#define D_BY "von"                   // Written by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CHANNEL "Kanal"
#define D_CO2 "CO₂"
#define D_CODE "code"                // Button code
#define D_COLDLIGHT "kalt"
#define D_COMMAND "Befehl"
#define D_CONNECTED "verbunden"
#define D_CORS_DOMAIN "CORS Domain"
#define D_COUNT "zählen"
#define D_COUNTER "Zähler"
#define D_CT_POWER "CT Power"
#define D_CURRENT "Strom"          // As in Voltage and Current
#define D_DATA "Daten"
#define D_DARKLIGHT "dunkel"
#define D_DEBUG "debug"
#define D_DEWPOINT "Taupunkt"
#define D_DISABLED "deaktiviert"
#define D_DISTANCE "Abstand"
#define D_DNS_SERVER "DNS-Server"
#define D_DO "Disolved Oxygen"
#define D_DONE "erledigt"
#define D_DST_TIME "DST"
#define D_EC "EC"
#define D_ECO2 "eCO₂"
#define D_EMULATION "Emulation"
#define D_ENABLED "aktiviert"
#define D_ERASE "löschen"
#define D_ERROR "Fehler"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "fehlgeschlagen"
#define D_FALLBACK "Fallback"
#define D_FALLBACK_TOPIC "Fallback-Topic"
#define D_FALSE "falsch"
#define D_FILE "Datei"
#define D_FLOW_RATE "Durchflussmenge"
#define D_FREE_MEMORY "Freier Arbeitsspeicher"
#define D_PSR_MAX_MEMORY "PS-RAM Speicher"
#define D_PSR_FREE_MEMORY "PS-RAM freier Speicher"
#define D_FREQUENCY "Frequenz"
#define D_GAS "Gas"
#define D_GATEWAY "Gateway"
#define D_GROUP "Gruppe"
#define D_HOST "Host"
#define D_HOSTNAME "Hostname"
#define D_HUMIDITY "Feuchtigkeit"
#define D_ILLUMINANCE "Beleuchtungsstärke"
#define D_IMMEDIATE "direkt"      // Button immediate
#define D_INDEX "Index"
#define D_INFO "Info"
#define D_INFRARED "Infrarot"
#define D_INITIALIZED "initialisiert"
#define D_IP_ADDRESS "IP-Adresse"
#define D_LIGHT "Licht"
#define D_LWT "LWT"
#define D_LQI "LQI"                  // Zigbee Link Quality Index
#define D_MODULE "Modul"
#define D_MOISTURE "Feuchtigkeit"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "Mehrfachdruck"
#define D_NOISE "Lautstärke"
#define D_NONE "keine"
#define D_O2 "Sauerstoff"
#define D_OFF "aus"
#define D_OFFLINE "Offline"
#define D_OK "OK"
#define D_ON "an"
#define D_ONLINE "Online"
#define D_ORP "ORP"
#define D_PASSWORD "Passwort"
#define D_PH "pH"
#define D_PORT "Port"
#define D_POWER_FACTOR "Leistungsfaktor"
#define D_POWERUSAGE "Leistung"
#define D_POWERUSAGE_ACTIVE "Wirkleistung"
#define D_POWERUSAGE_APPARENT "Scheinleistung"
#define D_POWERUSAGE_REACTIVE "Blindleistung"
#define D_PRESSURE "Luftdruck"
#define D_PRESSUREATSEALEVEL "Luftdruck auf Meereshöhe"
#define D_PROGRAM_FLASH_SIZE "Ges. Flash Speicher"
#define D_PROGRAM_SIZE "Ben. Flash Speicher"
#define D_PROJECT "Projekt"
#define D_RAIN "Regen"
#define D_RANGE "Bereich"
#define D_RECEIVED "erhalten"
#define D_RESTART "Neustart"
#define D_RESTARTING "starte neu"
#define D_RESTART_REASON "Grund für Neustart"
#define D_RESTORE "Wiederherstellung"
#define D_RETAINED "beibehalten"
#define D_RULE "Regel"
#define D_SAVE "Speichern"
#define D_SENSOR "Sensor"
#define D_SSID "SSID"
#define D_START "Start"
#define D_STD_TIME "STD"
#define D_STOP "Stop"
#define D_SUBNET_MASK "Subnetzmaske"
#define D_SUBSCRIBE_TO "abonniere"
#define D_UNSUBSCRIBE_FROM "löse abo. von"
#define D_SUCCESSFUL "erfolgreich"
#define D_SUNRISE "Sonnenaufgang"
#define D_SUNSET "Sonnenuntergang"
#define D_TEMPERATURE "Temperatur"
#define D_TO "zu"
#define D_TOGGLE "An/Aus"
#define D_TOPIC "topic"
#define D_TOTAL_USAGE "Gesamtverbrauch"
#define D_TRANSMIT "Übertragen"
#define D_TRUE "wahr"
#define D_TVOC "TVOC"
#define D_UPGRADE "update"
#define D_UPLOAD "Upload"
#define D_UPTIME "Laufzeit"
#define D_USER "Benutzer"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "UV-Index"
#define D_UV_INDEX_1 "Niedrig"
#define D_UV_INDEX_2 "Mittel"
#define D_UV_INDEX_3 "Hoch"
#define D_UV_INDEX_4 "Intensiv"
#define D_UV_INDEX_5 "Gefährlich"
#define D_UV_INDEX_6 "Schädlich"
#define D_UV_INDEX_7 "Messwert!"
#define D_UV_LEVEL "UV-Level"
#define D_UV_POWER "UV Intensität"
#define D_VERSION "Version"
#define D_VOLTAGE "Spannung"
#define D_VOLUME "Volume"
#define D_WEIGHT "Gewicht"
#define D_WARMLIGHT "warm"
#define D_WEB_SERVER "Web-Server"

// tasmota.ino
#define D_WARNING_MINIMAL_VERSION "ACHTUNG: Diese Version unterstützt keine persistenten Einstellungen"
#define D_LEVEL_10 "level 1-0"
#define D_LEVEL_01 "level 0-1"
#define D_SERIAL_LOGGING_DISABLED "Serielles Logging deaktiviert"
#define D_SYSLOG_LOGGING_REENABLED "Syslog-Logging aktiviert"

#define D_SET_BAUDRATE_TO "Setze Baudrate auf"
#define D_RECEIVED_TOPIC "empfangenes topic"
#define D_DATA_SIZE "Datengröße"
#define D_ANALOG_INPUT "Analog"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Schleife blockiert."
#define D_WPS_FAILED_WITH_STATUS "WPS fehlgeschlagen mit Status"
#define D_ACTIVE_FOR_3_MINUTES "aktiv für 3 Minuten"
#define D_FAILED_TO_START "Starten fehlgeschlagen"
#define D_PATCH_ISSUE_2186 "Repariere Problem #2186"
#define D_CONNECTING_TO_AP "verbinden mit AP"
#define D_IN_MODE "in Modus"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "Verbindung fehlgeschlagen, da keine IP-Adresse zugeteilt wurde"
#define D_CONNECT_FAILED_AP_NOT_REACHED "Verbindung fehlgeschlagen, da AP nicht erreicht werden konnte"
#define D_CONNECT_FAILED_WRONG_PASSWORD "Verbindung fehlgeschlagen"
#define D_CONNECT_FAILED_AP_TIMEOUT "Verbindung fehlgeschlagen, da der AP nicht antwortet (timeout)"
#define D_ATTEMPTING_CONNECTION "Verbindungsversuch..."
#define D_CHECKING_CONNECTION "Prüfe Verbindung..."
#define D_QUERY_DONE "Suchanfrage abgeschlossen. MQTT-Services gefunden"
#define D_MQTT_SERVICE_FOUND "MQTT-Service gefunden bei"
#define D_FOUND_AT "gefunden bei"
#define D_SYSLOG_HOST_NOT_FOUND "Syslog-Host nicht gefunden"

// settings.ino
#define D_SAVED_TO_FLASH_AT "in Flash gespeichert am"
#define D_LOADED_FROM_FLASH_AT "aus Flash geladen am"
#define D_USE_DEFAULTS "Standard verwenden"
#define D_ERASED_SECTOR "gelöschter Sektor"

// xdrv_02_webserver.ino
#define D_NOSCRIPT "JavaScript aktivieren um Tasmota benutzen zu können"
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "MINIMUM-Firmware<br>bitte upgraden"
#define D_WEBSERVER_ACTIVE_ON "Web-Server aktiv bei"
#define D_WITH_IP_ADDRESS "mit IP-Adresse"
#define D_WEBSERVER_STOPPED "Web-Server angehalten"
#define D_FILE_NOT_FOUND "Datei nicht gefunden"
#define D_REDIRECTED "umgeleitet zu captive portal"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "WLAN-Manager AccessPoint gesetzt und behält Station"
#define D_WIFIMANAGER_SET_ACCESSPOINT "WLAN-Manager AccessPoint gesetzt"
#define D_TRYING_TO_CONNECT "Versuche Gerät mit Netzwerk zu verbinden"

#define D_RESTART_IN "Neustart in"
#define D_SECONDS "Sekunden"
#define D_DEVICE_WILL_RESTART "Gerät wird jetzt neu gestartet"
#define D_BUTTON_TOGGLE "An/Aus"
#define D_CONFIGURATION "Einstellungen"
#define D_INFORMATION "Informationen"
#define D_FIRMWARE_UPGRADE "Firmware Update"
#define D_CONSOLE "Konsole"
#define D_CONFIRM_RESTART "Wirklich neustarten?"

#define D_CONFIGURE_MODULE "Gerät konfigurieren"
#define D_CONFIGURE_WIFI "WLAN konfigurieren"
#define D_CONFIGURE_MQTT "MQTT konfigurieren"
#define D_CONFIGURE_DOMOTICZ "Domoticz konfigurieren"
#define D_CONFIGURE_LOGGING "Logging konfigurieren"
#define D_CONFIGURE_OTHER "Sonstige Konfiguration"
#define D_CONFIRM_RESET_CONFIGURATION "Zurücksetzen der Konfiguration bestätigen"
#define D_RESET_CONFIGURATION "Konfiguration zurücksetzen"
#define D_BACKUP_CONFIGURATION "Konfiguration sichern"
#define D_RESTORE_CONFIGURATION "Konfiguration wiederherstellen"
#define D_MAIN_MENU "Hauptmenü"

#define D_MODULE_PARAMETERS "Geräte-Einstellungen"
#define D_MODULE_TYPE "Gerätetyp"
#define D_PULLUP_ENABLE "Kein Taster/Schalter Pull-up"
#define D_ADC "ADC"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "serieller Eingang [serial in]"
#define D_SERIAL_OUT "serieller Ausgang [serial out]"

#define D_WIFI_PARAMETERS "WLAN-Einstellungen"
#define D_SCAN_FOR_WIFI_NETWORKS "WLAN-Netzwerk suchen und auswählen"
#define D_SCAN_DONE "Suche abgeschlossen"
#define D_NO_NETWORKS_FOUND "Keine Netzwerke gefunden"
#define D_REFRESH_TO_SCAN_AGAIN "Aktualisieren, um erneut zu suchen"
#define D_DUPLICATE_ACCESSPOINT "AccessPoint duplizieren"
#define D_SKIPPING_LOW_QUALITY "überspringe wegen niedriger Qualität"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA-PSK"
#define D_WPA2_PSK "WPA2-PSK"
#define D_AP1_SSID "WLAN 1 - SSID"
#define D_AP1_PASSWORD "WLAN 1 - Passwort"
#define D_AP2_SSID "WLAN 2 - SSID"
#define D_AP2_PASSWORD "WLAN 2 - Passwort"

#define D_MQTT_PARAMETERS "MQTT-Einstellungen"
#define D_CLIENT "client"
#define D_FULL_TOPIC "full topic"

#define D_LOGGING_PARAMETERS "Logging-Einstellungen"
#define D_SERIAL_LOG_LEVEL "Seriell-Log Level"
#define D_MQTT_LOG_LEVEL "Mqtt-Log Level"
#define D_WEB_LOG_LEVEL "Web-Log Level"
#define D_SYS_LOG_LEVEL "Sys-Log Level"
#define D_MORE_DEBUG "Mehr Details"
#define D_SYSLOG_HOST "Sys-Log Host"
#define D_SYSLOG_PORT "Sys-Log Port"
#define D_TELEMETRY_PERIOD "Telemetrieperiode"

#define D_OTHER_PARAMETERS "Sonstige Einstellungen"
#define D_TEMPLATE "Vorlage"
#define D_ACTIVATE "Aktivieren"
#define D_DEVICE_NAME "Device Name"
#define D_WEB_ADMIN_PASSWORD "Passwort für Web Oberfläche"
#define D_MQTT_ENABLE "MQTT aktivieren"
#define D_MQTT_TLS_ENABLE "MQTT TLS"
#define D_FRIENDLY_NAME "Name [friendly name]"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "Einzelnes Gerät"
#define D_MULTI_DEVICE "Mehrfachgerät"

#define D_CONFIGURE_TEMPLATE "Vorlage konfigurieren"
#define D_TEMPLATE_PARAMETERS "Vorlage Parameter"
#define D_TEMPLATE_NAME "Name"
#define D_BASE_TYPE "basiert auf"
#define D_TEMPLATE_FLAGS "Options"

#define D_SAVE_CONFIGURATION "Konfiguration speichern"
#define D_CONFIGURATION_SAVED "Konfiguration gespeichert"
#define D_CONFIGURATION_RESET "Konfiguration zurücksetzen"

#define D_PROGRAM_VERSION "Tasmota Version"
#define D_BUILD_DATE_AND_TIME "Build-Datum & -Uhrzeit"
#define D_CORE_AND_SDK_VERSION "Core-/SDK-Version"
#define D_FLASH_WRITE_COUNT "Anz. Flash Schreibzugriffe"
#define D_MAC_ADDRESS "MAC-Adresse"
#define D_MQTT_HOST "MQTT Host"
#define D_MQTT_PORT "MQTT Port"
#define D_MQTT_CLIENT "MQTT Client"
#define D_MQTT_USER "MQTT Benutzer"
#define D_MQTT_TOPIC "MQTT Topic"
#define D_MQTT_GROUP_TOPIC "MQTT Group Topic"
#define D_MQTT_FULL_TOPIC "MQTT Full Topic"
#define D_MQTT_NO_RETAIN "MQTT No Retain"
#define D_MDNS_DISCOVERY "mDNS-Ermittlung"
#define D_MDNS_ADVERTISE "mDNS-Bekanntmachung"
#define D_ESP_CHIP_ID "ESP Chip ID"
#define D_FLASH_CHIP_ID "Flash Chip ID"
#define D_FLASH_CHIP_SIZE "Realer Flash Speicher"
#define D_FREE_PROGRAM_SPACE "Verf. Flash Speicher"

#define D_UPGRADE_BY_WEBSERVER "Update über Web-Server"
#define D_OTA_URL "OTA-URL"
#define D_START_UPGRADE "Update starten"
#define D_UPGRADE_BY_FILE_UPLOAD "Update Datei hochladen"
#define D_UPLOAD_STARTED "Upload gestartet"
#define D_UPGRADE_STARTED "Update gestartet"
#define D_UPLOAD_DONE "Upload abgeschlossen"
#define D_UPLOAD_TRANSFER "Upload Übertragung"
#define D_TRANSFER_STARTED "Transfer gestartet"
#define D_UPLOAD_ERR_1 "Keine Datei ausgewählt"
#define D_UPLOAD_ERR_2 "Ungenügend Speicherplatz"
#define D_UPLOAD_ERR_3 "Falsche Dateisignatur"
#define D_UPLOAD_ERR_4 "Datei überschreitet vorhdn. Flashspeicher"
#define D_UPLOAD_ERR_5 "Upload Buffer Vergleich weicht ab"
#define D_UPLOAD_ERR_6 "Upload fehlgeschlagen. Aktiviere logging 3"
#define D_UPLOAD_ERR_7 "Upload abgebrochen"
#define D_UPLOAD_ERR_8 "Datei ungültig"
#define D_UPLOAD_ERR_9 "Datei zu groß"
#define D_UPLOAD_ERR_10 "RF Chip init fehlgeschlagen"
#define D_UPLOAD_ERR_11 "RF Chip löschen fehlgeschlagen"
#define D_UPLOAD_ERR_12 "RF Chip beschreiben fehlgeschlagen"
#define D_UPLOAD_ERR_13 "RF Firmware ungültig"
#define D_UPLOAD_ERR_14 "Nicht kompatibel"
#define D_UPLOAD_ERROR_CODE "Upload Fehler Nummer"

#define D_ENTER_COMMAND "Befehl eingeben"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Aktivere Web Log Level 2 falls Reaktion erwartet"
#define D_NEED_USER_AND_PASSWORD "Benötige user=<Benutzername>&password=<Passwort>"

// xdrv_01_mqtt.ino
#define D_FINGERPRINT "TLS-Fingerabdruck wird verifiziert..."
#define D_TLS_CONNECT_FAILED_TO "TLS-Verbindung fehlgeschlagen an"
#define D_RETRY_IN "Wiederversuch in"
#define D_VERIFIED "verifiziert mit Fingerabdruck"
#define D_INSECURE "unsichere Verbindung aufgrund ungültigen Fingerabdrucks"
#define D_CONNECT_FAILED_TO "Verbindung fehlgeschlagen aufgrund von"

// xplg_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast deaktiviert"
#define D_MULTICAST_REJOINED "Multicast (wieder-)verbunden"
#define D_MULTICAST_JOIN_FAILED "Multicast Verbindung fehlgeschlagen"
#define D_FAILED_TO_SEND_RESPONSE "Antwort senden fehlgeschlagen"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo basic event"
#define D_WEMO_EVENT_SERVICE "WeMo event service"
#define D_WEMO_META_SERVICE "WeMo meta service"
#define D_WEMO_SETUP "WeMo-Setup"
#define D_RESPONSE_SENT "Antwort gesendet"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Hue-Setup"
#define D_HUE_API_NOT_IMPLEMENTED "Hue-API nicht implementiert"
#define D_HUE_API "Hue-API"
#define D_HUE_POST_ARGS "Hue POST-Argumente"
#define D_3_RESPONSE_PACKETS_SENT "3 Antwortpakete gesendet"

// xdrv_07_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Domoticz-Parameter"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Key idx"
#define D_DOMOTICZ_SWITCH_IDX "Switch idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Hum"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Hum,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Power,Energy"
  #define D_DOMOTICZ_ILLUMINANCE "Illuminance"
  #define D_DOMOTICZ_COUNT "Count/PM1"
  #define D_DOMOTICZ_VOLTAGE "Voltage/PM2.5"
  #define D_DOMOTICZ_CURRENT "Current/PM10"
  #define D_DOMOTICZ_AIRQUALITY "AirQuality"
  #define D_DOMOTICZ_P1_SMART_METER "P1SmartMeter"
#define D_DOMOTICZ_UPDATE_TIMER "Update Zeitplan"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Zeitplan konfigurieren"
#define D_TIMER_PARAMETERS "Zeitplan-Einstellungen"
#define D_TIMER_ENABLE "Zeitpläne aktivieren"
#define D_TIMER_ARM "Aktiv"
#define D_TIMER_TIME "Uhrzeit"
#define D_TIMER_DAYS "Wochentage"
#define D_TIMER_REPEAT "Wiederholen"
#define D_TIMER_OUTPUT "Ausgang"
#define D_TIMER_ACTION "Aktion"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "KNX konfigurieren"
#define D_KNX_PARAMETERS "KNX-Parameter"
#define D_KNX_GENERAL_CONFIG "Allgemein"
#define D_KNX_PHYSICAL_ADDRESS "Physikalische Adresse"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "( Muss einmalig im KNX-Netzwerk sein )"
#define D_KNX_ENABLE "KNX aktivieren"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Daten zum Senden an Gruppenadresse"
#define D_ADD "Hinzufügen"
#define D_DELETE "Löschen"
#define D_REPLY "Antworten"
#define D_KNX_GROUP_ADDRESS_TO_READ "Gruppenadresse zum Emfang von Daten"
#define D_RECEIVED_FROM "Empfangen von"
#define D_KNX_COMMAND_WRITE "Schreiben"
#define D_KNX_COMMAND_READ "Lesen"
#define D_KNX_COMMAND_OTHER "Andere"
#define D_SENT_TO "gesendet an"
#define D_KNX_WARNING "Die Gruppenadresse (0/0/0) ist reserviert und kann nicht verwendet werden."
#define D_KNX_ENHANCEMENT "Erweiterte Kommunikation"
#define D_KNX_TX_SLOT "KNX TX"
#define D_KNX_RX_SLOT "KNX RX"
#define D_KNX_TX_SCENE "KNX SCENE TX"
#define D_KNX_RX_SCENE "KNX SCENE RX"

// xdrv_23_zigbee
#define D_ZIGBEE_PERMITJOIN_ACTIVE "Gerätekopplung erlaubt"
#define D_ZIGBEE_MAPPING_TITLE "Tasmota Zigbee Karte"
#define D_ZIGBEE_NOT_STARTED "Zigbee nicht gestartet"
#define D_ZIGBEE_MAPPING_IN_PROGRESS_SEC "Karte in Erstellung (%d s. verbleibend)"
#define D_ZIGBEE_MAPPING_NOT_PRESENT "Keine Karte"
#define D_ZIGBEE_MAP_REFRESH "Zigbee Karte erneuern"
#define D_ZIGBEE_MAP   "Zigbee Karte"
#define D_ZIGBEE_PERMITJOIN "Zigbee Kopplung ein"
#define D_ZIGBEE_GENERATE_KEY "Erzeuge zufälligen Zigbee Netzwerkschlüssel"
#define D_ZIGBEE_UNKNOWN_DEVICE "Unbekanntes Gerät"
#define D_ZIGBEE_UNKNOWN_ATTRIBUTE "Unbekanntes Attribut"
#define D_ZIGBEE_INVALID_PARAM "Ungültiger Parameter"
#define D_ZIGBEE_MISSING_PARAM "Fehlende Parameter"
#define D_ZIGBEE_UNKNWON_ATTRIBUTE "Unbekannter Attribut Name (ignoriert): %s"
#define D_ZIGBEE_TOO_MANY_CLUSTERS "Nur eine Cluster id pro Kommando"
#define D_ZIGBEE_WRONG_DELIMITER "Falscher Delimeter für Payload"
#define D_ZIGBEE_UNRECOGNIZED_COMMAND "Unerkanntes zigbee Kommando: %s"
#define D_ZIGBEE_TOO_MANY_COMMANDS "Nur 1 Kommando zulässig (%d)"
#define D_ZIGBEE_NO_ATTRIBUTE "Kein Attribut in der Liste"
#define D_ZIGBEE_UNSUPPORTED_ATTRIBUTE_TYPE "Nicht unterstützter Attribut Typ"
#define D_ZIGBEE_JSON_REQUIRED "Konfiguration muss JSON basiert sein"
#define D_ZIGBEE_RESET_1_OR_2 "1 oder 2 für Reset"
#define D_ZIGBEE_EEPROM_FOUND_AT_ADDRESS "ZBBridge EEPROM gefunden auf Addresse"
#define D_ZIGBEE_RANDOMIZING_ZBCONFIG "Zufällige Zigbee Parameter erstellt, Überprüfung mit 'ZbConfig'"

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Energie heute"
#define D_ENERGY_YESTERDAY "Energie gestern"
#define D_ENERGY_TOTAL "Energie insgesamt"

// xdrv_27_shutter.ino
#define D_OPEN "Öffnen"
#define D_CLOSE "Schliessen"
#define D_DOMOTICZ_SHUTTER "Rollo"

// xdrv_28_pcf8574.ino
#define D_CONFIGURE_PCF8574 "Konfiguriere PCF8574"
#define D_PCF8574_PARAMETERS "PCF8574 Parameter"
#define D_INVERT_PORTS "Invertiere Ports"
#define D_DEVICE "Gerät"
#define D_DEVICE_INPUT "Eingang"
#define D_DEVICE_OUTPUT "Ausgang"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Sensor beschäftigt"
#define D_SENSOR_CRC_ERROR "Sensor CRC-Fehler"
#define D_SENSORS_FOUND "Sensor gefunden"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Timeout während Warten auf"
#define D_START_SIGNAL_LOW "Startausschlag niedrig"
#define D_START_SIGNAL_HIGH "Startausschlag hoch"
#define D_PULSE "Puls"
#define D_CHECKSUM_FAILURE "Prüfsummen-Fehler"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Sensor hat ACK-Befehl nicht ausgeführt"
#define D_SHT1X_FOUND "SHT1X gefunden"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Partikel"

// xsns_27_apds9960.ino
#define D_GESTURE "Geste"
#define D_COLOR_RED "Rot"
#define D_COLOR_GREEN "Grün"
#define D_COLOR_BLUE "Blau"
#define D_CCT "CCT"
#define D_PROXIMITY "Nähe"

// xsns_32_mpu6050.ino
#define D_AX_AXIS "Beschl. X-Achse"
#define D_AY_AXIS "Beschl. Y-Achse"
#define D_AZ_AXIS "Beschl. Z-Achse"
#define D_GX_AXIS "Gyroskop X-Achse"
#define D_GY_AXIS "Gyroskop Y-Achse"
#define D_GZ_AXIS "Gyroskop Z-Achse"

// xsns_34_hx711.ino
#define D_HX_CAL_REMOVE "Wägegut entfernen"
#define D_HX_CAL_REFERENCE "Referenzgewicht auflegen"
#define D_HX_CAL_DONE "kalibriert"
#define D_HX_CAL_FAIL "Kalibrierung fehlgeschlagen"
#define D_RESET_HX711 "Tara"
#define D_CONFIGURE_HX711 "Tara Wert?"
#define D_HX711_PARAMETERS "Skala Parameter"
#define D_ITEM_WEIGHT "Wägegut Gewicht"
#define D_REFERENCE_WEIGHT "Referenz Gewicht"
#define D_CALIBRATE "kalibriert"
#define D_CALIBRATION "Kalibrierung"

//xsns_35_tx20.ino
#define D_TX20_WIND_DIRECTION "Windrichtung"
#define D_TX20_WIND_SPEED "Windgeschwindigkeit"
#define D_TX20_WIND_SPEED_MIN "Windgeschwindigkeit Min"
#define D_TX20_WIND_SPEED_MAX "Windgeschwindigkeit Max"
#define D_TX20_NORTH "N"
#define D_TX20_EAST "O"
#define D_TX20_SOUTH "S"
#define D_TX20_WEST "W"

// xsns_53_sml.ino
#define D_TPWRIN "Verbrauch"
#define D_TPWROUT "Einspeisung"
#define D_TPWRCURR "Aktueller Verbrauch"
#define D_TPWRCURR1 "Verbrauch P1"
#define D_TPWRCURR2 "Verbrauch P2"
#define D_TPWRCURR3 "Verbrauch P3"
#define D_Strom_L1 "Strom L1"
#define D_Strom_L2 "Strom L2"
#define D_Strom_L3 "Strom L3"
#define D_Spannung_L1 "Spannung L1"
#define D_Spannung_L2 "Spannung L2"
#define D_Spannung_L3 "Spannung L3"
#define D_METERNR "Zähler Nr"
#define D_METERSID "Service ID"
#define D_GasIN "Zählerstand"                // Gas-Verbrauch
#define D_H2oIN "Zählerstand"                // H2o-Verbrauch
#define D_StL1L2L3 "Ströme L1+L2+L3"
#define D_SpL1L2L3 "Spannung L1+L2+L3/3"

// tasmota_template.h - keep them as short as possible to be able to fit them in GUI drop down box
#define D_SENSOR_NONE          "None"
#define D_SENSOR_USER          "User"
#define D_SENSOR_OPTION        "Option"
#define D_SENSOR_DHT11         "DHT11"
#define D_SENSOR_AM2301        "AM2301"
#define D_SENSOR_SI7021        "SI7021"
#define D_SENSOR_DS18X20       "DS18x20"
#define D_SENSOR_I2C_SCL       "I2C SCL"
#define D_SENSOR_I2C_SDA       "I2C SDA"
#define D_SENSOR_WS2812        "WS2812"
#define D_SENSOR_DFR562        "MP3 Player"
#define D_SENSOR_IRSEND        "IRsend"
#define D_SENSOR_SWITCH        "Switch"     // Suffix "1"
#define D_SENSOR_BUTTON        "Button"     // Suffix "1"
#define D_SENSOR_RELAY         "Relay"      // Suffix "1i"
#define D_SENSOR_LED           "Led"        // Suffix "1i"
#define D_SENSOR_LED_LINK      "LedLink"    // Suffix "i"
#define D_SENSOR_PWM           "PWM"        // Suffix "1"
#define D_SENSOR_COUNTER       "Counter"    // Suffix "1"
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
#define D_SENSOR_PMS5003_TX    "PMS5003 Tx"
#define D_SENSOR_PMS5003_RX    "PMS5003 Rx"
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
#define D_SENSOR_WE517_TX      "WE517 Tx"
#define D_SENSOR_WE517_RX      "WE517 Rx"
#define D_SENSOR_TM1638_CLK    "TM16 CLK"
#define D_SENSOR_TM1638_DIO    "TM16 DIO"
#define D_SENSOR_TM1638_STB    "TM16 STB"
#define D_SENSOR_HX711_SCK     "HX711 SCK"
#define D_SENSOR_HX711_DAT     "HX711 DAT"
#define D_SENSOR_FTC532        "FTC532"
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
#define D_SENSOR_MAX31865_CS   "MX31865 CS"
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
#define D_SENSOR_P9813_CLK     "P9813 Clk"
#define D_SENSOR_P9813_DAT     "P9813 Dat"
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
#define D_SENSOR_ZIGBEE_RST    "Zigbee Rst"
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
#define D_SENSOR_OUTPUT_HI     "Output Hi"
#define D_SENSOR_OUTPUT_LO     "Output Lo"
#define D_SENSOR_AS608_TX      "AS608 Tx"
#define D_SENSOR_AS608_RX      "AS608 Rx"
#define D_SENSOR_DDS2382_TX    "DDS238-2 Tx"
#define D_SENSOR_DDS2382_RX    "DDS238-2 Rx"
#define D_SENSOR_DDSU666_TX    "DDSU666 Tx"
#define D_SENSOR_DDSU666_RX    "DDSU666 Rx"
#define D_SENSOR_SM2135_CLK    "SM2135 Clk"
#define D_SENSOR_SM2135_DAT    "SM2135 Dat"
#define D_SENSOR_DEEPSLEEP     "DeepSleep"
#define D_SENSOR_EXS_ENABLE    "EXS Enable"
#define D_SENSOR_CLIENT_TX    "Client TX"
#define D_SENSOR_CLIENT_RX    "Client RX"
#define D_SENSOR_CLIENT_RESET "Client RST"
#define D_SENSOR_GPS_RX        "GPS RX"
#define D_SENSOR_GPS_TX        "GPS TX"
#define D_SENSOR_HM10_RX       "HM10 RX"
#define D_SENSOR_HM10_TX       "HM10 TX"
#define D_SENSOR_LE01MR_RX     "LE-01MR Rx"
#define D_SENSOR_LE01MR_TX     "LE-01MR Tx"
#define D_SENSOR_BL0940_RX     "BL0940 Rx"
#define D_SENSOR_CC1101_GDO0   "CC1101 GDO0"
#define D_SENSOR_CC1101_GDO2   "CC1101 GDO2"
#define D_SENSOR_HRXL_RX       "HRXL Rx"
#define D_SENSOR_DYP_RX        "DYP Rx"
#define D_SENSOR_ELECTRIQ_MOODL "MOODL Tx"
#define D_SENSOR_AS3935        "AS3935"
#define D_SENSOR_WINDMETER_SPEED "WindMeter Spd"
#define D_SENSOR_TELEINFO_RX   "TInfo Rx"
#define D_SENSOR_TELEINFO_ENABLE "TInfo EN"
#define D_SENSOR_LMT01_PULSE   "LMT01 Pulse"
#define D_SENSOR_ADC_INPUT     "ADC Input"
#define D_SENSOR_ADC_TEMP      "ADC Temp"
#define D_SENSOR_ADC_LIGHT     "ADC Light"
#define D_SENSOR_ADC_BUTTON    "ADC Button"
#define D_SENSOR_ADC_RANGE     "ADC Range"
#define D_SENSOR_ADC_CT_POWER  "ADC CT Power"
#define D_SENSOR_ADC_JOYSTICK  "ADC Joystick"
#define D_GPIO_WEBCAM_PWDN     "CAM_PWDN"
#define D_GPIO_WEBCAM_RESET    "CAM_RESET"
#define D_GPIO_WEBCAM_XCLK     "CAM_XCLK"
#define D_GPIO_WEBCAM_SIOD     "CAM_SIOD"
#define D_GPIO_WEBCAM_SIOC     "CAM_SIOC"
#define D_GPIO_WEBCAM_DATA     "CAM_DATA"
#define D_GPIO_WEBCAM_VSYNC    "CAM_VSYNC"
#define D_GPIO_WEBCAM_HREF     "CAM_HREF"
#define D_GPIO_WEBCAM_PCLK     "CAM_PCLK"
#define D_GPIO_WEBCAM_PSCLK    "CAM_PSCLK"
#define D_GPIO_WEBCAM_HSD      "CAM_HSD"
#define D_GPIO_WEBCAM_PSRCS    "CAM_PSRCS"
#define D_SENSOR_ETH_PHY_POWER "ETH POWER"
#define D_SENSOR_ETH_PHY_MDC   "ETH MDC"
#define D_SENSOR_ETH_PHY_MDIO  "ETH MDIO"
#define D_SENSOR_TCP_TXD       "TCP Tx"
#define D_SENSOR_TCP_RXD       "TCP Rx"
#define D_SENSOR_IEM3000_TX    "iEM3000 TX"
#define D_SENSOR_IEM3000_RX    "iEM3000 RX"
#define D_SENSOR_MIEL_HVAC_TX  "MiEl HVAC Tx"
#define D_SENSOR_MIEL_HVAC_RX  "MiEl HVAC Rx"
#define D_SENSOR_SHELLY_DIMMER_BOOT0 "SHD Boot 0"
#define D_SENSOR_SHELLY_DIMMER_RST_INV "SHD Reset"
#define D_SENSOR_RC522_RST     "RC522 Rst"
#define D_SENSOR_RC522_CS      "RC522 CS"
#define D_SENSOR_NRF24_CS      "NRF24 CS"
#define D_SENSOR_NRF24_DC      "NRF24 DC"
#define D_SENSOR_ILI9341_CS    "ILI9341 CS"
#define D_SENSOR_ILI9341_DC    "ILI9341 DC"
#define D_SENSOR_ILI9488_CS    "ILI9488 CS"
#define D_SENSOR_EPAPER29_CS   "EPaper29 CS"
#define D_SENSOR_EPAPER42_CS   "EPaper42 CS"
#define D_SENSOR_SSD1351_CS    "SSD1351 CS"
#define D_SENSOR_RA8876_CS     "RA8876 CS"
#define D_SENSOR_ST7789_CS     "ST7789 CS"
#define D_SENSOR_ST7789_DC     "ST7789 DC"
#define D_SENSOR_SSD1331_CS    "SSD1331 CS"
#define D_SENSOR_SSD1331_DC    "SSD1331 DC"

// Units
#define D_UNIT_AMPERE "A"
#define D_UNIT_CELSIUS "C"
#define D_UNIT_CENTIMETER "cm"
#define D_UNIT_DEGREE "°"
#define D_UNIT_FAHRENHEIT "F"
#define D_UNIT_HERTZ "Hz"
#define D_UNIT_HOUR "h"
#define D_UNIT_GALLONS "gal"
#define D_UNIT_GALLONS_PER_MIN "g/m"
#define D_UNIT_INCREMENTS "inc"
#define D_UNIT_KELVIN "K"
#define D_UNIT_KILOMETER "km"
#define D_UNIT_KILOGRAM "kg"
#define D_UNIT_KILOMETER_PER_HOUR "km/h"
#define D_UNIT_KILOOHM "kΩ"
#define D_UNIT_KILOWATTHOUR "kWh"
#define D_UNIT_LITERS "L"
#define D_UNIT_LITERS_PER_MIN "L/m"
#define D_UNIT_LUX "lx"
#define D_UNIT_MICROGRAM_PER_CUBIC_METER "µg/m³"
#define D_UNIT_MICROMETER "µm"
#define D_UNIT_MICROSECOND "µs"
#define D_UNIT_MICROSIEMENS_PER_CM "µS/cm"
#define D_UNIT_MILLIAMPERE "mA"
#define D_UNIT_MILLILITERS "ml"
#define D_UNIT_MILLIMETER "mm"
#define D_UNIT_MILLIMETER_MERCURY "mmHg"
#define D_UNIT_MILLISECOND "ms"
#define D_UNIT_MILLIVOLT "mV"
#define D_UNIT_MINUTE "min"
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PERCENT "%%"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "s"
#define D_UNIT_SECTORS "Sektoren"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "Wh"
#define D_UNIT_WATT_METER_QUADRAT "W/m²"

//SDM220, SDM120, LE01MR
#define D_PHASE_ANGLE     "Phasenwinkel"
#define D_IMPORT_ACTIVE   "Importiere Wirk"
#define D_EXPORT_ACTIVE   "Exportiere Wirk"
#define D_IMPORT_REACTIVE "Importiere Blind"
#define D_EXPORT_REACTIVE "Exportiere Blind"
#define D_TOTAL_REACTIVE  "Total Blind"
#define D_UNIT_KWARH      "kVArh"
#define D_UNIT_ANGLE      "Grad"
#define D_TOTAL_ACTIVE    "Total Wirk"

//SOLAXX1
#define D_PV1_VOLTAGE     "PV1 Spannung"
#define D_PV1_CURRENT     "PV1 Strom"
#define D_PV1_POWER       "PV1 Leistung"
#define D_PV2_VOLTAGE     "PV2 Spannung"
#define D_PV2_CURRENT     "PV2 Strom"
#define D_PV2_POWER       "PV2 Leistung"
#define D_SOLAR_POWER     "solare Leistung"
#define D_INVERTER_POWER  "Inverter Leistung"
#define D_STATUS          "Status"
#define D_WAITING         "warten"
#define D_CHECKING        "prüfen"
#define D_WORKING         "arbeitet"
#define D_FAILURE         "Fehler"
#define D_SOLAX_ERROR_0   "Kein Fehler Code"
#define D_SOLAX_ERROR_1   "Fehler im Solarstromnetz"
#define D_SOLAX_ERROR_2   "Spannungsfehler im Solarstromnetz"
#define D_SOLAX_ERROR_3   "Frequenzfehler im Solarstromnetz"
#define D_SOLAX_ERROR_4   "Pv Spannungsfehler"
#define D_SOLAX_ERROR_5   "Isolationsfehler"
#define D_SOLAX_ERROR_6   "Übertemperatur"
#define D_SOLAX_ERROR_7   "Lüfterfehler"
#define D_SOLAX_ERROR_8   "sonstiger Fehler"

//xdrv_10_scripter.ino
#define D_CONFIGURE_SCRIPT     "Skript konfigurieren"
#define D_SCRIPT               "Skript bearbeiten"
#define D_SDCARD_UPLOAD        "Datei speichern"
#define D_SDCARD_DIR           "SD Card Verzeichnis"
#define D_UPL_DONE             "Fertig"
#define D_SCRIPT_CHARS_LEFT    "Zeichen übrig"
#define D_SCRIPT_CHARS_NO_MORE "kein Speicher mehr"
#define D_SCRIPT_DOWNLOAD      "Download"
#define D_SCRIPT_ENABLE        "Skript aktivieren"
#define D_SCRIPT_UPLOAD        "Upload"
#define D_SCRIPT_UPLOAD_FILES  "Upload Dateien"

//xsns_67_as3935.ino
#define D_AS3935_GAIN "Umgebung:"
#define D_AS3935_ENERGY "Energie:"
#define D_AS3935_DISTANCE "Entfernung:"
#define D_AS3935_DISTURBER "Entstörer:"
#define D_AS3935_VRMS "µVrms:"
#define D_AS3935_APRX "ca.:"
#define D_AS3935_AWAY "entfernt"
#define D_AS3935_LIGHT "Blitz"
#define D_AS3935_OUT "ausserhalb der Reichweite"
#define D_AS3935_NOT "Entfernung nicht ermittelbar"
#define D_AS3935_ABOVE "Blitz überhalb"
#define D_AS3935_NOISE "Rauschen entdeckt"
#define D_AS3935_DISTDET "Störer entdeckt"
#define D_AS3935_INTNOEV "Interrupt ohne Grund!"
#define D_AS3935_FLICKER "IRQ Pin flackert!"
#define D_AS3935_POWEROFF "Ausgeschaltet"
#define D_AS3935_NOMESS "lausche..."
#define D_AS3935_ON "On"
#define D_AS3935_OFF "Off"
#define D_AS3935_INDOORS "Indoors"
#define D_AS3935_OUTDOORS "Outdoors"
#define D_AS3935_CAL_FAIL "Kalibrierung fehlerhaft"
#define D_AS3935_CAL_OK "Cap gesetzt auf:"

//xsns_68_opentherm.ino
#define D_SENSOR_BOILER_OT_RX   "OpenTherm RX"
#define D_SENSOR_BOILER_OT_TX   "OpenTherm TX"

// xnrg_15_teleinfo Denky (Teleinfo)
#define D_CONTRACT        "Vertrag"
#define D_POWER_LOAD      "Leistung"
#define D_CURRENT_TARIFF  "Aktueller Tarif"
#define D_TARIFF          "Tarif"
#define D_OVERLOAD        "ADPS"
#define D_MAX_POWER       "max. Leistung"
#define D_MAX_CURRENT     "max. Stromstärke"

// xsns_79_as608.ino
#define D_FP_ENROLL_PLACEFINGER "Finger auflegen"
#define D_FP_ENROLL_REMOVEFINGER "Finger entfernen"
#define D_FP_ENROLL_PLACESAMEFINGER "gleichen Finger auflegen"
#define D_FP_ENROLL_RETRY "Fehler - wiederholen"
#define D_FP_ENROLL_RESTART "Neustart"
#define D_FP_ENROLL_ERROR "Fehler"
#define D_FP_ENROLL_RESET "Zurücksetzen"
#define D_FP_ENROLL_ACTIVE "Aktiv"
#define D_FP_ENROLL_INACTIVE "Inaktiv"
// Indexed by Adafruit_Fingerprint.h defines
#define D_FP_PACKETRECIEVEERR "Kommunikationsfehler"    // 0x01 Error when receiving data package
#define D_FP_NOFINGER ""                                // 0x02 No finger on the sensor
#define D_FP_IMAGEFAIL "Abbildungsfehler"               // 0x03 Failed to enroll the finger
#define D_FP_IMAGEMESS "schlechtes Abbild"              // 0x06 Failed to generate character file due to overly disorderly fingerprint image
#define D_FP_FEATUREFAIL "Fingerabdruck zu klein"       // 0x07 Failed to generate character file due to the lack of character point or small fingerprint image
#define D_FP_NOMATCH "keine Übereinstimmung"           // 0x08 Finger doesn't match
#define D_FP_NOTFOUND "keinen Eintrag gefunden"         // 0x09 Failed to find matching finger
#define D_FP_ENROLLMISMATCH "Fingerabdruck fehlerhaft"  // 0x0A Failed to combine the character files
#define D_FP_BADLOCATION "Eintrag Fehler"               // 0x0B Addressed PageID is beyond the finger library
#define D_FP_DBRANGEFAIL "Datenbankfehler"              // 0x0C Error when reading template from library or invalid template
#define D_FP_UPLOADFEATUREFAIL "Speicherfehler"         // 0x0D Error when uploading template
#define D_FP_PACKETRESPONSEFAIL "Auslesefehler"         // 0x0E Module failed to receive the following data packages
#define D_FP_UPLOADFAIL "Bildspeicherfehler"            // 0x0F Error when uploading image
#define D_FP_DELETEFAIL "Löschfehler"                   // 0x10 Failed to delete the template
#define D_FP_DBCLEARFAIL "Datenbanklöschfehler"         // 0x11 Failed to clear finger library
#define D_FP_PASSFAIL "keine Übereinstimmung"           // 0x13 Find whether the fingerprint passed or failed
#define D_FP_INVALIDIMAGE "Abbild ungültig"             // 0x15 Failed to generate image because of lac of valid primary image
#define D_FP_FLASHERR "Flash Schreibfehler"             // 0x18 Error when writing flash
#define D_FP_INVALIDREG "Ungültige ID-Nummer"           // 0x1A Invalid register number
#define D_FP_ADDRCODE "Addresse"                        // 0x20 Address code
#define D_FP_PASSVERIFY "Übereinstimmung"               // 0x21 Verify the fingerprint passed
#define D_FP_UNKNOWNERROR "Fehler"                      // Any other error

#endif  // _LANGUAGE_DE_DE_H_
