#include "mainwindow.h"

// Constructor for the main window
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget(this);  // Create central widgit
    setCentralWidget(centralWidget);    // Set as main central widgit

    layout = new QGridLayout(centralWidget);  // Grid layout for placing items
    board = new GameBoard(this);  // Create the game board

    layout->addWidget(board, 0, 0);  // Add board to layout at top-left
}

// Destructor for clean up
MainWindow::~MainWindow() {}
