#ifndef _Tetromino_h_
#define _Tetromino_h_
#include "TetrisDefs.h"
#include "TetrisBoard.h"

class Tetromino
{
public:
  Tetromino(TetrominoShape shape, TetrisBoard* pBoard);
    int Fall();
    virtual int Rotate(RotateDirection direction);
    int MoveLeft();
    int MoveRight();
    int GetPieceCoord(int blockNo, bool isX);
    int FallToBottom();
    int WriteToBoard();
    int Print();
protected:
    TetrominoShape mShape;
    int vCoords[4][2];
    TetrisBoard* mpBoard;
    TetrominoPosition mPos;
};
#endif // _Tetromino_h_
