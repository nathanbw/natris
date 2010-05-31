#ifndef _Tet_Reverse_S_h_
#define _Tet_Reverse_S_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class TetReverseS : public Tetromino
{
public:
    TetReverseS(TetrominoShape shape, TetrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Reverse_S_h_
