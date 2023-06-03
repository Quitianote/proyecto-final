#ifndef MENU_H
#define MENU_H

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

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QDialog
{
    Q_OBJECT

public:
    //explicit menu(QWidget *parent = nullptr);
    menu(QWidget *parent = nullptr);
    ~menu();
private slots:
   // void on_GifButton_clicked();

    void jugar();

private:
    Ui::menu *ui;
    QGraphicsScene *scene;


    QGraphicsPixmapItem* fondo;
};

#endif // MENU_H
