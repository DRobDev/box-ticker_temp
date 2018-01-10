///////////////////////////////////////
// BOX TICKER
//--------------------
// Player flies around screen shooting targets which
// multiply when hit. 
// If a target hits the edge of the screen it's destroyed
// Game ends when player is hit by target, or all targets
// are destroyed.
//--------------------
// A game designed entirely to tick boxes
// in the hand in checklist.
// The goal is to scrape together the minimum
// requirement in a week.
// (all work done prior to this is written off 
// as an exercise in 'how not to time manage') 
// Start 26/03/14 Dennis.Hesketh (goblinIncident@gmail.com)
///////////////////////////////////////


#pragma once
#include "AIE.h"
#include "Vec2.h"

class BoxTicker
{
	//used to exit
	bool isShutdownCalled;

	enum GameStates
	{
		SPLASH,
		MENUSTART,
		MENU,
		HIGHSCORES,
		GAMESTART,
		GAME,
		DEFAULT
	} ;
	GameStates currentGameState;
	//Initialse framework and game
	void m_BaseInitialization();


public:
	//constructor
	BoxTicker();

	//size of game window
	static const Vec2 WINDOWSIZE;

	//launch game
	void RunGame();

	~BoxTicker();
};


