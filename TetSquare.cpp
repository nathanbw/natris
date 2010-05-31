#include "TetrisDefs.h"
#include "TetSquare.h"
TetSquare::TetSquare(TetrominoShape shape, TetrisBoard* pBoard) :
    Tetromino(shape, pBoard)
{
    // Square, like this:
    // 0110
    // 0110
    Reset();
}

void
TetSquare::Reset()
{
    // x, y for each block, starting at top left corner
    // and going clockwise
    // Top Row
    vCoords[0][0] = -1; vCoords[0][1] = 4;
    vCoords[1][0] = -1; vCoords[1][1] = 5;
    
    // Bottom Row
    vCoords[2][0] = 0; vCoords[2][1] = 4;
    vCoords[3][0] = 0; vCoords[3][1] = 5;
    mPos = TP_UP;
}

void
TetSquare::PopToTop()
{
    vCoords[0][0] = 0;
    vCoords[1][0] = 0;
    vCoords[2][0] = 1;
    vCoords[3][0] = 1;
}

int
TetSquare::Rotate(RotateDirection direction)
{
    return 0;
}

