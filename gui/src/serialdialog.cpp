#include "serialdialog.hpp"
#include "ui_serialdialog.h"

SerialDialog::SerialDialog(Serial *serial, QWidget *parent)
    : QDialog(parent), ui(new Ui::SerialDialog), serial(serial) {
  ui->setupUi(this);

  try {
    clearInfo();
    clearSelectedSerial();
    initializeInfoEntryComboBox();

    isAnyInfoAvaiable();
    fillInInfoDetailsTreeWidgetWithInfoNumber(0);
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

void SerialDialog::clearSelectedSerial() { serial->clearSelectedSerial(); }

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
  if (info.size() > 0)
    return;
  else
    throw 1;
}

void SerialDialog::fillInInfoDetailsTreeWidgetWithInfoNumber(
    const int &number) {
  try {
    isSerialInfoAvaiable(number);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(0, info[number].portName);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(1, info[number].vendorId);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(2, info[number].productId);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(3, info[number].baudRate);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(4, info[number].dataBits);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(5, info[number].parity);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(6, info[number].stopBits);
    fillInInfoDetailsTreeWidgetEntryNumberWithInfo(7, info[number].flowControl);
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

void SerialDialog::fillInInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const QString &info) {
  QTreeWidgetItem *entry = ui->infoDetailsTreeWidget->topLevelItem(number);
  entry->setText(1, info);
  ui->infoDetailsTreeWidget->editItem(entry);
}

void SerialDialog::fillInInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const quint16 &info) {
  fillInInfoDetailsTreeWidgetEntryNumberWithInfo(number, QString::number(info));
}

void SerialDialog::fillInInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const QSerialPort::BaudRate &info) {
  fillInInfoDetailsTreeWidgetEntryNumberWithInfo(number, QString::number(info));
}

void SerialDialog::fillInInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const QSerialPort::DataBits &info) {
  fillInInfoDetailsTreeWidgetEntryNumberWithInfo(number, QString::number(info));
}

void SerialDialog::fillInInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const QSerialPort::Parity &info) {
  fillInInfoDetailsTreeWidgetEntryNumberWithInfo(number, QString::number(info));
}

void SerialDialog::fillInInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const QSerialPort::StopBits &info) {
  fillInInfoDetailsTreeWidgetEntryNumberWithInfo(number, QString::number(info));
}

void SerialDialog::fillInInfoDetailsTreeWidgetEntryNumberWithInfo(
    const int &number, const QSerialPort::FlowControl &info) {
  fillInInfoDetailsTreeWidgetEntryNumberWithInfo(number, QString::number(info));
}

void SerialDialog::on_infoEntryComboBox_currentIndexChanged(int index) {
  fillInInfoDetailsTreeWidgetWithInfoNumber(index);
}

void SerialDialog::on_selectPushButton_clicked() {
  QString selectedPortName = ui->infoEntryComboBox->currentText();
  serial->selectSerialInfo(selectedPortName);
  close();
}
