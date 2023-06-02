#include "soldado.h"
#include <Qpainter>

QRectF soldado::boundingRect() const {
    return QRectF(0, 0, pixmap().width(), pixmap().height());
}

void soldado::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}


soldado::soldado(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
   // setPixmap(QPixmap(":/images/character.png"));
}


void soldado::posicion()
{
    setPos(x,y);
}

void soldado::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

int soldado::getX() const
{
    return x;
}

void soldado::setX(int value)
{
    x = value;
}

int soldado::getY() const
{
    return y;
}

void soldado::setY(int value)
{
    y = value;
}

void soldado::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale);
}

