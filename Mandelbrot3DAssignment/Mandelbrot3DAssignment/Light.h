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
	float velocity[3];
	
	void update(float elapsedSecond){
		const float half_box_size_1 = BOX_SIZE_1/2;
		const float half_box_size_2 = BOX_SIZE_2/2;

		position[0] += velocity[0] * elapsedSecond;
		position[1] += velocity[1] * elapsedSecond;
		position[2] += velocity[2] * elapsedSecond;

		if(	position[0] > half_box_size_1 - LIGHT_OBJECT_RADIUS ||
			position[0] < -(half_box_size_1 - LIGHT_OBJECT_RADIUS)){
			velocity[0] = -velocity[0];
		}
		if( position[1] > half_box_size_1 - LIGHT_OBJECT_RADIUS ||
			position[1] < -(half_box_size_1 - LIGHT_OBJECT_RADIUS)){
			velocity[1] = -velocity[1];
		}
		if( position[2] > half_box_size_2 - LIGHT_OBJECT_RADIUS ||
			position[2] < -(half_box_size_2 - LIGHT_OBJECT_RADIUS)){
			velocity[2] = -velocity[2];
		}

	}
};

