#pragma once
#include <vector>
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include "mScene.h"

using namespace std;

class mInput
{
private:
	mScene * sceneManager;
	glm::vec2 mousePosition;
public:
	mInput(mScene* inSceneManager);
	~mInput();

	static void CursorPositionCallback(GLFWwindow * window, double xPosition, double yPosition);
	static void MouseButtonCallback(GLFWwindow * window, int button, int action, int mods);
	static void CharacterCallback(GLFWwindow * window, unsigned int keyCode);
	static void CharacterModCallback(GLFWwindow * window, unsigned int keyCode, int modifierKeyCode);

	static void KeyCallback(GLFWwindow * window, int button, int scanCode, int action, int mods);

	static void CursorVisible(GLFWwindow * window, bool isVisible);
	static void CenterCursor(GLFWwindow * window, bool isCentered);
	static void ScrollWheelCallback(GLFWwindow * window, double xOffset, double yOffset);

	enum MOUSE_BUTTONS
	{
		MOUSE_BUTTON_LEFT, MOUSE_BUTTON_RIGHT, MOUSE_BUTTON_MIDDLE, NO_MOUSE_BUTTON,
	};
	static MOUSE_BUTTONS pressedMouseButton;

	enum KEYBOARD_BUTTONS
	{
		// LETTERS
		KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M,
		KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,

		// NUMBERS
		KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,

		// ARROWS
		KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW,

		// OTHER
		KEY_SHIFT, KEY_SPACE, KEY_BACKSPACE, KEY_CTRL, KEY_ALT, KEY_ENTER,

		No_Keyboard_Button
	};
	static KEYBOARD_BUTTONS pressedKeyboardButton;

	enum MOUSE_BUTTON_STATE
	{
		MOUSE_DOWN, MOUSE_UP,
	};
	static MOUSE_BUTTON_STATE mouseButtonState;

	enum KEYBOARD_BUTTON_STATE
	{
		KEY_DOWN, KEY_UP,
	};
	static KEYBOARD_BUTTON_STATE keyboardButtonState;
};

