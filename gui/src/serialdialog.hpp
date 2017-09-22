#ifndef SERIALDIALOG_HPP
#define SERIALDIALOG_HPP

#include <QDialog>

namespace Ui {
class SerialDialog;
}

class SerialDialog : public QDialog {
  Q_OBJECT

public:
  explicit SerialDialog(QWidget *parent = 0);
  ~SerialDialog();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::SerialDialog *ui;
};

#endif // SERIALDIALOG_HPP
