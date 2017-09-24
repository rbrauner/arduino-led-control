#ifndef LCDVALUE_HPP
#define LCDVALUE_HPP

#include <QtCore/qglobal.h>

struct LcdValue {
public:
  enum LcdMinAndMax { MIN = 0, MAX = 254 };

  int getValue() const;
  void setValue(int value);

private:
  unsigned char value;
};

#endif // LCDVALUE_HPP
