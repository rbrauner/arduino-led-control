#include "lcdvalue.hpp"

LcdValue::LcdValue() : value(0) {}

int LcdValue::getValue() const { return static_cast<int>(value); }

void LcdValue::setValue(int value) {
  this->value = static_cast<unsigned char>(value);
}
