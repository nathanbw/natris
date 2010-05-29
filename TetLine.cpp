#include "TetrisDefs.h"
#include "TetLine.h"

TetLine::TetLine(TetrominoShape shape, TetrisBoard* pBoard) :
    Tetromino(shape, pBoard)
{
    // Square, like this:
    // 0110
    // 0110
    // x, y for each block, starting at top left corner
    // and going clockwise
    // Top Row
    vCoords[0][0] = -3; vCoords[0][1] = 5;
    vCoords[1][0] = -2; vCoords[1][1] = 5;
    
    // Bottom Row
    vCoords[2][0] = -1; vCoords[2][1] = 5;
    vCoords[3][0] = 0; vCoords[3][1] = 5;
}

int
TetLine::Rotate(RotateDirection direction)
{
    // Any Direction of rotation is the same for this piece
    int newY = 0;
    int newX = 0;
    bool safeToMove = true;

    switch(mPos)
    {
    case TP_UP :
    case TP_DOWN : // UP and DOWN are the same for this piece
        // vCoords[0][0] has tallest point (lowest y value)
        newY = vCoords[0][0];
        newX = vCoords[0][1]; // Honestly doesn't matter which of the X values
                              // we pick; they're all the same
        // Is it safe to move?
        for (int i = 0; i < 4; i++)
        {
            if(!(mpBoard->IsEmpty(newX + i, newY)))
            {
                safeToMove = false;
            }
        }
        if(safeToMove)
        {
            // [0][0] stays the same
            // We could cleverly optimize with a loop here.
            vCoords[1][0] = newY; vCoords[1][1] = ++newX;
            vCoords[2][0] = newY; vCoords[2][1] = ++newX;
            vCoords[3][0] = newY; vCoords[3][1] = ++newX;
            mPos = TP_RIGHT; // Or LEFT.
            return 0;
        }
        break;
    case TP_RIGHT :
    case TP_LEFT :
        // vCoords[0][0] has tallest point (lowest y value)
        newY = vCoords[0][0];
        newX = vCoords[0][1];
        // Is it safe to move?
        for (int i = 0; i < 4; i++)
        {
            if(!(mpBoard->IsEmpty(newX, newY + i)))
            {
                safeToMove = false;
            }
        }
        if(safeToMove)
        {
            // [0][0] stays the same
            // We could cleverly optimize with a loop here.
            vCoords[1][0] = ++newY; vCoords[1][1] = newX;
            vCoords[2][0] = ++newY; vCoords[2][1] = newX;
            vCoords[3][0] = ++newY; vCoords[3][1] = newX;
            mPos = TP_UP; // Or DOWN.
            return 0;
        }
        break;
    default:
        break;
    }
    return -1;
}
