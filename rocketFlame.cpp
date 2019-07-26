#include "rocketFlame.h"
#include <QPixmap>

RocketFlame::RocketFlame(int x, int y)
{
    setPixmap(QPixmap(":/images/low.png"));
    setPos(x, y);
    setZValue(19);

}

void RocketFlame::setState(int state)
{
    switch(state){
    case 0:
        setPixmap(QPixmap(":/images/off.png"));
        break;
    case 1:
        setPixmap(QPixmap(":/images/low.png"));
        break;
    case 2:
        setPixmap(QPixmap(":/images/high.png"));
        break;
    case 3:
        setPixmap(QPixmap(":/images/turbo.png"));
        break;
    }
}
