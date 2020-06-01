#pragma once
#include"gameNode.h"
#include"Monster.h"

class gameScene;
class monsterManager : public gameNode
{
private:
	typedef vector<Monster*> vMonster;
	typedef vector<Monster*>::iterator viMonster;
	gameScene* _gameScene;

	vMonster	_vMonster;
	viMonster	_viMonster;

	bool _monRect_on = false;
	bool _mon_hpbar_on = true;

	char str1[128];

public:
	monsterManager();
	~monsterManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setMonster();

	vMonster	getVMonster() { return _vMonster; }
	viMonster	getViMonster() { return _viMonster; }

	void removeMonster();

	void monster_click();

	void setgameSceneMemoryLink(gameScene* gameScene) { _gameScene = gameScene; }
};

