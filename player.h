#pragma once
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "rocketFlame.h"

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;
    bool upKeyPressed = false;
    bool downKeyPressed = false;
    bool toggleKeyPressed = false;

    bool leftMousePressed = false;
    bool rightMousePressed = false;

    int rocketState = 1;
    bool outOfEnergy = false;

    //Control definitions
    Qt::Key upKey = Qt::Key_W;
    Qt::Key leftKey = Qt::Key_A;
    Qt::Key downKey = Qt::Key_S;
    Qt::Key rightKey = Qt::Key_D;
    Qt::Key toggleKey = Qt::Key_Space;


    double speed = 0;

    const int rocketFlameX = -102;
    const int rocketFlameY = 30;

    const int turboShakeAmount = 7;

public:
    const int shipHeight = 99;
    const int shipWidth = 245;

    Player();
    RocketFlame * rocketFlame = new RocketFlame(100, 100);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    //void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);

    //void mouseMoveEvent(QMouseEvent *event);

public slots:
    void handleInput();
};
