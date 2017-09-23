#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setMinAndMaxDialValues();

  serial.updateInfo();
  serial.selectSerialInfoByDialog();

  openAndSetupSerial();
}

void MainWindow::setMinAndMaxDialValues() {
  ui->dial->setMinimum(lcdValue.MIN);
  ui->dial->setMaximum(lcdValue.MAX);
}

void MainWindow::openAndSetupSerial() { serial.openAndSetup(); }

void MainWindow::closeSerial() { serial.close(); }

MainWindow::~MainWindow() { delete ui; }

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

void MainWindow::setLcdValue(const int &value) { lcdValue.value = value; }

void MainWindow::sendValueToSerial() { serial << lcdValue.value; }

void MainWindow::updateLcd() {
  int valueToDisplay = lcdValue.value;
  ui->lcdNumber->display(valueToDisplay);
}

void MainWindow::on_selectSerialPushButton_clicked() {
  serial.updateInfo();
  serial.selectSerialInfoByDialog();
}
