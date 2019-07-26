#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>

class BoostParticle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    double xSpeed = rand() % 10 - 5;
    double ySpeed = 10;
    double yAccel = -0.42;

    double x;
    double y;

    int lifetime = 22;
    int age = 0;

public:
    BoostParticle();
public slots:
    void move();
};
