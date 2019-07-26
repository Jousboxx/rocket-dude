#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T22:43:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rocketDude2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    game.cpp \
    starstreak.cpp \
    player.cpp \
    rocketFlame.cpp \
    powerup.cpp \
    energygauge.cpp \
    energyboost.cpp \
    asteroid.cpp \
    weaponindicator.cpp \
    weapon.cpp \
    laser.cpp \
    spark.cpp \
    boostparticle.cpp \
    missle.cpp \
    missleindicator.cpp \
    ufo.cpp \
    shard.cpp \
    ufobullet.cpp

HEADERS += \
    game.h \
    starstreak.h \
    player.h \
    rocketFlame.h \
    powerup.h \
    energygauge.h \
    energyboost.h \
    asteroid.h \
    weaponindicator.h \
    weapon.h \
    laser.h \
    spark.h \
    boostparticle.h \
    missle.h \
    missleindicator.h \
    ufo.h \
    shard.h \
    ufobullet.h

FORMS +=

RESOURCES += \
    resources.qrc
