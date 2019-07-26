#pragma once
#include <QGraphicsLineItem>
#include <QObject>
#include <tgmath.h>
#include <game.h>
extern Game * game;
class StarStreak: public QObject, public QGraphicsLineItem
{
    Q_OBJECT

    int speed = pow((rand() % 5000)/1000.0 + 1.0, 2);
    int x = game->gameWidth;
    int y = rand() % game->gameHeight;
public:
    StarStreak();
public slots:
    void move();
};
