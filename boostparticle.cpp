#include "boostparticle.h"
#include "game.h"
#include "spark.h"

#include <QDebug>

extern Game * game;

BoostParticle::BoostParticle()
{
    setPixmap(QPixmap(":/images/boostParticle.png"));

    x = rand() % game->player->shipWidth;
    y = game->player->shipHeight + (rand() % 30) - 15;

    setPos(game->player->x() + x, game->player->y() + y);
    setZValue(39);
}

void BoostParticle::move()
{

    x -= xSpeed;
    y -= ySpeed;

    setPos(game->player->x() + x, game->player->y() + y);

    ySpeed += yAccel;

    //if a particle moves toward the right or left side of the ship, push it toward to middle
    xSpeed += (x - game->player->shipWidth/2.0) * 0.8/game->player->shipWidth;

    //Decrease opacity of particles so they appear to fade out
    setOpacity((double)(lifetime - age) * 1.0/lifetime);

    if(age > lifetime){
        scene()->removeItem(this);
        delete this;
    }

    age ++;

}
