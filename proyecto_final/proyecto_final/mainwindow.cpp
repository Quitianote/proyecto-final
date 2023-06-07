#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include "game_over.h"
#include <cstdlib>
#include <ctime>

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

    jugador = new jeffrey(nullptr);
    jugador->setScale(1.3);

    ui->puntaje->setText(QString::number(puntos));

    crear_poli();

    jugador->posicion(210, -200);
    scene->addItem(jugador);

    /*soldados.append(new soldado(nullptr));
    soldados.last()->posicion(200, 310);
    soldados.last()->setScale(1.3);
    scene->addItem(soldados.last());*/

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

    timer_tiempo = new QTimer;
    connect(timer_tiempo,SIGNAL(timeout()),this, SLOT(tiempo()));
    timer_tiempo->start(1000);

    timer_fric_A = new QTimer;
    connect(timer_fric_A, SIGNAL(timeout()), this, SLOT(fric_A()));
    timer_fric_D = new QTimer;
    connect(timer_fric_D, SIGNAL(timeout()), this, SLOT(fric_D()));

    crear_sold();
    crear_sold();

    timer_bala_A = new QTimer;
    connect(timer_bala_A, SIGNAL(timeout()), this, SLOT(bala_A()));
    timer_bala_D = new QTimer;
    connect(timer_bala_D, SIGNAL(timeout()), this, SLOT(bala_D()));

    timer_ver = new QTimer;
    connect(timer_ver, SIGNAL(timeout()), this, SLOT(ver()));

    timer_ver->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::puntaje()
{
    puntos ++;

    ui->puntaje->setText(QString::number(puntos));
    if(!timer_tiempo->isActive() && !temp){//cuando llega a 0
        puntos += time_;
        time_ = 11;
        timer_tiempo->start(1000);
    }
    else if(timer_tiempo->isActive() && !temp){//cuando aun sigue con tiempo de sobra
        puntos += time_;
        timer_tiempo->stop();
        time_ = 11;
        timer_tiempo->start(1000);
    }
    if(poli%4 == 0){
        crear_sold();
    }
    temp = false;
}

int MainWindow::getPuntos()
{
    return puntos;
}

void MainWindow::tiempo()
{
    time_ --;
    ui->tiempo->setText(QString::number(time_));
    if(time_ == 0) timer_tiempo->stop();
}

void MainWindow::ver()
{
    QList<soldado*>::iterator
            it (soldados.begin()),
            end(soldados.end());

    for(; it != end; it ++){
        if((*it)->getY() == jugador->getY()){
            int sold = (*it)->getX();
            if(sold < 0) sold *= -1;
            int jug = jugador->getX();
            if(jug < 0) jug *= -1;
            dist = sold - jug;

            if(dist <= 20 && dist >= -20){
                soldado_disp = (*it);
                disparar();
            }
        }
    }
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
        }
        ult = 1;
    }

    if(event->key()== Qt::Key_D){
        if(!timer_lat_D->isActive()){
            timer_lat_D->start(10);
            jugador->setPixmap(QPixmap(":/imagenes/jeffrey-derecha - copia.png"));
        }
        ult = 2;
    }

    if(event->key()== Qt::Key_W){
        if(!timer_salto->isActive() && col_y()){
            timer_caida->stop();
            vel = 55;
            timer_salto->start(10);
        }
    }

    if(event->key()== Qt::Key_F){
        if(col_sold()){
            vA = 60;
            vD = 60;
            if(ult == 1){
                if(timer_fric_D->isActive()) timer_fric_D->stop();
                timer_fric_A->start(10);

            }
            else{
                if(timer_fric_A->isActive()) timer_fric_A->stop();
                timer_fric_D->start(10);
            }
        }
    }

    if(event->key()== Qt::Key_Space){
        if(jugador->collidesWithItem(politico_1)){
            //reproducir audio de tos
            delete politico_1;
            crear_poli();
            puntaje();
        }
    }


    jugador->posicion();
}

