/*
  fr-FR.h - localization for French - France for Tasmota
  Copyright (C) 2021  Olivier Francais
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

#ifndef _LANGUAGE_FR_FR_H_
#define _LANGUAGE_FR_FR_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v9.2.0.3
\*********************************************************************/

#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)

#define LANGUAGE_LCID 1036
// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "fr"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "-"
#define D_MONTH_DAY_SEPARATOR "-"
#define D_DATE_TIME_SEPARATOR "T"
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "DimLunMarMerJeuVenSam"
#define D_MONTH3LIST "JanFevMarAvrMaiJunJulAutSepOctNovDec"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR ","

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Qualité de l'Air"
#define D_AP "AP"                    // Access Point
#define D_AS "comme"
#define D_AUTO "AUTO"
#define D_BATT "Batt"                // Short for Battery
#define D_BLINK "Blink"
#define D_BLINKOFF "BlinkOff"
#define D_BOOT_COUNT "Nombre de boot"
#define D_BRIGHTLIGHT "Luminosité"
#define D_BSSID "BSSId"
#define D_BUTTON "Bouton"
#define D_BY "par"                    // Written by me
#define D_BYTES "Octets"
#define D_CELSIUS "Celsius"
#define D_CHANNEL "Canal"
#define D_CO2 "Dioxyde de carbone"
#define D_CODE "code"                // Button code
#define D_COLDLIGHT "Froid"
#define D_COMMAND "Commande"
#define D_CONNECTED "Connecté"
#define D_CORS_DOMAIN "Domaine CORS"
#define D_COUNT "Compte"
#define D_COUNTER "Compteur"
#define D_CT_POWER "CT Power"
#define D_CURRENT "Courant"          // As in Voltage and Current
#define D_DATA "Donnée"
#define D_DARKLIGHT "Sombre"
#define D_DEBUG "Debug"
#define D_DEWPOINT "Point de rosée"
#define D_DISABLED "Désactivé"
#define D_DISTANCE "Distance"
#define D_DNS_SERVER "Serveur DNS"
#define D_DO "Oxygène dissout"
#define D_DONE "Terminé"
#define D_DST_TIME "DST"
#define D_EC "EC"
#define D_ECO2 "eCO₂"
#define D_EMULATION "Émulation"
#define D_ENABLED "Activé"
#define D_ERASE "Effacer"
#define D_ERROR "Erreur"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "Échoué"
#define D_FALLBACK "Secours"
#define D_FALLBACK_TOPIC "Topic de secours"
#define D_FALSE "Faux"
#define D_FILE "Fichier"
#define D_FLOW_RATE "Débit"
#define D_FREE_MEMORY "Mémoire libre"
#define D_PSR_MAX_MEMORY "Mémoire PS-RAM"
#define D_PSR_FREE_MEMORY "Mémoire PS-RAM libre"
#define D_FREQUENCY "Fréquence"
#define D_GAS "Gaz"
#define D_GATEWAY "Passerelle"
#define D_GROUP "Groupe"
#define D_HOST "Hôte"
#define D_HOSTNAME "Nom d'Hôte"
#define D_HUMIDITY "Humidité"
#define D_ILLUMINANCE "Éclairement"
#define D_IMMEDIATE "immédiat"      // Button immediate
#define D_INDEX "Index"
#define D_INFO "Info"
#define D_INFRARED "Infra-rouge"
#define D_INITIALIZED "Initialisé"
#define D_IP_ADDRESS "Adresse IP"
#define D_LIGHT "Lumière"
#define D_LWT "LWT"
#define D_LQI "LQI"                  // Zigbee Link Quality Index
#define D_MODULE "Module"
#define D_MOISTURE "Humidité"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "multi-pression"
#define D_NOISE "Bruit"
#define D_NONE "Aucun"
#define D_O2 "Oxygène"
#define D_OFF "Arrêt"
#define D_OFFLINE "Déconnecté"
#define D_OK "Ok"
#define D_ON "Marche"
#define D_ONLINE "Connecté"
#define D_ORP "ORP"
#define D_PASSWORD "Mot de passe"
#define D_PH "pH"
#define D_PORT "Port"
#define D_POWER_FACTOR "Fact de puiss"
#define D_POWERUSAGE "Puissance"
#define D_POWERUSAGE_ACTIVE "Puiss active"
#define D_POWERUSAGE_APPARENT "Puiss apparente"
#define D_POWERUSAGE_REACTIVE "Puiss réactive"
#define D_PRESSURE "Pression"
#define D_PRESSUREATSEALEVEL "PressionMer"
#define D_PROGRAM_FLASH_SIZE "Taille Flash Programme"
#define D_PROGRAM_SIZE "Taille programme"
#define D_PROJECT "Projet"
#define D_RAIN "Pluie"
#define D_RANGE "Intervalle"
#define D_RECEIVED "Reçu"
#define D_RESTART "Redémarrage"
#define D_RESTARTING "Redémarre"
#define D_RESTART_REASON "Raison du redémarrage"
#define D_RESTORE "restaurer"
#define D_RETAINED "persistant"		// MQTT
#define D_RULE "Règle"
#define D_SAVE "Enregistrer"
#define D_SENSOR "Capteur"
#define D_SSID "SSID"
#define D_START "Lancer"	 // "Lancer la mise à jour"
#define D_STD_TIME "STD"
#define D_STOP "Stop"
#define D_SUBNET_MASK "Masque sous-réseau"
#define D_SUBSCRIBE_TO "S'abonner à"
#define D_UNSUBSCRIBE_FROM "Se désabonner de"
#define D_SUCCESSFUL "Réussi"
#define D_SUNRISE "Lever du jour"
#define D_SUNSET "Tombée de la nuit"
#define D_TEMPERATURE "Température"
#define D_TO "à"
#define D_TOGGLE "Inverser"
#define D_TOPIC "Topic"      // Keep MQTT keyword
#define D_TOTAL_USAGE "Eau totale"
#define D_TRANSMIT "Transmettre"
#define D_TRUE "Vrai"
#define D_TVOC "TVOC"
#define D_UPGRADE "la mise à jour" 	 // "Lancer la mise à jour"
#define D_UPLOAD "Upload"    // Not better in french
#define D_UPTIME "Durée d'activité"
#define D_USER "Utilisateur"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "Indice UV"
#define D_UV_INDEX_1 "Faible"
#define D_UV_INDEX_2 "Modéré"
#define D_UV_INDEX_3 "Élevé"
#define D_UV_INDEX_4 "Très élevé"
#define D_UV_INDEX_5 "Brûlure niv.1/2"
#define D_UV_INDEX_6 "Brûlure niv.3"
#define D_UV_INDEX_7 "Hors échelle"
#define D_UV_LEVEL "Niveau UV"
#define D_UV_POWER "Puissance UV"
#define D_VERSION "Version"
#define D_VOLTAGE "Tension"
#define D_VOLUME "Volume"
#define D_WEIGHT "Poids"
#define D_WARMLIGHT "Chaud"
#define D_WEB_SERVER "Serveur web"

