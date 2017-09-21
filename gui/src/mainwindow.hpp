#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QMainWindow>
#endif

#include "lcdvalue.hpp"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
  void changeEvent(QEvent *e);

private slots:
  void on_dial_sliderMoved(int position);

private:
  Ui::MainWindow *ui;
  LcdValue lcdValue;

  void setLcdValueByPercentage(const int &percentage);
  void sendValueToSerial();
  void updateLcd();
};

#endif // MAINWINDOW_HPP
