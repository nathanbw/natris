#include <iostream>
#include <cstdlib>
#include <ctime>

#include "TetrisDefs.h"
#include "TetrisBoard.h"
#include "Tetromino.h"
#include "TetSquare.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void timeOut(int);
TetrisBoard* pBoard = new TetrisBoard();
TetSquare* pTetSquare = new TetSquare(SHAPE_S_4, pBoard);


void init()
{
    glClearColor(0.25, 0.25, 0.25, 0.0);
    glShadeModel(GL_FLAT);
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D(0.0, 10.0, 0.0, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.75);
// Draw the board first:
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 10; x++)
        {
            if(pBoard->IsEmpty(x, y))
            {
                // Either write background color,
                // Or do nothing.
                // std::cout << "0 ";
            }
            else // There is a shape to display
            {
                // std::cout << "5 ";
                glPushMatrix();
                glTranslatef((float)x, 19.5 - (float)y, 0.0);
                glTranslatef(-0.5, -0.5, 0.0);
                glColor3f(0.0, 1.0, 0.75);
                glBegin(GL_QUADS);
                glVertex3f( 0.0f,  0.0f,  0.0f);
                glVertex3f( 1.0f,  0.0f,  0.0f);
                glVertex3f( 1.0f,  1.0f,  0.0f);
                glVertex3f( 0.0f,  1.0f,  0.0f);
                glEnd();
                glLineWidth(3.0);
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINE_LOOP);
                glVertex3f( 0.0f,  0.0f,  0.1f);
                glVertex3f( 1.0f,  0.0f,  0.1f);
                glVertex3f( 1.0f,  1.0f,  0.1f);
                glVertex3f( 0.0f,  1.0f,  0.1f);
                glEnd();
                glPopMatrix();
            }
        }
        // std::cout << std::endl;
    }
// Then draw the current piece:
    for (int i = 0; i < 4; i++)
     {
         glPushMatrix();
         glTranslatef((float)pTetSquare->GetPieceCoord(i, true) + 0.5,
                      19.5 - (float)pTetSquare->GetPieceCoord(i, false), 0.0);
         glTranslatef(-0.5, -0.5, 0.0);
         glColor3f(0.0, 1.0, 0.75);
         glBegin(GL_QUADS);
         glVertex3f( 0.0f,  0.0f,  0.0f);
         glVertex3f( 1.0f,  0.0f,  0.0f);
         glVertex3f( 1.0f,  1.0f,  0.0f);
         glVertex3f( 0.0f,  1.0f,  0.0f);
         glEnd();
         glLineWidth(3.0);
         glColor3f(0.0, 0.0, 0.0);
         glBegin(GL_LINE_LOOP);
         glVertex3f( 0.0f,  0.0f,  0.1f);
         glVertex3f( 1.0f,  0.0f,  0.1f);
         glVertex3f( 1.0f,  1.0f,  0.1f);
         glVertex3f( 0.0f,  1.0f,  0.1f);
         glEnd();
         glPopMatrix();
     }

    if(rand() % 2)
        pTetSquare->MoveLeft(); 
    else
        pTetSquare->MoveRight();

    pTetSquare->Fall();

    // Calls glFlush() for us.
    glutSwapBuffers();
}

void timeOut(int param)
{
    renderScene();
    glutTimerFunc((1000/*/30*/), timeOut, 0); // Let's do 30 fps
}

int main(int argc, char** argv)
{
    srand((unsigned)time(0));

 	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
 	glutInitWindowSize(320,640);
 	glutInitWindowPosition(100,100);
 	glutCreateWindow("uTetris-Dev");
    init();
 	glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    //glutIdleFunc(renderScene);
    glutTimerFunc((1000/30), timeOut, 0); // Let's do 30 fps
    glutMainLoop();
    return 0; // Never reached.
}
