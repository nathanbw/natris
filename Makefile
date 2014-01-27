UNAME := $(shell uname)

all:
ifeq ($(UNAME), Darwin)
	g++ -o natris -framework GLUT -framework OpenGL main.cpp Tetromino.cpp TetSquare.cpp TetLine.cpp TetS.cpp TetReverseS.cpp TetL.cpp TetReverseL.cpp TetTri.cpp LogicalGame.cpp NatrisBoard.cpp
else
	g++ -o natris -lGL -lGLU -lglut main.cpp Tetromino.cpp TetSquare.cpp TetLine.cpp TetS.cpp TetReverseS.cpp TetL.cpp TetReverseL.cpp TetTri.cpp LogicalGame.cpp NatrisBoard.cpp
endif

clean:
	rm natris
