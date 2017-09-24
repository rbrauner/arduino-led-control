#include "lcdvalue.hpp"

int LcdValue::getValue() const { return static_cast<int>(value); }

void LcdValue::setValue(int value) {
  this->value = static_cast<unsigned char>(value);
}
