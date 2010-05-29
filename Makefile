all: 
	g++ -o uTetris -lGL -lGLU -lglut main.cpp Tetromino.cpp TetSquare.cpp TetLine.cpp TetS.cpp TetReverseS.cpp TetL.cpp TetReverseL.cpp TetTri.cpp TetrisBoard.cpp
clean:
	rm uTetris
