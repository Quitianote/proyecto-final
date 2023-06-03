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
    fondo->setPixmap(QPixmap(":/imagenes/wallpaperbetter.com_7680x4320.jpg").scaled(1100, 800));
    fondo->setPos(-250, -180);
/*
    scene->setSceneRect(0,7,686,400);
    scene->addRect(scene->sceneRect());
*/


    jugador = new jeffrey(nullptr);
    jugador->setScale(1.3);

    politico_1 = new politico(nullptr);
    politico_1->setScale(1.3);

    soldado_1 = new soldado(nullptr);
    soldado_1->setScale(1.3);

    jugador->posicion(110, -58);
    scene->addItem(jugador);

    politico_1->posicion(50, 270);
    scene->addItem(politico_1);

    soldado_1->posicion(25, 150);
    scene->addItem(soldado_1);



    crear_suelo();


    vel=10;
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

    if(event->key()== Qt::Key_W && jugador->getY()>-150){
        jugador->setY(jugador->getY()-vel);
    }

    if(event->key()== Qt::Key_Space){

    }


    jugador->posicion();
}

void MainWindow::crear_suelo()
{
    int x = 0;
    int y = 110;

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(0, 0);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(0, -55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(55, -55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(-55, -55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(0, -110);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));//arriba centro
    cubos.last()->posicion(220, -150);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));//arriba centro
    cubos.last()->posicion(275, -150);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());


    for(int i = 0; i < 10; i ++){//arriba izquierda
        cubos.append(new suelo(nullptr));
        cubos.last()->setScale(1.3);
        cubos.last()->posicion(-110 + x,0);
        scene->addItem(cubos.last());
        x += 55;
    }

    cubos.append(new suelo(nullptr));//cubo solitario, derecha, arriba
    cubos.last()->posicion(x + 25, 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    x += (55*3);

    for(int i = 0; i < 4; i ++){//derecha del todo
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y += 55;
    }

    x -= 55;
    y -= (55*3);

    for(int i = 0; i < 3; i ++){//derecha del todo -1
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y += 55;
    }

    x -= 55;
    y -= (55*2);

    for(int i = 0; i < 2; i ++){//derecha del todo -2
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y += 55;
    }

    cubos.append(new suelo(nullptr));//derecha del todo -3
    cubos.last()->posicion(x - 55, y - 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    x = 170;
    y -= 55;

    for(int i = 0; i < 3; i ++){//izquierda centro
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(-170, y);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y -= 55;
    }

    x -= 55*7;

    for(int i = 0; i < 2; i ++){//izquierda centro arriba
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y -= 55;
    }


}

void MainWindow::bala_mov()
{

}
