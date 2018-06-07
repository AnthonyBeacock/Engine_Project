#include "stdafx.h"
#include "cVelocity.h"

cVelocity::cVelocity(float velocity, float maxVelocity, float acceleration, bool gravity)
{
}

float cVelocity::GetVelocity()
{
	return velocity;
}

void cVelocity::SetVelocity(float velocityIn)
{
	velocity = velocityIn;
}

float cVelocity::GetMaxVelocity()
{
	return maxVelocity;
}

void cVelocity::SetMaxVelocity(float maxVelocityIn)
{
	maxVelocity = maxVelocityIn;
}

float cVelocity::GetAcceleration()
{
	return acceleration;
}

void cVelocity::SetAcceleration(float accelerationIn)
{
	acceleration = accelerationIn;
}

bool cVelocity::GetGravity()
{
	return gravity;
}

void cVelocity::SetGravity(bool gravityIn)
{
	gravity = gravityIn;
}

IComponent::ComponentMasks cVelocity::ComponentMask()
{
	return ComponentMasks::COMPONENT_VELOCITY;
}
