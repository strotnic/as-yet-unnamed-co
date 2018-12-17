/*
  File Name: rotary_encoder.cpp
  Created By: Stephen Trotnic
  Date: December 12th, 2018
  Purpose: Rotary Encoder hardware driver for Bourns PEC11 Series
  Released into the public domain.
*/

#include "rotary_encoder.h"

uint8_t ClickEncoder::buttonState() {
  static uint32_t last_change_time=0, double_click_time=0;
  static uint8_t last_state=0, current_state=0, button_state=0;
  static uint8_t debounce_state=LOW, click_state=LOW, double_click_state=0;

  current_state = digitalRead(ROTARY_BUTTON);

  if ((current_state != last_state) && !debounce_state) {
    debounce_state = HIGH;
    if (current_state < last_state) {
      double_click_time = last_change_time;
      double_click_state++;
      button_state = MOMENTARY;
    }
    else if (current_state > last_state) {
      if (double_click_state >= 1) {
        button_state = DOUBLE_CLICK;
      }
      else if ((button_state == MOMENTARY) && ((millis() - last_change_time) < _momentary_delay)) {
        if (click_state) {
          button_state = OFF;
        }
        else {
          button_state = LATCHED;
        }
        click_state = !click_state;
      }
      else {
        button_state = OFF;
      }
    }
    last_change_time = millis();
  }

  if (((millis() - last_change_time) > _debounce_delay) && debounce_state) {
    debounce_state = LOW;
    last_state = current_state;
  }

  if ((millis() - double_click_time) > _double_click_delay) {
    double_click_state = 0;
  }

  return button_state;
}

void ClickEncoder::printButtonState(uint8_t button) {
  if (button == OFF) {
    Serial.println("Off");
  }
  if (button == MOMENTARY) {
    Serial.println("Momentary");
  }
  if (button == LATCHED) {
    Serial.println("Latched");
  }
  if (button == DOUBLE_CLICK) {
    Serial.println("Double click");
  }
}
