#include "stdafx.h"
#include "mEntity.h"

mEntity::mEntity()
{
}

mEntity::~mEntity()
{
}

oEntity mEntity::FindEntity(string & name)
{
	return oEntity();
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

void mEntity::RemoveEntity(oEntity * entity)
{
}

vector<oEntity>& mEntity::Entites()
{
	return entities;
}
