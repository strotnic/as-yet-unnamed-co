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
  lcd.lcdInit();

  String output = "hello";
  lcd.lcdPrintString(lcd.lcd_ddram_lines[4], output);

  delay(2000);
  lcd.lcdByte(0, 0xA0);
  lcd.lcdByte(1, 'H');
  lcd.lcdByte(1, 'i');
}

void loop() {
  
}
