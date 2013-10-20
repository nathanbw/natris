#include <iostream>
#include <ctime>

#include "TetrisDefs.h"
#include "TetrisBoard.h"
#include "LogicalGame.h"
#include "Tetromino.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int timeToFall = 0;
void timeOut(int);
TetrisBoard* pBoard = new TetrisBoard();
LogicalGame* pGame = new LogicalGame(pBoard);
Tetromino* pCurrPiece = 0;

float colors[7][3] = {{1.0, 0.0, 0.0}, // Line
                      {0.0, 0.0, 1.0}, // Square
                      {0.0, 0.25, 0.25}, // L
                      {0.5, 0.0, 0.5}, // Reverse L
                      {0.0, 1.0, 0.75}, // S
                      {0.25, 0.0, 0.0}, // Reverse S
                      {0.0, 1.0, 0.0}};  // Tri

void init()
{
    pCurrPiece = pGame->GetCurrPiece();
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

void specialKeys(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT :
        pCurrPiece->MoveLeft();
        break;
    case GLUT_KEY_RIGHT :
        pCurrPiece->MoveRight();
        break;
    case GLUT_KEY_DOWN :
        pCurrPiece->Fall();
        //pCurrPiece->Rotate(DIR_COUNTER_CLOCK);
        break;
    case GLUT_KEY_UP :
        pCurrPiece->Rotate(DIR_CLOCK);
        break;
    default:
        break;
    }
}

void regularKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 32 :
        pCurrPiece->FallToBottom();
        pBoard->ClearRows();
        pCurrPiece->Reset();
        pCurrPiece = pGame->GetCurrPiece();
        pCurrPiece->PopToTop();
        break;
    default:
        break;
    }
}

void renderScene(void) {
    TetrominoShape currShape;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
                currShape = pBoard->ShapeAt(x, y);
                glPushMatrix();
                glTranslatef((float)x + 0.5, 19.5 - (float)y, 0.0);
                glTranslatef(-0.5, -0.5, 0.0);
                //glColor3f(0.0, 1.0, 0.75);
                glColor3f(colors[currShape][0],
                          colors[currShape][1],
                          colors[currShape][2]);
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
         currShape = pCurrPiece->GetShape();
         glPushMatrix();
         glTranslatef((float)pCurrPiece->GetPieceCoord(i, true) + 0.5,
                      19.5 - (float)pCurrPiece->GetPieceCoord(i, false), 0.0);
         glTranslatef(-0.5, -0.5, 0.0);
         //glColor3f(0.0, 1.0, 0.75);
         glColor3f(colors[currShape][0],
                   colors[currShape][1],
                   colors[currShape][2]);
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

    if(((timeToFall % 30) == 0))
    {
        if(-1 == pCurrPiece->Fall())
        {
            pCurrPiece->WriteToBoard();
            pBoard->ClearRows();
            pCurrPiece->Reset();
            pCurrPiece = pGame->GetCurrPiece();
            pCurrPiece->PopToTop();
        }
    }
    timeToFall++;

    // Calls glFlush() for us.
    glutSwapBuffers();
}

void timeOut(int param)
{
    renderScene();
    glutTimerFunc((1000/30), timeOut, 0); // Let's do 30 fps
}

int main(int argc, char** argv)
{
 	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
 	glutInitWindowSize(320,640);
 	glutInitWindowPosition(100,100);
 	glutCreateWindow("uTetris-Dev");
    init();
 	glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    //glutIdleFunc(renderScene);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(regularKeys);
    glutTimerFunc((1000/30), timeOut, 0); // Let's do 30 fps
    glutMainLoop();
    return 0; // Never reached.
}
