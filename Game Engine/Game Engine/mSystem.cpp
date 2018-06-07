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


	for (int i; i < systemList.size; i++)
	{
		for (int j; j < entities.size; i++)
		{
			systemList[i]->AssignEntity(entities[j]);
		}
	}
}

void mSystem::AssignNewEntity(oEntity & entity)
{
	vector<ISystem*> systemList;

	systemList.insert(systemList.end(), renderSystems.begin(), renderSystems.end());
	systemList.insert(systemList.end(), updateSystems.begin(), updateSystems.end());

	for (int i; i < systemList.size; i++)
	{
		systemList[i]->AssignEntity(entity);
	}
}

void mSystem::DestroyEntity(oEntity & entity)
{
	vector<ISystem*> systemList;

	systemList.insert(systemList.end(), renderSystems.begin(), renderSystems.end());
	systemList.insert(systemList.end(), updateSystems.begin(), updateSystems.end());

	for (int i; i < systemList.size; i++)
	{
		systemList[i]->DestroyEntity(entity);
	}
}

void mSystem::RenderSystems()
{
	for (int i = 0; i < renderSystems.size; i++)
	{
		renderSystems[i]->OnAction();
	}
}

void mSystem::UpdateSystems()
{
	for (int i = 0; i < updateSystems.size; i++)
	{
		updateSystems[i]->OnAction();
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
