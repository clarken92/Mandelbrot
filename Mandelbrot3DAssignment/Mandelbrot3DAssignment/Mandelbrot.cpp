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
//Coi cac bien la global, tang toc do
float nx,ny,nz;
Vector3f t,v;
Color color;

double r, dr, r8, theta, phi;
double distance_estimation;

int k,step;
float escape_distance;

//Ham global
void update(){
	dr=dr*8*pow(r,7)+1; 
	r = v.Length();

	r8 = pow(r,8);
	phi = atan(v.y/v.x) * 8;
	//theta = atan(sqrt(v.x*v.x + v.y*v.y)/v.z);
	//theta = acos(v.z / r);
	theta = acos(v.z / r) * 8;
	
	//theta = atan(v.x/v.z) * 4;
	//theta = atan(v.x/v.z) * 8;

	//Classic
	//nx = cos(theta) * cos(phi) * r8;
	//ny = cos(theta) * sin(phi) * r8;
	//nz = -sin(theta) * r8;
	
	//Positive z-Component
	//nx = cos(theta) * cos(phi) * r8;
	//ny = sin(theta) * cos(phi) * r8;
	//nz = sin(theta) * r8;

	//Cosine (Mandelbulb)
	nx = sin(theta) * cos(phi) * r8;
	ny = sin(theta) * sin(phi) * r8;
	nz = cos(theta) * r8;
	
	//Rudy checker
	//theta = atan(v.z/v.x)*8;
	//nx = cos(theta) * cos(phi) * r8;
	//ny = cos(theta) * sin(phi) * r8;
	//nz = sin(theta) * r8;

	//Unknow
	//nx = cos(theta) * cos(phi) * r8;
	//ny = sin(theta) * cos(phi) * r8;
	//nz = cos(theta) * r8;

	v.x = nx + t.x;
	v.y = ny + t.y;
	v.z = nz + t.z;
}
void Mandelbrot::setPointsAndColors(){
	points.push_back(t);
	color.red = color.green = color.blue = (float)k/step;
	//color.red = (t.x-minX) / (maxX - minX); color.green = (t.y - minY)/ (maxY - minY);
	//color.blue = (t.z-minZ) / (maxZ-minZ);
	//color.alpha = (float)k/step;
	color.alpha = 1.0f;
	point_colors.push_back(color);
}

	//Phuong phap distance estimator
void Mandelbrot::createPointSet(){
	step = 100;
	escape_distance = 0.00001;
	
	int i,j,n;
	int threadNumber = 6;

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
					update();
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					setPointsAndColors();
					break;
				}
				else {
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
					update();
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					setPointsAndColors();
					break;
				}
				else {
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
					update();
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					setPointsAndColors();
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
					
					update();
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					setPointsAndColors();
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
					update();
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					setPointsAndColors();
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
					update();
				}

				distance_estimation = 0.5*log(r)*r/dr;
				if(distance_estimation < escape_distance){
					setPointsAndColors();
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

//Phuong phap co dien (cham, phai chay multithread)
/*
void Mandelbrot::createPointSet(){
	float x,y,z;
	float temp_x, temp_y, temp_z;
	double xsquare, ysquare, zsquare;
	double r, theta, phi, power, sinThetaOrder;
	
	bool lastIn = false, firstPoint;
	int iter;
	
	Vector3f v;
	Color c;

	for(float z0 = minZ; z0 < maxZ; z0 += zFactor){
		for(float x0 = minX; x0 < maxX; x0 += xFactor){
			for(float y0 = minY; y0 < maxY; y0 += yFactor){
				x=y=z=0;
				iter = 0;

				while(true){
					xsquare = x*x;
					ysquare = y*y;
					zsquare = z*z;

					temp_x = x; temp_y = y; temp_z = z;
					r = sqrt(xsquare + ysquare + zsquare);

					theta = atan2(sqrt(xsquare + ysquare), (double)z);
					phi = atan2(y,x);
					power = pow(r,order);

					sinThetaOrder = sin(theta * order);
					x = power * sinThetaOrder * cos(phi*order);
					y = power * sinThetaOrder * sin(phi*order);
					z = power * cos(theta * order);

					x += x0; y += y0; z += z0;
					iter++;

					if(iter > iteration){
						if (!lastIn){
                            v.z = z0; v.x = x0; v.y = y0;
							c.red = 1.0f ; c.green=1.0f ; c.blue = 1.0f;
							if (!firstPoint) { 
								point_colors.push_back(c);
								points.push_back(v); 
							}
                            lastIn = true;
                        }
                        firstPoint = false;
                        break;
					}

					if ((xsquare + ysquare + zsquare) > bail){
                        if (lastIn){
                            v.z = z0; v.x = x0; v.y = y0;
							c.red = 1.0f ; c.green=1.0f ; c.blue = 1.0f;
							if (!firstPoint) { points.push_back(v); }
                            lastIn = false;
                        }
                        firstPoint = false;
                        break;
                    }
				}
			}
		}
	}
}
*/

void Mandelbrot::draw(){
	glBegin(GL_POINTS);

	//glColor3f(1.0f,1.0f,1.0f);
	for(unsigned int i=0;i<points.size();i++){
		glColor4f(point_colors[i].red,point_colors[i].green, point_colors[i].blue, point_colors[i].alpha);
		glNormal3f(points[i].x,points[i].y,points[i].z);
		glVertex3f(points[i].x,points[i].y,points[i].z);
	}
	glEnd();
}
