/*
  File Name: LCD_display.ino
  Created By: Stephen Trotnic
  Date: December 2nd, 2018
  Purpose: Test application for NewHaven NHD-0420CW-AB3 OLED display
  Released into the public domain.
*/

/* LIBRARY INCLUDES */
#include <Wire.h>
#include <SPI.h>
#include "port.h"
#include "lcd.h"

//SPISettings settingsA(<speed>, <data_order>, <data_mode>); //device 1
//SPISettings settingsB(<speed>, <data_order>, <data_mode>); //device 2

LCD lcd;

void setup() {
  // COMMUNICATIONS INITIALIZATION
  //Serial.begin(9600);
  Wire.begin();
  //SPI.begin();

  // HARDWARE INITIALIZATION
  portInit();
  lcd.init();

  // Test of string output to display
  String output = "hello";
  lcd.stringSend(lcd.lcd_ddram_lines[4], output);

  // Test of character output to display
  delay(2000);
  lcd.byteSend(0, 0xA0); //manually change the output address
  lcd.byteSend(1, 'H');
  lcd.byteSend(1, 'i');
}

void loop() {
  
}
