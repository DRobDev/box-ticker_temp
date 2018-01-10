#include "Vec2.h"
#include <cmath>
#include <limits>

const Vec2 Vec2::ZERO = Vec2(0,0);
const Vec2 Vec2::MAX = Vec2(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());

float Vec2::Distance(Vec2& a_vecA, Vec2& a_vecB)
{
	return sqrtf(powf(a_vecB.x - a_vecA.x, 2) + powf(a_vecB.y - a_vecA.y, 2));
}

Vec2 Vec2::GetAbsolute()
{
	return Vec2(fabsf(x), fabsf(y));
}

float Vec2::GetMagnitude()
{
	return sqrtf(powf(x,2) + powf(y,2));
}

Vec2::Vec2() 
{ x = 0; y = 0;}

Vec2::Vec2(float a_x, float a_y) 
{ x = a_x; y = a_y; }

Vec2 Vec2::operator-()
{
	return Vec2(-x, -y);
}

bool Vec2::operator!=(Vec2& a_vec)
{
	return x!=a_vec.x || y!=a_vec.y;
}

bool Vec2::operator!=(const Vec2& a_vec)
{
	return x!=a_vec.x || y!=a_vec.y;
}

bool Vec2::operator==(Vec2& a_vec)
{
	return x == a_vec.x && y == a_vec.y;
}

bool Vec2::operator==(const Vec2& a_vec)
{
	return x == a_vec.x && y == a_vec.y;
}

Vec2 Vec2::operator+(Vec2& a_vec)
{ return Vec2(x + a_vec.x, y + a_vec.y); }

Vec2 Vec2::operator-(Vec2& a_vec)
{ return Vec2(x - a_vec.x, y - a_vec.y); }

Vec2& Vec2::operator+=(const Vec2& a_vec)
{  
	this->x += a_vec.x;
	this->y += a_vec.y;
	return *this;
}

Vec2& Vec2::operator+=(const float& a_float)
{
	this->x += a_float;
	this->y += a_float;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& a_vec)
{
	this->x -= a_vec.x;
	this->y -= a_vec.y;
	return *this;
}

Vec2& Vec2::operator-=(const float& a_float)
{
	this->x -= a_float;
	this->y -= a_float;
	return *this;
}

Vec2 Vec2::operator*(Vec2& a_vec)
{ return Vec2(x * a_vec.x, y * a_vec.y); }

Vec2 Vec2::operator*(float a_float)
{ return Vec2(x * a_float, y * a_float); }

Vec2& Vec2::operator*=(float a_float)
{
	this->x *= a_float;
	this->y *= a_float;
	return *this;
}

Vec2 Vec2::operator/(float a_float)
{
	if(a_float == 0) return Vec2();
	return Vec2(x/a_float, y/a_float);
}

bool Vec2::operator>(Vec2& a_vec)
{
	return x > a_vec.x && y > a_vec.y;
}

bool Vec2::operator<(Vec2& a_vec)
{
	return x < a_vec.x && y < a_vec.y;
}

bool Vec2::operator<=(Vec2& a_vec)
{
	return x <= a_vec.x && y <= a_vec.y;
}

bool Vec2::operator>=(Vec2& a_vec)
{
	return x >= a_vec.x && y >= a_vec.y;
}



