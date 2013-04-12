#pragma once

#include<math.h>
#include<iostream>

using namespace std;
struct Vector3f
{
	float x,y,z;
	Vector3f(){}
	Vector3f(float _x,float _y,float _z){
		x = _x; y = _y; z = _z;
	}
	void Normalize(){
		double ratio = 1/Length();
		x *= (float)ratio;
		y *= (float)ratio;
		z *= (float)ratio;
	}
	inline double Length(){
		return sqrt(x*x + y*y + z*z);
	}

	Vector3f operator + ( const Vector3f & rhs ) const {
		return( Vector3f( x + rhs.x, y + rhs.y, z + rhs.z ) );		
	}

	Vector3f operator - (const Vector3f & rhs) const{
		return( Vector3f( x - rhs.x, y - rhs.y, z - rhs.z ) );
	}

	Vector3f operator * (float k) const{
		return( Vector3f( x * k, y * k, z * k ) );
	}
	void operator = (const Vector3f & rhs){
		x = rhs.x; y = rhs.y; z = rhs.z;
	}
	bool operator == (const Vector3f &rhs){
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}

	static float dot(Vector3f & lhs, Vector3f & rhs){
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
	}
	static Vector3f cross(const Vector3f & lhs, const Vector3f & rhs ) {

		return( Vector3f( lhs.y * rhs.z - lhs.z * rhs.y, 
						  lhs.z * rhs.x - lhs.x * rhs.z,
					      lhs.x * rhs.y - lhs.y * rhs.x ) );
	}
	void print(){
		cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
	}
};

