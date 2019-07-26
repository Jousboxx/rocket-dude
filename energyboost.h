#pragma once
#include "powerup.h"
class EnergyBoost: public Powerup
{
    static const int energyAmount = 25;
public:
    EnergyBoost();
    void givePowerup();
};
