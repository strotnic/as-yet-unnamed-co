/*
  File Name: rotary_encoder.ino
  Created By: Stephen Trotnic
  Date: December 11th, 2018
  Purpose: Test application for Bourns PEC11 Series Rotary Encoder
  Released into the public domain.
*/

/* LIBRARY INCLUDES */
#include "port.h"
#include "rotary_encoder.h"

ClickEncoder rotary_encoder;

uint8_t button=0, left=0, right=0;
uint8_t last_button=0;

void setup() {
  // COMMUNICATIONS INITIALIZATION
  Serial.begin(9600);
  //Wire.begin();
  //SPI.begin();

  // HARDWARE INITIALIZATION
  portInit();

}

void loop() {
  button = rotary_encoder.buttonState();
  if (button != last_button) {
    rotary_encoder.printButtonState(button);
  }
  last_button = button;
  
}
