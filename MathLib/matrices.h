#pragma once
#include "vec3.h"
#include "vec4.h"
struct mat3
{
	union
	{
		struct
		{
			vec3 xAxis;
			vec3 yAxis;
			vec3 zAxis;
		};
		vec3 axis[3];
		
		struct 
		{
			float m1, m2, m3,
				  m4, m5, m6,
				  m7, m8, m9;
		};
		struct
		{
			float m[9];
		};
		struct 
		{
			float mm[3][3];
		};
	};
	mat3();
	mat3(float *ptr);
	mat3(float m1, float m2, float m3, 
		 float m4, float m5, float m6,
		 float m7, float m8, float m9);
};