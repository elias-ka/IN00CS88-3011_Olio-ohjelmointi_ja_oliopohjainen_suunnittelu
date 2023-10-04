#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void onCountButtonClick();
  void onResetButtonClick();

signals:
  void countChanged();

private:
  Ui::MainWindow* ui_;
  QPushButton* count_button_;
  QPushButton* reset_button_;
  QLineEdit* line_edit_;
  QVBoxLayout* layout_;
  int count_{};
};
#endif  // MAINWINDOW_H
