#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QDebug>
#include "jeffrey.h"
#include "suelo.h"
#include "bala.h"
#include "soldado.h"
#include "politico.h"
#include "menu.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void crear_orilla();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

    void crear_suelo();

    void disparar();

    bool col_y();
    bool col_y_sold();
    bool col_y_arriba();

    bool col_x_A();
    bool col_x_D();

    bool col_s_A();
    bool col_s_D();

    bool col_sold();

    void crear_poli();
    void crear_sold();

    void puntaje();

    int getPuntos();

private slots:
    void bala_D();
    void bala_A();

    void salto();

    void caida();
    void caida_sold();

    void tiempo();

    void ver();

    void fric_A();
    void fric_D();

    void mov_lat_D();
    void mov_lat_A();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    suelo *piso;
    jeffrey *jugador;
    politico *politico_1;
    soldado *soldado_1;
    soldado *soldado_disp;

    bool temp = false;

    int vel;

    int dist;

    float vA = 60;
    float vD = 60;

    int num = 0;

    int puntos = 0;

    int time_ = 11;

    int poli = 1;

    int sold = 0;

    int ult;

    QList<suelo*> orilla;
    QList<suelo*> lista_piso;
    QList<bala*> balas;
    QList<suelo*> cubos;
    QList<QGraphicsItem*> colisiones;
    QList<soldado*> soldados;

    QTimer *timer_fric_A;
    QTimer *timer_fric_D;
    QTimer *timer_bala_A;
    QTimer *timer_bala_D;
    QTimer *timer_caida;
    QTimer *timer_caida_sold;
    QTimer *timer_lat_D;
    QTimer *timer_lat_A;
    QTimer *timer_salto;
    QTimer *timer_tiempo;
    QTimer *timer_ver;

    QGraphicsPixmapItem* fondo;
};

#endif // MAINWINDOW_H
