#ifndef _Tet_Square_h_
#define _Tet_Square_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class TetSquare : public Tetromino
{
public:
    TetSquare(TetrominoShape shape, TetrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Square_h_
