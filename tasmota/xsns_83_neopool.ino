/*
  xsns_83_neopool.ino - Sugar Valley NeoPool Control System Modbus support for Tasmota

  Copyright (C) 2021  Norbert Richter

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

#ifdef USE_NEOPOOL
/*********************************************************************************************\
 * Sugar Valley NeoPool electronic pool control and water treatment system, also known as brand
 *   Hidrolife (yellow case)
 *   Aquascenic (blue case)
 *   Oxilife (green case)
 *   Bionet (light blue case)
 *   Hidroniser (red case)
 *   UVScenic (lilca case)
 *   Station (orange case)
 *   Brilix
 *   Bayrol
 *   Hay
 *
 * Sugar Valley RS485 connector inside (Display/Wifi/External)
 * pins (from top to bottom):
 *
 *    RS485 MODBUS
 *      ___
 *   1 |*  |- +12V
 *   2 |*  |-
 *   3 |*  |- Modbus A+
 *   4 |*  |- Modbus B-
 *   5 |*__|- Modbus GND
 *
 *   RS485 Parameter: 19200 Baud / 1 Stopbit / Parity None
 *
 * Hardware serial will be selected if GPIO1 = [NeoPool Rx] and GPIO3 = [NeoPool Tx]
\*********************************************************************************************/

#define XSNS_83                      83

#ifndef NEOPOOL_MODBUS_SPEED
#define NEOPOOL_MODBUS_SPEED         19200
#endif

#ifndef NEOPOOL_MODBUS_ADDRESS
#define NEOPOOL_MODBUS_ADDRESS       1      // Modbus address
#endif


#define NEOPOOL_READ_REGISTER        0x04   // Function code used to read register:   Read Input Registers
#define NEOPOOL_WRITE_REGISTER       0x10   // Function code used to write register: Write Multiple Registers
#define NEOPOOL_READ_TIMEOUT           25   // read data timeout in ms

//#define NEOPOOL_OPTIMIZE_READINGS          // Optimize modbus readings by considering of MBF_NOTIFICATION register - Note: Does not work on all systems!

/*********************************************************************************************\
 * Sugar Valley Modbus Register (* register are currently used)
 * (see https://downloads.vodnici.net/uploads/wpforo/attachments/69/171-Modbus-registers.pdf)
\*********************************************************************************************/
enum NeoPoolRegister {
                                      // addr    Unit  Description
                                      // ------  ----- ------------------------------------------------------------
  // MODBUS page (0x0000 - 0x002E - unknown - for internal use only)

  // MEASURE page (0x01xx)
  MBF_ION_CURRENT=0x0100,             // 0x0100*       Current measured in the ionization system
  MBF_HIDRO_CURRENT,                  // 0x0101*       Intensity level currently measured in the hydrolysissystem
  MBF_MEASURE_PH,                     // 0x0102* ph    Level measured in hundredths (700=7.00)
  MBF_MEASURE_RX,                     // 0x0103* ppm   Redox level in hundredths of ppm (100=1.00 ppm)
  MBF_MEASURE_CL,                     // 0x0104* ppm   Level measured in hundredths of chlorine ppm (100=1.00 ppm)
  MBF_MEASURE_CONDUCTIVITY,           // 0x0105  %     Level of conductivity measured in the water.
  MBF_MEASURE_TEMPERATURE,            // 0x0106* °C    Water temperature sensor (100=10.0°C)
  MBF_PH_STATUS,                      // 0x0107* mask  Status of the module control pH
  MBF_RX_STATUS,                      // 0x0108* mask  Status of the Rx-module
  MBF_CL_STATUS,                      // 0x0109* mask  Status of the Chlorine-module
  MBF_CD_STATUS,                      // 0x010A  mask  Status of the Conductivity-module
  MBF_ION_STATUS=0x010C,              // 0x010C* mask  Status of the Ionization-module
  MBF_HIDRO_STATUS,                   // 0x010D* mask  Status of the Hydrolysis-module
  MBF_RELAY_STATE,                    // 0x010E* mask  Status of each configurable relays
  MBF_HIDRO_SWITCH_VALUE,             // 0x010F        INTERNAL - contains the opening of the hydrolysis PWM.
  MBF_NOTIFICATION,                   // 0x0110* mask  Reports whether a page of properties has changed since the last time it was consulted.
  MBF_HIDRO_VOLTAGE,                  // 0x0111        Reports on the stress applied to the hydrolysis cell. This register, together with that of MBF_HIDRO_CURRENT allows extrapolating the salinity of the water.

  // GLOBAL page (0x02xx)
  MBF_SAVE_TO_EEPROM=0x02F0,          // 0x02F0        A write operation to this register starts a EEPROM storage operation immediately. During the EEPROM storage procedure, the system may be unresponsive to MODBUS requests. The operation will last always less than 1 second.
  MBF_IMM_TAKE_OVER=0x02F5,           // 0x02F5        undocumented - immediately tale over - a write operation to this register take over the previous written data (neccessary if changing e.g. timers)

  // FACTORY page (0x03xx)
  MBF_PAR_VERSION=0x0300,             // 0x0300*       Software version of the PowerBox (unused)
  MBF_PAR_MODEL,                      // 0x0301* mask  System model options
  MBF_PAR_SERNUM,                     // 0x0302        Serial number of the PowerBox (unused)
  MBF_PAR_ION_NOM,                    // 0x0303        Ionization maximum production level (DO NOT WRITE!)
  MBF_PAR_HIDRO_NOM=0x0306,           // 0x0306        Hydrolysis maximum production level. (DO NOT WRITE!) If the hydrolysis is set to work in percent mode, this value will be 100. If the hydrolysis module is set to work in g/h production, this module will contain the maximum amount of production in g/h units. (DO NOT WRITE!)
  MBF_PAR_SAL_AMPS=0x030A,            // 0x030A        Current command in regulation for which we are going to measure voltage
  MBF_PAR_SAL_CELLK,                  // 0x030B        Specifies the relationship between the resistance obtained in the measurement process and its equivalence in g / l (grams per liter)
  MBF_PAR_SAL_TCOMP,                  // 0x030C        Specifies the deviation in temperature from the conductivity.
  MBF_PAR_HIDRO_MAX_VOLTAGE=0x0322,   // 0x0322        Allows setting the maximum voltage value that can be reached with the hydrolysis current regulation. The value is specified in tenths of a volt. The default value of this register when the EEPROM is cleared is 80, which is equivalent to a maximum cell operating voltage of 8 volts.
  MBF_PAR_HIDRO_FLOW_SIGNAL,          // 0x0323        Allows to select the operation of the flow detection signal associated with the operation of the hydrolysis (see MBV_PAR_HIDRO_FLOW_SIGNAL*). The default value for this register is 0 (standard detection).
  MBF_PAR_HIDRO_MAX_PWM_STEP_UP,      // 0x0324        This register sets the PWM ramp up of the hydrolysis in pulses per duty cycle. This register makes it possible to adjust the rate at which the power delivered to the cell increases, allowing a gradual rise in power so that the operation of the switching source of the equipment is not saturated. Default 150
  MBF_PAR_HIDRO_MAX_PWM_STEP_DOWN,    // 0x0325        This register sets the PWM down ramp of the hydrolysis in pulses per duty cycle. This register allows adjusting the rate at which the power delivered to the cell decreases, allowing a gradual drop in power so that the switched source of the equipment is not disconnected due to lack of consumption. This gradual fall must be in accordance with the type of cell used, since said cell stores charge once the current stimulus has ceased. Default 20

