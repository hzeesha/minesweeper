#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QGridLayout>
#include "handleButton.h"
#include <vector>

class GameBoard : public QWidget {
    Q_OBJECT

public:
    // Public members accessible from outside the class
    explicit GameBoard(QWidget *parent = nullptr);

private:
    // Private members accessible only within the class
    QGridLayout *grid;
    handleButton *buttons[16][30];
    std::vector<std::vector<bool>> mineMap;
    bool firstClick = true;  // Ensure first click is safe

    void placeMines(int excludeRow, int excludeCol);
    int countAdjacentMines(int row, int col);
    void revealAllMines();
    void revealAdjacentEmptySpaces(int row, int col);
    void showGameOverMessage(bool won);
    void resetGame();

private slots:
    // Private slots used for signal-slot mechanism in Qt
    void handleLeftClick();
    void handleRightClick();
};

#endif
