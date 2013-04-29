#include "StdAfx.h"
#include "Plane.h"


Plane::Plane(void)
{
}

Plane::Plane(float _length, float _width, int _length_num, int _width_num){
	length = _length; width = _width;
	length_num = _length_num; width_num = _width_num;
}

Plane::~Plane(void)
{
}

void Plane::draw(float red,float green, float blue){
	//float half_length = length/2;
	//float half_width = width/2;
	float max_length_tex = length_num * 1.0f;
	float max_width_tex = width_num * 1.0f;

	glColor3f(red,green,blue);
	glBindTexture(GL_TEXTURE_2D,texture.texture_id);
	glBegin(GL_QUADS);
		glNormal3f(0.0f,0.0f,1.0f);
		glTexCoord2f(0.0f,0.0f); glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(max_length_tex,0.0f); glVertex3f(length, 0.0f,0.0f);	
		glTexCoord2f(max_length_tex,max_width_tex); glVertex3f( length, width,0.0f);
		glTexCoord2f(0.0f,max_width_tex); glVertex3f(0.0f, width,0.0f);
	glEnd();
}

void Plane::draw(){
	draw(1.0f,1.0f,1.0f);
}