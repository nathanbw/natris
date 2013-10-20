#include "NatrisDefs.h"
#include "TetS.h"
TetS::TetS(TetrominoShape shape, NatrisBoard* pBoard) :
    Tetromino(shape, pBoard)
{
    // S, like this:
    // 0100
    // 0110
    // 0010
    Reset();
}

void
TetS::Reset()
{
    // x, y for each block, starting at top left corner
    // and going clockwise
    vCoords[0][0] = -3; vCoords[0][1] = 4;
    vCoords[1][0] = -2; vCoords[1][1] = 4;
    vCoords[2][0] = -2; vCoords[2][1] = 5;
    vCoords[3][0] = -1; vCoords[3][1] = 5;
    mPos = TP_UP;
}

void
TetS::PopToTop()
{
    vCoords[0][0] = 0;
    vCoords[1][0] = 1;
    vCoords[2][0] = 1;
    vCoords[3][0] = 2;
}

int
TetS::Rotate(RotateDirection direction)
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
        if(!(mpBoard->IsEmpty(vCoords[0][1] + 1, vCoords[0][0])) ||
           !(mpBoard->IsEmpty(vCoords[3][1] + 1, vCoords[3][0] - 2)))
            safeToMove = false;

        if(safeToMove)
        {
            vCoords[0][1] = vCoords[0][1] + 1;
            vCoords[3][0] = vCoords[3][0] - 2; vCoords[3][1]++;
            mPos = TP_RIGHT; // Or LEFT
            return 0;
        }
        break;
    case TP_RIGHT :
    case TP_LEFT :
        // vCoords[0][0] has tallest point (lowest y value)
        newY = vCoords[0][0];
        newX = vCoords[0][1];
        // Is it safe to move?
        if(!(mpBoard->IsEmpty(vCoords[0][1] - 1, vCoords[0][0])) ||
           !(mpBoard->IsEmpty(vCoords[3][1] - 1, vCoords[3][0] + 2)))
            safeToMove = false;

        if(safeToMove)
        {
            vCoords[0][1] = vCoords[0][1] - 1;
            vCoords[3][0] = vCoords[3][0] + 2; vCoords[3][1]--;
            mPos = TP_UP; // Or DOWN.
            return 0;
        }
        break;
    default:
        break;
    }
    return -1;
}

