#include "jeffrey.h"
#include <Qpainter>

QRectF jeffrey::boundingRect() const {
    return QRectF(0, 0, pixmap().width(), pixmap().height());
}

void jeffrey::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}

void jeffrey::setVy(float _vy)
{
    vy = _vy;
}

float jeffrey::getVy()
{
    return vy;
}


jeffrey::jeffrey(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/imagenes/jeffrey-derecha - copia.png"));
}


void jeffrey::posicion()
{
    setPos(x,y);
}

void jeffrey::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

int jeffrey::getX() const
{
    return x;
}

void jeffrey::setX(int value)
{
    x = value;
}

int jeffrey::getY() const
{
    return y;
}

void jeffrey::setY(int value)
{
    y = value;
}

void jeffrey::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale);
}