// tasmota.ino
#define D_WARNING_MINIMAL_VERSION "ATTENTION Cette version ne supporte pas les réglages persistants"
#define D_LEVEL_10 "niveau 1-0"
#define D_LEVEL_01 "niveau 0-1"
#define D_SERIAL_LOGGING_DISABLED "Journalisation série désactivée"
#define D_SYSLOG_LOGGING_REENABLED "Jounalisation SysLog réactivée"

#define D_SET_BAUDRATE_TO "Définir le débit à"
#define D_RECEIVED_TOPIC "Topic reçu"  // Terme MQTT
#define D_DATA_SIZE "Taille données"
#define D_ANALOG_INPUT "Analogique"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Boucle bloquée"
#define D_WPS_FAILED_WITH_STATUS "WPSconfig ÉCHOUÉ avec status"
#define D_ACTIVE_FOR_3_MINUTES "actif pour 3 minutes"
#define D_FAILED_TO_START "Échec de démarrage"
#define D_PATCH_ISSUE_2186 "Correctif 2186"
#define D_CONNECTING_TO_AP "Connexion à l'AP"
#define D_IN_MODE "en mode"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "Échec de connexion car aucune adresse IP n'a été reçue"
#define D_CONNECT_FAILED_AP_NOT_REACHED "Échec de connexion car l'AP ne peut-être contacté"
#define D_CONNECT_FAILED_WRONG_PASSWORD "Échec de connexion"
#define D_CONNECT_FAILED_AP_TIMEOUT "Échec de connexion avec l'AP, expiré"
#define D_ATTEMPTING_CONNECTION "Tentative de connexion..."
#define D_CHECKING_CONNECTION "Vérification connexion..."
#define D_QUERY_DONE "Requête terminée. Services MQTT trouvés"
#define D_MQTT_SERVICE_FOUND "Service MQTT trouvé sur"
#define D_FOUND_AT "trouvé à"
#define D_SYSLOG_HOST_NOT_FOUND "Hôte SysLog introuvable"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Enregistré en flash à"
#define D_LOADED_FROM_FLASH_AT "Chargé de la flash à"
#define D_USE_DEFAULTS "Utiliser par défaut"
#define D_ERASED_SECTOR "Secteur effacé"

// xdrv_02_webserver.ino
#define D_NOSCRIPT "Pour utiliser Tasmota, veuillez activer JavaScript"
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "Firmware MINIMAL<br>merci de mettre à jour"
#define D_WEBSERVER_ACTIVE_ON "Serveur web actif sur"
#define D_WITH_IP_ADDRESS "avec l'adresse IP"
#define D_WEBSERVER_STOPPED "Serveur web éteint"
#define D_FILE_NOT_FOUND "Fichier introuvable"
#define D_REDIRECTED "Redirection sur le portail captif"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifimanager en mode Point d'Accès et Station"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifimanager en mode Point d'Accès"
#define D_TRYING_TO_CONNECT "Tentative de connexion du module au réseau"

#define D_RESTART_IN "Redémarrage dans"
#define D_SECONDS "secondes"
#define D_DEVICE_WILL_RESTART "Le module va redémarrer dans quelques secondes"
#define D_BUTTON_TOGGLE "on/off"
#define D_CONFIGURATION "Configuration"
#define D_INFORMATION "Informations"
#define D_FIRMWARE_UPGRADE "Mise à jour du Firmware"
#define D_CONSOLE "Console"
#define D_CONFIRM_RESTART "Confirmer redémarrage"

#define D_CONFIGURE_MODULE "Configuration du Module"
#define D_CONFIGURE_WIFI "Configuration WiFi"
#define D_CONFIGURE_MQTT "Configuration MQTT"
#define D_CONFIGURE_DOMOTICZ "Configuration Domoticz"
#define D_CONFIGURE_LOGGING "Configuration du journal"
#define D_CONFIGURE_OTHER "Autre configuration"
#define D_CONFIRM_RESET_CONFIGURATION "Confirmer la réinit. de la config."
#define D_RESET_CONFIGURATION "Configuration par défaut"
#define D_BACKUP_CONFIGURATION "Sauvegarde de la config."
#define D_RESTORE_CONFIGURATION "Restauration de la config."
#define D_MAIN_MENU "Menu principal"

#define D_MODULE_PARAMETERS "Paramètres module"
#define D_MODULE_TYPE "Type de module"
#define D_PULLUP_ENABLE "Inter. sans pull-up"
#define D_ADC "ADC"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Entrée série"
#define D_SERIAL_OUT "Sortie série"

