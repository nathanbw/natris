#include "Tetromino.h"

#include <iostream>
using std::cout;
using std::endl;

Tetromino::Tetromino(TetrominoShape shape, TetrisBoard* pBoard) :
    mShape(shape),
    mpBoard(pBoard),
    mPos(TP_UP)
{
    
}

int
Tetromino::Fall()
{
    bool safeToFall = true;
    for(int i = 0; i < 4; i++)
    {
        if ((vCoords[i][0] < 0) ||
            mpBoard->IsEmpty(vCoords[i][1],vCoords[i][0] + 1))
        {
        }
        else
        {
            safeToFall = false;
        }
    }
    if(safeToFall)
    {
        for(int i = 0; i < 4; i++)
        {
            vCoords[i][0]++;
        }
        return 0;
    }
    else
    {
        // Write to board?
        return -1;
    }
}

int
Tetromino::Rotate(RotateDirection direction)
{
    return 0;
}

int
Tetromino::MoveLeft()
{
    bool safeToMove = true;
    for(int i = 0; i < 4; i++)
    {
        if (mpBoard->IsEmpty(vCoords[i][1] - 1, vCoords[i][0]))
        {
        }
        else
        {
            safeToMove = false;
        }
    }
    if(safeToMove)
    {
        for(int i = 0; i < 4; i++)
        {
            vCoords[i][1]--;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

int
Tetromino::MoveRight()
{
    bool safeToMove = true;
    for(int i = 0; i < 4; i++)
    {
        if (mpBoard->IsEmpty(vCoords[i][1] + 1, vCoords[i][0]))
        {
        }
        else
        {
            safeToMove = false;
        }
    }
    if(safeToMove)
    {
        for(int i = 0; i < 4; i++)
        {
            vCoords[i][1]++;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

int
Tetromino::GetPieceCoord(int blockNo, bool isX)
{
    return vCoords[blockNo][(isX ? 1 : 0)];
}

int
Tetromino::WriteToBoard()
{
    for (int i = 0; i < 4; i++)
    {
        mpBoard->Write(vCoords[i][1], vCoords[i][0], mShape);
    }
}

int
Tetromino::Print()
{
    for (int i = 0; i < 4; i++)
    {
        cout << vCoords[i][0] << "," << vCoords[i][1] << endl;
    }
}
