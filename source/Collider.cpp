#include "Collider.h"

std::list<Collider*> Collider::allColliders = std::list<Collider*>();
std::list<Collider*> Collider::allCollidersToBeRemoved = std::list<Collider*>();

void Collider::CheckAllCollisions()
{

	//discard colliders (TEMP: fix)
	if(!allCollidersToBeRemoved.empty())
	{
		for(auto i = allCollidersToBeRemoved.begin(); i != allCollidersToBeRemoved.end(); i++)
			allColliders.remove(*i);
		allCollidersToBeRemoved.clear();
	}

	bool m_doDelete = false;

	//check for collisions
	for(auto i = allColliders.begin(); i != allColliders.end(); i++)
	{
		if(IsKeyDown(KEY_SPACE))
			bool blah = 0;

		for(auto r = i; r != allColliders.end(); r++)
		{
			if(i == r) continue; //dont check self

			if((*i)->collisionRadius + (*r)->colliderType 
				> Vec2::Distance((*i)->partentTran->GetPosition(), (*r)->partentTran->GetPosition()))
			{
				(*i)->parentEntity->OnCollision(*r);
				(*r)->parentEntity->OnCollision(*i);
				m_doDelete = true;
			}

			if(m_doDelete) break;
		}
		if(m_doDelete) break;
	}
}


Collider::Collider(ColliderTypes a_colliderType, Entity* a_baseEnt, Transform* a_baseTran, float a_colRadius)
	: colliderType(a_colliderType), collisionRadius(a_colRadius)
{
	allColliders.push_back(this);
	parentEntity = a_baseEnt;
	partentTran = a_baseTran;
}


Collider::~Collider(void)
{
	allCollidersToBeRemoved.push_back(this);
}
