#ifndef _Natris_Board_h_
#define _Natris_Board_h_
#include "NatrisDefs.h"
class NatrisBoard
{
public:
    NatrisBoard();
    bool IsEmpty(int x, int y);
    TetrominoShape ShapeAt(int x, int y);
    int Write(int x, int y, int value);
    int Print();
    int ClearRows();
    int ClearRow(int row);
private:
    int mBoard[20][10];
};
#endif // _Natris_Board_h_
