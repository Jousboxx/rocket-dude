#include "weapon.h"
#include "weaponindicator.h"
#include <QBrush>
#include <QDebug>
Weapon::Weapon()
{

}

void Weapon::resetTimeSinceShot()
{
    timeSinceShot = 0;
}

bool Weapon::isLoaded()
{
    return(timeSinceShot >= reloadTime);
}

void Weapon::reloadTick()
{
    timeSinceShot ++;
    if(isLoaded()){
        indicator->colorGreen();
    }else{
        indicator->colorRed();
    }
}