void MainWindow::disparar()
{
    balas.append(new bala(5));
    balas.last()->posicion(soldado_disp->getX(),soldado_disp->getY());
    if(dist >= 0) timer_bala_A->start(1000);
    else timer_bala_D->start(1000);
}
void MainWindow::bala_D()
{
    QList<bala*>::iterator
            it (balas.begin()),
            end (balas.end());

    float vX = 20;

    for( ; it != end; it ++){
        (*it)->setX((*it)->getX() + vX*0.1);
        /*if (!bala_temp->collidingItems().isEmpty()){

            for(auto re = rect.begin() ;re != rect.end(); ++re){
                auto f1 = *re;
                if (bala_temp->collidingItems().first() == f1){
                    balas.removeOne(bala_temp);
                    scene->removeItem(bala_temp);
                    rect.removeOne(f1);
                    scene->removeItem(f1);
                    break;
                }
            }
        }
        if (bala_temp->getY()<20){

            balas.removeOne(bala_temp);
            scene->removeItem(bala_temp);
        }*/

    }
}

void MainWindow::bala_A()
{

}

void MainWindow::salto()
{
    if(!col_y_arriba()){
        vel -= 9.8*0.1;
        jugador->setY(jugador->getY() - vel*0.1);
        jugador->posicion();
    }
    else{
        timer_salto->stop();
        timer_caida->start(10);
    }
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

        if(jugador->getY() < 600) jugador->posicion();
        else{
            timer_caida->stop();
            game_over *N =  new game_over;
            N->show();
            this->close();
        }

    }
    else jugador->setVy(2);//para evitar que la velocidad de la caida aumente progresivamente
}

void MainWindow::caida_sold()
{

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

void MainWindow::fric_A()
{
    float G = 9.8*0.1;
    vA -= G;//9.8*0.1;
    soldado_1->setX(soldado_1->getX() - vA*0.1);
    soldado_1->posicion();
    if(vA <= 0 || col_s_A()){
        //timer_fric_A->stop();
        //vA = 60;
        if(col_y_sold()){
            vA = G;
            soldado_1->setVy(2);
        }
        else vA = 9.8*0.1;
    }
    if(!col_y_sold()){
        soldado_1->setVy(soldado_1->getVy() + 9.8*0.1);
        soldado_1->setY(soldado_1->getY() + soldado_1->getVy()*0.1);

        if(soldado_1->getY() < 400) soldado_1->posicion();
        else{
            timer_fric_A->stop();
            scene->removeItem(soldado_1);
            soldados.removeOne(soldado_1);
            puntos += 2;
            temp = true;
            puntaje();
            crear_sold();
            if(sold%5 == 0){
                crear_sold();
            }

        }
    }
}

void MainWindow::fric_D()
{
    float G = 9.8*0.1;
    vD -= G;//9.8*0.1;
    soldado_1->setX(soldado_1->getX() + vD*0.1);
    soldado_1->posicion();
    if(vD <= 0 || col_s_D()){
        //timer_fric_A->stop();
        //vA = 60;
        if(col_y_sold()){
            vD = G;
            soldado_1->setVy(2);
        }
        else vD = 9.8*0.1;
    }
    if(!col_y_sold()){
        soldado_1->setVy(soldado_1->getVy() + 9.8*0.1);
        soldado_1->setY(soldado_1->getY() + soldado_1->getVy()*0.1);

        if(soldado_1->getY() < 400) soldado_1->posicion();
        else{
            timer_fric_D->stop();
            scene->removeItem(soldado_1);
            soldados.removeOne(soldado_1);
            puntos += 2;
            temp = true;
            puntaje();
            crear_sold();
            if(sold%5 == 0){
                crear_sold();
            }

        }
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

bool MainWindow::col_y_sold()//mira si esta pegado al piso
{
    QList<suelo*>::iterator
            it (cubos.begin()),
            end (cubos.end());
    for (; it != end; ++it) {

        if (soldado_1->collidesWithItem((*it)) && soldado_1->getY() + soldado_1->boundingRect().height() <= (*it)->getY()) {
            return true;
        }
    }
    return false;
}


bool MainWindow::col_y_arriba()
{
    QList<suelo*>::iterator
            it (cubos.begin()),
            end (cubos.end());
    for (; it != end; ++it) {

        if (jugador->collidesWithItem((*it)) && jugador->getY() <= (*it)->getY() + (*it)->boundingRect().height() && jugador->getY() > (*it)->getY()) {
            return true;
        }
    }
    return false;
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
                else if(jugador->getY() <= (*it)->getY()) return true;
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
                else if(jugador->getY() <= (*it)->getY()) return true;
            }
        }
    }
    return false;
}

