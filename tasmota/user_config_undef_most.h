// -- MQTT - Telemetry ----------------------------
#undef TELE_PERIOD
#define TELE_PERIOD            30               // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)
#undef TELE_ON_POWER
#define TELE_ON_POWER          false            // [SetOption59] send tele/STATE together with stat/RESULT (false = Disable, true = Enable)

#undef USE_IMPROV                               // Disable support for IMPROV serial protocol as used by esp-web-tools (+2k code)
#undef USE_TIMERS                               // Disable support for up to 16 timers (+2k2 code)

#undef USE_DOMOTICZ                             // Disable Domoticz (+6k code, +0.3k mem)
#undef USE_TASMOTA_DISCOVERY                    // Disable Tasmota Discovery support (+2k code)

// -- Rules or Script  ----------------------------
// Select none or only one of the below defines USE_RULES or USE_SCRIPT
#undef USE_RULES                                // Disable support for rules (+8k code)

#undef USE_SCRIPT                                // Disable support for script (+17k code)


#undef USE_BERRY                                // Disable Berry scripting language
#undef USE_WEBCLIENT                            // Berry `webclient` to make HTTP/HTTPS requests. Can be disabled for security reasons.
#undef USE_WEBCLIENT_HTTPS                      // Disable HTTPS outgoing requests based on BearSSL (much ligher then mbedTLS, 42KB vs 150KB) in insecure mode (no verification of server's certificate)

// -- KNX IP Protocol -----------------------------
#undef USE_KNX                                  // Disable KNX IP Protocol Support (+9.4k code, +3k7 mem)
#undef USE_KNX_WEB_MENU                         // Disable KNX WEB MENU (+8.3k code, +144 mem)
#undef USE_AUTOCONF                             // Enable Esp32 autoconf feature, requires USE_BERRY and USE_WEBCLIENT_HTTPS (12KB Flash)


#undef KNX_ENHANCED
#define KNX_ENHANCED           false             // [Knx_Enhanced] Enable KNX Enhanced Mode


#undef USE_ARDUINO_OTA                          // Disable support for Arduino OTA (+13k code)

#undef USE_HOME_ASSISTANT                       // Disable Home Assistant Discovery Support (+7k code)

// -- Low level interface devices -----------------
#undef USE_DHT                                  // Disable support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor

#undef USE_MAX31855                             // Disable MAX31855 K-Type thermocouple sensor using softSPI
#undef USE_MAX31865                             // Disable support for MAX31865 RTD sensors using softSPI
#undef USE_LMT01                                // Disable support for TI LMT01 temperature sensor, count pulses on single GPIO (+0k5 code)

#undef USE_TIMERS

#undef USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 (+4k3 code, 0k3 mem, 48 iram)

#undef USE_PZEM004T                             // Disable support for PZEM004T Energy monitor (+2k code)
#undef USE_PZEM_AC                              // Disable support for PZEM014,016 Energy monitor (+1k1 code)
#undef USE_PZEM_DC                              // Disable support for PZEM003,017 Energy monitor (+1k1 code)
#undef USE_MCP39F501

// -- Optional modules ----------------------------
#undef ROTARY_V1                                // Disable support for Rotary Encoder as used in MI Desk Lamp (+0k8 code)
#undef USE_SONOFF_RF                            // Disable support for Sonoff Rf Bridge (+3k2 code)
#undef USE_SONOFF_SC                            // Disable support for Sonoff Sc (+1k1 code)
#undef USE_TUYA_MCU                             // Disable support for Tuya Serial MCU
#undef USE_ARMTRONIX_DIMMERS                    // Disable support for Armtronix Dimmers (+1k4 code)
#undef USE_PS_16_DZ                             // Disable support for PS-16-DZ Dimmer (+2k code)
#undef USE_SONOFF_IFAN                          // Disable support for Sonoff iFan02 and iFan03 (+2k code)
#undef USE_BUZZER                               // Disable support for a buzzer (+0k6 code)
#undef USE_ARILUX_RF                            // Disable support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))
#undef USE_SHUTTER                              // Disable Shutter support for up to 4 shutter with different motortypes (+11k code)
#undef USE_DEEPSLEEP                            // Disable support for deepsleep (+1k code)
#undef USE_EXS_DIMMER                           // Disable support for ES-Store Wi-Fi Dimmer (+1k5 code)
#undef USE_DEVICE_GROUPS                        // Disable support for device groups (+5k5 code)
#undef USE_PWM_DIMMER                           // Disable support for MJ-SD01/acenx/NTONPOWER PWM dimmers (+2k3 code, DGR=0k7)
#undef USE_PWM_DIMMER_REMOTE                    // Disable support for remote switches to PWM Dimmer
#undef USE_SONOFF_D1                            // Disable support for Sonoff D1 Dimmer (+0k7 code)
#undef USE_SHELLY_DIMMER                        // Disable support for Shelly Dimmer (+3k code)

