#pragma once
#include <vector>
#include "Vector3f.h"
#include "TextureHandler.h"

class Plane
{
	private:
		float length, width;
		int length_num, width_num;

	public:
		TextureHandler texture;

		Plane(void);
		Plane(float _length, float _width, int _length_num, int _width_num);
		~Plane(void);
		void draw(float red,float green,float blue);
		void draw();
};

