#include "spark.h"
#include <QGraphicsRectItem>
#include <math.h>
#include "game.h"
#include <QDebug>

extern Game * game;

Spark::Spark(int x, int y, int spread)
{
    setColor();
    setPen(Qt::NoPen);

    double r = (rand() % (spread * 2)) - spread;
    double theta = rand() % 360;

    setRect(x + sin(theta) * r + 38, y + cos(theta) * r + 38, 4, 4);

    xSpeed = (rand() % (speedSpread * 1000)) / 500 - speedSpread + xSpeedOffset;
    ySpeed = (rand() % (speedSpread * 1000)) / 500 - speedSpread;

    setZValue(39);
}

void Spark::setColor()
{
    setBrush(QColor(-pow(255, 0.02 * age) + 255, -5.1 * age + 255, pow(255, -age/50.0 + 1)));
}

void Spark::fall()
{
    setPos(x() + xSpeed, y() + ySpeed);

    ySpeed += yAccel;
    age += 1;

    if(age > j || isObscured()){
        scene()->removeItem(this);
        delete this;
    }else{
        setColor();

    }

}
