#include "StdAfx.h"

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include "Mandelbrot.h"
Mandelbrot::Mandelbrot(void)
{
}

Mandelbrot::Mandelbrot(int _xRange, int _yRange, int _zRange, int _iteration){
	minX = -1.5f; maxX = 1.5f;
	minY = -1.5f; maxY = 1.5f;
	minZ = -1.5f; maxZ = 1.5f;
	
	xRange = _xRange; yRange = _yRange; zRange = _zRange;
	xFactor = (maxX-minX)/ xRange; yFactor = (maxY-minY)/ yRange; zFactor = (maxZ-minZ)/ zRange;

	iteration = _iteration;
	createPointSet();
	cout<<"So luong point: " << points.size()<<endl;
}

Mandelbrot::~Mandelbrot(void)
{
}

void Mandelbrot::createPointSet(){
	int step = 100;
	double escape_distance = 0.00001;

	int i, j, k, n;
	Vector3f t,sym_t,v;
	Color color;

	double r, dr, r8, theta, phi;
	double distance_estimation;
	float nx,ny,nz;

	//Distance estimator cho truc Z
	t.y = minY;
	for(j = 0; j < yRange; j++){
		t.x = minX;
		for(i = 0; i < xRange; i++){		
			//Distance estimation theo huong am
			t.z = minZ;
			for(k = step; k > 0 && t.z < maxZ; k--){				
				v = t;
				dr = 1.0; r = 0.0;

				for(n = 0; n < iteration;n++){
					if( r > 2.0) { break; }					
					
					dr=dr*8*pow(r,7)+1; 
					r = v.Length();

					r8 = pow(r,8);
					phi = atan(v.y/v.x) * 8;
					theta = acos(v.z / r) * 8;

					nx = sin(theta) * cos(phi) * r8;
					ny = sin(theta) * sin(phi) * r8;
					nz = cos(theta) * r8;

					v.x = nx + t.x;
					v.y = ny + t.y;
					v.z = nz + t.z;
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					points.push_back(t);
					color.red = color.green = color.blue = (float)k/step;
					point_colors.push_back(color);
					break;
				}
				else { 
					//k--;
					t.z += distance_estimation;
				}
			}
			//Distance estimation theo huong duong
			t.z = maxZ;
			for(k = step; k > 0 && t.z > minZ; k--){				
				v = t;
				dr = 1.0; r = 0.0;
				for(n = 0; n < iteration;n++){
					if( r > 2.0) { break; }

					dr=dr*8*pow(r,7)+1; 
					r = v.Length();

					r8 = pow(r,8);
					phi = atan(v.y/v.x) * 8;
					theta = acos(v.z / r) * 8;

					nx = sin(theta) * cos(phi) * r8;
					ny = sin(theta) * sin(phi) * r8;
					nz = cos(theta) * r8;

					v.x = nx + t.x;
					v.y = ny + t.y;
					v.z = nz + t.z;
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					points.push_back(t);
					color.red = color.green = color.blue = (float)k/step;
					point_colors.push_back(color);
					break;
				}
				else { 
					//k--;
					t.z -= distance_estimation;
				}
			}

			t.x += xFactor;
		}
		t.y += yFactor;
	}

	//Distance estimator cho truc y
	t.x = minX;
	for(j = 0; j < xRange; j++){
		t.z = minZ;
		for(i = 0; i < zRange; i++){
			t.y = minY;
			for(k = step; k > 0 && t.y < maxY; k--){				
				v = t;
				dr = 1.0; r = 0.0;

				for(n = 0; n < iteration;n++){
					if( r > 2.0) { break; }					
					
					dr=dr*8*pow(r,7)+1; 
					r = v.Length();

					r8 = pow(r,8);
					phi = atan(v.y/v.x) * 8;
					theta = acos(v.z / r) * 8;

					nx = sin(theta) * cos(phi) * r8;
					ny = sin(theta) * sin(phi) * r8;
					nz = cos(theta) * r8;

					v.x = nx + t.x;
					v.y = ny + t.y;
					v.z = nz + t.z;
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					points.push_back(t);
					color.red = color.green = color.blue = (float)k/step;
					point_colors.push_back(color);
					break;
				}
				else { 
					t.y += distance_estimation;
				}
			}

			t.y = maxY;
			for(k = step; k > 0 && t.y > minY; k--){				
				v = t;
				dr = 1.0; r = 0.0;

				for(n = 0; n < iteration;n++){
					if( r > 2.0) { break; }					
					
					dr=dr*8*pow(r,7)+1; 
					r = v.Length();

					r8 = pow(r,8);
					phi = atan(v.y/v.x) * 8;
					theta = acos(v.z / r) * 8;

					nx = sin(theta) * cos(phi) * r8;
					ny = sin(theta) * sin(phi) * r8;
					nz = cos(theta) * r8;

					v.x = nx + t.x;
					v.y = ny + t.y;
					v.z = nz + t.z;
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					points.push_back(t);
					color.red = color.green = color.blue = (float)k/step;
					point_colors.push_back(color);
					break;
				}
				else { 
					t.y -= distance_estimation;
				}
			}

			t.z += zFactor;
		}
		t.x += xFactor;
	}

	//Distance estimator cho truc x
	t.z = minZ;
	for(j = 0; j < zRange; j++){
		t.y = minY;
		for(i = 0; i < yRange; i++){
			t.x = minX;
			for(k = step; k > 0 && t.x < maxX; k--){				
				v = t;
				dr = 1.0; r = 0.0;

				for(n = 0; n < iteration;n++){
					if( r > 2.0) { break; }					
					
					dr=dr*8*pow(r,7)+1; 
					r = v.Length();

					r8 = pow(r,8);
					phi = atan(v.y/v.x) * 8;
					theta = acos(v.z / r) * 8;

					nx = sin(theta) * cos(phi) * r8;
					ny = sin(theta) * sin(phi) * r8;
					nz = cos(theta) * r8;

					v.x = nx + t.x;
					v.y = ny + t.y;
					v.z = nz + t.z;
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					points.push_back(t);
					color.red = color.green = color.blue = (float)k/step;
					point_colors.push_back(color);
					break;
				}
				else { 
					t.x += distance_estimation;
				}
			}

			t.x = maxX;
			for(k = step; k > 0 && t.x > minX; k--){				
				v = t;
				dr = 1.0; r = 0.0;

				for(n = 0; n < iteration;n++){
					if( r > 2.0) { break; }					
					
					dr=dr*8*pow(r,7)+1; 
					r = v.Length();

					r8 = pow(r,8);
					phi = atan(v.y/v.x) * 8;
					theta = acos(v.z / r) * 8;

					nx = sin(theta) * cos(phi) * r8;
					ny = sin(theta) * sin(phi) * r8;
					nz = cos(theta) * r8;

					v.x = nx + t.x;
					v.y = ny + t.y;
					v.z = nz + t.z;
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					points.push_back(t);
					color.red = color.green = color.blue = (float)k/step;
					point_colors.push_back(color);
					break;
				}
				else { 
					t.x -= distance_estimation;
				}
			}

			t.y += yFactor;
		}
		t.z += zFactor;
	}
}

void Mandelbrot::draw(){
	glBegin(GL_POINTS);

	for(unsigned int i=0;i<points.size();i++){
		glColor3f(point_colors[i].red,point_colors[i].green, point_colors[i].blue);
		glVertex3f(points[i].x,points[i].y,points[i].z);
	}
	glEnd();
}
