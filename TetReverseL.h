#ifndef _Tet_Reverse_L_h_
#define _Tet_Reverse_L_h_
#include "NatrisDefs.h"
#include "Tetromino.h"
class TetReverseL : public Tetromino
{
public:
    TetReverseL(TetrominoShape shape, NatrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Reverse_L_h_
