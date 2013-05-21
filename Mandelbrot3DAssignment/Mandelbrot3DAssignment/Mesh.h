#pragma once

#include <vector>
#include "Vector3f.h"

struct TextureCoordinate{
	float u,v;
};
struct Face
{
	int number;
	int vertex_indices[4];
	int normal_indices[4];
	int texture_indices[4];
	void println(){
		for(int i=0;i<number;i++){
			cout<<vertex_indices[i]<<"/"<<texture_indices[i]<<"/"<<normal_indices[i]<<" ";
		}
		cout<<endl;
	}
};

class Mesh
{
	vector<Vector3f> vertices;
	vector<Vector3f> normals;
	vector<TextureCoordinate> textures; 
	vector<Face> faces;

	public:
		Mesh(void);
		~Mesh(void);
		bool loadMeshFromFile(char* filename);
		void draw();
};