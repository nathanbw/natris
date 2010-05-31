#include "TetrisDefs.h"
#include "TetrisBoard.h"

#include <iostream>
using std::cout;
using std::endl;

TetrisBoard::TetrisBoard()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mBoard[i][j] = -1;
        }
    }
}

bool
TetrisBoard::IsEmpty(int x, int y)
{
    if((x >= 0) && (x < 10) && 
       (y >= 0) && (y < 20) &&
       (mBoard[y][x] == -1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

TetrominoShape
TetrisBoard::ShapeAt(int x, int y)
{
    if((x >= 0) && (x < 10) &&
       (y >= 0) && (y < 20))
    {
        return (TetrominoShape)mBoard[y][x];
    }
}

int
TetrisBoard::Write(int x, int y, int value)
{
    if((x >= 0) && (x < 10) &&
       (y >= 0) && (y < 20))
    {
        mBoard[y][x] = value;
        return 0;
    }
    else
    {
        return -1;
    }
}

int
TetrisBoard::Print()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << mBoard[i][j] + 1 << " ";
        }
        cout << endl;
    }
}

int
TetrisBoard::ClearRows()
{
    bool clearRow = true;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(mBoard[i][j] == -1)
                clearRow = false;
        }
        if(clearRow)
        {
            ClearRow(i);
        }
        clearRow = true;
    }
}

int
TetrisBoard::ClearRow(int row)
{
    for (int j = 0; j < 10; j++)
    {
        mBoard[row][j] = -1;
    }
    for(int i = row; i > 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            mBoard[i][j] = mBoard[i - 1][j];
        }
    }
}
