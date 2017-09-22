#include "serialdialog.hpp"
#include "ui_serialdialog.h"

SerialDialog::SerialDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::SerialDialog) {
  ui->setupUi(this);
}

SerialDialog::~SerialDialog() { delete ui; }

void SerialDialog::changeEvent(QEvent *e) {
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}
