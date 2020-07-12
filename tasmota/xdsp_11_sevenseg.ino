/*
  xdsp_11_sevenseg.ino - Display seven segment support for Tasmota

  Copyright (C) 2020  Theo Arends and Adafruit

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

#ifdef USE_I2C
#ifdef USE_DISPLAY
#ifdef USE_DISPLAY_SEVENSEG

#define XDSP_11                    11
#define XI2C_47                    47  // See I2CDEVICES.md

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>  // Seven segment LED

Adafruit_7segment *sevenseg[8];
uint8_t sevensegs = 0;
uint8_t sevenseg_state = 0;

/*********************************************************************************************/

void SevensegWrite(void)
{
  for (uint32_t i = 0; i < sevensegs; i++) {
    sevenseg[i]->writeDisplay();
  }
}

void SevensegClear(void)
{
  for (uint32_t i = 0; i < sevensegs; i++) {
    sevenseg[i]->clear();
  }
  SevensegWrite();
}


/*********************************************************************************************/

void SevensegInitMode(void)
{
  for (uint32_t i = 0; i < sevensegs; i++) {
    sevenseg[i]->setBrightness(Settings.display_dimmer);
    sevenseg[i]->blinkRate(0);
  }
  SevensegClear();
}

void SevensegInit(uint8_t mode)
{
  switch(mode) {
    case DISPLAY_INIT_MODE:
    case DISPLAY_INIT_PARTIAL:
    case DISPLAY_INIT_FULL:
      SevensegInitMode();
      break;
  }
}

void SevensegInitDriver(void)
{
  if (!Settings.display_model) {
    if (I2cSetDevice(Settings.display_address[0])) {
      Settings.display_model = XDSP_11;
    }
  }

  if (XDSP_11 == Settings.display_model) {
    sevenseg_state = 1;
    for (sevensegs = 0; sevensegs < 8; sevensegs++) {
        if (Settings.display_address[sevensegs]) {
          I2cSetActiveFound(Settings.display_address[sevensegs], "SevenSeg");
          sevenseg[sevensegs] = new Adafruit_7segment();
          sevenseg[sevensegs]->begin(Settings.display_address[sevensegs]);
        } else {
            break;
        }
    }
    
    Settings.display_width = 4;
    Settings.display_height = sevensegs;

    SevensegInitMode();
  }
}

void SevensegOnOff(void)
{
  if (!disp_power) { SevensegClear(); }
}

void SevensegDrawStringAt(uint16_t x, uint16_t y, char *str, uint16_t color, uint8_t flag)
{
  uint16_t number = 0;
  boolean hasnumber= false;
  uint8_t dots= 0;
  boolean t=false;
  boolean T=false;
  boolean d=false;
  boolean hex=false;
  boolean done=false;
  boolean s=false;
  uint8_t unit=y;
  if ((unit>=sevensegs) || (unit<0)) {
    unit=0;
  }

  for (int i=0; (str[i]!='\0') && (!done); i++) {
    // [optional prefix(es) chars]digits
    // Some combinations won't make sense.
    // Reference: https://learn.adafruit.com/adafruit-led-backpack/1-2-inch-7-segment-backpack-arduino-wiring-and-setup
    // 
    // Prefixes:
    // x  upcoming number decimal integer displayed as hex
    // :  turn on middle colon
    // ^  turh on top left dot
    // v  turn on bottom left dot
    // .  turn on AM/PM/Degree dot
    // s  upcoming number is seconds, print as HH:MM or MM:SS
    // z  clear this display
    // 
    // Some sample valid combinations:
    // 787    -> 787
    // x47    -> 2F
    // s:241  -> 04:01
    // s241   -> 4 01
    // s1241  -> 20:41
    // z      ->
    // x88    -> 58

    switch (str[i]) {
      case 'x': // print given dec value as hex
        hex = true;
        break;
      case ':': // print colon
        dots |= 0x02;
        break;
      case '^': // print top_left_dot
        dots |= 0x08;
        break;
      case 'v': // print bottom_left_dot
        dots |= 0x04;
        break;
      case '.': // print ampm
        dots |= 0x10;
        break;
      case 's': // duration in seconds
        s = true;
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        hasnumber= true;
        number = atoi(str+i);
        done = true;
        break;
      case 'z': // Clear this display
        hasnumber=false;
        dots=0;
        s=false;
        sevenseg[unit]->clear();
        break;
      default: // unknown format, ignore
        break;
    }
  }

  if (s) {
    // number is duration in seconds
    hex = false;
    int hour = number/60/60;
    int minute = (number/60)%60;

    if (hour) {
      // HH:MM
      number = hour*100 + minute;
    } else {
      // MM:SS
      number = minute*100 + number%60;
    }
  }

  if (hasnumber) {
    if (hex) {
      sevenseg[unit]->print(number, HEX);
    } else {
      sevenseg[unit]->print(number, DEC);
    }
  }

  if (dots) {
    sevenseg[unit]->writeDigitRaw(2, dots);
  }

  sevenseg[unit]->writeDisplay();
}

