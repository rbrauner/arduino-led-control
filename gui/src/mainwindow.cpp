#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), serial(this) {
  ui->setupUi(this);

  setMinAndMaxDialValues();

  setSerialPortName("ttyACM0");
  openAndSetupSerial();
}

void MainWindow::setMinAndMaxDialValues() {
  ui->dial->setMinimum(lcdValue.MIN);
  ui->dial->setMaximum(lcdValue.MAX);
}

void MainWindow::setSerialPortName(QString portName) {
  serial.setPortName(portName);
}

void MainWindow::openAndSetupSerial() {
  openSerial(QIODevice::ReadWrite);
  setupSerial();
}

void MainWindow::openSerial(const QIODevice::OpenModeFlag &mode) {
  serial.open(mode);
}

void MainWindow::setupSerial() {
  serial.setBaudRate(serial.Baud9600);
  serial.setDataBits(QSerialPort::Data8);
  serial.setParity(QSerialPort::NoParity);
  serial.setStopBits(QSerialPort::OneStop);
  serial.setFlowControl(QSerialPort::NoFlowControl);
}

void MainWindow::closeSerial() {
  serial.close();
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

void MainWindow::on_dial_valueChanged(int value) {
  setLcdValue(value);
  sendValueToSerial();
  updateLcd();
}

void MainWindow::setLcdValue(const int &value) {
  lcdValue.value = value;
}

void MainWindow::sendValueToSerial() {
  QByteArray valueToSend;
  valueToSend.resize(1);
  valueToSend[0] = static_cast<char>(lcdValue.value);

  serial.write(valueToSend);
  serial.flush();
}

void MainWindow::updateLcd() {
  int valueToDisplay = lcdValue.value;
  ui->lcdNumber->display(valueToDisplay);
}
