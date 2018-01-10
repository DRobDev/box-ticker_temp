///////////////////////////////////////
// MENU
//--------------------
// Presents options to the player
// Play, Exit, Highscores
///////////////////////////////////////

#pragma once
#include "Sprite.h"
#include "Entity.h"
#include "Collider.h"

class Button;
class Menu : Entity
{
	Transform* middleScreenTran;

	Sprite* spalshScreen;
	Sprite* menuBackground;

	Button* buttonExit;
	Button* buttonStartGame;


	//Sprite buttonExitGame;
	//Sprite buttonHighScores;

	//main update for menu
	virtual void OncePerFrame();



public:

	enum Buttons
	{
		EXITBUTTON,
		STARTGAMEBUTTON,
		BUTTONS_END
	};

	//constructor
	Menu();

	//destroys buttons in menu
	void ClearButtons();

	//returns true if button pressed
	bool IsButtonPressed(Buttons a_checkButton);

	//initialize menu
	void StartStartMenu();
	//update menu
	void UpdateStartMenu();

	//update splash
	void UpdateSplash();

	//destructor
	~Menu();
};

class Button : Entity
{
public: 
	static const int BUTTONSIZE = 128;

	bool hasBeenPressed;

	Sprite* sprite;
	Collider* collider;
	Transform* transform;

	virtual void OnCollision(Collider* a_otherCol);


	Button(const char* a_imgDir, Vec2 a_screenPos);

	~Button();
};