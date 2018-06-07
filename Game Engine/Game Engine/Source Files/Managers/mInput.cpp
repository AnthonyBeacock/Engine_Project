#include "stdafx.h"
#include "mInput.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include <iostream>


mInput::mInput()
{
}


mInput::~mInput()
{
}

void mInput::cursorPosition(GLFWwindow * window, double xPosition, double yPosition)
{
	std::cout << xPosition << "  :  " << yPosition << endl;
}

void mInput::CenterCursor(GLFWwindow * window)
{
	glfwSetCursorPosCallback(window, cursorPosition);

}

void mInput::CursorVisible()
{

}
