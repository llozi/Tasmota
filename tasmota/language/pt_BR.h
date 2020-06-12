/*
  pt-BR.h - localization for Portuguese - Brazil for Tasmota

  Copyright (C) 2020  Fabiano Bovo

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

#ifndef _LANGUAGE_PT_BR_H_
#define _LANGUAGE_PT_BR_H_

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

#define LANGUAGE_LCID 1046
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
#define D_DECIMAL_SEPARATOR ","

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Qualidade do ar"
#define D_AP "Ponto de acesso"     	// Ponto de Acesso
#define D_AS "como"
#define D_AUTO "Auto"
#define D_BLINK "Pulsar"
#define D_BLINKOFF "Pulsar desligado"
#define D_BOOT_COUNT "Contagem de inicialização"
#define D_BRIGHTLIGHT "Brilho"
#define D_BSSID "BSSId"
#define D_BUTTON "Botão"
#define D_BY "por"                    // Write by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CHANNEL "Canal"
#define D_CO2 "CO2"
#define D_CODE "Código"                // Button code
#define D_COLDLIGHT "Luz fria"
#define D_COMMAND "Comando"
#define D_CONNECTED "Ligado"
#define D_CORS_DOMAIN "CORS Domain"
#define D_COUNT "Contagem"
#define D_COUNTER "Contador"
#define D_CT_POWER "CT Power"
#define D_CURRENT "Corrente"          // As in Voltage and Current
#define D_DATA "Dados"
#define D_DARKLIGHT "Luz escura"
#define D_DEBUG "Depurar"
#define D_DEWPOINT "Dew point"
#define D_DISABLED "Desabilitado"
#define D_DISTANCE "Distância"
#define D_DNS_SERVER "Servidor DNS"
#define D_DONE "Concluído"
#define D_DST_TIME "DST"
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
#define D_FILE "Arquivo"
#define D_FLOW_RATE "Quociente de vazão"
#define D_FREE_MEMORY "Memória livre"
#define D_PSR_MAX_MEMORY "PS-RAM Memory"
#define D_PSR_FREE_MEMORY "PS-RAM free Memory"
#define D_FREQUENCY "Frequência"
#define D_GAS "Gás"
#define D_GATEWAY "Gateway"
#define D_GROUP "Grupo"
#define D_HOST "Host"
#define D_HOSTNAME "Nome do Host"
#define D_HUMIDITY "Umidade"
#define D_ILLUMINANCE "Luminância"
#define D_IMMEDIATE "Imediato"      // Button immediate
#define D_INDEX "Índice"
#define D_INFO "Informação"
#define D_INFRARED "Infravermelho"
#define D_INITIALIZED "Inicializado"
#define D_IP_ADDRESS "Endereço IP"
#define D_LIGHT "Luz"
#define D_LWT "LWT"
#define D_MODULE "Módulo"
#define D_MOISTURE "Umidade"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "multi-pressão"
#define D_NOISE "Ruído"
#define D_NONE "Nenhum"
#define D_OFF "Desligado"
#define D_OFFLINE "Desconectado"
#define D_OK "Ok"
#define D_ON "Ligado"
#define D_ONLINE "Conectado"
#define D_PASSWORD "Senha"
#define D_PORT "Porta"
#define D_POWER_FACTOR "Fator de potência"
#define D_POWERUSAGE "Potência"
#define D_POWERUSAGE_ACTIVE "Potência ativa"
#define D_POWERUSAGE_APPARENT "Potência aparente"
#define D_POWERUSAGE_REACTIVE "Potência reativa"
#define D_PRESSURE "Pressão"
#define D_PRESSUREATSEALEVEL "Pressão ao nível do mar"
#define D_PROGRAM_FLASH_SIZE "Tamanho do programa na memória"
#define D_PROGRAM_SIZE "Tamanho do programa"
#define D_PROJECT "Projeto"
#define D_RAIN "Rain"
#define D_RANGE "Range"
#define D_RECEIVED "Recebido"
#define D_RESTART "Reiniciar"
#define D_RESTARTING "Reiniciando"
#define D_RESTART_REASON "Motivo do reinício"
#define D_RESTORE "Restauração"
#define D_RETAINED "Manter"
#define D_RULE "Regra"
#define D_SAVE "Salvar"
#define D_SENSOR "Sensor"
#define D_SSID "SSId"
#define D_START "Iniciar"
#define D_STD_TIME "STD"
#define D_STOP "Parar"
#define D_SUBNET_MASK "Máscara sub rede"
#define D_SUBSCRIBE_TO "Subescrever para"
#define D_UNSUBSCRIBE_FROM "Unsubscribe from"
#define D_SUCCESSFUL "Successo"
#define D_SUNRISE "Nascer do sol"
#define D_SUNSET "Por do sol"
#define D_TEMPERATURE "Temperatura"
#define D_TO "Para"
#define D_TOGGLE "Inverter"
#define D_TOPIC "Tópico"
#define D_TOTAL_USAGE "Total Usage"
#define D_TRANSMIT "Transmitir"
#define D_TRUE "Verdadeiro"
#define D_TVOC "TVOC"
#define D_UPGRADE "atualização"
#define D_UPLOAD "Enviar"
#define D_UPTIME "Tempo de atividade"
#define D_USER "Usuário"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "Índice UV"
#define D_UV_INDEX_1 "Baixo"
#define D_UV_INDEX_2 "Médio"
#define D_UV_INDEX_3 "Alto"
#define D_UV_INDEX_4 "Perigro"
#define D_UV_INDEX_5 "BurnL1/2"
#define D_UV_INDEX_6 "BurnL3"
#define D_UV_INDEX_7 "OoR"
#define D_UV_LEVEL "Nível UV"
#define D_UV_POWER "UV Power"
#define D_VERSION "Versão"
#define D_VOLTAGE "Voltagem"
#define D_WEIGHT "Peso"
#define D_WARMLIGHT "Luz quente"
#define D_WEB_SERVER "Servidor WEB"

// tasmota.ino
#define D_WARNING_MINIMAL_VERSION "AVISO: esta versão não supporta configurações persistentes"
#define D_LEVEL_10 "nível 1-0"
#define D_LEVEL_01 "nível 0-1"
#define D_SERIAL_LOGGING_DISABLED "Registro Serial desabilitado"
#define D_SYSLOG_LOGGING_REENABLED "Registro do Syslog reativado"

#define D_SET_BAUDRATE_TO "Ajuste da velocidade para"
#define D_RECEIVED_TOPIC "Tópico recebido"
#define D_DATA_SIZE "Tamanho de dados"
#define D_ANALOG_INPUT "Entrada analógica"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Loop bloqueado"
#define D_WPS_FAILED_WITH_STATUS "WPSconfig falha de estado"
#define D_ACTIVE_FOR_3_MINUTES "Ativo por 3 minutos"
#define D_FAILED_TO_START "Falha ao iníciar"
#define D_PATCH_ISSUE_2186 "Questão 2186"
#define D_CONNECTING_TO_AP "Ligando ao PA"
#define D_IN_MODE "em modo"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "A ligação falhou porque nenhum endereço IP foi recebido"
#define D_CONNECT_FAILED_AP_NOT_REACHED "A ligação falhou porque o PA não pôde ser alcançado"
#define D_CONNECT_FAILED_WRONG_PASSWORD "A ligação falhou"
#define D_CONNECT_FAILED_AP_TIMEOUT "A ligação falhou porque o tempo foi excedido"
#define D_ATTEMPTING_CONNECTION "Ligando..."
#define D_CHECKING_CONNECTION "Verificando ligação..."
#define D_QUERY_DONE "Consulta finalizada. Serviço MQTT não encontrado"
#define D_MQTT_SERVICE_FOUND "Serviço MQTT encontrado em"
#define D_FOUND_AT "encontrado em"
#define D_SYSLOG_HOST_NOT_FOUND "Syslog anfitrião não encontrado"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Guardado na flash em"
#define D_LOADED_FROM_FLASH_AT "Lido da flash em"
#define D_USE_DEFAULTS "Usar predefinições"
#define D_ERASED_SECTOR "Apagar setores"

// xdrv_02_webserver.ino
#define D_NOSCRIPT "To use Tasmota, please enable JavaScript"
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "Firmware mínimo<br>Atualizar por favor"
#define D_WEBSERVER_ACTIVE_ON "Servidor WEB ativo em"
#define D_WITH_IP_ADDRESS "com o endereço IP"
#define D_WEBSERVER_STOPPED "Servidor WEB parou"
#define D_FILE_NOT_FOUND "Arquivo não encontrado"
#define D_REDIRECTED "Redirecionado para o portal ativo"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifimanager: configura o Ponto de Acesso e a Estação"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifimanager: configura o Ponto de Acesso"
#define D_TRYING_TO_CONNECT "Conectar o dispositivo à rede"

#define D_RESTART_IN "Reinicia em"
#define D_SECONDS "segundos"
#define D_DEVICE_WILL_RESTART "O dispositivo irá reiniciar dentro de alguns segundos"
#define D_BUTTON_TOGGLE "Comandar"
#define D_CONFIGURATION "Configuração"
#define D_INFORMATION "Informação"
#define D_FIRMWARE_UPGRADE "Atualização de Firmware"
#define D_CONSOLE "Console"
#define D_CONFIRM_RESTART "Confirmar o reinicio"

#define D_CONFIGURE_MODULE "Configurar Módulo"
#define D_CONFIGURE_WIFI "Configurar WiFi"
#define D_CONFIGURE_MQTT "Configurar MQTT"
#define D_CONFIGURE_DOMOTICZ "Configurar Domoticz"
#define D_CONFIGURE_LOGGING "Configurar Logging"
#define D_CONFIGURE_OTHER "Configurar outras opções"
#define D_CONFIRM_RESET_CONFIGURATION "Confirmar limpeza de configuração"
#define D_RESET_CONFIGURATION "Apagar configuração"
#define D_BACKUP_CONFIGURATION "Salvar configuração"
#define D_RESTORE_CONFIGURATION "Repor configuração"
#define D_MAIN_MENU "Menu principal"

#define D_MODULE_PARAMETERS "Parâmetros do módulo"
#define D_MODULE_TYPE "Tipo de módulo"
#define D_PULLUP_ENABLE "No Button/Switch pull-up"
#define D_ADC "ADC"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Entrada serial"
#define D_SERIAL_OUT "Saída serial"

#define D_WIFI_PARAMETERS "Parâmetros do wifi"
#define D_SCAN_FOR_WIFI_NETWORKS "Encontrar redes wifi"
#define D_SCAN_DONE "Busca finalizada"
#define D_NO_NETWORKS_FOUND "Sem redes"
#define D_REFRESH_TO_SCAN_AGAIN "Nova busca"
#define D_DUPLICATE_ACCESSPOINT "Ponto de Acesso duplicado"
#define D_SKIPPING_LOW_QUALITY "Ignorado devido à baixa qualidade do sinal"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "AP1 SSId"
#define D_AP1_PASSWORD "Senha AP1"
#define D_AP2_SSID "AP2 SSId"
#define D_AP2_PASSWORD "Senha AP2"

#define D_MQTT_PARAMETERS "Parâmetros MQTT"
#define D_CLIENT "Cliente"
#define D_FULL_TOPIC "Tópico completo"

#define D_LOGGING_PARAMETERS "Parâmetros Logging"
#define D_SERIAL_LOG_LEVEL "Nível de registro serial"
#define D_MQTT_LOG_LEVEL "Mqtt log level"
#define D_WEB_LOG_LEVEL "Nível de registro WEB"
#define D_SYS_LOG_LEVEL "Nível de registro Syslog"
#define D_MORE_DEBUG "Depurar mais"
#define D_SYSLOG_HOST "Syslog anfitrião"
#define D_SYSLOG_PORT "Porta Syslog"
#define D_TELEMETRY_PERIOD "Período de telemetria"

#define D_OTHER_PARAMETERS "Outros parâmetros"
#define D_TEMPLATE "Modelo"
#define D_ACTIVATE "Activate"
#define D_DEVICE_NAME "Device Name"
#define D_WEB_ADMIN_PASSWORD "Senha de WEB Admin"
#define D_MQTT_ENABLE "MQTT habilitado"
#define D_FRIENDLY_NAME "Nome amigável"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "Dispositivo único"
#define D_MULTI_DEVICE "Múltiplos dispositivos"

#define D_CONFIGURE_TEMPLATE "Configurar Modelo"
#define D_TEMPLATE_PARAMETERS "Parâmetros Modelo"
#define D_TEMPLATE_NAME "Nome"
#define D_BASE_TYPE "Baseado em"
#define D_TEMPLATE_FLAGS "Opções"

#define D_SAVE_CONFIGURATION "Gravar configuração"
#define D_CONFIGURATION_SAVED "Configuração gravada"
#define D_CONFIGURATION_RESET "Reinicialização da configuração"

#define D_PROGRAM_VERSION "Versão do programa"
#define D_BUILD_DATE_AND_TIME "Data e Hora da compilação"
#define D_CORE_AND_SDK_VERSION "Versão Core/SDK"
#define D_FLASH_WRITE_COUNT "Contagem de gravação flash"
#define D_MAC_ADDRESS "Endereço MAC"
#define D_MQTT_HOST "MQTT Servidor"
#define D_MQTT_PORT "MQTT Porta"
#define D_MQTT_CLIENT "MQTT Cliente"
#define D_MQTT_USER "MQTT Usuário"
#define D_MQTT_TOPIC "MQTT Tópico"
#define D_MQTT_GROUP_TOPIC "MQTT Tópico Grupo"
#define D_MQTT_FULL_TOPIC "MQTT Tópico Completo"
#define D_MDNS_DISCOVERY "Descobrir mDNS"
#define D_MDNS_ADVERTISE "Anunciar mDNS"
#define D_ESP_CHIP_ID "ESP Chip Id"
#define D_FLASH_CHIP_ID "Flash Chip Id"
#define D_FLASH_CHIP_SIZE "Flash Size"
#define D_FREE_PROGRAM_SPACE "Espaço Livre Programa"

#define D_UPGRADE_BY_WEBSERVER "Atualizar pelo servidor WEB"
#define D_OTA_URL "OTA Url"
#define D_START_UPGRADE "Iniciar atualização"
#define D_UPGRADE_BY_FILE_UPLOAD "Atualização por arquivo local"
#define D_UPLOAD_STARTED "Início do envio"
#define D_UPGRADE_STARTED "Atualização iniciada"
#define D_UPLOAD_DONE "Atualização finalizada"
#define D_UPLOAD_ERR_1 "Nenhum arquivo selecionado"
#define D_UPLOAD_ERR_2 "Não existe memória disponível"
#define D_UPLOAD_ERR_3 "Byte mágico não é 0xE9"
#define D_UPLOAD_ERR_4 "O tamanho do programa é maior do que o tamanho da memória"
#define D_UPLOAD_ERR_5 "Envio buffer miscompare"
#define D_UPLOAD_ERR_6 "Falha no envio. Habilitar logging 3"
#define D_UPLOAD_ERR_7 "Envio cancelado"
#define D_UPLOAD_ERR_8 "Arquivo inválido"
#define D_UPLOAD_ERR_9 "Arquivo muito grande"
#define D_UPLOAD_ERR_10 "Falha ao iniciar chip RF"
#define D_UPLOAD_ERR_11 "Falha ao apagar o chip RF"
#define D_UPLOAD_ERR_12 "Falha ao escrever o chip RF"
#define D_UPLOAD_ERR_13 "Falha ao decodificar o firmware de RF"
#define D_UPLOAD_ERR_14 "Not compatible"
#define D_UPLOAD_ERROR_CODE "Código de erro do envio"

#define D_ENTER_COMMAND "Inserir comando"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Habilitar weblog 2 se resposta esperada"
#define D_NEED_USER_AND_PASSWORD "Necessário user=<nome usuário>&password=<senha>"

// xdrv_01_mqtt.ino
#define D_FINGERPRINT "Verifique a impressão digital TLS..."
#define D_TLS_CONNECT_FAILED_TO "TLS não conseguiu ligar"
#define D_RETRY_IN "Tentativa em"
#define D_VERIFIED "Verificado impressão digital "
#define D_INSECURE "Ligação insegura devido à impressão digital inválida"
#define D_CONNECT_FAILED_TO "A ligação falhou ao"

// xplg_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast desabilitado"
#define D_MULTICAST_REJOINED "Multicast (re)ingressou"
#define D_MULTICAST_JOIN_FAILED "Multicast falha no reingresso"
#define D_FAILED_TO_SEND_RESPONSE "Falha no envio de reposta"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo evento básico"
#define D_WEMO_EVENT_SERVICE "WeMo evento de serviço"
#define D_WEMO_META_SERVICE "WeMo serviço meta"
#define D_WEMO_SETUP "WeMo configuração"
#define D_RESPONSE_SENT "Resposta enviada"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Hue setup"
#define D_HUE_API_NOT_IMPLEMENTED "Hue API nao implementada"
#define D_HUE_API "Hue API"
#define D_HUE_POST_ARGS "Hue POST args"
#define D_3_RESPONSE_PACKETS_SENT "3 pacotes de resposta enviados"

// xdrv_07_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Parâmetros Domoticz"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Chave idx"
#define D_DOMOTICZ_SWITCH_IDX "Interruptor idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Umi"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Umi,Pres"
  #define D_DOMOTICZ_POWER_ENERGY "Potência,Energia"
  #define D_DOMOTICZ_ILLUMINANCE "Luminância"
  #define D_DOMOTICZ_COUNT "Contagem/PM1"
  #define D_DOMOTICZ_VOLTAGE "Voltagem/PM2.5"
  #define D_DOMOTICZ_CURRENT "Corrente/PM10"
  #define D_DOMOTICZ_AIRQUALITY "Qualidade do ar"
  #define D_DOMOTICZ_P1_SMART_METER "P1SmartMeter"
#define D_DOMOTICZ_UPDATE_TIMER "Tempo de atualização"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Configurar temporizador"
#define D_TIMER_PARAMETERS "Parâmetros"
#define D_TIMER_ENABLE "Habilitar temporizadores"
#define D_TIMER_ARM "Habilitar"
#define D_TIMER_TIME "Horário"
#define D_TIMER_DAYS "Dias"
#define D_TIMER_REPEAT "Repetir"
#define D_TIMER_OUTPUT "Saída"
#define D_TIMER_ACTION "Ação"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Configurar KNX"
#define D_KNX_PARAMETERS "Parâmetros KNX"
#define D_KNX_GENERAL_CONFIG "Geral"
#define D_KNX_PHYSICAL_ADDRESS "Endereço físico"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "(Deve ser único na rede KNX)"
#define D_KNX_ENABLE "Habilitar KNX"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Endereço do grupo para enviar"
#define D_ADD "Adicionar"
#define D_DELETE "Remover"
#define D_REPLY "Responder"
#define D_KNX_GROUP_ADDRESS_TO_READ "Endereço do grupo para receber"
#define D_RECEIVED_FROM "Recebido de"
#define D_KNX_COMMAND_WRITE "Escrever"
#define D_KNX_COMMAND_READ "Ler"
#define D_KNX_COMMAND_OTHER "Outros"
#define D_SENT_TO "Enviar para"
#define D_KNX_WARNING "O endereço ( 0 / 0 / 0 ) é reservado e não pode ser usado."
#define D_KNX_ENHANCEMENT "Melhoria da comunicação"
#define D_KNX_TX_SLOT "KNX TX"
#define D_KNX_RX_SLOT "KNX RX"

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Consumo energético de hoje"
#define D_ENERGY_YESTERDAY "Consumo energético de ontem"
#define D_ENERGY_TOTAL "Consumo total de energia"

// xdrv_27_shutter.ino
#define D_OPEN "Aberta"
#define D_CLOSE "Fechada"
#define D_DOMOTICZ_SHUTTER "Persiana"

// xdrv_28_pcf8574.ino
#define D_CONFIGURE_PCF8574 "Configura PCF8574"
#define D_PCF8574_PARAMETERS "Parâmetros PCF8574"
#define D_INVERT_PORTS "Portas Invertidas"
#define D_DEVICE "Dispositivo"
#define D_DEVICE_INPUT "Input"
#define D_DEVICE_OUTPUT "Output"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Sensor ocupado"
#define D_SENSOR_CRC_ERROR "Erro sensor CRC"
#define D_SENSORS_FOUND "Sensores encontrados"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Fim do tempo de espera"
#define D_START_SIGNAL_LOW "Sinal de início baixo"
#define D_START_SIGNAL_HIGH "Sinal de início elevado"
#define D_PULSE "pulso"
#define D_CHECKSUM_FAILURE "Falha checksum"

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
#define D_HX_CAL_REFERENCE "Peso de referência de carga"
#define D_HX_CAL_DONE "Calibrado"
#define D_HX_CAL_FAIL "Falha na calibração"
#define D_RESET_HX711 "Redefinir escala"
#define D_CONFIGURE_HX711 "Configurar escala"
#define D_HX711_PARAMETERS "Parâmetros de escala"
#define D_ITEM_WEIGHT "Peso do Item"
#define D_REFERENCE_WEIGHT "Peso de referência"
#define D_CALIBRATE "Calibrar"
#define D_CALIBRATION "Calibração"

//xsns_35_tx20.ino
#define D_TX20_WIND_DIRECTION "Direção do vento"
#define D_TX20_WIND_SPEED "Velocidade do vento"
#define D_TX20_WIND_SPEED_MIN "Velocidade do vento Mínima"
#define D_TX20_WIND_SPEED_MAX "Velocidade do vento Máxima"
#define D_TX20_NORTH "N"
#define D_TX20_EAST "L"
#define D_TX20_SOUTH "S"
#define D_TX20_WEST "O"

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
#define D_SENSOR_NONE          "Nenhum"
#define D_SENSOR_USER          "User"
#define D_SENSOR_DHT11         "DHT11"
#define D_SENSOR_AM2301        "AM2301"
#define D_SENSOR_SI7021        "SI7021"
#define D_SENSOR_DS18X20       "DS18x20"
#define D_SENSOR_I2C_SCL       "I2C SCL"
#define D_SENSOR_I2C_SDA       "I2C SDA"
#define D_SENSOR_WS2812        "WS2812"
#define D_SENSOR_DFR562        "MP3 Player"
#define D_SENSOR_IRSEND        "IRsend"
#define D_SENSOR_SWITCH        "Interruptor" // Suffix "1"
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
#define D_SENSOR_BACKLIGHT     "Luz de fundo"
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
#define D_SENSOR_BL0940_RX     "BL0940 Rx"
#define D_SENSOR_CC1101_GDO0   "CC1101 GDO0"
#define D_SENSOR_CC1101_GDO2   "CC1101 GDO2"
#define D_SENSOR_HRXL_RX       "HRXL Rx"
#define D_SENSOR_ELECTRIQ_MOODL "MOODL Tx"
#define D_SENSOR_AS3935        "AS3935"
#define D_SENSOR_WINDMETER_SPEED "WindMeter Spd"
#define D_SENSOR_TELEINFO_RX   "TInfo Rx"
#define D_SENSOR_TELEINFO_ENABLE "TInfo EN"
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

// Units
#define D_UNIT_AMPERE "A"
#define D_UNIT_CELSIUS "C"
#define D_UNIT_CENTIMETER "cm"
#define D_UNIT_DEGREE "°"
#define D_UNIT_FAHRENHEIT "F"
#define D_UNIT_HERTZ "Hz"
#define D_UNIT_HOUR "H"
#define D_UNIT_GALLONS "gal"
#define D_UNIT_GALLONS_PER_MIN "g/m"
#define D_UNIT_INCREMENTS "inc"
#define D_UNIT_KELVIN "K"
#define D_UNIT_KILOMETER "km"
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
#define D_UNIT_MINUTE "M"
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PERCENT "%%"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "s"
#define D_UNIT_SECTORS "setores"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "W/h"
#define D_UNIT_WATT_METER_QUADRAT "W/m²"

//SDM220, SDM120, LE01MR
#define D_PHASE_ANGLE     "Ângulo de Fase"
#define D_IMPORT_ACTIVE   "Importar Ativo"
#define D_EXPORT_ACTIVE   "Exportar Ativo"
#define D_IMPORT_REACTIVE "Importar Reativo"
#define D_EXPORT_REACTIVE "Exportar Reativo"
#define D_TOTAL_REACTIVE  "Reativo total"
#define D_UNIT_KWARH      "kVArh"
#define D_UNIT_ANGLE      "Deg"
#define D_TOTAL_ACTIVE    "Total Active"

//SOLAXX1
#define D_PV1_VOLTAGE     "PV1 Voltagem"
#define D_PV1_CURRENT     "PV1 Corrente"
#define D_PV1_POWER       "PV1 Energia"
#define D_PV2_VOLTAGE     "PV2 Voltagem"
#define D_PV2_CURRENT     "PV2 Corrente"
#define D_PV2_POWER       "PV2 Energia"
#define D_SOLAR_POWER     "Energia Solar"
#define D_INVERTER_POWER  "Potência do Inversor"
#define D_STATUS          "Status"
#define D_WAITING         "Esperando"
#define D_CHECKING        "Verificando"
#define D_WORKING         "Trabalhando"
#define D_FAILURE         "Falha"
#define D_SOLAX_ERROR_0   "Nenhum código de erro"
#define D_SOLAX_ERROR_1   "Erro Grid Perdida"
#define D_SOLAX_ERROR_2   "Falha na Tensão da rede"
#define D_SOLAX_ERROR_3   "Falha na Frequência do Grid"
#define D_SOLAX_ERROR_4   "Pv Falha de Tensão"
#define D_SOLAX_ERROR_5   "Falha de Isolamento"
#define D_SOLAX_ERROR_6   "Falha de Temperatura excessiva"
#define D_SOLAX_ERROR_7   "Falha no Ventilador"
#define D_SOLAX_ERROR_8   "Outra falha do dispositivo"

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

#endif  // _LANGUAGE_PT_BR_H_
