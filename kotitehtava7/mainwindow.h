#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <cstdint>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

public slots:
  void timeout();

private slots:
  void handleStartButton();
  void handleStopButton();
  void handlePlayerSwitchButton();
  void handleTimeSelectButton(std::uint16_t time);

private:
  void updateProgressBars();
  void setGameInfoText(const QString& text, int fontSize = 20);

  Ui::MainWindow* ui;
  std::uint8_t currentPlayer;
  std::uint16_t player1Time;
  std::uint16_t player2Time;
  QTimer* timer;
};
#endif  // MAINWINDOW_H
