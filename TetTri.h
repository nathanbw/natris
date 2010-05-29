#ifndef _Tet_Tri_h_
#define _Tet_Tri_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class TetTri : public Tetromino
{
public:
    TetTri(TetrominoShape shape, TetrisBoard* pBoard);
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Tri_h_
