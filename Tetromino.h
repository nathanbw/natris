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
    virtual void Reset();
    int MoveLeft();
    int MoveRight();
    int GetPieceCoord(int blockNo, bool isX);
    int FallToBottom();
    virtual void PopToTop();
    int WriteToBoard();
    int Print();
    TetrominoShape GetShape();
protected:
    TetrominoShape mShape;
    int vCoords[4][2];
    TetrisBoard* mpBoard;
    TetrominoPosition mPos;
};
#endif // _Tetromino_h_
