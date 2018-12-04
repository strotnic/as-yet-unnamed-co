/*
  File Name: lcd.h
  Created By: Stephen Trotnic
  Date: December 2nd, 2018
  Purpose: OLED display driver library for NewHaven NHD-0420CW-AB3 
  Released into the public domain.
*/

#ifndef LCD_H
#define LCD_H

#include <Wire.h>
#include "Arduino.h"
#include "port.h"

const uint8_t CLEAR = 0x01;
const uint8_t HOME = 0x02;
const uint8_t SET_DDRAM = 0X80;

// SPECIAL FUNCTION MESSAGES
const String WELCOME_MESSAGE = "Multi-Funct Lab Inst";
const String VOLTMETER_STD = "Voltmeter: <9-digits>";
const String VOLTMETER_HP = " <20-digits output> ";
const String LED_OUTPUT = " <LED S/P out info> ";

// OUTPUT VALUES
const String CURRENT_OUTPUT_VALUES = "<o1 value><o2 value>" //flashing when channel is off?

// DUAL OUTPUT FUNCTION MESSAGES
const String DUAL_OUTPUT = "- 0-20 V +- 0-20 V +";
const String SINGLE_NEGATIVE_OUTPUT = "- -20-0 V G 0-20 V +";
const String DIFFERENTIAL_OUTPUT = "differential: <valu>";

// SOFT KEY MESSAGES
const String GENERIC_SOFT_KEYS = " SK1  SK2  SK3  SK4 ";
const String FUTURE_MENU_KEYS = " <1>  <2>  <3>  <4> ";
class LCD
{
  public:
    void init();
    void byteSend(uint8_t type, uint8_t value);
    void stringSend(uint8_t starting_line, String output);
    uint8_t lcd_output[20] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
    uint8_t lcd_ddram_lines[5] = {0x00, 0x00, 0x20, 0x40, 0x60};
  private:
    uint8_t _address = 0x3C;
    uint8_t _rows = 0x08;
    uint8_t _num_rows = 4;
    uint8_t _num_cols = 20;    
};

#endif
