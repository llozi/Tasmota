// tasmota32_watering-well
// Configuration for specific firmware for esp32-wroom-32u module used for water level indication and pump switching.
// (ESP32-DevKitC V4 board, https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html)

#undef CODE_IMAGE_STR
#define CODE_IMAGE_STR "esp32-watering-well"

#undef USER_TEMPLATE
// Template for ESP32-Wroom32U ESP32-DevKitC V4 board, (see https://templates.blakadder.com/ - no entry)
// GPIO usage on my ESP32-DevKitC V4 board:
//    0: 37 =Button1 (on-board button "Boot")
//    1: U0TxD
//    2: 8256 =Heartbeati
//    3: U0RxD
//    4: 576 =LedLinki
//    5: non-existent
//    6 - 11: reserved external flash
//   12: 160 =Input1
//   13: unused
//   14: 161 =Input2
//   15: 224 =Relay1, switch for water pump
//   16: unused
//   17: unused
//   18: unused
//   19: unused
//   20: non-existent
//   21: 640 =I2C_SDA (currently not in use)
//   22: 608 =I2C_SCL (currently not in use)
//   23: unused
//   24: non-existent
//   25: unused
//   26: 162 =Input3
//   27: unused
//   28: non-existent
//   29: non-existent
//   30: non-existent
//   31: non-existent
//   32: unused
//   33: unused
//   34: unused
//   35: unused
//   36: unused
//   39: unused
#define USER_TEMPLATE "{\"NAME\":\"ESP32-WATERING_WELL\",\"GPIO\":[32,1,8256,1,576,0,0,0,160,1,161,224,1,1,1,1,0,640,608,1,0,1,162,1,0,0,0,0,1,1,1,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"
#undef MODULE
#define MODULE USER_MODULE

#undef FALLBACK_MODULE
#define FALLBACK_MODULE        WEMOS             // [Module2] Select default module on fast reboot where USER_MODULE is user template

#undef FRIENDLY_NAME
#define FRIENDLY_NAME          "Watering-Well"    // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

#undef OTA_URL
#define OTA_URL                "http://sievju.org/tasmota_firmware/tasmota32-watering-well.bin"  // [OtaUrl]

#undef MQTT_TOPIC
#define MQTT_TOPIC             PROJECT "watering-well"  // [Topic]

#undef MQTT_SWITCHES
#define MQTT_SWITCHES          true             // [SetOption114] Detach switches from relays and send MQTT messages instead

//#define USE_SPI

// -- I2C sensors ---------------------------------
#ifndef USE_I2C
#define USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)
#endif

#ifdef USE_UFILESYS
#define USE_UFILESYS
#endif

#ifndef USE_BMP
#define USE_BMP
//  #ifndef BME68X
//  #define USE_BME68X
//  #endif
#endif

// -- Counter input -------------------------------
#ifndef USE_COUNTER
#define USE_COUNTER                              // Enable inputs as counter (+0k8 code)
#endif

// -- One wire sensors ----------------------------
#ifndef USE_DS18x20
#define USE_DS18x20                              // Enable support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)
#endif

#define USE_ADC                                  // Add support for ADC on GPIO32 to GPIO39

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
          // #define USE_BERRY_DEBUG                        // Compile Berry bytecode with line number information, makes exceptions easier to debug. Adds +8% of memory consumption for compiled code
            // #define USE_BERRY_INT64                        // Add 64 bits integer support (+1.7KB Flash)
  #define USE_WEBCLIENT                          // Enable `webclient` to make HTTP/HTTPS requests. Can be disabled for security reasons.
  #define USE_WEBCLIENT_HTTPS                    // Enable HTTPS outgoing requests based on BearSSL (much ligher then mbedTLS, 42KB vs 150KB) in insecure mode (no verification of server's certificate)
                                                 // Note that only one cipher is enabled: ECDHE_RSA_WITH_AES_128_GCM_SHA256 which is very commonly used and highly secure
  #define USE_BERRY_WEBCLIENT_USERAGENT  "TasmotaClient" // default user-agent used, can be changed with `wc.set_useragent()`
  #define USE_BERRY_WEBCLIENT_TIMEOUT  2000      // Default timeout in milliseconds
  #define USE_BERRY_TCPSERVER                    // Enable TCP socket server (+0.6k)
 // #define USE_BERRY_ULP                          // Enable ULP (Ultra Low Power) support (+4.9k)// see https://tasmota.github.io/docs/Thermostat
#endif

