/////////////////////////////////////
// CUSTOM CURSOR
//-----------------------
// Hides default mouse pointer.
// Replacing it with drawn sprite.
/////////////////////////////////////

#include "Entity.h"
#include "Transform.h"
#include "Sprite.h"

class CustomCursor : Entity
{
	//active sprite representing cursor
	Sprite* currentSprite;
	//transform for cursor
	static Transform transform;

	//class instace (semi-singleton pattern)
	static CustomCursor* instance;

	//main cursor update
	virtual void OncePerFrame();

	//private constructor
	CustomCursor();

public:
	//call to use custom cursor in game
	static void UseCustomCursor();

	//returns cursor position
	static Vec2 GetPosition();

	//destructor
	~CustomCursor();
};