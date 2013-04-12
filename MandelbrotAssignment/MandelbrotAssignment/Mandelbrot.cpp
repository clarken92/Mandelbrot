#include "StdAfx.h"

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include <iostream>

#include "Mandelbrot.h"
using namespace std;
Mandelbrot::Mandelbrot(void)
{
}

Mandelbrot::Mandelbrot(int _screenWidth, int _screenHeight, int _iteration){
	minReal = -2.0; maxReal = 1.0;
	
	screenWidth = _screenWidth; screenHeight = _screenHeight;
	scale = (maxReal - minReal)/_screenWidth;

	float ratio = (float)_screenWidth/(float)_screenHeight;
	double ImgRange = (maxReal - minReal) / ratio;
	minImg = - ImgRange/2; maxImg = ImgRange/2;

	iteration = _iteration;
	createPointSet();
}

Mandelbrot::~Mandelbrot(void)
{
}

void Mandelbrot::createPointSet(){
	int row, col, n;
	Complex c, z;

	Color color;
	double log2 = log(2.0);
	double smooth_value;

	for(row = 0; row < screenHeight; row++){
		c.img = minImg + row * scale;
		for(col = 0; col < screenWidth; col++){
			c.real = minReal + col * scale;

			z.real = 0; z.img = 0;
			//Vong lap kiem tra 1 diem co thuoc Mandelbrot set khong
			for(n = 0; n < iteration; n++){
				if(z.DistanceSquare() > 4){
					break;
				}
				z = z * z + c;
			}
			
			//Neu khong thuoc set
			if(n < iteration) { 
				smooth_value = (n + 1 - log(log(z.DistanceSquare())/2)/log2)/iteration;
				color =  Color::HueToRGB(smooth_value*360);
			}
			//Neu thuoc set thi cho mau den
			else { color.red = 0.0f; color.green = 0.0f; color.blue = 0.0f; }
			points.push_back(color);
		}
	}
}

void Mandelbrot::draw(){
	glBegin(GL_POINTS);
	vector<Color>::iterator it = points.begin();
	for(int j=0 ;j<screenHeight; j++){
		for(int i=0; i<screenWidth; i++){
			glColor3f(it->red,it->green,it->blue);
			glVertex2i(i,j);
			it++;
		}
	}
	glEnd();
}
