#include "missleindicator.h"
#include "missle.h"
#include "game.h"

extern Game* game;

MissleIndicator::MissleIndicator()
{
    reloadTime = 60;
    indicator = new WeaponIndicator(200, QPixmap(":/images/missleIndicator.png"));
    resetTimeSinceShot();
}

void MissleIndicator::fire()
{
    if(isLoaded()){
        Missle* m = new Missle(game->player->x(), game->player->y());
        game->player->scene()->addItem(m);
        connect(game, SIGNAL(frame()), m, SLOT(move()));
        resetTimeSinceShot();
    }
}
