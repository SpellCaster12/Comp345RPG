#ifndef MAP_H
#define MAP_H

#include <QList>
#include "tileset.h"
#include "observable.h"

//Forward Declaration
class TileSet;
class Observable;

class Map : public Observable
{
public:
    Map();
    ~Map();
    Map(int aWidth, int aHeight);

    void displayMap();
    void saveMap();
    void saveMap2();
    void loadMap();
    void loadMap2();
    void createMapGrid();
    void clearMapGrid();

    //  Accessors
    int mapWidth();
    int mapHeight();
    QList<QList<TileSet> > mapGrid();
    TileSet lastModifiedTileSet(); // last modified tile will be returned
    TileSet mapGridTileSet(int aRowPosition, int aColumnPosition);
    TileSet characterTileSet();
    TileSet exitTileSet();
    bool isCharacterPlaced();
    bool isExitPlaced();
    bool isDungeonCompleted();

    //  Mutators
    void setMapWidth(int aWidth);
    void setMapHeight(int aHeight);
    void setLastModifiedTile(TileSet aTileSet);
    void setTileSet(TileSet aTileSet, int aRowPosition, int aColumnPosition);
    void setCharacterTileSet(TileSet aTileSet);
    void setExitTileSet(TileSet aTileSet);
    void setIsCharacterPlaced(bool aIsCharacterPlaced);
    void setIsExitPlaced(bool aIsExitPlaced);
    void setIsDungeonCompleted(bool cleared);

    //Observer methods
    void addObserver(Observer *aObserver);
    void removeObserver(Observer *aObserver);
    void notifyObservers();

    bool moveCharacter(QString aMovement);
    void moveTile(TileSet tile, int row, int column);


private:
    QList<QList<TileSet> > mMapGrid;
    QList<Observer*> observerList;
    int width;
    int height;
    TileSet mLastModifiedTile;
    TileSet mCharacterTileSet;
    TileSet mExitTileSet;
    bool mIsCharacterPlaced;
    bool mIsExitPlaced;
    bool mIsDungeonCompleted;


//    TODO
//    bool isCharacterPlaced;
//    bool isExitPlaced;

};

#endif // MAP_H
