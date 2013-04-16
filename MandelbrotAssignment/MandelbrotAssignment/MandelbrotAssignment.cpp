#include "stdafx.h"
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include <fstream>
#include <string>
#include <iostream>
#include <math.h>

#include "Mandelbrot.h"
#include "MyRectangle.h"
using namespace std;

/* -- GLOBAL VARIABLES -- */
int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

int PreviousLeftMouseState = GLUT_UP;
MyRectangle rect;
Mandelbrot mandelbrot (WINDOW_WIDTH, WINDOW_HEIGHT);

void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{           glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(left, right, bottom, top);
} 


void myInit( void ) {
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0 );
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D( 0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT );
}

void myDisplay( void )  {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	mandelbrot.draw();
	glutSwapBuffers();
}

void myKeyInput(unsigned char key, int x, int y){
	switch(key){
		case 'a':
			cout<<'a'<<endl;
			mandelbrot.zoom(0.3f,1.0f,0.8f,1.5f);
			glutPostRedisplay();
			break;
	}
}

void myMouseAction(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && PreviousLeftMouseState == GLUT_UP){
		//cout<<"Start point is: ("<<x<<" , "<<y<<")"<<endl;
		//He toa do world coordinate khac voi mouse coordinate
		rect.x1 = x; rect.y1 = WINDOW_HEIGHT - y;
		PreviousLeftMouseState = GLUT_DOWN; return;
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && PreviousLeftMouseState == GLUT_DOWN){
		//cout<<"End point is: ("<<x<<" , "<<y<<")"<<endl;
		rect.x2 = x; rect.y2 = WINDOW_HEIGHT - y;
		PreviousLeftMouseState = GLUT_UP;
		
		mandelbrot.resize(rect);
		glutPostRedisplay();
		return;
	}
	rect.reset();
	PreviousLeftMouseState = GLUT_UP; 
}


int main( int argc, char *argv[] )  {
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );
	glutInitWindowPosition( 100, 150 );
	glutCreateWindow("Mandelbrot 2D");
	// Set the callback funcion to call when we need to draw something.
	glutDisplayFunc( myDisplay );
	glutKeyboardFunc(myKeyInput);
	glutMouseFunc(myMouseAction);
	// Initialize some things.
	myInit( );
	// Now that we have set everything up, loop responding to events.
	glutMainLoop( );
}



