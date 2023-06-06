#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QDialog>
#include <QWidget>
#include <QMovie>
#include <QSize>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QDebug>
#include "mainwindow.h"

namespace Ui {
class game_over;
}

class game_over : public QDialog
{
    Q_OBJECT

public:
    explicit game_over(QWidget *parent = nullptr);
    ~game_over();

    void keyPressEvent(QKeyEvent *event);

    void setTotal(int newTotal);

private:
    Ui::game_over *ui;
    QGraphicsScene *scene;

    QGraphicsPixmapItem *fondo;

    int total;
};

#endif // GAME_OVER_H
