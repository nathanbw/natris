#ifndef _Tet_S_h_
#define _Tet_S_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class TetS : public Tetromino
{
public:
    TetS(TetrominoShape shape, TetrisBoard* pBoard);
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_S_h_
