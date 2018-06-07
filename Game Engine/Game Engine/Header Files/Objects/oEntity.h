#ifndef ENTITY
#define ENTITY

#include "IComponent.h"
#include <string>
#include <vector>
#include "cTransform.h"
#include <algorithm>

using namespace std;

class oEntity
{
private:
	string name;
	vector<IComponent*> componentList;
	IComponent::ComponentMasks mask;

public:
	oEntity();
	~oEntity();
	oEntity(string &nameIn);
	void AddComponent(IComponent* componentIn);
	string& GetName();
	void SetName(string &nameIn);
	IComponent::ComponentMasks Mask();
	vector<IComponent*>& Components();

};

#endif // !ENTITY