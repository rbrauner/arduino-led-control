#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "lcdvalue.hpp"
#include "serial.hpp"
#include "serialdialog.hpp"
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
  void on_selectSerialPushButton_clicked();

private:
  Ui::MainWindow *ui;
  LcdValue lcdValue;
  Serial serial;

  void setMinAndMaxDialValues();

  void openAndSetupSerial();
  void closeSerial();

  void setLcdValue(const int &value);
  void sendValueToSerial();
  void updateLcd();
};

#endif // MAINWINDOW_HPP
