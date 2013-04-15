#pragma once

#include <math.h>
struct Color{
	float red,green,blue;

	Color(){}
	Color(float r, float g, float b){
		red = r; green = g; blue = b;
	}
	static Color HueToRGB(float hue){
		hue = fmodf(hue,360.0f);
		Color color(0.0f,0.0f,0.0f);

		//Chia lam 6 mien
		float h = hue/60;
		float t = (1 - fabs(fmodf(h, 2) - 1));
		switch((int)h){
			case 0:
				color.red = 1.0f; color.green = t; break;
			case 1:
				color.red = t; color.green = 1.0f; break;
			case 2:
				color.green = 1.0f; color.blue = t; break;
			case 3:
				color.green = t; color.blue = 1.0f; break;
			case 4:
				color.blue = 1.0f; color.red = t; break;
			case 5:
				color.blue = t; color.red = 1.0f; break;
			default:
				break;
		}
		return color;
	}
};