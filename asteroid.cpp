#include "asteroid.h"
#include "game.h"
#include "shard.h"
#include "spark.h"

extern Game * game;


Asteroid::Asteroid()
{
    setPixmap(QPixmap(":/images/asteroid.png"));
    setPos(game->gameWidth, (rand() % (game->gameHeight - 80)));
}

void Asteroid::move()
{
    setPos(x() - motionSpeed, y());

    if(x() < -80){
        scene()->removeItem(this);
        delete this;
    }
}

void Asteroid::destroy()
{
    if(game->enableParticles){
        //Burst of asteroid shards
        for(int i = 0; i < 30; i ++){
            Shard * a = new Shard(x(), y(), true);
            scene()->addItem(a);
            connect(game, SIGNAL(frame()), a, SLOT(fall()));
        }

        //Burst of sparks
        for(int j = 0; j < 40; j ++){
            Spark * s = new Spark(x(), y(), 50);
            scene()->addItem(s);
            connect(game, SIGNAL(frame()), s, SLOT(fall()));
        }
    }


    //Get rid of the asteroid
    scene()->removeItem(this);
    delete this;
}

void Asteroid::decreaseHealth()
{
    health -= 1;
    if(health == 0){
        destroy();
    }
}
