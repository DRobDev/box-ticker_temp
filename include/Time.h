/////////////////////////////////////
// TIME
//-----------------------
// Controls game time
// provides access to delta time and fps
/////////////////////////////////////

#pragma once

#include "Entity.h"

class Time : Entity
{
	//semi singleton instance
	static Time* instance;

	//returns instance
	static Time* m_GetInstance();


	float delta;
	float gameTime;
	int	 fps;

	//private constructor
	Time();

	//called once per frame; updates time variables
	virtual void OncePerFrame();

public:
	//returns delta time
	static float GetDelta();

	//returns game time
	static float GetGameTime();

	//returns fps
	static int GetFPS();

	~Time();

};


