// tasmota32-sievju-esp32-cam
// Configuration for specific firmware for esp32-cam modules
// tasmota32-sievju-esp32-cam

#undef CODE_IMAGE_STR
#define CODE_IMAGE_STR "sievju-esp32-cam"

#undef USER_TEMPLATE
// Template for ESP32-CAM, see https://templates.blakadder.com/ai-thinker_ESP32-CAM.html
//#define USER_TEMPLATE "{\"NAME\":\"ESP32-CAM\",\"GPIO\":[4992,1,672,1,416,5088,1,1,1,6720,736,704,1,1,5089,5090,0,5091,5184,5152,0,5120,5024,5056,0,0,0,0,4928,576,5094,5095,5092,0,0,5093],\"FLAG\":0,\"BASE\":2}"
// Template for ESP32-CAM, see https://gist.github.com/MadmanMonty/f89417bbd9ef225691a73dc4b198d15d
#define USER_TEMPLATE "{\"NAME\":\"AITHINKER CAM inc LEDs\",\"GPIO\":[4992,1,1,1,416,5088,1,1,1,1,1,1,1,1,5089,5090,0,5091,5184,5152,0,5120,5024,5056,0,0,0,0,4928,320,5094,5095,5092,0,0,5093],\"FLAG\":0,\"BASE\":1}"
#undef MODULE
#define MODULE USER_MODULE

#undef FALLBACK_MODULE
#define FALLBACK_MODULE        WEMOS             // [Module2] Select default module on fast reboot where USER_MODULE is user template

#undef FRIENDLY_NAME
#define FRIENDLY_NAME          "Sievju ESP32-Cam"    // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

#undef OTA_URL
#define OTA_URL                OTA_BASE_URL "tasmota32-sievju-esp32-cam.bin"  // [OtaUrl]

#undef MQTT_TOPIC
#define MQTT_TOPIC             PROJECT "-esp32-cam"  // [Topic]

#define USE_WEBCAM
  //#define WEBCAM_DEV_DEBUG
  #define USE_WEBCAM_V2
  #define USE_WEBCAM_MOTION                     // Enable motion detection in webcam V2 driver
  #define ENABLE_RTSPSERVER

#define USE_SPI
#define USE_SDCARD

#ifndef USE_RULES
#define USE_RULES                                // Add support for rules (+8k code)
  #ifndef USE_EXPRESSION
    #define USE_EXPRESSION                       // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
    #ifndef SUPPORT_IF_STATEMENT
    #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+4k2 code, -332 bytes mem)
    #endif
  #endif
#endif

#ifndef USE_BERRY
#define USE_BERRY                                // Enable Berry scripting language
  #define USE_BERRY_PYTHON_COMPAT                // Enable by default `import python_compat`
  #define USE_BERRY_TIMEOUT             4000     // Timeout in ms, will raise an exception if running time exceeds this timeout
  #define USE_BERRY_PSRAM                        // Allocate Berry memory in PSRAM if PSRAM is connected - this might be slightly slower but leaves main memory intact
  #define USE_BERRY_IRAM                         // Allocate some data structures in IRAM (which is ususally unused) when possible and if no PSRAM is available
  #define USE_BERRY_DEBUG                        // Compile Berry bytecode with line number information, makes exceptions easier to debug. Adds +8% of memory consumption for compiled code
  //   #define USE_BERRY_DEBUG_GC                   // Print low-level GC metrics
  // #define USE_BERRY_INT64                        // Add 64 bits integer support (+1.7KB Flash)
  #define USE_WEBCLIENT                          // Enable `webclient` to make HTTP/HTTPS requests. Can be disabled for security reasons.
  #define USE_WEBCLIENT_HTTPS                    // Enable HTTPS outgoing requests based on BearSSL (much ligher then mbedTLS, 42KB vs 150KB) in insecure mode (no verification of server's certificate)
                                                 // Note that only one cipher is enabled: ECDHE_RSA_WITH_AES_128_GCM_SHA256 which is very commonly used and highly secure
  #define USE_BERRY_WEBCLIENT_USERAGENT  "TasmotaClient" // default user-agent used, can be changed with `wc.set_useragent()`
  #define USE_BERRY_WEBCLIENT_TIMEOUT  2000      // Default timeout in milliseconds
  #define USE_BERRY_TCPSERVER                    // Enable TCP socket server (+0.6k)
  #define USE_BERRY_FAST_LOOP_SLEEP_MS  5        // Minimum time in milliseconds to before calling again `tasmota.fast_loop()`, a smaller value will consume more CPU (min 1ms)
    #define USE_BERRY_LEDS_PANEL                 // Add button to dynamically load the Leds Panel from a bec file online
    #define USE_BERRY_LEDS_PANEL_URL             "http://ota.tasmota.com/tapp/leds_panel.bec"
    //#define USE_BERRY_LVGL_PANEL                 // Add button to dynamically load the LVGL Panel from a bec file online
    #define USE_BERRY_LVGL_PANEL_URL             "http://ota.tasmota.com/tapp/lvgl_panel.bec"
    //#define USE_BERRY_PARTITION_WIZARD           // Add a button to dynamically load the Partion Wizard from a bec file online (+1.3KB Flash)
    #define USE_BERRY_PARTITION_WIZARD_URL      "http://ota.tasmota.com/tapp/partition_wizard.bec"
    //#define USE_BERRY_GPIOVIEWER                 // Add a button to dynamocally load the GPIO Viewer from a bec file online
    #define USE_BERRY_GPIOVIEWER_URL            "http://ota.tasmota.com/tapp/gpioviewer.bec"
  // #define USE_BERRY_ULP                          // Enable ULP (Ultra Low Power) support (+4.9k)
  // Berry crypto extensions below:
  #define USE_BERRY_CRYPTO_AES_GCM               // enable AES GCM 256 bits
  // #define USE_BERRY_CRYPTO_AES_CCM               // enable AES CCM 128 bits
  // #define USE_BERRY_CRYPTO_AES_CTR               // enable AES CTR 256 bits
  // #define USE_BERRY_CRYPTO_EC_P256               // enable EC P256r1
  // #define USE_BERRY_CRYPTO_EC_C25519             // enable Elliptic Curve C C25519
  #define USE_BERRY_CRYPTO_SHA256                // enable SHA256 hash function
  #define USE_BERRY_CRYPTO_HMAC_SHA256           // enable HMAC SHA256 hash function
  // #define USE_BERRY_CRYPTO_PBKDF2_HMAC_SHA256    // PBKDF2 with HMAC SHA256, used in Matter protocol
  // #define USE_BERRY_CRYPTO_HKDF_SHA256      // HKDF with HMAC SHA256, used in Matter protocol
  // #define USE_BERRY_CRYPTO_SPAKE2P_MATTER   // SPAKE2+ used in Matter 1.0, complete name is SPAKE2+-P256-SHA256-HKDF-SHA256-HMAC-SHA256
  // #define USE_BERRY_CRYPTO_RSA              // RSA primitives including JWT RS256 (3.9KB flash)

#endif  // #ifndef USE_BERRY

