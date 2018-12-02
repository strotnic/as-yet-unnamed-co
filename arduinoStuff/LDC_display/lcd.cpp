#include "lcd.h"

void LCD::lcdInit() {
    // Initialization routine
    byte lcd_init_values[] = {byte(0x22 | _lcd_rows), 0x71, 0x5C, byte(0x20 | _lcd_rows), 0x08, byte(0x22 | _lcd_rows), 0x79, 0xD5, 0x70, 0x78,
                               byte(_lcd_num_rows > 2 ? 0x09 : 0x08), 0x06, 0x72, 0x00, 0x79, 0xDA, 0x10, 0x81, 0x7F, 0xD9,
                               0xF1, 0xDB, 0x40, 0x78, byte(0x20 | _lcd_rows)
                              };

    digitalWrite(RST_n, HIGH);
    delay(200);

    // Cycle through the initialization routuine
    for (byte init_count = 0; init_count < (sizeof(lcd_init_values)/sizeof(byte)); init_count++) {
        // Check for command/data types in the inialization routine
        ((init_count == 2) || (init_count == 13)) ? lcdByte(1, lcd_init_values[init_count]) : lcdByte(0, lcd_init_values[init_count]);
    }
    // Clear and Turning on the LCD require delays
    lcdByte(0, 0x01);
    delay(2);
    lcdByte(0, 0x0F);
    delay(250);
}

void LCD::lcdByte(byte type, byte value) {
    Wire.beginTransmission(_lcd_address);
    Wire.write(type<<6);
    Wire.write(value);
    Wire.endTransmission();
}

void LCD::lcdPrintString(byte starting_line) {
    //lcdByte(0, (SET_DDRAM | starting_line));
    Wire.beginTransmission(_lcd_address);
    Wire.write(0x40);
    for (byte i = 0; i < 20; i++) {
        Wire.write(lcd_output[i]);
        lcd_output[i] = 0x20;
    }
    Wire.endTransmission();
    
}
