#include "stdafx.h"
#include "mScene.h"
#include "mInput.h"


mScene::mScene()
{
}

mScene::~mScene()
{
}

int mScene::InitialiseGLFW()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}
}

int mScene::OpenWindow(const char* titleString, int width, int height, bool isResizable)
{
	glfwWindowHint(GLFW_SAMPLES, 4);

	if (isResizable)
	{
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	}
	else
	{
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(width, height, titleString, NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	//glfwSetKeyCallback(window, mInput::keyCallback);
	//glfwSetCharCallback(window, mInput::CharacterCallback); // allows keyboard keys to be tracked (produced ASCII code)
	glfwSetCharModsCallback(window, mInput::CharacterModCallback); // allows keyboard keys to be tracked (produced ASCII code)
	glfwSetCursorPosCallback(window, mInput::CursorPositionCallback); // allows cursor position to be tracked
	glfwSetMouseButtonCallback(window, mInput::MouseButtonCallback); // allows mouse buttons to be tracked
}

void mScene::Render()
{
	glClearColor(0.15f, 0.15f, 0.15f, 0.0f);

	do {
		glClear(GL_COLOR_BUFFER_BIT);

		// DRAW HERE


		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
}

void mScene::Update()
{
	do {

		// UPDATE HERE

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}
