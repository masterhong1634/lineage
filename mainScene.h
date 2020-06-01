#pragma once
#include"gameNode.h"
#include"gameScene.h"
#include"UIScene.h"
#include"monsterManager.h"

class mainScene : public gameNode
{
private:
	gameScene* _gameScene;
	monsterManager* _monsterManager;
	UIScene* _UIScene;

public:
	mainScene();
	~mainScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

