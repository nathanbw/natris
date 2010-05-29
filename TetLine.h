#ifndef _Tet_Line_h_
#define _Tet_Line_h_
#include "TetrisDefs.h"
#include "Tetromino.h"
class TetLine : public Tetromino
{
public:
    TetLine(TetrominoShape shape, TetrisBoard* pBoard);
    int Rotate(RotateDirection direction);
 private:
};
#endif // _Tet_Line_h_
