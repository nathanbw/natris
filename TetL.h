#ifndef _Tet_L_h_
#define _Tet_L_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class TetL : public Tetromino
{
public:
    TetL(TetrominoShape shape, TetrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_L_h_
