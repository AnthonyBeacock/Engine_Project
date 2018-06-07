#ifndef RESOURCEMANAGER
#define RESOURCEMANAGER
#include <map>
#include "oGeometry.h"

using namespace std;

class mResource
{
public:
	mResource();
	~mResource();

	static int LoadTexture();
	static void LoadShader();
	static oGeometry LoadGeometry();
	//static AudioBuffer LoadWAV();
	
private:
	map<string, int> textureDict;
	map<string, int> shaderDict;
	//map<string, Geometry> geometryDict;
	//map<string, AudioBuffer> audioDict;
};

#endif // RESOURCEMANAGER


