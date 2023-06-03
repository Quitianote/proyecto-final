#include "politico.h"
#include <Qpainter>

QRectF politico::boundingRect() const {
    return QRectF(0, 0, pixmap().width(), pixmap().height());
}

void politico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}


politico::politico(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/imagenes/politico_1.png"));
}


void politico::posicion()
{
    setPos(x,y);
}

void politico::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

int politico::getX() const
{
    return x;
}

void politico::setX(int value)
{
    x = value;
}

int politico::getY() const
{
    return y;
}

void politico::setY(int value)
{
    y = value;
}

void politico::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale);
}

