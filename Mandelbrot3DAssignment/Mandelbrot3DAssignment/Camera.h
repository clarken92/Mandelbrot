#pragma once

#include "Vector3f.h"
class Camera
{
	public: 
		Vector3f eye;
		Vector3f u,v,n;
		float aspect, nearDist, farDist, viewAngle, W, H;
		int nRows, nCols;
	public:
		Camera(void);
		~Camera(void);
		void roll(float angle);
		void pitch(float angle);
		void yaw(float angle);
		void slide(float du, float dv, float dn);
		void setLookAt(Vector3f _eye, Vector3f _look, Vector3f _up);
		void setLookAt(float eye_x,float eye_y,float eye_z, float look_x, float look_y, float look_z, float up_x, float up_y, float up_z);
		void setPerspective(float _viewAngle, float _aspect, float _nearDist, float _farDist);
		void setDisplay(int _nRows,int _nCols);
		void setDefaultCamera();
	private:
		//Xoay 2 vector theo mot goc xung quanh vector vuong goc voi 2 vector nay
		void rotateAxes(Vector3f& a, Vector3f& b, float angle);
		void setModelViewMatrix();
		void setProjectionMatrix();
};

