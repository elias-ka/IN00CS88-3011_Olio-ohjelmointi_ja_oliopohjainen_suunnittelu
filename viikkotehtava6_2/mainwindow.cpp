#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
  ui->setupUi(this);
  operand = '\0';

  auto* grid = new QGridLayout;
  grid->setSpacing(2);

  auto* label1 = new QLabel("Number 1", this);
  grid->addWidget(label1, 0, 0);

  auto* label2 = new QLabel("Number 2", this);
  grid->addWidget(label2, 0, 1);

  auto* label3 = new QLabel("Result", this);
  grid->addWidget(label3, 0, 2);

  num1LineEdit = new QLineEdit(this);
  grid->addWidget(num1LineEdit, 1, 0);

  num2LineEdit = new QLineEdit(this);
  grid->addWidget(num2LineEdit, 1, 1);

  resultLineEdit = new QLineEdit(this);
  resultLineEdit->setReadOnly(true);
  grid->addWidget(resultLineEdit, 1, 2);

  for (int i = 0; i < 10; i++) {
    auto* button = new QPushButton(QString::number(i), this);
    connect(button, &QPushButton::clicked, this, [=]() {
      if (operand == '\0') {
        num1LineEdit->setText(num1LineEdit->text() + button->text());
      } else {
        num2LineEdit->setText(num2LineEdit->text() + button->text());
      }
    });
    grid->addWidget(button, i / 3 + 2, i % 3);
  }

  auto* plusButton = new QPushButton("+", this);
  grid->addWidget(plusButton, 2, 3);

  auto* minusButton = new QPushButton("-", this);
  grid->addWidget(minusButton, 3, 3);

  auto* multiplyButton = new QPushButton("*", this);
  grid->addWidget(multiplyButton, 4, 3);

  auto* divideButton = new QPushButton("/", this);
  grid->addWidget(divideButton, 5, 3);

  auto* clearButton = new QPushButton("Clear", this);
  grid->addWidget(clearButton, 5, 1);

  auto* enterButton = new QPushButton("Enter", this);
  grid->addWidget(enterButton, 5, 2);

  connect(plusButton, &QPushButton::clicked, this, [=]() {
    onOperandClicked('+');
  });
  connect(minusButton, &QPushButton::clicked, this, [=]() {
    onOperandClicked('-');
  });
  connect(multiplyButton, &QPushButton::clicked, this, [=]() {
    onOperandClicked('*');
  });
  connect(divideButton, &QPushButton::clicked, this, [=]() {
    onOperandClicked('/');
  });
  connect(
      clearButton, &QPushButton::clicked, this, [=]() { onClearClicked(); });
  connect(
      enterButton, &QPushButton::clicked, this, [=]() { onEnterClicked(); });

  auto* central = new QWidget;
  central->setLayout(grid);
  setCentralWidget(central);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::onOperandClicked(char operand) {
  this->operand = operand;
}

void MainWindow::onClearClicked() {
  num1LineEdit->setText("");
  num2LineEdit->setText("");
  resultLineEdit->setText("");
  operand = '\0';
}

void MainWindow::onEnterClicked() {
  const int num1 = num1LineEdit->text().toInt();
  const int num2 = num2LineEdit->text().toInt();

  double res = 0;

  if (operand == '+') {
    res = num1 + num2;
  } else if (operand == '-') {
    res = num1 - num2;
  } else if (operand == '*') {
    res = num1 * num2;
  } else if (operand == '/') {
    if (num2 == 0) {
      resultLineEdit->setText("Div by 0");
      return;
    }
    res = static_cast<double>(num1) / num2;
  }

  resultLineEdit->setText(QString::number(res));
}
