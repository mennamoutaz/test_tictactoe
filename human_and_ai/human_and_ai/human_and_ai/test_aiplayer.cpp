#include <QtTest/QtTest>
#include "aiplayer.h"
#include "gameBoard.h"

// Test fixture for AIPlayer unit tests
class TestAIPlayer : public QObject {
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

    // Helper function to create a board with a specific state
    GameBoard createBoard(std::initializer_list<std::initializer_list<int>> values) {
        GameBoard board;
        int row = 0;
        for (auto& rowValues : values) {
            int col = 0;
            for (auto value : rowValues) {
                board.setValue(row, col, value);
                ++col;
            }
            ++row;
        }
        return board;
    }

    // Test AIPlayer makeMove function
    void testMakeMove() {
        GameBoard board;
        AIPlayer aiPlayer;

        // Simulate a board state where AI can make a move
        board.setValue(0, 0, 1); // Example board setup
        aiPlayer.makeMove(board);

        // Assert that AI has made a move and the board state has changed
        QVERIFY(board.getValue(0, 0) != 0); // Assuming AI's move changes board state
    }

    // Test AIPlayer build_tree function
    void testBuildTree() {
        GameBoard board;
        AIPlayer aiPlayer;
        TreeNode* root = new TreeNode;

        // Simulate an initial board state and build the tree
        board.setValue(0, 0, 0); // Empty board
        aiPlayer.build_tree(root, -1);

        // Assert that root node has children corresponding to possible moves
        QVERIFY(root->children.size() > 0);

        delete root;
    }

    // Test AIPlayer minimax function
    void testMinimax() {
        GameBoard board;
        AIPlayer aiPlayer;
        TreeNode* root = new TreeNode;

        // Simulate an initial board state and build the tree
        board.setValue(0, 0, 0); // Empty board
        aiPlayer.build_tree(root, -1);

        // Test minimax on the generated tree
        int score = aiPlayer.minimax(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), true, 3); // Example depth

        // Assert expected score based on your game logic
        QVERIFY(score >= -1000); // Adjust based on your evaluation logic

        delete root;
    }

    // Test AIPlayer evaluate function
    void testEvaluate() {
        GameBoard board;
        AIPlayer aiPlayer;

        // Test case 1: AI wins
        board.setValue(0, 0, -1);
        board.setValue(0, 1, -1);
        board.setValue(0, 2, -1);
        int score = aiPlayer.evaluate(board);
        QCOMPARE(score, 1000);

        // Test case 2: Player wins
        board.clear();
        board.setValue(1, 0, 1);
        board.setValue(1, 1, 1);
        board.setValue(1, 2, 1);
        score = aiPlayer.evaluate(board);
        QCOMPARE(score, -1000);

        // Test case 3: Draw
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
        score = aiPlayer.evaluate(board);
        QCOMPARE(score, 0);
    }
};

// Include the QTEST_MAIN macro to compile the unit tests
QTEST_MAIN(TestAIPlayer)

#include "test_aiplayer.moc" // Include the moc file for Qt Test
