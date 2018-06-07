#ifndef TRANSFORM
#define TRANSFORM

#include "IComponent.h"
#include "glm\glm.hpp"

using namespace glm;

class cTransform : public IComponent
{
private:
	mat4 transform;

	vec3 forward;
	vec3 right;
	vec3 up;
	vec3 translation;
	vec3 rotation;
	vec3 scale;

	bool transformSet;

public:
	cTransform(vec3 &t, vec3 &r, vec3 &s);
	void SetTransform();
	vec3& GetTranslation();
	void SetTranslation(vec3 &translationIn);
	vec3& GetRotation();
	void SetRotation(vec3 &rotationIn);
	vec3& GetScale();
	void SetScale(vec3 &scaleIn);
	mat4& GetTransform();
	void SetTransform(mat4 &transformIn);
	vec3& GetForward();
	void SetForward(vec3 &forwardIn);
	vec3& GetRight();
	void SetRight(vec3 &rightIn);
	vec3& GetUp();
	void SetUp(vec3 &upIn);
	ComponentMasks ComponentMask();
};

#endif
