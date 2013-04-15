#pragma once

struct Complex{
	double real,img;
	
	Complex(){}
	Complex(double _real,double _img){
		real = _real; img = _img;
	}
	Complex(const Complex& c){
		real = c.real; img = c.img;
	}

	//Phan operator
	Complex operator+(const Complex& rhs) const{
		return Complex(real + rhs.real, img + rhs.img);
	}
	Complex operator-(const Complex& rhs) const{
		return Complex(real - rhs.real, img - rhs.img);
	}
	Complex operator*(const Complex& rhs) const{
		double r = real * rhs.real - img * rhs.img;
		double i = real * rhs.img + img * rhs.real;
		return Complex(r,i);
	}
	Complex operator/(const Complex& rhs) const{
		Complex conjugate_rhs(rhs.real, -rhs.img);
		Complex top = (*this) * conjugate_rhs;
		double bottom = rhs.real * rhs.real + rhs.img * rhs.img;

		top.real /= bottom; top.img /= bottom;
		return top;
	}

	Complex& operator=(const Complex& rhs){
		real = rhs.real; img = rhs.img;
		return (*this);
	}
	void operator += (const Complex& rhs){
		real += rhs.real; img += rhs.img;
	}
	void operator -= (const Complex& rhs){
		real -= rhs.real; img -= rhs.img;
	}
	void operator *= (const Complex& rhs){
		double r = real * rhs.real - img * rhs.img;
		double i = real * rhs.img + img * rhs.real;
		real = r; img =i;
	}
	void operator /= (const Complex& rhs){
		Complex conjugate_rhs(rhs.real, -rhs.img);
		Complex top = (*this) * conjugate_rhs;
		double bottom = rhs.real * rhs.real + rhs.img * rhs.img;

		top.real /= bottom; top.img /= bottom;
		real = top.real; img = top.img;
	}

	bool operator<(const Complex &rhs) const {
		return (real < rhs.real) || (real == rhs.real && img < rhs.img);
	}

	bool operator>(const Complex &rhs) const {
		return rhs < *this; 
	}

	bool operator<=(const Complex &rhs) const {
		return (real <= rhs.real) || (real == rhs.real && img <= rhs.img);
	}

	bool operator>=(const Complex &rhs) const {
		return rhs <= *this; 
	}

	bool operator==(const Complex &rhs) const {
		return (real == rhs.real && img == rhs.img);
	}

	bool operator!=(const Complex &rhs) const {
		return (real != rhs.real || img != rhs.img);
	}

	double DistanceSquare(){
		return real*real + img *img;
	}
};