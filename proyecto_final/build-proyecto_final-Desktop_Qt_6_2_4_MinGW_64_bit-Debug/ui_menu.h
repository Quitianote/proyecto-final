/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QGraphicsView *graphicsView;
    QPushButton *boton_play;
    QPushButton *boton_score;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(600, 450);
        graphicsView = new QGraphicsView(menu);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 600, 450));
        boton_play = new QPushButton(menu);
        boton_play->setObjectName(QString::fromUtf8("boton_play"));
        boton_play->setGeometry(QRect(340, 190, 121, 24));
        boton_play->setStyleSheet(QString::fromUtf8("font: 9pt \"Copperplate Gothic Bold\";\n"
"background-color: rgb(197, 197, 197);\n"
"border-color: rgb(77, 77, 77);\n"
"border-right-color: rgb(255, 255, 255);\n"
"border-left-color: rgb(17, 17, 17);\n"
"border-top-color: rgb(102, 102, 102);\n"
"\n"
""));
        boton_score = new QPushButton(menu);
        boton_score->setObjectName(QString::fromUtf8("boton_score"));
        boton_score->setGeometry(QRect(340, 260, 121, 24));
        boton_score->setStyleSheet(QString::fromUtf8("font: 9pt \"Copperplate Gothic Bold\";\n"
"background-color: rgb(197, 197, 197);\n"
"border-color: rgb(77, 77, 77);\n"
"border-right-color: rgb(255, 255, 255);\n"
"border-left-color: rgb(17, 17, 17);\n"
"border-top-color: rgb(102, 102, 102);"));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Dialog", nullptr));
        boton_play->setText(QCoreApplication::translate("menu", "PLAY", nullptr));
        boton_score->setText(QCoreApplication::translate("menu", "SCORE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