  // INSTALLER page (0x04xx)
  MBF_PAR_ION_POL0=0x0400,            // 0x0400        Time in min the team must spend working on positive polarization in copper-silver ionization.
  MBF_PAR_ION_POL1,                   // 0x0401        Time in min the team must spend working on positive polarization in copper-silver ionization.
  MBF_PAR_ION_POL2,                   // 0x0402        Time in min the team must spend working on positive polarization in copper-silver ionization.
  MBF_PAR_HIDRO_ION_CAUDAL,           // 0x0403  mask  Bitmask register regulates the external control mode of ionization, hydrolysis and pumps.
  MBF_PAR_HIDRO_MODE,                 // 0x0404        Regulates the external control mode of hydrolysis from the modules of measure. 0: no control, 1: standard control (on / off), 2: with timed pump
  MBF_PAR_HIDRO_POL0,                 // 0x0405        Time must spend working on positive polarization in hydrolysis / electrolysis. Time is stored in minutes.
  MBF_PAR_HIDRO_POL1,                 // 0x0406        Time must spend working on positive polarization in hydrolysis / electrolysis. Time is stored in minutes.
  MBF_PAR_HIDRO_POL2,                 // 0x0407        Time must spend working on positive polarization in hydrolysis / electrolysis. Time is stored in minutes.
  MBF_PAR_TIME_LOW,                   // 0x0408*       System timestamp (32 bit unixtime) - low word
  MBF_PAR_TIME_HIGH,                  // 0x0409*       System timestamp (32 bit unixtime) - high word
  MBF_PAR_PH_ACID_RELAY_GPIO,         // 0x040A*       Relay number assigned to the acid pump function (only with pH module).
  MBF_PAR_PH_BASE_RELAY_GPIO,         // 0x040B*       Relay number assigned to the base pump function (only with pH module).
  MBF_PAR_RX_RELAY_GPIO,              // 0x040C*       Relay number assigned to the Redox level regulation function. If the value is 0, there is no relay assigned, and therefore there is no pump function (ON / OFF should not be displayed)
  MBF_PAR_CL_RELAY_GPIO,              // 0x040D*       Relay number assigned to the chlorine pump function (only with free chlorine measuring modules).
  MBF_PAR_CD_RELAY_GPIO,              // 0x040E*       Relay number assigned to the conductivity (brine) pump function (only with conductivity measurement modules).
  MBF_PAR_TEMPERATURE_ACTIVE,         // 0x040F*       Indicates whether the equipment has a temperature measurement or not.
  MBF_PAR_LIGHTING_GPIO,              // 0x0410*       Relay number assigned to the lighting function. 0: inactive.
  MBF_PAR_FILT_MODE,                  // 0x0411*       Filtration mode (see MBV_PAR_FILT_*)
  MBF_PAR_FILT_GPIO,                  // 0x0412*       Relay selected to perform the filtering function (by default it is relay 2). When this value is at zero, there is no relay assigned and therefore it is understood that the equipment does not control the filtration. In this case, the filter option does not appear in the user menu.
  MBF_PAR_FILT_MANUAL_STATE,          // 0x0413        Filtration status in manual mode (on = 1; off = 0)
  MBF_PAR_HEATING_MODE,               // 0x0414        Heating mode. 0: the equipment is not heated. 1: the equipment is heating.
  MBF_PAR_HEATING_GPIO,               // 0x0415        Relay selected to perform the heating function (by default it is relay 7). When this value is at zero, there is no relay assigned and therefore it is understood that the equipment does not control the heating. In this case, the filter modes associated with heating will not be displayed.
  MBF_PAR_HEATING_TEMP,               // 0x0416        Heating setpoint temperature
  MBF_PAR_CLIMA_ONOFF,                // 0x0417        Activation of the air conditioning mode (0 inactive; 1 active.
  MBF_PAR_SMART_TEMP_HIGH,            // 0x0418        Superior temperature of the Smart mode
  MBF_PAR_SMART_TEMP_LOW,             // 0x0419        Lower temperature of the Smart mode
  MBF_PAR_SMART_ANTI_FREEZE,          // 0x041A        Antifreeze mode activated (1) or not (0). This adjustment is only available in the Smart filtration mode.
  MBF_PAR_SMART_INTERVAL_REDUCTION,   // 0x041B        This register is read-only and reports to the outside what percentage (0 to 100%) is being applied to the nominal filtration time. 100% means that the total programmed time is being filtered.
  MBF_PAR_INTELLIGENT_TEMP,           // 0x041C        Setpoint temperature for smart mode
  MBF_PAR_INTELLIGENT_FILT_MIN_TIME,  // 0x041D        Minimum filtration time in minutes
  MBF_PAR_INTELLIGENT_BONUS_TIME,     // 0x041E        Bonus time for the current set of intervals
  MBF_PAR_INTELLIGENT_TT_NEXT_INTERVAL,//0x041F        Time to next filtration interval. When it reaches 0 an interval is started and the number of seconds is reloaded for the next interval (2x3600)
  MBF_PAR_INTELLIGENT_INTERVALS,      // 0x0420        Number of started intervals. When it reaches 12 it is reset to 0 and the bonus time is reloaded with the value of MBF_PAR_INTELLIGENT_FILT_MIN_TIME
  MBF_PAR_FILTRATION_STATE,           // 0x0421        Filtration function state: 0 is off and 1 is on. The filtration state is regulated according to the MBF_PAR_FILT_MANUAL_STATE register if the filtration mode held in register MBF_PAR_FILT_MODE is set to FILT_MODE_MANUAL (0).
  MBF_PAR_HEATING_DELAY_TIME,         // 0x0422        // Timer in seconds that counts up when the heating is to be enabled. Once this counter reaches 60 seconds, the heating is then enabled. This counter is for internal use only.
  MBF_PAR_FILTERING_TIME_LOW,         // 0x0423        32-bit value:
  MBF_PAR_FILTERING_TIME_HIGH,        // 0x0424        Internal timer for the intelligent filtering mode. It counts the filtering time done during a given day. This register is only for internal use and should not be modified by the user.
  MBF_PAR_INTELLIGENT_INTERVAL_TIME_LOW,// 0x0425      32-bit value:
  MBF_PAR_INTELLIGENT_INTERVAL_TIME_HIGH,// 0x0426     Internal timer that counts the filtration interval assigned to the the intelligent mode. This register is only for internal use and should not be modified by the user.
  MBF_PAR_UV_MODE,                    // 0x0427        UV mode active or not - see MBV_PAR_UV_MODE*. To enable UV support for a given device, add the mask MBMSK_MODEL_UV to the MBF_PAR_MODEL register.
  MBF_PAR_UV_HIDE_WARN,               // 0x0428  mask  Suppression for warning messages in the UV mode.
  MBF_PAR_UV_RELAY_GPIO,              // 0x0429        Relay number assigned to the UV function.
  MBF_PAR_PH_PUMP_REP_TIME_ON,        // 0x042A  mask  Time that the pH pump will be turn on in the repetitive mode (see MBMSK_PH_PUMP_*). Contains a special time format, see desc for MBMSK_PH_PUMP_TIME.
  MBF_PAR_PH_PUMP_REP_TIME_OFF,       // 0x042B        Time that the pH pump will be turn off in the repetitive mode. Contains a special time format, see desc for MBMSK_PH_PUMP_TIME, has no upper configuration bit 0x8000
  MBF_PAR_HIDRO_COVER_ENABLE,         // 0x042C        Options for the hydrolysis/electrolysis module (see MBMSK_HIDRO_*)
  MBF_PAR_HIDRO_COVER_REDUCTION,      // 0x042D        Configured levels for the cover reduction and the hydrolysis shutdown temperature options: LSB=Percentage for the cover reduction, MSB=Temperature level for the hydrolysis shutdown (see MBMSK_HIDRO_*)
  MBF_PAR_PUMP_RELAY_TIME_OFF,        // 0x042E        Time level in minutes or seconds that the dosing pump must remain off when the temporized pump mode is selected. This time level register applies to all pumps except pH. Contains a special time format, see desc for MBMSK_PH_PUMP_TIME, has no upper configuration bit 0x8000
  MBF_PAR_PUMP_RELAY_TIME_ON,         // 0x042F        Time level in minutes or seconds that the dosing pump must remain on when the temporized pump mode is selected. This time level register applies to all pumps except pH. Contains a special time format, see desc for MBMSK_PH_PUMP_TIME, has no upper configuration bit 0x8000
  MBF_PAR_RELAY_PH,                   // 0x0430        Determine what pH regulation configuration the equipment has (see MBV_PAR_RELAY_PH_*)
  MBF_PAR_RELAY_MAX_TIME,             // 0x0431        Maximum amount of time, in seconds, that a dosing pump can operate before rising an alarm signal. The behavior of the system when the dosing time is exceeded is regulated by the type of action stored in the MBF_PAR_RELAY_MODE register.
  MBF_PAR_RELAY_MODE,                 // 0x0432        Behavior of the system when the dosing time is exceeded (see MBMSK_PAR_RELAY_MODE_* and MBV_PAR_RELAY_MODE_*)
  MBF_PAR_RELAY_ACTIVATION_DELAY,     // 0x0433        Delay time in seconds for the pH pump when the measured pH value is outside the allowable pH setpoints. The system internally adds an extra time of 10 seconds to the value stored here. The pump starts the dosing operation once the condition of pH out of valid interval is maintained during the time specified in this register.
  MBF_PAR_TIMER_BLOCK_BASE,           // 0x0434        This block of 180 registers holds the configuration of the system timers. The system has a set of 12 fully configurable timers, each one assigned to a specific function, described below:
  MBF_PAR_TIMER_BLOCK_FILT_INT1=0x0434,//0x0434        Filtration interval 1 (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_FILT_INT2=0x0443,//0x0443        Filtration interval 2 (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_FILT_INT3=0x0452,//0x0452        Filtration interval 3 (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX1_INT2=0x0461,//0x0461        Auxiliary relay 1 - 2. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_LIGHT_INT=0x0470,//0x0470        Lighting interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX2_INT2=0x047F,//0x047F        Auxiliary relay 2 - 2. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX3_INT2=0x048E,//0x048E        Auxiliary relay 3 - 2. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX4_INT2=0x049D,//0x049D        Auxiliary relay 4 - 2. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX1_INT1=0x04AC,//0x04AC        Auxiliary relay 1 - 1. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX2_INT1=0x04BB,//0x04BB        Auxiliary relay 2 - 1. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX3_INT1=0x04CA,//0x04CA        Auxiliary relay 3 - 1. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_TIMER_BLOCK_AUX4_INT1=0x04D9,//0x04D9        Auxiliary relay 4 - 1. interval (15 register - see MBV_TIMER_OFFMB_* for desc)
  MBF_PAR_FILTVALVE_ENABLE=0x04E8,    // 0x04E8        Filter cleaning functionality mode (0=off, 1=Besgo)
  MBF_PAR_FILTVALVE_MODE,             // 0x04E9        Filter cleaning valve timing mode, possible modes: MBV_PAR_CTIMER_ENABLED, MBV_PAR_CTIMER_ALWAYS_ON, MBV_PAR_CTIMER_ALWAYS_OFF
  MBF_PAR_FILTVALVE_GPIO,             // 0x04EA        Relay associated with the filter cleaning function. default AUX2 (value 5)
  MBF_PAR_FILTVALVE_START_LOW,        // 0x04EB        start timestamp of filter cleaning (32-bit)
  MBF_PAR_FILTVALVE_START_HIGH,       // 0x04EC          "
  MBF_PAR_FILTVALVE_PERIOD_MINUTES,   // 0x04ED        Period in minutes between cleaning actions. For example, if a value of 60 is stored in this registry, a cleanup action will occur every hour.
  MBF_PAR_FILTVALVE_INTERVAL,         // 0x04EE        Cleaning action duration in seconds.
  MBF_PAR_FILTVALVE_REMAINING,        // 0x04EF        Time remaining for the current cleaning action in seconds. If this register is 0, it means that there is no cleaning function running. When a cleanup function is started, the contents of the MBF_PAR_FILTVALVE_INTERVAL register are copied to this register, then decremented once per second. The display uses this log to track the progress of the cleaning function.
  MBF_ACTION_COPY_TO_RTC,             // 0x04F0        A write (any value) forces the writing of the RTC time registers MBF_PAR_TIME_LOW (0x0408) and MBF_PAR_TIME_HIGH (0x0409) into the RTC internal microcontroller clock management registers.

  // USER page (0x05xx)                                To make the modification of this register persistent, execute the EEPROM storage procedure described in global register MBF_SAVE_TO_EEPROM.
  MBF_PAR_ION=0x0500,                 // 0x0500        Ionization target production level. The value adjusted in this register must not exceed the value set in the MBF_PAR_ION_NOM factory register.
  MBF_PAR_ION_PR,                     // 0x0501        Amount of time in minutes that the ionization must be activated each time that the filtration starts.
  MBF_PAR_HIDRO,                      // 0x0502        Hydrolisis target production level. When the hydrolysis production is to be set in percent values, this value will contain the percent of production. If the hydrolysis module is set to work in g/h production, this module will contain the desired amount of production in g/h units. The value adjusted in this register must not exceed the value set in the MBF_PAR_HIDRO_NOM factory register.
  MBF_PAR_PH1=0x0504,                 // 0x0504        Higher limit of the pH regulation system. The value set in this register is multiplied by 100. This means that if we want to set a value of 7.5, the numerical content that we must write in this register is 750. This register must be always higher than MBF_PAR_PH2.
  MBF_PAR_PH2,                        // 0x0505        Lower limit of the pH regulation system. The value set in this register is multiplied by 100. This means that if we want to set a value of 7.0, the numerical content that we must write in this register is 700. This register must be always lower than MBF_PAR_PH1.
  MBF_PAR_RX1=0x0508,                 // 0x0508        Set point for the redox regulation system. This value must be in the range of 0 to 1000.
  MBF_PAR_CL1=0x050A,                 // 0x050A        Set point for the chlorine regulation system. The value stored in this register is multiplied by 100. This mean that if we want to set a value of 1.5 ppm, we will have to write a numerical value of 150. This value stored in this register must be in the range of 0 to 1000.
  MBF_PAR_FUNCTION_DEPENDENCY=0x051B, // 0x051B  mask  Specification for the dependency of different functions, such as heating, from external events like FL1 (see MBMSK_FCTDEP_HEATING/MBMSK_DEPENDENCY_*)

  // MISC page (0x06xx)
  MBF_PAR_UICFG_MACHINE=0x0600,       // 0x0600*       Machine type (see MBV_PAR_MACH_* and  kNeoPoolMachineNames[])
  MBF_PAR_UICFG_LANGUAGE,             // 0x0601        Selected language (see MBV_PAR_LANG_*)
  MBF_PAR_UICFG_BACKLIGHT,            // 0x0602        Display backlight (see MBV_PAR_BACKLIGHT_*)
  MBF_PAR_UICFG_SOUND,                // 0x0603  mask  Audible alerts (see MBMSK_PAR_SOUND_*)
  MBF_PAR_UICFG_PASSWORD,             // 0x0604        System password encoded in BCD
  MBF_PAR_UICFG_VISUAL_OPTIONS,       // 0x0605  mask  Stores the different display options for the user interface menus (bitmask). Some bits allow you to hide options that are normally visible (bits 0 to 3) while other bits allow you to show options that are normally hidden (bits 9 to 15)
  MBF_PAR_UICFG_VISUAL_OPTIONS_EXT,   // 0x0606  mask  This register stores additional display options for the user interface menus, see MBMSK_VOE_*
  MBF_PAR_UICFG_MACH_VISUAL_STYLE,    // 0x0607  mask  This register is an expansion of register 0x0600 and 0x0605. The lower part of the register (8 bits LSB) is used to store the type of color selected when in register 0x600 has been specified that the machine is of type "generic". Colors and styles correspond to those listed in record 0x600 MBF_PAR_UICFG_MACHINE. The upper part (8-bit MSB) contains extra bits MBMSK_VS_FORCE_UNITS_GRH, MBMSK_VS_FORCE_UNITS_PERCENTAGE and MBMSK_ELECTROLISIS
  MBF_PAR_UICFG_MACH_NAME_BOLD_0,     // 0x0608        This set of 4 registers stores an ASCIIZ string of up to 8 characters that is used to specify the bold part of the title to be displayed at startup if the specified machine type is generic. Note: only lowercase letters (a-z) can be used.
  MBF_PAR_UICFG_MACH_NAME_BOLD_1,     // 0x0609
  MBF_PAR_UICFG_MACH_NAME_BOLD_2,     // 0x060A
  MBF_PAR_UICFG_MACH_NAME_BOLD_3,     // 0x060B
  MBF_PAR_UICFG_MACH_NAME_LIGHT_0,    // 0x060C        This set of 4 registers stores an ASCIIZ string of up to 8 characters that is used to specify the normal intensity part of the title that will be displayed at startup if the specified machine type is generic. Note: Only lowercase letters (a-z) can be used.
  MBF_PAR_UICFG_MACH_NAME_LIGHT_1,    // 0x060D
  MBF_PAR_UICFG_MACH_NAME_LIGHT_2,    // 0x060E
  MBF_PAR_UICFG_MACH_NAME_LIGHT_3,    // 0x060F
};

// Sugar Valley register constants and bit masks
enum NeoPoolConstAndBitMask {
  // MBF_PH_STATUS
  MBMSK_PH_STATUS_ALARM                   = 0x000F, // PH alarm. The possible alarm values are depending on the regulation model:
      // Valid alarm values for pH regulation with acid and base:
  MBV_PH_ACID_BASE_ALARM0 = 0,                      // no alarm
  MBV_PH_ACID_BASE_ALARM1 = 1,                      // pH too high; the pH value is 0.8 points higher than the setpoint value set in PH1
  MBV_PH_ACID_BASE_ALARM2 = 2,                      // pH too low: the pH value is 0.8 points lower than the set point value set in PH2
  MBV_PH_ACID_BASE_ALARM3 = 3,                      // pH pump (acid or base, it does not matter) has exceeded the working time set by the MBF_PAR_RELAY_PH_MAX_TIME parameter and has stopped.
  MBV_PH_ACID_BASE_ALARM4 = 4,                      // pH higher than the set point indicated in PH1
  MBV_PH_ACID_BASE_ALARM5 = 5,                      // pH lower than the set point indicated in PH2
      // Valid alarm values for pH regulation with acid only:
  MBV_PH_ACID_ALARM0 = 0,                           // no alarm
  MBV_PH_ACID_ALARM1 = 1,                           // pH too high; the pH value is 0.8 points higher than the setpoint value set in PH1
  MBV_PH_ACID_ALARM2 = 2,                           // pH too low: the pH value is 0.8 points lower than the setpoint value set in PH1
  MBV_PH_ACID_ALARM3 = 3,                           // pH pump acid has exceeded the working time set by the MBF_PAR_RELAY_PH_MAX_TIME parameter and has stopped.
  MBV_PH_ACID_ALARM4 = 4,                           // pH higher than the setpoint indicated in PH1 by 0.1
  MBV_PH_ACID_ALARM5 = 5,                           // pH lower than the set point indicated in PH1 by 0.3
      // Valid alarm values for pH regulation with base only:
  MBV_PH_BASE_ALARM0 = 0,                           // no alarm
  MBV_PH_BASE_ALARM1 = 1,                           // pH too high; the pH value is 0.8 points higher than the set point value set in PH2
  MBV_PH_BASE_ALARM2 = 2,                           // pH too low: the pH value is 0.8 points lower than the set point value set in PH2
  MBV_PH_BASE_ALARM3 = 3,                           // pH pump has exceeded the working time set by the MBF_PAR_RELAY_PH_MAX_TIME parameter and has stopped.
  MBV_PH_BASE_ALARM4 = 4,                           // pH higher than the set point indicated in PH2 by 0.1
  MBV_PH_BASE_ALARM5 = 5,                           // pH lower than the set point indicated in PH2 by 0.3

