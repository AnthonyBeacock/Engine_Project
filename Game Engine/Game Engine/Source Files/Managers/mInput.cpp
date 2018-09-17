#pragma once
#include "stdafx.h"
#include "mInput.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include <iostream>

mInput::MOUSE_BUTTONS mInput::pressedMouseButton;
mInput::MOUSE_BUTTON_STATE mInput::mouseButtonState;
mInput::KEYBOARD_BUTTONS mInput::pressedKeyboardButton;
mInput::KEYBOARD_BUTTON_STATE mInput::keyboardButtonState;

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

void mInput::ScrollWheelCallback(GLFWwindow * window, double xOffset, double yOffset)
{
	system("CLS");
	cout << "Scroll Wheel" << endl;
	cout << "X: " << xOffset << endl;
	cout << "Y: " << yOffset << endl;
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
		mouseButtonState = MOUSE_BUTTON_STATE::MOUSE_DOWN;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		cout << "Left Mouse Button Released" << endl;
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_LEFT;
		mouseButtonState = MOUSE_BUTTON_STATE::MOUSE_UP;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_RIGHT;
		mouseButtonState = MOUSE_BUTTON_STATE::MOUSE_DOWN;
		cout << "Right Mouse Button Clicked" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_RIGHT;
		mouseButtonState = MOUSE_BUTTON_STATE::MOUSE_UP;
		cout << "Right Mouse Button Released" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_MIDDLE;
		mouseButtonState = MOUSE_BUTTON_STATE::MOUSE_DOWN;
		cout << "Middle Mouse Button Clicked" << endl;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE)
	{
		pressedMouseButton = MOUSE_BUTTONS::MOUSE_BUTTON_MIDDLE;
		mouseButtonState = MOUSE_BUTTON_STATE::MOUSE_UP;
		cout << "Middle Mouse Button Released" << endl;
	}
}

void mInput::CharacterCallback(GLFWwindow * window, unsigned int keyCode)
{
	//cout << (char)keyCode << endl;
}

void mInput::CharacterModCallback(GLFWwindow * window, unsigned int keyCode, int modifierKeyCode)
{
	//cout << (char)keyCode << "  :  " << modifierKeyCode << endl;

	//unsigned int key = toupper((char)keyCode);

	/*if (key == GLFW_KEY_A)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_A;
	}
	if (key == GLFW_KEY_B)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_B;
	}
	if (key == GLFW_KEY_C)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_C;
	}
	if (key == GLFW_KEY_D)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_D;
	}
	if (key == GLFW_KEY_E)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_E;
	}
	if (key == GLFW_KEY_F)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F;
	}
	if (key == GLFW_KEY_G)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_G;
	}
	if (key == GLFW_KEY_H)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_H;
	}
	if (key == GLFW_KEY_I)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_I;
	}
	if (key == GLFW_KEY_J)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_J;
	}
	if (key == GLFW_KEY_K)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_K;
	}
	if (key == GLFW_KEY_L)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_L;
	}
	if (key == GLFW_KEY_M)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_M;
	}
	if (key == GLFW_KEY_N)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_N;
	}
	if (key == GLFW_KEY_O)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_O;
	}
	if (key == GLFW_KEY_P)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_P;
	}
	if (key == GLFW_KEY_Q)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Q;
	}
	if (key == GLFW_KEY_R)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_R;
	}
	if (key == GLFW_KEY_S)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_S;
	}
	if (key == GLFW_KEY_T)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_T;
	}
	if (key == GLFW_KEY_U)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_U;
	}
	if (key == GLFW_KEY_V)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_V;

	}
	if (key == GLFW_KEY_W)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_W;
	}
	if (key == GLFW_KEY_X)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_X;
	}
	if (key == GLFW_KEY_Y)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Y;
	}
	if (key == GLFW_KEY_Z)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Z;
	}
	if (key == GLFW_KEY_0)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_0;
	}
	if (key == GLFW_KEY_1)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_1;
	}
	if (key == GLFW_KEY_2)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_2;
	}
	if (key == GLFW_KEY_3)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_3;
	}
	if (key == GLFW_KEY_4)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_4;
	}
	if (key == GLFW_KEY_5)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_5;
	}
	if (key == GLFW_KEY_6)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_6;
	}
	if (key == GLFW_KEY_7)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_7;
	}
	if (key == GLFW_KEY_8)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_8;
	}
	if (key == GLFW_KEY_9)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_9;
		cout << "9 was pressed"
			<< endl;
	}*/


	//switch (modifierKeyCode)
	//{
	//case 1: // SHIFT
	//	cout << "Shift Modifier Key has been Pressed" << endl;
	//	break;
	//case 2: // CTRL
	//	cout << "CRTL Modifier Key has been Pressed" << endl;
	//	break;
	//case 3:
	//	break;
	//case 4: // ALT
	//	cout << "Alt Modifier Key has been Pressed" << endl;
	//	break;
	//case 5:
	//	break;
	//}
}

