#pragma once
#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#include <QGraphicsTextItem>

class EnergyGauge: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    double energy = 20;
    double regenSpeed = 1.5;
public:
    QGraphicsTextItem * energyText = new QGraphicsTextItem();
    EnergyGauge();
    void useEnergy(double howMuch);
    void addEnergy(double howMuch);
    double getEnergy();
public slots:
    void updateGauge();
};