/*********************************************************************************************/

#ifdef USE_DISPLAY_MODES1TO5
void SevensegTime(boolean time_24)
{

  uint hours = RtcTime.hour;
  uint minutes = RtcTime.minute;
  uint second = RtcTime.second;
  uint16_t displayValue = hours * 100 + minutes;
  uint16_t dots = 0;

  // Do 24 hour to 12 hour format conversion when required.
  if (!time_24) {
    // Handle when hours are past 12 by subtracting 12 hours (1200 value).
    if (hours > 12) {
      displayValue -= 1200;
    }
    // Handle hour 0 (midnight) being shown as 12.
    else if (hours == 0) {
      displayValue += 1200;
    }
  }


  // Now print the time value to the display.
  sevenseg[0]->print(displayValue, DEC);

  // Add zero padding when in 24 hour mode and it's midnight.
  // In this case the print function above won't have leading 0's
  // which can look confusing.  Go in and explicitly add these zeros.
  if (time_24) {
    if (hours == 0) {
      // Pad hour 0.
      sevenseg[0]->writeDigitNum(1, 0);
      // Also pad when the 10's minute is 0 and should be padded.
      if (minutes < 10) {
        sevenseg[0]->writeDigitNum(3, 0);
      }
    }
    if (hours < 10) {
      // Always have 4 digits time
      sevenseg[0]->writeDigitNum(0, 0);
    }
  } else {
    // Identify and display AM/PM
    if (hours >= 12) {
        dots |= 0x10;
    }
  }

  sevenseg[0]->writeDigitRaw(2, dots |= ((second%2) << 1));
  sevenseg[0]->writeDisplay();
}

void SevensegRefresh(void)  // Every second
{
  if (disp_power) {
    if (Settings.display_mode) {  // Mode 0 is User text
      switch (Settings.display_mode) {
        case 1:  // Time 12
          SevensegTime(false);
          break;
        case 2:  // Time 24
          SevensegTime(true);
          break;
        case 4:  // Mqtt
        case 3:  // Local
        case 5: {  // Mqtt
          break;
        }
      }
    }
  }
}

#endif  // USE_DISPLAY_MODES1TO5

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xdsp11(uint8_t function)
{
  if (!I2cEnabled(XI2C_47)) { return false; }

  bool result = false;

  if (FUNC_DISPLAY_INIT_DRIVER == function) {
    SevensegInitDriver();
  }
  else if (XDSP_11 == Settings.display_model) {
    switch (function) {
      case FUNC_DISPLAY_MODEL:
        result = true;
        break;
      case FUNC_DISPLAY_INIT:
        SevensegInit(dsp_init);
        break;
      case FUNC_DISPLAY_CLEAR:
        SevensegClear();
        break;
#ifdef USE_DISPLAY_MODES1TO5
      case FUNC_DISPLAY_EVERY_SECOND:
        SevensegRefresh();
        break;
#endif  // USE_DISPLAY_MODES1TO5
      case FUNC_DISPLAY_ONOFF:
      case FUNC_DISPLAY_POWER:
        SevensegOnOff();
        break;
      case FUNC_DISPLAY_DRAW_STRING:
        SevensegDrawStringAt(dsp_x, dsp_y, dsp_str, dsp_color, dsp_flag);
        break;
    }
  }
  return result;
}

#endif  // USE_DISPLAY_SEVENSEG
#endif  // USE_DISPLAY
#endif  // USE_I2C
