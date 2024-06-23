#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentPlayer(1), againstAI(false)
{
    ui->setupUi(this);

    // Connect buttons to the handleButtonClick slot
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QString buttonName = QString("pushButton_%1_%2").arg(i).arg(j);
            QPushButton *button = this->findChild<QPushButton *>(buttonName);
            connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        }
    }

    // Setup menu or button to choose game mode
    // For simplicity, let's assume a button "Play against AI" and "Play with Player"
    QPushButton *playAIButton = new QPushButton("Play against AI", this);
    QPushButton *playPlayerButton = new QPushButton("Play with Player", this);

    playAIButton->move(50, 200);
    playPlayerButton->move(200, 200);

    connect(playAIButton, &QPushButton::clicked, this, &MainWindow::setupAgainstAI);
    connect(playPlayerButton, &QPushButton::clicked, this, &MainWindow::setupAgainstPlayer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupAgainstAI()
{
    againstAI = true;
    initializeGame();
}

void MainWindow::setupAgainstPlayer()
{
    againstAI = false;
    initializeGame();
}

void MainWindow::initializeGame()
{
    // Hide the setup buttons or menu here
    // ...

    if (againstAI) {
        ui->turnLabel->setText("Player 1's Turn (X)");
        currentPlayer = 1;
    } else {
        ui->turnLabel->setText("Player 1's Turn (X)");
    }

    updateBoard();
}

void MainWindow::handleButtonClick()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString buttonName = button->objectName();
    int row = buttonName.split("_")[1].toInt();
    int col = buttonName.split("_")[2].toInt();

    if (board.getValue(row, col) == 0) {
        board.setValue(row, col, currentPlayer);
        updateBoard();
        if (checkGameState()) {
            return; // If the game is over, return immediately
        }
        currentPlayer = -currentPlayer;
        updateTurnLabel();

        // If AI's turn, make AI move
        if (againstAI && currentPlayer == -1) {
            QTimer::singleShot(500, this, &MainWindow::makeAIMove);
        }
    }
}

void MainWindow::makeAIMove()
{
    ai.makeMove(board);
    updateBoard();
    if (checkGameState()) {
        return; // If the game is over, return immediately
    }
    currentPlayer = 1; // Switch back to Player 1
    updateTurnLabel();
}

void MainWindow::updateBoard()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QString buttonName = QString("pushButton_%1_%2").arg(i).arg(j);
            QPushButton *button = this->findChild<QPushButton *>(buttonName);
            int value = board.getValue(i, j);
            if (value == 1) {
                button->setText("X");
            } else if (value == -1) {
                button->setText("O");
            } else {
                button->setText("");
            }
        }
    }
}

bool MainWindow::checkGameState()
{
    int result = board.checkWin();
    if (result == 1) {
        QMessageBox::information(this, "Game Over", "Player 1 wins!");
        resetGame();
        return true;
    } else if (result == -1) {
        if (againstAI && currentPlayer == -1) {
            QMessageBox::information(this, "Game Over", "AI wins!");
        } else {
            QMessageBox::information(this, "Game Over", "Player 2 wins!");
        }
        resetGame();
        return true;
    } else if (result == 2) {
        QMessageBox::information(this, "Game Over", "It's a draw!");
        resetGame();
        return true;
    }
    return false;
}

void MainWindow::updateTurnLabel()
{
    if (againstAI) {
        if (currentPlayer == 1) {
            ui->turnLabel->setText("Player 1's Turn (X)");
        } else {
            ui->turnLabel->setText("AI's Turn (O)");
        }
    } else {
        if (currentPlayer == 1) {
            ui->turnLabel->setText("Player 1's Turn (X)");
        } else {
            ui->turnLabel->setText("Player 2's Turn (O)");
        }
    }
}

void MainWindow::resetGame()
{
    board = GameBoard();
    updateBoard();
    initializeGame();
}
