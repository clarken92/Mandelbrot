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
#include "Sphere.h"

#define FRAME_TIME 15
/* -- GLOBAL VARIABLES -- */

Camera camera;
Mandelbrot mandelbrot(X_RANGE, Y_RANGE, Z_RANGE, MAX_ITERATION);

Plane ground(BOX_SIZE_1,BOX_SIZE_1,BOX_SIZE_1_TILES,BOX_SIZE_1_TILES);
Plane roof(BOX_SIZE_1,BOX_SIZE_1,BOX_SIZE_1_TILES,BOX_SIZE_1_TILES);
Plane wall(BOX_SIZE_1,BOX_SIZE_2,BOX_SIZE_1_TILES,BOX_SIZE_2_TILES);
	
Light lights[]={
	{
		0.0f,-1.0,0.0f,1.0f,
		1.0f,1.0f,1.0f,1.0f,
		45.0f,
		0.0f,
		0.0f,-1.0f,0.0f,
		1.0f,-1.5f,0.8f,
		4.8,
		1.0f,1.0f,1.0f,1.0f
	},
	{
		2.0f,2.0f,2.0f,1.0f,
		1.0f,0.0f,0.0f,1.0f,
		60.0f,
		0.05f,
		-1.3f,-1.2f,1.0f,
		-1.3f,-1.2f,1.0f,
		2.8,
		1.0f,0.0f,0.0f,1.0f
	},
	{
		2.0f,-2.0f,2.0f,1.0f,
		0.0f,1.0f,0.0f,1.0f,
		60.0f,
		0.05f,
		-2.0f,2.0f,-2.0f,
		1.2f,0.7f,-1.8f,
		3.5,
		0.0f,1.0f,0.0f,1.0f
	},
	{
		-2.0f,2.0f,2.0f,1.0f,
		0.0f,0.0f,1.0f,1.0f,
		60.0f,
		0.05f,
		2.0f,-2.0f,-2.0f,
		-1.2f,1.0f,-1.0f,
		3.0,
		0.0f,0.0f,1.0f,1.0f
	}
};

Sphere light_source;

int mouse_x=0 ,mouse_y=0;
bool mouse_updated = false;
//int previous_state;
int rot_x=0,rot_y=0,rot_z=0;

void UpdateLightPosition(){
	glLightfv(GL_LIGHT0,GL_POSITION,lights[0].position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION,lights[0].spot_direction);
	
	glLightfv(GL_LIGHT1,GL_POSITION,lights[1].position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,lights[1].spot_direction);
	
	glLightfv(GL_LIGHT2,GL_POSITION,lights[2].position);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION,lights[2].spot_direction);
	
	glLightfv(GL_LIGHT3,GL_POSITION,lights[3].position);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION,lights[3].spot_direction);
}

void update(int value){
	float elapsed_second = (float)FRAME_TIME/1000;
	for(int i=0;i<LIGHT_NUMBER;i++){
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
	
	light_source.loadMeshFromFile("sphere.object");
	for(int i=0;i<LIGHT_NUMBER;i++){
		lights[i].init();
	}

	ground.texture.LoadTextureFromFile("stone.png",1);
	roof.texture.LoadTextureFromFile("wood.png",2);
	wall.texture.LoadTextureFromFile("brick.png",3);
	
	//glMatrixMode(GL_MODELVIEW);
	// enable depth testing
	glEnable( GL_DEPTH_TEST );
	//glEnable( GL_LIGHTING);
	

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

	float global_amb[] = {0.2f,0.2f,0.2f,1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_amb);
	
	glLightfv(GL_LIGHT0,GL_POSITION,lights[0].position);
	glLightfv(GL_LIGHT1,GL_POSITION,lights[1].position);
	glLightfv(GL_LIGHT2,GL_POSITION,lights[2].position);
	glLightfv(GL_LIGHT3,GL_POSITION,lights[3].position);
	

	glLightfv(GL_LIGHT0,GL_DIFFUSE,lights[0].diffuse);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,lights[1].diffuse);
	glLightfv(GL_LIGHT2,GL_DIFFUSE,lights[2].diffuse);
	glLightfv(GL_LIGHT3,GL_DIFFUSE,lights[3].diffuse);

	//glEnable( GL_LIGHT0 );
	//glEnable( GL_LIGHT1 );
	//glEnable( GL_LIGHT2 );
	//glEnable( GL_LIGHT3 );
	
	glCullFace(GL_BACK); glEnable(GL_CULL_FACE);
}

