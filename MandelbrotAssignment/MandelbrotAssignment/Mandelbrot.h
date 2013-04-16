#pragma once

#include <vector>
#include <iostream>
#include "Color.h"
#include "Complex.h"
#include "MyRectangle.h"

using namespace std;
class Mandelbrot
{
	public:
		double minReal;
		double maxReal;
		double minImg;
		double maxImg;

		int screenWidth, screenHeight;
		float scale;

		float zoom_factor;
		int iteration;
		//bool isChanged;
		//int last_iteration;
		vector<Color> points;

	public:
		Mandelbrot(void);
		Mandelbrot(int _screenWidth, int _screenHeigh);
		~Mandelbrot(void);
		void draw();
		void zoom(float _minReal, float _maxReal, float _minImg, float _maxImg);
		void resize(MyRectangle rect);
	private:
		void createPointSet();
		
};

