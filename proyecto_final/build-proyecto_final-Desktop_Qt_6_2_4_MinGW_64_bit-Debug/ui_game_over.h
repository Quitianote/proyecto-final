/********************************************************************************
** Form generated from reading UI file 'game_over.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_OVER_H
#define UI_GAME_OVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_game_over
{
public:
    QGraphicsView *graphicsView;
    QLabel *total;

    void setupUi(QDialog *game_over)
    {
        if (game_over->objectName().isEmpty())
            game_over->setObjectName(QString::fromUtf8("game_over"));
        game_over->resize(800, 600);
        graphicsView = new QGraphicsView(game_over);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        total = new QLabel(game_over);
        total->setObjectName(QString::fromUtf8("total"));
        total->setGeometry(QRect(90, 240, 51, 21));
        total->setStyleSheet(QString::fromUtf8("font: 20pt \"Impact\";\n"
"background-color: rgb(255, 255, 255);"));
        total->raise();
        graphicsView->raise();

        retranslateUi(game_over);

        QMetaObject::connectSlotsByName(game_over);
    } // setupUi

    void retranslateUi(QDialog *game_over)
    {
        game_over->setWindowTitle(QCoreApplication::translate("game_over", "Dialog", nullptr));
        total->setText(QCoreApplication::translate("game_over", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_over: public Ui_game_over {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_OVER_H