void myDisplay( void )  {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	
	glPushMatrix();
		glRotatef(rot_x,1,0,0);
		glRotatef(rot_y,0,1,0);
		glRotatef(rot_z,0,0,1);
		mandelbrot.draw();
	glPopMatrix();
	//Enable texture
	//float diffused[] = {0.8,0.5,0.1,1.0};
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffused);
	/*
	glEnable(GL_TEXTURE_2D); glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	//Nen nha
	float half_box_size_1 = BOX_SIZE_1/2;
	float half_box_size_2 = BOX_SIZE_2/2;

	glPushMatrix();
	glTranslatef(-half_box_size_1,-half_box_size_1,-half_box_size_2);
		ground.draw();
	glPopMatrix();
	
	//Tran nha
	glPushMatrix();
	glRotatef(-180,0,1,0);
	glTranslatef(-half_box_size_1,-half_box_size_1,-half_box_size_2);
		roof.draw();
	glPopMatrix();
	
	//Tuong giua
	glPushMatrix();
	glRotatef(-90,1,0,0);
	glTranslatef(-half_box_size_1,-half_box_size_2,-half_box_size_1);
		wall.draw();
	glPopMatrix();
	
	//Tuong phai
	glPushMatrix();
	glRotatef(90,0,0,1);
	glRotatef(90,1,0,0);
	glTranslatef(-half_box_size_1,-half_box_size_2,-half_box_size_1);
		wall.draw();
	glPopMatrix();
	
	//Tuong trai
	glPushMatrix();
	glRotatef(-90,0,0,1);
	glRotatef(90,1,0,0);
	glTranslatef(-half_box_size_1,-half_box_size_2,-half_box_size_1);
		wall.draw();
	glPopMatrix();
	//Disable texture
	glDisable(GL_TEXTURE_2D);
	
	//glDisable(GL_LIGHTING);
	//Ve lightsource
	for(int i=0;i<LIGHT_NUMBER;i++){
		glPushMatrix();
		glTranslatef(lights[i].position[0],lights[i].position[1],lights[i].position[2]);
		light_source.draw(lights[i].source_color);
		glPopMatrix();
	}
	//glEnable(GL_LIGHTING);
	*/
	glFinish();
	glutSwapBuffers();
}

void myKeyInput(unsigned char key, int x, int y){
	switch(key){
		case 27:
			exit(0);
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
		
		case 't':
			rot_x += 10; rot_x = rot_x%360;
			glutPostRedisplay();break;
		case 'y':
			rot_x -= 10; rot_x = rot_x%360;
			glutPostRedisplay();break;
		case 'g':
			rot_y += 10; rot_y = rot_y%360;
			glutPostRedisplay();break;
		case 'h':
			rot_y -= 10; rot_y = rot_y%360;
			glutPostRedisplay();break;
		case 'b':
			rot_z += 10; rot_z = rot_z%360;
			glutPostRedisplay();break;
		case 'n':
			rot_z -= 10; rot_z = rot_z%360;
			glutPostRedisplay();break;
	}
}
void myMouseMotion(int x, int y){
	int dx,dy;
	if( ! mouse_updated) {
		mouse_x = x;
		mouse_y = y;

		mouse_updated = true;
	
	} else {

		// calc delta
		dx = x - mouse_x;
		dy = y - mouse_y;

		mouse_x = x;
		mouse_y = y;

		// determine rotation amount
		camera.pitch( dy / 5.0 );
		camera.yaw( dx / 5.0 );
		glutPostRedisplay();
	}

}

/*
void Mouse(int button,int state,int x,int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && previous_state == GLUT_UP){
		mouse_x = x; mouse_y = y;
		previous_state = GLUT_DOWN;
		return;
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP && previous_state == GLUT_DOWN){
		int diff_x = x - mouse_x; int diff_y = y - mouse_y;
		cout<<diff_x<<"  "<<diff_y<<endl;
		rot_x = diff_x/10.0f;
		rot_y = diff_y/10.0f;

		previous_state = GLUT_UP;
		glutPostRedisplay();
	}
}
*/
int main( int argc, char *argv[] )  {
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );
	glutInitWindowPosition( 100, 150 );

	glutCreateWindow("Mandelbulb 3D");
	// Set the callback funcion to call when we need to draw something.
	glutDisplayFunc( myDisplay );
	glutKeyboardFunc(myKeyInput);
	glutPassiveMotionFunc( myMouseMotion );
	//glutMouseFunc(Mouse);
	ilInit();	//Khoi tao 
	myInit();
	// Now that we have set everything up, loop responding to events.
	//glutTimerFunc(FRAME_TIME,update,0);
	glutMainLoop();
}



