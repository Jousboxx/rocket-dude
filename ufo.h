#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>

class ufo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    static const int motionSpeed = 5;
    int health = 20;

    //int behavior = (rand() % 3) + 1; //1 = move up and down repeatedly, 2 = follow player, 3 = dive bomb

    int behavior = 2;
    static const int speed = 3;

    bool movingUp = false;

    int timeSinceShot = 0;
    static const int reloadTime = 30;

public:
    ufo();
    void destroy();
    void decreaseHealth();
    void shoot();
public slots:
    void move();
};

