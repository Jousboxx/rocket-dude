#pragma once
#include <QGraphicsPixmapItem>

class RocketFlame: public QGraphicsPixmapItem
{
public:
    RocketFlame(int x, int y);
    void setState(int state);
};
