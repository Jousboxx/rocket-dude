#pragma once
#include "weapon.h"
#include "weaponindicator.h"
#include <QPixmap>


class MissleIndicator: public Weapon
{
    Q_OBJECT
public:
    MissleIndicator();
    void fire();
};
