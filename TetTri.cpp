#include "TetrisDefs.h"
#include "TetTri.h"
TetTri::TetTri(TetrominoShape shape, TetrisBoard* pBoard) :
    Tetromino(shape, pBoard)
{
    // Tri, like this:
    // 0010
    // 0111
    // 0000
    Reset();
}

void
TetTri::Reset()
{
    // x, y for each block, starting at top left corner
    // and going clockwise
    vCoords[0][0] = -2; vCoords[0][1] = 4;
    vCoords[1][0] = -1; vCoords[1][1] = 3;
    vCoords[2][0] = -1; vCoords[2][1] = 4;
    vCoords[3][0] = -1; vCoords[3][1] = 5;
    mPos = TP_UP;
}

void
TetTri::PopToTop()
{
    vCoords[0][0] = 0;
    vCoords[1][0] = 1;
    vCoords[2][0] = 1;
    vCoords[3][0] = 1;
}

int
TetTri::Rotate(RotateDirection direction)
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
            if(!(mpBoard->IsEmpty(vCoords[0][1] + 1, vCoords[0][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] + 1, vCoords[1][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] - 1, vCoords[3][0] + 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]++; vCoords[0][1]++;
                vCoords[1][0]--; vCoords[1][1]++;
                vCoords[3][0]++; vCoords[3][1]--;
                mPos = TP_RIGHT;
            }
            return 0;
        case DIR_COUNTER_CLOCK :
            if(!(mpBoard->IsEmpty(vCoords[0][1] - 1, vCoords[0][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] + 1, vCoords[1][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] - 1, vCoords[3][0] - 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]++; vCoords[0][1]--;
                vCoords[1][0]++; vCoords[1][1]++;
                vCoords[3][0]--; vCoords[3][1]--;
                mPos = TP_LEFT;
            }
            return 0;
        default:
            break;
        }
        break;
    case TP_DOWN :
        switch(direction)
        {
        case DIR_CLOCK :
            if(!(mpBoard->IsEmpty(vCoords[0][1] - 1, vCoords[0][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] - 1, vCoords[1][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] + 1, vCoords[3][0] - 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]--; vCoords[0][1]--;
                vCoords[1][0]++; vCoords[1][1]--;
                vCoords[3][0]--; vCoords[3][1]++;
                mPos=TP_LEFT;
            }
            return 0;
        case DIR_COUNTER_CLOCK :
            if(!(mpBoard->IsEmpty(vCoords[0][1] + 1, vCoords[0][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] - 1, vCoords[1][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] + 1, vCoords[3][0] + 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]--; vCoords[0][1]++;
                vCoords[1][0]--; vCoords[1][1]--;
                vCoords[3][0]++; vCoords[3][1]++;
                mPos = TP_RIGHT;
            }
            return 0;
        default:
            break;
        }
        break;
    case TP_RIGHT :
        switch(direction)
        {
        case DIR_CLOCK :
            if(!(mpBoard->IsEmpty(vCoords[0][1] - 1, vCoords[0][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] + 1, vCoords[1][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] - 1, vCoords[3][0] - 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]++; vCoords[0][1]--;
                vCoords[1][0]++; vCoords[1][1]++;
                vCoords[3][0]--; vCoords[3][1]--;
                mPos = TP_DOWN;
            }
            return 0;
        case DIR_COUNTER_CLOCK :
            if(!(mpBoard->IsEmpty(vCoords[0][1] - 1, vCoords[0][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] - 1, vCoords[1][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] + 1, vCoords[3][0] - 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]--; vCoords[0][1]--;
                vCoords[1][0]++; vCoords[1][1]--;
                vCoords[3][0]--; vCoords[3][1]++;
                mPos = TP_UP;
            }
            return 0;
        default:
            break;
        }
        break;
    case TP_LEFT :
        switch(direction)
        {
        case DIR_CLOCK :
            if(!(mpBoard->IsEmpty(vCoords[0][1] + 1, vCoords[0][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] - 1, vCoords[1][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] + 1, vCoords[3][0] + 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]--; vCoords[0][1]++;
                vCoords[1][0]--; vCoords[1][1]--;
                vCoords[3][0]++; vCoords[3][1]++;
                mPos = TP_UP;
            }
            return 0;
        case DIR_COUNTER_CLOCK :
            if(!(mpBoard->IsEmpty(vCoords[0][1] + 1, vCoords[0][0] + 1)) ||
               !(mpBoard->IsEmpty(vCoords[1][1] + 1, vCoords[1][0] - 1)) ||
               !(mpBoard->IsEmpty(vCoords[3][1] - 1, vCoords[3][0] + 1)))
                safeToMove = false;
            if(safeToMove)
            {
                vCoords[0][0]++; vCoords[0][1]++;
                vCoords[1][0]--; vCoords[1][1]++;
                vCoords[3][0]++; vCoords[3][1]--;
                mPos = TP_DOWN;
            }
            return 0;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return -1;
}

