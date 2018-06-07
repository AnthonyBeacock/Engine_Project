#ifndef ENTITY_M
#define ENTITY_M

#include <string>
#include <vector>
#include "oEntity.h"

using namespace std;

class mEntity
{
private:
	vector<oEntity> entities;
	vector<string> entityNames;

public:;
	mEntity();
	~mEntity();
	oEntity FindEntity(string &name);
	void AddEntity(oEntity &entity);
	void RemoveEntity(oEntity *entity);
	vector<oEntity>& Entites();

};

#endif // !ENTITY_M