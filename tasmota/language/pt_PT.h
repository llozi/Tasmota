/*
  pt-PT.h - localization for Portuguese - Portugal for Tasmota

  Copyright (C) 2021  Paulo Paiva

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

#ifndef _LANGUAGE_PT_PT_H_
#define _LANGUAGE_PT_PT_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v7.0.0.1
\*********************************************************************/

#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)

#define LANGUAGE_LCID 2070
// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "pt"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "-"
#define D_MONTH_DAY_SEPARATOR "-"
#define D_DATE_TIME_SEPARATOR "T"
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "DomSegTerQuaQuiSexSab"
#define D_MONTH3LIST "JanFevMarAbrMaiJunJulAgoSepOutNovDez"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR "."

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Qualidade do Ar"
#define D_AP "AP"                    // Ponto de Acesso
#define D_AS "como"
#define D_AUTO "AUTO"
#define D_BATT "Batt"                // Short for Battery
#define D_BLINK "Piscar"
#define D_BLINKOFF "Piscar Desligado"
#define D_BOOT_COUNT "Contagem de Inicialização"
#define D_BRIGHTLIGHT "Brilho"
#define D_BSSID "BSSId"
#define D_BUTTON "Botão"
#define D_BY "por"                    // Write by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CHANNEL "Canal"
#define D_CO2 "Dioxido de Carbono"
#define D_CODE "Código"                // Button code
#define D_COLDLIGHT "Luz Fria"
#define D_COMMAND "Comando"
#define D_CONNECTED "Ligado"
#define D_CORS_DOMAIN "CORS Domain"
#define D_COUNT "Contagem"
#define D_COUNTER "Contador"
#define D_CT_POWER "CT Power"
#define D_CURRENT "Corrente"          // As in Voltage and Current
#define D_DATA "Dados"
#define D_DARKLIGHT "Luz Escura"
#define D_DEBUG "Depurar"
#define D_DEWPOINT "Dew point"
#define D_DISABLED "Disabilitado"
#define D_DISTANCE "Distância"
#define D_DNS_SERVER "Servidor DNS"
#define D_DO "Disolved Oxygen"
#define D_DONE "Concluído"
#define D_DST_TIME "DST"
#define D_EC "EC"
#define D_ECO2 "eCO₂"
#define D_EMULATION "Emulação"
#define D_ENABLED "Habilitado"
#define D_ERASE "Apagar"
#define D_ERROR "Erro"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "Falha"
#define D_FALLBACK "Retornar"
#define D_FALLBACK_TOPIC "Tópico para retornar"
#define D_FALSE "Falso"
#define D_FILE "Ficheiro"
#define D_FLOW_RATE "Taxa de Fluxo"
#define D_FREE_MEMORY "Memoria Livre"
#define D_PSR_MAX_MEMORY "PS-RAM Memory"
#define D_PSR_FREE_MEMORY "PS-RAM free Memory"
#define D_FREQUENCY "Frequência"
#define D_GAS "Gás"
#define D_GATEWAY "Gateway"
#define D_GROUP "Grupo"
#define D_HOST "Anfitrião"
#define D_HOSTNAME "Nome Anfitrião"
#define D_HUMIDITY "Humidade"
#define D_ILLUMINANCE "Luminâcia"
#define D_IMMEDIATE "Immediato"      // Button immediate
#define D_INDEX "Indíce"
#define D_INFO "Info"
#define D_INFRARED "Infravermelho"
#define D_INITIALIZED "Inicializado"
#define D_IP_ADDRESS "Endereço IP"
#define D_LIGHT "Luz"
#define D_LWT "LWT"
#define D_LQI "LQI"                  // Zigbee Link Quality Index
#define D_MODULE "Módulo"
#define D_MOISTURE "Moisture"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "multi-pressão"
#define D_NOISE "Ruído"
#define D_NONE "Nenhum"
#define D_O2 "Oxygen"
#define D_OFF "Off"
#define D_OFFLINE "Desconetado"
#define D_OK "Ok"
#define D_ON "On"
#define D_ONLINE "Conetado"
#define D_ORP "ORP"
#define D_PASSWORD "Palavra Chave"
#define D_PH "pH"
#define D_PORT "Porta"
#define D_POWER_FACTOR "Factor de Potência"
#define D_POWERUSAGE "Potência"
#define D_POWERUSAGE_ACTIVE "Potência Ativa"
#define D_POWERUSAGE_APPARENT "Potência Aparente"
#define D_POWERUSAGE_REACTIVE "Potência Reativa"
#define D_PRESSURE "Pressão"
#define D_PRESSUREATSEALEVEL "Pressão ao nível do Mar"
#define D_PROGRAM_FLASH_SIZE "Tamanho do Programa na Flash"
#define D_PROGRAM_SIZE "Tamanho do Programa"
#define D_PROJECT "Projeto"
#define D_RAIN "Chuva"
#define D_RANGE "Range"
#define D_RECEIVED "Recebido"
#define D_RESTART "Reiniciar"
#define D_RESTARTING "A reiniciar"
#define D_RESTART_REASON "Razão do reinicio"
#define D_RESTORE "Restauro"
#define D_RETAINED "Manter"
#define D_RULE "Regra"
#define D_SAVE "Guardar"
#define D_SENSOR "Sensor"
#define D_SSID "SSId"
#define D_START "Início"
#define D_STD_TIME "STD"
#define D_STOP "Parar"
#define D_SUBNET_MASK "Mascara sub rede"
#define D_SUBSCRIBE_TO "Subscrever"
#define D_UNSUBSCRIBE_FROM "Cancelar subscrição de"
#define D_SUCCESSFUL "Successo"
#define D_SUNRISE "Nascer do Sol"
#define D_SUNSET "Pôr do Sol"
#define D_TEMPERATURE "Temperatura"
#define D_TO "para"
#define D_TOGGLE "Pressionar"
#define D_TOPIC "Tópico"
#define D_TOTAL_USAGE "Uso total"
#define D_TRANSMIT "Transmitir"
#define D_TRUE "Verdadeiro"
#define D_TVOC "TVOC"
#define D_UPGRADE "Atualizar"
#define D_UPLOAD "Enviar"
#define D_UPTIME "Tempo de Atividade"
#define D_USER "Utilizador"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "Indíce UV"
#define D_UV_INDEX_1 "Baixo"
#define D_UV_INDEX_2 "Médio"
#define D_UV_INDEX_3 "Elevado"
#define D_UV_INDEX_4 "Perigoso"
#define D_UV_INDEX_5 "QueimaduraL1/2"
#define D_UV_INDEX_6 "QueimaduraL3"
#define D_UV_INDEX_7 "OoR"
#define D_UV_LEVEL "Nível UV"
#define D_UV_POWER "Poder UV"
#define D_VERSION "Versão"
#define D_VOLTAGE "Voltagem"
#define D_VOLUME "Volume"
#define D_WEIGHT "Peso"
#define D_WARMLIGHT "Luz Quente"
#define D_WEB_SERVER "Servidor WEB"

