#include "stdafx.h"
#include "mainScene.h"


mainScene::mainScene()
{
}


mainScene::~mainScene()
{
}

HRESULT mainScene::init()
{
	ITEMMANAGER->init();
	SOUNDMANAGER->addSound("lin_bgm", "sound/0.mid", true, true);
	SOUNDMANAGER->play("lin_bgm", 0.15f);
	_gameScene = new gameScene;
	_gameScene->init();

	UI->setgameSceneMemoryLink(_gameScene);
	UI->init();
	
	_monsterManager = new monsterManager;
	_monsterManager->setgameSceneMemoryLink(_gameScene);
	_monsterManager->init();

	_gameScene->setMonsterManagerLink(_monsterManager);
	_gameScene->setUIMemoryLink(UI->getuiScene());


	IMAGEMANAGER->addFrameImage("tile", "images/tile1.bmp",
		0, 0, 100 * 8, (50 + 50) * 7, 8, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tile2", "images/tile3.bmp",
		0, 0, 100 * 21, (50 + 50) * 8, 21, 8, true, RGB(255, 0, 255));

	return S_OK;
}

void mainScene::release()
{
}

void mainScene::update()
{
	_gameScene->update();
	_monsterManager->update();
	UI->update();
	EFFECTMANAGER->update();
	if(SOUNDMANAGER->isPauseSound("lin_bgm")) SOUNDMANAGER->play("lin_bgm", 0.15f);
	if(SOUNDMANAGER->isPauseSound("lin_bgm")) SOUNDMANAGER->play("lin_bgm", 0.15f);
}

void mainScene::render()
{
	_gameScene->render();
	_monsterManager->render();
	UI->render(getMemDC());
	EFFECTMANAGER->render();
}
