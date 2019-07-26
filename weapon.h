#pragma once
#include "weaponindicator.h"
#include <QObject>

class Weapon: public QObject
{
    Q_OBJECT



public:
    int timeSinceShot;
    Weapon();
    bool isLoaded();
    //These two must be intialized in the constructor of the child concrete weapon class
    WeaponIndicator * indicator;
    int reloadTime;

    virtual void fire() = 0;

    void resetTimeSinceShot();
public slots:
    void reloadTick();
};
