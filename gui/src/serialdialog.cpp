#include "serialdialog.hpp"
#include "ui_serialdialog.h"

SerialDialog::SerialDialog(Serial *serial, QWidget *parent)
    : QDialog(parent), ui(new Ui::SerialDialog), serial(serial) {
  ui->setupUi(this);

  clearInfo();
  initializeInfoEntryComboBox();

  try {
    isAnyInfoAvaiable();
    fillInfoDetailsTreeWidgetWithInfoNumber(0);
  } catch (...) {
  }
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

void SerialDialog::initializeInfoEntryComboBox() {
  for (auto i : serial->getInfo()) {
    try {
      isSerialInfoEntryAvaiable(&i);
      info.append(i);
      addItemToInfoEntryComboBox(i.portName);
    } catch (...) {
    }
  }
}

void SerialDialog::isSerialInfoEntryAvaiable(const SerialInfo *entry) {
  if (entry->isAviable == true)
    return;
  else
    throw 1;
}

void SerialDialog::addItemToInfoEntryComboBox(const QString &name) {
  ui->infoEntryComboBox->addItem(name);
}

void SerialDialog::isAnyInfoAvaiable() {
  if (info.size() != 0)
    return;
  else
    throw 1;
}

void SerialDialog::fillInfoDetailsTreeWidgetWithInfoNumber(const int &number) {
  try {
    isSerialInfoAvaiable(number);
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(
        0, QString(info[number].portName));
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(
        1, QString(info[number].vendorId));
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(
        2, QString(info[number].productId));
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(
        3, QString(info[number].baudRate));
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(
        4, QString(info[number].dataBits));
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(5,
                                                 QString(info[number].parity));
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(
        6, QString(info[number].stopBits));
    fillInfoDetailsTreeWidgetEntryNumberWithInfo(
        7, QString(info[number].flowControl));
  } catch (...) {
    throw 1;
  }
}

void SerialDialog::isSerialInfoAvaiable(const int &number) {
  if (number < info.size())
    return;
  else
    throw 1;
}

void SerialDialog::fillInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const QString &info) {
  QTreeWidgetItem *entry = ui->infoDetailsTreeWidget->topLevelItem(number);
  entry->setText(1, info);
  ui->infoDetailsTreeWidget->editItem(entry);
}

void SerialDialog::on_selectPushButton_clicked() {
  QString selectedPortName = ui->infoEntryComboBox->currentText();
  serial->selectSerialInfo(selectedPortName);
  close();
}