#define D_WIFI_PARAMETERS "Paramètres Wifi"
#define D_SCAN_FOR_WIFI_NETWORKS "Scan des réseaux wifi"
#define D_SCAN_DONE "Scan terminé"
#define D_NO_NETWORKS_FOUND "Aucun réseau trouvé"
#define D_REFRESH_TO_SCAN_AGAIN "Rafraîchir pour scanner à nouveau"
#define D_DUPLICATE_ACCESSPOINT "Point d'Accès dupliqué"
#define D_SKIPPING_LOW_QUALITY "Évité car de mauvaise qualité"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "AP1 SSID"
#define D_AP1_PASSWORD "Mot de passe AP1"
#define D_AP2_SSID "AP2 SSId"
#define D_AP2_PASSWORD "Mot de passe AP2"

#define D_MQTT_PARAMETERS "Paramètres MQTT"
#define D_CLIENT "Client"
#define D_FULL_TOPIC "Topic complet"

#define D_LOGGING_PARAMETERS "Paramètres du journal"
#define D_SERIAL_LOG_LEVEL "Niveau de journalisation série"
#define D_MQTT_LOG_LEVEL "Niveau de journalisation MQTT"
#define D_WEB_LOG_LEVEL "Niveau de journalisation web"
#define D_SYS_LOG_LEVEL "Niveau SysLog"
#define D_MORE_DEBUG "Plus de debug"
#define D_SYSLOG_HOST "Hôte SysLog"
#define D_SYSLOG_PORT "Port SysLog"
#define D_TELEMETRY_PERIOD "Période télémétrie"

#define D_OTHER_PARAMETERS "Autres paramètres"
#define D_TEMPLATE "Modèle"
#define D_ACTIVATE "Activer"
#define D_DEVICE_NAME "Nom de l'appareil"
#define D_WEB_ADMIN_PASSWORD "Mot de passe Web Admin"
#define D_MQTT_ENABLE "MQTT activé"
#define D_MQTT_TLS_ENABLE "MQTT TLS"
#define D_FRIENDLY_NAME "Surnom"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "module unique"
#define D_MULTI_DEVICE "multi module"

#define D_CONFIGURE_TEMPLATE "Configuration du modèle"
#define D_TEMPLATE_PARAMETERS "Paramètres du modèle"
#define D_TEMPLATE_NAME "Nom"
#define D_BASE_TYPE "Basé sur"
#define D_TEMPLATE_FLAGS "Options"

#define D_SAVE_CONFIGURATION "Enregistrer la configuration"
#define D_CONFIGURATION_SAVED "Configuration enregistrée"
#define D_CONFIGURATION_RESET "Configuration réinitialisée"

#define D_PROGRAM_VERSION "Version du programme"
#define D_BUILD_DATE_AND_TIME "Date & Heure de build"
#define D_CORE_AND_SDK_VERSION "Version Core/SDK"
#define D_FLASH_WRITE_COUNT "Compteur écriture flash"
#define D_MAC_ADDRESS "Adresse MAC"
#define D_MQTT_HOST "Hôte MQTT"
#define D_MQTT_PORT "Port MQTT"
#define D_MQTT_CLIENT "Client MQTT"
#define D_MQTT_USER "Utilisateur MQTT"
#define D_MQTT_TOPIC "Topic MQTT"
#define D_MQTT_GROUP_TOPIC "Groupe topic MQTT"
#define D_MQTT_FULL_TOPIC "Topic complet MQTT"
#define D_MQTT_NO_RETAIN "MQTT No Retain"
#define D_MDNS_DISCOVERY "Découverte mDNS"
#define D_MDNS_ADVERTISE "Annonce mDNS"
#define D_ESP_CHIP_ID "ESP Chip Id"
#define D_FLASH_CHIP_ID "Flash Chip Id"
#define D_FLASH_CHIP_SIZE "Taille flash"
#define D_FREE_PROGRAM_SPACE "Espace programme libre"

#define D_UPGRADE_BY_WEBSERVER "Mise à jour par serveur web"
#define D_OTA_URL "URL OTA"
#define D_START_UPGRADE "Lancer la mise à jour"
#define D_UPGRADE_BY_FILE_UPLOAD "Mise à jour par téléchargement fichier"
#define D_UPLOAD_STARTED "Téléchargement lancé"
#define D_UPGRADE_STARTED "Mise à jour lancée"
#define D_UPLOAD_DONE "Téléchargement terminé"
#define D_UPLOAD_TRANSFER "Transfert ZigBee"
#define D_TRANSFER_STARTED "Transfert lancé"
#define D_UPLOAD_ERR_1 "Aucun fichier sélectionné"
#define D_UPLOAD_ERR_2 "Espace insuffisant"
#define D_UPLOAD_ERR_3 "Invalid file signature"
#define D_UPLOAD_ERR_4 "La taille du programme à flasher est plus grande que la taille réelle de la mémoire flash"
#define D_UPLOAD_ERR_5 "Erreur de comparaison du buffer de téléchargement"
#define D_UPLOAD_ERR_6 "Téléchargement échoué. Activer WebLog 3"
#define D_UPLOAD_ERR_7 "Téléchargement annulé"
#define D_UPLOAD_ERR_8 "Fichier invalide"
#define D_UPLOAD_ERR_9 "Fichier trop grand"
#define D_UPLOAD_ERR_10 "Erreur d'initialisation du chip RF"
#define D_UPLOAD_ERR_11 "Erreur d'effacement du chip RF"
#define D_UPLOAD_ERR_12 "Erreur d'accès en écriture au chip RF"
#define D_UPLOAD_ERR_13 "Erreur de décodage du firmware RF"
#define D_UPLOAD_ERR_14 "Incompatible"
#define D_UPLOAD_ERROR_CODE "Code d'erreur téléchargement"

#define D_ENTER_COMMAND "Saisir une commande"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Activer WebLog 2 si une réponse est attendue"
#define D_NEED_USER_AND_PASSWORD "Nécessite utilisateur=<username>&mot-de-passe=<password>"

