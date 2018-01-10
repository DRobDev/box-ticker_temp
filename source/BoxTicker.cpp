#include "BoxTicker.h"
#include "Player.h"
#include "Enemy.h"
#include "CustomCursor.h"
#include "Time.h"
#include "Menu.h"

const Vec2 BoxTicker::WINDOWSIZE = Vec2(900, 900);

BoxTicker::BoxTicker()
{
	currentGameState = SPLASH;
	isShutdownCalled = false;
}

void BoxTicker::RunGame()
{
	//initialze framework
	m_BaseInitialization();

	//initialize Game Variables
	Player* player = nullptr;
	Enemy* enemy = nullptr;
	Menu menu;

	//////////// MAIN GAME LOOP //////////////
	//run loop until framework closes
	do
	{
		switch (currentGameState)
		{
			//-----------SPLASH SCREEN Start----------//

			// Displays background image while waiting
			// for player input.

		case SPLASH:
			menu.ClearButtons();						//clear menu items (artifacts if navigating back from menu screen)
			if(player != nullptr)
			{
				delete player;
				player = nullptr;
			}

			menu.UpdateSplash();						//draw splash screen

			if(Player::IsButtonPressed())				//go to Main Menu if input detected
				currentGameState = MENUSTART;
			break;
			//-----------SPLASH SCREEN END---------//


			//-----------MENU SCREEN-------------//

			// Player is presented with three
			// buttons: 'Exit' 'Start' and 'High Scores'.
			// Buttens are selected by the player 
			// shooting or crashing into the desired
			// option.

		case MENUSTART:
			menu.StartStartMenu();						//initialize menu
			currentGameState = MENU;	
			if(player == nullptr)
				player = new Player();					//create player
			else player->ResetPosition();

		case MENU:
			menu.UpdateStartMenu();						//update button check and draw
			if(menu.IsButtonPressed(Menu::EXITBUTTON))	
				isShutdownCalled = true;				//shutdown if 'Exit' pressed
			if(menu.IsButtonPressed(Menu::STARTGAMEBUTTON))
				currentGameState = GAMESTART;			//start game if 'Start Game' pressed
			if(IsKeyDown(KEY_ESCAPE))
				currentGameState = SPLASH;				//go back to splash screen if 'esc' pressed
			break;
			//-----------SPLASH SCREEN END---------//


		case HIGHSCORES:
			break;


			//-----------MAIN GAME-------------//

			// Player and single stationary enemy 
			// created.
			// Player shoot enemy to start game.
			// Game ends when player or enemies 
			// are destroyed.
		case GAMESTART:
			menu.ClearButtons();						//clear menu
			if(player == nullptr) player = new Player();
			player->ResetPosition();					//reset player position
			enemy = new Enemy();						//spawn first enemy
			currentGameState = GAME;					//
		case GAME:
			if(IsKeyDown(KEY_ESCAPE))
				currentGameState = MENUSTART;
			if(Enemy::AreAllEnemiesDestroyed())
			{
				bool blah = 0;
			}
			break;
			//-----------MAIN GAME END---------//


		case DEFAULT:
			break;
		default:
			break;
		}
		//clears the last draw
		ClearScreen();

		//Update 'once per frame' updates
		Entity::CallOncePerFrameInAllEntities();
		//check all collisions
		Collider::CheckAllCollisions();

	} while(FrameworkUpdate() == false && !isShutdownCalled);
	//////////// MAIN GAME LOOP (END) ////////


}

BoxTicker::~BoxTicker()
{
	Shutdown();
}

void BoxTicker::m_BaseInitialization()
{
	//Initialize aie framework
	Initialise(WINDOWSIZE.x, WINDOWSIZE.y, false, "BOX TICKER");
	//set game background colour
	SetBackgroundColour(SColour(0,0,0,255)); //black
	//use custom cursor
	CustomCursor::UseCustomCursor();
}

