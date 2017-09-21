#include <Arduino.h>
extern HardwareSerial Serial;

namespace au {
  void turnOn(const int &pin) {
    digitalWrite(pin, HIGH);
	}

  void turnOff(const int &pin) {
    digitalWrite(pin, LOW);
	}

  // OStreamKeywords
  class OStreamKeywords {};
  class Endl : public OStreamKeywords {};
  class Flush : public OStreamKeywords {};
  static Endl endl;
  static Flush flush;

  // Serial operator<<
  HardwareSerial &operator<<(HardwareSerial &serial, const __FlashStringHelper *value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, const String &value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, const char *value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, char value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, unsigned char value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, const int &value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, unsigned int value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, long value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, unsigned long value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, double value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, const Printable &value) {
    serial.print(value);
	}

  HardwareSerial &operator<<(HardwareSerial &serial, const Endl &value) {
    serial.println();
	}

  HardwareSerial &operator<<(HardwareSerial &serial, const Flush &value) {
    serial.flush();
	}

  // Serial operator>>
  HardwareSerial &operator>>(HardwareSerial &serial, int &value) {
    value = serial.read();
	}
}
