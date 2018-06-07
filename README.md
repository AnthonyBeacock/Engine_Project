# Engine-Project

## Contributors:

###### Anthony Beacock:
- Audio System
- Audio Buffer Object
- Resource Manager (High Priority)
- Input Manager (High Priority)
- Render System (Basic Rendering High Priority)

###### Dean Barnard:
- Physics System
- Collision System
- System Manager (High Priority)
- Entity Manager (High Priority)
- Entity Object (High Priority)

###### Jakob Scrivener:
- Render System (Basic Rendering High Priority)
- Geometry Object (Basic Geometry High Priority)
- Resource Manager (High Priority)
- Camera Object

###### Reece Giles:
- AI System
- Scene Manager (High Priority)
- Scene Object (High Priority)
- GUI Object

## Libraries:

###### GLFW

GLFW provides basic functionality to create an OpenGL window, without having to mess around with Win32 API. 

#include "GLFW\glfw3.h"

###### GLM

GLM provides magical maths things like Vector maths etc.

#include "glm\glm.hpp"

###### OpenAL

To make OpenAL work you may have to modify your filepaths in project properties to point towards the location of the OpenAL folder:

1. Right-Click on the Project Solution and select Properties.

2. Go to "C/C++ -> General -> Additional Include Directories" and add in correct filepath e.g.
	(...\Engine-Project\OpenAL\openal-soft-1.18.2-bin\openal-soft-1.18.2-bin\include\AL)

3. Go to "Linker -> General -> Additional Library Directories" and add in correct filepath e.g.
	(...\Engine-Project\OpenAL\openal-soft-1.18.2-bin\openal-soft-1.18.2-bin\libs\Win32)

4. Go to to "Linker -> Input -> Additional Dependencies" and add in OpenAL32.lib; directly before %(AdditionalDependencies)

#include "al.h" 
#include "alc.h" 
#include "alut.h"

## Engine Design:

Download NClass to view the Engine Design.ncp, already contains a framework of the core stuff we'll need, feel free to add stuff/flesh out the classes.

http://nclass.sourceforge.net/

## Coding Conventions

- Use Include Guards in all header files (https://www.youtube.com/watch?v=RU5JUHAiR18&app=desktop)
- Name files appropriately (eg. Components = cHealth, Managers = mSystem, Systems = mRender, Objects = oEntity)
- Pass by value if small type like int, pass by reference if larger object, pass by pointer if you absolutely need to (eg. parameter can be null)
