#include "dungeon.h"
#include "ui_dungeon.h"
#include <QFileDialog>
#include <QTextStream>
#include "game.h"

Dungeon::Dungeon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dungeon)
{
    ui->setupUi(this);

}

Dungeon::~Dungeon()
{
    delete ui;
}

void Dungeon::init()
{
    layout = new QGridLayout();
    layout->setSpacing(0);
    layout->setVerticalSpacing(0);

    assignMovementOperations();
    mapObject = new Map();
    mapObject->loadMap();
    mapObject->addObserver(this);
    initializeMap();
    this->show();
}


//Method it initialize the map
void Dungeon::initializeMap()
{
    if(layout->count() == 0)
    {
        for (int row = 0; row < mapObject->mapHeight(); row++)
        {
            mapGrid.append(QList<QPushButton*>() );
            for (int column = 0; column < mapObject->mapWidth(); column++)
            {
                mapGrid[row].append(new QPushButton(mapObject->mapGridTileSet(row, column).getGamePiece()));
                mapGrid[row][column]->setObjectName(QString::number(row)+"_"+QString::number(column));
                mapGrid[row][column]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                mapGrid[row][column]->setStyleSheet(mapStyleSheet(mapObject->mapGridTileSet(row, column)));

                layout->addWidget(mapGrid[row][column], row, column);
            }
        }

        ui->mapDungeonFrame->setLayout(layout);
    }
    //Implement Matt Tam's "createMap" stuff
}

//Method to assignment operations to movement buttons
void Dungeon::assignMovementOperations()
{
    connect(ui->movementButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(moveCharacter(QAbstractButton*)));
}

//Slot to move the character
void Dungeon::moveCharacter(QAbstractButton* button)
{

    mapObject->moveCharacter(button->text());
}

void Dungeon::update(Observable *aObs)
{

//    QIcon characterImage(":/images/fighter.jpg");
//    QIcon wallImage(":/images/wall.jpg");
//    QIcon enemyImage(":/images/enemy.jpg");
//    QIcon exitImage(":/images/exit.jpg");
//    QIcon chestImage(":/images/chest.jpg");
//    QIcon terrainImage(":/images/terrain.jpg");

    Map *aMap = (Map*)aObs;
    TileSet tile = aMap->lastModifiedTileSet();
    int row = tile.rowPosition();
    int column = tile.columnPosition();



    if(tile.getGamePiece().compare("Character") == 0)
    {
        mapGrid[row][column]->setText("Character");
        mapGrid[row][column]->setStyleSheet("background-color: blue;");
    }
    else
    {
        mapGrid[row][column]->setText("");
        mapGrid[row][column]->setStyleSheet("background-color: white;");
    }

    if(mapObject->isDungeonCompleted())
    {/*
        if (mapObject != 0)
        {
            delete mapObject;
            mapObject = 0;
        }*/
        Game *game = (Game*)this->parentWidget();
        game->setCurrentIndex(0);
    }
}

QString Dungeon::mapStyleSheet(TileSet aTile)
{
    QString styleSheet = "";
    if(aTile.getGamePiece() == "Wall")
    {
        styleSheet = QString("background-color: grey;");
    }
    else if(aTile.getGamePiece() == "Chest")
    {
        styleSheet = QString("background-color: yellow;");
    }
    else if(aTile.getGamePiece() == "Monster")
    {
        styleSheet = QString("background-color: red;");
    }
    else if(aTile.getGamePiece() == "Exit")
    {
        styleSheet = QString("background-color: black;");
    }
    else if(aTile.getGamePiece() == "Character")
    {
        styleSheet = QString("background-color: blue;");
    }
    else if(aTile.getGamePiece() == "")
    {
        styleSheet = QString("background-color: white;");
    }
    return styleSheet;
}
