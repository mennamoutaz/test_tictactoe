#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameboard.h"
#include "aiplayer.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();
    void makeAIMove();
    void setupAgainstAI(); // Declaration added
    void setupAgainstPlayer(); // Declaration added

private:
    Ui::MainWindow *ui;
    GameBoard board;
    AIPlayer ai;
    int currentPlayer;
    bool againstAI; // Flag to indicate if playing against AI

    void updateBoard();
    bool checkGameState();
    void updateTurnLabel();
    void resetGame();
    void initializeGame();
};

#endif // MAINWINDOW_H