// tasmota.ino
#define D_WARNING_MINIMAL_VERSION "AVISO esta versão não supporta configurações persistentes"
#define D_LEVEL_10 "nível 1-0"
#define D_LEVEL_01 "nível 0-1"
#define D_SERIAL_LOGGING_DISABLED "Registro de porta série desabilitado"
#define D_SYSLOG_LOGGING_REENABLED "Registro do Syslog reativado"

#define D_SET_BAUDRATE_TO "Ajuste da velocidade para"
#define D_RECEIVED_TOPIC "Topico Recebido"
#define D_DATA_SIZE "Tamanho de Dados"
#define D_ANALOG_INPUT "Entrada Analógica"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Loop Bloqueado"
#define D_WPS_FAILED_WITH_STATUS "WPSconfig FALHOU com estado"
#define D_ACTIVE_FOR_3_MINUTES "ativo por 3 minutos"
#define D_FAILED_TO_START "Falha ao iníciar"
#define D_PATCH_ISSUE_2186 "Questão 2186"
#define D_CONNECTING_TO_AP "Ligando ao AP"
#define D_IN_MODE "em modo"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "A ligação falhou porque nenhum endereço IP foi recebido"
#define D_CONNECT_FAILED_AP_NOT_REACHED "A ligação falhou porque o AP não pode ser alcançado"
#define D_CONNECT_FAILED_WRONG_PASSWORD "A ligação falhou"
#define D_CONNECT_FAILED_AP_TIMEOUT "A ligação falhou porque o tempo excedeu"
#define D_ATTEMPTING_CONNECTION "A ligar..."
#define D_CHECKING_CONNECTION "A verificar ligação..."
#define D_QUERY_DONE "Consulta finalizada. Serviço MQTT não encontrado"
#define D_MQTT_SERVICE_FOUND "Serviço MQTT encontrado em"
#define D_FOUND_AT "encontrado em"
#define D_SYSLOG_HOST_NOT_FOUND "Anfitrião Syslog não encontrado"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Guardado na flash em"
#define D_LOADED_FROM_FLASH_AT "Lido da flash em"
#define D_USE_DEFAULTS "Usar predefinições"
#define D_ERASED_SECTOR "Apagado setor"

