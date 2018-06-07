#ifndef SYSTEMMANAGER
#define SYSTEMMANAGER

#include <string>
#include <vector>
#include "ISystem.h"
#include "mEntity.h"

using namespace std;

class mSystem
{
private:
	vector<ISystem*> renderSystems;
	vector<ISystem*> updateSystems;

public:
	mSystem();
	~mSystem();
	void AssignEntities(mEntity &entityManager);
	void AssignNewEntity(oEntity &entity);
	void DestroyEntity(oEntity &entity);
	void RenderSystems();
	void UpdateSystems();
	void AddRenderSystem(ISystem* system);
	void AddUpdateSystem(ISystem* system);
};

#endif // !SYSTEMMANGER
