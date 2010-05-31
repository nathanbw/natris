#ifndef _TetrisDefs_h_
#define _TetrisDefs_h_
enum TetrominoShape
{
    SHAPE_LINE_4,
    SHAPE_SQUARE_4,
    SHAPE_L_4,
    SHAPE_REVERSE_L_4,
    SHAPE_S_4,
    SHAPE_REVERSE_S_4,
    SHAPE_TRI_4,
    SHAPE_TET_MAX
};

enum RotateDirection
{
    DIR_CLOCK,
    DIR_COUNTER_CLOCK
};

enum TetrominoPosition
  {
    TP_UP,
    TP_RIGHT,
    TP_DOWN,
    TP_LEFT
  };
#endif //_TetrisDefs_h_
