/*
  File Name: rotary_encoder.h
  Created By: Stephen Trotnic
  Date: December 12th, 2018
  Purpose: Rotary Encoder driver library for Bourns PEC11 Series
  Released into the public domain.
*/

#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include "port.h"

class ClickEncoder {
  public:
    uint8_t buttonState();
    void encoder();
    void printButtonState(uint8_t button);
    const uint8_t OFF = 0;
    const uint8_t MOMENTARY = 1;
    const uint8_t LATCHED = 2;
    const uint8_t DOUBLE_CLICK = 3;
  private:
    const uint16_t _debounce_delay = 10;
    const uint16_t _momentary_delay = 250;
    const uint16_t _double_click_delay = 500;
};

#endif