  MBMSK_PH_STATUS_CTRL_BY_FL              = 0x0400, // Control status of the pH module by flow detection (if enabled by MBF_PAR_HIDRO_ION_CAUDAL)
  MBMSK_PH_STATUS_ACID_PUMP_ACTIVE        = 0x0800, // Acid pH pump relay on (pump on)
  MBMSK_PH_STATUS_BASE_PUMP_ACTIVE        = 0x1000, // Base pH Pump Relay On (Pump On)
  MBMSK_PH_STATUS_CTRL_ACTIVE             = 0x2000, // Active pH control module and controlling pumps
  MBMSK_PH_STATUS_MEASURE_ACTIVE          = 0x4000, // Active pH measurement module and making measurements. If this bit is at 1, the pH bar should be displayed.
  MBMSK_PH_STATUS_MODULE_PRESENT          = 0x8000, // Detected pH measurement module

  // MBF_RX_STATUS
  MBMSK_RX_STATUS_RX_PUMP_ACTIVE          = 0x1000, // Redox pump relay on (pump activated)
  MBMSK_RX_STATUS_CTRL_ACTIVE             = 0x2000, // Active Redox control module and controlling pump
  MBMSK_RX_STATUS_MEASURE_ACTIVE          = 0x4000, // Active Redox measurement module and performing measurements. If this bit is at 1, the Redox bar should be displayed on the screen.
  MBMSK_RX_STATUS_MODULE_PRESENT          = 0x8000, // Redox measurement module detected in the system

  // MBF_CL_STATUS
  MBMSK_CL_STATUS_CHLORINE_FLOW           = 0x0008, // Chlorine Probe Flow Sensor. This sensor is built into the probe itself and serves to detect whether there is water passing through the chlorine measurement probe. In case the sensor is at 0, the chlorine measurement will not be valid.
  MBMSK_CL_STATUS_CL_PUMP_ACTIVE          = 0x1000, // Chlorine pump relay on (pump on)
  MBMSK_CL_STATUS_CTRL_ACTIVE             = 0x2000, // Active chlorine control module and controlling pump
  MBMSK_CL_STATUS_MEASURE_ACTIVE          = 0x4000, // Active chlorine measurement module and taking measurements. If this bit is 1, the chlorine bar should be displayed on the screen.
  MBMSK_CL_STATUS_MODULE_PRESENT          = 0x8000, // Chlorine measurement module detected in the system

  // MBF_CD_STATUS
  MBMSK_CD_STATUS_RX_PUMP_ACTIVE          = 0x1000, // Conductivity pump relay on (pump active)
  MBMSK_CD_STATUS_CTRL_ACTIVE             = 0x2000, // Active conductivity control module and controlling pump
  MBMSK_CD_STATUS_MEASURE_ACTIVE          = 0x4000, // Active conductivity measurement module and making measurements. If this bit is 1, the conditionality bar should be displayed on the screen.
  MBMSK_CD_STATUS_MODULE_PRESENT          = 0x8000, // Conductivity measurement module detected in the system

  // MBF_ION_STATUS
  MBMSK_ION_STATUS_ON_TARGET              = 0x0001, // On Target - the system has reached the set point.
  MBMSK_ION_STATUS_LOW                    = 0x0002, // Low - Ionization cannot reach the set point.
  MBMSK_ION_STATUS_RESERVED               = 0x0004,
  MBMSK_ION_STATUS_PROGTIME_EXCEEDED      = 0x0008, // Pr off - The programmed ionization time has been exceeded
  MBMSK_ION_STATUS_POLOFF                 = 0x1000, // Ion Pol off - Ionization in dead time
  MBMSK_ION_STATUS_POL1                   = 0x2000, // Ion Pol 1 - Ionization working in polarization 1
  MBMSK_ION_STATUS_POL2                   = 0x4000, // Ion Pol 2 - Ionization working in polarization 2

  // MBF_HIDRO_STATUS
  MBMSK_HIDRO_STATUS_ON_TARGET            = 0x0001, // On Target - the system has reached the set point.
  MBMSK_HIDRO_STATUS_LOW                  = 0x0002, // Low - Hydrolysis cannot reach the set point.
  MBMSK_HIDRO_STATUS_RESERVED             = 0x0004,
  MBMSK_HIDRO_STATUS_FL1                  = 0x0008, // Flow - Hydrolysis cell flow indicator (FL1)
  MBMSK_HIDRO_STATUS_COVER                = 0x0010, // Cover - Cover input activated
  MBMSK_HIDRO_STATUS_MODULE_ACTIVE        = 0x0020, // Active - Active Module hydrolysis (hidroEnable)
  MBMSK_HIDRO_STATUS_CTRL_ACTIVE          = 0x0040, // Control - Hydrolysis module working with regulation (hydroControlEnable)
  MBMSK_HIDRO_STATUS_REDOX_ENABLED        = 0x0080, // Redox enable - Activation of hydrolysis by the redox module
  MBMSK_HIDRO_STATUS_SHOCK_ENABLED        = 0x0100, // Hydro shock enabled - Chlorine shock mode enabled
  MBMSK_HIDRO_STATUS_FL2                  = 0x0200, // FL2 - Chlorine probe flow indicator, if present
  MBMSK_HIDRO_STATUS_ENABLED_BY_CHLORINE  = 0x0400, // Cl enable - Activation of hydrolysis by the chlorine module
  MBMSK_HIDRO_STATUS_POLOFF               = 0x1000, // Ion Pol off - Ionization in dead time
  MBMSK_HIDRO_STATUS_POL1                 = 0x2000, // Ion Pol 1 - Ionization working in polarization 1
  MBMSK_HIDRO_STATUS_POL2                 = 0x4000, // Ion Pol 2 - Ionization working in polarization 2

  // MBF_RELAY_STATE
  MBMSK_RELAY_STATE1                      = 0x0001, // Relay 1 state (1 on; 0 off) (normally assigned to ph)
  MBMSK_RELAY_STATE2                      = 0x0002, // Relay 2 state (1 on; 0 off) (normally assigned to filtering)
  MBMSK_RELAY_STATE3                      = 0x0004, // Relay 3 status (1 on; 0 off) (normally assigned to lighting)
  MBMSK_RELAY_STATE4                      = 0x0008, // Relay 4 status (1 on; 0 off)
  MBMSK_RELAY_STATE5                      = 0x0010, // Relay 5 status (1 on; 0 off)
  MBMSK_RELAY_STATE6                      = 0x0020, // Relay 6 status (1 on; 0 off)
  MBMSK_RELAY_STATE7                      = 0x0040, // Relay 7 status (1 on; 0 off)
  MBMSK_RELAY_FILTSPEED_LOW               = 0x0100, // Filtration low speed
  MBMSK_RELAY_FILTSPEED_MID               = 0x0200, // Filtration mid speed
  MBMSK_RELAY_FILTSPEED_HIGH              = 0x0400, // Filtration high speed

  // MBF_NOTIFICATION
  MBMSK_NOTIF_MODBUS_CHANGED              = 0x0001,
  MBMSK_NOTIF_GLOBAL_CHANGED              = 0x0002,
  MBMSK_NOTIF_FACTORY_CHANGED             = 0x0004,
  MBMSK_NOTIF_INSTALLER_CHANGED           = 0x0008,
  MBMSK_NOTIF_USER_CHANGED                = 0x0010,
  MBMSK_NOTIF_MISC_CHANGED                = 0x0020,

  // MBF_PAR_MODEL
  MBMSK_MODEL_ION                         = 0x0001, // The equipment includes ionization control
  MBMSK_MODEL_HIDRO                       = 0x0002, // The equipment includes hydrolysis or electrolysis
  MBMSK_MODEL_UV                          = 0x0004, // The equipment includes disinfection control by ultraviolet lamp
  MBMSK_MODEL_SALINITY                    = 0x0008, // The equipment includes measurement of salinity (Fanless equipment only)

  // MBF_PAR_HIDRO_FLOW_SIGNAL
  MBV_PAR_HIDRO_FLOW_SIGNAL_STD           = 0,      // Standard detection based on conduction between an auxiliary electrode and either of the two electrodes of the cell.
  MBV_PAR_HIDRO_FLOW_SIGNAL_ALWAYS_ON     = 1,      // Always connected. This value allows forcing the generation of the hydrolysis current even if no flow is detected in the sensor.
  MBV_PAR_HIDRO_FLOW_SIGNAL_PADDLE        = 2,      // Detection based on the paddle switch, associated with the FL1 input
  MBV_PAR_HIDRO_FLOW_SIGNAL_PADDLE_AND_STD= 3,      // Detection based on the paddle switch, associated with the FL1 input, and the standard detector. The system will understand that there is flow when both elements detect flow. If either one opens, the hydrolysis will stop.
  MBV_PAR_HIDRO_FLOW_SIGNAL_PADDLE_OR_STD = 4,      // Detection based on the paddle switch, associated with the FL1 input, or the standard detector. The system will understand that there is flow when either of the two elements detects flow. Hydrolysis will stop only if both detectors detect no flow.

  // MBF_PAR_HIDRO_ION_CAUDAL
  MBMSK_HIDRO_ION_CAUDAL_FL1_CTRL         = 0x0001, // If the FL1 signal is detected to be inactive, the actuation of the different elements of the system is disabled.
  MBMSK_HIDRO_ION_CAUDAL_FL2_CTRL         = 0x0002, // If the FL2 signal is detected to be inactive, the actuation of the different elements of the system is disabled.
  MBMSK_HIDRO_ION_CAUDAL_FULL_CL_HIDRO_CTRL=0x0004, // If there is a chlorine module installed and it is detected that its flow sensor is inactive, the action of the different elements of the system is disabled.
  MBMSK_HIDRO_ION_CAUDAL_SLAVE            = 0x0008, // The value of the slave input is taken and if it is inactive, the action of the different elements of the system is disabled.
  MBMSK_HIDRO_ION_CAUDAL_PADDLE_SWITCH    = 0x0010,
  MBMSK_HIDRO_ION_CAUDAL_PADDLE_SWITCH_INV= 0x0020,
  MBMSK_HIDRO_ION_CAUDAL_INVERSION        = 0x0080, // This bit determines if active means open or closed for the input electrical signals, and allows to reverse the operation for example to implement a paddle switch that closes when there is no flow.

  // MBF_PAR_FILT_MODE
  MBV_PAR_FILT_MANUAL                     = 0,      // This mode allows to turn the filtration (and all other systems that depend on it) on and off manually.
  MBV_PAR_FILT_AUTO                       = 1,      // This mode allows filtering to be turned on and off according to the settings of the TIMER1, TIMER2 and TIMER3 timers.
  MBV_PAR_FILT_HEADING                    = 2,      // This mode is similar to the AUTO mode, but includes setting the temperature for the heating function. This mode is activated only if the MBF_PAR_HEATING_MODE register is at 1 and there is a heating relay assigned.
  MBV_PAR_FILT_SMART                      = 3,      // This filtration mode adjusts the pump operating times depending on the temperature. This mode is activated only if the MBF_PAR_TEMPERATURE_ACTIVE register is at 1.
  MBV_PAR_FILT_INTELLIGENT                = 4,      // This mode performs an intelligent filtration process in combination with the heating function. This mode is activated only if the MBF_PAR_HEATING_MODE register is at 1 and there is a heating relay assigned.
  MBV_PAR_FILT_BACKWASH                   = 13,     // This filter mode is started when the backwash operation is activated.

  // MBF_PAR_UV_MODE
  MBV_PAR_UV_MODE0                        = 0,      // UV is switched off and it will not turn on when filtration starts
  MBV_PAR_UV_MODE1                        = 1,      // UV is switched on and it will turn on when filtration starts. Time counter for the UV lamp will be incremented.

  // MBF_PAR_UV_HIDE_WARN
  MBMSK_UV_HIDE_WARN_CLEAN                = 0x0001,
  MBMSK_UV_HIDE_WARN_REPLACE              = 0x0002,

