#ifndef _Logical_Game_h_
#define _Logical_Game_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class LogicalGame
{
public:
    LogicalGame(TetrisBoard* pBoard);
    Tetromino* GetCurrPiece();
    int ClearRows();
private:
    Tetromino* mPieces[SHAPE_TET_MAX];
};
#endif // _Logical_Game_h_
