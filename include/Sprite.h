/////////////////////////////////////
// SPRITE
//-----------------------
// Defines a simple non animated sprite
// drawn from the center.
// Handles drawing
/////////////////////////////////////

#pragma once
#include "Vec2.h"

class Sprite
{
	//director of sprite image
	const char* dir;

	//sprite size when created
	const Vec2 BASESIZE;

	//unique id for sprite on the framework
	int id;

public:
	//constructor
	Sprite(const char* a_imgDir, Vec2 a_imageSize);

	//sets matrix for this sprite
	void SetMatrix(float* a_matrix);

	//Simple draw
	virtual void Draw();

	~Sprite(void);
};

