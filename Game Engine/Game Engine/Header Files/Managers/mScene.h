#pragma once
#include "IScene.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

#define HEIGHT 768
#define WIDTH 1024

class mScene : public IScene
{
public:
	mScene();
	~mScene();

	GLFWwindow * window;

	int InitialiseGLFW();
	int OpenWindow();
	void SetupKeyPress();

	void Render() override;
	void Update() override;

};

