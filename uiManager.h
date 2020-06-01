#pragma once
#include"singletonBase.h"
#include"UIScene.h"

class uiManager : public singletonBase<uiManager>
{
private:
	UIScene* _uiScene;
	gameScene* _gameScene;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void setgameSceneMemoryLink(gameScene* gameScene) { _gameScene = gameScene; }
	UIScene* getuiScene() { return _uiScene; }
	void set_invenon(bool onoff) { _uiScene->setinven_on(onoff); }
	bool get_restart_on() { return _uiScene->get_restart_on(); }

	void itemDBClick() { return _uiScene->itemDBClick(); }
};

