#include "stdafx.h"
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include "GlobalVariables.h"
#include "Mandelbrot.h"
#include "Plane.h"
#include "Camera.h"
#include "Light.h"

#define FRAME_TIME 15
/* -- GLOBAL VARIABLES -- */
//int WINDOW_WIDTH = 800;
//int WINDOW_HEIGHT = 600;

//int X_RANGE = 100;
//int Y_RANGE = 100;
//int Z_RANGE = 100;

Camera camera;
Mandelbrot mandelbrot(X_RANGE, Y_RANGE, Z_RANGE, MAX_ITERATION);
//Plane ground(8.0f,8.0f,8,8);
//Plane roof(8.0f,8.0f,8,8);
//Plane wall(8.0f,6.0f,8,6);
Plane ground(BOX_SIZE_1,BOX_SIZE_1,BOX_SIZE_1_TILES,BOX_SIZE_1_TILES);
Plane roof(BOX_SIZE_1,BOX_SIZE_1,BOX_SIZE_1_TILES,BOX_SIZE_1_TILES);
Plane wall(BOX_SIZE_1,BOX_SIZE_2,BOX_SIZE_1_TILES,BOX_SIZE_2_TILES);
	
Light lights[]={
	{
		-2.0f,-2.0f,2.0f,1.0f,
		1.0f,1.0f,1.0f,1.0f,
		45.0f,
		0.1f,
		2.0f,2.0f,-2.0f,
		1.0f,-1.5f,0.8f
	},
	{
		2.0f,2.0f,2.0f,1.0f,
		1.0f,0.0f,0.0f,1.0f,
		30.0f,
		0.05f,
		-2.0f,-2.0f,-2.0f,
		-1.3f,-1.2f,1.0f
	},
	{
		2.0f,-2.0f,2.0f,1.0f,
		0.0f,1.0f,0.0f,1.0f,
		30.0f,
		0.05f,
		-2.0f,2.0f,-2.0f,
		1.2f,0.7f,-1.8f
	},
	{
		-2.0f,2.0f,2.0f,1.0f,
		0.0f,0.0f,1.0f,1.0f,
		30.0f,
		0.05f,
		2.0f,-2.0f,-2.0f,
		-1.2f,1.0f,-1.0f
	}
};
int light_number = 4;

//void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
//{           glMatrixMode(GL_PROJECTION);
//            glLoadIdentity();
//            gluOrtho2D(left, right, bottom, top);
//} 

void UpdateLightPosition(){
	glLightfv(GL_LIGHT0,GL_POSITION,lights[0].position);
	glLightfv(GL_LIGHT1,GL_POSITION,lights[1].position);
	glLightfv(GL_LIGHT2,GL_POSITION,lights[2].position);
	glLightfv(GL_LIGHT3,GL_POSITION,lights[3].position);
}

void update(int value){
	cout<<"Co update"<<endl;
	float elapsed_second = (float)FRAME_TIME/1000;
	for(int i=0;i<light_number;i++){
		lights[i].update(elapsed_second);
	}
	UpdateLightPosition();
	glutPostRedisplay();
	glutTimerFunc(FRAME_TIME, update, 0);
}
void myInit( void ) {
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0 );
	glPointSize(1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	camera.setPerspective(60, (float)WINDOW_WIDTH/(float) WINDOW_HEIGHT, 0.01f, 100.0f);
	camera.setLookAt(0.0f , 8.0f , 0.0f , 0.0f , 0.0f , 0.0f , 0.0f , 0.0f , 1.0f);
	
	glMatrixMode(GL_MODELVIEW);
	// enable depth testing
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_LIGHTING);
	

	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lights[0].spot_cutoff);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, lights[1].spot_cutoff);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, lights[2].spot_cutoff);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, lights[3].spot_cutoff);

	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, lights[0].linear_attenuation);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, lights[1].linear_attenuation);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, lights[2].linear_attenuation);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, lights[3].linear_attenuation);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION,lights[0].spot_direction);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,lights[1].spot_direction);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION,lights[2].spot_direction);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION,lights[3].spot_direction);

	float global_amb[] = {0.0f,0.0f,0.0f,1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_amb);
	
	glLightfv(GL_LIGHT0,GL_POSITION,lights[0].position);
	glLightfv(GL_LIGHT1,GL_POSITION,lights[1].position);
	glLightfv(GL_LIGHT2,GL_POSITION,lights[2].position);
	glLightfv(GL_LIGHT3,GL_POSITION,lights[3].position);
	

	glLightfv(GL_LIGHT0,GL_DIFFUSE,lights[0].diffuse);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,lights[1].diffuse);
	glLightfv(GL_LIGHT2,GL_DIFFUSE,lights[2].diffuse);
	glLightfv(GL_LIGHT3,GL_DIFFUSE,lights[3].diffuse);

	glEnable( GL_LIGHT0 );
	glEnable( GL_LIGHT1 );
	glEnable( GL_LIGHT2 );
	glEnable( GL_LIGHT3 );
	
	
	ground.texture.LoadTextureFromFile("stone.png",1);
	roof.texture.LoadTextureFromFile("wood.png",2);
	wall.texture.LoadTextureFromFile("brick.png",3);
	glCullFace(GL_BACK); glEnable(GL_CULL_FACE);
}

