#pragma once
#include "GlobalVariables.h"
struct Light
{
	float position[4];
	float diffuse[4];
	float spot_cutoff;
	float linear_attenuation;
	float spot_direction[3];
	//Huong chuyen dong cua anh sang
	float move_direction[3];
	float speed;
	float source_color[4];
	
	void init(){
		double length = sqrt(move_direction[0]*move_direction[0]+
							move_direction[1]*move_direction[1]+
							move_direction[2]*move_direction[2]);
		
		move_direction[0]= move_direction[0]/length;
		move_direction[1]= move_direction[1]/length;
		move_direction[2]= move_direction[2]/length;
	}
	void update(float elapsedSecond){
		const float half_box_size_1 = BOX_SIZE_1/2;
		const float half_box_size_2 = BOX_SIZE_2/2;

		position[0] += speed * move_direction[0] * elapsedSecond;
		position[1] += speed * move_direction[1] * elapsedSecond;
		position[2] += speed * move_direction[2] * elapsedSecond;

		if(	position[0] > half_box_size_1 - LIGHT_OBJECT_RADIUS ||
			position[0] < -(half_box_size_1 - LIGHT_OBJECT_RADIUS)){
			move_direction[0] = -move_direction[0];
		}
		if( position[1] > half_box_size_1 - LIGHT_OBJECT_RADIUS ||
			position[1] < -(half_box_size_1 - LIGHT_OBJECT_RADIUS)){
			move_direction[1] = -move_direction[1];
		}
		if( position[2] > half_box_size_2 - LIGHT_OBJECT_RADIUS ||
			position[2] < -(half_box_size_2 - LIGHT_OBJECT_RADIUS)){
			move_direction[2] = -move_direction[2];
		}
		spot_direction[0] = move_direction[0];
		spot_direction[1] = move_direction[1];
		spot_direction[2] = move_direction[2];
	}
};

