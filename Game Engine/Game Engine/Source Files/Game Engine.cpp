// Game Engine.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "mScene.h"
#include "mInput.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include "oEntity.h"
#include "mEntity.h"
#include "mSystem.h"
#include "sRender.h"

int main(void)
{

	//Entity and Entity Manager testing

	string name = "name";
	oEntity entity(name);
	mEntity entityManager;

	//Creates Transform Component and a pointer to it
	cTransform transform(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	cTransform *transformP = &transform;

	//Creates Velocity Component and a pointer to it
	cVelocity velocity(1.0f, 10.0f, 0.5f, true);
	cVelocity *velocityP = &velocity;

	//Adds a transform component to the entity then adds the entity to the list
	entity.AddComponent(transformP);
	entityManager.AddEntity(entity);

	//Adds a velocity component to the entity then adds entity to the list
	entity.AddComponent(velocityP);
	entityManager.AddEntity(entity);

	//Retrieves pointers to the transform and velocity components of the entity
	cTransform *transformP2 = entity.GetTransform();
	cVelocity *velocityP2 = entity.GetVelocity();

	//Finds entity with the name "name"
	entity = entityManager.FindEntity(name);

	//Removes entity from entity manager
	entityManager.RemoveEntity(entity);


	//System and System Manager testing

	mSystem systemManager;

	//Creates Render System and a pointer to it
	sRender renderSystem;
	sRender *renderSystemP = &renderSystem;

	//Adds system to render system and update system list
	systemManager.AddRenderSystem(renderSystemP);
	systemManager.AddUpdateSystem(renderSystemP);


	//Initialisation of GL window and input handling

	mScene sceneManager;
	mInput inputManager(&sceneManager);

	sceneManager.InitialiseGLFW();
	sceneManager.OpenWindow();
	sceneManager.SetupKeyPress();

	//inputManager.CursorVisible(sceneManager.window, true); // would be called from the actual game?

	sceneManager.Render();
	sceneManager.Update();


	return 0;
}


