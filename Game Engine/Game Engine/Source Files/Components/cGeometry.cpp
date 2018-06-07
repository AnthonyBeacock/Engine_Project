#include "stdafx.h"
#include "cGeometry.h"
#include "IComponent.h"

cGeometry::cGeometry()
{
}

cGeometry::~cGeometry()
{
}

int cGeometry::GetGeometry()
{
	return 0;
}

void cGeometry::SetGeometry(string & filename)
{
}

IComponent::ComponentMasks cGeometry::ComponentMask()
{
	return ComponentMasks();
}
