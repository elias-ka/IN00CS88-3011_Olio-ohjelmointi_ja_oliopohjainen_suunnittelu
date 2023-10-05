#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setFixedSize(300, 200);
  w.setWindowTitle("Calculator");
  w.show();
  return a.exec();
}
