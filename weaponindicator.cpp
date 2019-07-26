#include "weaponindicator.h"
#include "game.h"
#include <QPen>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDebug>

extern Game * game;

WeaponIndicator::WeaponIndicator(int xPos, QPixmap image)
{

    colorBlue();
    setPen(QPen(Qt::white));
    setRect(xPos, game->gameHeight - 76, 130, 37);
    setZValue(40);

    indicatorImage->setPixmap(image);
    indicatorImage->setPos(xPos, game->gameHeight - 76);
    indicatorImage->setZValue(40);

}

void WeaponIndicator::colorRed()
{
    setBrush(QColor(120, 40, 40));
}

void WeaponIndicator::colorBlue()
{
    setBrush(QColor(40, 40, 120));
}

void WeaponIndicator::colorGreen()
{
    setBrush(QColor(40, 120, 40));
}



