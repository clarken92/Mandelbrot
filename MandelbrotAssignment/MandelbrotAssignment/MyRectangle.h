#pragma once

#include <math.h>
struct MyRectangle{
	int x1, y1, x2, y2;

	MyRectangle(){x1=0; y1=0; x2=1; y2=1;}
	MyRectangle(int _x1, int _y1, int _x2, int _y2){
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;
	}

	int height(){ return abs(y2 - y1); }
	int width(){ return abs(x2 - x1); }

	float ratio(){
		int h = height(); int w = width();
		if(h>0) { return (float)w/(float)h; }
		else { return -1.0f; }
	}
	void reset(){
		x1=0; y1=0; x2=1; y2=1;
	}

	int left(){ return min(x1,x2); }
	int right() { return max(x1,x2); }
	int top() { return max(y1,y2); }
	int bottom() { return min(y1,y2); }

	void Standardlize(float _ratio){		
		int _x1 = min(x1,x2); int _x2 = max(x1,x2);
		int _y1 = min(y1,y2); int _y2 = max(y1,y2);

		x1 = _x1; x2 = _x2; y1 = _y1; y2 =_y2;

		int width = x2 - x1; int height = y2 - y1;
		
		float ratio = (float)width/(float)height;
		if(ratio > _ratio) {
			x2 = ceil(x1 + height * _ratio);
		}
		else {
			y2 = ceil(y1 + width/ _ratio);
		}
	}
};