#include "handleButton.h"

// Constructor to initalize button with default values
handleButton::handleButton(QWidget *parent) : QPushButton(parent), revealed(false), markState(0) {}

// Set the posiiton of the button in the grid
void handleButton::setPosition(int row, int col) {
    this->row = row;
    this->col = col;
}

// Get the row of the button
int handleButton::getRow() const { return row; }

// Get the column of the button
int handleButton::getCol() const { return col; }

// Check if button has been revelead
bool handleButton::isRevealed() const { return revealed; }

// Set the button's revelead state
void handleButton::setRevealed(bool revealed) { this->revealed = revealed; }

// Handle left and right mouse clicks
void handleButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        emit rightClicked();  // Emit custom right-click signal
    } else {
        QPushButton::mousePressEvent(event);  // Default behaviour for left click
    }
}

// Cycle through marking states: flag, question, none
void handleButton::cycleMarking() {
    if (markState == 0) {
        setIcon(QIcon("icons/flag.png"));  // Show flag icon
        setIconSize(QSize(24, 24));
        markState = 1;
    } else if (markState == 1) {
        setIcon(QIcon("icons/question.png"));  // Show question mark icon
        setIconSize(QSize(24, 24));
        markState = 2;
    } else {
        setIcon(QIcon());  // Clear the icon
        markState = 0;
    }
}
