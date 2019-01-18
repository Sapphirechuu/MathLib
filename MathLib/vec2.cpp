#include "vec2.h"

vec2::vec2()
{
	x = 0;
	y = 0;
}

vec2::vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	vec2 vec;
	vec.x = x + rhs.x;
	vec.y = y + rhs.y;

	return vec;
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	vec2 vec;
	vec.x = x - rhs.x;
	vec.y = y - rhs.y;
	return vec;
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

bool vec2::operator==(const vec2 & rhs) const
{
	return ((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
		(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON)));
}

bool vec2::operator!=(const vec2 & rhs) const
{
	return ((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
		(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON)));
}

vec2 vec2::operator-() const
{
	vec2 neg;
	neg.x = -x;
	neg.y = -y;
	return neg;
}

vec2::operator float*()
{
	return &x;
}

vec2::operator const float*() const
{
	return &x;
}

float vec2::magnitude() const
{
	float magnitude = (x * x + y * y);
	magnitude = pow(magnitude, .5);
	return magnitude;
}

vec2 & vec2::normalize()
{
	vec2 norma = getNormalized();
	x = norma.x;
	y = norma.y;
	return *this;
}

vec2 vec2::getNormalized() const
{
	vec2 normal;
	float mag = magnitude();
	normal.x = x / mag;
	normal.y = y / mag;
	return normal;
}

vec2 & vec2::scale(const vec2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	vec2 scaled{ x,y };
	scaled *= rhs.x;
	scaled *= rhs.y;
	return scaled;
}

vec2 vec2::operator*(const float rhs) const
{
	vec2 multi{ x,y };
	multi.x *= rhs;
	multi.y *= rhs;
	return multi;
}

vec2 & vec2::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

float vec2::dot(const vec2 & rhs) const
{
	return ((x * rhs.x) + (y * rhs.y));
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 temp{ rhs.x,rhs.y };
	temp.x = rhs.x * lhs;
	temp.y = rhs.y * lhs;
	return temp;
}

#ifdef RAYLIB_H
{
	// constructor vec2 from Vector2
	vec2(const Vector2 &vec)
	{
		x = vec.x;
		y = vec.y;
	}

	// convert from Vector2 to vec2
	vec2& operator =(const Vector2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}

	// convert from vec2 to Vector2
	operator Vector2()
	{
		return { x , y };
	}
}
#endif // RAYLIB_H
