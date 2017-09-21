#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
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

void MainWindow::setLcdValueByPercentage(const int &percentage) {
  lcdValue.setValueByPercentage(percentage);
}

void MainWindow::sendValueToSerial() {

}

void MainWindow::updateLcd() {
  int valueToDisplay = lcdValue.getValue();
  ui->lcdNumber->display(valueToDisplay);
}
