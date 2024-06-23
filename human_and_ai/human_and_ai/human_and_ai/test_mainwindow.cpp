#include <QtTest/QtTest>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"

// Test fixture for MainWindow unit tests
class TestMainWindow : public QObject {
    Q_OBJECT

private slots:
    void initTestCase() {
        // Initialize resources before the first test case, if any
    }

    void cleanupTestCase() {
        // Clean up resources after the last test case, if any
    }

    void init() {
        // Initialize resources before each test case, if any
        mainWindow = new MainWindow();
    }

    void cleanup() {
        // Clean up resources after each test case, if any
        delete mainWindow;
    }

    // Test setupAgainstAI function
    void testSetupAgainstAI() {
        // Simulate button click on "Play against AI"
        QPushButton* playAIButton = mainWindow->findChild<QPushButton*>("playAIButton");
        QVERIFY(playAIButton != nullptr);

        QTest::mouseClick(playAIButton, Qt::LeftButton);

        QVERIFY(mainWindow->isAgainstAI()); // Check if againstAI flag is set
    }

    // Test handleButtonClick function
    void testHandleButtonClick() {
        // Simulate button click on a game board button
        QPushButton* button_0_0 = mainWindow->findChild<QPushButton*>("pushButton_0_0");
        QVERIFY(button_0_0 != nullptr);

        QTest::mouseClick(button_0_0, Qt::LeftButton);

        // Verify if board value was updated
        QCOMPARE(mainWindow->getBoard().getValue(0, 0), 1); // Assuming player 1 (X)
    }

    // Test checkGameState function
    void testCheckGameState() {
        // Simulate a game scenario leading to a win
        mainWindow->getBoard().setValue(0, 0, 1);
        mainWindow->getBoard().setValue(0, 1, 1);
        mainWindow->getBoard().setValue(0, 2, 1);

        QVERIFY(mainWindow->checkGameState()); // Check if game over message box appears
        QVERIFY(mainWindow->getBoard().checkWin() == 1); // Check if player 1 wins
    }

private:
    MainWindow* mainWindow;
};

// Include the QTEST_MAIN macro to compile the unit tests
QTEST_MAIN(TestMainWindow)

#include "test_mainwindow.moc" // Include the moc file for Qt Test
