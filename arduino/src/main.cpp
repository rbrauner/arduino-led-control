#include <Arduino.h>
#include "arduino-utils.hpp"
using namespace au;

const int BUILT_IN_LED = 13;

int main() {
  init();
  Serial.begin(9600);
	
  pinMode(BUILT_IN_LED, OUTPUT);
  pinMode(LED, OUTPUT);

  while (true) {

  }
}
