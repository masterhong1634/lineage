#pragma once
#include"singletonBase.h"

class gameScene;
class maptileManager : public singletonBase<maptileManager>
{
private:
	gameScene* _gameScene;
public:
	maptileManager();
	~maptileManager();

	int getStartX();
	int getStartY();
};

