#include "arena.h"

void Arena::buildMapGrid()
{
    mMap = new Map(9, 9);
    mMap->createMapGrid();
}

void Arena::buildWall()
{
    for (int row = 0; row < mMap->mapHeight(); row++)
    {
        for (int column = 0; column < mMap->mapWidth(); column++)
        {
            TileSet wallTile = mMap->mapGridTileSet(row, column);
            wallTile.setIsTerrain(false);
            wallTile.setGamePiece("Wall");
            if (row == 0 && column != 4 || row == 8 && column !=4)
            {
                mMap->setTileSet(wallTile, row, column);
            }
            else if (column == 0 || column == 8 )
            {
                mMap->setTileSet(wallTile, row, column);
            }
        }
    }
}
void Arena::buildChest()
{
    TileSet chestTile = mMap->mapGridTileSet(4, 4);
    chestTile.setGamePiece("Chest");
    mMap->setTileSet(chestTile, 4, 4);
}



void Arena::buildMonster()
{
    TileSet monsterTile = mMap->mapGridTileSet(7, 4);
    monsterTile.setGamePiece("Monster");
    mMap->setTileSet(monsterTile, 7, 4);
}

void Arena::buildExit()
{
    TileSet exitTile = mMap->mapGridTileSet(8, 4);
    exitTile.setGamePiece("Exit");
    mMap->setTileSet(exitTile, 8, 4);
    mMap->setExitTileSet(exitTile);
    mMap->setIsExitPlaced(true);
}

void Arena::buildCharacter()
{
    TileSet characterTile = mMap->mapGridTileSet(0, 4);
    characterTile.setGamePiece("You");
    mMap->setTileSet(characterTile, 0, 4);
    mMap->setCharacterTileSet(characterTile);
    mMap->setIsCharacterPlaced(true);

}

void Arena::buildLevel()
{
    mMap->setLevel(5);
}
