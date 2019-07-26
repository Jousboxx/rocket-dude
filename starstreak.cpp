#include "starstreak.h"
#include <QPen>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"

extern Game * game;

StarStreak::StarStreak()
{
    setPen(QPen(Qt::white));

    connect(game, SIGNAL(frame()), this, SLOT(move()));

    setZValue(speed);

}

void StarStreak::move(){
    x -= speed;
    setLine(x, y, x - speed, y);

    if(x < 0){
        scene()->removeItem(this);
        delete(this);
    }

}

