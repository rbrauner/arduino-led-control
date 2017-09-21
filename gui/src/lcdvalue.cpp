#include "src/lcdvalue.hpp"

LcdValue::LcdValue() : value(0) {

}

void LcdValue::setValueByPercentage(int percentage) {
  value = percentageToFraction(percentage) * MAX;
}

int LcdValue::getValue() const {
  return value;
}

double LcdValue::percentageToFraction(int percentage) {
  return percentage / 100;
}
