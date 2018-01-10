#include "Time.h"
#include "BoxTicker.h"

Time* Time::instance = nullptr;

Time* Time::m_GetInstance()
{
	if(instance == nullptr)
		instance = new Time();
	return instance;
}

float Time::GetDelta()
{
	return m_GetInstance()->delta;
}

float Time::GetGameTime()
{
	return m_GetInstance()->gameTime;
}

int Time::GetFPS()
{
	return m_GetInstance()->fps;
}

Time::Time()
{
	delta = 0;
}

void Time::OncePerFrame()
{
	delta = GetDeltaTime();
	gameTime+= delta;
	fps = delta / 1;
}

Time::~Time()
{
	delete instance;
}


