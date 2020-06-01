#include "stdafx.h"
#include "startScene.h"


startScene::startScene()
{
}


startScene::~startScene()
{
}

HRESULT startScene::init()
{
	IMAGEMANAGER->addFrameImage("start_page", "images/start_page.bmp", WINSIZEX * 20, WINSIZEY, 20, 1, true, RGB(255,0,255));

	//EFFECTMANAGER->addEffect("start_page", "images/start_page.bmp", WINSIZEX * 20, WINSIZEY, WINSIZEX, WINSIZEY, 1, 0.05f, 2);
	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
	//EFFECTMANAGER->play("start_page", 600, 450);
	count++;
	if (count == 50)
	{
		_index_x++;
		count = 0;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		SCENEMANAGER->changeScene("mainScene");
	}

}

void startScene::render()
{
	if(_index_x >= 0 && _index_x <= 20)
	IMAGEMANAGER->frameRender("start_page", getMemDC(), 0, 0, _index_x, 0);
}