// xdrv_01_mqtt.ino
#define D_FINGERPRINT "Vérification d'empreinte TLS ..."
#define D_TLS_CONNECT_FAILED_TO "Échec de connexion TLS à"
#define D_RETRY_IN "Nouvelle tentative dans"
#define D_VERIFIED "Vérifié par empreinte "
#define D_INSECURE "Connexion non sécurisée car empreinte non vérifiée"
#define D_CONNECT_FAILED_TO "Échec de connexion à"

// xplg_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast désactivé"
#define D_MULTICAST_REJOINED "Multicast (re)joint"
#define D_MULTICAST_JOIN_FAILED "Multicast échec abonnement"
#define D_FAILED_TO_SEND_RESPONSE "Échec d'envoi réponse"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo basic event"
#define D_WEMO_EVENT_SERVICE "WeMo event service"
#define D_WEMO_META_SERVICE "WeMo meta service"
#define D_WEMO_SETUP "Réglage WeMo"
#define D_RESPONSE_SENT "Réponse envoyée"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Réglage Hue"
#define D_HUE_API_NOT_IMPLEMENTED "API Hue non implémentée"
#define D_HUE_API "Hue API"
#define D_HUE_POST_ARGS "Hue POST args"
#define D_3_RESPONSE_PACKETS_SENT "3 paquets de réponse envoyés"

// xdrv_07_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Paramètres Domoticz"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Key idx"
#define D_DOMOTICZ_SWITCH_IDX "Switch idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Hum"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Hum,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Puissance,Énergie"
  #define D_DOMOTICZ_ILLUMINANCE "Éclairement"
  #define D_DOMOTICZ_COUNT "Compteur/PM1"
  #define D_DOMOTICZ_VOLTAGE "Tension/PM2,5"
  #define D_DOMOTICZ_CURRENT "Courant/PM10"
  #define D_DOMOTICZ_AIRQUALITY "Qualité de l'air"
  #define D_DOMOTICZ_P1_SMART_METER "P1SmartMeter"
#define D_DOMOTICZ_UPDATE_TIMER "Durée de rafraichissement"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Configuration des Timers"
#define D_TIMER_PARAMETERS "Paramètres Timer"
#define D_TIMER_ENABLE "Activer les Timers"
#define D_TIMER_ARM "Armer"
#define D_TIMER_TIME "Temps"
#define D_TIMER_DAYS "Jours"
#define D_TIMER_REPEAT "Répéter"
#define D_TIMER_OUTPUT "Sortie"
#define D_TIMER_ACTION "Action"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Configuration de KNX"
#define D_KNX_PARAMETERS "Paramètres KNX"
#define D_KNX_GENERAL_CONFIG "Général"
#define D_KNX_PHYSICAL_ADDRESS "Adresse individuelle"				// Backbone/Line/Device -> Zone/Ligne/Participant
#define D_KNX_PHYSICAL_ADDRESS_NOTE "(Doit être unique sur le réseau KNX)"
#define D_KNX_ENABLE "Activer KNX"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Données à envoyer aux Adresses de Groupe"
#define D_ADD "Ajoûter"
#define D_DELETE "Supprimer"
#define D_REPLY "Répondre"
#define D_KNX_GROUP_ADDRESS_TO_READ "Données à recevoir des Adresses de Groupe"
#define D_RECEIVED_FROM "Reçu de"
#define D_KNX_COMMAND_WRITE "Écrire"
#define D_KNX_COMMAND_READ "Lire"
#define D_KNX_COMMAND_OTHER "Autre"
#define D_SENT_TO "envoyé à"
#define D_KNX_WARNING "L'Adresse de Groupe (0/0/0) est réservée et ne peut être utilisée."
#define D_KNX_ENHANCEMENT "Amélioration de la communication"
#define D_KNX_TX_SLOT "KNX TX"
#define D_KNX_RX_SLOT "KNX RX"
#define D_KNX_TX_SCENE "KNX Scène TX"
#define D_KNX_RX_SCENE "KNX Scène RX"

// xdrv_23_zigbee
#define D_ZIGBEE_PERMITJOIN_ACTIVE "Modules autorisés à s'associer"
#define D_ZIGBEE_MAPPING_TITLE "Cartographie Tasmota Zigbee"
#define D_ZIGBEE_NOT_STARTED "Zigbee non démarré"
#define D_ZIGBEE_MAPPING_IN_PROGRESS_SEC "Cartographie en cours (%d s. restant)"
#define D_ZIGBEE_MAPPING_NOT_PRESENT "Pas de cartographie"
#define D_ZIGBEE_MAP_REFRESH "MàJ de la carto Zigbee"
#define D_ZIGBEE_MAP   "Carto Zigbee"
#define D_ZIGBEE_PERMITJOIN "Association Zigbee autorisée"
#define D_ZIGBEE_GENERATE_KEY "création d'une clé réseau ZigBee aléatoire"
#define D_ZIGBEE_UNKNOWN_DEVICE "Module inconnu"
#define D_ZIGBEE_UNKNOWN_ATTRIBUTE "Attribut inconnu"
#define D_ZIGBEE_INVALID_PARAM "Paramètre invalide"
#define D_ZIGBEE_MISSING_PARAM "Paramètres manquants"
#define D_ZIGBEE_UNKNWON_ATTRIBUTE "Nom d'attribut inconnu (ignoré): %s"
#define D_ZIGBEE_TOO_MANY_CLUSTERS "Pas plus d'un Id de Cluster par commande"
#define D_ZIGBEE_WRONG_DELIMITER "Mauvais délimiteur dans le contenu du message"
#define D_ZIGBEE_UNRECOGNIZED_COMMAND "Commande ZigBee inconnue: %s"
#define D_ZIGBEE_TOO_MANY_COMMANDS "Une seule commande autorisée (%d)"
#define D_ZIGBEE_NO_ATTRIBUTE "Liste sans attribut"
#define D_ZIGBEE_UNSUPPORTED_ATTRIBUTE_TYPE "Type d'attribut non supporté"
#define D_ZIGBEE_JSON_REQUIRED "Objets JSON requis par la config"
#define D_ZIGBEE_RESET_1_OR_2 "Réinitialiser 1 ou 2"
#define D_ZIGBEE_EEPROM_FOUND_AT_ADDRESS "EEPROM ZBBridge trouvée à l'adresse"
#define D_ZIGBEE_RANDOMIZING_ZBCONFIG "Randomisation des paramètres ZigBee, veuillez vérifier avec 'ZbConfig'"

