#pragma once
class IScene
{
protected:
	virtual void Render() = 0;
	virtual void Update() = 0;
};

