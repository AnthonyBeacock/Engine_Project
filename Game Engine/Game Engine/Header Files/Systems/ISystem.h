#pragma once
#include "oEntity.h"

class ISystem
{
protected: 
	virtual void OnAction() = 0; // setting to 0 creates a pure virtual function
	virtual void AssignEntity(oEntity& entity) = 0;
	virtual void DestroyEntity(oEntity& entity) = 0;

private:
	string name;
};

