#include "suelo.h"
#include <Qpainter>

QRectF suelo::boundingRect() const {
    return QRectF(0, 0, pixmap().width()+10, pixmap().height()+5);
}


void suelo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}




suelo::suelo(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/imagenes/cubo - copia.png"));
}

void suelo::posicion()
{
    setPos(x,y);
}

void suelo::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}


int suelo::getX() const
{
    return x;
}

void suelo::setX(int value)
{
    x = value;
}

int suelo::getY() const
{
    return y;
}

void suelo::setY(int value)
{
    y = value;
}


void suelo::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale);
}