// xdrv_02_webserver.ino
#define D_NOSCRIPT "Para utilizar o Tasmota, por favor ative o JavaScript"
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "Firmware MÍNIMO<br>Por favor atualize"
#define D_WEBSERVER_ACTIVE_ON "Servidor WEB ativo em"
#define D_WITH_IP_ADDRESS "com o endereço IP"
#define D_WEBSERVER_STOPPED "Servitor WEB parou"
#define D_FILE_NOT_FOUND "Ficheiro não encontrado"
#define D_REDIRECTED "Redirecionado para o portal ativo"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifimanager configura o Ponto de Acesso e mantem a Estação"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifimanager configura o Ponto de Acesso"
#define D_TRYING_TO_CONNECT "A tentar ligar o dispositivo à rede"

#define D_RESTART_IN "Reinicia em"
#define D_SECONDS "segundos"
#define D_DEVICE_WILL_RESTART "O dispositivo irá reiniciar dentro de alguns segundos"
#define D_BUTTON_TOGGLE "Alternar"
#define D_CONFIGURATION "Configuração"
#define D_INFORMATION "Informação"
#define D_FIRMWARE_UPGRADE "Atualização de Firmware"
#define D_CONSOLE "Consola"
#define D_CONFIRM_RESTART "Confirmar o reinício"

#define D_CONFIGURE_MODULE "Configurar Módulo"
#define D_CONFIGURE_WIFI "Configurar WiFi"
#define D_CONFIGURE_MQTT "Configurar MQTT"
#define D_CONFIGURE_DOMOTICZ "Configurar Domoticz"
#define D_CONFIGURE_LOGGING "Configurar registro"
#define D_CONFIGURE_OTHER "Configurar outras opções"
#define D_CONFIRM_RESET_CONFIGURATION "Confirme o reinício da configuração"
#define D_RESET_CONFIGURATION "Apagar configuração"
#define D_BACKUP_CONFIGURATION "Guardar configuração"
#define D_RESTORE_CONFIGURATION "Repor configuração"
#define D_MAIN_MENU "Menu Principal"

#define D_MODULE_PARAMETERS "Parametros do Módulo"
#define D_MODULE_TYPE "Tipo de Módulo"
#define D_PULLUP_ENABLE "Sem pull-up de Botão/Interruptor"
#define D_ADC "ADC"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Entrada de porta série"
#define D_SERIAL_OUT "Saída de porta série"

#define D_WIFI_PARAMETERS "Parametros Wifi"
#define D_SCAN_FOR_WIFI_NETWORKS "Procurar redes Wifi"
#define D_SCAN_DONE "Pesquisa terminada"
#define D_NO_NETWORKS_FOUND "Sem redes encontradas"
#define D_REFRESH_TO_SCAN_AGAIN "Atualize para realizar nova pesquisa"
#define D_DUPLICATE_ACCESSPOINT "Duplicar ponto de Acesso"
#define D_SKIPPING_LOW_QUALITY "Ignorado devido a baixa qualidade do sinal"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "SSId do AP1"
#define D_AP1_PASSWORD "Palavra Chave do AP1"
#define D_AP2_SSID "SSId do AP2"
#define D_AP2_PASSWORD "Palavra Chave do AP2"

#define D_MQTT_PARAMETERS "Parametros MQTT"
#define D_CLIENT "Cliente"
#define D_FULL_TOPIC "Tópico completo"

#define D_LOGGING_PARAMETERS "Parametros para registro"
#define D_SERIAL_LOG_LEVEL "Nível de registro na porta série"
#define D_MQTT_LOG_LEVEL "Nível de registro MQTT"
#define D_WEB_LOG_LEVEL "Nível de registro WEB"
#define D_SYS_LOG_LEVEL "Nível de registro do Syslog"
#define D_MORE_DEBUG "Depurar mais"
#define D_SYSLOG_HOST "Anfitrião Syslog"
#define D_SYSLOG_PORT "Porta Syslog"
#define D_TELEMETRY_PERIOD "Período de Telemetria"

#define D_OTHER_PARAMETERS "Outros parametros"
#define D_TEMPLATE "Modelo"
#define D_ACTIVATE "Ativar"
#define D_DEVICE_NAME "Device Name"
#define D_WEB_ADMIN_PASSWORD "Palavra Chave do Admin WEB"
#define D_MQTT_ENABLE "MQTT habilitado"
#define D_MQTT_TLS_ENABLE "MQTT TLS"
#define D_FRIENDLY_NAME "Nome amigável"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "dispositivo único"
#define D_MULTI_DEVICE "dispositivo múltiplo"

