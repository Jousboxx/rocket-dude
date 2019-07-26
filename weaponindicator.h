#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class WeaponIndicator: public QGraphicsRectItem
{

public:
    QGraphicsPixmapItem * indicatorImage = new QGraphicsPixmapItem();
    WeaponIndicator(int xPos, QPixmap image);
    void colorRed();
    void colorBlue();
    void colorGreen();
};
