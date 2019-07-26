//game.h
#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "energygauge.h"
#include "player.h"
#include "laser.h"
#include "missleindicator.h"

class Game: public QObject
{
    Q_OBJECT
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView();


public:
    static const int gameWidth = 1600;
    static const int gameHeight = 900;
    
    //cheats
    static const bool unlimitedPower = false;
    static const bool backWall = false;

    static const int energyBoostRegularity = 50;
    static const int asteroidRegularity = 50;
    static const int ufoRegularity = 400;

    static const int collisionDamage = 15;
    static const int ufoBulletDamage = 5;

    static const bool enableParticles = true;

    EnergyGauge * energyGauge = new EnergyGauge();
    Laser * laser = new Laser();
    Player * player = new Player();

    MissleIndicator* missleIndicator = new MissleIndicator();

    Game();
    void spawnStarStreak();
    void spawnEnergyBoost();
    void spawnAsteroid();
    void spawnUfo();

public slots:
    void emitFrame();
signals:
    void frame();
};
