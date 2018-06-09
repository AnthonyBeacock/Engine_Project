#pragma once
#include "IScene.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

class mScene : public IScene
{
public:
	mScene();
	~mScene();

	GLFWwindow * window;

	int InitialiseGLFW();
	int OpenWindow(const char* titleString, int widith, int height, bool isResizable);

	void Render() override;
	void Update() override;
};

