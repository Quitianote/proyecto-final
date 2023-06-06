#ifndef SOLDADO_H
#define SOLDADO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class soldado : public QGraphicsPixmapItem {

public:


    soldado(QGraphicsItem *carr = nullptr);
    void setScale(qreal scale);

    void pos2();
    void posicion();
    void posicion(int newX, int newY);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


    float getVy() const;
    void setVy(float newVy);

private:
    int x,y;

    float vy = 0;

};

#endif // SOLDADO_H
