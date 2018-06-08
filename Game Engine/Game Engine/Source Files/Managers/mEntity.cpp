#include "stdafx.h"
#include "mEntity.h"

mEntity::mEntity()
{
}

mEntity::~mEntity()
{
}

oEntity& mEntity::FindEntity(string & name)
{
	for (auto & entity : entities)
	{
		if (entity.GetName() == name)
		{
			return entity;
		}
	}
}

void mEntity::AddEntity(oEntity & entity)
{
	bool added = false;
	int count = 0;
	string name = entity.GetName();
	string tempName = entity.GetName();

	while (!added)
	{
		if (find(entityNames.begin(), entityNames.end(), tempName) != entityNames.end())
		{
			tempName = name + "(" + to_string(count) + ")";
		}
		else
		{
			entityNames.push_back(tempName);
			entity.SetName(tempName);
			entities.push_back(entity);
			added = true;
		}
	}
}

void mEntity::RemoveEntity(oEntity & entity)
{
	entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
	entityNames.erase(remove(entityNames.begin(), entityNames.end(), entity.GetName()), entityNames.end());
}

vector<oEntity>& mEntity::Entites()
{
	return entities;
}
