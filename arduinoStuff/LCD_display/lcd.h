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

const byte CLEAR = 0x01;
const byte HOME = 0x02;
const byte SET_DDRAM = 0X80;

class LCD
{
  public:
    void init();
    void byteSend(byte type, byte value);
    void stringSend(byte starting_line, String output);
    byte lcd_output[20] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
    byte lcd_ddram_lines[5] = {0x00, 0x00, 0x20, 0x40, 0x60};
  private:
    byte _address = 0x3C;
    byte _rows = 0x08;
    byte _num_rows = 4;
    byte _num_cols = 20;    
};

#endif
