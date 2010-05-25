#ifndef _Tetris_Board_h_
#define _Tetris_Board_h_
#include "TetrisDefs.h"
class TetrisBoard
{
public:
    TetrisBoard();
    bool IsEmpty(int x, int y);
    TetrominoShape ShapeAt(int x, int y);
    int Write(int x, int y, int value);
    int Print();
private:
    int mBoard[20][10];
};
#endif // _Tetris_Board_h_
