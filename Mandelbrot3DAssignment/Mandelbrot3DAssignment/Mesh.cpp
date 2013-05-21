#include "StdAfx.h"

#include <windows.h>
#include <fstream>
#include <string>

#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include "Mesh.h"
using namespace std;
Mesh::Mesh(void)
{
}

Mesh::~Mesh(void)
{
}

bool Mesh::loadMeshFromFile(char* filename){
	FILE* file = fopen(filename, "r");
	if( file == NULL ){
		printf("Impossible to open the file !\n");
		return false;
	}
	//string lineHeader;
	char lineHeader[20];
	while(!feof(file)){
		fscanf(file, "%s", lineHeader);
		if (strcmp(lineHeader,"v") == 0){
			Vector3f v;
			fscanf(file,"%f %f %f\n", &v.x, &v.y , &v.z);
			vertices.push_back(v);
		}
		else if (strcmp(lineHeader,"vn") == 0){
			Vector3f vn;
			fscanf(file, "%f %f %f\n", &vn.x, &vn.y, &vn.z);
			normals.push_back(vn);
		}
		else if (strcmp(lineHeader,"vt") == 0){
			TextureCoordinate vt;
			fscanf(file, "%f %f\n", &vt.u, &vt.v);
			textures.push_back(vt);
		}
		else if (strcmp(lineHeader,"f") == 0){
			unsigned int v_index[4], vt_index[4], vn_index[4];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",
				&v_index[0], &vt_index[0], &vn_index[0],
				&v_index[1], &vt_index[1], &vn_index[1],
				&v_index[2], &vt_index[2], &vn_index[2],
				&v_index[3], &vt_index[3], &vn_index[3]);
			Face face;
			if(matches == 9){			
				face.number = 3;				
			}
			else if(matches = 12){
				face.number = 4;
			}
			else { 
				printf("Wrong face data !");
				fclose(file); return false;
			}
			for(int i=0;i<face.number;i++){
				face.vertex_indices[i] = v_index[i]-1;
				face.normal_indices[i] = vn_index[i]-1;
				face.texture_indices[i] = vt_index[i]-1;
			}
			faces.push_back(face);
		}
	}
	fclose(file); return true;
}

void Mesh::draw(){
	vector<Face>::iterator it;
	Vector3f v, vn;
	for(it = faces.begin(); it < faces.end(); it++){
		glBegin(GL_POLYGON);	
		for(int i=0; i<it->number; i++){
			v = vertices[it->vertex_indices[i]];
			vn = normals[it->normal_indices[i]];

			glVertex3f(v.x,v.y,v.z); glNormal3f(vn.x,vn.y,vn.z);
		}
		glEnd();
	}
	
}