#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>
#include "rocketFlame.h"


class Missle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int age = 0;

    double decel = -0.2;
    double accel = 1.5;

    double ySpeed = 3;
    double speed = 0;

    bool dead = false;

    RocketFlame * flame = new RocketFlame(0, 0);
public:
    Missle(int x, int y);
public slots:
    void move();
};
