#include "vec3.h"

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

vec3::vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	vec3 vec;
	vec.x = x + rhs.x;
	vec.y = y + rhs.y;
	vec.z = z + rhs.z;
	return vec;
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	vec3 vec;
	vec.x = x - rhs.x;
	vec.y = y - rhs.y;
	vec.z = z - rhs.z;
	return vec;
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

bool vec3::operator==(const vec3 & rhs) const
{
	return ((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
			(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON)) &&
			(z >= (rhs.z - FLT_EPSILON) && z <= (rhs.z + FLT_EPSILON)));
}

bool vec3::operator!=(const vec3 & rhs) const
{
	return !((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
			(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON)) &&
			(z >= (rhs.z - FLT_EPSILON) && z <= (rhs.z + FLT_EPSILON)));
}

vec3 vec3::operator-() const
{
	vec3 neg;
	neg.x = -x;
	neg.y = -y;
	neg.z = -z;
	return neg;
}

vec3::operator float*()
{
	return *this;
}

vec3::operator const float*() const
{
	return *this;
}

float vec3::magnitude() const
{
	float magnitude = (x * x + y * y + z * z);
	magnitude = pow(magnitude, .5);
	return magnitude;
}

vec3 & vec3::normalize()
{
	vec3 norma = getNormalized();
	x = norma.x;
	y = norma.y;
	z = norma.z;
	return *this;
}

vec3 vec3::getNormalized() const
{
	vec3 normal;
	float mag = magnitude();
	normal.x = x / mag;
	normal.y = y / mag;
	normal.z = z / mag;
	return normal;
}

vec3 & vec3::scale(const vec3 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	vec3 scaled{ x,y,z };
	scaled *= rhs.x;
	scaled *= rhs.y;
	scaled *= rhs.z;
	return scaled;
}

vec3 vec3::operator*(const float rhs) const
{
	vec3 multi{ x,y,z };
	multi.x *= rhs;
	multi.y *= rhs;
	multi.z *= rhs;
	return multi;
}

vec3 & vec3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

float vec3::dot(const vec3 & rhs) const
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
}

vec3 vec3::cross(const vec3 & rhs) const
{
	return vec3{((y * rhs.z) - (z * rhs.y)), ((z * rhs.x) - (x * z)), ((x * rhs.y) - (y * rhs.x)) };
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 temp{ rhs.x,rhs.y,rhs.z };
	temp.x = rhs.x * lhs;
	temp.y = rhs.y * lhs;
	temp.z = rhs.z * lhs;
	return temp;
}