// xsns_03_energy.ino
#define D_ENERGY_TODAY "Énergie aujourd'hui"
#define D_ENERGY_YESTERDAY "Énergie hier"
#define D_ENERGY_TOTAL "Énergie totale"

// xdrv_27_shutter.ino
#define D_OPEN "Ouvert"
#define D_CLOSE "Fermé"
#define D_DOMOTICZ_SHUTTER "Volet"

// xdrv_28_pcf8574.ino
#define D_CONFIGURE_PCF8574 "Configurer PCF8574"
#define D_PCF8574_PARAMETERS "Paramètres PCF8574"
#define D_INVERT_PORTS "Inverser les Ports"
#define D_DEVICE "Module"
#define D_DEVICE_INPUT "Entrée"
#define D_DEVICE_OUTPUT "Sortie"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Capteur occupé"
#define D_SENSOR_CRC_ERROR "Erreur CRC capteur"
#define D_SENSORS_FOUND "Capteur trouvé"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Expiration du délai"
#define D_START_SIGNAL_LOW "Signal Start bas"
#define D_START_SIGNAL_HIGH "Signal Start haut"
#define D_PULSE "Impulsion"
#define D_CHECKSUM_FAILURE "Erreur checksum"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Le capteur n'a pas acquitté la commande"
#define D_SHT1X_FOUND "SHT1X trouvé"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Particules"

// xsns_27_apds9960.ino
#define D_GESTURE "Geste"
#define D_COLOR_RED "Rouge"
#define D_COLOR_GREEN "Vert"
#define D_COLOR_BLUE "Bleu"
#define D_CCT "CCT"
#define D_PROXIMITY "Proximité"

// xsns_32_mpu6050.ino
#define D_AX_AXIS "Accél. Axe-X"
#define D_AY_AXIS "Accél. Axe-Y"
#define D_AZ_AXIS "Accél. Axe-Z"
#define D_GX_AXIS "Gyro Axe-X"
#define D_GY_AXIS "Gyro Axe-Y"
#define D_GZ_AXIS "Gyro Axe-Z"

// xsns_34_hx711.ino
#define D_HX_CAL_REMOVE "Retirer la charge"
#define D_HX_CAL_REFERENCE "Charger l'étalon de poids"
#define D_HX_CAL_DONE "Étalonné"
#define D_HX_CAL_FAIL "L'étalonnage a échoué"
#define D_RESET_HX711 "Réinitialiser le capteur"
#define D_CONFIGURE_HX711 "Configurer le capteur"
#define D_HX711_PARAMETERS "Paramètres capteur"
#define D_ITEM_WEIGHT "Poids de l'objet"
#define D_REFERENCE_WEIGHT "Poids de référence"
#define D_CALIBRATE "Étalonner"
#define D_CALIBRATION "Étalonnage"

// xsns_35_TX20.ino
#define D_TX20_WIND_DIRECTION "Direction du vent"
#define D_TX20_WIND_SPEED "Vitesse du vent"
#define D_TX20_WIND_SPEED_MIN "Vitesse Min"
#define D_TX20_WIND_SPEED_MAX "Vitesse Max"
#define D_TX20_NORTH "N"
#define D_TX20_EAST "E"
#define D_TX20_SOUTH "S"
#define D_TX20_WEST "O"

// xsns_53_sml.ino
#define D_TPWRIN "Energie totale Entrée"
#define D_TPWROUT "Energie totale Sortie"
#define D_TPWRCURR "Puissance active E/S"
#define D_TPWRCURR1 "Puissance active Ent Ph1"
#define D_TPWRCURR2 "Puissance active Ent Ph2"
#define D_TPWRCURR3 "Puissance active Ent Ph3"
#define D_Strom_L1 "Courant Ph1"
#define D_Strom_L2 "Courant Ph2"
#define D_Strom_L3 "Courant Ph3"
#define D_Spannung_L1 "Tension Ph1"
#define D_Spannung_L2 "Tension Ph2"
#define D_Spannung_L3 "Tension Ph3"
#define D_METERNR "Numéro compteur"
#define D_METERSID "Service ID"
#define D_GasIN "Compteur Gaz"
#define D_H2oIN "Compteur Eau"
#define D_StL1L2L3 "Courant Ph1+Ph2+Ph3"
#define D_SpL1L2L3 "Tension (Ph1+Ph2+Ph3)/3"

