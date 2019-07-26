#include "game.h"
#include <QTimer>
#include <QGraphicsItem>
#include "starstreak.h"
#include "player.h"
#include "energygauge.h"
#include "energyboost.h"
#include "asteroid.h"
#include "weaponindicator.h"
#include "laser.h"
#include "boostparticle.h"
#include "missle.h"
#include "ufo.h"
#include "ufobullet.h"
#include "spark.h"

#include "shard.h"
#include <QDebug>

Game::Game()
{
    view->setScene(scene);

    //Set size of window
    view->setFixedSize(gameWidth, gameHeight);
    scene->setSceneRect(0, 0, gameWidth, gameHeight);

    //Turn off scrollbars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Make background black
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    //Prepare player
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player->rocketFlame);
    connect(this, SIGNAL(frame()), player, SLOT(handleInput()));

    //energy gauge
    scene->addItem(energyGauge);
    scene->addItem(energyGauge->energyText);
    connect(this, SIGNAL(frame()), energyGauge, SLOT(updateGauge()));

    //laser
    scene->addItem(laser->indicator);
    scene->addItem(laser->indicator->indicatorImage);
    connect(this, SIGNAL(frame()), laser, SLOT(reloadTick()));
    connect(this, SIGNAL(frame()), laser, SLOT(deleteShot()));

    //do frames
    QTimer * frameTimer = new QTimer();
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(emitFrame()));
    frameTimer->start(16);

    //missle
    scene->addItem(missleIndicator->indicator);
    scene->addItem(missleIndicator->indicator->indicatorImage);
     connect(this, SIGNAL(frame()), missleIndicator, SLOT(reloadTick()));

    //Show
    view->setVisible(true);
}

//This method is everything that happens in game on each frame, and also it sends the frame signal to the rest of the program
void Game::emitFrame()
{
    //spawn star streaks
    spawnStarStreak();

    //spawn energy boosts
    if(rand() % energyBoostRegularity == 1){
        spawnEnergyBoost();
    }

    //spawn asteroids
    if(rand() % asteroidRegularity == 1){
        spawnAsteroid();
    }

    //spawn ufos
    if(rand() % ufoRegularity == 1){
        spawnUfo();
    }

    //Getting Powerups
    {
    QList<QGraphicsItem *> colliding_items = player->collidingItems(); //This list can hold any QGraphicsItem

    for(int i = 0; i < colliding_items.size(); i ++){ //For each thing in the first list

        if(typeid(*(colliding_items[i])) == typeid(EnergyBoost)){ //If it's a Powerup
            Powerup *temp = dynamic_cast<Powerup *>(colliding_items[i]);
            temp->givePowerup();
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];

            if(enableParticles){
                //Boost Particles
                for(int j = 0; j < 40; j ++){
                    BoostParticle* b = new BoostParticle();
                    scene->addItem(b);
                    connect(this, SIGNAL(frame()), b, SLOT(move()));
                }
            }

        }else if(typeid(*(colliding_items[i])) == typeid(Asteroid)){ //If it's an Asteroid
            energyGauge->useEnergy(collisionDamage);
            Asteroid *temp = dynamic_cast<Asteroid *>(colliding_items[i]);
            temp->destroy();
        }else if(typeid(*(colliding_items[i])) == typeid(ufo)){ //If it's a ufo
            energyGauge->useEnergy(collisionDamage);
            ufo *temp = dynamic_cast<ufo*>(colliding_items[i]);
            temp->destroy();
        }else if(typeid(*(colliding_items[i])) == typeid(ufoBullet)){ //If it's a ufoBullet
            energyGauge->useEnergy(ufoBulletDamage);

            for(int j = 0; j < 10; j ++){
                Spark * s = new Spark(colliding_items[i]->x(), colliding_items[i]->y(), 4);
                scene->addItem(s);
                connect(game, SIGNAL(frame()), s, SLOT(fall()));
            }

            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }

    }
    emit frame();
}

void Game::spawnStarStreak(){
        StarStreak * s = new StarStreak();
        scene->addItem(s);
}

void Game::spawnEnergyBoost()
{
    EnergyBoost * e = new EnergyBoost();
    scene->addItem(e);
    connect(this, SIGNAL(frame()), e, SLOT(move()));
}

void Game::spawnAsteroid()
{
    Asteroid * a = new Asteroid();
    scene->addItem(a);
    connect(this, SIGNAL(frame()), a, SLOT(move()));
}

void Game::spawnUfo()
{
    ufo* u = new ufo();
    scene->addItem(u);
    connect(this, SIGNAL(frame()), u, SLOT(move()));
}

