#include "missle.h"
#include "game.h"
#include "rocketFlame.h"
#include "asteroid.h"
#include "ufo.h"
#include "spark.h"

extern Game* game;

Missle::Missle(int x, int y)
{

    //setPos(game->player->x(), game->player->y());
    setPos(x, y);
    flame->setState(0);
    setPixmap(QPixmap(":/images/missle.png"));
    setZValue(39);
}

void Missle::move()
{
    setPos(x() + speed, y() + ySpeed);

    if(age > 50){
        speed += accel;
        ySpeed -= 0.1;
        flame->setPos(x() - 140, y() - 5);
    }else if(age == 50){
       flame->setState(2);
       flame->setPos(x() - 140, y() - 5);
       scene()->addItem(flame);
    }else{
        speed += decel;
    }
    age ++;

    QList<QGraphicsItem *> colliding_items = this->collidingItems();

    for(int i = 0; i < colliding_items.size(); i ++){ //For each thing in the first list

        if(typeid(*(colliding_items[i])) == typeid(Asteroid)){ //If it's an Asteroid
            Asteroid *temp = dynamic_cast<Asteroid *>(colliding_items[i]);

            if(game->enableParticles){
                //Burst of sparks
                for(int j = 0; j < 70; j ++){
                    Spark * s = new Spark(temp->x(), temp->y(), 60);
                    scene()->addItem(s);
                    connect(game, SIGNAL(frame()), s, SLOT(fall()));
                }
            }
            temp->destroy();

            dead = true;
        }else if(typeid(*(colliding_items[i])) == typeid(ufo)){ //If it's an ufo
            ufo *temp = dynamic_cast<ufo *>(colliding_items[i]);

            if(game->enableParticles){
                //Burst of sparks
                for(int j = 0; j < 70; j ++){
                    Spark * s = new Spark(temp->x(), temp->y(), 60);
                    scene()->addItem(s);
                    connect(game, SIGNAL(frame()), s, SLOT(fall()));
                }
            }
            temp->destroy();

            dead = true;
        }
    }

    if(x() > game->gameWidth || dead){
        scene()->removeItem(flame);
        delete flame;
        scene()->removeItem(this);
        delete this;
    }
}
