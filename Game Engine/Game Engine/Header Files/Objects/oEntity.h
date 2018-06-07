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
	void AddComponent(IComponent* component);
	string& GetName();
	void SetName(string &name);
	IComponent::ComponentMasks Mask();
	vector<IComponent*>& Components();

	bool oEntity::operator==(const oEntity& a)
	{
		return name == a.name;
	}
};

#endif // !ENTITY