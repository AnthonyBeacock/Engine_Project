#pragma once
#include <vector>
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

using namespace std;

class mInput
{
public:
	
	mInput();
	~mInput();

	static void cursorPosition(GLFWwindow * window, double xPosition, double yPosition);

	void CenterCursor(GLFWwindow * window);
	void CursorVisible();
	void KeyDown();
	void KeyUp();
	void MouseClickDown();
	void MouseClickUp();
	void MouseMovement();

	vector<string> keyboardInput;
	vector<string> mouseInput;

private:
	glm::vec2 mousePosition;
};

