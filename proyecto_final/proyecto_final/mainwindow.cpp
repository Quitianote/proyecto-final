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
    fondo->setFlag(QGraphicsItem::ItemIsMovable, false);


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

    jugador->posicion(110, -100);
    scene->addItem(jugador);

    politico_1->posicion(50, 270);
    scene->addItem(politico_1);

    soldado_1->posicion(25, 150);
    scene->addItem(soldado_1);

    crear_suelo();

    jugador->setVy(2);
    timer_caida =  new QTimer;
    connect(timer_caida,SIGNAL(timeout()),this, SLOT(caida()));
    timer_caida->start(15);

    timer_lat_A = new QTimer;
    connect(timer_lat_A,SIGNAL(timeout()),this, SLOT(mov_lat_A()));

    timer_lat_D = new QTimer;
    connect(timer_lat_D,SIGNAL(timeout()),this, SLOT(mov_lat_D()));

    timer_salto = new QTimer;
    connect(timer_salto,SIGNAL(timeout()),this, SLOT(salto()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){

    if(event->key()== Qt::Key_A){
        timer_lat_A->stop();
    }

    if(event->key()== Qt::Key_D){
        timer_lat_D->stop();
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()== Qt::Key_F4) close();

    if(event->key()== Qt::Key_A ){
        if(!timer_lat_A->isActive()){
            jugador->setPixmap(QPixmap(":/imagenes/jeffrey - izquierda - copia.png"));
            timer_lat_A->start(10);
            //jugador->setX(jugador->getX()-vel);
        }
    }

    if(event->key()== Qt::Key_S && jugador->getY()<scene->height()-40){
        jugador->setY(jugador->getY()+vel);
    }

    if(event->key()== Qt::Key_D /*&& jugador->getX()<scene->width()-34*/){
        if(!timer_lat_D->isActive()){
            timer_lat_D->start(10);
            jugador->setPixmap(QPixmap(":/imagenes/jeffrey-derecha - copia.png"));
            //jugador->setX(jugador->getX()+vel);
        }
    }

    if(event->key()== Qt::Key_W /*&& jugador->getY()>-150*/){
        //jugador->setY(jugador->getY()-vel);
        if(!timer_salto->isActive() && col_y()){
            timer_caida->stop();
            vel = 55;
            timer_salto->start(10);
        }
    }

    if(event->key()== Qt::Key_Space){
        if(!timer_caida->isActive()){
            jugador->setVy(2);
            timer_caida->start(15);
        }
    }


    jugador->posicion();
}


void MainWindow::bala_mov()
{

}

void MainWindow::salto()
{
    vel -= 9.8*0.1;
    jugador->setY(jugador->getY() - vel*0.1);
    jugador->posicion();
    if(vel <= 0){
        timer_salto->stop();
        timer_caida->start(10);
    }
}

void MainWindow::caida()
{
    if(!col_y()) {
        jugador->setVy(jugador->getVy() + 9.8*0.1);
        jugador->setY(jugador->getY() + jugador->getVy()*0.1);

        if(jugador->getY() < 400) jugador->posicion();
        else timer_caida->stop();

    }
    else jugador->setVy(2);
}

void MainWindow::mov_lat_D()
{
    if(!col_x_D()){
        float vel_D = 20;
        jugador->setX(jugador->getX() + vel_D*0.1);
        jugador->posicion();
    }
}

void MainWindow::mov_lat_A()
{
    if(!col_x_A()){
        float vel_D = 20;
        jugador->setX(jugador->getX() - vel_D*0.1);
        jugador->posicion();
    }
}

bool MainWindow::col_y()//mira si esta pegado al piso
{
    QList<suelo*>::iterator
            it (cubos.begin()),
            end (cubos.end());
    for (; it != end; ++it) {

        if (jugador->collidesWithItem((*it)) && jugador->getY() + jugador->boundingRect().height() <= (*it)->getY()) {
            return true;
        }
    }
    return false;
}

bool MainWindow::col_y_arriba()
{

}

bool MainWindow::col_x_A()
{
    QList<suelo*>::iterator
            it (cubos.begin()),
            end (cubos.end());
    for (; it != end; ++it) {

        if (jugador->collidesWithItem((*it)) && jugador->getX() <= (*it)->getX() + (*it)->boundingRect().width() && jugador->getX() > (*it)->getX()) {
            if((*it)->getY() <= jugador->getY() + jugador->boundingRect().height()){
                if(jugador->getY() >= (*it)->getY()) return true;
                else if(jugador->getY() <= (*it)->getY());return true;
            }
        }
    }
    return false;
}

bool MainWindow::col_x_D()
{
    QList<suelo*>::iterator
            it (cubos.begin()),
            end (cubos.end());
    for (; it != end; ++it) {

        if (jugador->collidesWithItem((*it)) && jugador->getX() + jugador->boundingRect().width() <= (*it)->getX()) {
            if((*it)->getY() <= jugador->getY() + jugador->boundingRect().height()){
                if(jugador->getY() >= (*it)->getY()) return true;
                else if(jugador->getY() <= (*it)->getY());return true;
            }
        }
    }
    return false;
}



/*void bola::mover(float dt)
{
    //if(py<=0) vy = -vy;
    vy = vy - G*dt;
    if (int(vy) <= 0 && int(py) <= rad){ py=rad; vy=0;}
    px += vx*dt;
    py += vy*dt;
}
*/

void MainWindow::crear_suelo()
{
    int x = 0;
    int y = 110;

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(0, 0 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(0, -55 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(55, -55 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(-55, -55 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(0, -110 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));//arriba centro
    cubos.last()->posicion(220, -150 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    cubos.append(new suelo(nullptr));//arriba centro
    cubos.last()->posicion(275, -150 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());


    for(int i = 0; i < 10; i ++){//arriba izquierda
        cubos.append(new suelo(nullptr));
        cubos.last()->setScale(1.3);
        cubos.last()->posicion(-110 + x,0 + 55);
        scene->addItem(cubos.last());
        x += 55;
    }

    cubos.append(new suelo(nullptr));//cubo solitario, derecha, arriba
    cubos.last()->posicion(x + 25, 55 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    x += (55*3);

    for(int i = 0; i < 4; i ++){//derecha del todo
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y + 55);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y += 55;
    }

    x -= 55;
    y -= (55*3);

    for(int i = 0; i < 3; i ++){//derecha del todo -1
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y + 55);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y += 55;
    }

    x -= 55;
    y -= (55*2);

    for(int i = 0; i < 2; i ++){//derecha del todo -2
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y + 55);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y += 55;
    }

    cubos.append(new suelo(nullptr));//derecha del todo -3
    cubos.last()->posicion(x - 55, y - 55 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());

    x = 170;
    y -= 55*2;

    for(int i = 0; i < 2; i ++){//izquierda centro
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(-170, y + 55);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        y -= 55;
    }

    x -= 55*7;

    //izquierda centro arriba
    cubos.append(new suelo(nullptr));
    cubos.last()->posicion(x, y + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());
    y -= 55;


    cubos.append(new suelo(nullptr));//izquierda centro, abajo de centro arriba
    cubos.last()->posicion(-58*2, 55*4 + 55);
    cubos.last()->setScale(1.3);
    scene->addItem(cubos.last());
    y = 55*4 + 55*3;
    x = -58*2 + 55*2;

    for(int i = 0; i < 9; i ++){// linea horizontal de abajo, centro
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        x += 55;
    }


}


