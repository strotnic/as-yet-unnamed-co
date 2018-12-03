/*
  File Name: port.h
  Created By: Stephen Trotnic
  Date: December 2nd, 2018
  Purpose: Port manipulation for Arduino Uno
  Released into the public domain.
*/

#ifndef PORT_H
#define PORT_H

#include "Arduino.h"

/* DEFAULT PIN DEFINITIONS */
const byte RX  = 0;
const byte TX  = 1;
const byte D2  = 2;
const byte D3  = 3;
const byte D4  = 4;
const byte D5  = 5;
const byte D6  = 6;
const byte D7  = 7;
const byte D8  = 8;
const byte D9  = 9;
const byte D10 = 10;
const byte D11 = 11;
const byte D12 = 12;
const byte D13 = 13;
const char DIGITAL_PIN_TYPE[16] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
const char DIGITAL_PIN_INIT_VALUE[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int ANALOG_PIN_INIT_VALUE[6] = {0, 0, 0, 0, 0, 0};

/* APPLICATION SPECIFIC PINS */
const byte RST_n = D6;

void portInit();

#endif
