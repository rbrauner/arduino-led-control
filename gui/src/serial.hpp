#ifndef SERIAL_HPP
#define SERIAL_HPP

#include "serialinfo.hpp"
#include <QVector>
#include <QtCore/qglobal.h>

class Serial {
public:
  Serial();

  void updateInfo();

private:
  QVector<SerialInfo> info;

  void clearInfo();
};

#endif // SERIAL_HPP