#define D_CONFIGURE_TEMPLATE "Configurar Modelo"
#define D_TEMPLATE_PARAMETERS "Parametros do Modelo"
#define D_TEMPLATE_NAME "Nome do Modelo"
#define D_BASE_TYPE "Baseado em"
#define D_TEMPLATE_FLAGS "Opções"

#define D_SAVE_CONFIGURATION "Guardar configuração"
#define D_CONFIGURATION_SAVED "Configuração guardada"
#define D_CONFIGURATION_RESET "Reinicializar a configuração"

#define D_PROGRAM_VERSION "Versão do Programa"
#define D_BUILD_DATE_AND_TIME "Data e Hora de criação"
#define D_CORE_AND_SDK_VERSION "Versão Core/SDK"
#define D_FLASH_WRITE_COUNT "Contagem de gravação da flash"
#define D_MAC_ADDRESS "Endereço MAC"
#define D_MQTT_HOST "Servidor MQTT"
#define D_MQTT_PORT "Porta MQTT"
#define D_MQTT_CLIENT "Cliente MQTT"
#define D_MQTT_USER "Utilizador MQTT"
#define D_MQTT_TOPIC "Tópico MQTT"
#define D_MQTT_GROUP_TOPIC "Tópico MQTT de Grupo"
#define D_MQTT_FULL_TOPIC "Tópico MQTT Completo"
#define D_MQTT_NO_RETAIN "MQTT No Retain"
#define D_MDNS_DISCOVERY "Descobrir mDNS"
#define D_MDNS_ADVERTISE "Anunciar mDNS"
#define D_ESP_CHIP_ID "ID do chip ESP"
#define D_FLASH_CHIP_ID "ID do chip da Flash"
#define D_FLASH_CHIP_SIZE "Tamanho da Flash"
#define D_FREE_PROGRAM_SPACE "Espaço de Programa Livre"

#define D_UPGRADE_BY_WEBSERVER "Atualizar pelo servidor WEB"
#define D_OTA_URL "Url OTA"
#define D_START_UPGRADE "Iniciar atualização"
#define D_UPGRADE_BY_FILE_UPLOAD "Atualizar por envio de ficheiro"
#define D_UPLOAD_STARTED "Envio Iniciado"
#define D_UPGRADE_STARTED "Atualização Iniciada"
#define D_UPLOAD_DONE "Atualização Finalizada"
#define D_UPLOAD_TRANSFER "Upload transfer"
#define D_TRANSFER_STARTED "Transfer started"
#define D_UPLOAD_ERR_1 "Nenhum ficheiro selecionado"
#define D_UPLOAD_ERR_2 "Não existe espaço disponível"
#define D_UPLOAD_ERR_3 "Invalid file signature"
#define D_UPLOAD_ERR_4 "O tamanho do programa e maior do que o tamanho real da flash"
#define D_UPLOAD_ERR_5 "Comparação incorreta do buffer de upload"
#define D_UPLOAD_ERR_6 "Falha no envio. Habilitar registro 3"
#define D_UPLOAD_ERR_7 "Envio cancelado"
#define D_UPLOAD_ERR_8 "Ficheiro inválido"
#define D_UPLOAD_ERR_9 "Ficheiro demasiado grande"
#define D_UPLOAD_ERR_10 "Falha ao iniciar o chip de RF"
#define D_UPLOAD_ERR_11 "Falha ao apagar o chip de RF"
#define D_UPLOAD_ERR_12 "Falha ao escrever no chip de RF"
#define D_UPLOAD_ERR_13 "Falha ao descodificar o firmware RF"
#define D_UPLOAD_ERR_14 "Not compatible"
#define D_UPLOAD_ERROR_CODE "Código de erro do envio"

#define D_ENTER_COMMAND "Inserir comando"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Habilitar weblog 2 se resposta esperada"
#define D_NEED_USER_AND_PASSWORD "Necessário user=<nome utilizador>&password=<palavra chave>"

// xdrv_01_mqtt.ino
#define D_FINGERPRINT "Verifique a impressão digital TLS..."
#define D_TLS_CONNECT_FAILED_TO "TLS não conseguiu ligar"
#define D_RETRY_IN "Nova tentativa em"
#define D_VERIFIED "Verificado usando impressão digital"
#define D_INSECURE "Ligação insegura devido à impressão digital inválida"
#define D_CONNECT_FAILED_TO "A ligação falhou ao"