  // MBF_PAR_PH_PUMP_REP_TIME_ON
  MBMSK_PH_PUMP_TIME                      = 0x7FFF, // Time level for the pump: The time level has a special coding format. It can cover periods of 1 to 180 seconds with 1 second granularity and from 3 to 999 minutes with 1 minute granularity. f the value is set to 30 for example, a 30 second time will be considered. If we have the value 200, we will have an on time of (200-180+3) = 23 minutes.
  MBMSK_PH_PUMP_REPETITIVE                = 0x8000, // pH pump in repetitive mode (1)

  // MBF_PAR_HIDRO_COVER_ENABLE
  MBMSK_HIDRO_COVER_ENABLE                = 0x0001, // If enabled, the hydrolysis/electrolysis production will be reduced by a given percentage specified in the lower half of the MBF_PAR_HIDRO_COVER_REDUCTION register when the cover input is detected.
  MBMSK_HIDRO_TEMPERATURE_SHUTDOWN_ENABLE = 0x0002, // If enabled, the hydrolysis/electrolysis production will stop when the temperature falls below a given temperature threshold specified in higher part of the MBF_PAR_HIDRO_COVER_REDUCTION register.
  // MBF_PAR_HIDRO_COVER_REDUCTION
  MBMSK_HIDRO_COVER_REDUCTION             = 0x00FF, // Percentage for the cover reduction
  MBMSK_HIDRO_SHUTDOWN_TEMPERATURE        = 0xFF00, // Temperature level for the hydrolysis shutdown

  // MBF_PAR_RELAY_PH
  MBV_PAR_RELAY_PH_ACID_AND_BASE          = 0,      // The equipment works with an acid and base pump
  MBV_PAR_RELAY_PH_ACID_ONLY              = 1,      // The equipment works with acid pump only
  MBV_PAR_RELAY_PH_BASE_ONLY              = 2,      // The equipment works with base pump only

  //MBF_PAR_RELAY_MODE
  MBMSK_PAR_RELAY_MODE_PH                 = 0x0003, // Behavior for the pH module (MBV_PAR_RELAY_MODE_*)
  MBMSK_PAR_RELAY_MODE_RX                 = 0x000C, // Behavior for the Redox module (MBV_PAR_RELAY_MODE_*)
  MBMSK_PAR_RELAY_MODE_CL                 = 0x0030, // Behavior for the Chlorine module (MBV_PAR_RELAY_MODE_*)
  MBMSK_PAR_RELAY_MODE_CD                 = 0x00C0, // Behavior for the Conductivity module (MBV_PAR_RELAY_MODE_*)
  MBMSK_PAR_RELAY_MODE_TURBIDITY          = 0x0300, // Behavior for the Turbidity module (MBV_PAR_RELAY_MODE_*)
  MBV_PAR_RELAY_MODE_IGNORE               = 0,      // The system simply ignores the alarm and dosing continues.
  MBV_PAR_RELAY_MODE_SHOW_ONLY            = 1,      // The system only shows the alarm on screen, but the dosing continues.
  MBV_PAR_RELAY_MODE_SHOW_AND_STOP        = 2,      // The system shows the alarm on screen and stops the dosing pump

  // MBF_PAR_FUNCTION_DEPENDENCY
  MBMSK_FCTDEP_HEATING                    = 0x0007, // Heating function dependency:
  MBMSK_DEPENDENCY_FL1_PADDLE             = 0x0001,
  MBMSK_DEPENDENCY_FL2                    = 0x0002,
  MBMSK_DEPENDENCY_SLAVE                  = 0x0004,

  // MBF_PAR_UICFG_MACHINE
  MBV_PAR_MACH_NONE                       = 0,      // No machine assigned
  MBV_PAR_MACH_HIDROLIFE                  = 1,      // Hidrolife (yellow)
  MBV_PAR_MACH_AQUASCENIC                 = 2,      // Aquascenic (blue)
  MBV_PAR_MACH_OXILIFE                    = 3,      // Oxilife (green)
  MBV_PAR_MACH_BIONET                     = 4,      // Bionet (light blue)
  MBV_PAR_MACH_HIDRONISER                 = 5,      // Hidroniser (red)
  MBV_PAR_MACH_UVSCENIC                   = 6,      // UVScenic (lilac)
  MBV_PAR_MACH_STATION                    = 7,      // Station (orange)
  MBV_PAR_MACH_BRILIX                     = 8,      // Brilix
  MBV_PAR_MACH_GENERIC                    = 9,      // Generic
  MBV_PAR_MACH_BAYROL                     = 10,     // Bayrol
  MBV_PAR_MACH_HAY                        = 11,     // Hay

  // MBF_PAR_UICFG_LANGUAGE
  MBV_PAR_LANG_SPANISH                    = 0,
  MBV_PAR_LANG_ENGLISH                    = 1,
  MBV_PAR_LANG_FRENCH                     = 2,
  MBV_PAR_LANG_GERMAN                     = 3,
  MBV_PAR_LANG_ITALIAN                    = 4,
  MBV_PAR_LANG_TURKISH                    = 5,
  MBV_PAR_LANG_CZECH                      = 6,
  MBV_PAR_LANG_PORTUGUESE                 = 7,
  MBV_PAR_LANG_DUTCH                      = 8,
  MBV_PAR_LANG_POLISH                     = 9,
  MBV_PAR_LANG_HUNGARIAN                  = 10,
  MBV_PAR_LANG_RUSSIAN                    = 11,

  // MBF_PAR_UICFG_BACKLIGHT
  MBV_PAR_BACKLIGHT_15SEC                 = 0,      // Backlight off after 15 sec
  MBV_PAR_BACKLIGHT_30SEC                 = 1,      // Backlight off after 30 sec
  MBV_PAR_BACKLIGHT_60SEC                 = 2,      // Backlight off after 60 sec
  MBV_PAR_BACKLIGHT_5MIN                  = 3,      // Backlight off after 5 min
  MBV_PAR_BACKLIGHT_ON                    = 4,      // Backlight never turns off

  // MBF_PAR_TIMER_BLOCK_BASE
  MBV_TIMER_OFFMB_TIMER_ENABLE            = 0,      // Enables the timer function in the selected working mode, see MBF_PAR_CTIMER_*
  MBV_TIMER_OFFMB_TIMER_ON                = 1,      // Timer start (32-bit timestamp, LSB first)
  MBV_TIMER_OFFMB_TIMER_OFF               = 3,      // Timer stop (32-bit timestamp, LSB first) - not used
  MBV_TIMER_OFFMB_TIMER_PERIOD            = 5,      // Time in seconds between starting points (32-bit, LSB first), e.g. 86400 means daily
  MBV_TIMER_OFFMB_TIMER_INTERVAL          = 7,      // Time in seconds that the timer has to run when started (32-bit, LSB first)
  MBV_TIMER_OFFMB_TIMER_COUNTDOWN         = 9,      // Time remaining in seconds for the countdown mode (32-bit, LSB first)
  MBV_TIMER_OFFMB_TIMER_FUNCTION          = 11,     // Function assigned to this timer, see MBV_PAR_CTIMER_FCT_*
  MBV_TIMER_OFFMB_TIMER_WORK_TIME         = 13,     // Number of seconds that the timer has been operating
  // MBV_TIMER_OFFMB_TIMER_ENABLE working modes:
  MBV_PAR_CTIMER_DISABLE                  = 0,      // Timer disabled
  MBV_PAR_CTIMER_ENABLED                  = 1,      // Timer enabled and independent
  MBV_PAR_CTIMER_ENABLED_LINKED           = 2,      // Timer enabled and linked to relay from timer 0
  MBV_PAR_CTIMER_ALWAYS_ON                = 3,      // Relay assigned to this timer always on
  MBV_PAR_CTIMER_ALWAYS_OFF               = 4,      // Relay assigned to this timer always off
  MBV_PAR_CTIMER_COUNTDOWN                = 5,      // Timer in countdown mode
  // MBV_TIMER_OFFMB_TIMER_FUNCTION codes:
  MBV_PAR_CTIMER_FCT_FILTRATION           = 0x0001, // Filtration function of the system
  MBV_PAR_CTIMER_FCT_LIGHTING             = 0x0002, // Lighting function of the system
  MBV_PAR_CTIMER_FCT_HEATING              = 0x0004, // Heating function of the system
  MBV_PAR_CTIMER_FCT_AUXREL1              = 0x0100, // Auxiliary function assigned to relay 1
  MBV_PAR_CTIMER_FCT_AUXREL2              = 0x0200, // Auxiliary function assigned to relay 2
  MBV_PAR_CTIMER_FCT_AUXREL3              = 0x0400, // Auxiliary function assigned to relay 3
  MBV_PAR_CTIMER_FCT_AUXREL4              = 0x0800, // Auxiliary function assigned to relay 4
  MBV_PAR_CTIMER_FCT_AUXREL5              = 0x1000, // Auxiliary function assigned to relay 5
  MBV_PAR_CTIMER_FCT_AUXREL6              = 0x2000, // Auxiliary function assigned to relay 6
  MBV_PAR_CTIMER_FCT_AUXREL7              = 0x4000, // Auxiliary function assigned to relay 7

  // MBF_PAR_UICFG_SOUND
  MBMSK_PAR_SOUND_CLICK                   = 0x0001, // Click sounds every time a key is pressed
  MBMSK_PAR_SOUND_POPUP                   = 0x0002, // Sound plays each time a pop-up message appears
  MBMSK_PAR_SOUND_ALERTS                  = 0x0004, // An alarm sounds when there is an alert on the equipment (AL3)
  MBMSK_PAR_SOUND_FILTRATION              = 0x0008, // Audible warning every time the filtration is started

  // MBF_PAR_UICFG_VISUAL_OPTIONS
  MBMSK_HIDE_TEMPERATURE                  = 0x0001, // Hide temperature measurement from main menu
  MBMSK_HIDE_FILTRATION                   = 0x0002, // Hide filter status from main menu
  MBMSK_HIDE_LIGHTING                     = 0x0004, // Hide lighting status from main menu
  MBMSK_HIDE_AUX_RELAYS                   = 0x0008, // Hide auxiliary relay status from main menu.
  MBMSK_VO_HIDE_EXTRA_REGS                = 0x0010, // Hide the option to adjust additional registers in the installer menu
  MBMSK_VO_HIDE_RELAY_CONFIG              = 0x0020, // Hide the relay configuration option in the installer menu.
  MBMSK_VO_SLOW_FILTER_HIDRO_LEVEL        = 0x0040, // This option enables the slow hydrolysis level filtering option when the pH module is installed. This is especially important when the acid / base dosing is done very close to the hydrolysis probe.
  MBMSK_VO_HIDE_SALINITY_MAIN_WINDOW      = 0x0080, // Hides the salinity measurement from main screen.
  MBMSK_VO_SHOW_SPECIAL_REGS              = 0x0100, // Displays the special register set configuration menu in the installer menu.
  MBMSK_SHOW_HID_SHUTDOWN_BY_TEMPERATURE  = 0x0200, // Displays the option to turn off hydrolysis by temperature.
  MBMSK_SHOW_CELL_SELECTION               = 0x0400, // Enables access to the cell selection menu from the service menu option of the configuration menu.
  MBMSK_SHOW_PUMP_TYPE                    = 0x0800, // Displays the option for selecting the type of filtration pump (normal, three speeds, etc.).
  MBMSK_SHOW_QUICK_MENU                   = 0x1000, // Displays the quick access menu instead of the conventional menu, when the SET key is pressed from the main display screen. Filtration (normal, three speeds, etc).
  MBMSK_SHOW_OXI_MAIN_DATA_SCREEN         = 0x2000, // Displays main screen shown with a particular style called OXI
  MBMSK_SHOW_INSTALLER_MENU               = 0x4000, // Shows access to the installer menu in the main menu without the need for a password.
  MBMSK_SHOW_FACTORY_MENU                 = 0x8000, // Shows access to the factory menu in the main menu without the need for a password.

  // MBF_PAR_UICFG_VISUAL_OPTIONS_EXT
  MBMSK_VOE_SHOW_PNEUMATIC_VALVE          = 0x0001, // Shows the pneumatic valve
  MBMSK_VOE_HIDE_AUX_REL_DEPENDENCY       = 0x0002, // Hides the auxiliary relay dependency
  MBMSK_VOE_SHOW_BESGO_NAME               = 0x0004, // Show “Besgo” instead of “Pneumatic” for the pneumatic valve titles.

  // MBF_PAR_UICFG_MACH_VISUAL_STYLE
  MBMSK_VS_FORCE_UNITS_GRH                = 0x2000, // Display the hydrolysis/electrolysis in units of grams per hour (gr/h).
  MBMSK_VS_FORCE_UNITS_PERCENTAGE         = 0x4000, // Display the hydrolysis/electrolysis in percentage units (%).
  MBMSK_ELECTROLISIS                      = 0x8000, // Display the word electrolysis instead of hydrolysis in generic mode.
};

#include <TasmotaModbus.h>
TasmotaModbus *NeoPoolModbus;

bool neopool_active = false;
volatile bool neopool_poll = true;

