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

    bool col_est();

    void crear_orilla();

    void keyPressEvent(QKeyEvent *event);

    void crear_suelo();

private slots:
    void bala_mov(); 

    void salto();

    void caida();
    //void on_pushButton_clicked();
    //void verify(menu *N);


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    suelo *piso;
    jeffrey *jugador;
    politico *politico_1;
    soldado *soldado_1;

    int vel;
    int vel_auto;

    QList<suelo*> orilla;
    QList<suelo*> lista_piso;
    QList<bala*> balas;
    QList<suelo*> cubos;
    QList<QGraphicsItem*> colisiones;

    QTimer *timer_sold;
    QTimer *timer_bala;
    QTimer *timer_caida;

    QGraphicsPixmapItem* fondo;



};

#endif // MAINWINDOW_H
