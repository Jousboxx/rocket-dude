//energygauge.cpp
#include "energygauge.h"
#include <QBrush>
#include "game.h"

extern Game * game;

EnergyGauge::EnergyGauge()
{ 
    setZValue(40);
    energyText->setDefaultTextColor(Qt::white);
    energyText->setFont(QFont("arial", 16));
    energyText->setZValue(40);
    energyText->setPos(10, game->gameHeight - 38);

    if(game->unlimitedPower){
        energyText->setPlainText(QString("Energy: unlimited"));
        setBrush(Qt::blue);
        setRect(-1, game->gameHeight - 40, game->gameWidth, game->gameHeight);
    }else{

    }
    updateGauge();
}

void EnergyGauge::useEnergy(double howMuch)
{
    energy -= howMuch;
}

void EnergyGauge::addEnergy(double howMuch)
{
    energy += howMuch;
}

double EnergyGauge::getEnergy()
{
    return energy;
}

void EnergyGauge::updateGauge()
{
    if(game->unlimitedPower){
        energy = 100;
    }else{
        energy += regenSpeed;

        if(energy > 100){
            energy = 100;
        }else if(energy < 0){
            energy = 0;
        }
        setBrush(QColor(2.5 * (100 - energy), 2 * energy, 0));
        setRect(0, game->gameHeight - 40, energy/100.0 * game->gameWidth, game->gameHeight);
        energyText->setPlainText(QString("Energy: ") + QString::number(energy, 'f', 0) + QString("%"));
    }

}
