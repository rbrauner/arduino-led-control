#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), serial(this) {
  ui->setupUi(this);
  setupSerial();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::changeEvent(QEvent *e) {
  QMainWindow::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
  }
}

void MainWindow::on_dial_sliderMoved(int position) {
  setLcdValueByPercentage(position);
  sendValueToSerial();
  updateLcd();
}

void MainWindow::setupSerial() {
  serial.setPortName("ttyACM0");
  serial.setBaudRate(serial.Baud9600);
  serial.setDataBits(QSerialPort::Data8);
  serial.setParity(QSerialPort::NoParity);
  serial.setStopBits(QSerialPort::OneStop);
  serial.setFlowControl(QSerialPort::NoFlowControl);
}

void MainWindow::setLcdValueByPercentage(const int &percentage) {
  lcdValue.setValueByPercentage(percentage);
}

void MainWindow::sendValueToSerial() {
  char tempValue = static_cast<char>(lcdValue.getValue());
  char *valueToSend = &tempValue;

  serial.open(QIODevice::WriteOnly);
  serial.write(valueToSend);
  serial.flush();
  serial.close();
}

void MainWindow::updateLcd() {
  int valueToDisplay = lcdValue.getValue();
  ui->lcdNumber->display(valueToDisplay);
}