void myDisplay( void )  {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	
	mandelbrot.draw();
	
	//Enable texture
	glEnable(GL_TEXTURE_2D); glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	//Nen nha

	float half_box_size_1 = BOX_SIZE_1/2;
	float half_box_size_2 = BOX_SIZE_2/2;

	glPushMatrix();
	//glTranslatef(-4.0f,-4.0f,-3.0f);
	glTranslatef(-half_box_size_1,-half_box_size_1,-half_box_size_2);
		ground.draw();
	glPopMatrix();
	
	//Tran nha
	glPushMatrix();
	glRotatef(-180,0,1,0);
	//glTranslatef(-4.0f,-4.0f,-3.0f);
	glTranslatef(-half_box_size_1,-half_box_size_1,-half_box_size_2);
		roof.draw();
	glPopMatrix();
	
	//Tuong giua
	glPushMatrix();
	glRotatef(-90,1,0,0);
	//glTranslatef(-4.0f,-3.0f,-4.0f);
	glTranslatef(-half_box_size_1,-half_box_size_2,-half_box_size_1);
		wall.draw();
	glPopMatrix();
	
	//Tuong phai
	glPushMatrix();
	glRotatef(90,0,0,1);
	glRotatef(90,1,0,0);
	//glTranslatef(-4.0f,-3.0f,-4.0f);
	glTranslatef(-half_box_size_1,-half_box_size_2,-half_box_size_1);
		wall.draw();
	glPopMatrix();
	
	//Tuong trai
	glPushMatrix();
	glRotatef(-90,0,0,1);
	glRotatef(90,1,0,0);
	//glTranslatef(-4.0f,-3.0f,-4.0f);
	glTranslatef(-half_box_size_1,-half_box_size_2,-half_box_size_1);
		wall.draw();
	glPopMatrix();
	//Disable texture
	glDisable(GL_TEXTURE_2D);

	
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	for(int i=0;i<light_number;i++){
			glVertex3fv(lights[i].position);
		}
	glEnd();
	glPointSize(1.0f);

	//glDisable(GL_LIGHTING);
	//Truc Oxyz
	//Truc x mau do
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(4,0,0);
	glEnd();

	
	//Truc y mau xanh la cay
	glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(0,4,0);
	glEnd();

	//Truc z mau xanh nuoc bien
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(0,0,4);
	glEnd();
	//glEnable(GL_LIGHTING);

	glFinish();
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
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );
	glutInitWindowPosition( 100, 150 );

	glutCreateWindow("Mandelbulb 3D");
	// Set the callback funcion to call when we need to draw something.
	glutDisplayFunc( myDisplay );
	glutKeyboardFunc(myKeyInput);
	ilInit();	//Khoi tao 
	myInit();
	// Now that we have set everything up, loop responding to events.
	glutTimerFunc(FRAME_TIME,update,0);
	glutMainLoop();
}



