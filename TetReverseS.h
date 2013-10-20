#ifndef _Tet_Reverse_S_h_
#define _Tet_Reverse_S_h_
#include "NatrisDefs.h"
#include "Tetromino.h"
class TetReverseS : public Tetromino
{
public:
    TetReverseS(TetrominoShape shape, NatrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Reverse_S_h_
