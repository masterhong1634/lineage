#include "stdafx.h"
#include "monsterManager.h"
#include "gameScene.h"

monsterManager::monsterManager()
{
}

monsterManager::~monsterManager()
{
}

HRESULT monsterManager::init()
{
	setMonster();
	_viMonster = _vMonster.begin();

	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{		
		(*_viMonster)->init();
	}
	return S_OK;
}

void monsterManager::release()
{
}

void monsterManager::update()
{
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_monRect_on = !_monRect_on;
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_mon_hpbar_on = !_mon_hpbar_on;
	}
	for (int i = 0; i < _vMonster.size(); i++)
	{
		_vMonster[i]->setgameSceneMemoryLink(_gameScene);
		_vMonster[i]->update();

		if (_mon_hpbar_on) _vMonster[i]->set_mon_hpbar_on(true);
		else _vMonster[i]->set_mon_hpbar_on(false);

		if (_vMonster[i]->get_monster_hp() <= 0)
		{
			if (_vMonster[i]->get_monster_form() == monster_form::ORC) _gameScene->set_player_adena(250 + RND->getInt(150));
			else if (_vMonster[i]->get_monster_form() == monster_form::WOLFMAN)  _gameScene->set_player_adena(550 + RND->getInt(250));

			_gameScene->set_player_attack_on(false);

			if (_vMonster[i]->get_monster_form() == monster_form::ORC) _gameScene->set_player_lawful(16);
			else if (_vMonster[i]->get_monster_form() == monster_form::WOLFMAN)  _gameScene->set_player_lawful(32);
			_vMonster.erase(_vMonster.begin() + i);
		}
	}
}

void monsterManager::render()
{
	_viMonster = _vMonster.begin();

	int i = 0;
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		i++;
		(*_viMonster)->render();
		if (_monRect_on)
		{
			Rectangle(getMemDC(), (*_viMonster)->get_monster_rect().left, (*_viMonster)->get_monster_rect().top,
				(*_viMonster)->get_monster_rect().right, (*_viMonster)->get_monster_rect().bottom);
		}
		//sprintf_s(str1, "monster.hp : %d", (*_viMonster)->get_monster_hp());
		//TextOut(getMemDC(), 0, 130 + i * 20, str1, strlen(str1));
	}
}

void monsterManager::setMonster()
{
	for (int i = 68; i < 81; i+=3)
	{
		for (int j = 108; j < 120; j+=3)
		{
			Monster* _monster;
			_monster = new Monster(i + RND->getInt(2) ,j + RND->getInt(2) ,monster_form::WOLFMAN);
			_monster->setgameSceneMemoryLink(_gameScene);
			_vMonster.push_back(_monster);
		}
	}

	for (int i = 70; i < 80; i += 4)
	{
		for (int j = 65; j < 75; j += 4)
		{
			Monster* _monster;
			_monster = new Monster(i + RND->getInt(2), j + RND->getInt(2), monster_form::ORC);
			_monster->setgameSceneMemoryLink(_gameScene);
			_vMonster.push_back(_monster);
		}
	}

	for (int i = 38; i < 53; i += 6)
	{
		for (int j = 56; j < 69; j += 6)
		{
			Monster* _monster;
			_monster = new Monster(i + RND->getInt(3), j + RND->getInt(3), monster_form::ORC);
			_monster->setgameSceneMemoryLink(_gameScene);
			_vMonster.push_back(_monster);
		}
	}

	for (int i = 38; i < 53; i += 6)
	{
		for (int j = 56; j < 69; j += 6)
		{
			Monster* _monster;
			_monster = new Monster(i + RND->getInt(3), j + RND->getInt(3), monster_form::WOLFMAN);
			_monster->setgameSceneMemoryLink(_gameScene);
			_vMonster.push_back(_monster);
		}
	}
}

void monsterManager::removeMonster()
{
}

void monsterManager::monster_click()
{

}
