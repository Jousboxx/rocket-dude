#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>


class Asteroid: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    static const int motionSpeed = 5;
    int health = 5;
public:
    Asteroid();
    void destroy();
    void decreaseHealth();
public slots:
    void move();  
};

