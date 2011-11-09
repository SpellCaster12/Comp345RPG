#ifndef TILESET_H
#define TILESET_H
#include <QString>

class TileSet
{
public:
    TileSet();
    TileSet(int aRowPosition, int aColumnPosition,
            bool aIsTerrain, QString aGamePiece);
    QString getGamePiece();
    int rowPosition();
    int columnPosition();


    void setRowPosition(int aRowPosition);
    void setColumnPosition(int aColumnPosition);
    void setGamePiece(QString aGamePiece);

private:
    int mRowPosition;
    int mColumnPosition;
    bool isTerrain;
    QString mGamePiece;
};

#endif // TILESET_H
