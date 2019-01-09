#include "vec4.h"

vec4::vec4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

vec4::vec4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	vec4 vec;
	vec.x = x + rhs.x;
	vec.y = y + rhs.y;
	vec.z = z + rhs.z;
	vec.w = w + rhs.w;
	return vec;
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	vec4 vec;
	vec.x = x - rhs.x;
	vec.y = y - rhs.y;
	vec.z = z - rhs.z;
	vec.w = w - rhs.w;
	return vec;
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

bool vec4::operator==(const vec4 & rhs) const
{
	return ((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
			(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON)) &&
			(z >= (rhs.z - FLT_EPSILON) && z <= (rhs.z + FLT_EPSILON)) &&
			(w >= (rhs.w - FLT_EPSILON) && w <= (rhs.w + FLT_EPSILON)));
}

bool vec4::operator!=(const vec4 & rhs) const
{
	return !((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
			(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON)) &&
			(z >= (rhs.z - FLT_EPSILON) && z <= (rhs.z + FLT_EPSILON)) &&
			(w >= (rhs.w - FLT_EPSILON) && w <= (rhs.w + FLT_EPSILON)));
}

vec4 vec4::operator-() const
{
	vec4 neg;
	neg.x = -x;
	neg.y = -y;
	neg.z = -z;
	neg.w = -w;
	return neg;
}

vec4::operator float*()
{
	return *this;
}

vec4::operator const float*() const
{
	return *this;
}

float vec4::magnitude() const
{
	float magnitude = (x * x + y * y + z * z + w * w);
	magnitude = pow(magnitude, .5);
	return magnitude;
}

vec4 & vec4::normalize()
{
	vec4 norma = getNormalized();
	x = norma.x;
	y = norma.y;
	z = norma.z;
	w = norma.w;
	return *this;
}

vec4 vec4::getNormalized() const
{
	vec4 normal;
	float mag = magnitude();
	normal.x = x / mag;
	normal.y = y / mag;
	normal.z = z / mag;
	normal.w = w / mag;
	return normal;
}

vec4 & vec4::scale(const vec4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	vec4 scaled{ x,y,z,w };
	scaled *= rhs.x;
	scaled *= rhs.y;
	scaled *= rhs.z;
	scaled *= rhs.w;
	return scaled;
}

vec4 vec4::operator*(const float rhs) const
{
	vec4 multi{ x,y,z,w };
	multi.x *= rhs;
	multi.y *= rhs;
	multi.z *= rhs;
	multi.w *= rhs;
	return multi;
}

vec4 & vec4::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;
	return *this;
}

vec4 & vec4::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;
	return *this;
}

float vec4::dot(const vec4 & rhs) const
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w));
}

vec4 vec4::cross(const vec4 & rhs) const
{
	return vec4{ ((y * rhs.z) - (z * rhs.y)), ((z * rhs.x) - (x * z)), ((x * rhs.y) - (y * rhs.x)), 0 };
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	vec4 temp{ rhs.x,rhs.y,rhs.z,rhs.w };
	temp.x = rhs.x * lhs;
	temp.y = rhs.y * lhs;
	temp.z = rhs.z * lhs;
	temp.w = rhs.w * lhs;
	return temp;
}
