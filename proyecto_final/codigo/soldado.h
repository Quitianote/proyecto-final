#ifndef SOLDADO_H
#define SOLDADO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class soldado : public QGraphicsPixmapItem {

public:


    soldado(QGraphicsItem *carr = nullptr);
    void setScale(qreal scale);
    void posicion();
    void posicion(int newX, int newY);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void friccion();

private:
    int x,y;
};

#endif // SOLDADO_H
