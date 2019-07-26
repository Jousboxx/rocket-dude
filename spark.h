#pragma once
#include <QGraphicsRectItem>
#include <QObject>

class Spark: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    double xSpeed;
    double ySpeed;

    int age = 0;

    int j = 50; //lifespan, once age j is reached, spark will become black and be deleted

    static const int speedSpread = 3;

    static const int xSpeedOffset = -8;

    static constexpr float yAccel = 0.5;

public:
    Spark(int x, int y, int spread);
    void setColor();
public slots:
    void fall();
};
