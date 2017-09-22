#include "serial.hpp"
#include <QList>
#include <QSerialPortInfo>

Serial::Serial() { updateInfo(); }

void Serial::updateInfo() {
  clearInfo();

  QList<QSerialPortInfo> avaliablePorts = QSerialPortInfo::availablePorts();
  int howManyToReserve = avaliablePorts.size();
  info.reserve(howManyToReserve);

  SerialInfo *infoEntry = &info[0];
  for (auto port : avaliablePorts) {
    infoEntry->isAviable = false;
    infoEntry->portName = "";
    infoEntry->vendorId = 0;
    infoEntry->productId = 0;

    if (port.hasVendorIdentifier()) {
      infoEntry->vendorId = port.vendorIdentifier();
      if (port.hasProductIdentifier()) {
        infoEntry->productId = port.productIdentifier();
        infoEntry->portName = port.portName();
        infoEntry->isAviable = true;
      }
    }

    infoEntry->baudRate = QSerialPort::Baud9600;
    infoEntry->dataBits = QSerialPort::Data8;
    infoEntry->parity = QSerialPort::NoParity;
    infoEntry->stopBits = QSerialPort::OneStop;
    infoEntry->flowControl = QSerialPort::NoFlowControl;

    infoEntry++;
  }
}

void Serial::clearInfo() { info.clear(); }
