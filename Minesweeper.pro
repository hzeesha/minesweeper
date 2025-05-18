QT += core gui widgets  # Qt modules used
CONFIG += c++11  # Use C++11 standard

SOURCES += main.cpp mainwindow.cpp gameboard.cpp \  # Source files
    handleButton.cpp
HEADERS += mainwindow.h gameboard.h \  # Header files
    handleButton.h

TARGET = Minesweeper  # Name of the output app
TEMPLATE = app  # Template type (application)
