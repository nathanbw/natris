#include "TetrisDefs.h"
#include "TetL.h"
TetL::TetL(TetrominoShape shape, TetrisBoard* pBoard) :
    Tetromino(shape, pBoard)
{
    // S, like this:
    // 0010
    // 0010
    // 0110
    // x, y for each block, starting at top left corner
    // and going clockwise
    vCoords[0][0] = -2; vCoords[0][1] = 5;
    vCoords[1][0] = -1; vCoords[1][1] = 5;
    vCoords[2][0] = 0; vCoords[2][1] = 5;
    vCoords[3][0] = 0; vCoords[3][1] = 4;
}

int
TetL::Rotate(RotateDirection direction)
{
    // Any Direction of rotation is the same for this piece
    int newY = 0;
    int newX = 0;
    bool safeToMove = true;

    switch(mPos)
    {
    case TP_UP :
        switch(direction)
        {
        case DIR_CLOCK :
            vCoords[0][0]++; vCoords[0][1]++;
            vCoords[2][0]--; vCoords[2][1]--;
            vCoords[3][0] = vCoords[3][0] - 2;
            mPos = TP_RIGHT;
            break;
        case DIR_COUNTER_CLOCK :
            vCoords[0][0]++; vCoords[0][1]--;
            vCoords[2][0]--; vCoords[2][1]++;
            vCoords[3][1] = vCoords[3][1] + 2;
            mPos = TP_LEFT;
            break;
        default:
            break;
        }
        break;
    case TP_DOWN : // UP and DOWN are the same for this piece
        switch(direction)
        {
        case DIR_CLOCK :
            vCoords[0][0]--; vCoords[0][1]--;
            vCoords[2][0]++; vCoords[2][1]++;
            vCoords[3][0] = vCoords[3][0] + 2;
            mPos=TP_LEFT;
            break;
        case DIR_COUNTER_CLOCK :
            vCoords[0][0]--; vCoords[0][1]++;
            vCoords[2][0]++; vCoords[2][1]--;
            vCoords[3][1] = vCoords[3][1] - 2;
            mPos = TP_RIGHT;
            break;
        default:
            break;
        }
        break;
    case TP_RIGHT :
        switch(direction)
        {
        case DIR_CLOCK :
            vCoords[0][0]++; vCoords[0][1]--;
            vCoords[2][0]--; vCoords[2][1]++;
            vCoords[3][1] = vCoords[3][1] + 2;
            mPos = TP_DOWN;
            break;
        case DIR_COUNTER_CLOCK :
            vCoords[0][0]--; vCoords[0][1]--;
            vCoords[2][0]++; vCoords[2][1]++;
            vCoords[3][0] = vCoords[3][0] + 2;
            mPos = TP_UP;
            break;
        default:
            break;
        }
        break;
    case TP_LEFT :
        switch(direction)
        {
        case DIR_CLOCK :
            vCoords[0][0]--; vCoords[0][1]++;
            vCoords[2][0]++; vCoords[2][1]--;
            vCoords[3][1] = vCoords[3][1] - 2;
            mPos = TP_UP;
            break;
        case DIR_COUNTER_CLOCK :
            vCoords[0][0]++; vCoords[0][1]++;
            vCoords[2][0]--; vCoords[2][1]--;
            vCoords[3][0] = vCoords[3][0] - 2;
            mPos = TP_DOWN;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return -1;
}

