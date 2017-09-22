#include "serialdialog.hpp"
#include "ui_serialdialog.h"

SerialDialog::SerialDialog(QVector<const SerialInfo *> info, QWidget *parent)
    : QDialog(parent), ui(new Ui::SerialDialog) {
  ui->setupUi(this);

  clearInfo();
  initializeInfoEntryComboBox(info);
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

void SerialDialog::clearInfo() { info.clear(); }

void SerialDialog::initializeInfoEntryComboBox(
    QVector<const SerialInfo *> &info) {
  for (auto i : info) {
    try {
      isAvaiable(i);
      info.append(i);
      addItemToInfoEntryComboBox(i->portName);
    } catch (...) {
    }
  }
}

void SerialDialog::isAvaiable(const SerialInfo *entry) {
  if (entry->isAviable == true)
    return;
  else
    throw;
}

void SerialDialog::addItemToInfoEntryComboBox(const QString &name) {
  ui->infoEntryComboBox->addItem(name);
}