// xplg_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast desabilitado"
#define D_MULTICAST_REJOINED "Multicast (re)ingressado"
#define D_MULTICAST_JOIN_FAILED "Multicast falha no reingresso"
#define D_FAILED_TO_SEND_RESPONSE "Falha no envio de reposta"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo evento básico"
#define D_WEMO_EVENT_SERVICE "WeMo evento de serviço"
#define D_WEMO_META_SERVICE "WeMo serviço meta"
#define D_WEMO_SETUP "WeMo configuração"
#define D_RESPONSE_SENT "Resposta enviada"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Configuração do Hue"
#define D_HUE_API_NOT_IMPLEMENTED "API Hue nao implementada"
#define D_HUE_API "API Hue"
#define D_HUE_POST_ARGS "Argumentos de POST HUE"
#define D_3_RESPONSE_PACKETS_SENT "3 pacotes de resposta enviados"

// xdrv_07_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Parametros Domoticz"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Chave idx"
#define D_DOMOTICZ_SWITCH_IDX "Interruptor idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Hum"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Hum,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Potência,Energia"
  #define D_DOMOTICZ_ILLUMINANCE "Luminâcia"
  #define D_DOMOTICZ_COUNT "Contagem/PM1"
  #define D_DOMOTICZ_VOLTAGE "Voltagem/PM2.5"
  #define D_DOMOTICZ_CURRENT "Corrente/PM10"
  #define D_DOMOTICZ_AIRQUALITY "Qualidade do Ar"
  #define D_DOMOTICZ_P1_SMART_METER "P1SmartMeter"
#define D_DOMOTICZ_UPDATE_TIMER "Temporizador de atualização"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Configurar temporizador"
#define D_TIMER_PARAMETERS "Parâmetros do temporizador"
#define D_TIMER_ENABLE "Habilitar Temporizadores"
#define D_TIMER_ARM "Armar"
#define D_TIMER_TIME "Tempo"
#define D_TIMER_DAYS "Dias"
#define D_TIMER_REPEAT "Repetir"
#define D_TIMER_OUTPUT "Aaída"
#define D_TIMER_ACTION "Açao"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Configurar KNX"
#define D_KNX_PARAMETERS "Parâmetros KNX"
#define D_KNX_GENERAL_CONFIG "Geral"
#define D_KNX_PHYSICAL_ADDRESS "Endereço físico"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "( Deve ser exclusivo na rede KNX )"
#define D_KNX_ENABLE "Habilitar KNX"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Dados para enviar para Endereços de Grupo"
#define D_ADD "Adicionar"
#define D_DELETE "Remover"
#define D_REPLY "Responder"
#define D_KNX_GROUP_ADDRESS_TO_READ "Endereços de Grupo de onde receber dados"
#define D_RECEIVED_FROM "Recebido de"
#define D_KNX_COMMAND_WRITE "Escrever"
#define D_KNX_COMMAND_READ "Ler"
#define D_KNX_COMMAND_OTHER "Outro"
#define D_SENT_TO "enviar para"
#define D_KNX_WARNING "O Endereço de Grupo ( 0 / 0 / 0 ) está reservado e não pode ser usado."
#define D_KNX_ENHANCEMENT "Melhoria de Comunicação"
#define D_KNX_TX_SLOT "KNX TX"
#define D_KNX_RX_SLOT "KNX RX"
#define D_KNX_TX_SCENE "KNX SCENE TX"
#define D_KNX_RX_SCENE "KNX SCENE RX"

// xdrv_23_zigbee
#define D_ZIGBEE_PERMITJOIN_ACTIVE "Devices allowed to join"
#define D_ZIGBEE_MAPPING_TITLE "Tasmota Zigbee Mapping"
#define D_ZIGBEE_NOT_STARTED "Zigbee not started"
#define D_ZIGBEE_MAPPING_IN_PROGRESS_SEC "Mapping in progress (%d s. remaining)"
#define D_ZIGBEE_MAPPING_NOT_PRESENT "No mapping"
#define D_ZIGBEE_MAP_REFRESH "Zigbee Map Refresh"
#define D_ZIGBEE_MAP   "Zigbee Map"
#define D_ZIGBEE_PERMITJOIN "Zigbee Permit Join"
#define D_ZIGBEE_GENERATE_KEY "generating random Zigbee network key"
#define D_ZIGBEE_UNKNOWN_DEVICE "Unknown device"
#define D_ZIGBEE_UNKNOWN_ATTRIBUTE "Unknown attribute"
#define D_ZIGBEE_INVALID_PARAM "Invalid parameter"
#define D_ZIGBEE_MISSING_PARAM "Missing parameters"
#define D_ZIGBEE_UNKNWON_ATTRIBUTE "Unknown attribute name (ignored): %s"
#define D_ZIGBEE_TOO_MANY_CLUSTERS "No more than one cluster id per command"
#define D_ZIGBEE_WRONG_DELIMITER "Wrong delimiter for payload"
#define D_ZIGBEE_UNRECOGNIZED_COMMAND "Unrecognized zigbee command: %s"
#define D_ZIGBEE_TOO_MANY_COMMANDS "Only 1 command allowed (%d)"
#define D_ZIGBEE_NO_ATTRIBUTE "No attribute in list"
#define D_ZIGBEE_UNSUPPORTED_ATTRIBUTE_TYPE "Unsupported attribute type"
#define D_ZIGBEE_JSON_REQUIRED "Config requires JSON objects"
#define D_ZIGBEE_RESET_1_OR_2 "1 or 2 to reset"
#define D_ZIGBEE_EEPROM_FOUND_AT_ADDRESS "ZBBridge EEPROM found at address"
#define D_ZIGBEE_RANDOMIZING_ZBCONFIG "Randomizing Zigbee parameters, please check with 'ZbConfig'"

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Consumo energético de hoje"
#define D_ENERGY_YESTERDAY "Consumo energético de ontem"
#define D_ENERGY_TOTAL "Consumo energético total"

