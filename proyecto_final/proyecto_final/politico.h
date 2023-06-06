#ifndef POLITICO_H
#define POLITICO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class politico : public QGraphicsPixmapItem {

public:


    politico(QGraphicsItem *carr = nullptr);
    void setScale(qreal scale);

    void posicion();
    void posicion(int newX, int newY);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int x,y;
};

#endif // POLITICO_H
