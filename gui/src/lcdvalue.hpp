#ifndef LCDVALUE_HPP
#define LCDVALUE_HPP

#include <QtCore/qglobal.h>

struct LcdValue {
  enum LcdMinAndMax {
    MIN = 0,
    MAX = 254
  };

  int value;
};

#endif // LCDVALUE_HPP
