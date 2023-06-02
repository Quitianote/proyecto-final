#ifndef BALA_H
#define BALA_H

#include <QPainter>
#include <QGraphicsItem>



class bala: public QGraphicsItem
{

private:
    int x;
    int y;
    int radio;

public:
    bala(int rad);
    ~bala();

    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    void posicion();
    void posicion(int newX, int newY);
    void disparo(int);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BALA_H