#undef USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices

#undef USE_RF_FLASH                             // Disable support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB
#undef USE_HOTPLUG                              // Disable support for HotPlug
#undef USE_KEELOQ                               // Disable support for Jarolift rollers by Keeloq algorithm (+4k5 code)


// -- Optional light modules ----------------------
#undef USE_LIGHT                                // Disable support for light control
#undef USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
#undef USE_MY92X1                               // Disable support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas
#undef USE_SM16716                              // Disable support for SM16716 RGB LED controller (+0k7 code)
#undef USE_SM2135                               // Disable support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
#undef USE_SM2335                               // Disable support for SM2335 RGBCW led control as used in SwitchBot Color Bulb (+0k7 code)
#undef USE_BP5758D                              // Disable support for BP5758D RGBCW led control as used in some Tuya lightbulbs (+0k8 code)
#undef USE_SONOFF_L1                            // Disable support for Sonoff L1 led control
#undef USE_ELECTRIQ_MOODL                       // Disable support for ElectriQ iQ-wifiMOODL RGBW LED controller (+0k3 code)
#undef USE_LIGHT_PALETTE                        // Disable support for color palette (+0k7 code)
#undef USE_LIGHT_VIRTUAL_CT                     // Disable support for Virtual White Color Temperature (+1.1k code)
#undef USE_DGR_LIGHT_SEQUENCE                   // Disable support for device group light sequencing (requires USE_DEVICE_GROUPS) (+0k2 code)
#undef USE_AC_ZERO_CROSS_DIMMER

// -- Counter input -------------------------------
#undef USE_COUNTER                              // Enable inputs as counter (+0k8 code)

// -- One wire sensors ----------------------------
#undef USE_DS18x20                              // Disable support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)

// -- I2C sensors ---------------------------------
#undef USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)
// undefining the following leads to a compile error
//#undef I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
//#undef I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
//#undef I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

#undef USE_SPI
  #undef USE_MIBLE                              // BLE-bridge for some Mijia-BLE-sensors (+4k7 code)
  #undef USE_DISPLAY_ILI9341                    // [DisplayModel 4] Enable ILI9341 Tft 480x320 display (+19k code)

// -- Power monitoring sensors --------------------
#undef USE_ENERGY_SENSOR                        // Disable support for Energy Monitors (+14k code)
#undef USE_ENERGY_COLUMN_GUI                    // Disable support for column display in GUI (+0k5 code)
#undef USE_ENERGY_MARGIN_DETECTION              // Disable support for Energy Margin detection (+1k6 code)
#undef USE_ENERGY_POWER_LIMIT                   // Disable additional support for Energy Power Limit detection (+1k2 code)
#undef USE_ENERGY_DUMMY                         // Disable support for dummy Energy monitor allowing user values (+0k7 code)
#undef USE_HLW8012                              // Disable support for HLW8012, BL0937 or HJL-01 Energy Monitor for Sonoff Pow and WolfBlitz
#undef USE_CSE7766                              // Disable support for CSE7766 Energy Monitor for Sonoff S31 and Pow R2
#undef USE_CSE7761                              // Disable support for CSE7761 Energy monitor as used in Sonoff Dual R3
#undef USE_ADE7880                              // Disable ADE7880 Energy monitor as used on Shelly 3EM (I2C address 0x38) (+3k8)
#undef USE_ADE7953                              // Disable ADE7953 Energy monitor as used on Shelly 2.5 (I2C address 0x38) (+1k5)
#undef USE_PZEM004T                             // Disable support for PZEM004T Energy monitor (+2k code)
#undef USE_PZEM_AC                              // Disable support for PZEM014,016 Energy monitor (+1k1 code)
#undef USE_PZEM_DC                              // Disable support for PZEM003,017 Energy monitor (+1k1 code)
#undef USE_MCP39F501                            // Disable support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)
#undef USE_BL09XX                               // Disable support for various BL09XX Energy monitor as used in Blitzwolf SHP-10 or Sonoff Dual R3 v2 (+1k6 code)
#undef USE_SDM72                                // Disable support for Eastron SDM72-Modbus energy meter
#undef USE_SDM120                               // Disable support for Eastron SDM120-Modbus energy meter
#undef USE_SDM230                               // Disable support for Eastron SDM230-Modbus energy monitor (+?? code)
#undef USE_SDM630                               // Disable support for Eastron SDM630-Modbus energy monitor (+0k6 code)
#undef USE_DDS2382                              // Disable support for Hiking DDS2382 Modbus energy monitor (+0k6 code)
#undef USE_DDSU666                              // Disable support for Chint DDSU666 Modbus energy monitor (+0k6 code)
#undef USE_SOLAX_X1                             // Disable support for Solax X1 series Modbus log info (+4k1 code)
#undef USE_LE01MR                               // Disable support for F&F LE-01MR modbus energy meter
#undef USE_WE517                                // Disable support for Orno WE517-Modbus energy monitor (+1k code)
#undef USE_TELEINFO                             // Disable support for French Energy Provider metering telemetry
#undef USE_IEM3000                              // Disable support for Schneider Electric iEM3000-Modbus series energy monitor (+0k8 code)

