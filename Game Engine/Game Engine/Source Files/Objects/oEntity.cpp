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

cTransform* oEntity::GetTransform()
{
	for (auto & component : componentList)
	{
		if (component->ComponentMask() == IComponent::COMPONENT_TRANSFORM)
		{
			return static_cast<cTransform*>(component);
		}
	}
}

cVelocity* oEntity::GetVelocity()
{
	for (auto & component : componentList)
	{
		if (component->ComponentMask() == IComponent::COMPONENT_VELOCITY)
		{
			return static_cast<cVelocity*>(component);
		}
	}
}

