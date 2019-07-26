#include "laser.h"
#include <QGraphicsRectItem>
#include "game.h"
#include <QDebug>
#include "asteroid.h"
#include "ufo.h"
#include "spark.h"

extern Game * game;

Laser::Laser()
{
    reloadTime = 2;
    indicator = new WeaponIndicator(0, QPixmap(":/images/laser.png"));
    resetTimeSinceShot();
    beam->setBrush(Qt::green);
    beam->setPen(Qt::NoPen);
}

void Laser::fire()
{
    if(isLoaded()){
        resetTimeSinceShot();
        beam->setRect(game->player->x() + game->player->shipWidth - 70, game->player->y() + game->player->shipHeight/2 + 30, game->gameWidth, 4);
        game->player->scene()->addItem(beam);

        QList<QGraphicsItem *> colliding_items = beam->collidingItems();

        QGraphicsItem * closest;
        bool hitSomething = false;

        //Loop through all objects the laser beam is colliding with, searching for the object with the lowest x coordinate
        for(int i = 0; i < colliding_items.size(); i ++){

            //If this item is an asteroid or ufo
            if(typeid(*(colliding_items[i])) == typeid(Asteroid) || typeid(*(colliding_items[i])) == typeid(ufo)){

                //If we've already detected at least one object, we know that closest is defined and we can compare the x coordinates
                if(hitSomething){

                    //If this object is closer than closest, update closest
                    if(colliding_items[i]->x() < closest->x() && hitSomething){
                        closest = colliding_items[i];
                    }

                }else{ //If hitSomething is false, we know this is the first and closest object we have found so far.
                    closest = colliding_items[i];
                    hitSomething = true;
                }
            }

        }

        //If we hit an something,
        if(hitSomething){

            if(typeid(*(closest)) == typeid(Asteroid)){
                //Cast closest into Asteroid* data type
                Asteroid * a = dynamic_cast<Asteroid *>(closest);
                //decrease the health of the thing we shot
                a->decreaseHealth();
            }else if(typeid(*(closest)) == typeid(ufo)){
                //Cast closest into ufo* data type
                ufo * u = dynamic_cast<ufo *>(closest);
                //decrease the health of the thing we shot
                u->decreaseHealth();
            }

            //Calculate the coordinates and length of laser beam and update it
            width = closest->x() - game->player->x() - 170;
            xPos = game->player->x() + game->player->shipWidth - 70;
            yPos = game->player->y() + game->player->shipHeight/2 + 30;
            beam->setRect(xPos, yPos, width, 4);


            if(game->enableParticles){
                //Spawn sparks at the point where the beam hits the asteroid
                for(int j = 0; j < 2; j ++){
                    Spark * s = new Spark(xPos + width - 40, yPos - 40, 4);
                    beam->scene()->addItem(s);
                    connect(game, SIGNAL(frame()), s, SLOT(fall()));
                }
            }

        }

    }


}

void Laser::deleteShot()
{
    if(timeSinceShot == 2){
        game->player->scene()->removeItem(beam);
    }

}
