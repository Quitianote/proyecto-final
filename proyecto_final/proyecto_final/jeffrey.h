#ifndef JEFFREY_H
#define JEFFREY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
class jeffrey : public QGraphicsPixmapItem {

public:


    jeffrey(QGraphicsItem *carr = nullptr);
    void setScale(qreal scale);

    void posicion();
    void posicion(int newX, int newY);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void empujar();

    void setVy(float _vy);
    float getVy();



private slots:
    void tos();

private:
    int x,y;

    float vy = 0;
};


#endif // JEFFREY_H
