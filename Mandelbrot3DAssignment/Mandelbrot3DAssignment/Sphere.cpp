#include "StdAfx.h"

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include "Sphere.h"
Sphere::Sphere(void)
{
}


Sphere::~Sphere(void)
{
}

void Sphere::draw(float color[4]){
	glColor4f(color[0],color[1],color[2],color[3]);
	Mesh::draw();
}