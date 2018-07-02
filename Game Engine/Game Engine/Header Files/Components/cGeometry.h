#ifndef GEOMETRYCOMPONENT
#define GEOMETRYCOMPONENT

#include "IComponent.h"
#include <string>

using namespace std;

class cGeometry:IComponent
{
public:
	cGeometry();
	~cGeometry();
	int GetGeometry();
	void SetGeometry(string &filename);
	ComponentMasks ComponentMask() override;
	
};
#endif // GEOMETRYCOMPONENT

