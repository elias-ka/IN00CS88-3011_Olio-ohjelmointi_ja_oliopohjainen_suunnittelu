#include <optional>

#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(0)
    , player2Time(0)
    , timer(new QTimer(this))
    , currentPlayer(1) {
  ui->setupUi(this);

  QObject::connect(ui->startButton,
                   &QPushButton::clicked,
                   this,
                   &MainWindow::handleStartButton);

  QObject::connect(ui->stopButton,
                   &QPushButton::clicked,
                   this,
                   &MainWindow::handleStopButton);

  QObject::connect(
      ui->shortPlayTimeButton, &QPushButton::clicked, this, [this]() {
        handleTimeSelectButton(120);
      });

  QObject::connect(
      ui->longPlayTimeButton, &QPushButton::clicked, this, [this]() {
        handleTimeSelectButton(300);
      });

  QObject::connect(ui->player1SwitchButton,
                   &QPushButton::clicked,
                   this,
                   &MainWindow::handlePlayerSwitchButton);

  QObject::connect(ui->player2SwitchButton,
                   &QPushButton::clicked,
                   this,
                   &MainWindow::handlePlayerSwitchButton);

  QObject::connect(timer, &QTimer::timeout, this, &MainWindow::timeout);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::handleStartButton() {
  if (player1Time == 0 && player2Time == 0) {
    setGameInfoText("Select a time");
    return;
  }

  setGameInfoText(QString("Player %1's turn").arg(currentPlayer));
  timer->start(1000);

  ui->startButton->setEnabled(false);
  ui->stopButton->setEnabled(true);
  ui->player1SwitchButton->setEnabled(true);
  ui->player2SwitchButton->setEnabled(false);
  ui->shortPlayTimeButton->setEnabled(false);
  ui->longPlayTimeButton->setEnabled(false);
}

void MainWindow::handleStopButton() {
  timer->stop();
  setGameInfoText("Game stopped");
  ui->stopButton->setEnabled(false);
  ui->startButton->setEnabled(true);
  ui->player1SwitchButton->setEnabled(false);
  ui->player2SwitchButton->setEnabled(false);
  ui->shortPlayTimeButton->setEnabled(true);
  ui->longPlayTimeButton->setEnabled(true);
}

void MainWindow::handlePlayerSwitchButton() {
  currentPlayer = currentPlayer == 1 ? 2 : 1;
  setGameInfoText(QString("Player %1's turn").arg(currentPlayer));
  ui->player1SwitchButton->setEnabled(currentPlayer == 1);
  ui->player2SwitchButton->setEnabled(currentPlayer == 2);
}

void MainWindow::updateProgressBars() {
  ui->player1ProgressBar->setValue(player1Time);
  ui->player2ProgressBar->setValue(player2Time);
}

void MainWindow::timeout() {
  std::optional<int> winner = std::nullopt;
  if (currentPlayer == 1) {
    player1Time--;
    if (player1Time == 0) {
      winner = 2;
    }
  } else {
    player2Time--;
    if (player2Time == 0) {
      winner = 1;
    }
  }

  if (winner.has_value()) {
    timer->stop();
    setGameInfoText(QString("Player %1 won!").arg(*winner));
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->player1SwitchButton->setEnabled(false);
    ui->player2SwitchButton->setEnabled(false);
    ui->shortPlayTimeButton->setEnabled(true);
    ui->longPlayTimeButton->setEnabled(true);
  } else {
    updateProgressBars();
  }
}

void MainWindow::setGameInfoText(const QString& text, int fontSize) {
  auto font = ui->label->font();
  font.setPointSize(fontSize);
  ui->label->setFont(font);
  ui->label->setText(text);
}

void MainWindow::handleTimeSelectButton(std::uint16_t time) {
  setGameInfoText("Ready to play");
  timer->stop();
  player1Time = time;
  player2Time = time;
  ui->player1ProgressBar->setMaximum(time);
  ui->player2ProgressBar->setMaximum(time);
  updateProgressBars();
}
