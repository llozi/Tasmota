// Configuration for specific firmware for Auvisio S06 IR remote control
// Includes support of USE_IR_REMOTE_FULL
// tasmota-sievju-ir
#undef CODE_IMAGE_STR
#define CODE_IMAGE_STR "sievju-ir-remote"

#undef USER_TEMPLATE
// Template for S06 IR remote control
#define USER_TEMPLATE "{\"NAME\":\"Auvisio S06\",\"GPIO\":[255,255,255,255,52,51,0,0,255,255,8,255,255],\"FLAG\":1,\"BASE\":18}"

#undef MODULE
#define MODULE USER_MODULE

#undef FALLBACK_MODULE
#define FALLBACK_MODULE        SONOFF_BASIC

#undef FRIENDLY_NAME
#define FRIENDLY_NAME          "Sievju IR Controller"  // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

#undef MQTT_TOPIC
#define MQTT_TOPIC             PROJECT "-ir"           // [Topic]

#undef OTA_URL
#define OTA_URL                OTA_BASE_URL "tasmota-sievju-ir.bin"  // [OtaUrl]

//#undef  SERIAL_LOG_LEVEL
//#define SERIAL_LOG_LEVEL       LOG_LEVEL_DEBUG_MORE
//#undef WEB_LOG_LEVEL
//#define WEB_LOG_LEVEL          LOG_LEVEL_DEBUG_MORE


// -- IR Remote features - subset of IR protocols --------------------------
#ifndef USE_IR_REMOTE
#define USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 (+4k3 code, 0k3 mem, 48 iram)
#endif
#ifndef USE_IR_REMOTE_FULL
#define USE_IR_REMOTE_FULL                       // Support all IR protocols from IRremoteESP8266
#endif


#ifndef USE_RULES
#define USE_RULES                                // Add support for rules (+8k code)
  #ifndef USE_EXPRESSION
    #define USE_EXPRESSION                       // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
    #ifndef SUPPORT_IF_STATEMENT
    #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+4k2 code, -332 bytes mem)
    #endif
  #endif
#endif


// -- Optional light modules ----------------------
#define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices

