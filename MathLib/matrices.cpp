#include "matrices.h"
#include <cmath>
mat3::mat3()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

mat3::mat3(float * ptr)
{ 
	for (int i = 0; i < 9; ++i)
	{
		m[i] = ptr[i];
	}
}

mat3::mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
}

mat3::operator float*()
{
	float temp[9];
	for (int i = 0; i < 9; ++i)
	{
	temp[i] = m[i];
	}
	return temp;
}

vec3 & mat3::operator[](const int index)
{
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 result;
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			result.mm[c][r] = mm[0][r] * rhs.mm[c][0] +
				mm[1][r] * rhs.mm[c][1] +
				mm[2][r] * rhs.mm[c][2];
		}
	}
	return result;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			mm[c][r] = mm[0][r] * rhs.mm[c][0] +
				mm[1][r] * rhs.mm[c][1] +
				mm[2][r] * rhs.mm[c][2];
		}
	}
	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			if (!mm[c][r] == rhs.mm[c][r])
			{
				return false;
			}
		}
	}
	return true;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	int count = 0;
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			if (!mm[c][r] == rhs.mm[c][r])
			{
				++count;
			}
		}
	}
	if (count == 9)
	{
		return false;
	}
	return true;
}

mat3 mat3::identity()
{
	return mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
}

void mat3::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
}

void mat3::set(float * ptr)
{
	for (int i = 0; i < 9; ++i)
	{
		m[i] = ptr[i];
	}
}

void mat3::transpose()
{
	mat3 result = getTranspose();

	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			mm[c][r] = result.mm[r][c];
		}
	}
}

mat3 mat3::getTranspose() const
{
	mat3 result;
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			result.mm[r][c] = mm[c][r];
		}
	}
	return result;
}

mat3 mat3::translation(float x, float y)
{
	mat3 trans;
	trans.mm[2][0] = x;
	trans.mm[2][1] = y;
	return trans;
}

mat3 mat3::translation(const vec2 & vec)
{
	mat3 trans;
	trans.mm[2][0] = vec.x;
	trans.mm[2][1] = vec.y;
	return trans;
}

mat3 mat3::rotation(float rot)
{
	mat3 rotation;
	rotation.mm[0][0] = cos(rot);
	rotation.mm[1][0] = sin(rot);
	rotation.mm[0][1] = -sin(rot);
	rotation.mm[1][1] = cos(rot);
	return rotation;
}

mat3 mat3::scale(float xScale, float yScale)
{
	mat3 scale;
	scale.mm[0][0] = xScale;
	scale.mm[1][1] = yScale;
	return scale;
}

mat3 mat3::scale(const vec2 & vec)
{
	mat3 scale;
	scale.mm[0][0] = vec.x;
	scale.mm[1][1] = vec.y;
	return scale;
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 temp;

	for (int i = 0; i < 3; ++i)
	{
		temp.x += (mm[0][i] * rhs.x);
	}
	for (int i = 0; i < 3; ++i)
	{
		temp.y += (mm[1][i] * rhs.y);
	}
	for (int i = 0; i < 3; ++i)
	{
		temp.z += (mm[2][i] * rhs.z);
	}
	return temp;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	vec2 temp;

	for (int i = 0; i < 3; ++i)
	{
		temp.x += (mm[0][i] * rhs.x);
	}
	for (int i = 0; i < 3; ++i)
	{
		temp.y += (mm[1][i] * rhs.y);
	}
	return temp;
}
