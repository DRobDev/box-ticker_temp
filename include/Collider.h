/////////////////////////////////////
// COLLIDER
//-----------------------
// Handles collision and fires off 'hit' events
/////////////////////////////////////

#pragma once

#include <list>
#include "Transform.h"
#include "Entity.h"

class Collider
{
public:
	enum ColliderTypes
	{
		ENEMY,
		PLAYER,
		ENEMYBULLET,
		PLAYERBULLET,
		BUTTON,
	};

private:
	static std::list<Collider*>allColliders;
	static std::list<Collider*>allCollidersToBeRemoved;

	//

	//type of collider
	const ColliderTypes colliderType;
	//radius for collider
	const float collisionRadius;

	//transform of parent
	Transform* partentTran;
	//entity of parent
	Entity* parentEntity;

	//called when hit
	//void (*OnHit)(Collider* a_otherCol);


public:


	//constructor
	Collider(ColliderTypes a_colliderType, Entity* a_baseEnt, Transform* a_baseTran, float a_colRadius = 32);

	//checks collision for all colliders
	static void CheckAllCollisions();

	//returns collider type
	ColliderTypes GetColliderType(){return colliderType;}

	~Collider(void);
};

