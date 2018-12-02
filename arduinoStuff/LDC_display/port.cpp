#include "Arduino.h"
#include "port.h"

void portInit() {
  /* DIGITAL PIN INITIALIZATION */
  //(DIGITAL_PIN_TYPE[0]  == 0) ? pinMode(RX,  OUTPUT) : pinMode(RX,  INPUT);
  //(DIGITAL_PIN_TYPE[1]  == 0) ? pinMode(TX,  OUTPUT) : pinMode(TX,  INPUT);
  //(DIGITAL_PIN_TYPE[2]  == 0) ? pinMode(D2,  OUTPUT) : pinMode(D2,  INPUT);
  //(DIGITAL_PIN_TYPE[3]  == 0) ? pinMode(D3,  OUTPUT) : pinMode(D3,  INPUT);
  //(DIGITAL_PIN_TYPE[4]  == 0) ? pinMode(D4,  OUTPUT) : pinMode(D4,  INPUT);
  //(DIGITAL_PIN_TYPE[5]  == 0) ? pinMode(D5,  OUTPUT) : pinMode(D5,  INPUT);
  (DIGITAL_PIN_TYPE[6]  == 0) ? pinMode(D6,  OUTPUT) : pinMode(D6,  INPUT);
  //(DIGITAL_PIN_TYPE[7]  == 0) ? pinMode(D7,  OUTPUT) : pinMode(D7,  INPUT);
  //(DIGITAL_PIN_TYPE[8]  == 0) ? pinMode(D8,  OUTPUT) : pinMode(D8,  INPUT);
  //(DIGITAL_PIN_TYPE[9]  == 0) ? pinMode(D9,  OUTPUT) : pinMode(D9,  INPUT);
  //(DIGITAL_PIN_TYPE[10] == 0) ? pinMode(D10, OUTPUT) : pinMode(D10, INPUT);
  //(DIGITAL_PIN_TYPE[11] == 0) ? pinMode(D11, OUTPUT) : pinMode(D11, INPUT);
  //(DIGITAL_PIN_TYPE[12] == 0) ? pinMode(D12, OUTPUT) : pinMode(D12, INPUT);
  //(DIGITAL_PIN_TYPE[13] == 0) ? pinMode(D13, OUTPUT) : pinMode(D13, INPUT);

  //(DIGITAL_PIN_INIT_VALUE[0]  == 0) ? digitalWrite(RX,  LOW) : digitalWrite(RX,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[1]  == 0) ? digitalWrite(TX,  LOW) : digitalWrite(TX,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[2]  == 0) ? digitalWrite(D2,  LOW) : digitalWrite(D2,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[3]  == 0) ? digitalWrite(D3,  LOW) : digitalWrite(D3,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[4]  == 0) ? digitalWrite(D4,  LOW) : digitalWrite(D4,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[5]  == 0) ? digitalWrite(D5,  LOW) : digitalWrite(D5,  HIGH);
  (DIGITAL_PIN_INIT_VALUE[6]  == 0) ? digitalWrite(D6,  LOW) : digitalWrite(D6,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[7]  == 0) ? digitalWrite(D7,  LOW) : digitalWrite(D7,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[8]  == 0) ? digitalWrite(D8,  LOW) : digitalWrite(D8,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[9]  == 0) ? digitalWrite(D9,  LOW) : digitalWrite(D9,  HIGH);
  //(DIGITAL_PIN_INIT_VALUE[10] == 0) ? digitalWrite(D10, LOW) : digitalWrite(D10, HIGH);
  //(DIGITAL_PIN_INIT_VALUE[11] == 0) ? digitalWrite(D11, LOW) : digitalWrite(D11, HIGH);
  //(DIGITAL_PIN_INIT_VALUE[12] == 0) ? digitalWrite(D12, LOW) : digitalWrite(D12, HIGH);
  //(DIGITAL_PIN_INIT_VALUE[13] == 0) ? digitalWrite(D13, LOW) : digitalWrite(D13, HIGH);
  
  /* ANALOG PIN INITIALIZATION */
  //analogWrite(A0, ANALOG_PIN_INIT_VALUE[0]);
  //analogWrite(A1, ANALOG_PIN_INIT_VALUE[1]);
  //analogWrite(A2, ANALOG_PIN_INIT_VALUE[2]);
  //analogWrite(A3, ANALOG_PIN_INIT_VALUE[3]);
  //analogWrite(A4, ANALOG_PIN_INIT_VALUE[4]);
  //analogWrite(A5, ANALOG_PIN_INIT_VALUE[5]);
}
