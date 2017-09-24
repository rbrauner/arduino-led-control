#ifndef SERIALINFO_HPP
#define SERIALINFO_HPP

#include <QSerialPort>
#include <QString>

struct SerialInfo {
  bool isAviable = false;
  QString portName = "";
  quint16 vendorId = 0;
  quint16 productId = 0;
  QSerialPort::BaudRate baudRate = QSerialPort::UnknownBaud;
  QSerialPort::DataBits dataBits = QSerialPort::UnknownDataBits;
  QSerialPort::Parity parity = QSerialPort::UnknownParity;
  QSerialPort::StopBits stopBits = QSerialPort::UnknownStopBits;
  QSerialPort::FlowControl flowControl = QSerialPort::UnknownFlowControl;
};

#endif // SERIALINFO_HPP
