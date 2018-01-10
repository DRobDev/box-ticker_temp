/////////////////////////////////////
// PLAYER
//-----------------------
// Stores all player infomation
// Handles controls
//-----------------------
// Player faces cursor position.
// Moves towards cursor on Rright Moue Button (RMB)
// Fires when Left Mouse Button (LMB) pressed
/////////////////////////////////////

#pragma once

#include "Entity.h"

class Collider;
class Sprite;
class Transform;

class Player : Entity
{
	//controls
#define MoveButtonDown GetMouseButtonDown(MOUSE_BUTTON_2)  
#define FireButtonDown GetMouseButtonDown(MOUSE_BUTTON_1) 
#define MoveButtonUp GetMouseButtonReleased(MOUSE_BUTTON_2)  
#define FireButtonUp GetMouseButtonReleased(MOUSE_BUTTON_1) 

	//player settings
	static const float MOVESPEED;

	Collider* collider;
	Transform* transform;
	Sprite* activeSprite;



	//draws player (called every frame by Entity.cpp)
	virtual void OncePerFrame();

	//called on collision
	void OnCollision(Collider* a_otherCol);


	//rotate player to face cursor position
	void m_LookAtCursor();

	//move player towards cursor
	void m_MoveLocal();


public:
	//constructor
	Player();

	static bool IsButtonPressed();

	void ResetPosition();

	~Player();
};

