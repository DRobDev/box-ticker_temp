/////////////////////////////////////
// ENTITY
//-----------------------
// All game object inherit from this base 
// class.
// Used as basic message bank and updater
//-----------------------
// Calls all updates every frame
/////////////////////////////////////

#pragma once 
#include "BoxTicker.h"
#include <list>

class Collider;
class Entity
{
	static std::list<Entity*>allEntities;	//holds all active entities
	static std::list<Entity*>allEntitiesToBeRemoved;	//held entities ready for removal
	
public:
	//constructor
	Entity();


	//calls all virtual 'per-frame' updates for all entities (TODO: this is lazy, create a more optimized version using Reflection)
	static void CallOncePerFrameInAllEntities();

	// Empty Virtual //
	//called once per frame
	//generic update
	virtual void OncePerFrame(){}

	//called by collider on hit
	virtual void OnCollision(Collider* a_otherCol){};

	//destructor
	virtual ~Entity();
};