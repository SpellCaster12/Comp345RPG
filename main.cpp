#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QObject>
#include <QHBoxLayout>
#include "charactergenerator.h"
#include "mapgenerator.h"
#include "game.h"
#include <QSound>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game *mainGameWindow = new Game;
    CharacterGenerator *charGen = new CharacterGenerator(mainGameWindow);
    charGen->init();
    //QSound::play("mySounds/test.wav");
    MapGenerator *mapGen = new MapGenerator(mainGameWindow);
    mapGen->init();
    mainGameWindow->insertWidget(1, charGen);
    mainGameWindow->insertWidget(2, mapGen);

    //Move the window to the vertical center, 1/4 from the left side of the screen
    QRect screenRect;
    screenRect = QApplication::desktop()->availableGeometry(mainGameWindow);
    mainGameWindow->move(QPoint(screenRect.center().x(), screenRect.center().y()) - mainGameWindow->rect().center());

    mainGameWindow->show();


    return a.exec();
}
