#pragma once
struct Light
{
	float position[4];
	float diffuse[4];
	float spot_cutoff;
	float linear_attenuation;
	float spot_direction[3];
	
};

