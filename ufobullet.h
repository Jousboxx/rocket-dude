#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>

class ufoBullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int speed = 10;
public:
    ufoBullet(int x, int y);
public slots:
    void move();
};
