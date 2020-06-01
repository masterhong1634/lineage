#include "stdafx.h"
#include "uiManager.h"

uiManager::uiManager()
{
}

uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{
	_uiScene = new UIScene;
	_uiScene->init();
	_uiScene->setgameSceneMemoryLink(_gameScene);
	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
	_uiScene->update();
}

void uiManager::render(HDC hdc)
{
	_uiScene->render();
}