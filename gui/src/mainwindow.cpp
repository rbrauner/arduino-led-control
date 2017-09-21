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
  setLcd(position);
}

void MainWindow::setLcd(const int &value) {
  lcdValue.setValueByPercentage(value);
  int valueToDisplay = lcdValue.getValue();
  ui->lcdNumber->display(valueToDisplay);
}
