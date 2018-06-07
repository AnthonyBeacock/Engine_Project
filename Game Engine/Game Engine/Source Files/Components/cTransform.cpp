#include "stdafx.h"
#include "cTransform.h"

cTransform::cTransform(vec3 & t, vec3 & r, vec3 & s)
{
	translation = t;
	rotation = r;
	scale = s;
	transformSet = false;
}

void cTransform::SetTransform()
{
	transformSet = true;
}

vec3& cTransform::GetTranslation()
{
	return translation;
}

void cTransform::SetTranslation(vec3 &translationIn)
{
	translation = translationIn;
}

vec3& cTransform::GetRotation()
{
	return rotation;
}

void cTransform::SetRotation(vec3 &rotationIn)
{
	rotation = rotationIn;
}

vec3& cTransform::GetScale()
{
	return scale;
}

void cTransform::SetScale(vec3 &scaleIn)
{
	scale = scaleIn;
}

mat4& cTransform::GetTransform()
{
	return transform;
}

void cTransform::SetTransform(mat4 &transformIn)
{
	transform = transformIn;
}

vec3& cTransform::GetForward()
{
	return forward;
}

void cTransform::SetForward(vec3 &forwardIn)
{
	forward = forwardIn;
}

vec3& cTransform::GetRight()
{
	return right;
}

void cTransform::SetRight(vec3 &rightIn)
{
	right = rightIn;
}

vec3& cTransform::GetUp()
{
	return up;
}

void cTransform::SetUp(vec3 &upIn)
{
	up = upIn;
}

IComponent::ComponentMasks cTransform::ComponentMask()
{
	return ComponentMasks::COMPONENT_TRANSFORM;
}
