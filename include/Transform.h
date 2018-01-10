/////////////////////////////////////
// TRANSFORM
//-----------------------
// Stores position, rotation, and scale
// information.
// Controls movement.
/////////////////////////////////////

#pragma once
#include "Vec2.h"

class Transform
{
	//matrix size and position location
	static const int MATRIXSIZE = 16;
	static const int MAT_POSX = 12;
	static const int MAT_POSY = 13;

	//transform matrix; stores position rotation and scale
	float transformMatrix[MATRIXSIZE];

public:
	//constructor
	Transform();

	//returns tran matrix (making it readonly)
	float* GetMatrix();

	//sets matrix
	void SetMatrix(float* a_matrix);

	//set positrion (0'x/y' = bottom left)
	void SetPosition(Vec2 a_pos);

	//sets rotation (0 = up)
	void SetRotation(float a_degrees);

	//offset current position by this ammount (translated to use local axis)
	void MoveLocal(Vec2 a_moveAmount);

	//get position as vector 2
	Vec2 GetPosition();

	//true if transform is out of frame
	bool GoesOffScreen();

	//rotate to face parameter
	void LookAt(Vec2 a_screenPos);
};