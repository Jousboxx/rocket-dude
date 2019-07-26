#include "energyboost.h"
#include "powerup.h"
#include <QDebug>
#include <QString>
#include "game.h"
#include "energygauge.h"

extern Game * game;

EnergyBoost::EnergyBoost()
{
    setPixmap(QPixmap(":/images/energyBoost.png"));
}

void EnergyBoost::givePowerup()
{
    game->energyGauge->addEnergy(energyAmount);
}
