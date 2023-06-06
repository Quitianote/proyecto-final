#include "mainwindow.h"
#include "menu.h"
#include "game_over.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //menu w;
    MainWindow w;
    //game_over w;
    w.show();
    return a.exec();
}
