#pragma once
#include <QGraphicsPixmapItem>
#include <QObject>

class Shard: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    double xSpeed;
    double ySpeed;

    static const int posSpread = 30;
    static const int speedSpread = 3;

    static const int xSpeedOffset = -8;

    static constexpr float yAccel = 0.5;

public:
    Shard(int x, int y, bool isAsteroidShard);
public slots:
    void fall();
};