bool MainWindow::col_s_A()
{
    QList<suelo*>::iterator
            it (cubos.begin()),
            end (cubos.end());
    for (; it != end; ++it) {

        if (soldado_1->collidesWithItem((*it)) && soldado_1->getX() <= (*it)->getX() + (*it)->boundingRect().width() && soldado_1->getX() > (*it)->getX()) {
            if((*it)->getY() <= soldado_1->getY() + soldado_1->boundingRect().height()){
                if(soldado_1->getY() >= (*it)->getY()) return true;
                else if(soldado_1->getY() <= (*it)->getY()) return true;
            }
        }
    }
    return false;
}

bool MainWindow::col_s_D()
{
    QList<suelo*>::iterator
            it (cubos.begin()),
            end (cubos.end());
    for (; it != end; ++it) {

        if (soldado_1->collidesWithItem((*it)) && soldado_1->getX() + soldado_1->boundingRect().width() <= (*it)->getX()) {
            if((*it)->getY() <= soldado_1->getY() + soldado_1->boundingRect().height()){
                if(soldado_1->getY() >= (*it)->getY()) return true;
                else if(soldado_1->getY() <= (*it)->getY()) return true;
            }
        }
    }
    return false;
}

bool MainWindow::col_sold()
{
    QList<soldado*>::iterator
            it (soldados.begin()),
            end (soldados.end());
    for (; it != end; ++it) {
        if (jugador->collidesWithItem((*it))) {
            soldado_1 = *it;
            return true;
        }
    }
    return false;
}

void MainWindow::crear_poli()
{
    int posx = 0;
    int posy = 0;

    poli ++;

    srand(time(0));

    politico_1 = new politico(nullptr);
    politico_1->setScale(1.3);

    for(;;){
        posx = rand()%1000;
        if(posx%11 == 0 && num != 11){
            num = 11;
            posy = 310;
            posx = -5 + (rand()%405);
            break;
        }
        else if(posx%3 == 0 && num != 3){
            num = 3;
            posx = -110;
            posy = 200;
            break;
        }
        else if(posx%5 == 0 && num != 5){
            num = 5;
            posx = 610;
            posy = 200;
            break;
        }
        else if(posx%7 == 0 && num != 7){
            num = 7;
            posy = -20;
            posx = 110 + (rand()%290);
            break;
        }
    }

    politico_1->posicion(posx, posy);
    scene->addItem(politico_1);

}

void MainWindow::crear_sold()
{
    int posx = 0;
    int posy = 0;
    bool aux = false;

    /*QList<soldado*>::iterator
            it (soldados.begin()),
            end (soldados.end());*/

    sold ++;

    srand(time(0));

    soldados.append(new soldado(nullptr));
    soldados.last()->setScale(1.3);

    for(;;){
        posx = rand()%1000;
        if(posx%11 == 0 && num != 11){
            //num = 11;
            posy = 310;
            posx = -5 + (rand()%405);
            break;
        }
        else if(posx%7 == 0 && num != 7){
            //num = 7;
            posy = -20;
            posx = 110 + (rand()%290);
            break;
        }
    }

    soldados.last()->posicion(posx, posy);
    scene->addItem(soldados.last());
    /*for(; it != end; it ++){
        if(soldados.last()->collidesWithItem((*it)) && soldados.last() != (*it)){
            aux = true;
            scene->removeItem(soldados.last());
            soldados.removeOne(soldados.last());
            break;
        }
        else aux = false;
    }
    if(!aux) break;*/




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
    cubos.last()->posicion(x - 25, 55 + 55);
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

    for(int i = 0; i < 8; i ++){// linea horizontal de abajo, centro
        cubos.append(new suelo(nullptr));
        cubos.last()->posicion(x, y);
        cubos.last()->setScale(1.3);
        scene->addItem(cubos.last());
        x += 55;
    }


}


