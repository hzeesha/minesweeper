#include <QApplication>
#include "gameboard.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

const int ROWS = 16;
const int COLS = 30;
const int MINES = 99;

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent), mineMap(ROWS, std::vector<bool>(COLS, false)), firstClick(true) {

    grid = new QGridLayout(this);

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            buttons[row][col] = new handleButton(this);
            buttons[row][col]->setFixedSize(30, 30);
            grid->addWidget(buttons[row][col], row, col);

            buttons[row][col]->setPosition(row, col);  // Set button posiiton in grid

            connect(buttons[row][col], &handleButton::clicked, this, &GameBoard::handleLeftClick);
            connect(buttons[row][col], &handleButton::rightClicked, this, &GameBoard::handleRightClick);
        }
    }
}

// Place mines, skipping the first clicked cell
void GameBoard::placeMines(int excludeRow, int excludeCol) {
    srand(time(0));
    int minesPlaced = 0;

    while (minesPlaced < MINES) {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        // Avoid placing mine on the first click or existing mine
        if ((row == excludeRow && col == excludeCol) || mineMap[row][col]) {
            continue;
        }

        mineMap[row][col] = true;
        minesPlaced++;
    }
}

// Count mines around the current cell
int GameBoard::countAdjacentMines(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && mineMap[newRow][newCol]) {
                count++;
            }
        }
    }
    return count;
}

// Handle left click event
void GameBoard::handleLeftClick() {
    handleButton *button = qobject_cast<handleButton *>(sender());
    if (button) {
        int row = button->getRow();
        int col = button->getCol();

        // First click logic - ensure it’s safe
        if (firstClick) {
            placeMines(row, col);
            firstClick = false;
        }

        if (!button->isRevealed()) {
            if (mineMap[row][col]) {
                revealAllMines();
                showGameOverMessage(false);
            } else {
                int mineCount = countAdjacentMines(row, col);
                if (mineCount > 0) {
                    button->setText(QString::number(mineCount));
                } else {
                    revealAdjacentEmptySpaces(row, col);
                }
                button->setRevealed(true);
            }
        }
    }
}

// Handle right click to mark flags or question marks
void GameBoard::handleRightClick() {
    handleButton *button = qobject_cast<handleButton *>(sender());
    if (button) {
        button->cycleMarking();
    }
}

// Reveals all mines when the player clicks on one
void GameBoard::revealAllMines() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (mineMap[row][col]) {
                buttons[row][col]->setIcon(QIcon("icons/mine.png"));
                buttons[row][col]->setIconSize(QSize(24, 24));
            }
        }
    }
}

// Show win/lose message and offer to restart
void GameBoard::showGameOverMessage(bool won) {
    QString message = won ? "Congratulations! You won!" : "Game Over! You clicked on a mine!";

    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText(message);
    msgBox.setInformativeText("Would you like to play again?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        resetGame();  // Reset the game if player wants to try again
    } else {
        qApp->quit();  // Quit the game
    }
}

// Resets the game board to its inital state
void GameBoard::resetGame() {
    firstClick = true;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            buttons[row][col]->setText("");
            buttons[row][col]->setIcon(QIcon());
            buttons[row][col]->setRevealed(false);
        }
    }

    mineMap = std::vector<std::vector<bool>>(ROWS, std::vector<bool>(COLS, false));
}

// Reveal empty spaces recursively
void GameBoard::revealAdjacentEmptySpaces(int row, int col) {
    if (buttons[row][col]->isRevealed()) return;

    buttons[row][col]->setRevealed(true);
    int mineCount = countAdjacentMines(row, col);
    if (mineCount > 0) {
        buttons[row][col]->setText(QString::number(mineCount));
        return;
    }

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
                revealAdjacentEmptySpaces(newRow, newCol);
            }
        }
    }
}
