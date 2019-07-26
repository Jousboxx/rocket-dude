#include "player.h"
#include "game.h"
#include "rocketFlame.h"
#include <QPixmap>
#include <QObject>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>

extern Game * game;

Player::Player()
{
    setPixmap(QPixmap(":/images/shippy.png"));

    //setPos(game->gameWidth / 2 + shipWidth / 2, game->gameHeight / 2 + shipHeight / 2);
    setPos(100, 200);

    setZValue(20);


}

//Update bool variables whenever a key/mouse button is pressed or released. This allows for accurate multi-button input.

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();
    if(event->key() == upKey){
        upKeyPressed = true;
    }else if(event->key() == downKey){
        downKeyPressed = true;
    }else if(event->key() == leftKey){
        leftKeyPressed = true;
    }else if(event->key() == rightKey){
        rightKeyPressed = true;
    }else if(event->key() == toggleKey){
        toggleKeyPressed = true;
    }else if(event->key() == 16777237){ //down arrow
        leftMousePressed = true;
    }else if(event->key() == 16777235){ //up arrow
        rightMousePressed = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == upKey){
        upKeyPressed = false;
    }else if(event->key() == downKey){
        downKeyPressed = false;
    }else if(event->key() == leftKey){
        leftKeyPressed = false;
    }else if(event->key() == rightKey){
        rightKeyPressed = false;
    }else if(event->key() == toggleKey){
        toggleKeyPressed = false;
    }else if(event->key() == 16777237){ //down arrow
        leftMousePressed = false;
    }else if(event->key() == 16777235){ //up arrow
        rightMousePressed = false;
    }
}

/*
void Player::mousePressEvent(QMouseEvent *event)
{

    if(event->buttons() == Qt::LeftButton){
        leftMousePressed = true;
    }else if(event->buttons() == Qt::RightButton){
        rightMousePressed = true;
    }

    leftMousePressed = true;
}

void Player::mouseReleaseEvent(QMouseEvent *event)
{

    if(event->buttons() == Qt::LeftButton){
        leftMousePressed = false;
    }else if(event->buttons() == Qt::RightButton){
        rightMousePressed = false;
    }

    leftMousePressed = false;
}


void Player::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        leftMousePressed = true;
    }else if(event->button() == Qt::RightButton){
        rightMousePressed = true;
    }
}
*/

//Same for mouse

void Player::handleInput()
{
    setFocus();

    //qWarning() << leftMousePressed;


    //Up and down motion
    {
    if(upKeyPressed)
        setPos(x(), y() - 10);

    if(downKeyPressed)
        setPos(x(), y() + 10);
    }

    //Set rocket state based on left/right key combo
    {
    rocketState = 1; //set to low (default), will be changed if any keys are being pressed

    if(rightKeyPressed && leftKeyPressed){
        rocketState = 3;
    }else{
        if(leftKeyPressed){
                rocketState = 0; //off
        }

        if(rightKeyPressed){
            rocketState = 2; //high
        }
    }
    }

    //If we are out of energy, don't turn high power rockets on or regen energy
    //without this section they quickly pulse as the necessary energy regens making it basically impossible to lose
    if(outOfEnergy && rocketState > 1){
        rocketState = 0;
        game->energyGauge->useEnergy(5);
    }else{
        outOfEnergy = false;
    }

    //Make sure we have enough energy for the requested rocket state
    if(game->energyGauge->getEnergy() - rocketState < 0){
        rocketState = 0;
        outOfEnergy = true; //We are out of energy!
    }

    //Add/subtract from speed based on rocket state
    switch(rocketState){
    case 0:
        speed -= 0.3;
        break;
    case 1:
        speed -= 0.075;
        break;
    case 2:
        speed += 0.1;
        break;
    case 3:
        speed +=  0.3;
        break;
    }

    //Burn energy
    game->energyGauge->useEnergy(rocketState);

    setPos(x() + speed, y());

    //Shake the ship on turbo mode
    if(rocketState == 3){
        int shakeX = (rand() % turboShakeAmount * 2) - turboShakeAmount;
        int shakeY = (rand() % turboShakeAmount * 2) - turboShakeAmount;
        setPos(x() + shakeX, y() + shakeY);
    }

    //Once we are done moving, make sure we are still on the screen
    {
    if(x() < -40 && game->backWall){
        speed = 0;
        setPos(-40, y());
    }

    if(x() > game->gameWidth - shipWidth){
        speed = 0;
        setPos(game->gameWidth - shipWidth, y());
    }

    if(y() < 0){
        setPos(x(), 0);
    }

    if(y() > game->gameHeight - shipHeight){
        setPos(x(), game->gameHeight - shipHeight);
    }
    }

    //Update the rocket flame
    rocketFlame->setPos(x() + rocketFlameX, y() + rocketFlameY);
    rocketFlame->setState(rocketState);

    //laser
    if(leftMousePressed){
        game->laser->fire();
    }

    if(rightMousePressed){
        game->missleIndicator->fire();
    }

}
