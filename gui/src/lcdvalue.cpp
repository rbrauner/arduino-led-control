#include "src/lcdvalue.hpp"

LcdValue::LcdValue() : value(0) {

}

int LcdValue::getMin() const {
  return MIN;
}

int LcdValue::getMax() const {
  return MAX;
}

int LcdValue::getValue() const {
  return value;
}

void LcdValue::setValue(const int &value) {
  this->value = value;
}