// xdrv_27_shutter.ino
#define D_OPEN "Abrir"
#define D_CLOSE "Fechar"
#define D_DOMOTICZ_SHUTTER "Estore"

// xdrv_28_pcf8574.ino
#define D_CONFIGURE_PCF8574 "Configurar PCF8574"
#define D_PCF8574_PARAMETERS "Parâmetros PCF8574"
#define D_INVERT_PORTS "Inverter Portas"
#define D_DEVICE "Dispositivo"
#define D_DEVICE_INPUT "Entrada"
#define D_DEVICE_OUTPUT "Saída"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Sensor ocupado"
#define D_SENSOR_CRC_ERROR "Erro no CRC do sensor"
#define D_SENSORS_FOUND "Sensores encontrados"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Fim do tempo de espera"
#define D_START_SIGNAL_LOW "Sinal de início baixo"
#define D_START_SIGNAL_HIGH "Sinal de início elevado"
#define D_PULSE "pulso"
#define D_CHECKSUM_FAILURE "Falha na soma de verificação"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Sensor não aceitou o comando ACK"
#define D_SHT1X_FOUND "SHT1X encontrado"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Partículas"

// xsns_27_apds9960.ino
#define D_GESTURE "Gesture"
#define D_COLOR_RED "Red"
#define D_COLOR_GREEN "Green"
#define D_COLOR_BLUE "Blue"
#define D_CCT "CCT"
#define D_PROXIMITY "Proximity"

// xsns_32_mpu6050.ino
#define D_AX_AXIS "Accel. X-Axis"
#define D_AY_AXIS "Accel. Y-Axis"
#define D_AZ_AXIS "Accel. Z-Axis"
#define D_GX_AXIS "Gyro X-Axis"
#define D_GY_AXIS "Gyro Y-Axis"
#define D_GZ_AXIS "Gyro Z-Axis"

// xsns_34_hx711.ino
#define D_HX_CAL_REMOVE "Remover peso"
#define D_HX_CAL_REFERENCE "Carregar peso de referência"
#define D_HX_CAL_DONE "Calibrado"
#define D_HX_CAL_FAIL "Falha na calibração"
#define D_RESET_HX711 "Reiniciar balança"
#define D_CONFIGURE_HX711 "Configurar balança"
#define D_HX711_PARAMETERS "Parâmetros da balança"
#define D_ITEM_WEIGHT "Peso do item"
#define D_REFERENCE_WEIGHT "Peso de referência"
#define D_CALIBRATE "Calibrar"
#define D_CALIBRATION "Calibração"

//xsns_35_tx20.ino
#define D_TX20_WIND_DIRECTION "Direção do vento"
#define D_TX20_WIND_SPEED "Velocidade do vento"
#define D_TX20_WIND_SPEED_MIN "Velocidade mínima do vento"
#define D_TX20_WIND_SPEED_MAX "Velocidade máxima do vento"
#define D_TX20_NORTH "N"
#define D_TX20_EAST "E"
#define D_TX20_SOUTH "S"
#define D_TX20_WEST "O"

//xsns_53_sml.ino
#define D_TPWRIN "Energia-Consumo"
#define D_TPWROUT "Energia-Geração"
#define D_TPWRCURR "Potência Ativa-Consumo/Geração"
#define D_TPWRCURR1 "Potência Ativa-Consumo F1"
#define D_TPWRCURR2 "Potência Ativa-Consumo F2"
#define D_TPWRCURR3 "Potência Ativa-Consumo F3"
#define D_Strom_L1 "Corrente F1"
#define D_Strom_L2 "Corrente F2"
#define D_Strom_L3 "Corrente F3"
#define D_Spannung_L1 "Tensão F1"
#define D_Spannung_L2 "Tensão F2"
#define D_Spannung_L3 "Tensão F3"
#define D_METERNR "Número_Contador"
#define D_METERSID "ID Serviço"
#define D_GasIN "Contagem"
#define D_H2oIN "Contagem"
#define D_StL1L2L3 "Corrente F1+F2+F3"
#define D_SpL1L2L3 "Tensão F1+F2+F3/3"

