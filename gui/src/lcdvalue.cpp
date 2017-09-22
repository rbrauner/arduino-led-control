#include "src/lcdvalue.hpp"

LcdValue::LcdValue() : value(0) {

}

int LcdValue::getMin() const {
  return MIN;
}

int LcdValue::getMax() const {
  return MAX;
}

void LcdValue::setValueByPercentage(int percentage) {
  double valueWithMorePrecision = 0;
  valueWithMorePrecision = percentageToFraction(percentage) * 254.0;
  value = static_cast<int>(valueWithMorePrecision);
}

int LcdValue::getValue() const {
  return value;
}

double LcdValue::percentageToFraction(int percentage) {
  return (percentage / 100.0);
}
