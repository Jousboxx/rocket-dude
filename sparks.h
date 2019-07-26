#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>

class Sparks: public QObject, public QGraphicsPixmapItem
{
    double fadeAmountPerFrame = 0.2;
public:
    Sparks(int x, int y);
public slots:
    void fade();
};
