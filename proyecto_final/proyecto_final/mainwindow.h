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

    void caida();

private slots:
    void bala_mov(); 

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    suelo *piso;
    jeffrey *jugador;

    int vel;
    int vel_auto;

    QList<suelo*> orilla;
    QList<suelo*> lista_piso;
    QList<bala*> balas;

    QTimer *timer_sold;
    QTimer *timer_bala;

    QGraphicsPixmapItem* fondo;

};

#endif // MAINWINDOW_H
