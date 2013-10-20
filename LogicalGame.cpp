#include <cstdlib>
#include <ctime>

#include "LogicalGame.h"
#include "TetSquare.h"
#include "TetS.h"
#include "TetReverseS.h"
#include "TetL.h"
#include "TetReverseL.h"
#include "TetTri.h"
#include "TetLine.h"

LogicalGame::LogicalGame(NatrisBoard* pBoard)
{
    srand((unsigned)time(0));
    mPieces[SHAPE_LINE_4] = new TetLine(SHAPE_LINE_4, pBoard);
    mPieces[SHAPE_SQUARE_4] = new TetSquare(SHAPE_SQUARE_4, pBoard);
    mPieces[SHAPE_L_4] = new TetL(SHAPE_L_4, pBoard);
    mPieces[SHAPE_REVERSE_L_4] = new TetReverseL(SHAPE_REVERSE_L_4, pBoard);
    mPieces[SHAPE_S_4] = new TetS(SHAPE_S_4, pBoard);
    mPieces[SHAPE_REVERSE_S_4] = new TetReverseS(SHAPE_REVERSE_S_4, pBoard);
    mPieces[SHAPE_TRI_4] = new TetTri(SHAPE_TRI_4, pBoard);
}

Tetromino*
LogicalGame::GetCurrPiece()
{
    return mPieces[rand() % SHAPE_TET_MAX];
}


int
LogicalGame::ClearRows()
{
}
