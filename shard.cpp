#include "shard.h"
#include "game.h"
#include <math.h>

extern Game * game;

Shard::Shard(int x, int y, bool isAsteroidShard)
{
    double r = (rand() % (posSpread * 2)) - posSpread;
    double theta = rand() % 360;

    if(isAsteroidShard){
        setPixmap(QPixmap(":/images/asteroidShard.png"));
        setPos(x + sin(theta) * r + 25, y + cos(theta) * r + 25);
    }else{ //It's a UFO shard
        setPixmap(QPixmap(":/images/ufoShard.png"));
        setPos(x + sin(theta) * 2.5 * r + 90, y + cos(theta) * 0.5 * r + 25);
    }

    xSpeed = (rand() % (speedSpread * 1000)) / 500 - speedSpread + xSpeedOffset;
    ySpeed = (rand() % (speedSpread * 1000)) / 500 - speedSpread;

}

void Shard::fall()
{

    setPos(x() + xSpeed, y() + ySpeed);

    if(y() > game->gameHeight){
        scene()->removeItem(this);
        delete this;
    }

    ySpeed += yAccel;


}
