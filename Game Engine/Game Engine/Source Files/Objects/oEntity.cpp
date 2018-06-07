#include "stdafx.h"
#include "oEntity.h"

oEntity::oEntity()
{
}

oEntity::~oEntity()
{
}

oEntity::oEntity(string &nameIn)
{
	name = nameIn;
}

void oEntity::AddComponent(IComponent* componentIn)
{
	componentList.push_back(componentIn);
	mask |= componentIn->ComponentMask();
}

string& oEntity::GetName()
{
	return name;
}

void oEntity::SetName(string &nameIn)
{
	name = nameIn;
}

IComponent::ComponentMasks oEntity::Mask()
{
	return mask;
}

vector<IComponent*>& oEntity::Components()
{
	return componentList;
}

