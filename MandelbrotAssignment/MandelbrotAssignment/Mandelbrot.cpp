#include "StdAfx.h"

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include "Mandelbrot.h"
Mandelbrot::Mandelbrot(void)
{
}

Mandelbrot::Mandelbrot(int _screenWidth, int _screenHeight){
	minReal = -2.0; maxReal = 1.0;
	
	screenWidth = _screenWidth; screenHeight = _screenHeight;
	scale = (maxReal - minReal)/screenWidth;

	float ratio = (float)screenWidth/(float)screenHeight;
	double ImgRange = (maxReal - minReal) / ratio;
	minImg = - ImgRange/2; maxImg = ImgRange/2;

	iteration = 32;
	cout<<"Initial iteration: "<<iteration<<endl;
	zoom_factor = 1.0f;

	createPointSet();	
	//isChanged = true;
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

	c.img = minImg;
	for(row = 0; row < screenHeight; row++){
		//c.img = minImg + row * scale;
		c.real = minReal;
		for(col = 0; col < screenWidth; col++){
			//c.real = minReal + col * scale;
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
			else { color.red = color.green = color.blue = 0.0f; }
			points.push_back(color);

			c.real += scale;
		}
		c.img += scale;
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

void Mandelbrot::zoom(float _minReal, float _maxReal, float _minImg, float _maxImg){
	float ratio = (float)screenWidth/(float)screenHeight;
	float new_ratio = (_maxReal - _minReal)/(_maxImg - _minImg);
	
	if (new_ratio > ratio) {
		minImg = _minImg; maxImg = _maxImg;
		scale = (maxImg - minImg)/screenHeight;
		minReal = _minReal; maxReal = minReal + (maxImg - minImg) * ratio;
	}
	
	else{
		minReal = _minReal; maxReal = _maxReal; 
		scale = (maxReal - minReal)/screenWidth;
		minImg = _minImg; maxImg = minImg + (maxReal - minReal) / ratio;
	}

	//double ImgRange = (maxReal - minReal) / ratio;
	points.clear();
	createPointSet();
}

void Mandelbrot::resize(MyRectangle rect){
	float ratio = (float)screenWidth/(float)screenHeight;
	rect.Standardlize(ratio);
	//cout<<"Standarlized: ("<<rect.left()<<","<<rect.top()<<"), ("<<rect.right()<<","<<rect.bottom()<<")"<<endl;

	//cout<<"Old min real: "<<minReal<<"  Old max real: "<<maxReal<<endl;
	//double realRange = (maxReal - minReal)/screenWidth;
	double newMinReal = minReal + rect.left() * scale;//realRange;
	double newMaxReal = minReal + rect.right() * scale; //realRange;
	minReal = newMinReal; maxReal = newMaxReal;
	//cout<<"New min real: "<<minReal<<"  New max real: "<<maxReal<<endl;

	//cout<<"Old min img: "<<minImg<<"  Old max img: "<<maxImg<<endl;
	//double imgRange = (maxImg - minImg)/screenHeight;
	double newMinImg = minImg + rect.bottom() * scale;//imgRange;
	double newMaxImg = minImg + rect.top() * scale;//imgRange;
	minImg = newMinImg; maxImg = newMaxImg;
	//cout<<"New min img: "<<minImg<<"  New max img: "<<maxImg<<endl;

	scale = (maxReal - minReal)/screenWidth;	
	zoom_factor = (1.0 + 2.0)/(maxReal - minReal);
	iteration = (int)(sqrt(abs(2*sqrt(abs(1-sqrt(5*zoom_factor)))))*66.5);
	
	cout<<"Iteration after zooming: "<<iteration<<endl;

	points.clear();
	createPointSet();

	//isChange = true;
}