#include <QPushButton>
#include <QString>

#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  count_button_ = new QPushButton("Count", this);
  reset_button_ = new QPushButton("Reset", this);

  line_edit_ = new QLineEdit(this);
  line_edit_->setReadOnly(true);
  line_edit_->setText(QString::number(count_));

  ui_->horizontalLayout->addWidget(count_button_);
  ui_->horizontalLayout->addWidget(reset_button_);
  ui_->horizontalLayout->addWidget(line_edit_);

  connect(count_button_,
          &QPushButton::clicked,
          this,
          &MainWindow::onCountButtonClick);

  connect(reset_button_,
          &QPushButton::clicked,
          this,
          &MainWindow::onResetButtonClick);
}

MainWindow::~MainWindow() {
  delete ui_;
}

void MainWindow::onResetButtonClick() {
  count_ = 0;
  line_edit_->setText("0");
}

void MainWindow::onCountButtonClick() {
  ++count_;
  line_edit_->setText(QString::number(count_));
}
