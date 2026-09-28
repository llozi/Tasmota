// Configuration for specific firmware for Athom Mini Relay Switch (RS01-TAS-1)
// tasmota-sievju-mini
#undef CODE_IMAGE_STR
#define CODE_IMAGE_STR "sievju-mini-relay"

#ifdef USER_TEMPLATE
#undef USER_TEMPLATE
#endif
// Template for Athom Mini Relay Switch (RS01-TAS-1)
//#define USER_TEMPLATE "{\"NAME\":\"RS01-TAS-1\",             \"GPIO\":[0,0,0,32,576,0,0,0,0,224,160,0,0,0],\"FLAG\":0,\"BASE\":18}"
#define USER_TEMPLATE "{\"NAME\":\"Athom Mini Relay Switch\",\"GPIO\":[0,0,0,32,576,0,0,0,0,224,160,0,0,0],\"FLAG\":0,\"BASE\":18}"

#undef FALLBACK_MODULE
#define FALLBACK_MODULE        SONOFF_BASIC
#undef MODULE
#define MODULE USER_MODULE

#undef FRIENDLY_NAME
#define FRIENDLY_NAME          "Sievju MiniRelay"  // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

#undef OTA_URL
#define OTA_URL                 OTA_BASE_URL "tasmota-sievju-mini.bin"  // [OtaUrl]

#undef MQTT_TOPIC
#define MQTT_TOPIC              PROJECT "-mini"     // [Topic]

// -- Power monitoring sensors --------------------
#ifndef USE_ENERGY_SENSOR
  #define USE_ENERGY_SENSOR                        // Add support for Energy Monitors (+14k code)
  #ifndef USE_HLW8012
    #define USE_HLW8012                            // Add support for HLW8012, BL0937 or HJL-01 Energy Monitor for Sonoff Pow and WolfBlitz
  #endif
  #ifndef USE_BL09XX
    #define USE_BL09XX                             // Add support for various BL09XX Energy monitor as used in Blitzwolf SHP-10 or Sonoff Dual R3 v2 (+1k6 code)
  #endif
#endif


#ifndef USE_RULES
#define USE_RULES                                  // Add support for rules (+8k code)
  #ifndef USE_EXPRESSION
    #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
    #ifndef SUPPORT_IF_STATEMENT
    #define SUPPORT_IF_STATEMENT                   // Add support for IF statement in rules (+4k2 code, -332 bytes mem)
    #endif
  #endif
#endif

