#ifndef SERIALDIALOG_HPP
#define SERIALDIALOG_HPP

#include "serialinfo.hpp"
#include <QDialog>
#include <QVector>

namespace Ui {
class SerialDialog;
}

class SerialDialog : public QDialog {
  Q_OBJECT

public:
  explicit SerialDialog(QVector<const SerialInfo *> info, QWidget *parent = 0);
  ~SerialDialog();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::SerialDialog *ui;
  QVector<SerialInfo> info;

  void clearInfo();
  void initializeInfoEntryComboBox(QVector<const SerialInfo *> &info);
  void isSerialInfoEntryAvaiable(const SerialInfo *entry);
  void addItemToInfoEntryComboBox(const QString &name);
  void isAnyInfoAvaiable();
  void fillInfoDetailsTreeWidgetWithInfoNumber(const int &number);
  void isSerialInfoAvaiable(const int &number);
  void fillInfoDetailsTreeWidgetEntryNumberWithInfo(const int &number,
                                                    const QString &info);
};

#endif // SERIALDIALOG_HPP