// tasmota_template.h - keep them as short as possible to be able to fit them in GUI drop down box
#define D_SENSOR_NONE          "Nenhum"
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
#define D_SENSOR_SWITCH        "Interruptor"  // Suffix "1"
#define D_SENSOR_BUTTON        "Botão"      // Suffix "1"
#define D_SENSOR_RELAY         "Relé"       // Suffix "1i"
#define D_SENSOR_LED           "Led"        // Suffix "1i"
#define D_SENSOR_LED_LINK      "LedLink"    // Suffix "i"
#define D_SENSOR_PWM           "PWM"        // Suffix "1"
#define D_SENSOR_COUNTER       "Contador"   // Suffix "1"
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
#define D_SENSOR_BACKLIGHT     "Luz fundo"
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
#define D_SENSOR_RF_SENSOR     "Sensor RF"
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
#define D_SENSOR_ROTARY        "Rotativo"     // Suffix "1A"
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
#define D_SENSOR_SDCARD_CS     "SDCard CS"

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
#define D_UNIT_KILOMETER_PER_HOUR "km/h"  // or "km/h"
#define D_UNIT_KILOOHM "kΩ"
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
#define D_UNIT_MINUTE "Min"
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PERCENT "%%"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "sec"
#define D_UNIT_SECTORS "setores"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "Wh"
#define D_UNIT_WATT_METER_QUADRAT "W/m²"

//SDM220, SDM120, LE01MR
#define D_PHASE_ANGLE     "Ângulo de fase"
#define D_IMPORT_ACTIVE   "Ativo importado"
#define D_EXPORT_ACTIVE   "Ativo exportado"
#define D_IMPORT_REACTIVE "Reativo importado"
#define D_EXPORT_REACTIVE "Reativo exportado"
#define D_TOTAL_REACTIVE  "Reactivo total"
#define D_UNIT_KWARH      "kVArh"
#define D_UNIT_ANGLE      "Deg"
#define D_TOTAL_ACTIVE    "Total Active"

//SOLAXX1
#define D_PV1_VOLTAGE     "Voltagem PV1"
#define D_PV1_CURRENT     "Corrente PV1"
#define D_PV1_POWER       "Potência PV1"
#define D_PV2_VOLTAGE     "Voltagem PV2"
#define D_PV2_CURRENT     "Corrente PV2"
#define D_PV2_POWER       "Potência PV2"
#define D_SOLAR_POWER     "Potência Solar"
#define D_INVERTER_POWER  "Potência do Inversor"
#define D_STATUS          "Estado"
#define D_WAITING         "Esperando"
#define D_CHECKING        "Verificando"
#define D_WORKING         "Trabalhando"
#define D_FAILURE         "Falha"
#define D_SOLAX_ERROR_0   "Nenhum código de erro"
#define D_SOLAX_ERROR_1   "Falha devido a perda de rede"
#define D_SOLAX_ERROR_2   "Falha devido a perda de tensão"
#define D_SOLAX_ERROR_3   "Falha devido a perda de frequência"
#define D_SOLAX_ERROR_4   "Falha de tensão de Pv"
#define D_SOLAX_ERROR_5   "Falha de isolamento"
#define D_SOLAX_ERROR_6   "Falha de temperatura excessiva"
#define D_SOLAX_ERROR_7   "Falha no ventilador"
#define D_SOLAX_ERROR_8   "Outra falha no dispositivo"

//xdrv_10_scripter.ino
#define D_CONFIGURE_SCRIPT     "Edit script"
#define D_SCRIPT               "edit script"
#define D_SDCARD_UPLOAD        "file upload"
#define D_SDCARD_DIR           "sd card directory"
#define D_UPL_DONE             "Done"
#define D_SCRIPT_CHARS_LEFT    "chars left"
#define D_SCRIPT_CHARS_NO_MORE "no more chars"
#define D_SCRIPT_DOWNLOAD      "Download"
#define D_SCRIPT_ENABLE        "script enable"
#define D_SCRIPT_UPLOAD        "Upload"
#define D_SCRIPT_UPLOAD_FILES  "Upload files"

