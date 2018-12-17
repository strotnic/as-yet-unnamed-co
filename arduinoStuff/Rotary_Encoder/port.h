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

//#define int8_t char;
//#define int16_t int;
//#define int32_t long;
//#define uint8_t unsigned char;
//#define uint16_t unsigned int;
//#define uint32_t unsigned long;

/* DEFAULT PIN DEFINITIONS */
const uint8_t RX  = 0;
const uint8_t TX  = 1;
const uint8_t D2  = 2;
const uint8_t D3  = 3;
const uint8_t D4  = 4;
const uint8_t D5  = 5;
const uint8_t D6  = 6;
const uint8_t D7  = 7;
const uint8_t D8  = 8;
const uint8_t D9  = 9;
const uint8_t D10 = 10;
const uint8_t D11 = 11;
const uint8_t D12 = 12;
const uint8_t D13 = 13;
const int8_t  DIGITAL_PIN_TYPE[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const int8_t  DIGITAL_PIN_INIT_VALUE[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
const uint16_t ANALOG_PIN_INIT_VALUE[6] = {0, 0, 0, 0, 0, 0};

/* APPLICATION SPECIFIC PINS */
const uint8_t ROTARY_LEFT = D10;
const uint8_t ROTARY_RIGHT = D11;
const uint8_t ROTARY_BUTTON = D12;

void portInit();

#endif
