#include "sparks.h"
#include "QGraphicsScene"
Sparks::Sparks(int x, int y)
{
    setPixmap(QPixmap(":/images/sparks.png"));
    setPos(x - 14, y - 29);
}

void Sparks::fade()
{
    setOpacity(opacity() - fadeAmountPerFrame);
    if(opacity() <= 0){
        scene()->removeItem(this);
        delete this;
    }
}
