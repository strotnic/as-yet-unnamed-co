/*
  File Name: lcd.cpp
  Created By: Stephen Trotnic
  Date: December 2nd, 2018
  Purpose: OLED display hardware driver for NewHaven NHD-0420CW-AB3 
  Released into the public domain.
*/

#include "lcd.h"

void LCD::init() {
  // Initialization routine
  int8_t init_values[] = {int8_t(0x22 | _rows), 0x71, 0x5C, int8_t(0x20 | _rows), 0x08, int8_t(0x22 | _rows), 0x79, 0xD5, 0x70, 0x78,
                             int8_t(_num_rows > 2 ? 0x09 : 0x08), 0x06, 0x72, 0x00, 0x79, 0xDA, 0x10, 0x81, 0x7F, 0xD9,
                             0xF1, 0xDB, 0x40, 0x78, int8_t(0x20 | _rows)
                            };

  digitalWrite(RST_n, HIGH);
  delay(200);

  // Cycle through the initialization routuine
  for (int8_t init_count = 0; init_count < (sizeof(init_values)/sizeof(int8_t)); init_count++) {
    // Check for command/data types in the inialization routine
    ((init_count == 2) || (init_count == 13)) ? byteSend(1, init_values[init_count]) : byteSend(0, init_values[init_count]);
  }
  // Clearing and Turning on the LCD require delays
  byteSend(0, CLEAR);
  delay(2);
  byteSend(0, 0x0C); //0x0C = LCD on, 0x0F = LCD/Cursor/Blink on
  delay(250);
}

void LCD::byteSend(int8_t type, int8_t value) {
  Wire.beginTransmission(_address);
  Wire.write(type<<6);
  Wire.write(value);
  Wire.endTransmission();
}

void LCD::stringSend(int8_t starting_line, String output) {
  // Set LCD cursor to the start of the desired output line
  byteSend(0, (SET_DDRAM | starting_line));

  // Load output string into the character array
  for (int i=0; i<output.length(); i++) {
    lcd_output[i] = output[i];
  }

  // Transmit the output array to the LCD
  Wire.beginTransmission(_address);
  Wire.write(0x40);               // preparatory code for data being sent
  for (int8_t i = 0; i < 20; i++) {
      Wire.write(lcd_output[i]);
      lcd_output[i] = 0x20;       // reset sent value to a blank space
  }
  Wire.endTransmission();
}