// tasmota_template.h - keep them as short as possible to be able to fit them in GUI drop down box
#define D_SENSOR_NONE          "Aucun"
#define D_SENSOR_USER          "Utilisateur"
#define D_SENSOR_OPTION        "Option"
#define D_SENSOR_DHT11         "DHT11"
#define D_SENSOR_AM2301        "AM2301"
#define D_SENSOR_SI7021        "SI7021"
#define D_SENSOR_DS18X20       "DS18x20"
#define D_SENSOR_I2C_SCL       "I2C SCL"
#define D_SENSOR_I2C_SDA       "I2C SDA"
#define D_SENSOR_WS2812        "WS2812"
#define D_SENSOR_DFR562        "MP3 Player"
#define D_SENSOR_IRSEND        "IR TX"
#define D_SENSOR_SWITCH        "Inter."     // Suffix "1"
#define D_SENSOR_BUTTON        "Bouton"     // Suffix "1"
#define D_SENSOR_RELAY         "Relais"     // Suffix "1i"
#define D_SENSOR_LED           "LED"        // Suffix "1i"
#define D_SENSOR_LED_LINK      "LedLink"    // Suffix "i"
#define D_SENSOR_PWM           "PWM"        // Suffix "1"
#define D_SENSOR_COUNTER       "Compteur"   // Suffix "1"
#define D_SENSOR_IRRECV        "IR RX"
#define D_SENSOR_MHZ_RX        "MHZ RX"
#define D_SENSOR_MHZ_TX        "MHZ TX"
#define D_SENSOR_PZEM004_RX    "PZEM004 RX"
#define D_SENSOR_PZEM016_RX    "PZEM016 RX"
#define D_SENSOR_PZEM017_RX    "PZEM017 RX"
#define D_SENSOR_PZEM0XX_TX    "PZEM0XX TX"
#define D_SENSOR_SAIR_RX       "SAir RX"
#define D_SENSOR_SAIR_TX       "SAir TX"
#define D_SENSOR_SPI_CS        "SPI CS"
#define D_SENSOR_SPI_DC        "SPI DC"
#define D_SENSOR_SPI_MISO      "SPI MISO"
#define D_SENSOR_SPI_MOSI      "SPI MOSI"
#define D_SENSOR_SPI_CLK       "SPI CLK"
#define D_SENSOR_BACKLIGHT     "RétroÉcl"
#define D_SENSOR_PMS5003_TX    "PMS5003 Tx"
#define D_SENSOR_PMS5003_RX    "PMS5003 Rx"
#define D_SENSOR_SDS0X1_RX     "SDS0X1 RX"
#define D_SENSOR_SDS0X1_TX     "SDS0X1 TX"
#define D_SENSOR_HPMA_RX       "HPMA RX"
#define D_SENSOR_HPMA_TX       "HPMA TX"
#define D_SENSOR_SBR_RX        "SerBr RX"
#define D_SENSOR_SBR_TX        "SerBr TX"
#define D_SENSOR_SR04_TRIG     "SR04 Tri/TX"
#define D_SENSOR_SR04_ECHO     "SR04 Ech/RX"
#define D_SENSOR_SDM120_TX     "SDMx20 TX"
#define D_SENSOR_SDM120_RX     "SDMx20 RX"
#define D_SENSOR_SDM630_TX     "SDM630 TX"
#define D_SENSOR_SDM630_RX     "SDM630 RX"
#define D_SENSOR_WE517_TX      "WE517 Tx"
#define D_SENSOR_WE517_RX      "WE517 Rx"
#define D_SENSOR_TM1638_CLK    "TM16 CLK"
#define D_SENSOR_TM1638_DIO    "TM16 DIO"
#define D_SENSOR_TM1638_STB    "TM16 STB"
#define D_SENSOR_HX711_SCK     "HX711 SCK"
#define D_SENSOR_HX711_DAT     "HX711 DAT"
#define D_SENSOR_FTC532        "FTC532"
#define D_SENSOR_TX2X_TX       "TX2x"
#define D_SENSOR_RFSEND        "RF TX"
#define D_SENSOR_RFRECV        "RF RX"
#define D_SENSOR_TUYA_TX       "Tuya TX"
#define D_SENSOR_TUYA_RX       "Tuya RX"
#define D_SENSOR_MGC3130_XFER  "MGC3130 Xfr"
#define D_SENSOR_MGC3130_RESET "MGC3130 Rst"
#define D_SENSOR_SSPI_MISO     "SSPI MISO"
#define D_SENSOR_SSPI_MOSI     "SSPI MOSI"
#define D_SENSOR_SSPI_SCLK     "SSPI SCLK"
#define D_SENSOR_SSPI_CS       "SSPI CS"
#define D_SENSOR_SSPI_DC       "SSPI DC"
#define D_SENSOR_RF_SENSOR     "RF Sensor"
#define D_SENSOR_AZ_RX         "AZ RX"
#define D_SENSOR_AZ_TX         "AZ TX"
#define D_SENSOR_MAX31855_CS   "MX31855 CS"
#define D_SENSOR_MAX31855_CLK  "MX31855 CLK"
#define D_SENSOR_MAX31855_DO   "MX31855 DO"
#define D_SENSOR_MAX31865_CS   "MX31865 CS"
#define D_SENSOR_NRG_SEL       "HLWBL SEL"  // Suffix "i"
#define D_SENSOR_NRG_CF1       "HLWBL CF1"
#define D_SENSOR_HLW_CF        "HLW8012 CF"
#define D_SENSOR_HJL_CF        "BL0937 CF"
#define D_SENSOR_MCP39F5_TX    "MCP39F5 TX"
#define D_SENSOR_MCP39F5_RX    "MCP39F5 RX"
#define D_SENSOR_MCP39F5_RST   "MCP39F5 Rst"
#define D_SENSOR_CSE7766_TX    "CSE7766 TX"
#define D_SENSOR_CSE7766_RX    "CSE7766 RX"
#define D_SENSOR_PN532_TX      "PN532 TX"
#define D_SENSOR_PN532_RX      "PN532 RX"
#define D_SENSOR_SM16716_CLK   "SM16716 CLK"
#define D_SENSOR_SM16716_DAT   "SM16716 DAT"
#define D_SENSOR_SM16716_POWER "SM16716 PWR"
#define D_SENSOR_P9813_CLK     "P9813 Clk"
#define D_SENSOR_P9813_DAT     "P9813 Dat"
#define D_SENSOR_MY92X1_DI     "MY92x1 DI"
#define D_SENSOR_MY92X1_DCKI   "MY92x1 DCKI"
#define D_SENSOR_ARIRFRCV      "ALux IrRcv"
#define D_SENSOR_ARIRFSEL      "ALux IrSel"
#define D_SENSOR_TXD           "Série TX"
#define D_SENSOR_RXD           "Série RX"
#define D_SENSOR_ROTARY        "Rotary"     // Suffix "1A"
#define D_SENSOR_HRE_CLOCK     "HRE Clock"
#define D_SENSOR_HRE_DATA      "HRE Data"
#define D_SENSOR_ADE7953_IRQ   "ADE7953 IRQ"
#define D_SENSOR_BUZZER        "Buzzer"
#define D_SENSOR_OLED_RESET    "OLED Reset"
#define D_SENSOR_ZIGBEE_TXD    "Zigbee TX"
#define D_SENSOR_ZIGBEE_RXD    "Zigbee RX"
#define D_SENSOR_ZIGBEE_RST    "Zigbee Rst"
#define D_SENSOR_SOLAXX1_TX    "SolaxX1 TX"
#define D_SENSOR_SOLAXX1_RX    "SolaxX1 RX"
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
#define D_SENSOR_DDS2382_TX    "DDS238-2 TX"
#define D_SENSOR_DDS2382_RX    "DDS238-2 RX"
#define D_SENSOR_DDSU666_TX    "DDSU666 TX"
#define D_SENSOR_DDSU666_RX    "DDSU666 RX"
#define D_SENSOR_SM2135_CLK    "SM2135 Clk"
#define D_SENSOR_SM2135_DAT    "SM2135 Dat"
#define D_SENSOR_DEEPSLEEP     "Hibernation"
#define D_SENSOR_EXS_ENABLE    "EXS Enable"
#define D_SENSOR_CLIENT_TX      "Esclave TX"
#define D_SENSOR_CLIENT_RX      "Esclave RX"
#define D_SENSOR_CLIENT_RESET   "Esclave Rst"
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
#define D_SENSOR_WINDMETER_SPEED "Anémomètre"
#define D_SENSOR_TELEINFO_RX   "TInfo Rx"
#define D_SENSOR_TELEINFO_ENABLE "TInfo En"
#define D_SENSOR_LMT01_PULSE   "LMT01 Impulsion"
#define D_SENSOR_ADC_INPUT     "ADC Entrée"
#define D_SENSOR_ADC_TEMP      "ADC Temp"
#define D_SENSOR_ADC_LIGHT     "ADC Lumière"
#define D_SENSOR_ADC_BUTTON    "ADC Bouton"
#define D_SENSOR_ADC_RANGE     "ADC Distance"
#define D_SENSOR_ADC_CT_POWER  "ADC CT Power"
#define D_SENSOR_ADC_JOYSTICK  "ADC Manette"
#define D_SENSOR_ADC_PH        "ADC pH"
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
#define D_SENSOR_SDCARD_CS     "CarteSD CS"

