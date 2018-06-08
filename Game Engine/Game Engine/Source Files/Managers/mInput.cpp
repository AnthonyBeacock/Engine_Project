#pragma once
#include "stdafx.h"
#include "mInput.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include <iostream>

mInput::MOUSE_BUTTONS mInput::pressedMouseButton;

mInput::mInput(mScene * inSceneManager)
{
	sceneManager = inSceneManager;
}

mInput::~mInput()
{
}

void mInput::CursorPositionCallback(GLFWwindow * window, double xPosition, double yPosition)
{
	system("CLS");
	cout << "Cursor Position" << endl;
	cout << "X: " << xPosition << endl;
	cout << "Y: " << yPosition << endl;
}

void mInput::CenterCursor(GLFWwindow * window)
{

}

void mInput::CursorVisible(GLFWwindow * window, bool isVisible)
{
	if (isVisible)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	}
	else
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}
}

void mInput::MouseButtonCallback(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		cout << "Left Mouse Button Clicked" << endl;
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_LEFT;
		//buttonState = BUTTON_STATE::DOWN;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		cout << "Left Mouse Button Released" << endl;
	//	pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_LEFT;
	//	buttonState = BUTTON_STATE::UP;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
	//	pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_RIGHT;
	//	buttonState = BUTTON_STATE::DOWN;
		cout << "Right Mouse Button Clicked" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
	//	pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_RIGHT;
	//	buttonState = BUTTON_STATE::UP;
		cout << "Right Mouse Button Released" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
	{
		//pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_MIDDLE;
		//buttonState = BUTTON_STATE::DOWN;
		cout << "Middle Mouse Button Clicked" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE)
	{
		//pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_MIDDLE;
		//buttonState = BUTTON_STATE::UP;
		cout << "Middle Mouse Button Released" << endl;
	}
}

void mInput::CharacterCallback(GLFWwindow * window, unsigned int keyCode)
{
	cout << (char)keyCode << endl;
}

void mInput::CharacterModCallback(GLFWwindow * window, unsigned int keyCode, int modifierKeyCode)
{
	cout << (char)keyCode << "  :  " << modifierKeyCode << endl;

	if (keyCode == GLFW_KEY_A)
	{
		cout << "This works!" << endl;
	}





	switch (modifierKeyCode)
	{
	case 1:
		cout << "Shift Modifier Key has been Pressed" << endl;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		cout << "Alt Modifier Key has been Pressed" << endl;
		break;
	case 5:
		break;
	}

}
