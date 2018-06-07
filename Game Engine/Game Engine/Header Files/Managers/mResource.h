#ifndef RESOURCEMANAGER
#define RESOURCEMANAGER
#include <map>;

using namespace std;

class mResource
{
public:
	mResource();
	~mResource();

	static int LoadTexture();
	static void LoadShader();
	//static AudioBuffer LoadWAV();
	//static Geometry LoadGeometry();
	
private:
	map<string, int> textureDict;
	map<string, int> shaderDict;
	//map<string, Geometry> geometryDict;
	//map<string, AudioBuffer> audioDict;
};

#endif // RESOURCEMANAGER


