#ifndef _Tet_Line_h_
#define _Tet_Line_h_
#include "NatrisDefs.h"
#include "Tetromino.h"
class TetLine : public Tetromino
{
public:
    TetLine(TetrominoShape shape, NatrisBoard* pBoard);
    void Reset();
    void PopToTop();
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Line_h_
