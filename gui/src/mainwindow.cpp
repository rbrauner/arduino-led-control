#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setMinAndMaxDialValues();

  emit on_selectSerialPushButton_clicked();
}

MainWindow::~MainWindow() {
  closeSerial();
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

void MainWindow::setMinAndMaxDialValues() {
  ui->dial->setMinimum(lcdValue.MIN);
  ui->dial->setMaximum(lcdValue.MAX);
}

void MainWindow::on_selectSerialPushButton_clicked() {
  serial.updateInfo();
  serial.selectSerialInfoByDialog();
  openAndSetupSerial();

  QString statusBarMessage = serial.getSelectedSerialPortName();
  ui->statusBar->showMessage(statusBarMessage);
}

void MainWindow::openAndSetupSerial() { serial.openAndSetup(); }

void MainWindow::closeSerial() { serial.close(); }

void MainWindow::on_dial_valueChanged(int value) {
  setLcdValue(value);
  sendValueToSerial();
  updateLcd();
}

void MainWindow::setLcdValue(const int &value) { lcdValue.setValue(value); }

void MainWindow::sendValueToSerial() {
  serial << static_cast<char>(lcdValue.getValue());
}

void MainWindow::updateLcd() {
  int valueToDisplay = lcdValue.getValue();
  ui->lcdNumber->display(valueToDisplay);
}
