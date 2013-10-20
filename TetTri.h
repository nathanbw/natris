#ifndef _Tet_Tri_h_
#define _Tet_Tri_h_
#include "NatrisDefs.h"
#include "Tetromino.h"
class TetTri : public Tetromino
{
public:
    TetTri(TetrominoShape shape, NatrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Tri_h_