// Units
#define D_UNIT_AMPERE "A"
#define D_UNIT_CELSIUS "C"
#define D_UNIT_CENTIMETER "cm"
#define D_UNIT_DEGREE "°"
#define D_UNIT_FAHRENHEIT "F"
#define D_UNIT_HERTZ "Hz"
#define D_UNIT_HOUR "h"
#define D_UNIT_GALLONS "gal"
#define D_UNIT_GALLONS_PER_MIN "gal/mn"
#define D_UNIT_INCREMENTS "inc"
#define D_UNIT_KELVIN "K"
#define D_UNIT_KILOMETER "km"
#define D_UNIT_KILOGRAM "kg"
#define D_UNIT_KILOMETER_PER_HOUR "km/h"
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
#define D_UNIT_MINUTE "min"  // https://fr.wikipedia.org/wiki/Minute_(temps)#Symbole%20et%20d%C3%A9finition
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PERCENT "%%"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "s"
#define D_UNIT_SECTORS "secteurs"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "Wh"
#define D_UNIT_WATT_METER_QUADRAT "W/m²"
//SDM220, SDM120, LE01MR
#define D_PHASE_ANGLE     "Angle de phase"
#define D_IMPORT_ACTIVE   "Énergie act conso"
#define D_EXPORT_ACTIVE   "Énergie act fournie"
#define D_IMPORT_REACTIVE "Énergie réa conso"
#define D_EXPORT_REACTIVE "Énergie réa fournie"
#define D_TOTAL_REACTIVE  "Énergie réa totale"
#define D_UNIT_KWARH      "kVArh"
#define D_UNIT_ANGLE      "°"
#define D_TOTAL_ACTIVE    "Total Active"
//SOLAXX1
#define D_PV1_VOLTAGE     "Tension PV1"
#define D_PV1_CURRENT     "Courant PV1"
#define D_PV1_POWER       "Puissance PV1"
#define D_PV2_VOLTAGE     "Tension PV2"
#define D_PV2_CURRENT     "Courant PV2"
#define D_PV2_POWER       "Puissance PV2"
#define D_SOLAR_POWER     "Puissance solaire"
#define D_INVERTER_POWER  "Puissance onduleur"
#define D_STATUS          "Statut"
#define D_WAITING         "En attente"
#define D_CHECKING        "En test"
#define D_WORKING         "En marche"
#define D_FAILURE         "Défault"
#define D_SOLAX_ERROR_0   "Aucun code d'erreur"
#define D_SOLAX_ERROR_1   "Défaut Perte de réseau"
#define D_SOLAX_ERROR_2   "Défaut Tension réseau"
#define D_SOLAX_ERROR_3   "Défaut Fréquence réseau"
#define D_SOLAX_ERROR_4   "Défaut Tension PV"
#define D_SOLAX_ERROR_5   "Défaut Isolation"
#define D_SOLAX_ERROR_6   "Défaut Surchauffe"
#define D_SOLAX_ERROR_7   "Défaut Ventilateur"
#define D_SOLAX_ERROR_8   "Défaut Autre équipement"