// -- Low level interface devices -----------------
#undef USE_DHT                                  // Disable support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor (1k6 code)

// -- Serial sensors ------------------------------
#undef USE_MHZ19                                // Disable support for MH-Z19 CO2 sensor (+2k code)
#undef USE_SENSEAIR                             // Disable support for SenseAir K30, K70 and S8 CO2 sensor (+2k3 code)
#undef USE_PMS5003                              // Disable support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
#undef USE_NOVA_SDS                             // Disable support for SDS011 and SDS021 particle concentration sensor (+0k7 code)
#undef USE_HPMA                                 // Disable support for Honeywell HPMA115S0 particle concentration sensor (+1k4)
#undef USE_SERIAL_BRIDGE                        // Disable support for software Serial Bridge (+1k1 code)
#undef USE_MP3_PLAYER                           // Use of the DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
#undef USE_AZ7798                               // Disable support for AZ-Instrument 7798 CO2 datalogger (+1k6 code)
#undef USE_PN532_HSU                            // Disable support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
#undef USE_RDM6300                              // Disable support for RDM6300 125kHz RFID Reader (+0k8)
#undef USE_IBEACON                              // Disable support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)
#undef USE_HM10                                 // Disable support for HM-10 as a BLE-bridge for the LYWSD03 (+5k1 code)
#undef USE_HRXL                                 // Disable support for MaxBotix HRXL-MaxSonar ultrasonic range finders (+0k7)
#undef USE_DYP                                  // Disable support for DYP ME-007 ultrasonic distance sensor, serial port version (+0k5 code)

// -- IR Remote features - subset of IR protocols --------------------------
#undef USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 (+4k3 code, 0k3 mem, 48 iram)
// WARNING: if you change any IR configuration, you need to clear Platform.io cache
//          currently the include change detection does not work for these parameters
//          This is not an issue if you compile with gitpod or pre-compiled binaries
//          since there is no cache of previously compiled libraries
// ====>

// -- Zigbee interface ----------------------------
#undef USE_ZIGBEE                               // Disable serial communication with Zigbee CC2530 flashed with ZNP (+49k code, +3k mem)

#undef USE_DISPLAY                              // Disable Display support

#undef USE_TCP_BRIDGE

#undef USE_PROJECTOR_CTRL                       // Disable support for LCD/DLP Projector serial control interface

#undef USE_GPS                                  // Disable support for GPS and NTP Server for becoming Stratus 1 Time Source (+ 3.1kb flash, +132 bytes RAM)

#undef USE_CCLOADER

#undef USE_RC_SWITCH

#undef USE_SR04                                 // Disable support for HC-SR04 ultrasonic devices (+1k code)

#undef USE_TM1638                               // Disable support for TM1638 switches copying Switch1 .. Switch8 (+1k code)

#undef USE_HX711                                // Disable support for HX711 load cell (+1k5 code)
#undef USE_HX711_GUI

#undef USE_TX20_WIND_SENSOR                     // Disable support for La Crosse TX20 anemometer (+2k6/0k8 code)
#undef USE_TX23_WIND_SENSOR                     // Disable support for La Crosse TX23 anemometer (+2k7/1k code)
#undef USE_WINDMETER                            // Disable support for analog anemometer (+2k2 code)

#undef USE_RF_SENSOR                            // Disable support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)

#undef USE_HRE                                  // Disable support for Badger HR-E Water Meter (+1k4 code)

#undef USE_A4988_STEPPER                        // Disable support for A4988 stepper-motor-driver-circuit (+10k5 code)

#undef USE_TASMOTA_CLIENT                       // Disable support for Arduino Uno/Pro Mini via serial interface including flashing (+2k3 code, 44 mem)

#undef USE_BLE_ESP32                            // (ESP32 only) Disable support for native BLE on ESP32 - use new driver
#undef USE_MI_ESP32                             // (ESP32 only) Disable support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)

#undef USE_MIEL_HVAC                            // Disable support for Mitsubishi Electric HVAC serial interface (+5k code)

#undef USE_OPENTHERM                            // Disable support for OpenTherm (+15k code)


