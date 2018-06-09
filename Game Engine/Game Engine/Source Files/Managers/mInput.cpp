#pragma once
#include "stdafx.h"
#include "mInput.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include <iostream>

mInput::MOUSE_BUTTONS mInput::pressedMouseButton;
mInput::BUTTON_STATE mInput::buttonState;
mInput::KEYBOARD_BUTTONS mInput::pressedKeyboardButton;

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

void mInput::CenterCursor(GLFWwindow * window, bool isCentered)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width / 2, height / 2);

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
		buttonState = BUTTON_STATE::DOWN;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		cout << "Left Mouse Button Released" << endl;
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_LEFT;
		buttonState = BUTTON_STATE::UP;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_RIGHT;
		buttonState = BUTTON_STATE::DOWN;
		cout << "Right Mouse Button Clicked" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_RIGHT;
		buttonState = BUTTON_STATE::UP;
		cout << "Right Mouse Button Released" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_MIDDLE;
		buttonState = BUTTON_STATE::DOWN;
		cout << "Middle Mouse Button Clicked" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_MIDDLE;
		buttonState = BUTTON_STATE::UP;
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

	switch (toupper((char)keyCode))
	{
	case 'A':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_A;
		break;
	case 'B':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_B;
		break;
	case 'C':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_C;
		break;
	case 'D':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_D;
		break;
	case 'E':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_E;
		break;
	case 'F':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F;
		break;
	case 'G':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_G;
		break;
	case 'H':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_H;
		break;
	case 'I':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_I;
		break;
	case 'J':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_J;
		break;
	case 'K':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_K;
		break;
	case 'L':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_L;
		break;
	case 'M':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_M;
		break;
	case 'N':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_N;
		break;
	case 'O':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_O;
		break;
	case 'P':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_P;
		break;
	case 'Q':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Q;
		break;
	case 'R':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_R;
		break;
	case 'S':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_S;
		break;
	case 'T':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_T;
		break;
	case 'U':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_U;
		break;
	case 'V':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_V;
		break;
	case 'W':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_W;
		break;
	case 'X':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_X;
		break;
	case 'Y':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Y;
		break;
	case 'Z':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Z;
		break;
	case '0':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_0;
		break;
	case '1':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_1;
		break;
	case '2':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_2;
		break;
	case '3':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_3;
		break;
	case '4':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_4;
		break;
	case '5':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_5;
		break;
	case '6':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_6;
		break;
	case '7':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_7;
		break;
	case '8':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_8;
		break;
	case '9':
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_9;
		break;
	}

	switch (modifierKeyCode)
	{
	case 1: // SHIFT
		cout << "Shift Modifier Key has been Pressed" << endl;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4: // ALT
		cout << "Alt Modifier Key has been Pressed" << endl;
		break;
	case 5:
		break;
	}
}