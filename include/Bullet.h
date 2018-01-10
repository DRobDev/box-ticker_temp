/////////////////////////////////////
// Bullet
//-----------------------
// Travels along its y axis at constant speed
// until it hits something or goes off the screen
//-----------------------
/////////////////////////////////////
#pragma once

#include "Collider.h"
#include "Transform.h"
#include "Entity.h"

class Sprite;

class Bullet : public Entity
{
	Collider* collider;
	Transform* transform;
	Sprite* activeSprite;
	

	static const float BULLETSPEED;

	//Main bullet update
	virtual void OncePerFrame();

	//on collision
	virtual void OnCollision(Collider* a_otherCol);

	virtual Vec2 GetPositionForCollider(){ return transform->GetPosition(); }
	virtual void PostDestroy(){delete this;}
public:
	//constructor (creates bullet at parents position)
	Bullet(float* a_parentMatrix,
		Collider::ColliderTypes a_colType = Collider::ColliderTypes::PLAYERBULLET);

	~Bullet(void);
};

