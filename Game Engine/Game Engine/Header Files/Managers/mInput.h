#pragma once
#include <vector>
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include "mScene.h"

using namespace std;

class mInput
{
private:
	glm::vec2 mousePosition;
public:

	mInput(mScene* inSceneManager);
	~mInput();

	mScene* sceneManager;

	static void CursorPositionCallback(GLFWwindow * window, double xPosition, double yPosition);
	static void CursorVisible(GLFWwindow * window, bool isVisible);
	static void MouseButtonCallback(GLFWwindow * window, int button, int action, int mods);

	static void CharacterCallback(GLFWwindow * window, unsigned int keyCode);
	static void CharacterModCallback(GLFWwindow * window, unsigned int keyCode, int modifierKeyCode);

	//enum MOUSE_BUTTONS
	//{
	//	MOUSE_BUTTON_LEFT,
	//	MOUSE_BUTTON_RIGHT,
	//	MOUSE_BUTTON_MIDDLE,
	//	NO_MOUSE_BUTTON,
	//};

	/*enum KEYBOARD_BUTTONS
	{
		KEY_W,
		KEY_A,
		KEY_S,
		KEY_D,
		KEY_SHIFT,
		KEY_SPACE,
		No_Keyboard_Button
	};
	KEYBOARD_BUTTONS pressedKeyboardButton;

	enum BUTTON_STATE
	{
		DOWN,
		UP,
	};
	BUTTON_STATE buttonState;*/

	void CenterCursor(GLFWwindow * window);
	void KeyDown();
	void KeyUp();
	void MouseClickUp();
	void MouseMovement();

	vector<string> keyboardInput; // dont use the strings, use enums instead
	vector<string> mouseInput;


};

