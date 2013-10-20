#ifndef _Tet_L_h_
#define _Tet_L_h_
#include "NatrisDefs.h"
#include "Tetromino.h"
class TetL : public Tetromino
{
public:
    TetL(TetrominoShape shape, NatrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_L_h_
