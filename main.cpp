#include <iostream>
#include "TetrisDefs.h"
#include "TetrisBoard.h"
#include "Tetromino.h"
#include "TetSquare.h"
int main(int argc, char** argv)
{
    std::cout << "Instantiating Tetronimo..." << std::endl;
    TetrisBoard* pBoard = new TetrisBoard();
    TetSquare* pTetSquare = new TetSquare(SHAPE_S_4, pBoard);
    pTetSquare->Fall();
    pTetSquare->MoveLeft();
    pTetSquare->MoveRight();
    pTetSquare->WriteToBoard();
    pBoard->Print();
//    pTetSquare->Print();
    std::cout << "Instantiation Successful!" << std::endl;
}


// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <GL/glut.h>
// #include <iostream>

// float angle = 0.0;
// float yOffset = 0.0;
// int timeCount = 0;

// void timeOut(int);

// void init()
// {
//     glClearColor(0.25, 0.25, 0.25, 0.0);
//     glShadeModel(GL_FLAT);
// }

// void reshape (int w, int h)
// {
//    glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
//    glMatrixMode (GL_PROJECTION);
//    glLoadIdentity ();
//    gluOrtho2D(0.0, 10.0, 0.0, 20.0);
//    glMatrixMode (GL_MODELVIEW);
// }

// void renderScene(void) {
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glColor3f(0.0, 1.0, 0.75);
//     glPushMatrix();
//     glTranslatef(5.0, 19.5 - yOffset, 0.0);
//     //glRotatef(angle, 0.0, 0.0, 1.0);
//     glTranslatef(-0.5, -0.5, 0.0);
// 	glBegin(GL_QUADS);
//         glVertex3f( 0.0f,  0.0f,  0.0f);
//         glVertex3f( 1.0f,  0.0f,  0.0f);
//         glVertex3f( 1.0f,  1.0f,  0.0f);
//         glVertex3f( 0.0f,  1.0f,  0.0f);
// 	glEnd();
//     glLineWidth(3.0);
//     glColor3f(0.0, 0.0, 0.0);
//     glBegin(GL_LINE_LOOP);
//         glVertex3f( 0.0f,  0.0f,  0.1f);
//         glVertex3f( 1.0f,  0.0f,  0.1f);
//         glVertex3f( 1.0f,  1.0f,  0.1f);
//         glVertex3f( 0.0f,  1.0f,  0.1f);
//     glEnd();        
//     glPopMatrix();
    
//     // Calls glFlush() for us.
//     glutSwapBuffers();

//     if(!(timeCount % 15) && yOffset < 19)
//         yOffset = yOffset + 1;
//     timeCount++;
//     //angle++;
// }

// void timeOut(int param)
// {
//     renderScene();
//     glutTimerFunc((1000/30), timeOut, 0); // Let's do 30 fps
// }

// int main(int argc, char **argv) {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
// 	glutInitWindowSize(320,640);
// 	glutInitWindowPosition(100,100);
// 	glutCreateWindow("uTetris-Dev");
//     init();
// 	glutDisplayFunc(renderScene);
//     glutReshapeFunc(reshape);
//     //glutIdleFunc(renderScene);
//     glutTimerFunc((1000/30), timeOut, 0); // Let's do 30 fps
// 	glutMainLoop();
//     return 0; // Never reached.
// }
