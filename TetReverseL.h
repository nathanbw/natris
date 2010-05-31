#ifndef _Tet_Reverse_L_h_
#define _Tet_Reverse_L_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class TetReverseL : public Tetromino
{
public:
    TetReverseL(TetrominoShape shape, TetrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Reverse_L_h_
