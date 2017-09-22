#include "serial.hpp"
#include <QList>
#include <QSerialPortInfo>

Serial::Serial() : selectedSerialInfo(0) { updateInfo(); }

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

void Serial::openAndSetup() {
  try {
    isSelectedSerialInfoValidAndAviable();
    serial.setPortName(selectedSerialInfo->portName);
    open(QIODevice::ReadWrite);
    setup();
  } catch (...) {
  }
}

void Serial::close() { serial.close(); }

void Serial::selectSerialInfo(const int &number) {
  selectedSerialInfo = &info[number];
}

const Serial &Serial::operator<<(const char &value) {
  prepareDataAndSendIt(value);
}

const Serial &Serial::operator<<(const short &value) {
  prepareDataAndSendIt(value);
}

const Serial &Serial::operator<<(const int &value) {
  prepareDataAndSendIt(value);
}

const Serial &Serial::operator<<(const long &value) {
  prepareDataAndSendIt(value);
}

const Serial &Serial::operator<<(const float &value) {
  prepareDataAndSendIt(value);
}

const Serial &Serial::operator<<(const double &value) {
  prepareDataAndSendIt(value);
}

const Serial &Serial::operator<<(const QString &value) {
  prepareDataAndSendIt(value);
}

const Serial &Serial::operator>>(QByteArray &value) { value = receive(); }

void Serial::isSerialOpen() {
  if (serial.isOpen())
    return;
  else
    throw;
}

void Serial::send(const QByteArray &data) { serial.write(data); }

QByteArray Serial::receive() { return serial.readAll(); }

void Serial::clearInfo() { info.clear(); }

void Serial::open(const QIODevice::OpenModeFlag &mode) { serial.open(mode); }

void Serial::setup() {
  serial.setBaudRate(selectedSerialInfo->baudRate);
  serial.setDataBits(selectedSerialInfo->dataBits);
  serial.setParity(selectedSerialInfo->parity);
  serial.setStopBits(selectedSerialInfo->stopBits);
  serial.setFlowControl(selectedSerialInfo->flowControl);
}

void Serial::isSelectedSerialInfoValidAndAviable() {
  if (selectedSerialInfo != NULL && selectedSerialInfo->isAviable == true)
    return;
  else
    throw;
}

void Serial::prepareDataAndSendIt(const QString &data) {
  try {
    const char *dataToSend = data.toStdString().c_str();
    isSerialOpen();
    send(dataToSend);
  } catch (...) {
  }
}

template <typename T> QByteArray Serial::prepareDataToSend(const T &data) {
  QByteArray dataToSend;
  dataToSend.resize(sizeof(T));
  dataToSend[0] = static_cast<char>(data);
  return dataToSend;
}

template <typename T> void Serial::prepareDataAndSendIt(const T &data) {
  try {
    QByteArray dataToSend = prepareDataToSend(data);
    isSerialOpen();
    send(dataToSend);
  } catch (...) {
  }
}