//xdrv_10_scripter.ino
#define D_CONFIGURE_SCRIPT     "Éditer le script"
#define D_SCRIPT               "édition du script"
#define D_SDCARD_UPLOAD        "Envoi du fichier"
#define D_UFSDIR               "Dossier UFS"
#define D_UPL_DONE             "Terminé"
#define D_SCRIPT_CHARS_LEFT    "car. restant"
#define D_SCRIPT_CHARS_NO_MORE "plus de car."
#define D_SCRIPT_DOWNLOAD      "Download"
#define D_SCRIPT_ENABLE        "script actif"
#define D_SCRIPT_UPLOAD        "Envoi"
#define D_SCRIPT_UPLOAD_FILES  "Envoi de fichiers"

//xdrv_50_filesystem.ino
#define D_MANAGE_FILE_SYSTEM   "Gestion du Système de Fichier"
#define D_FS_SIZE              "Taille"
#define D_FS_FREE              "Libre"

//xsns_67_as3935.ino
#define D_AS3935_GAIN "gain:"
#define D_AS3935_ENERGY "energie:"
#define D_AS3935_DISTANCE "distance:"
#define D_AS3935_DISTURBER "interférence:"
#define D_AS3935_VRMS "µVrms:"
#define D_AS3935_APRX "approx.:"
#define D_AS3935_AWAY "de distance"
#define D_AS3935_LIGHT "éclair"
#define D_AS3935_OUT "éclair éloigné"
#define D_AS3935_NOT "distance indéterminée"
#define D_AS3935_ABOVE "éclair trop intense"
#define D_AS3935_NOISE "bruit détecté"
#define D_AS3935_DISTDET "interférence détectée"
#define D_AS3935_INTNOEV "Interruption sans évenement!"
#define D_AS3935_FLICKER "IRQ flicker!"
#define D_AS3935_POWEROFF "Power Off"
#define D_AS3935_NOMESS "en écoute..."
#define D_AS3935_ON "Actif"
#define D_AS3935_OFF "Inactif"
#define D_AS3935_INDOORS "Intérieur"
#define D_AS3935_OUTDOORS "Extérieur"
#define D_AS3935_CAL_FAIL "défaut de calibration"
#define D_AS3935_CAL_OK "calibration établie à :"

//xsns_68_opentherm.ino
#define D_SENSOR_BOILER_OT_RX   "OpenTherm RX"
#define D_SENSOR_BOILER_OT_TX   "OpenTherm TX"

// xnrg_15_teleinfo Denky (Teleinfo)
#define D_CONTRACT        "Type contrat"
#define D_POWER_LOAD      "Charge actuelle"
#define D_CURRENT_TARIFF  "Tarif en cours"
#define D_TARIFF          "Tarif"
#define D_OVERLOAD        "ADPS"
#define D_MAX_POWER       "Puissance max"
#define D_MAX_CURRENT     "Courant max"

// xsns_79_as608.ino
#define D_FP_ENROLL_PLACEFINGER "Placer un doigt"
#define D_FP_ENROLL_REMOVEFINGER "Retirer le doigt"
#define D_FP_ENROLL_PLACESAMEFINGER "Replacer le même doigt"
#define D_FP_ENROLL_RETRY "Erreur, rééssayer"
#define D_FP_ENROLL_RESTART "Redémarrer"
#define D_FP_ENROLL_ERROR "Erreur"
#define D_FP_ENROLL_RESET "Réinitialiser"
#define D_FP_ENROLL_ACTIVE "Actif"
#define D_FP_ENROLL_INACTIVE "Inactif"
// Indexed by Adafruit_Fingerprint.h defines
#define D_FP_PACKETRECIEVEERR "Erreur de com." // 0x01 Error when receiving data package
#define D_FP_NOFINGER ""                       // 0x02 No finger on the sensor
#define D_FP_IMAGEFAIL "Erreur d'acquisition"  // 0x03 Failed to enroll the finger
#define D_FP_IMAGEMESS "Empreinte incohérante" // 0x06 Failed to generate character file due to overly disorderly fingerprint image
#define D_FP_FEATUREFAIL "Empreinte trop petite" // 0x07 Failed to generate character file due to the lack of character point or small fingerprint image
#define D_FP_NOMATCH "Le doigt ne correspond pas" // 0x08 Finger doesn't match
#define D_FP_NOTFOUND "Pas de doigt correspondant" // 0x09 Failed to find matching finger
#define D_FP_ENROLLMISMATCH "Echec de la comparaison" // 0x0A Failed to combine the character files
#define D_FP_BADLOCATION "Erreur d'indexation" // 0x0B Addressed PageID is beyond the finger library
#define D_FP_DBRANGEFAIL "Modèle invalide"     // 0x0C Error when reading template from library or invalid template
#define D_FP_UPLOADFEATUREFAIL "Erreur de transfert" // 0x0D Error when uploading template
#define D_FP_PACKETRESPONSEFAIL "Transfert interrompu" // 0x0E Module failed to receive the following data packages
#define D_FP_UPLOADFAIL "Transfert échoué"     // 0x0F Error when uploading image
#define D_FP_DELETEFAIL "Suppression échouée"  // 0x10 Failed to delete the template
#define D_FP_DBCLEARFAIL "Réinitialisation échouée" // 0x11 Failed to clear finger library
#define D_FP_PASSFAIL "Mot-de-passe erroné"    // 0x13 Find whether the fingerprint passed or failed
#define D_FP_INVALIDIMAGE "Image incorrecte"   // 0x15 Failed to generate image because of lack of valid primary image
#define D_FP_FLASHERR "Erreur d'écriture en Flash" // 0x18 Error when writing flash
#define D_FP_INVALIDREG "Nombre incorrect"     // 0x1A Invalid register number
#define D_FP_ADDRCODE "Code adresse"           // 0x20 Address code
#define D_FP_PASSVERIFY "Mot-de-passe vérifié" // 0x21 Verify the fingerprint passed
#define D_FP_UNKNOWNERROR "Erreur"             // Any other error

#endif  // _LANGUAGE_FR_FR_H_
