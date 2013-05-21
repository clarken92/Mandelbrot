#pragma once

#include "Mesh.h"
class Sphere : public Mesh
{
public:
	Sphere(void);
	~Sphere(void);
	void draw(float color[4]);
};

