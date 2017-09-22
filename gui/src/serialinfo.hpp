#ifndef SERIALINFO_HPP
#define SERIALINFO_HPP

#include <QSerialPort>
#include <QString>

struct SerialInfo {
  bool isAviable;
  QString portName;
  const quint16 vendorId;
  const quint16 productId;
  QSerialPort::BaudRate baudRate;
  QSerialPort::DataBits dataBits;
  QSerialPort::Parity parity;
  QSerialPort::StopBits stopBits;
  QSerialPort::FlowControl flowControl;
};

#endif // SERIALINFO_HPP
