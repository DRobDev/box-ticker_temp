#include "CustomCursor.h"
#include <Windows.h>

CustomCursor* CustomCursor::instance = nullptr;
Transform CustomCursor::transform = Transform();

void CustomCursor::UseCustomCursor()
{
	//only one instance allowed
	if(instance == nullptr) 
		instance = new CustomCursor();
}

Vec2 CustomCursor::GetPosition()
{
	return transform.GetPosition();
}

CustomCursor::CustomCursor()
{
	//create cursor sprite
	currentSprite = new Sprite("./images/img_Cursor_512x512.png", Vec2(32,32));
}

void CustomCursor::OncePerFrame()
{
	//hide default cursor
	while(ShowCursor(false)>=0);

	//move cursor to mouse position
	double m_mX, m_mY;
	GetMouseLocation(m_mX, m_mY);
	m_mY = BoxTicker::WINDOWSIZE.y - m_mY; //invert 'y'
	Vec2 m_mousePos(m_mX, m_mY);
	transform.SetPosition(m_mousePos);

	//draw cursor
	currentSprite->SetMatrix(transform.GetMatrix());
	currentSprite->Draw();
}



CustomCursor::~CustomCursor()
{
	delete currentSprite;
	delete instance;
}