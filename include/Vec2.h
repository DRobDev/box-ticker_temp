////////////////////////////////////
// handle two dimensional 
////////////////////////////////////


#pragma once

//holds an x and y
class Vec2 
{
public:
	float x;
	float y;

	//base constructor sets values to zero
	Vec2();
	//custom constructor
	Vec2(float a_x, float a_y);

	//vector initialized to x0 y0
	static const Vec2 ZERO;
	//vector initialized to max
	static const Vec2 MAX;

	//returns the distance between two vectors
	static float Distance(Vec2& a_vecA, Vec2& a_vecB); 

	//returns absolute values of vector
	Vec2 GetAbsolute();

	//returns magnitude of vector
	float GetMagnitude();

	//opperators
	Vec2 operator-();
	bool operator==(Vec2& a_vec);
	bool operator==(const Vec2& a_vec);
	bool operator!=(Vec2& a_vec);
	bool operator!=(const Vec2& a_vec);
	Vec2 operator+(Vec2& a_vec);
	Vec2 operator-(Vec2& a_vec);
	Vec2& operator+=(const Vec2& a_vec);
	Vec2& operator+=(const float& a_float);
	Vec2& operator-=(const Vec2& a_vec);
	Vec2& operator-=(const float& a_float);
	Vec2 operator*(Vec2& a_vec);
	Vec2 operator*(float a_float);
	Vec2& operator*=(float a_float);
	Vec2 operator/(float a_float);
	bool operator>(Vec2& a_vec);
	bool operator>=(Vec2& a_vec);
	bool operator<(Vec2& a_vec);
	bool operator<=(Vec2& a_vec);
};