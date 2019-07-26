#include "ufobullet.h"
#include <QGraphicsScene>

ufoBullet::ufoBullet(int x, int y)
{
    setPos(x, y);
    setPixmap(QPixmap(":/images/ufoBullet.png"));
}

void ufoBullet::move()
{
    setPos(x() - speed, y());

    if(x() < -20){
        scene()->removeItem(this);
        delete this;
    }
}
