#include <Arduino.h>
#include "arduino-utils.hpp"
using namespace au;

const int BUILT_IN_LED = 13;
const int LED = 3;

bool isValueInRangeOfPwm(int value);

int main() {
  init();
  Serial.begin(9600);

  int ledBrightness = 0;
  int tempLedBrightness = 0;

  pinMode(BUILT_IN_LED, OUTPUT);
  pinMode(LED, OUTPUT);

  while (true) {
    if (Serial.available()) {
      Serial >> tempLedBrightness;
      ledBrightness = tempLedBrightness;

      if (isValueInRangeOfPwm(ledBrightness)) {
        analogWrite(LED, ledBrightness);
      }
    }
  }
}

bool isValueInRangeOfPwm(int value) {
  bool result = false;

  if (value >= 0 && value < 255) { result = true; }

  return result;
}
