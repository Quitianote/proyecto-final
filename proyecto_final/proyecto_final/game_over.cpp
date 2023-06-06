#include "game_over.h"
#include "ui_game_over.h"
#include "mainwindow.h"

game_over::game_over(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game_over)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    fondo = new QGraphicsPixmapItem(QPixmap(":/imagenes/GAME_OVER.png"));
    scene->addItem(fondo);
    fondo->setPixmap(QPixmap(":/imagenes/game_over.png").scaled(800, 600));
    fondo->setPos(-150, -180);
}

game_over::~game_over()
{
    delete ui;
}

void game_over::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Space){
        menu *N =  new menu;
        N->show();
        this->close();
    }
}

