/////////////////////////////////////
// Enemy
//-----------------------
// Enemies move a constant speed in a constant direction.
// If they leave the screen they are destroyed.
// If they are shot by player they are destroyed
// but spawn # more enemies.
// The more enemies the player destroy, the faster they move
/////////////////////////////////////

#pragma once

#include  "Collider.h"
#include "Entity.h"
#include "Transform.h"

class Sprite;


class Enemy : Entity
{
	//keeps track of number of enemies in game
	static int EnemyCounter;

	//player settings
	static const float BASEMOVESPEED;
	static const float SPEEDMULTIPLYERINCREASE;

	//static 
	static float speedMultiplyer;



	float moveSpeed;

	Collider* collider;
	Transform* transform;
	Sprite* activeSprite;


	//private constructor
	Enemy(Vec2 a_spawnPosition, float a_facingDirection, float a_moveSpeed = BASEMOVESPEED * speedMultiplyer);

	//spawn more enemies at this point
	void m_SpawnMore();

	//Main update
	virtual void OncePerFrame();
	//on collision
	virtual void OnCollision(Collider* a_otherCol);

	virtual Vec2 GetPositionForCollider() { return transform->GetPosition(); }
	virtual void PostDestroy(){delete this;}

public:
	//public constructor for starter enemy
	Enemy();

	//check if all enemies are destroyed
	static bool AreAllEnemiesDestroyed();

	~Enemy();

};
