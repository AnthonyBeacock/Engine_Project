#include "stdafx.h"
#include "mSystem.h"

mSystem::mSystem()
{
}

mSystem::~mSystem()
{
}

void mSystem::AssignEntities(mEntity & entityManager)
{
	vector<ISystem*> systemList;

	systemList.insert(systemList.end(), renderSystems.begin(), renderSystems.end());
	systemList.insert(systemList.end(), updateSystems.begin(), updateSystems.end());

	vector<oEntity> entities = entityManager.Entites();


	for (auto & system : systemList)
	{
		for (auto & entity : entities)
		{
			system->AssignEntity(entity);
		}
	}
}

void mSystem::AssignNewEntity(oEntity & entity)
{
	vector<ISystem*> systemList;

	systemList.insert(systemList.end(), renderSystems.begin(), renderSystems.end());
	systemList.insert(systemList.end(), updateSystems.begin(), updateSystems.end());

	for (auto & system : systemList)
	{
		system->AssignEntity(entity);
	}
}

void mSystem::DestroyEntity(oEntity & entity)
{
	vector<ISystem*> systemList;

	systemList.insert(systemList.end(), renderSystems.begin(), renderSystems.end());
	systemList.insert(systemList.end(), updateSystems.begin(), updateSystems.end());

	for (auto & system : systemList)
	{
		system->DestroyEntity(entity);
	}
}

void mSystem::RenderSystems()
{
	for (auto & system : renderSystems)
	{
		system->OnAction();
	}
}

void mSystem::UpdateSystems()
{
	for (auto & system : updateSystems)
	{
		system->OnAction();
	}
}

void mSystem::AddRenderSystem(ISystem * system)
{
	renderSystems.push_back(system);
}

void mSystem::AddUpdateSystem(ISystem * system)
{
	updateSystems.push_back(system);
}