uint8_t neopool_read_state = 0;
uint8_t neopool_send_retry = 0;
uint8_t neopool_failed = 0;
uint8_t neopool_failed_count = 0;
#ifdef NEOPOOL_OPTIMIZE_READINGS
bool neopool_first_read = true;
#endif  // NEOPOOL_OPTIMIZE_READINGS
bool neopool_error = true;

// Modbus register set to read
struct NEOPOOL_REG {
    const uint16_t addr;
    const uint16_t cnt;
    uint16_t *data;
} NeoPoolReg[] = {
    {MBF_ION_CURRENT,       MBF_NOTIFICATION      - MBF_ION_CURRENT + 1, nullptr},
    {MBF_PAR_VERSION,       MBF_PAR_MODEL         - MBF_PAR_VERSION + 1, nullptr},
    {MBF_PAR_TIME_LOW,      MBF_PAR_FILT_GPIO     - MBF_PAR_TIME_LOW + 1, nullptr},
    {MBF_PAR_UICFG_MACHINE, MBF_PAR_UICFG_MACHINE - MBF_PAR_UICFG_MACHINE + 1, nullptr}
};

// NeoPool modbus function errors
#define NEOPOOL_OK                    0
#define NEOPOOL_ERROR_RW_DATA         1
#define NEOPOOL_ERROR_TIMEOUT         2
#define NEOPOOL_ERROR_OUT_OF_MEM      3
#define NEOPOOL_ERROR_DEADLOCK        4


#define D_NEOPOOL_NAME "NeoPool"

const char kNeoPoolMachineNames[] PROGMEM =
  D_NEOPOOL_MACH_NONE "|"
  D_NEOPOOL_MACH_HIDROLIFE "|"
  D_NEOPOOL_MACH_AQUASCENIC "|"
  D_NEOPOOL_MACH_OXILIFE "|"
  D_NEOPOOL_MACH_BIONET "|"
  D_NEOPOOL_MACH_HIDRONISER "|"
  D_NEOPOOL_MACH_UVSCENIC "|"
  D_NEOPOOL_MACH_STATION "|"
  D_NEOPOOL_MACH_BRILIX "|"
  D_NEOPOOL_MACH_GENERIC "|"
  D_NEOPOOL_MACH_BAYROL "|"
  D_NEOPOOL_MACH_HAY
  ;

const char kNeoPoolFiltrationMode[] PROGMEM =
  D_NEOPOOL_FILTRATION_MANUAL "|"
  D_NEOPOOL_FILTRATION_AUTO "|"
  D_NEOPOOL_FILTRATION_HEATING "|"
  D_NEOPOOL_FILTRATION_SMART "|"
  D_NEOPOOL_FILTRATION_INTELLIGENT "|"
  D_NEOPOOL_FILTRATION_BACKWASH
  ;

const char kNeoPoolFiltrationSpeed[] PROGMEM =
  D_NEOPOOL_FILTRATION_NONE "|"
  D_NEOPOOL_FILTRATION_SLOW "|"
  D_NEOPOOL_FILTRATION_MEDIUM "|"
  D_NEOPOOL_FILTRATION_FAST
  ;

const char kNeoPoolpHAlarms[] PROGMEM =
  D_NEOPOOL_SETPOINT_OK "|"
  D_NEOPOOL_PH_HIGH "|"
  D_NEOPOOL_PH_LOW "|"
  D_NEOPOOL_PUMP_TIME_EXCEEDED
  ;

#ifndef D_STR_BIT
#define D_STR_BIT "Bit"
#endif  // D_STR_BIT

#define NEOPOOL_FMT_PH        "%-2_f"
#define NEOPOOL_FMT_RX        "%-2_f"
#define NEOPOOL_FMT_CL        "%-2_f"
#define NEOPOOL_FMT_CD        "%d"
#define NEOPOOL_FMT_ION       "%1_f"
#define NEOPOOL_FMT_HIDRO     "%1_f"

#define HTTP_SNS_NEOPOOL_FLAGS "<span style=\"font-size:small\">%s</span>"
const char HTTP_SNS_NEOPOOL_TIME[]             PROGMEM = "{s}%s " D_NEOPOOL_TIME            "{m}%s"                                                               "{e}";
const char HTTP_SNS_NEOPOOL_PH[]               PROGMEM = "{s}%s " D_PH                      "{m}"  NEOPOOL_FMT_PH     " "  "<span%s>&nbsp;%s&nbsp;</span>"        "{e}";
const char HTTP_SNS_NEOPOOL_REDOX[]            PROGMEM = "{s}%s " D_NEOPOOL_REDOX           "{m}"  NEOPOOL_FMT_RX     " "  D_UNIT_MILLIVOLT                       "{e}";
const char HTTP_SNS_NEOPOOL_PPM_CHLORINE[]     PROGMEM = "{s}%s " D_NEOPOOL_CHLORINE        "{m}"  NEOPOOL_FMT_CL     " "  D_UNIT_PARTS_PER_MILLION               "{e}";
const char HTTP_SNS_NEOPOOL_CONDUCTIVITY[]     PROGMEM = "{s}%s " D_NEOPOOL_CONDUCTIVITY    "{m}"  NEOPOOL_FMT_CD     " "  D_UNIT_PERCENT                         "{e}";
const char HTTP_SNS_NEOPOOL_IONIZATION[]       PROGMEM = "{s}%s " D_NEOPOOL_IONIZATION      "{m}"  NEOPOOL_FMT_ION    " "  "%s%s"                                 "{e}";
const char HTTP_SNS_NEOPOOL_HYDROLYSIS[]       PROGMEM = "{s}%s " D_NEOPOOL_HYDROLYSIS      "{m}"  NEOPOOL_FMT_HIDRO  " "  D_UNIT_PERCENT HTTP_SNS_NEOPOOL_FLAGS  "{e}";
const char HTTP_SNS_NEOPOOL_FILT_MODE[]        PROGMEM = "{s}%s " D_NEOPOOL_FILT_MODE       "{m}%s"                                                               "{e}";
const char HTTP_SNS_NEOPOOL_RELAY[]            PROGMEM = "{s}%s " D_NEOPOOL_RELAY " %d %s"  "{m}%s"                                                               "{e}";


void NeoPool250ms(void)              // Every 250 mSec
{
  if (!neopool_poll) {
    return;
  };

  bool data_ready = NeoPoolModbus->ReceiveReady();

  if (data_ready && nullptr != NeoPoolReg[neopool_read_state].data) {
    uint8_t *buffer = (uint8_t *)malloc(5+(NeoPoolReg[neopool_read_state].cnt)*2);

    if( nullptr != buffer) {
      uint8_t error = NeoPoolModbus->ReceiveBuffer(buffer, NeoPoolReg[neopool_read_state].cnt);  // cnt x 16bit register

      if (0 == error) {
        neopool_failed_count = 0;
        neopool_error = false;
        for(uint32_t i=0; i<NeoPoolReg[neopool_read_state].cnt; i++) {
          NeoPoolReg[neopool_read_state].data[i] = (buffer[i*2+3] << 8) | buffer[i*2+4];
        }
      }
#ifdef DEBUG_TASMOTA_SENSOR
      else {
        AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("NEO: modbus receive error %d"), error);
      }
#endif  // DEBUG_TASMOTA_SENSOR
      free(buffer);
    }
#ifdef DEBUG_TASMOTA_SENSOR
    else {
        AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("NEO: modbus block 0x%04X - 0x%04X skipped"), NeoPoolReg[neopool_read_state].addr, NeoPoolReg[neopool_read_state].addr+NeoPoolReg[neopool_read_state].cnt);
    }
#endif  // DEBUG_TASMOTA_SENSOR

    ++neopool_read_state %= ARRAY_SIZE(NeoPoolReg);
#ifdef NEOPOOL_OPTIMIZE_READINGS
    if (0 == neopool_read_state) {
      neopool_first_read = false;
    }
#endif  // NEOPOOL_OPTIMIZE_READINGS
  }

  if (nullptr != NeoPoolReg[neopool_read_state].data) {
    if (0 == neopool_send_retry || data_ready) {
      neopool_send_retry = (1000/250)+1;
#ifdef NEOPOOL_OPTIMIZE_READINGS
      // optimize register block reads by attend to MBF_NOTIFICATION bits
      if ( neopool_first_read || 0x0100 == (NeoPoolReg[neopool_read_state].addr & 0x0700) ||
            (NeoPoolGetData(MBF_NOTIFICATION) & (1 << (NeoPoolReg[neopool_read_state].addr >> 8)-1))) {
#endif  // NEOPOOL_OPTIMIZE_READINGS
#ifdef DEBUG_TASMOTA_SENSOR
        AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("NEO: modbus send(%d, %d, 0x%04X, %d)"), NEOPOOL_MODBUS_ADDRESS, NEOPOOL_READ_REGISTER, NeoPoolReg[neopool_read_state].addr, NeoPoolReg[neopool_read_state].cnt);
#endif  // DEBUG_TASMOTA_SENSOR
        NeoPoolModbus->Send(NEOPOOL_MODBUS_ADDRESS, NEOPOOL_READ_REGISTER, NeoPoolReg[neopool_read_state].addr, NeoPoolReg[neopool_read_state].cnt);
#ifdef NEOPOOL_OPTIMIZE_READINGS
      }
      else {
        // search next addr block having notification
        while( (NeoPoolReg[neopool_read_state].addr & 0x0F00) != 0x100 || (NeoPoolGetData(MBF_NOTIFICATION) & (1 << (NeoPoolReg[neopool_read_state].addr >> 8)-1)) ) {
#ifdef DEBUG_TASMOTA_SENSOR
          AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("NEO: notify 0x%04X - addr block 0x%04X ignored"), NeoPoolGetData(MBF_NOTIFICATION), NeoPoolReg[neopool_read_state].addr);
#endif  // DEBUG_TASMOTA_SENSOR
          ++neopool_read_state %= ARRAY_SIZE(NeoPoolReg);
          // neopool_read_state++;
          // if (ARRAY_SIZE(NeoPoolReg) <= neopool_read_state) {
          //   neopool_read_state = 0;
          // }
        }
      }
#endif  // NEOPOOL_OPTIMIZE_READINGS
    }
    else {
      if (1 == neopool_send_retry) {
        neopool_failed_count++;
        if (neopool_failed_count > 2) {
          neopool_failed_count = 0;
          neopool_error = true;
          NeoPoolInitData();
        }
      }
      neopool_send_retry--;
    }
  }
}

/*********************************************************************************************/

void NeoPoolInit(void) {
  neopool_active = false;
  if (PinUsed(GPIO_NEOPOOL_RX) && PinUsed(GPIO_NEOPOOL_TX)) {
    NeoPoolModbus = new TasmotaModbus(Pin(GPIO_NEOPOOL_RX), Pin(GPIO_NEOPOOL_TX));
    uint8_t result = NeoPoolModbus->Begin(NEOPOOL_MODBUS_SPEED);
    if (result) {
      if (2 == result) {
          ClaimSerial();
      }
#ifdef NEOPOOL_OPTIMIZE_READINGS
      neopool_first_read = true;
#endif  // NEOPOOL_OPTIMIZE_READINGS
      if (NeoPoolInitData()) {  // Claims heap space
        neopool_active = true;
      }
    }
  }
}

bool NeoPoolInitData(void)
{
  bool res = false;

  neopool_error = true;
  for(uint32_t i=0; i<ARRAY_SIZE(NeoPoolReg); i++) {
    if (nullptr == NeoPoolReg[i].data) {
      NeoPoolReg[i].data = (uint16_t *)malloc(sizeof(uint16_t)*NeoPoolReg[i].cnt);
      if (nullptr != NeoPoolReg[i].data) {
        memset(NeoPoolReg[i].data, 0, sizeof(uint16_t)*NeoPoolReg[i].cnt);
#ifdef DEBUG_TASMOTA_SENSOR
        AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("NEO: Init - addr 0x%04x cnt %d data %p"), NeoPoolReg[i].addr, NeoPoolReg[i].cnt, NeoPoolReg[i].data);
#endif  // DEBUG_TASMOTA_SENSOR
        res = true;
      }
#ifdef DEBUG_TASMOTA_SENSOR
      else {
        AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: Init - out of memory"));
      }
#endif  // DEBUG_TASMOTA_SENSOR
    }
  }
  return res;
}

