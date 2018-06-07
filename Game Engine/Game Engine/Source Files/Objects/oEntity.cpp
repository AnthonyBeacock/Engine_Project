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

void oEntity::AddComponent(IComponent* component)
{
	componentList.push_back(component);
	mask |= component->ComponentMask();
}

string& oEntity::GetName()
{
	return name;
}

void oEntity::SetName(string &name)
{
	name = name;
}

IComponent::ComponentMasks oEntity::Mask()
{
	return mask;
}

vector<IComponent*>& oEntity::Components()
{
	return componentList;
}

