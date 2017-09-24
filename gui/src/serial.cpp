#include "serial.hpp"
#include <QList>
#include <QSerialPortInfo>

Serial::Serial() : selectedSerialInfo(0) { updateInfo(); }

void Serial::updateInfo() {
  try {
    clearInfo();
    clearSelectedSerial();

    QList<QSerialPortInfo> avaliablePorts = QSerialPortInfo::availablePorts();
    int howManyToReserve = avaliablePorts.size();
    info.resize(howManyToReserve);

    isAnyInfoAvaiable();
    SerialInfo *infoEntry = &info[0];

    for (QSerialPortInfo port : avaliablePorts) {
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
  } catch (...) {
  }
}

void Serial::clearInfo() { info.clear(); }

void Serial::clearSelectedSerial() { selectedSerialInfo = 0; }

void Serial::isAnyInfoAvaiable() {
  if (info.size() > 0)
    return;
  else
    throw 1;
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

void Serial::isSelectedSerialInfoValidAndAviable() {
  if (selectedSerialInfo != NULL && selectedSerialInfo->isAviable == true)
    return;
  else
    throw 1;
}

void Serial::open(const QIODevice::OpenModeFlag &mode) { serial.open(mode); }

void Serial::close() { serial.close(); }

void Serial::setup() {
  serial.setBaudRate(selectedSerialInfo->baudRate);
  serial.setDataBits(selectedSerialInfo->dataBits);
  serial.setParity(selectedSerialInfo->parity);
  serial.setStopBits(selectedSerialInfo->stopBits);
  serial.setFlowControl(selectedSerialInfo->flowControl);
}

const QVector<SerialInfo> Serial::getInfo() const { return info; }

void Serial::selectSerialInfo(const int &number) {
  selectedSerialInfo = &info[number];
}

void Serial::selectSerialInfo(const QString &portName) {
  bool condition = true;
  for (int i = 0; i < info.size(); i++) {
    if (condition) {
      if (info[i].portName == portName) {
        selectedSerialInfo = &info[i];
        condition = true;
      }
    }
  }
}

void Serial::selectSerialInfoByDialog() {
  SerialDialog dialog(this);
  dialog.exec();
}

const Serial &Serial::operator<<(const char &value) {
  prepareDataAndSendIt<char>(value);
}

const Serial &Serial::operator>>(QByteArray &value) { value = receive(); }

template <typename T> void Serial::prepareDataAndSendIt(const T &data) {
  try {
    QByteArray dataToSend = prepareDataToSend<T>(data);
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

void Serial::isSerialOpen() {
  if (serial.isOpen())
    return;
  else
    throw 1;
}

void Serial::send(const QByteArray &data) { serial.write(data); }

QByteArray Serial::receive() { return serial.readAll(); }