void mInput::KeyCallback(GLFWwindow * window, int key, int scanCode, int action, int mods)
{
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_A;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'A' Pressed" << endl;
	}
	if (key == GLFW_KEY_A && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'A' Released" << endl;
	}

	if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_B;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'B' Pressed" << endl;
	}
	if (key == GLFW_KEY_B && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'B' Released" << endl;
	}

	if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_C;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'C' Pressed" << endl;
	}
	if (key == GLFW_KEY_C && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'C' Released" << endl;
	}

	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_D;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'D' Pressed" << endl;
	}
	if (key == GLFW_KEY_D && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'D' Released" << endl;
	}

	if (key == GLFW_KEY_E && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_E;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'E' Pressed" << endl;
	}
	if (key == GLFW_KEY_E && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'E' Released" << endl;
	}

	if (key == GLFW_KEY_F && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F' Pressed" << endl;
	}
	if (key == GLFW_KEY_F && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F' Released" << endl;
	}

	if (key == GLFW_KEY_G && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_G;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'G' Pressed" << endl;
	}
	if (key == GLFW_KEY_G && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'G' Released" << endl;
	}

	if (key == GLFW_KEY_H && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_H;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'H' Pressed" << endl;
	}
	if (key == GLFW_KEY_H && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'H' Released" << endl;
	}

	if (key == GLFW_KEY_I && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_I;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'I' Pressed" << endl;
	}
	if (key == GLFW_KEY_I && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'I' Released" << endl;
	}

	if (key == GLFW_KEY_J && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_J;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'J' Pressed" << endl;
	}
	if (key == GLFW_KEY_J && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'J' Released" << endl;
	}

	if (key == GLFW_KEY_K && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_K;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'K' Pressed" << endl;
	}
	if (key == GLFW_KEY_K && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'K' Released" << endl;
	}

	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_L;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'L' Pressed" << endl;
	}
	if (key == GLFW_KEY_L && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'L' Released" << endl;
	}

	if (key == GLFW_KEY_M && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_M;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'M' Pressed" << endl;
	}
	if (key == GLFW_KEY_M && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'M' Released" << endl;
	}

	if (key == GLFW_KEY_N && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_N;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'N' Pressed" << endl;
	}
	if (key == GLFW_KEY_N && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'N' Released" << endl;
	}

	if (key == GLFW_KEY_O && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_O;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'O' Pressed" << endl;
	}
	if (key == GLFW_KEY_O && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'O' Released" << endl;
	}

	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_P;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'P' Pressed" << endl;
	}
	if (key == GLFW_KEY_P && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'P' Released" << endl;
	}

	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Q;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'Q' Pressed" << endl;
	}
	if (key == GLFW_KEY_Q && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'Q' Released" << endl;
	}

	if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_R;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'R' Pressed" << endl;
	}
	if (key == GLFW_KEY_R && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'R' Released" << endl;
	}

	if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_S;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'S' Pressed" << endl;
	}
	if (key == GLFW_KEY_S && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'S' Released" << endl;
	}

	if (key == GLFW_KEY_T && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_T;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'T' Pressed" << endl;
	}
	if (key == GLFW_KEY_T && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'T' Released" << endl;
	}

	if (key == GLFW_KEY_U && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_U;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'U' Pressed" << endl;
	}
	if (key == GLFW_KEY_U && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'U' Released" << endl;
	}

	if (key == GLFW_KEY_V && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_V;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'V' Pressed" << endl;
	}
	if (key == GLFW_KEY_V && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'V' Released" << endl;
	}

	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_W;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'W' Pressed" << endl;
	}
	if (key == GLFW_KEY_W && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'W' Released" << endl;
	}

	if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_X;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'X' Pressed" << endl;
	}
	if (key == GLFW_KEY_X && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'X' Released" << endl;
	}

	if (key == GLFW_KEY_Y && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Y;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'Y' Pressed" << endl;
	}
	if (key == GLFW_KEY_Y && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'Y' Released" << endl;
	}

	if (key == GLFW_KEY_Z && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_Z;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'Z' Pressed" << endl;
	}
	if (key == GLFW_KEY_Z && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'Z' Released" << endl;
	}

	if (key == GLFW_KEY_0 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_0;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '0' Pressed" << endl;
	}
	if (key == GLFW_KEY_0 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '0' Released" << endl;
	}

	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_1;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '1' Pressed" << endl;
	}
	if (key == GLFW_KEY_1 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '1' Released" << endl;
	}

	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_2;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '2' Pressed" << endl;
	}
	if (key == GLFW_KEY_2 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '2' Released" << endl;
	}

	if (key == GLFW_KEY_3 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_3;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '3' Pressed" << endl;
	}
	if (key == GLFW_KEY_3 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '3' Released" << endl;
	}

	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_4;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '4' Pressed" << endl;
	}
	if (key == GLFW_KEY_4 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '4' Released" << endl;
	}

	if (key == GLFW_KEY_5 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_5;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '5' Pressed" << endl;
	}
	if (key == GLFW_KEY_5 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '5' Released" << endl;
	}

	if (key == GLFW_KEY_6 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_6;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '6' Pressed" << endl;
	}
	if (key == GLFW_KEY_6 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '6' Released" << endl;
	}

	if (key == GLFW_KEY_7 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_7;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '7' Pressed" << endl;
	}
	if (key == GLFW_KEY_7 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '7' Released" << endl;
	}

	if (key == GLFW_KEY_8 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_8;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '8' Pressed" << endl;
	}
	if (key == GLFW_KEY_8 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '8' Released" << endl;
	}

	if (key == GLFW_KEY_9 && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_9;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key '9' Pressed" << endl;
	}
	if (key == GLFW_KEY_9 && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key '9' Released" << endl;
	}

	if (key == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_BACKSPACE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'BACKSPACE' Pressed" << endl;
	}
	if (key == GLFW_KEY_BACKSPACE && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'BACKSPACE' Released" << endl;
	}

	if ((key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_SHIFT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'SHIFT' Pressed" << endl;
	}
	if ((key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'SHIFT' Released" << endl;
	}

	if ((key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_CTRL;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'CTRL' Pressed" << endl;
	}
	if ((key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'CTRL' Released" << endl;
	}

	if ((key == GLFW_KEY_LEFT_ALT || key == GLFW_KEY_RIGHT_ALT) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_ALT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'ALT' Pressed" << endl;
	}
	if ((key == GLFW_KEY_LEFT_ALT || key == GLFW_KEY_RIGHT_ALT) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'ALT' Released" << endl;
	}

	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_DOWN_ARROW;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'DOWN ARROW' Pressed" << endl;
	}
	if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'DOWN ARROW' Released" << endl;
	}

	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_UP_ARROW;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'UP ARROW' Pressed" << endl;
	}
	if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'UP ARROW' Released" << endl;
	}

	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_RIGHT_ARROW;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'RIGHT ARROW' Pressed" << endl;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'RIGHT ARROW' Released" << endl;
	}

	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_LEFT_ARROW;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'LEFT ARROW' Pressed" << endl;
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'LEFT ARROW' Released" << endl;
	}

	if ((key == GLFW_KEY_ENTER || key == GLFW_KEY_KP_ENTER) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_ENTER;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'ENTER' Pressed" << endl;
	}
	if ((key == GLFW_KEY_ENTER || key == GLFW_KEY_KP_ENTER) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::No_Keyboard_Button;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'ENTER' Released" << endl;
	}
	if ((key == 32) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_SPACE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'SPACE' Pressed" << endl;
	}
	if ((key == 32) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_SPACE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'SPACE' Released" << endl;
	}
	if ((key == 39) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_APOSTROPHE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'APOSTROPHE' Pressed" << endl;
	}
	if ((key == 39) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_APOSTROPHE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'APOSTROPHE' Released" << endl;
	}
	if ((key == 44) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_COMMA;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'COMMA' Pressed" << endl;
	}
	if ((key == 44) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_COMMA;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'COMMA' Released" << endl;
	}
	if ((key == 45) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_MINUS;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'MINUS' Pressed" << endl;
	}
	if ((key == 45) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_MINUS;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'MINUS' Released" << endl;
	}
	if ((key == 46) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_FULL_STOP;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'FULL STOP' Pressed" << endl;
	}
	if ((key == 46) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_FULL_STOP;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'FULL STOP' Released" << endl;
	}
	if ((key == 47) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_FOWARD_SLASH;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'FORWARD SLASH' Pressed" << endl;
	}
	if ((key == 47) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_FOWARD_SLASH;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'FORWARD SLASH' Released" << endl;
	}
	if ((key == 162) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_BACK_SLASH;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'BACK SLASH' Pressed" << endl;
	}
	if ((key == 162) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_BACK_SLASH;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'BACK SLASH' Released" << endl;
	}
	if ((key == 92) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_HASH;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'HASH' Pressed" << endl;
	}
	if ((key == 92) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_HASH;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'HASH' Released" << endl;
	}
	if ((key == 59) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_SEMICOLON;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'SEMICOLON' Pressed" << endl;
	}
	if ((key == 59) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_SEMICOLON;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'SEMICOLON' Released" << endl;
	}
	if ((key == 61) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_EQUALS;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'EQUALS' Pressed" << endl;
	}
	if ((key == 61) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_EQUALS;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'EQUALS' Released" << endl;
	}
	if ((key == 91) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_LEFT_BRACKET;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'LEFT BRACKET' Pressed" << endl;
	}
	if ((key == 91) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_LEFT_BRACKET;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'LEFT BRACKET' Released" << endl;
	}
	if ((key == 93) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_RIGHT_BRACKET;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'RIGHT BRACKET' Pressed" << endl;
	}
	if ((key == 93) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_RIGHT_BRACKET;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'RIGHT BRACKET' Released" << endl;
	}
	if ((key == 96) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_GRAVE_ACCENT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'GRAVE ACCENT' Pressed" << endl;
	}
	if ((key == 96) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_GRAVE_ACCENT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'GRAVE ACCENT' Released" << endl;
	}
	if ((key == 258) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_TAB;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'TAB' Pressed" << endl;
	}
	if ((key == 258) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_TAB;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'TAB' Released" << endl;
	}
	if ((key == 260) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_INSERT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'INSERT' Pressed" << endl;
	}
	if ((key == 260) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_INSERT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'INSERT' Released" << endl;
	}
	if ((key == 261) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_DELETE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'DELETE' Pressed" << endl;
	}
	if ((key == 261) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_DELETE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'DELETE' Released" << endl;
	}
	if ((key == 266) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PAGE_UP;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'PAGE UP' Pressed" << endl;
	}
	if ((key == 266) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PAGE_UP;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'PAGE UP' Released" << endl;
	}if ((key == 267) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PAGE_DOWN;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'PAGE DOWN' Pressed" << endl;
	}
	if ((key == 267) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PAGE_DOWN;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'PAGE DOWN' Released" << endl;
	}
	if ((key == 268) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_HOME;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'HOME' Pressed" << endl;
	}
	if ((key == 268) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_HOME;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'HOME' Released" << endl;
	}
	if ((key == 269) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_END;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'END' Pressed" << endl;
	}
	if ((key == 269) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_END;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'END' Released" << endl;
	}
	if ((key == 280) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_CAPS_LOCK;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'CAPS LOCK' Pressed" << endl;
	}
	if ((key == 280) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_CAPS_LOCK;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'CAPS LOCK' Released" << endl;
	}
	if ((key == 281) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_SCROLL_LOCK;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'SCROLL LOCK' Pressed" << endl;
	}
	if ((key == 281) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_SCROLL_LOCK;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'SCROLL LOCK' Released" << endl;
	}
	if ((key == 282) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_NUM_LOCK;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'NUM LOCK' Pressed" << endl;
	}
	if ((key == 282) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_NUM_LOCK;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'NUM LOCK' Released" << endl;
	}
	if ((key == 283) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PRINT_SCREEN;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'PRINT SCREEN' Pressed" << endl;
	}
	if ((key == 283) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PRINT_SCREEN;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'PRINT SCREEN' Released" << endl;
	}
	if ((key == 284) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PAUSE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'PAUSE' Pressed" << endl;
	}
	if ((key == 284) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_PAUSE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'PAUSE' Released" << endl;
	}
	if ((key == 290) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F1;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F1' Pressed" << endl;
	}
	if ((key == 290) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F1;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F1' Released" << endl;
	}
	if ((key == 291) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F2;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F2' Pressed" << endl;
	}
	if ((key == 291) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F2;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F2' Released" << endl;
	}
	if ((key == 292) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F3;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F3' Pressed" << endl;
	}
	if ((key == 292) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F3;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F3' Released" << endl;
	}
	if ((key == 293) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F4;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F4' Pressed" << endl;
	}
	if ((key == 293) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F4;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F4' Released" << endl;
	}
	if ((key == 294) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F5;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F5' Pressed" << endl;
	}
	if ((key == 294) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F5;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F5' Released" << endl;
	}
	if ((key == 295) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F6;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F6' Pressed" << endl;
	}
	if ((key == 295) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F6;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F6' Released" << endl;
	}
	if ((key == 296) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F7;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F7' Pressed" << endl;
	}
	if ((key == 296) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F7;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F7' Released" << endl;
	}
	if ((key == 297) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F8;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F8' Pressed" << endl;
	}
	if ((key == 297) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F8;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F8' Released" << endl;
	}
	if ((key == 298) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F9;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F9' Pressed" << endl;
	}
	if ((key == 298) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F9;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F9' Released" << endl;
	}
	if ((key == 299) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F10;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F10' Pressed" << endl;
	}
	if ((key == 299) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F10;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F10' Released" << endl;
	}
	if ((key == 300) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F11;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F11' Pressed" << endl;
	}
	if ((key == 300) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F11;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F11' Released" << endl;
	}
	if ((key == 301) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F12;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'F12' Pressed" << endl;
	}
	if ((key == 301) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_F12;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'F12' Released" << endl;
	}
	if ((key == 320) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_0;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 0' Pressed" << endl;
	}
	if ((key == 320) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_0;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 0' Released" << endl;
	}
	if ((key == 321) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_1;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 1' Pressed" << endl;
	}
	if ((key == 321) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_1;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 1' Released" << endl;
	}
	if ((key == 322) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_2;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 2' Pressed" << endl;
	}
	if ((key == 322) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_2;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 2' Released" << endl;
	}
	if ((key == 323) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_3;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 3' Pressed" << endl;
	}
	if ((key == 323) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_3;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 3' Released" << endl;
	}
	if ((key == 324) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_4;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 4' Pressed" << endl;
	}
	if ((key == 324) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_4;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 4' Released" << endl;
	}
	if ((key == 325) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_5;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 5' Pressed" << endl;
	}
	if ((key == 325) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_5;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 5' Released" << endl;
	}
	if ((key == 326) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_6;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 6' Pressed" << endl;
	}
	if ((key == 326) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_6;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 6' Released" << endl;
	}
	if ((key == 327) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_7;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 7' Pressed" << endl;
	}
	if ((key == 327) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_7;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 7' Released" << endl;
	}
	if ((key == 328) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_8;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 8' Pressed" << endl;
	}
	if ((key == 328) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_8;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 8' Released" << endl;
	}
	if ((key == 329) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_9;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD 9' Pressed" << endl;
	}
	if ((key == 329) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_9;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD 9' Released" << endl;
	}
	if ((key == 330) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_DECIMAL;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD DECIMAL' Pressed" << endl;
	}
	if ((key == 330) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_DECIMAL;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD DECIMAL' Released" << endl;
	}
	if ((key == 331) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_DIVIDE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD DIVIDE' Pressed" << endl;
	}
	if ((key == 331) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_DIVIDE;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD DIVIDE' Released" << endl;
	}
	if ((key == 332) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_MULTIPLY;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD MULTIPLY' Pressed" << endl;
	}
	if ((key == 332) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_MULTIPLY;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD MULTIPLY' Released" << endl;
	}
	if ((key == 333) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_SUBTRACT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD SUBTRACT' Pressed" << endl;
	}
	if ((key == 333) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_SUBTRACT;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD SUBTRACT' Released" << endl;
	}
	if ((key == 334) && action == GLFW_PRESS)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_ADD;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_DOWN;
		cout << "Key 'KEY PAD ADD' Pressed" << endl;
	}
	if ((key == 334) && action == GLFW_RELEASE)
	{
		pressedKeyboardButton = KEYBOARD_BUTTONS::KEY_KP_ADD;
		keyboardButtonState = KEYBOARD_BUTTON_STATE::KEY_UP;
		cout << "Key 'KEY PAD ADD' Released" << endl;
	}
}
