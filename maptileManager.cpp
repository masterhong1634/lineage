#include "stdafx.h"
#include "maptileManager.h"
#include "gameScene.h"


maptileManager::maptileManager()
{
	_gameScene = new gameScene;
}


maptileManager::~maptileManager()
{
}

int maptileManager::getStartX()
{
	return _gameScene->getStartX();
}

int maptileManager::getStartY()
{
	return _gameScene->getStartY();
}
