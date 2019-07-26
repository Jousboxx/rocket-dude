#pragma once
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>

class Powerup: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    static const int motionSpeed = 5;
public:
    virtual void givePowerup() = 0;
    Powerup();
public slots:
    void move();
};

