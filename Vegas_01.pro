#-------------------------------------------------
#
# Project created by QtCreator 2016-09-26T18:18:35
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++14 -pedantic-errors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Vegas_01
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    model/player.cpp \
    model/dice.cpp \
    model/game.cpp \
    o_sdo/sujetdobservation.cpp \
    model/casino.cpp \
    observateurcasino.cpp \
    observateurdice.cpp \
    dialogconfiguration.cpp

HEADERS  += mainwindow.h \
    model/player.h \
    model/game.h \
    model/color.h \
    model/dice.h \
    model/casino.h \
    o_sdo/observateur.h \
    o_sdo/sujetdobservation.h \
    model/randomgenerator.hpp \
    observateurcasino.h \
    observateurdice.h \
    dialogconfiguration.h

FORMS    += mainwindow.ui \
    dialogconfiguration.ui

RESOURCES += \
    dices_img.qrc
