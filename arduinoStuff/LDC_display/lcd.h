/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
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
    void lcdInit();
    void lcdByte(byte type, byte value);
    void lcdPrintString(byte starting_line, String output);
    byte lcd_output[20] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20};
    byte lcd_ddram_lines[5] = {0x00, 0x00, 0x20, 0x40, 0x60};
  private:
    byte _lcd_address = 0x3C;
    byte _lcd_rows = 0x08;
    byte _lcd_num_rows = 4;
    byte _lcd_num_cols = 20;    
};

#endif
