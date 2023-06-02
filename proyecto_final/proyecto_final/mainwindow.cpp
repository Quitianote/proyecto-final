#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene();
    scene->setSceneRect(0,7,686,400);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

    fondo = new QGraphicsPixmapItem(QPixmap("ruta_de_la_imagen"));



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
