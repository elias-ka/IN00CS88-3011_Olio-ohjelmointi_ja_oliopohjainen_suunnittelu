#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void onOperandClicked(char operand);
  void onClearClicked();
  void onEnterClicked();

private:
  Ui::MainWindow* ui;
  QLineEdit* num1LineEdit;
  QLineEdit* num2LineEdit;
  QLineEdit* resultLineEdit;
  char operand;
};
#endif  // MAINWINDOW_H
