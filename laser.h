#pragma once
#include "weapon.h"
#include "weaponindicator.h"
#include <QPixmap>

class Laser: public Weapon
{
    Q_OBJECT
    int width;
    int xPos;
    int yPos;
    QGraphicsRectItem * beam = new QGraphicsRectItem();
public:
    Laser();
    void fire();
public slots:
    void deleteShot();
};
