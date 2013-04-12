#pragma once

#include <vector>
#include "Color.h"
#include "Vector3f.h"
#include "Complex.h"

class Mandelbrot
{
	public:
		double minReal;
		double maxReal;
		double minImg;
		double maxImg;

		int screenWidth, screenHeight;
		float scale;

		int iteration;
		vector<Color> points;

	public:
		Mandelbrot(void);
		Mandelbrot(int _screenWidth, int _screenHeigh, int _iteration);
		~Mandelbrot(void);
		void draw();
	private:
		void createPointSet();
		
};

