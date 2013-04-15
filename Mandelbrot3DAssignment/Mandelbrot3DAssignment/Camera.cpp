#include "StdAfx.h"

#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <math.h>

#include "Camera.h" 
Camera::Camera(void){
}

Camera::~Camera(void){
}
//Phan cai dat camera
void Camera::setDefaultCamera(){
	setPerspective(75.0f, 640/(float)480, 0.1f, 200.0f); // good default values here
	setLookAt(Vector3f(100, 100, 100), Vector3f(0, 0, 0), Vector3f(0, 1, 0));
}
void Camera::setDisplay(int _nRows, int _nCols){
	nRows = _nRows;
	nCols = _nCols;
}

void Camera::setLookAt(Vector3f _eye, Vector3f _look, Vector3f _up){
	eye = _eye;
	n = Vector3f(_eye.x - _look.x , _eye.y - _look.y , _eye.z - _look.z);
	u = Vector3f::cross(_up,n);
	v = Vector3f::cross(n,u);
	n.Normalize();u.Normalize();v.Normalize();
	setModelViewMatrix();
}

void Camera::setLookAt(float eye_x,float eye_y,float eye_z, float look_x, float look_y, float look_z, float up_x, float up_y, float up_z){
	setLookAt(Vector3f(eye_x,eye_y,eye_z),Vector3f(look_x,look_y,look_z),Vector3f(up_x,up_y,up_z));
}
void Camera::setPerspective(float _viewAngle, float _aspect, float _nearDist, float _farDist){
	viewAngle = _viewAngle;
	aspect = _aspect;
	nearDist = _nearDist; farDist = _farDist;
	H = nearDist * tan(3.14159265 * viewAngle/(2.0 * 180));
	W = aspect * H;
	//Chinh lai Projection Matrix voi thong so bi thay doi
	setProjectionMatrix();
}

//Cac action xoay camera
void Camera::roll(float angle){
	rotateAxes(u,v,-angle);
}
void Camera::yaw(float angle){
	rotateAxes(n,u,-angle);
}
void Camera::pitch(float angle){
	rotateAxes(n,v,-angle);	
}
void Camera::slide(float du,float dv, float dn){
	eye.x += du * u.x + dv * v.x + dn * n.x;
	eye.y += du * u.y + dv * v.y + dn * n.y;
	eye.z += du * u.z + dv * v.z + dn * n.z;
	setModelViewMatrix();
}

void Camera::rotateAxes(Vector3f &a, Vector3f &b, float angle){
	//Chuyen ve dang radian
	float rad_angle = 3.14159265/180 * angle;
	float cosVal = cos(rad_angle);
	float sinVal = sin(rad_angle);
	Vector3f new_a(cosVal * a.x + sinVal * b.x, cosVal * a.y + sinVal * b.y, cosVal * a.z + sinVal * b.z);
	Vector3f new_b(-sinVal * a.x + cosVal * b.x, -sinVal * a.y + cosVal * b.y, -sinVal * a.z + cosVal * b.z);
	a = new_a; b = new_b;
	//Dat lai ModelViewMatrix
	setModelViewMatrix();
}
void Camera::setModelViewMatrix(){
	float matrix[16];
	Vector3f eyeVector(eye.x,eye.y,eye.z);
	matrix[0] = u.x ; matrix[4] = u.y ; matrix[8] = u.z ; matrix[12] = -Vector3f::dot(eyeVector,u);
	matrix[1] = v.x ; matrix[5] = v.y ; matrix[9] = v.z ; matrix[13] = -Vector3f::dot(eyeVector,v);
	matrix[2] = n.x ; matrix[6] = n.y ; matrix[10]= n.z ; matrix[14] = -Vector3f::dot(eyeVector,n);
	matrix[3] = 0	; matrix[7] = 0	  ; matrix[11] = 0	; matrix[15] = 1;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(matrix);
}

void Camera::setProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(viewAngle,aspect,nearDist,farDist);
	//Chuyen lai ve MODEL VIEW
	glMatrixMode(GL_MODELVIEW);
}