uint8_t NeoPoolReadRegister(uint16_t addr, uint16_t *data, uint16_t cnt)
{
  bool data_ready;
  uint32_t timeoutMS;

  neopool_poll = false;
  *data = 0;

#ifdef DEBUG_TASMOTA_SENSOR
  AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: NeoPoolReadRegister(0x%04X, %p, %d)"), addr, data, cnt);
#endif  // DEBUG_TASMOTA_SENSOR
  NeoPoolModbus->Send(NEOPOOL_MODBUS_ADDRESS, NEOPOOL_READ_REGISTER, addr, cnt);
  timeoutMS = millis() + cnt * NEOPOOL_READ_TIMEOUT; // Max delay before we timeout
  while (!(data_ready = NeoPoolModbus->ReceiveReady()) && millis() < timeoutMS) { delay(1); }
  if (data_ready) {
    uint8_t *buffer = (uint8_t*)malloc(5+cnt*2);
    if (buffer != nullptr) {
      uint8_t error = NeoPoolModbus->ReceiveBuffer(buffer, cnt);
      if (error) {
#ifdef DEBUG_TASMOTA_SENSOR
        AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: addr 0x%04X read data error %d"), addr, error);
#endif  // DEBUG_TASMOTA_SENSOR
        neopool_poll = true;
        return NEOPOOL_ERROR_RW_DATA;
      }
      for(uint32_t i=0; i<cnt; i++) {
        *data++ = (buffer[i*2+3] << 8) | buffer[i*2+4];
      }
      neopool_poll = true;
      delay(2);
      free(buffer);
      return 0;
    }
#ifdef DEBUG_TASMOTA_SENSOR
    AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: addr 0x%04X read out of memory"), addr);
#endif  // DEBUG_TASMOTA_SENSOR
    return NEOPOOL_ERROR_OUT_OF_MEM;
  }
#ifdef DEBUG_TASMOTA_SENSOR
  AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: addr 0x%04X read data timeout"), addr);
#endif  // DEBUG_TASMOTA_SENSOR
  neopool_poll = true;
  return NEOPOOL_ERROR_TIMEOUT;
}

uint8_t NeoPoolWriteRegister(uint16_t addr, uint16_t *data, uint16_t cnt)
{
  uint8_t *frame;
  uint32_t numbytes;
  bool data_ready;
  uint32_t timeoutMS;

#ifdef DEBUG_TASMOTA_SENSOR
  AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: NeoPoolWriteRegister(0x%04X, %p, %d)"), addr, data, cnt);
#endif  // DEBUG_TASMOTA_SENSOR
  neopool_poll = false;
  numbytes = 7+cnt*2;
  frame = (uint8_t*)malloc(numbytes+2);
  if (nullptr == frame) {
#ifdef DEBUG_TASMOTA_SENSOR
    AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: addr 0x%04X write out of memory"), addr);
#endif  // DEBUG_TASMOTA_SENSOR
    return NEOPOOL_ERROR_OUT_OF_MEM;
  }

  // Function 16 (10hex) Write Multiple Registers
  // Header
  frame[0] = NEOPOOL_MODBUS_ADDRESS;
  frame[1] = NEOPOOL_WRITE_REGISTER;
  frame[2] = (uint8_t)(addr >> 8);        // addr MSB
  frame[3] = (uint8_t)(addr);             // addr LSB
  frame[4] = (uint8_t)(cnt >> 8);         // register quantity MSB
  frame[5] = (uint8_t)(cnt);              // register quantity LSB
  frame[6] = (uint8_t)(cnt*2);            // byte count
  for(uint32_t i=0; i<cnt; i++) {
    frame[7+i*2] = (uint8_t)(data[i] >> 8);  // data MSB
    frame[8+i*2] = (uint8_t)(data[i]);       // data LSB
  }
  uint16_t crc = NeoPoolModbus->CalculateCRC(frame, numbytes);
  frame[numbytes] = (uint8_t)(crc);
  frame[numbytes+1] = (uint8_t)(crc >> 8);

  NeoPoolModbus->flush();
  NeoPoolModbus->write(frame, numbytes+2);

  timeoutMS = millis() + 1 * NEOPOOL_READ_TIMEOUT; // Max delay before we timeout
  while (!(data_ready = NeoPoolModbus->ReceiveReady()) && millis() < timeoutMS) { delay(1); }
  free(frame);
  if (data_ready) {
    uint8_t buffer[9];
    uint8_t error = NeoPoolModbus->ReceiveBuffer(buffer, 1);
    if (0!=error && 9!=error) { // ReceiveBuffer can't handle 0x10 code result
#ifdef DEBUG_TASMOTA_SENSOR
      AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: addr 0x%04X write data response error %d"), addr, error);
#endif  // DEBUG_TASMOTA_SENSOR
      neopool_poll = true;
      return NEOPOOL_ERROR_RW_DATA;
    }
    if (9==error) {
      // clear buffer before we leave
      while (NeoPoolModbus->available()) {
        NeoPoolModbus->read();
      }
    }
    neopool_poll = true;
    delay(2);
    return NEOPOOL_OK;
  }
#ifdef DEBUG_TASMOTA_SENSOR
  AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: addr 0x%04X write data response timeout"), addr);
#endif  // DEBUG_TASMOTA_SENSOR
  neopool_poll = true;
  return NEOPOOL_ERROR_TIMEOUT;
}

uint16_t NeoPoolGetData(uint16_t addr)
{
  for(uint32_t i=0; i<ARRAY_SIZE(NeoPoolReg); i++) {
    if (nullptr != NeoPoolReg[i].data && addr >= NeoPoolReg[i].addr && addr < NeoPoolReg[i].addr+NeoPoolReg[i].cnt) {
      return NeoPoolReg[i].data[addr - NeoPoolReg[i].addr];
    }
  }
  return 0;
}

uint32_t NeoPoolGetSpeedIndex(uint16_t speedvalue)
{
  if (speedvalue>=4) {
    return 3;
  }
  if (speedvalue>=2) {
    return 2;
  }
  if (speedvalue>=1) {
    return 1;
  }
  return 0;
}

char *NeoPoolGetInverse(char *scss, size_t size)
{
  char scolor[10];
  GetTextIndexed(scolor, sizeof(scolor), COL_BACKGROUND, kWebColors);
  snprintf_P(scss, size, PSTR(" style=\"background-color:%s;filter:invert(1);\""),scolor);
  return scss;
}

void NeoPoolShow(bool json)
{
  char parameter[FLOATSZ];
  char *neopool_type;
  char stemp[160];
  char smachine[60];
  float fvalue;

  if (neopool_error) {
    return;
  }

  neopool_type = GetTextIndexed(smachine, sizeof(smachine), NeoPoolGetData(MBF_PAR_UICFG_MACHINE), kNeoPoolMachineNames);

  if (json) {
    char delimiter[] = {'\0','\0'};

    ResponseAppend_P(PSTR(",\"" D_NEOPOOL_NAME "\":{"));

#ifndef NEOPOOL_OPTIMIZE_READINGS
    // Time
    ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_TIME "\":\"%s\""), delimiter,
      GetDT((uint32_t)NeoPoolGetData(MBF_PAR_TIME_LOW) + ((uint32_t)NeoPoolGetData(MBF_PAR_TIME_HIGH) << 16)).c_str());
    *delimiter = ',';
