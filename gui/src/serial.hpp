#ifndef SERIAL_HPP
#define SERIAL_HPP

#include "serialinfo.hpp"
#include <QSerialPort>
#include <QVector>
#include <QtCore/qglobal.h>

class Serial {
public:
  Serial();

  void updateInfo();
  void openAndSetup();
  void close();

  const QVector<SerialInfo> getInfo() const;
  void selectSerialInfo(const int &number);
  void selectSerialInfo(const QString &portName);
  void selectSerialInfoByDialog();

  const Serial &operator<<(const char &value);
  const Serial &operator<<(const short &value);
  const Serial &operator<<(const int &value);
  const Serial &operator<<(const long &value);
  const Serial &operator<<(const float &value);
  const Serial &operator<<(const double &value);
  const Serial &operator<<(const QString &value);

  const Serial &operator>>(QByteArray &value);

private:
  QSerialPort serial;
  QVector<SerialInfo> info;
  const SerialInfo *selectedSerialInfo;

  void clearInfo();
  void open(const QIODevice::OpenModeFlag &mode);
  void setup();
  void isSelectedSerialInfoValidAndAviable();

  template <typename T> void prepareDataAndSendIt(const T &data);
  void prepareDataAndSendIt(const QString &data);
  template <typename T> QByteArray prepareDataToSend(const T &data);
  void isSerialOpen();

  void send(const QByteArray &data);
  QByteArray receive();
};

#endif // SERIAL_HPP
