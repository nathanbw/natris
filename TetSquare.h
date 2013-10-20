#ifndef _Tet_Square_h_
#define _Tet_Square_h_
#include "NatrisDefs.h"
#include "Tetromino.h"
class TetSquare : public Tetromino
{
public:
    TetSquare(TetrominoShape shape, NatrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Square_h_