#endif  // NEOPOOL_OPTIMIZE_READINGS

    // TODO: Add alarm infos

    // Type
    ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_TYPE "\":\"%s\""), delimiter, neopool_type);
    *delimiter = ',';

    // Temperature
    if (NeoPoolGetData(MBF_PAR_TEMPERATURE_ACTIVE)) {
      fvalue = Settings.flag.temperature_conversion ?
        (float)NeoPoolGetData(MBF_MEASURE_TEMPERATURE)/10 * 1.8 + 32 :
        (float)NeoPoolGetData(MBF_MEASURE_TEMPERATURE)/10;
      ResponseAppend_P(PSTR("%s\"" D_TEMPERATURE "\":%*_f"), delimiter, Settings.flag2.temperature_resolution, &fvalue);
      *delimiter = ',';
    }

    // pH
    if (NeoPoolGetData(MBF_PH_STATUS) & MBMSK_PH_STATUS_MEASURE_ACTIVE) {
      fvalue = (float)NeoPoolGetData(MBF_MEASURE_PH)/100;
      ResponseAppend_P(PSTR("%s\"" D_PH """\":" NEOPOOL_FMT_PH), delimiter, &fvalue);
      *delimiter = ',';
    }

    // Redox
    if (NeoPoolGetData(MBF_RX_STATUS) & MBMSK_RX_STATUS_MEASURE_ACTIVE) {
      fvalue = (float)NeoPoolGetData(MBF_MEASURE_RX)/100;
      ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_REDOX "\":" NEOPOOL_FMT_RX), delimiter, &fvalue);
      *delimiter = ',';
    }

    // Chlorine
    if (NeoPoolGetData(MBF_CL_STATUS) & MBMSK_CL_STATUS_MEASURE_ACTIVE) {
      fvalue = (float)NeoPoolGetData(MBF_MEASURE_CL)/100;
      ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_CHLORINE "\":" NEOPOOL_FMT_CL), delimiter, &fvalue);
    }

    // Conductivity
    if (NeoPoolGetData(MBF_CD_STATUS) & MBMSK_CD_STATUS_MEASURE_ACTIVE) {
      ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_CONDUCTIVITY "\":" NEOPOOL_FMT_CD), delimiter, NeoPoolGetData(MBF_MEASURE_CONDUCTIVITY));
    }

    // Ionization
    if (NeoPoolGetData(MBF_PAR_MODEL) & MBMSK_MODEL_ION) {
      fvalue = (float)NeoPoolGetData(MBF_ION_CURRENT);
      ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_IONIZATION "\":" NEOPOOL_FMT_ION), delimiter, &fvalue);
    }

    // Hydrolysis
    if ((NeoPoolGetData(MBF_PAR_MODEL) & MBMSK_MODEL_HIDRO) && (NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_MODULE_ACTIVE)) {
      fvalue = (float)NeoPoolGetData(MBF_HIDRO_CURRENT);
      ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_HYDROLYSIS "\":" NEOPOOL_FMT_HIDRO), delimiter, &fvalue);
    }

    // Filtration
    ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_RELAY_FILTRATION "\":%d"), delimiter, (NeoPoolGetData(MBF_RELAY_STATE) >>1) & 0x02);
    ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_RELAY_FILTRATION D_JSON_SPEED "\":%d"), delimiter,
      (NeoPoolGetData(MBF_RELAY_STATE) >> 8) & 0x7
      );

    // Light
    ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_RELAY_LIGHT "\":%d"), delimiter, (NeoPoolGetData(MBF_RELAY_STATE) >>2) & 0x01);

    // Relays
    ResponseAppend_P(PSTR("%s\"" D_NEOPOOL_RELAY "\":%d"), delimiter, NeoPoolGetData(MBF_RELAY_STATE));

    ResponseJsonEnd();

#ifdef USE_WEBSERVER
  }
  else {
#ifndef NEOPOOL_OPTIMIZE_READINGS
    // Time
    char dt[20];
    TIME_T tmpTime;
    BreakTime((uint32_t)NeoPoolGetData(MBF_PAR_TIME_LOW) + ((uint32_t)NeoPoolGetData(MBF_PAR_TIME_HIGH) << 16), tmpTime);
    snprintf_P(dt, sizeof(dt), PSTR("%04d-%02d-%02d %02d:%02d"),
      tmpTime.year +1970, tmpTime.month, tmpTime.day_of_month, tmpTime.hour, tmpTime.minute);
    WSContentSend_PD(HTTP_SNS_NEOPOOL_TIME, neopool_type, dt);
#endif  // NEOPOOL_OPTIMIZE_READINGS

    // Temperature
    if (NeoPoolGetData(MBF_PAR_TEMPERATURE_ACTIVE)) {
      fvalue = Settings.flag.temperature_conversion?(float)NeoPoolGetData(MBF_MEASURE_TEMPERATURE)/10 * 1.8 + 32:(float)NeoPoolGetData(MBF_MEASURE_TEMPERATURE)/10;
      WSContentSend_PD(HTTP_SNS_F_TEMP, neopool_type, Settings.flag2.temperature_resolution, &fvalue, TempUnit());
    }

    // pH
    if (NeoPoolGetData(MBF_PH_STATUS) & MBMSK_PH_STATUS_MEASURE_ACTIVE) {
      char scss[60];
      *stemp = 0;
      if ((NeoPoolGetData(MBF_PH_STATUS) & MBMSK_PH_STATUS_ALARM) >=1 && (NeoPoolGetData(MBF_PH_STATUS) & MBMSK_PH_STATUS_ALARM) <= 3) {
        GetTextIndexed(stemp, sizeof(stemp), NeoPoolGetData(MBF_PH_STATUS) & MBMSK_PH_STATUS_ALARM, kNeoPoolpHAlarms);
      }
      fvalue = (float)NeoPoolGetData(MBF_MEASURE_PH)/100;
      WSContentSend_PD(HTTP_SNS_NEOPOOL_PH, neopool_type, &fvalue, *stemp ? NeoPoolGetInverse(scss, sizeof(scss)) : PSTR(""), stemp);
    }

    // Redox
    if (NeoPoolGetData(MBF_RX_STATUS) & MBMSK_RX_STATUS_MEASURE_ACTIVE) {
      fvalue = (float)NeoPoolGetData(MBF_MEASURE_RX)/100;
      WSContentSend_PD(HTTP_SNS_NEOPOOL_REDOX, neopool_type, &fvalue);
    }

    // Chlorine
    if (NeoPoolGetData(MBF_CL_STATUS) & MBMSK_CL_STATUS_MEASURE_ACTIVE) {
      fvalue = (float)NeoPoolGetData(MBF_MEASURE_CL)/100;
      WSContentSend_PD(HTTP_SNS_NEOPOOL_PPM_CHLORINE, neopool_type, parameter);
    }

    // Conductivity
    if (NeoPoolGetData(MBF_CD_STATUS) & MBMSK_CD_STATUS_MEASURE_ACTIVE) {
      WSContentSend_PD(HTTP_SNS_NEOPOOL_CONDUCTIVITY, neopool_type, NeoPoolGetData(MBF_MEASURE_CONDUCTIVITY));
    }

    // Ionization
    if (NeoPoolGetData(MBF_PAR_MODEL) & MBMSK_MODEL_ION) {
      char spol[32];
      sprintf_P(spol,PSTR(" " D_NEOPOOL_POLARIZATION "%d"),NeoPoolGetData(MBF_ION_STATUS)>>13);
      sprintf_P(stemp, PSTR("%s%s%s"),
        NeoPoolGetData(MBF_ION_STATUS)>>13?spol:PSTR(""),
        NeoPoolGetData(MBF_ION_STATUS) & MBMSK_ION_STATUS_ON_TARGET ? PSTR(" " D_NEOPOOL_SETPOINT_OK) : PSTR(""),
        NeoPoolGetData(MBF_ION_STATUS) & MBMSK_ION_STATUS_PROGTIME_EXCEEDED ? PSTR(" " D_NEOPOOL_PR_OFF) : PSTR("")
        );
      fvalue = (float)NeoPoolGetData(MBF_ION_CURRENT);
      WSContentSend_PD(HTTP_SNS_NEOPOOL_IONIZATION, neopool_type, &fvalue, NeoPoolGetData(MBF_ION_STATUS)>>13, NeoPoolGetData(MBF_ION_STATUS)&0x0002?" Low":"");
    }

    // Hydrolysis
#ifdef DEBUG_TASMOTA_SENSOR
    //AddLog(LOG_LEVEL_DEBUG_MORE, PSTR("NEO: MBF_PAR_MODEL 0x%04X MBF_HIDRO_STATUS 0x%04X"), NeoPoolGetData(MBF_PAR_MODEL), NeoPoolGetData(MBF_HIDRO_STATUS));
#endif  // DEBUG_TASMOTA_SENSOR
    if ((NeoPoolGetData(MBF_PAR_MODEL) & MBMSK_MODEL_HIDRO) && (NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_MODULE_ACTIVE)) {
      char spol[32];
      char scss[60];
      sprintf_P(spol,PSTR(" " D_NEOPOOL_POLARIZATION "%d"),NeoPoolGetData(MBF_HIDRO_STATUS)>>13);
      sprintf_P(stemp, PSTR("%s%s%s%s <span%s>%s%s%s</span>"),
        NeoPoolGetData(MBF_HIDRO_STATUS)>>13?spol:PSTR(""),
        NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_ON_TARGET ? PSTR(" " D_NEOPOOL_SETPOINT_OK " ") : PSTR(""),
        NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_COVER ? PSTR(" " D_NEOPOOL_COVER " ") : PSTR(""),
        NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_SHOCK_ENABLED ? PSTR(" " D_NEOPOOL_SHOCK " ") : PSTR(""),
        (NeoPoolGetData(MBF_HIDRO_STATUS) ^(MBMSK_HIDRO_STATUS_FL1|MBMSK_HIDRO_STATUS_FL2)) & (MBMSK_HIDRO_STATUS_LOW|MBMSK_HIDRO_STATUS_FL1|MBMSK_HIDRO_STATUS_FL2) ? NeoPoolGetInverse(scss, sizeof(scss)) : PSTR(""),
        NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_LOW ? PSTR("&nbsp;" D_NEOPOOL_LOW "&nbsp;") : PSTR(""),
        !(NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_FL1) ? PSTR("&nbsp;" D_NEOPOOL_FLOW1 "&nbsp;") : PSTR(""),
        !(NeoPoolGetData(MBF_HIDRO_STATUS) & MBMSK_HIDRO_STATUS_FL2) ? PSTR("&nbsp;" D_NEOPOOL_FLOW2 "&nbsp;") : PSTR("")
        );
      fvalue = (float)NeoPoolGetData(MBF_HIDRO_CURRENT);
      WSContentSend_PD(HTTP_SNS_NEOPOOL_HYDROLYSIS, neopool_type, &fvalue, stemp);
    }

    // Filtration mode
    GetTextIndexed(stemp, sizeof(stemp), NeoPoolGetData(MBF_PAR_FILT_MODE) < MBV_PAR_FILT_INTELLIGENT ? NeoPoolGetData(MBF_PAR_FILT_MODE) : 5, kNeoPoolFiltrationMode);
    WSContentSend_PD(HTTP_SNS_NEOPOOL_FILT_MODE, neopool_type, stemp);

    // Relays
    for(uint32_t i=0; i<8; i++) {
      char sdesc[24];
      memset(sdesc, 0, ARRAY_SIZE(sdesc));
      memset(stemp, 0, ARRAY_SIZE(stemp));
      if (0 != NeoPoolGetData(MBF_PAR_PH_ACID_RELAY_GPIO) && i == NeoPoolGetData(MBF_PAR_PH_ACID_RELAY_GPIO)-1) {
        strncpy_P(sdesc, PSTR(D_NEOPOOL_RELAY_PH_ACID), sizeof(sdesc));
      }
      else if (0 != NeoPoolGetData(MBF_PAR_PH_BASE_RELAY_GPIO) && i == NeoPoolGetData(MBF_PAR_PH_BASE_RELAY_GPIO)-1) {
        strncpy_P(sdesc, PSTR(D_NEOPOOL_RELAY_PH_BASE), sizeof(sdesc));
      }
      else if (0 != NeoPoolGetData(MBF_PAR_RX_RELAY_GPIO) && i == NeoPoolGetData(MBF_PAR_RX_RELAY_GPIO)-1) {
        strncpy_P(sdesc, PSTR(D_NEOPOOL_RELAY_RX), sizeof(sdesc));
      }
      else if (0 != NeoPoolGetData(MBF_PAR_CL_RELAY_GPIO) && i == NeoPoolGetData(MBF_PAR_CL_RELAY_GPIO)-1) {
        strncpy_P(sdesc, PSTR(D_NEOPOOL_RELAY_CL), sizeof(sdesc));
      }
      else if (0 != NeoPoolGetData(MBF_PAR_CD_RELAY_GPIO) && i == NeoPoolGetData(MBF_PAR_CD_RELAY_GPIO)-1) {
        strncpy_P(sdesc, PSTR(D_NEOPOOL_RELAY_CD), sizeof(sdesc));
      }
      else if (0 != NeoPoolGetData(MBF_PAR_FILT_GPIO) && i == NeoPoolGetData(MBF_PAR_FILT_GPIO)-1) {
          char smotorspeed[32];
          // Filtration
          strncpy_P(sdesc, PSTR(D_NEOPOOL_RELAY_FILTRATION), sizeof(sdesc));
          GetTextIndexed(smotorspeed, sizeof(smotorspeed), NeoPoolGetSpeedIndex((NeoPoolGetData(MBF_RELAY_STATE) >> 8) & 0x7), kNeoPoolFiltrationSpeed);
          sprintf_P(stemp, PSTR("%s%s%s%s"), ((NeoPoolGetData(MBF_RELAY_STATE) & (1<<i))?D_ON:D_OFF), *smotorspeed ? " (" : "", smotorspeed,  *smotorspeed ? ")" : "");
      }
      else if (0 != NeoPoolGetData(MBF_PAR_LIGHTING_GPIO) && i == NeoPoolGetData(MBF_PAR_LIGHTING_GPIO)-1) {
          // Light
          strncpy_P(sdesc, PSTR(D_NEOPOOL_RELAY_LIGHT), sizeof(sdesc));
      }
      WSContentSend_PD(HTTP_SNS_NEOPOOL_RELAY,
        neopool_type,
        i+1,
        sdesc,
        '\0' == *stemp ? ((NeoPoolGetData(MBF_RELAY_STATE) & (1<<i))?PSTR(D_ON):PSTR(D_OFF)) : stemp);
    }
#endif  // USE_WEBSERVER
  }
}


/*********************************************************************************************\
 * Supported commands for Sensor83:
 *
 * Sensor83  1 <addr> {<cnt>}
 *            read 16-bit register (cnt=1..30, cnt=1 if omitted)
 *
 * Sensor83  2 <addr> <data> {<data>...}
 *            write 16-bit register (data=0..65535, <data> max 8 times)
 *
 * Sensor83  3 <addr> <bit> {<data>}
 *            read/write register bit (bit=0..15, data=0|1)
 *            read if <data> is omitted, otherwise set <bit> to new <data>
 *
 * Sensor83  4 {<state>}
 *            get/set manual filtration (state=0|1)
 *            get filtration state if <state> is omitted, otherwise set new state
 *
 * Sensor83  5 {<mode>}
 *            get/set filtration mode (mode=0..4|13)
 *            get mode if <mode> is omitted, otherwise set new mode
 *
 * Sensor83  6 {<time>}
 *            get/set system time
 *            get current time if <time> is omitted, otherwise set time according:
 *              0 - sync with Tasmota local time
 *              1 - sync with Tasmota utc time
 *            any other value of <time> will set time as epoch
 *
 * Sensor83  7 {<state>}
 *            get/set light (state=0|1|2)
 *            get light state if <state> is omitted, otherwise set new state
 *              0 - switch light manual off
 *              1 - switch light manual on
 *              2 - switch light to auto mode
 *
 * Sensor83 16 <addr> {<cnt>}
 *            same as "Sensor83 1" but using hex data output
 *
 * Sensor83 21 <addr> {<cnt>}
 *            read 32-bit register (cnt=1..15, cnt=1 if omitted)
 *
 * Sensor83 22 <addr> <data> {<data>...}
 *            write 32-bit register (data=0..0xffffffff, <data> max 8 times)
 *
 * Sensor83 26 <addr> (<cnt>}
 *            same as "Sensor83 21" but using hex data output
 *
 * Sensor83 99
 *            write data permanent into flash
 *
 * Sensor83 100
 *            immediately take over data to running firmware
 *
 *
 * Examples:
 *
 * Read filtration status MBF_PAR_FILT_MANUAL_STATE
 *    Sensor83 1 0x413
 *    RESULT = {"Sensor83":{"Command":1,"Address":"0x0413","Data":0}}
 *
 * Read Heating setpoint temperature MBF_PAR_HEATING_TEMP
 *    Sensor83 1 0x416
 *    RESULT = {"Sensor83":{"Command":1,"Address":"0x0416","Data":28}}
 *
 * Read system time MBF_PAR_TIME_* as 32-bit register
 *    Sensor83 21 0x408
 *    RESULT = {"Sensor83":{"Command":21,"Address":"0x0408","Data":1611399658}}
 *
 * Enable temperature module by setting MBF_PAR_TEMPERATURE_ACTIVE and set it permanent by using a write to MBF_SAVE_TO_EEPROM (0x02F0)
 *    Backlog Sensor83 2 0x40F,1;Sensor83 2 0x2F0,1
 *    RESULT = {"Sensor83":{"Command":3,"Address":"0x040F","Data":1}}
 *    RESULT = {"Sensor83":{"Command":3,"Address":"0x2F0","Data":1}}
 *
 * Hide auxiliary relay display from main menu by setting bit 3 of MBF_PAR_UICFG_VISUAL_OPTIONS
 *    Sensor83 3 0x0605,3,1
 *    RESULT = {"Sensor83":{"Command":2,"Address":"0x0605","Bit":3,"Data":1}}
 *
 * Read Filtration interval 1-3 settings
 *    Backlog Sensor83 1 0x434;Sensor83 21 0x435 7;Sensor83 1 0x0443;Sensor83 21 0x0444 7;Sensor83 1 0x0452;Sensor83 21 0x0453 7
 *    RESULT = {"Sensor83":{"Command":1,"Address":"0x0434","Data":1}}
 *    RESULT = {"Sensor83":{"Command":21,"Address":"0x0435","Data":[28800,0,86400,14400,0,1,0]}}
 *    RESULT = {"Sensor83":{"Command":1,"Address":"0x0443","Data":1}}
 *    RESULT = {"Sensor83":{"Command":21,"Address":"0x0444","Data":[43200,0,86400,21600,0,1,0]}}
 *    RESULT = {"Sensor83":{"Command":1,"Address":"0x0452","Data":1}}
 *    RESULT = {"Sensor83":{"Command":21,"Address":"0x0453","Data":[0,0,86400,0,0,1,0]}}
 *
 * Set Filtration interval 1 to daily 9:00 - 12:30 (9:00: 3600 * 9 ≙ 32400 / 12:30 ≙ 3,5h = 12600)
 *    Sensor83 22 0x435 32400 0 86400 12600
 *    RESULT = {"Sensor83":{"Command":22,"Address":"0x0435","Data":[32400,0,86400,12600]}}
 *
 *********************************************************************************************/
#define NEOPOOL_CMND_READ_REG         1
#define NEOPOOL_CMND_WRITE_REG        2
#define NEOPOOL_CMND_READWRITE_BIT    3
#define NEOPOOL_CMND_FILTRATION       4
#define NEOPOOL_CMND_FILTRATION_MODE  5
#define NEOPOOL_CMND_TIME             6
#define NEOPOOL_CMND_LIGHT            7
#define NEOPOOL_CMND_READ_REG_HEX     16
#define NEOPOOL_CMND_READ_REG32       21
#define NEOPOOL_CMND_WRITE_REG32      22
#define NEOPOOL_CMND_READ_REG_HEX32   26
#define NEOPOOL_CMND_SAVE_TO_EEPROM   99
#define NEOPOOL_CMND_IMM_TAKE_OVER   100

#define NEOPOOL_CMND_SENSOR D_CMND_SENSOR STR(XSNS_83)
#define NEOPOOL_MAX_CMND_LEN 160

bool NeoPoolCmnd(void)
{
  bool serviced = false;
  char sub_string[XdrvMailbox.data_len +1];
  uint16_t cmnd, addr, data[30], cnt=1;
  int8_t bit;
  bool bits32 = false;
  uint32_t value[10] = { 0 };
  uint32_t params_cnt = ParseParameters(ARRAY_SIZE(value), value);
  char *scmnd = (char *)malloc(NEOPOOL_MAX_CMND_LEN);

  if(!neopool_error && scmnd != nullptr && params_cnt > 0) {
    params_cnt--;

    cmnd = value[0];
    bits32 = (NEOPOOL_CMND_READ_REG32 == cmnd || NEOPOOL_CMND_WRITE_REG32 == cmnd || NEOPOOL_CMND_READ_REG_HEX32 == cmnd);
    switch (cmnd) {

    case NEOPOOL_CMND_READ_REG:  // <addr> (<cnt>)
    case NEOPOOL_CMND_READ_REG_HEX:
    case NEOPOOL_CMND_READ_REG_HEX32:
    case NEOPOOL_CMND_READ_REG32:
      {
        addr = value[1];
        cnt = 1;
        if (2 == params_cnt) {
          cnt = value[2];
        }
        if (cnt > (bits32 ? (ARRAY_SIZE(data)/2) : ARRAY_SIZE(data))) {
          serviced = false;
        }
        else {
          serviced = (NEOPOOL_OK == NeoPoolReadRegister(addr, data, bits32 ? (cnt*2) : cnt));
        }
      }
      break;

    case NEOPOOL_CMND_WRITE_REG:  // <addr> <data> (<data>...)
    case NEOPOOL_CMND_WRITE_REG32:
      {
        addr = value[1];
        if (params_cnt >= 2) {
          cnt = params_cnt-1;
          for(uint32_t i=0; i<cnt; i++) {
            if (bits32) {
              data[i*2] = value[i+2];       // LSB
              data[i*2+1] = value[i+2]>>16; // MSB
            }
            else {
              data[i] = value[i+2];
            }
          }
          serviced = (NEOPOOL_OK == NeoPoolWriteRegister(addr, data, bits32 ? (cnt*2) : cnt));
        }
      }
      break;

    case NEOPOOL_CMND_READWRITE_BIT:  // <addr> <bit> (<data>)
      {
        uint16_t tempdata;

        addr = value[1];
        bit = (int8_t)value[2];
        data[0] = value[3];
        if (bit>=0 && bit<=15 && data[0]>=0 && data[0]<=1) {
          if (2 == params_cnt) {
            serviced = (NEOPOOL_OK == NeoPoolReadRegister(addr, data, 1));
            data[0] = (data[0] >> bit) & 0x0001;
          }
          if (3 == params_cnt) {
            if (NEOPOOL_OK == NeoPoolReadRegister(addr, &tempdata, 1)) {
              tempdata &= ~(1<<bit);
              tempdata |= (data[0]<<bit);
              serviced = (NEOPOOL_OK == NeoPoolWriteRegister(addr, &tempdata, 1));
            }
          }
        }
      }
      break;

    case NEOPOOL_CMND_FILTRATION:  // (<state>)
      {
        addr = MBF_PAR_FILT_MANUAL_STATE;
        if (0 == params_cnt) {
          serviced = (NEOPOOL_OK == NeoPoolReadRegister(addr, data, 1));
        }
        if (1 == params_cnt) {
          // Filtration ON/OFF:
          // First set filtration mode to manual
          snprintf_P(scmnd, NEOPOOL_MAX_CMND_LEN, PSTR(NEOPOOL_CMND_SENSOR " " STR(NEOPOOL_CMND_FILTRATION_MODE) ",0"));
          ExecuteWebCommand(scmnd, SRC_WEBGUI);
          // Set MBF_PAR_FILT_MANUAL_STATE [MBF_PAR_FILT_MANUAL_STATE] accordingly (0|1)
          data[0] = value[1] ? 1 : 0;
          serviced = (NEOPOOL_OK == NeoPoolWriteRegister(addr, data, 1));
        }
      }
      break;

    case NEOPOOL_CMND_FILTRATION_MODE:  // (<mode>)
      {
        addr = MBF_PAR_FILT_MODE;
        if (0 == params_cnt) {
          serviced = (NEOPOOL_OK == NeoPoolReadRegister(addr, data, 1));
        }
        if (1 == params_cnt) {
          data[0] = value[1];
          if( (data[0] >= MBV_PAR_FILT_MANUAL && data[0] <= MBV_PAR_FILT_INTELLIGENT) || MBV_PAR_FILT_BACKWASH == data[0]) {
            // Set MBF_PAR_FILT_MODE
            serviced = (NEOPOOL_OK == NeoPoolWriteRegister(addr, data, 1));
          }
        }
      }
      break;

    case NEOPOOL_CMND_TIME:  // (<time>)
      {
        char dt[20];
        TIME_T tmpTime;

        if (1 == params_cnt) {
          uint32_t new_time = Rtc.local_time;
          if (1==value[1]) {
            new_time = Rtc.utc_time;
          }
          if (value[1]>1) {
            new_time = value[1];
          }
          data[0] = (uint16_t)(new_time & 0xFFFF);
          data[1] = (uint16_t)((new_time>>16) & 0xFFFF);
#ifdef DEBUG_TASMOTA_SENSOR
          AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: set time to %ld (%04X%04X)"), new_time, data[0], data[1]);
#endif  // DEBUG_TASMOTA_SENSOR
          serviced = (NEOPOOL_OK == NeoPoolWriteRegister(MBF_PAR_TIME_LOW, data, 2));
          if (serviced) {
            uint16_t set=0;
            serviced = (NEOPOOL_OK == NeoPoolWriteRegister(MBF_ACTION_COPY_TO_RTC, &set, 1));
          }
        }
        else if (0 == params_cnt) {
          serviced = (NEOPOOL_OK == NeoPoolReadRegister(MBF_PAR_TIME_LOW, data, 2));
#ifdef DEBUG_TASMOTA_SENSOR
          AddLog(LOG_LEVEL_DEBUG, PSTR("NEO: time read 0x%04X%04X %ld"), data[1], data[0], (uint32_t)data[0] + ((uint32_t)data[1] << 16));
#endif  // DEBUG_TASMOTA_SENSOR
        }
        else {
          serviced = false;
        }
        if (serviced) {
          BreakTime((uint32_t)data[0] + ((uint32_t)data[1] << 16), tmpTime);
          snprintf_P(dt, sizeof(dt), PSTR("%04d" D_YEAR_MONTH_SEPARATOR "%02d" D_MONTH_DAY_SEPARATOR "%02d" D_DATE_TIME_SEPARATOR "%02d" D_HOUR_MINUTE_SEPARATOR "%02d" D_MINUTE_SECOND_SEPARATOR "%02d"),
            tmpTime.year +1970, tmpTime.month, tmpTime.day_of_month, tmpTime.hour, tmpTime.minute, tmpTime.second);
          Response_P(PSTR("{\"" NEOPOOL_CMND_SENSOR "\":{\"" D_JSON_TIME "\":\"%s\"}}"), dt);
        }
      }
      break;

    case NEOPOOL_CMND_LIGHT:  // (<state>)
      {
        if (0 == params_cnt) {
          addr = MBF_RELAY_STATE;
          if (NEOPOOL_OK == NeoPoolReadRegister(MBF_PAR_LIGHTING_GPIO, data, 1) && 0 != data[0]) {
            data[1] = data[0] - 1;
            serviced = (NEOPOOL_OK == NeoPoolReadRegister(MBF_RELAY_STATE, data, 1));
            data[0] >>= data[1];
          }
          else {
            serviced = false;
          }
        }
        if (1 == params_cnt) {
          addr = MBF_PAR_TIMER_BLOCK_LIGHT_INT + MBV_TIMER_OFFMB_TIMER_ENABLE;
          uint16_t timer_val[] = {MBV_PAR_CTIMER_ALWAYS_OFF, MBV_PAR_CTIMER_ALWAYS_ON, MBV_PAR_CTIMER_ENABLED};
          if (value[1] <= ARRAY_SIZE(timer_val)) {
              data[0] = timer_val[value[1]];
              serviced = true;
          }
          if( serviced ) {
            snprintf_P(scmnd, NEOPOOL_MAX_CMND_LEN,
              PSTR(D_CMND_BACKLOG " "
                   NEOPOOL_CMND_SENSOR " " STR(NEOPOOL_CMND_WRITE_REG) ",0x%04X,%d;"
                   NEOPOOL_CMND_SENSOR " " STR(NEOPOOL_CMND_SAVE_TO_EEPROM) ";"
                   NEOPOOL_CMND_SENSOR " " STR(NEOPOOL_CMND_IMM_TAKE_OVER)),
               addr, data[0]);
            ExecuteWebCommand(scmnd, SRC_WEBGUI);
            serviced = (NEOPOOL_OK == NeoPoolReadRegister(addr, data, 1));
          }
        }
      }
      break;

    case NEOPOOL_CMND_SAVE_TO_EEPROM:
        addr = MBF_SAVE_TO_EEPROM;
        if (0 == params_cnt) {
          data[0] = 1;
          serviced = (NEOPOOL_OK == NeoPoolWriteRegister(addr, data, 1));
        }
        break;

    case NEOPOOL_CMND_IMM_TAKE_OVER:
        addr = MBF_IMM_TAKE_OVER;
        if (0 == params_cnt) {
          data[0] = 1;
          serviced = (NEOPOOL_OK == NeoPoolWriteRegister(addr, data, 1));
        }
        break;

    default:
      AddLog_P(LOG_LEVEL_DEBUG, PSTR("NEO: Unknown " NEOPOOL_CMND_SENSOR " cmnd %d"), cmnd);
      break;
    }
    free(scmnd);
  }

  if (serviced) {
    switch (cmnd) {
    case NEOPOOL_CMND_TIME:
      break;
    case NEOPOOL_CMND_READWRITE_BIT:
        Response_P(PSTR("{\"" NEOPOOL_CMND_SENSOR "\":{\"" D_JSON_COMMAND "\":%d,\"" D_JSON_ADDRESS "\":\"0x%04X\",\"" D_STR_BIT "\":%d,\"" D_JSON_DATA "\":%d}}"), cmnd, addr, bit, data[0]);
      break;
    default:
      {
        Response_P(PSTR("{\"" NEOPOOL_CMND_SENSOR "\":{\"" D_JSON_COMMAND "\":%d,\"" D_JSON_ADDRESS "\":\"0x%04X\",\"" D_JSON_DATA"\":"), cmnd, addr);
        if ( cnt > 1 ) {
          char sdel[2] = {0};
          ResponseAppend_P(PSTR("["));
          for(uint32_t i=0; i<cnt; i++) {
            if (bits32) {
            uint32_t data32 = ((uint32_t)data[i*2+1]) << 16 | (uint32_t)data[i*2];
              ResponseAppend_P(NEOPOOL_CMND_READ_REG_HEX32 == cmnd ? PSTR("%s\"0x%08X\"") : PSTR("%s%ld"), sdel, data32);
            }
            else {
              ResponseAppend_P(NEOPOOL_CMND_READ_REG_HEX == cmnd ? PSTR("%s\"0x%04X\"") : PSTR("%s%d"), sdel, data[i]);
            }
            *sdel = ',';
          }
          ResponseAppend_P(PSTR("]"));
        }
        else {
          if (bits32) {
            uint32_t data32 = ((uint32_t)data[1]) << 16 | (uint32_t)data[0];
            ResponseAppend_P(NEOPOOL_CMND_READ_REG_HEX32 == cmnd ? PSTR("\"0x%08X\"") : PSTR("%ld"), data32);
          }
          else {
            ResponseAppend_P(NEOPOOL_CMND_READ_REG_HEX == cmnd ? PSTR("\"0x%04X\"") : PSTR("%d"), data[0]);
          }
        }
        ResponseJsonEndEnd();
      }
      break;
    }
  }

  return serviced;
}


/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xsns83(uint8_t function)
{
  bool result = false;

  if (FUNC_INIT == function) {
    NeoPoolInit();
  }
  else if (neopool_active) {
    switch (function) {
      case FUNC_EVERY_250_MSECOND:
        NeoPool250ms();
        break;
      case FUNC_COMMAND_SENSOR:
        if (XSNS_83 == XdrvMailbox.index) {
          result = NeoPoolCmnd();
        }
        break;
      case FUNC_JSON_APPEND:
        NeoPoolShow(1);
        break;
#ifdef USE_WEBSERVER
      case FUNC_WEB_SENSOR:
        NeoPoolShow(0);
        break;
#endif  // USE_WEBSERVER
    }
  }
  return result;
}

#endif  // USE_NEOPOOL
