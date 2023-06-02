#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene();

    ui->graphicsView->setScene(scene);


    fondo = new QGraphicsPixmapItem(QPixmap(":/imagenes/wallpaperbetter.com_7680x4320.jpg"));
    scene->addItem(fondo);
    fondo->setPixmap(QPixmap(":/imagenes/wallpaperbetter.com_7680x4320.jpg").scaled(1000, 800));
    fondo->setPos(-150, -180);

    scene->setSceneRect(0,7,686,400);
    scene->addRect(scene->sceneRect());



    jugador = new jeffrey(nullptr);
    jugador->setScale(1.5);

    jugador->posicion(0,270);
    scene->addItem(jugador);



    vel=5;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()== Qt::Key_F4) close();

    if(event->key()== Qt::Key_A && jugador->getX()>4){
        jugador->setX(jugador->getX()-vel);
    }

    if(event->key()== Qt::Key_S && jugador->getY()<scene->height()-40){
        jugador->setY(jugador->getY()+vel);
    }

    if(event->key()== Qt::Key_D && jugador->getX()<scene->width()-34){
        jugador->setX(jugador->getX()+vel);
    }

    if(event->key()== Qt::Key_W && jugador->getY()>109){
        jugador->setY(jugador->getY()-vel);
    }

    if(event->key()== Qt::Key_Space){

    }


    jugador->posicion();
}

void MainWindow::bala_mov()
{

}
