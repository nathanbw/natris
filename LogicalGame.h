#ifndef _Logical_Game_h_
#define _Logical_Game_h_
#include "NatrisDefs.h"
#include "Tetromino.h"
class LogicalGame
{
public:
    LogicalGame(NatrisBoard* pBoard);
    Tetromino* GetCurrPiece();
    int ClearRows();
private:
    Tetromino* mPieces[SHAPE_TET_MAX];
};
#endif // _Logical_Game_h_
