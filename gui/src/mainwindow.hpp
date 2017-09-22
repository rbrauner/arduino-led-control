#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "lcdvalue.hpp"
#include <QSerialPort>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
  void changeEvent(QEvent *e);

private slots:
  void on_dial_valueChanged(int value);

private:
  Ui::MainWindow *ui;
  LcdValue lcdValue;
  QSerialPort serial;

  void setMinAndMaxDialValues();

  void setSerialPortName(QString portName);
  void openAndSetupSerial();
  void openSerial(const QIODevice::OpenModeFlag &mode);
  void setupSerial();
  void closeSerial();

  void setLcdValue(const int &value);
  void sendValueToSerial();
  void updateLcd();
};

#endif // MAINWINDOW_HPP
