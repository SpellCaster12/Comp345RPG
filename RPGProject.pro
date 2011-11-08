#-------------------------------------------------
#
# Project created by QtCreator 2011-10-13T20:08:16
#
#-------------------------------------------------

QT       += core gui

TARGET = RPGAssignment2
TEMPLATE = app

INCLUDEPATH += Character \
               Equipment \
               CharacterGenerator \
               Map \
               MapGenerator

include(Character/Character.pri)
include(CharacterGenerator/CharacterGenerator.pri)
include(Equipment/Equipment.pri)
include(Map/Map.pri)
include(MapGenerator/MapGenerator.pri)

SOURCES += main.cpp \
    diceroller.cpp \
    game.cpp \
    quitdialog.cpp

HEADERS  += \
    diceroller.h \
    observable.h \
    observer.h \
    game.h \
    quitdialog.h

FORMS    += game.ui \
    quitdialog.ui

RESOURCES += \
    resources.qrc






















































