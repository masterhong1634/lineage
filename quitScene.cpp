#include "stdafx.h"
#include "quitScene.h"

quitScene::quitScene()
{
}

quitScene::~quitScene()
{
}

HRESULT quitScene::init()
{
	IMAGEMANAGER->addImage("quitScene", "images/quitScene.bmp", WINSIZEX, WINSIZEY, true, RGB(255,0,255));
	return S_OK;
}

void quitScene::release()
{
}

void quitScene::update()
{
	RECT _rect{ 0,0,WINSIZEX,WINSIZEY };
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		SCENEMANAGER->changeScene("mainScene");
}

void quitScene::render()
{
	IMAGEMANAGER->render("quitScene", getMemDC());
}
