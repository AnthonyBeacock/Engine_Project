#ifndef RENDER
#define RENDER
#include <iostream>
#include <string>
#include <vector>
#include "oEntity.h"
#include <stdlib.h>
#include "ISystem.h"

using namespace std;

class sRender : public ISystem
{
public:
	vector<oEntity> entityList;
	IComponent::ComponentMasks ComponentMask = IComponent::ComponentMasks::COMPONENT_NONE;// (IComponent::ComponentMasks::COMPONENT_TRANSFORM | IComponent::ComponentMasks::COMPONENT_TEXTURE | IComponent::ComponentMasks::COMPONENT_GEOMETRY | IComponent::ComponentMasks::COMPONENT_SHADER);
	sRender();
	~sRender();

	void OnAction() override;
	void AssignEntity(oEntity& entity) override;
	void DestroyEntity(oEntity& entity) override;
};

#endif // !RENDER