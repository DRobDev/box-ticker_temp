#include "Entity.h"

std::list<Entity*> Entity::allEntities = std::list<Entity*>();
std::list<Entity*> Entity::allEntitiesToBeRemoved = std::list<Entity*>();

Entity::Entity()
{
	//add newly created entity to list
	allEntities.push_back(this);
}

void Entity::CallOncePerFrameInAllEntities()
{
	//discard entities (TEMP: fix)
	if(!allEntitiesToBeRemoved.empty())
	{
		for(auto i = allEntitiesToBeRemoved.begin(); i != allEntitiesToBeRemoved.end(); i++)
			allEntities.remove(*i);
		allEntitiesToBeRemoved.clear();
	}

	//cycle through active
	for(auto i = allEntities.begin(); i != allEntities.end(); i++)
	{
		//generic update for all entities
		(*i)->OncePerFrame();
	}

}

Entity::~Entity()
{
	//(need to delay removal so iteration doesn't screw up)
	allEntitiesToBeRemoved.push_back(this);
}