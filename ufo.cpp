#include "ufo.h"
#include "game.h"
#include "shard.h"
#include "spark.h"
#include "ufobullet.h"

extern Game* game;

ufo::ufo()
{
    setPixmap(QPixmap(":/images/ufo.png"));
    setPos(game->gameWidth - 200, rand() % game->gameHeight);
    setZValue(39);

    behavior = (rand() % 2) + 1;
}

void ufo::destroy()
{
    if(game->enableParticles){
        //Burst of ufo shards
        for(int i = 0; i < 30; i ++){
            Shard * u = new Shard(x(), y(), false);
            scene()->addItem(u);
            connect(game, SIGNAL(frame()), u, SLOT(fall()));
        }

        //Burst of sparks
        for(int j = 0; j < 40; j ++){
            Spark * s = new Spark(x(), y(), 50);
            scene()->addItem(s);
            connect(game, SIGNAL(frame()), s, SLOT(fall()));
        }
    }

    //Get rid of the ufo
    scene()->removeItem(this);
    delete this;
}

void ufo::decreaseHealth()
{
    health -= 1;
    if(health == 0){
        destroy();
    }
}

void ufo::shoot()
{
    timeSinceShot ++;
    if(timeSinceShot > reloadTime){
        ufoBullet* uu = new ufoBullet(x(), y());
        scene()->addItem(uu);
        connect(game, SIGNAL(frame()), uu, SLOT(move()));
        timeSinceShot = 0;
    }
}

void ufo::move()
{
    if(behavior == 1){ //Move up and down
        if(movingUp){
            setPos(x(), y() - speed);
        }else{
            setPos(x(), y() + speed);
        }

        if(y() < 0){
            movingUp = false;
        }else if(y() > game->gameHeight - 50){
            movingUp = true;
        }
    }else if(behavior == 2){ //follow player
        if(y() > game->player->y() + 26){
            setPos(x(), y() - speed);
        }else if(y() < game->player->y() + 24){
            setPos(x(), y() + speed);
        }
    }

    shoot();
}
