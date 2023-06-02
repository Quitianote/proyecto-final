#include "menu.h"
#include "ui_menu.h"
#include <QGraphicsScene>

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    fondo = new QGraphicsPixmapItem(QPixmap(":/imagenes/fondo_menu.png"));
    scene->addItem(fondo);
    fondo->setPixmap(QPixmap(":/imagenes/fondo_menu.png").scaled(600, 450));
    fondo->setPos(-150, -180);

}

menu::~menu()
{
    delete ui;
}

void menu::on_backButton_clicked()
{
    MainWindow *N =  new MainWindow;
    N->show();
    this->close();
}

/*void menu::on_backButton_clicked()
{
    MainWindow *N =  new MainWindow;
    N->show();
    this->close();
}
*/
