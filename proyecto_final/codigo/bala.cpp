#include "bala.h"

int bala::getX() const
{
    return x;
}

void bala::setX(int newX)
{
    x = newX;
}

int bala::getY() const
{
    return y;
}

void bala::setY(int newY)
{
    y = newY;
}

bala::bala(int rad)
{
    radio = rad;
}

bala::~bala()
{

}

void bala::posicion()
{
    setPos(x,y);
}

void bala::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

void bala::disparo(int vel)
{
    posicion(x,y+vel);
}

QRectF bala::boundingRect() const
{
    return QRectF(-radio/2,-radio/2,radio,radio);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

