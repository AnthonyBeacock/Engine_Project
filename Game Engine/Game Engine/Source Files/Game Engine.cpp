// Game Engine.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "mScene.h"
#include "mInput.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include "oEntity.h"

int main(void)
{
	mScene sceneManager;
	string name = "name";
	oEntity entity(name);

	cTransform transform(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	cTransform *transformP = &transform;

	entity.AddComponent(transformP);

	sceneManager.InitialiseGLFW();
	sceneManager.OpenWindow();
	sceneManager.SetupKeyPress();
	sceneManager.Render();
	sceneManager.Update();

	

	return 0;
}


