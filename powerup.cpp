#include "powerup.h"
#include "game.h"
#include <QDebug>
extern Game * game;

Powerup::Powerup()
{
    setPos(game->gameWidth, (rand() % (game->gameHeight - 80)));
}

void Powerup::move()
{
    setPos(x() - motionSpeed, y());

    if(x() < -80){
        scene()->removeItem(this);
        delete this;
    }
}
