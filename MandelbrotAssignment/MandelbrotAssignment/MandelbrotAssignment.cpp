/* Module      : Lab06_2.cpp
 * Author      : Do Duc Kien
 * Email       : kiendd_55@vnu.edu.vn
 * Course      : Computer Graphics
 *
 * Description : 
 *
 *
 * Date        : 
 *
 * History:
 * Revision      Date          Changed By
 * --------      ----------    ----------
 * 01.00         ?????          ???
 * First release.
 *
 */

/* -- INCLUDE FILES ------------------------------------------------------ */
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
using namespace std;

/* -- GLOBAL VARIABLES --------------------------------------------------- */
int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

Mandelbrot mandelbrot (WINDOW_WIDTH, WINDOW_HEIGHT, 50);
/* -- LOCAL VARIABLES ---------------------------------------------------- */

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

/* ----------------------------------------------------------------------- */
/* Function    : void myDisplay( void )
 *
 * Description : This function gets called everytime the window needs to
 *               be redrawn.
 * * Parameters  : void
 *
 * Returns     : void
 */

void myDisplay( void )  {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	mandelbrot.draw();
	glutSwapBuffers();
}

void myKeyInput(unsigned char key, int x, int y){

}
/* ----------------------------------------------------------------------- */
/* Function    : int main( int argc, char** argv )
 *
 * Description : This is the main function. It sets up the rendering
 *               context, and then reacts to user events.
 *
 * Parameters  : int argc     : Number of command-line arguments.
 *               char *argv[] : Array of command-line arguments.
 *
 * Returns     : int : Return code to pass to the shell.
 */

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
  glutCreateWindow("Mandelbrot");
  // Set the callback funcion to call when we need to draw something.
  glutDisplayFunc( myDisplay );
  glutKeyboardFunc(myKeyInput);
  // Initialize some things.
  myInit( );
  // Now that we have set everything up, loop responding to events.
  glutMainLoop( );
}

/* ----------------------------------------------------------------------- */



