#include <QtTest/QtTest>
#include "gameboard.h"

// Test fixture for GameBoard unit tests
class TestGameBoard : public QObject {
    Q_OBJECT

private slots:
    void initTestCase() {
        // Optional: Initialize resources before the first test case
    }

    void cleanupTestCase() {
        // Optional: Clean up resources after the last test case
    }

    void init() {
        // Optional: Initialize resources before each test case
    }

    void cleanup() {
        // Optional: Clean up resources after each test case
    }

    // Test GameBoard initialization and display function
    void testInitializationAndDisplay() {
        GameBoard board;

        // Test if board is initialized correctly
        QCOMPARE(board.getValue(0, 0), 0);
        QCOMPARE(board.getValue(1, 1), 0);

        // Redirect cout to capture output for display testing
        std::stringstream capturedOutput;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(capturedOutput.rdbuf());

        // Test display function output
        board.display();

        std::cout.rdbuf(coutBuffer); // Restore cout

        // Verify expected display output
        const std::string expectedOutput =
            "  1 2 3 \n"
            " -------\n"
            "1|- - - \n"
            "2|- - - \n"
            "3|- - - \n"
            " -------\n";
        QCOMPARE(capturedOutput.str(), expectedOutput);
    }

    // Test GameBoard checkWin function
    void testCheckWin() {
        GameBoard board;

        // Test for no win initially
        QCOMPARE(board.checkWin(), 0);

        // Simulate a win for Player 1 (X)
        board.setValue(0, 0, 1);
        board.setValue(0, 1, 1);
        board.setValue(0, 2, 1);
        QCOMPARE(board.checkWin(), 1); // Player 1 wins

        // Simulate a win for Player 2 (O)
        board.clear();
        board.setValue(1, 0, -1);
        board.setValue(1, 1, -1);
        board.setValue(1, 2, -1);
        QCOMPARE(board.checkWin(), -1); // Player 2 wins

        // Simulate a draw
        board.clear();
        board.setValue(0, 0, 1);
        board.setValue(0, 1, -1);
        board.setValue(0, 2, 1);
        board.setValue(1, 0, -1);
        board.setValue(1, 1, 1);
        board.setValue(1, 2, -1);
        board.setValue(2, 0, -1);
        board.setValue(2, 1, 1);
        board.setValue(2, 2, -1);
        QCOMPARE(board.checkWin(), 2); // Game is a draw
    }
};

// Include the QTEST_MAIN macro to compile the unit tests
QTEST_MAIN(TestGameBoard)

#include "test_gameboard.moc" // Include the moc file for Qt Test
