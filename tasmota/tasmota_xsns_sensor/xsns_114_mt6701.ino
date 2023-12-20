/*
  xsns_114_mt6701.ino - MT6701 Tasmota support for Hall based angle position sensor

  based on
  https://github.com/S-LABc/MT6701-Arduino-Library
  Copyright (c) 2022 Roman Sklyar S-LAB (MIT License)

  Copyright (C) 2023  Lukas Zimmermann

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
#ifdef USE_MT6701
/*********************************************************************************************\
 * MT6701 - Hall based rotary position sensor from MagnTek
 * https://www.magntek.com.cn/upload/MT6701_Rev.1.8.pdf
 *
 * I2C Address: 0x06
 *
\*********************************************************************************************/

#define XSNS_100                                100
#define XI2C_86                                 86        // See I2CDEVICES.md

#define MT6701_ADDRESS                          (0x06)    // 0000110

#endif  // USE_MT6701
#endif  // USE_I2C

