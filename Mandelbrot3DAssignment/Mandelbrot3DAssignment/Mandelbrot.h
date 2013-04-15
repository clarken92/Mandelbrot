#pragma once

#include <vector>
#include "Color.h"
#include "Vector3f.h"
#include "Complex.h"

class Mandelbrot
{
	public:
		float minX, maxX;
		float minY, maxY;
		float minZ, maxZ;

		int xRange, yRange, zRange;
		float xFactor, yFactor, zFactor;

		int iteration;
		vector<Vector3f> points;
		vector<Color> point_colors;

	public:
		Mandelbrot(void);
		Mandelbrot(int _xRange, int _yRange, int _zRange, int _iteration);
		~Mandelbrot(void);
		void draw();
	private:
		void createPointSet();
		
};

