#include "TetrisDefs.h"
#include "TetSquare.h"
TetSquare::TetSquare(TetrominoShape shape, TetrisBoard* pBoard) :
    Tetromino(shape, pBoard)
{
    // Square, like this:
    // 0110
    // 0110
    // x, y for each block, starting at top left corner
    // and going clockwise
    // Top Row
    vCoords[0][0] = -1; vCoords[0][1] = 4;
    vCoords[1][0] = -1; vCoords[1][1] = 5;
    
    // Bottom Row
    vCoords[2][0] = 0; vCoords[2][1] = 4;
    vCoords[3][0] = 0; vCoords[3][1] = 5;
}

int
TetSquare::Rotate(RotateDirection direction)
{
    return 0;
}

