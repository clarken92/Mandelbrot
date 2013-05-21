#include "StdAfx.h"
#include "Plane.h"


Plane::Plane(void)
{
}

Plane::Plane(float _length, float _width, int _length_num, int _width_num){
	length = _length; width = _width;
	length_num = _length_num; width_num = _width_num;

	/*
	Vector3f v;
	v.z = 0;
	for(int j=0;j<=width_num;j++){
		v.y = j * width / width_num;
		for(int i=0;i<=length_num;i++){
			v.x = i * length / length_num;
			v.print();
				cout<<endl;
			vertices.push_back(v);
		}
	}

	int width_num_1 = width_num + 1; int length_num_1 = length_num + 1;
	vector<int> cell(4);
	int count = 0;
	for(int j=0;j<width_num;j++){
		for(int i=0;i<length_num;i++){
			cell[0] = j * length_num_1 + i;
			cell[1] = j * length_num_1 + (i+1);
			cell[2] = (j+1) * length_num_1 + (i+1);
			cell[3] = (j+1) * length_num_1 + i;
			cells.push_back(cell);
		}
	}
	*/
}

Plane::~Plane(void)
{
}

void Plane::draw(float red,float green, float blue){
	float max_length_tex = length_num * 1.0f;
	float max_width_tex = width_num * 1.0f;

	glColor3f(red,green,blue);
	glBindTexture(GL_TEXTURE_2D,texture.texture_id);

	//vector< vector<int> >::iterator it;
	//Vector3f v;

	glBegin(GL_QUADS);
		glNormal3f(0.0f,0.0f,1.0f);
		/*for(it = cells.begin();it<cells.end();it++){
			v = vertices[(*it)[0]]; glTexCoord2f(0.0f,0.0f); glVertex3f(v.x,v.y,v.z);
			v = vertices[(*it)[1]]; glTexCoord2f(1.0f,0.0f); glVertex3f(v.x,v.y,v.z);
			v = vertices[(*it)[2]]; glTexCoord2f(1.0f,1.0f); glVertex3f(v.x,v.y,v.z);
			v = vertices[(*it)[3]]; glTexCoord2f(0.0f,1.0f); glVertex3f(v.x,v.y,v.z);
		}*/
		glTexCoord2f(0.0f,0.0f); glVertex3f(0.0f,0.0f,0.0f);
		glTexCoord2f(max_length_tex,0.0f); glVertex3f(length, 0.0f,0.0f);	
		glTexCoord2f(max_length_tex,max_width_tex); glVertex3f( length, width,0.0f);
		glTexCoord2f(0.0f,max_width_tex); glVertex3f(0.0f, width,0.0f);
	glEnd();
}

void Plane::draw(){
	draw(1.0f,1.0f,1.0f);
}