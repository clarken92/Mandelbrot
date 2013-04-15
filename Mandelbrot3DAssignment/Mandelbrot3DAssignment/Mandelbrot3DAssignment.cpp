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
#include "Camera.h"
using namespace std;

/* -- GLOBAL VARIABLES --------------------------------------------------- */
int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

int X_RANGE = 400;
int Y_RANGE = 400;
int Z_RANGE = 200;

Camera camera;

Mandelbrot mandelbrot (X_RANGE, Y_RANGE, Z_RANGE, 20);
/* -- LOCAL VARIABLES ---------------------------------------------------- */

void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{           glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(left, right, bottom, top);
} 


void myInit( void ) {
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0 );
	glPointSize(1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	camera.setPerspective(90, (float)WINDOW_WIDTH/(float) WINDOW_HEIGHT, 0.01, 10.0);
	camera.setLookAt(2.0f , 0.0f , 0.0f , 0.0f , 0.0f , 0.0f , 0.0f , -1.0f , 0.0f);

	// enable depth testing
	//glEnable( GL_DEPTH_TEST );
}

void myDisplay( void )  {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	mandelbrot.draw();
	
	glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_LINES);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,1.0f);
	glEnd();
	
	glutSwapBuffers();
}

void myKeyInput(unsigned char key, int x, int y){
	switch(key){
		case 'q':
			camera.roll(-10);
			glutPostRedisplay();break;
		case 'w':
			camera.roll(10);
			glutPostRedisplay();break;
		case 'a':
			camera.yaw(-10);
			glutPostRedisplay();break;
		case 's':
			camera.yaw(10);
			glutPostRedisplay();break;
		case 'z':
			camera.pitch(-10);
			glutPostRedisplay();break;
		case 'x':
			camera.pitch(10);
			glutPostRedisplay();break;
		
		case 'e':
			camera.slide(-0.1f,0,0);
			glutPostRedisplay();break;
		case 'r':
			camera.slide(0.1f,0,0);
			glutPostRedisplay();break;
		case 'd':
			camera.slide(0,-0.1f,0);
			glutPostRedisplay();break;
		case 'f':
			camera.slide(0,0.1f,0);
			glutPostRedisplay();break;
		case 'c':
			camera.slide(0,0,-0.1f);
			glutPostRedisplay();break;
		case 'v':
			camera.slide(0,0,0.1f);
			glutPostRedisplay();break;
	}
}

int main( int argc, char *argv[] )  {
  // Initialize GLUT.
  glutInit( &argc, argv );
  // Set the mode to draw in.
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
  // Set the window size in screen pixels.
  glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );
  // Set the window position in screen pixels.
  glutInitWindowPosition( 100, 150 );
  // Create the window.
  glutCreateWindow("Mandelbrot 3D");
  // Set the callback funcion to call when we need to draw something.
  glutDisplayFunc( myDisplay );
  glutKeyboardFunc(myKeyInput);
  // Initialize some things.
  myInit( );
  // Now that we have set everything up, loop responding to events.
  glutMainLoop( );
}

/* ----------------------------------------------------------------------- */