//xsns_67_as3935.ino
#define D_AS3935_GAIN "gain:"
#define D_AS3935_ENERGY "energy:"
#define D_AS3935_DISTANCE "distance:"
#define D_AS3935_DISTURBER "disturber:"
#define D_AS3935_VRMS "µVrms:"
#define D_AS3935_APRX "aprx.:"
#define D_AS3935_AWAY "away"
#define D_AS3935_LIGHT "lightning"
#define D_AS3935_OUT "lightning out of range"
#define D_AS3935_NOT "distance not determined"
#define D_AS3935_ABOVE "lightning overhead"
#define D_AS3935_NOISE "noise detected"
#define D_AS3935_DISTDET "disturber detected"
#define D_AS3935_INTNOEV "Interrupt with no Event!"
#define D_AS3935_FLICKER "IRQ flicker!"
#define D_AS3935_POWEROFF "Power Off"
#define D_AS3935_NOMESS "listening..."
#define D_AS3935_ON "On"
#define D_AS3935_OFF "Off"
#define D_AS3935_INDOORS "Indoors"
#define D_AS3935_OUTDOORS "Outdoors"
#define D_AS3935_CAL_FAIL "calibration failed"
#define D_AS3935_CAL_OK "calibration set to:"

//xsns_68_opentherm.ino
#define D_SENSOR_BOILER_OT_RX   "OpenTherm RX"
#define D_SENSOR_BOILER_OT_TX   "OpenTherm TX"

// xnrg_15_teleinfo Denky (Teleinfo)
#define D_CONTRACT        "Contract"
#define D_POWER_LOAD      "Power load"
#define D_CURRENT_TARIFF  "Current Tariff"
#define D_TARIFF          "Tariff"
#define D_OVERLOAD        "ADPS"
#define D_MAX_POWER       "Max Power"
#define D_MAX_CURRENT     "Max Current"

// xsns_79_as608.ino
#define D_FP_ENROLL_PLACEFINGER "Place finger"
#define D_FP_ENROLL_REMOVEFINGER "Remove finger"
#define D_FP_ENROLL_PLACESAMEFINGER "Place same finger again"
#define D_FP_ENROLL_RETRY "Error so retry"
#define D_FP_ENROLL_RESTART "Restart"
#define D_FP_ENROLL_ERROR "Error"
#define D_FP_ENROLL_RESET "Reset"
#define D_FP_ENROLL_ACTIVE "Active"
#define D_FP_ENROLL_INACTIVE "Inactive"
// Indexed by Adafruit_Fingerprint.h defines
#define D_FP_PACKETRECIEVEERR "Comms error"    // 0x01 Error when receiving data package
#define D_FP_NOFINGER ""                       // 0x02 No finger on the sensor
#define D_FP_IMAGEFAIL "Imaging error"         // 0x03 Failed to enroll the finger
#define D_FP_IMAGEMESS "Image too messy"       // 0x06 Failed to generate character file due to overly disorderly fingerprint image
#define D_FP_FEATUREFAIL "Fingerprint too small" // 0x07 Failed to generate character file due to the lack of character point or small fingerprint image
#define D_FP_NOMATCH "No match"                // 0x08 Finger doesn't match
#define D_FP_NOTFOUND "Did not find a match"   // 0x09 Failed to find matching finger
#define D_FP_ENROLLMISMATCH "Fingerprint did not match" // 0x0A Failed to combine the character files
#define D_FP_BADLOCATION "Bad location"        // 0x0B Addressed PageID is beyond the finger library
#define D_FP_DBRANGEFAIL "DB range error"      // 0x0C Error when reading template from library or invalid template
#define D_FP_UPLOADFEATUREFAIL "Upload feature error" // 0x0D Error when uploading template
#define D_FP_PACKETRESPONSEFAIL "Packet response error" // 0x0E Module failed to receive the following data packages
#define D_FP_UPLOADFAIL "Upload error"         // 0x0F Error when uploading image
#define D_FP_DELETEFAIL "Delete error"         // 0x10 Failed to delete the template
#define D_FP_DBCLEARFAIL "DB Clear error"      // 0x11 Failed to clear finger library
#define D_FP_PASSFAIL "Password error"         // 0x13 Find whether the fingerprint passed or failed
#define D_FP_INVALIDIMAGE "Image invalid"      // 0x15 Failed to generate image because of lac of valid primary image
#define D_FP_FLASHERR "Flash write error"      // 0x18 Error when writing flash
#define D_FP_INVALIDREG "Invalid number"       // 0x1A Invalid register number
#define D_FP_ADDRCODE "Address code"           // 0x20 Address code
#define D_FP_PASSVERIFY "Password verified"    // 0x21 Verify the fingerprint passed
#define D_FP_UNKNOWNERROR "Error"              // Any other error

#endif  // _LANGUAGE_PT_PT_H_
