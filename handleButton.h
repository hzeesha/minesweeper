#ifndef HANDLEBUTTON_H
#define HANDLEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class handleButton : public QPushButton {
    Q_OBJECT

public:
    explicit handleButton(QWidget *parent = nullptr);
    void setPosition(int row, int col);
    int getRow() const;
    int getCol() const;
    void setRevealed(bool revealed);
    bool isRevealed() const;
    void cycleMarking();

signals:
    void rightClicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int row;
    int col;
    bool revealed = false;
    int markState = 0;
};

#endif
