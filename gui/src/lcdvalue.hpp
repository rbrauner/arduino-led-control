#ifndef LCDVALUE_HPP
#define LCDVALUE_HPP

#include <QtCore/qglobal.h>

class LcdValue {
public:
  LcdValue();

  int getMin() const;
  int getMax() const;

  int getValue() const;
  void setValue(const int &value);

private:
  enum LcdMinAndMax {
    MIN = 0,
    MAX = 254
  };

  int value;
};

#endif // LCDVALUE_HPP
