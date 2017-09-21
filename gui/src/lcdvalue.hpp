#ifndef LCDVALUE_HPP
#define LCDVALUE_HPP

#include <QtCore/qglobal.h>

class LcdValue {
public:
  LcdValue();

  void setValueByPercentage(int percentage);
  int getValue() const;

private:
  enum LcdMinAndMax {
    MIN = 0,
    MAX = 254
  };

  int value;

  static double percentageToFraction(int percentage);
};

#endif // LCDVALUE_HPP
