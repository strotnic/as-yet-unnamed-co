/* LIBRARY INCLUDES */
#include <Wire.h>
#include "port.h"
#include "lcd.h"

LCD lcd;

void setup() {
  // COMMUNICATIONS INITIALIZATION
  Wire.begin();
  Serial.begin(9600);

  // HARDWARE INITIALIZATION
  portInit();
  lcd.lcdInit();

  String output = "hello";
  for (int i=0; i<output.length(); i++) {
    lcd.lcd_output[i] = output[i];
  }
  lcd.lcdPrintString(lcd.lcd_ddram_lines[1]);

  delay(2000);
  lcd.lcdByte(0, 0xA0);
  lcd.lcdByte(1, 'H');
  lcd.lcdByte(1, 'i');
}

void loop() {
  
}
