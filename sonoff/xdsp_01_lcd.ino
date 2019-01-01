/*
  xdsp_01_lcd.ino - Display LCD support for Sonoff-Tasmota

  Copyright (C) 2019  Theo Arends and Adafruit

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
#ifdef USE_DISPLAY_LCD

#define XDSP_01                1

#define LCD_ADDRESS1           0x27         // LCD I2C address option 1
#define LCD_ADDRESS2           0x3F         // LCD I2C address option 2

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C *lcd;

/*********************************************************************************************/

void LcdInitMode(void)
{
  lcd->init();
  lcd->clear();
}

void LcdInit(uint8_t mode)
{
  switch(mode) {
    case DISPLAY_INIT_MODE:
      LcdInitMode();
#ifdef USE_DISPLAY_MODES1TO5
      DisplayClearScreenBuffer();
#endif  // USE_DISPLAY_MODES1TO5
      break;
    case DISPLAY_INIT_PARTIAL:
    case DISPLAY_INIT_FULL:
      break;
  }
}

void LcdInitDriver(void)
{
  if (!Settings.display_model) {
    if (I2cDevice(LCD_ADDRESS1)) {
      Settings.display_address[0] = LCD_ADDRESS1;
      Settings.display_model = XDSP_01;
    }
    else if (I2cDevice(LCD_ADDRESS2)) {
      Settings.display_address[0] = LCD_ADDRESS2;
      Settings.display_model = XDSP_01;
    }
  }

  if (XDSP_01 == Settings.display_model) {
    lcd = new LiquidCrystal_I2C(Settings.display_address[0], Settings.display_cols[0], Settings.display_rows);

#ifdef USE_DISPLAY_MODES1TO5
    DisplayAllocScreenBuffer();
#endif  // USE_DISPLAY_MODES1TO5

    LcdInitMode();
  }
}

void LcdDrawStringAt(void)
{
  lcd->setCursor(dsp_x, dsp_y);
  lcd->print(dsp_str);
}

void LcdDisplayOnOff(uint8_t on)
{
  if (on) {
    lcd->backlight();
  } else {
    lcd->noBacklight();
  }
}

/*********************************************************************************************/

#ifdef USE_DISPLAY_MODES1TO5

void LcdCenter(byte row, char* txt)
{
  int offset;
  int len;
  char line[Settings.display_cols[0] +2];

  memset(line, 0x20, Settings.display_cols[0]);
  line[Settings.display_cols[0]] = 0;
  len = strlen(txt);
  offset = (len < Settings.display_cols[0]) ? offset = (Settings.display_cols[0] - len) / 2 : 0;
  strlcpy(line +offset, txt, len);
  lcd->setCursor(0, row);
  lcd->print(line);
}

boolean LcdPrintLog(void)
{
  boolean result = false;

  disp_refresh--;
  if (!disp_refresh) {
    disp_refresh = Settings.display_refresh;
    if (!disp_screen_buffer_cols) { DisplayAllocScreenBuffer(); }

    char* txt = DisplayLogBuffer('\337');
    if (txt != NULL) {
      uint8_t last_row = Settings.display_rows -1;

      for (byte i = 0; i < last_row; i++) {
        strlcpy(disp_screen_buffer[i], disp_screen_buffer[i +1], disp_screen_buffer_cols);
        lcd->setCursor(0, i);            // Col 0, Row i
        lcd->print(disp_screen_buffer[i +1]);
      }
      strlcpy(disp_screen_buffer[last_row], txt, disp_screen_buffer_cols);
      DisplayFillScreen(last_row);

      snprintf_P(log_data, sizeof(log_data), PSTR(D_LOG_DEBUG "[%s]"), disp_screen_buffer[last_row]);
      AddLog(LOG_LEVEL_DEBUG);

      lcd->setCursor(0, last_row);
      lcd->print(disp_screen_buffer[last_row]);

      result = true;
    }
  }
  return result;
}

void LcdTime(void)
{
  char line[Settings.display_cols[0] +1];

  snprintf_P(line, sizeof(line), PSTR("%02d" D_HOUR_MINUTE_SEPARATOR "%02d" D_MINUTE_SECOND_SEPARATOR "%02d"), RtcTime.hour, RtcTime.minute, RtcTime.second);
  LcdCenter(0, line);
  snprintf_P(line, sizeof(line), PSTR("%02d" D_MONTH_DAY_SEPARATOR "%02d" D_YEAR_MONTH_SEPARATOR "%04d"), RtcTime.day_of_month, RtcTime.month, RtcTime.year);
  LcdCenter(1, line);
}

void LcdRefresh(void)  // Every second
{
  if (Settings.display_mode) {  // Mode 0 is User text
    switch (Settings.display_mode) {
      case 1:  // Time
        LcdTime();
        break;
      case 2:  // Local
      case 4:  // Mqtt
        LcdPrintLog();
        break;
      case 3:  // Local
      case 5: {  // Mqtt
        if (!LcdPrintLog()) { LcdTime(); }
        break;
      }
    }
  }
}

#endif  // USE_DISPLAY_MODES1TO5

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

boolean Xdsp01(byte function)
{
  boolean result = false;

  if (i2c_flg) {
    if (FUNC_DISPLAY_INIT_DRIVER == function) {
      LcdInitDriver();
    }
    else if (XDSP_01 == Settings.display_model) {
      switch (function) {
        case FUNC_DISPLAY_MODEL:
          result = true;
          break;
        case FUNC_DISPLAY_INIT:
          LcdInit(dsp_init);
          break;
        case FUNC_DISPLAY_POWER:
          LcdDisplayOnOff(disp_power);
          break;
        case FUNC_DISPLAY_CLEAR:
          lcd->clear();
          break;
//        case FUNC_DISPLAY_DRAW_HLINE:
//          break;
//        case FUNC_DISPLAY_DRAW_VLINE:
//          break;
//        case FUNC_DISPLAY_DRAW_CIRCLE:
//          break;
//        case FUNC_DISPLAY_FILL_CIRCLE:
//          break;
//        case FUNC_DISPLAY_DRAW_RECTANGLE:
//          break;
//        case FUNC_DISPLAY_FILL_RECTANGLE:
//          break;
//        case FUNC_DISPLAY_DRAW_FRAME:
//          break;
//        case FUNC_DISPLAY_TEXT_SIZE:
//          break;
//        case FUNC_DISPLAY_FONT_SIZE:
//          break;
        case FUNC_DISPLAY_DRAW_STRING:
          LcdDrawStringAt();
          break;
        case FUNC_DISPLAY_ONOFF:
          LcdDisplayOnOff(dsp_on);
          break;
//        case FUNC_DISPLAY_ROTATION:
//          break;
#ifdef USE_DISPLAY_MODES1TO5
        case FUNC_DISPLAY_EVERY_SECOND:
          LcdRefresh();
          break;
#endif  // USE_DISPLAY_MODES1TO5
      }
    }
  }
  return result;
}

#endif  // USE_DISPLAY_LCD
#endif  // USE_DISPLAY
#endif  // USE_I2C
