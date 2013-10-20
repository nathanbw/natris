all:
	g++ -o natris -lGL -lGLU -lglut main.cpp Tetromino.cpp TetSquare.cpp TetLine.cpp TetS.cpp TetReverseS.cpp TetL.cpp TetReverseL.cpp TetTri.cpp LogicalGame.cpp NatrisBoard.cpp
clean:
	rm natris
