#include "stdafx.h"
#include "gameScene.h"
#include "Monster.h"
#include "resource1.h"
#include "UIScene.h"
#include "monsterManager.h"


gameScene::gameScene()
{
}


gameScene::~gameScene()
{
}

HRESULT gameScene::init()
{
	//Main Map
	IMAGEMANAGER->addImage("linmap", "images/townmap.bmp", 0, 0, 4400 * 1.5, 2700 * 1.5, true, RGB(255, 0, 255));
	//MIni Map
	IMAGEMANAGER->addImage("minimap", "images/townmap.bmp", 0, 0, 440 * 1.5, 270 * 1.5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Direction_indicator", "images/Direction_indicator.bmp", 144, 18, 8, 1, true, RGB(255, 0, 255));

	//각종 사운드 추가
	SOUNDMANAGER->addSound("meteor", "sound/meteor.mp3", false, false);
	SOUNDMANAGER->addSound("icespike", "sound/icespike.mp3", false, false);
	SOUNDMANAGER->addSound("orc_damage", "sound/orc_damage.mp3", false, false);
	SOUNDMANAGER->addSound("wolf_damage", "sound/wolf_damage.mp3", false, false);
	SOUNDMANAGER->addSound("lightning", "sound/lightning.mp3", false, false);
	
	//Player Motion
	IMAGEMANAGER->addFrameImage("player_right", "images/magician/player_right.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_left", "images/magician/player_left.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_up", "images/magician/player_up.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_down", "images/magician/player_down.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_lefttop", "images/magician/player_lefttop.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_righttop", "images/magician/player_righttop.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_rightbottom", "images/magician/player_rightbottom.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_leftbottom", "images/magician/player_leftbottom.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_stop", "images/magician/player_stop.bmp", 120*1.5, 60*1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_middlebottom", "images/magician/pl_att_middlebottom.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_middletop", "images/magician/pl_att_middletop.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_middleleft", "images/magician/pl_att_middleleft.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_middleright", "images/magician/pl_att_middleright.bmp", 440 , 170 , 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_rightbottom", "images/magician/pl_att_rightbottom.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_righttop", "images/magician/pl_att_righttop.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_lefttop", "images/magician/pl_att_lefttop.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("pl_att_leftbottom", "images/magician/pl_att_leftbottom.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_middleright", "images/magician/staff_middleright.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_leftbottom", "images/magician/staff_leftbottom.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_lefttop", "images/magician/staff_lefttop.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_middlebottom", "images/magician/staff_middlebottom.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_middleleft", "images/magician/staff_middleleft.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_middletop", "images/magician/staff_middletop.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_rightbottom", "images/magician/staff_rightbottom.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("staff_righttop", "images/magician/staff_righttop.bmp", 440, 170, 4, 1, true, RGB(255, 0, 255));

	//Orc Motion
	IMAGEMANAGER->addFrameImage("orc_right", "images/orc/orc_middleright.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_left", "images/orc/orc_middleleft.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_up", "images/orc/orc_middletop.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_down", "images/orc/orc_middledown.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_lefttop", "images/orc/orc_lefttop.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_righttop", "images/orc/orc_righttop.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_rightbottom", "images/orc/orc_rightbottom.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_leftbottom", "images/orc/orc_leftdown.bmp", 200 * 1.5, 50 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_leftbottom", "images/orc/orc_att_leftbottom.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_lefttop", "images/orc/orc_att_lefttop.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_middlebottom", "images/orc/orc_att_middlebottom.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_middleleft", "images/orc/orc_att_middleleft.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_middleright", "images/orc/orc_att_middleright.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_middletop", "images/orc/orc_att_middletop.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_rightbottom", "images/orc/orc_att_rightbottom.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orc_att_righttop", "images/orc/orc_att_righttop.bmp", 200 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	
	//WolfMan Motion
	IMAGEMANAGER->addFrameImage("wol_right", "images/wol/wol_middleright.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_left", "images/wol/wol_middleleft.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_up", "images/wol/wol_middletop.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_down", "images/wol/wol_middlebottom.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_lefttop", "images/wol/wol_lefttop.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_righttop", "images/wol/wol_righttop.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_rightbottom", "images/wol/wol_rightbottom.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_leftbottom", "images/wol/wol_leftbottom.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_leftbottom", "images/wol/wol_att_leftbottom.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_lefttop", "images/wol/wol_att_lefttop.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_middlebottom", "images/wol/wol_att_middlebottom.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_middleleft", "images/wol/wol_att_middleleft.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_middleright", "images/wol/wol_att_middleright.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_middletop", "images/wol/wol_att_middletop.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_rightbottom", "images/wol/wol_att_rightbottom.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wol_att_righttop", "images/wol/wol_att_righttop.bmp", 240 * 1.5, 70 * 1.5, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("shop", "images/shop.bmp", 0, 0, 232 * 1.5, 309 * 1.5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shop_buy", "images/shop_buy.bmp", 0, 0, 248 * 1.5, 375 * 1.5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("inventory", "images/inventory.bmp", 0, 0, 181 * 1.5, 275 * 1.5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("UI", "images/UI.bmp", 0, 0, 1200, 203, true, RGB(255, 0, 255));

	//Skill
	EFFECTMANAGER->addEffect("meteor", "images/meteor.bmp", 1600, 400, 400, 400, 1, 0.07f, 5);
	EFFECTMANAGER->addEffect("icespike", "images/icespike.bmp", 600, 150, 150, 150, 1, 0.1f, 5);
	EFFECTMANAGER->addEffect("lightning", "images/lightning.bmp", 600, 400, 150, 400, 1, 0.1f, 5);
	EFFECTMANAGER->addEffect("immune", "images/immune.bmp", 320, 400, 80, 400, 1, 0.1f, 5);
	EFFECTMANAGER->addEffect("white_potion_effect", "images/white_potion_effect.bmp", 240, 60, 60, 60, 1, 0.1f, 5);

	_isoX = 86;
	_isoY = 75;
	_start_i = _isoX;
	_start_j = _isoY;

	_startX = INIT_X;
	_startY = INIT_Y;
	_player_direct = RIGHTTOP;
	_player_move = false;
	_player_attack_on = false;
	_calcul_on = false;


	_center = 0;
	memset(_tileMap, 0, sizeof(_tileMap));

	Load(1);
	_tileMap[86][75].tileKind[0] = TILEKIND_PLAYER;

	tileInitializing();

	_isDebug = true;

	_player_form = MAGICIAN;

	_player_rect = { 570, 270, 630, 360 };

	//hp bar
	_maxHP = _player_stats._maxHp;
	_currentHP = _player_stats._hp;
	_hpBar = new progressBar;
	_hpBar->init("images/hpbarFront.bmp", "images/barBack.bmp", 0, 0, 213, 15);
	_hpBar->setGauge(_currentHP, _maxHP);

	//mp bar
	_maxMP = _player_stats._maxMp;
	_currentMP = _player_stats._mp;
	_mpBar = new progressBar;
	_mpBar->init("images/mpbarFront.bmp", "images/barBack.bmp", 0, 0, 213, 15);
	_mpBar->setGauge(_currentMP, _maxMP);
	return S_OK;
}

void gameScene::release()
{
}

void gameScene::update()
{
	//판도라(상점)
	pandora = { static_cast<int>(_startX + 1050), static_cast<int>(_startY + 3050), static_cast<int>(_startX + 1100), static_cast<int>(_startY + 3150) };
	close_rect = { 320, 7, 345, 32 };
	close_rect2 = { 346, 3, 371, 30 };
	buy_rect = { 105, 280, 240, 360 };
	buy_rect2 = { 0, 0, static_cast<int> (248*1.5), static_cast<int> (375*1.5) };
	buy_rect3 = { 0, 0, static_cast<int> (232*1.5), static_cast<int> (309*1.5) };
	inven_rect = { static_cast<int>(WINSIZEX - 181 * 1.5), 0, WINSIZEX, static_cast<int>(275 * 1.5) };
	UI_rect = { 0, WINSIZEY - 203, 1200, WINSIZEY };

	if (KEYMANAGER->isOnceKeyDown(VK_F5))
	{
		_player_stats._hp += 15 + RND->getInt(10);
		if (_player_stats._hp > _player_stats._maxHp) _player_stats._hp = _player_stats._maxHp;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F6))
	{
		_player_stats._hp += 45 + RND->getInt(15);
		if (_player_stats._hp > _player_stats._maxHp) _player_stats._hp = _player_stats._maxHp;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F7))
	{
		_skill_meteor = true;
		_skill_icespike = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F8))
	{
		_skill_icespike = true;
		_skill_meteor = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		_player_stats._mp += 35 + RND->getInt(10);
		if (_player_stats._mp > _player_stats._maxMp) _player_stats._mp = _player_stats._maxMp;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F10))
	{
		frame_attack_speed /= 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_isDebug = !_isDebug;
	}	
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_player_rect_on = !_player_rect_on;
	}
	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_start_i = 88;
		_start_j = 70;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		EFFECTMANAGER->update();
		
		if (_player_attack_on) return;
		if (_UIScene->getShop_on())
		{
			if (PtInRect(&close_rect, m_ptMouse))
			{
				return;
			}				
			if (PtInRect(&buy_rect, m_ptMouse))
			{
				return;
			}	
			if (PtInRect(&buy_rect3, m_ptMouse))
			{
				return;
			}
		}
		if (_UIScene->getShop_buy())
		{
			if (PtInRect(&close_rect2, m_ptMouse))
			{
				return;
			}
			if (PtInRect(&buy_rect2, m_ptMouse))
			{
				return;
			}
		}

		if (_UIScene->getinven_on())
		{
			if (PtInRect(&inven_rect, m_ptMouse))
			{
				return;
			}
		}
		if (PtInRect(&UI_rect, m_ptMouse))
		{
			return;
		}
		for (int i = 0; i < _monsterManager->getVMonster().size(); i++)
		{
			if (abs(_monsterManager->getVMonster()[i]->get_start_isoX() - _start_i) < 8 && abs(_monsterManager->getVMonster()[i]->get_start_isoY() - _start_j) < 8 &&
				PtInRect(&_monsterManager->getVMonster()[i]->get_monster_rect(), m_ptMouse))
			{
				if (_skill_meteor && _player_stats._mp >= 60 )
				{
					EFFECTMANAGER->play("meteor", _monsterManager->getVMonster()[i]->get_monster_rect().left + 30,
						_monsterManager->getVMonster()[i]->get_monster_rect().top - 30);
					SOUNDMANAGER->play("meteor", 0.5f);
					if (SOUNDMANAGER->isPauseSound("meteor")) SOUNDMANAGER->play("meteor", 0.5f);

					_skill_meteor = false;
					_player_stats._mp -= 60;

					meteor_rect = { _monsterManager->getVMonster()[i]->get_monster_rect().left - 120, _monsterManager->getVMonster()[i]->get_monster_rect().top - 40,
						_monsterManager->getVMonster()[i]->get_monster_rect().right + 120, _monsterManager->getVMonster()[i]->get_monster_rect().bottom + 40 };

					for (int i = 0; i < _monsterManager->getVMonster().size(); i++)
					{
						if (IntersectRect(&temp, &meteor_rect, &_monsterManager->getVMonster()[i]->get_monster_rect()))
						{
							_monsterManager->getVMonster()[i]->set_monster_hp (-50 - RND->getInt(20) - 3 * _player_stats._spell_power);
						}
					}

					if (_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::ORC)
					{
						SOUNDMANAGER->play("orc_damage", 0.5f);
						if (SOUNDMANAGER->isPauseSound("orc_damage")) SOUNDMANAGER->play("orc_damage", 0.5f);
					}

					else if (_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::WOLFMAN)
					{
						SOUNDMANAGER->play("wolf_damage", 0.5f);
						if (SOUNDMANAGER->isPauseSound("wolf_damage")) SOUNDMANAGER->play("wolf_damage", 0.5f);
					}
				}
				else _skill_meteor = false;

				if (_skill_icespike && _player_stats._mp >= 30)
				{
					SOUNDMANAGER->play("icespike", 0.5f);
					EFFECTMANAGER->play("icespike", _monsterManager->getVMonster()[i]->get_monster_rect().left + 30,
						_monsterManager->getVMonster()[i]->get_monster_rect().top + 30);	
					if (SOUNDMANAGER->isPauseSound("icespike")) SOUNDMANAGER->play("icespike", 0.5f);
					_monsterManager->getVMonster()[i]->set_monster_hp( -60 - RND->getInt(30) - 3 * _player_stats._spell_power);

					_skill_icespike = false;
					_player_stats._mp -= 30;

					if (_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::ORC)
					{
						SOUNDMANAGER->play("orc_damage", 0.5f);
						if (SOUNDMANAGER->isPauseSound("orc_damage")) SOUNDMANAGER->play("orc_damage", 0.5f);
					}
					else if (_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::WOLFMAN)
					{
						SOUNDMANAGER->play("wolf_damage", 0.5f);
						if (SOUNDMANAGER->isPauseSound("wolf_damage")) SOUNDMANAGER->play("wolf_damage", 0.5f);
					}
				}
				else _skill_icespike = false;
			}
			if (abs(_monsterManager->getVMonster()[i]->get_start_isoX() - _start_i) < 2 && abs(_monsterManager->getVMonster()[i]->get_start_isoY() - _start_j) < 2 &&
				_player_move == false && !_skill_meteor && PtInRect(&_monsterManager->getVMonster()[i]->get_monster_rect(), m_ptMouse))
			{
				if (_monsterManager->getVMonster()[i]->get_start_isoX() < _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() < _start_j)
				{
					_player_direct = MIDDLETOP_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() == _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() == _start_j)
				{
					_player_direct = MIDDLETOP_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() < _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() == _start_j)
				{
					_player_direct = LEFTTOP_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() < _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() > _start_j)
				{
					_player_direct = MIDDLELEFT_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() == _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() > _start_j)
				{
					_player_direct = LEFTBOTTOM_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() > _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() > _start_j)
				{
					_player_direct = MIDDLEBOTTOM_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() > _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() == _start_j)
				{
					_player_direct = RIGHTBOTTOM_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() > _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() < _start_j)
				{
					_player_direct = MIDDLERIGHT_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
				if (_monsterManager->getVMonster()[i]->get_start_isoX() == _start_i && _monsterManager->getVMonster()[i]->get_start_isoY() < _start_j)
				{
					_player_direct = RIGHTTOP_ATT;
					_player_attack_on = true;
					_monsterManager->getVMonster()[i]->set_player_att_on(true);
					_monsterManager->getVMonster()[i]->set_player_click(true);
					return;
				}
			}
		}

		if (!(PtInRect(&inven_rect, m_ptMouse)) && !UI->get_restart_on())
		{
			float cellX = (float)(m_ptMouse.x - _startX);

			if (cellX < 0)
			{
				cellX = (cellX - CELL_WIDTH) / (float)CELL_WIDTH;
			}
			else
			{
				//얼만큼 떨어져서 클릭했는가를 수치화(가로지름 기준)
				cellX = cellX / (float)CELL_WIDTH;
			}

			//cellY는 -개념이 없기 때문에(기준점이 가장 위)절대값으로 구하자
			int cellY = abs(m_ptMouse.y - _startY) / CELL_HEIGHT;
			//만약 -시작점 자체가 -이면 -1을 곱해주자
			cellY = (m_ptMouse.y < _startY) ? cellY * -1 : cellY;
			//x는 y가 기준점에 가까워 질수록 작아져야 한다.
			//마름모 이기 때문에 x축은 y의기준값으로부터 멀리 떨어진수록 x값은 커진다.
			isoX = (int)cellX + (int)cellY;
			//y축은 x기준값으로 부터 멀리 떨어질수록 y는 늘어나게 된다.
			isoY = (int)cellY - (int)cellX;
			/*
			//만약 x좌표가 0보다 크고 최대타일수 보다 작고
			//Y좌표 0보다 크고, 최대타일수보다 작으면 검출대상에 집어넣자
			*/
			if (isoX >= 0 && isoX < TILE_COUNT_X &&isoY >= 0 && isoY < TILE_COUNT_Y)
			{

				//1분면이면[x - 1][y]
				//2분면이면[x][y - 1]
				//3분면이면[x1][y + 1]
				//4분면이면[x + 1][y]

				//코너 검출(어느 분면에 찍혔는지)
				int corner = GetCornerIndex(isoX, isoY);
				// 검출되었는데, 그게 마름모안에 있는지 확인
				/*
				//만약 들어가 있다면 지금의 isoX, isoY는 건들 필요 없다
				//마름모 안에 들어가 있기 때문에 예외처리를 할 필요가 없다
				//만약 이 값이 false가 되었다면 마롬므가 아닌 그 밖에 찍혔다는 뜻이 되므로
				//다른 타일을 눌렀다는 것이 되고 거기에 따른 예외처리는 밑에서 써주면 된다.

				*/
				if (IsInRhombus(corner, isoX, isoY))corner = 0;

				//만약 1/4분면에서 마름모 안에 찍힌게 아니라면 그 위의 마름모가 찍히게 된다.
				switch (corner)
				{
				case 1:
					isoX = isoX - 1;//마름모의 4변중에 좌측 윗변과 맞닿아 있는 마름모는 x축으로 한단계 낮은 좌표임.
					break;
				case 2:
					isoY = isoY - 1;
					break;
				case 3:
					isoY = isoY + 1;
					break;
				case 4:
					isoX = isoX + 1;
					break;
				}

				_center = corner;
				_isoX = isoX;
				_isoY = isoY;

				_calcul_on = true;

				if (_tileMap[isoX][isoY].walkable)
				{
					_end_i = isoX;
					_end_j = isoY;
				}
				else
					_calcul_on = false;
			}
		}

		if ((_player_move == true && _calcul_on == true) || _player_attack_on == true || UI->get_restart_on())
		{
			_openList.clear();
			_closeList.clear();
			_calcul_on = false;
			_pathList.clear();
			_pathList_count = -1;
			for (int i = 0; i < TILE_COUNT_X; i++)
			{
				for (int j = 0; j < TILE_COUNT_Y; j++)
				{
					_tileMap[i][j].parent = NULL;	//부모타일
					_tileMap[i][j].F = BIGNUM;		//초기값 F
					_tileMap[i][j].H = 0;			//계산전이므로 0
					_tileMap[i][j].G = 0;			//계산전이므로 0
					_tileMap[i][j].i = i;			// 배열 y 위치
					_tileMap[i][j].j = j;			// 배열 x 위치
					_tileMap[i][j].listOn = false;
				}
			}

			if (_player_direct_temp == LEFTTOP)
			{
				_closeList.push_back(&_tileMap[_start_i - 1][_start_j]);
				_tileMap[_start_i - 1][_start_j].listOn = true;
			}
			if (_player_direct_temp == MIDDLETOP)
			{
				_closeList.push_back(&_tileMap[_start_i - 1][_start_j - 1]);
				_tileMap[_start_i - 1][_start_j - 1].listOn = true;
			}
			if (_player_direct_temp == RIGHTTOP)
			{
				_closeList.push_back(&_tileMap[_start_i][_start_j - 1]);
				_tileMap[_start_i][_start_j - 1].listOn = true;
			}
			if (_player_direct_temp == MIDDLELEFT)
			{
				_closeList.push_back(&_tileMap[_start_i - 1][_start_j + 1]);
				_tileMap[_start_i - 1][_start_j + 1].listOn = true;
			}
			if (_player_direct_temp == MIDDLERIGHT)
			{
				_closeList.push_back(&_tileMap[_start_i + 1][_start_j - 1]);
				_tileMap[_start_i + 1][_start_j - 1].listOn = true;
			}
			if (_player_direct_temp == LEFTBOTTOM)
			{
				_closeList.push_back(&_tileMap[_start_i][_start_j + 1]);
				_tileMap[_start_i][_start_j + 1].listOn = true;
			}
			if (_player_direct_temp == MIDDLEBOTTOM)
			{
				_closeList.push_back(&_tileMap[_start_i + 1][_start_j + 1]);
				_tileMap[_start_i + 1][_start_j + 1].listOn = true;
			}
			if (_player_direct_temp == RIGHTBOTTOM)
			{
				_closeList.push_back(&_tileMap[_start_i + 1][_start_j]);
				_tileMap[_start_i + 1][_start_j].listOn = true;
			}
		}
	}



	if (_player_move == false)
	{
		_moveDist_x = 0;
		_moveDist_y = 0;

		if (_pathList.size() > 1 && _pathList_count < _pathList.size() - 1)
		{
			//LEFTTOP
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i + 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j)
			{
				_player_direct = LEFTTOP;
				_player_move = true;
				minimap_direction = 5;
			}
			//MIDDLETOP
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i + 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j + 1)
			{
				_player_direct = MIDDLETOP;
				_player_move = true;
				minimap_direction = 6;
			}
			//RIGHTTOP
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j + 1)
			{
				_player_direct = RIGHTTOP;
				_player_move = true;
				minimap_direction = 7;
			}
			//MIDDLELEFT
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i + 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j - 1)
			{
				_player_direct = MIDDLELEFT;
				_player_move = true;
				minimap_direction = 4;
			}
			//MIDDLERIGHT
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i - 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j + 1)
			{
				_player_direct = MIDDLERIGHT;
				_player_move = true;
				minimap_direction = 0;
			}
			//LEFTBOTTOM
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j - 1)
			{
				_player_direct = LEFTBOTTOM;
				_player_move = true;
				minimap_direction = 3;
			}
			//MIDDLEBOTTOM
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i - 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j - 1)
			{
				_player_direct = MIDDLEBOTTOM;
				_player_move = true;
				minimap_direction = 2;
			}
			//RIGHTBOTTOM
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i - 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j)
			{
				_player_direct = RIGHTBOTTOM;
				_player_move = true;
				minimap_direction = 1;
			}
		}
	}


	if (_player_move == true)
	{
		MoveFunction();
	}
	if (_player_attack_on == true)
	{
		AttackFunction();
	}

	if (_calcul_on)
	{
		addOpenList(); // 이동이 가능한 지역인지 파악하고 이동이 가능하면 _openList에 추가해주는 함수. 
		calculateH();  //오픈 리스트내 타일 H값계산
		calculateF();  //오픈 리스트내 타일 F값계산
		addCloseList();//가장 작은 F선택후 클로즈 리스트에 추가

	}
	checkArrive(); //도착했는지 여부 체크

	_hpBar->setX(216);
	_hpBar->setY(715);
	_currentHP = _player_stats._hp;
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();

	_mpBar->setX(477);
	_mpBar->setY(715);
	_currentMP = _player_stats._mp;
	_mpBar->setGauge(_currentMP, _maxMP);
	_mpBar->update();


}

void gameScene::render()
{
	IMAGEMANAGER->render("linmap", getMemDC(), _startX - 3000, _startY + 2000);
	if (!_isDebug)
	{
		DrawTileMap();
	}

	switch (_player_direct)
	{
	case LEFTTOP:
		switch (_player_form)
		{
			case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_lefttop"; break; } else { _image_name = "player_lefttop"; break; }
			case ORC: _image_name = "orc_lefttop"; break;
			case WOLFMAN: _image_name = "wol_lefttop"; break;
			default: break;
		}
		break;
	case MIDDLETOP:
		switch (_player_form)
		{
			case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_middletop"; break; } else { _image_name = "player_up"; break; }
			case ORC: _image_name = "orc_up"; break;
			case WOLFMAN: _image_name = "wol_up"; break;
			default: break;
		}
		break;
	case RIGHTTOP:
		switch (_player_form)
		{
			case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_righttop"; break; } else { _image_name = "player_righttop"; break; }
			case ORC: _image_name = "orc_righttop"; break;
			case WOLFMAN: _image_name = "wol_righttop"; break;
			default: break;
		}
		break;
	case MIDDLELEFT:
		switch (_player_form)
		{
			case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_middleleft"; break; } else { _image_name = "player_left"; break; }
			case ORC: _image_name = "orc_left"; break;
			case WOLFMAN: _image_name = "wol_left"; break;
			default: break;
		}
		break;
	case MIDDLERIGHT:
		switch (_player_form)
		{
		case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_middleright"; break; } else { _image_name = "player_right"; break; }
			case ORC: _image_name = "orc_right"; break;
			case WOLFMAN: _image_name = "wol_right"; break;
			default: break;
		}
		break;
	case LEFTBOTTOM:
		switch (_player_form)
		{
			case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_leftbottom"; break; } else { _image_name = "player_leftbottom"; break; }
			case ORC: _image_name = "orc_leftbottom"; break;
			case WOLFMAN: _image_name = "wol_leftbottom"; break;
			default: break;
		}
		break;
	case MIDDLEBOTTOM:
		switch (_player_form)
		{
			case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_middlebottom"; break; } else { _image_name = "player_down"; break; }
			case ORC: _image_name = "orc_down"; break;
			case WOLFMAN: _image_name = "wol_down"; break;
			default: break;
		}
		break;
	case RIGHTBOTTOM:
		switch (_player_form)
		{
			case MAGICIAN: if (_UIScene->get_weapon_on()) { _image_name = "staff_rightbottom"; break; } else { _image_name = "player_rightbottom"; break; }
			case ORC: _image_name = "orc_rightbottom"; break;
			case WOLFMAN: _image_name = "wol_rightbottom"; break;
			default: break;
		}
		break;
	//case STOP:_image_name = "player_stop"; break;
	case START:
		switch (_player_form)
		{
			case MAGICIAN: _image_name = "player_stop"; break;
			case ORC: _image_name = "orc_stop"; break;
			case WOLFMAN: _image_name = "wol_stop"; break;
			default: break;
		}
		break;
	case MIDDLETOP_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_middletop"; break;
		case ORC: _image_name = "orc_att_middletop"; break;
		case WOLFMAN: _image_name = "wol_att_middletop"; break;
		default: break;
		}
		break;
	case LEFTTOP_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_lefttop"; break;
		case ORC: _image_name = "orc_att_lefttop"; break;
		case WOLFMAN: _image_name = "wol_att_lefttop"; break;
		default: break;
		}
		break;
	case MIDDLELEFT_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_middleleft"; break;
		case ORC: _image_name = "orc_att_middleleft"; break;
		case WOLFMAN: _image_name = "wol_att_middleleft"; break;
		default: break;
		}
		break;
	case LEFTBOTTOM_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_leftbottom"; break;
		case ORC: _image_name = "orc_att_leftbottom"; break;
		case WOLFMAN: _image_name = "wol_att_leftbottom"; break;
		default: break;
		}
		break;
	case MIDDLEBOTTOM_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_middlebottom"; break;
		case ORC: _image_name = "orc_att_middlebottom"; break;
		case WOLFMAN: _image_name = "wol_att_middlebottom"; break;
		default: break;
		}
		break;
	case RIGHTBOTTOM_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_rightbottom"; break;
		case ORC: _image_name = "orc_att_rightbottom"; break;
		case WOLFMAN: _image_name = "wol_att_rightbottom"; break;
		default: break;
		}
		break;
	case MIDDLERIGHT_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_middleright"; break;
		case ORC: _image_name = "orc_att_middleright"; break;
		case WOLFMAN: _image_name = "wol_att_middleright"; break;
		default: break;
		}
		break;
	case RIGHTTOP_ATT:
		switch (_player_form)
		{
		case MAGICIAN: _image_name = "pl_att_righttop"; break;
		case ORC: _image_name = "orc_att_rightbottom"; break;
		case WOLFMAN: _image_name = "wol_att_righttop"; break;
		default: break;
		}
		break;
	default:
		break;
	}
	switch (_player_form)
	{
		case MAGICIAN: 
			if (_player_direct == MIDDLETOP || _player_direct == RIGHTTOP || _player_direct == MIDDLELEFT || _player_direct == MIDDLERIGHT || 
				_player_direct == LEFTBOTTOM || _player_direct == MIDDLEBOTTOM || _player_direct == RIGHTBOTTOM || _player_direct == LEFTTOP)
			{
				if (_UIScene->get_weapon_on()) IMAGEMANAGER->frameRender(_image_name, getMemDC(), 540, 220, _current_x, _current_y);
				else IMAGEMANAGER->frameRender(_image_name, getMemDC(), 575, 270, _current_x, _current_y); break;
			}
			else if (_player_direct == LEFTTOP_ATT || _player_direct ==  MIDDLETOP_ATT || _player_direct == RIGHTTOP_ATT || _player_direct == MIDDLELEFT_ATT ||
				_player_direct == MIDDLERIGHT_ATT || _player_direct == LEFTBOTTOM_ATT || _player_direct == MIDDLEBOTTOM_ATT || _player_direct == RIGHTBOTTOM_ATT)
			{
				IMAGEMANAGER->frameRender(_image_name, getMemDC(), 540, 220, _current_x, _current_y); break;
			}
		case ORC: IMAGEMANAGER->frameRender(_image_name, getMemDC(), 570, 285, _current_x, _current_y); break;
		case WOLFMAN: IMAGEMANAGER->frameRender(_image_name, getMemDC(), 560, 260, _current_x, _current_y); break;
	}

	if (_player_rect_on)	Rectangle(getMemDC(), _player_rect.left, _player_rect.top, _player_rect.right, _player_rect.bottom);

	//sprintf_s(str, "isoX : %d, isoY : %d, corner : %d",
	//	_isoX, _isoY, _center);
	//TextOut(getMemDC(), 0, 70, str, strlen(str));

	//sprintf_s(str1, "startX : %d, startY : %d", _startX,
	//	_startY);
	//TextOut(getMemDC(), 0, 90, str1, strlen(str1));

	//sprintf_s(str2, "player.hp : %d", _player_stats._hp);
	//TextOut(getMemDC(), 0, 110, str2, strlen(str2));

	_hpBar->render();
	_mpBar->render();

	//hp bar number
	hp_num[2] = _player_stats._hp % 10;
	hp_num[1] = (_player_stats._hp / 10) % 10;
	hp_num[0] = (_player_stats._hp / 100) % 10;
	max_hp_num[2] = _player_stats._maxHp % 10;
	max_hp_num[1] = (_player_stats._maxHp / 10) % 10;
	max_hp_num[0] = (_player_stats._maxHp / 100) % 10;

	if(_player_stats._hp >= 100) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 290, 717, hp_num[0], 0);
	if (_player_stats._hp >= 10) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 300, 717, hp_num[1], 0);
	if (_player_stats._hp > 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 310, 717, hp_num[2], 0);
	else if (_player_stats._hp <= 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 310, 717, 0, 0);
	IMAGEMANAGER->render("slash", getMemDC(), 320, 717);
	IMAGEMANAGER->frameRender("hp_num", getMemDC(), 330, 717, max_hp_num[0], 0);
	IMAGEMANAGER->frameRender("hp_num", getMemDC(), 340, 717, max_hp_num[1], 0);
	IMAGEMANAGER->frameRender("hp_num", getMemDC(), 350, 717, max_hp_num[2], 0);

	//mp bar number
	mp_num[2] = _player_stats._mp % 10;
	mp_num[1] = (_player_stats._mp / 10) % 10;
	mp_num[0] = (_player_stats._mp / 100) % 10;
	max_mp_num[2] = _player_stats._maxMp % 10;
	max_mp_num[1] = (_player_stats._maxMp / 10) % 10;
	max_mp_num[0] = (_player_stats._maxMp / 100) % 10;

	if (_player_stats._mp >= 100) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 550, 717, mp_num[0], 0);
	if (_player_stats._mp >= 10) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 560, 717, mp_num[1], 0);
	if (_player_stats._mp > 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 570, 717, mp_num[2], 0);
	else if (_player_stats._mp <= 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 570, 717, 0, 0);
	IMAGEMANAGER->render("slash", getMemDC(), 580, 717);
	IMAGEMANAGER->frameRender("hp_num", getMemDC(), 590, 717, max_mp_num[0], 0);
	IMAGEMANAGER->frameRender("hp_num", getMemDC(), 600, 717, max_mp_num[1], 0);
	IMAGEMANAGER->frameRender("hp_num", getMemDC(), 610, 717, max_mp_num[2], 0);
	
	//캐릭터 이름 화면출력
	if (PtInRect(&_player_rect, m_ptMouse))
	{
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf_s(str, _player_stats._player_name);
		TextOut(getMemDC(), _player_rect.left - 3, _player_rect.top - 20, str, strlen(str));
	}

	//몬스터 이름 화면출력
	for (int i = 0; i < _monsterManager->getVMonster().size(); i++)
	{
		if (PtInRect(&_monsterManager->getVMonster()[i]->get_monster_rect(), m_ptMouse))
		{
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf_s(str, _monsterManager->getVMonster()[i]->get_monster_stats()._monster_name);
			if(_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::WOLFMAN)
				TextOut(getMemDC(), _monsterManager->getVMonster()[i]->get_monster_rect().left - 10, _monsterManager->getVMonster()[i]->get_monster_rect().top - 52, str, strlen(str));
			else if (_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::ORC)
				TextOut(getMemDC(), _monsterManager->getVMonster()[i]->get_monster_rect().left + 2, _monsterManager->getVMonster()[i]->get_monster_rect().top - 32, str, strlen(str));
		}
	}
}

void gameScene::DrawTileMap()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			int left = _startX + (i * RADIUS_WIDTH) - (j * RADIUS_WIDTH);
			int top = _startY + (i * RADIUS_HEIGHT) + (j * RADIUS_HEIGHT);

			_tileMap[i][j].left = left;
			_tileMap[i][j].top = top;
			_tileMap[i][j].rc = { left, top, left + CELL_WIDTH, top + CELL_HEIGHT };
			for (int z = 0; z <= _tileMap[i][j].index; z++)
			{
				if (IntersectRect(&_temp, &_winsize, &_tileMap[i][j].rc))
				{
					if (_tileMap[i][j].tileKind[z] != TILEKIND_NONE)
					{
						switch (_tileMap[i][j].tileNum[z])
						{
						case 0:
							IMAGEMANAGER->frameRender("tile", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top,
								_tileMap[i][j].tilePos[z].x,
								_tileMap[i][j].tilePos[z].y);
							break;
						case 1:
						case 2:
							IMAGEMANAGER->frameRender("tile2", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top,
								_tileMap[i][j].tilePos[z].x,
								_tileMap[i][j].tilePos[z].y);
							break;
						}
					}
				}				
			}

			if (!_isDebug)
			{
				_rhombus.x = left;
				_rhombus.y = top;
				if (PtInRect(&_winsize, _rhombus))
				{
					DrawRhombus(left, top);
				}
				_rhombus2.x = left + RADIUS_WIDTH / 2 + 5;
				_rhombus2.y = top + RADIUS_HEIGHT / 2 + 5;
				if (PtInRect(&_winsize, _rhombus2))
				{
					SetTextColor(getMemDC(), RGB(0, 0, 0));
					sprintf_s(str, "(%d,%d)", i, j);
					TextOut(getMemDC(),
						left + RADIUS_WIDTH / 2 + 5,
						top + RADIUS_HEIGHT / 2 + 5, str, strlen(str));
				}
			}

		}
	}
}

void gameScene::DrawRhombus(int left, int top)
{
	int centerX = left + RADIUS_WIDTH;
	int centerY = top + RADIUS_HEIGHT;

	POINT p[5];
	p[0].x = centerX;
	p[0].y = centerY - RADIUS_HEIGHT;

	p[1].x = centerX + RADIUS_WIDTH;
	p[1].y = centerY;

	p[2].x = centerX;
	p[2].y = centerY + RADIUS_HEIGHT;

	p[3].x = centerX - RADIUS_WIDTH;
	p[3].y = centerY;

	p[4].x = centerX;
	p[4].y = centerY - RADIUS_HEIGHT;

	for (int i = 1; i < 5; i++)
	{
		LineMake(getMemDC(), p[i - 1], p[i]);
	}
}

int gameScene::GetCornerIndex(int isoX, int isoY)
{
	//클릭한 좌표점을 통해서 공식을 통해 렉트의 left,top을 구한다.
	int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
	int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);


	//left에서 마우스값을 빼면 레프트에서 이동한 값만 남는데,
	//이걸 전체길이로 나누면 0.0~ 1.0 (float으로 나눴고 , 변수가 float이니까)의 값이 나온다
	//비율값으로 마름모를 포함한 렉트를 1~4분으로 나웠을때
	//찍은 위치를 알 수 있다.
	float dx = (m_ptMouse.x - left) / (float)CELL_WIDTH;
	float dy = (m_ptMouse.y - top) / (float)CELL_HEIGHT;

	//막약 둘다 중점 보다 작으면 1/4분면
	if (dx < 0.5f && dy < 0.5f) return 1;
	//만약 dx 중점(0.5)보다 크면 2/4분면
	if (dx >= 0.5f && dy < 0.5f) return 2;
	//만약 dx 중점(0.5)보다 작고 dy 중점보다 크면 3/4분면
	if (dx < 0.5f && dy >= 0.5f) return 3;
	//만약 둘다 중점(0.5)보다 크면 4/4
	if (dx >= 0.5f && dy >= 0.5f) return 4;

	return 0;
}

bool gameScene::IsInRhombus(int corner, int isoX, int isoY)
{
	// lefttop
	if (corner == 1) {
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);

		//left 에서 마우스값을 뺀값(left에서 이동거리)를
		//left와 중점폭으로 top과 중점을 길이로 하는 작은 사각형으로 
		//비례하기 위해 dx와 dy를 구한다.
		float dx = (float)(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT;

		//만약 전체 비례즁에서 정삼각형 안에 들어가야 하기 때문에
		//무조건 dy가 dx보다 같거나 작을 수 밖에 없다.
		//정삼각형 안에 들어가 잇는 점은 무조건 y가 x보다 작거나 
		//같을 수 밖에 없다.

		//1뺴주는 이유는 top에서부터 차이를 계산 했기 떄무에
		//바텀에서부터의 값을 구하기 위함
		if ((1.0f - dy) <= dx) return true;
		//정삼각형 밖에 있다면 
		else return false;
	}
	// righttop
	else if (corner == 2)
	{
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		//레프트의 중점의 절반을 더하는 이유는
		//검사하는 렉트가 실질적으로 마름모의 시작점인 left가
		//아닌 중점에서의 작은 렉트(사각형)이기 때문에
		//가로 반지름을 더한다
		left += RADIUS_WIDTH;
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);

		float dx = (float)(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if (dy >= dx) return true;
		else return false;
	}
	// leftdown
	else if (corner == 3) {
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);
		top += RADIUS_HEIGHT;

		float dx = (float)(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if (dy < dx) return true;
		else return false;
	}
	// rightdown
	else if (corner == 4)
	{
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		left += RADIUS_WIDTH;
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);
		top += RADIUS_HEIGHT;

		float dx = (float)(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = (float)(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if ((1.0f - dy) > dx) return true;
		else return false;
	}

	return false;
}

void gameScene::Load(int loadCount)
{
	file = CreateFile(fileName[loadCount], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tileMap, sizeof(TagTile) * TILE_COUNT_X * TILE_COUNT_Y, &read, NULL);
	CloseHandle(file);
}

void gameScene::MoveFunction()
{
		_frame_count++;
		if (_frame_count > frame_move_speed)
		{
			_current_x++;
			if (_current_x >= 4)
				_current_x = 0;
			_frame_count = 0;
		}
			if (_player_direct == LEFTTOP)
			{
				_player_direct_temp = LEFTTOP;
				_startX += _player_speedx;
				_startY += _player_speedy;
				_moveDist_y += _player_speedy;
				if (RADIUS_HEIGHT <= _moveDist_y)
				{
					_start_i--;
					_player_move = false;
					_pathList_count++;
				}
			}
			if (_player_direct == MIDDLETOP)
			{
				_player_direct_temp = MIDDLETOP;
				_startY += _player_speedy;
				_moveDist_y += _player_speedy;
				if (CELL_HEIGHT <= _moveDist_y)
				{
					_start_i--;
					_start_j--;
					_player_move = false;
					_pathList_count++;
				}
			}
			if (_player_direct == RIGHTTOP)
			{
				_player_direct_temp = RIGHTTOP;
				_startX -= _player_speedx;
				_startY += _player_speedy;
				_moveDist_y += _player_speedy;
				if (RADIUS_HEIGHT <= _moveDist_y)
				{
					_start_j--;
					_player_move = false;
					_pathList_count++;
				}
			}
			if (_player_direct == MIDDLELEFT)
			{
				_player_direct_temp = MIDDLELEFT;
				_startX += _player_speedx;
				_moveDist_x += _player_speedx;
				if (CELL_WIDTH <= _moveDist_x)
				{
					_start_i--;
					_start_j++;
					_player_move = false;
					_pathList_count++;
				}
			}
			if (_player_direct == MIDDLERIGHT)
			{
				_player_direct_temp = MIDDLERIGHT;
				_startX -= _player_speedx;
				_moveDist_x += _player_speedx;
				if (CELL_WIDTH <= _moveDist_x)
				{
					_start_i++;
					_start_j--;
					_player_move = false;
					_pathList_count++;
				}
			}
			if (_player_direct == LEFTBOTTOM)
			{
				_player_direct_temp = LEFTBOTTOM;
				_startX += _player_speedx;
				_startY -= _player_speedy;
				_moveDist_y += _player_speedy;
				if (RADIUS_HEIGHT <= _moveDist_y)
				{
					_start_j++;
					_player_move = false;
					_pathList_count++;
				}
			}
			if (_player_direct == MIDDLEBOTTOM)
			{
				_player_direct_temp = MIDDLEBOTTOM;
				_startY -= _player_speedy;
				_moveDist_y += _player_speedy;
				if (CELL_HEIGHT <= _moveDist_y)
				{
					_start_i++;
					_start_j++;
					_player_move = false;
					_pathList_count++;
				}
			}
			if (_player_direct == RIGHTBOTTOM)
			{
				_player_direct_temp = RIGHTBOTTOM;
				_startX -= _player_speedx;
				_startY -= _player_speedy;
				_moveDist_y += _player_speedy;
				if (RADIUS_HEIGHT <= _moveDist_y)
				{
					_start_i++;
					_player_move = false;
					_pathList_count++;
				}
			}
}

void gameScene::AttackFunction()
{
	_frame_count++;
	if (_frame_count > frame_attack_speed)
	{
		
		_current_x++;
		if (_current_x >= 4)
		{
			_current_x = 0;
			for (int i = 0; i < _monsterManager->getVMonster().size(); i++)
			{
				if (_monsterManager->getVMonster()[i]->get_player_click())
				{
					_attack_skill_rnd = RND->getInt(7);
					if (_attack_skill_rnd == 3 && _UIScene->get_weapon_on())
					{
						EFFECTMANAGER->play("lightning", _monsterManager->getVMonster()[i]->get_monster_rect().left + 35, _monsterManager->getVMonster()[i]->get_monster_rect().top - 80);
						SOUNDMANAGER->play("lightning", 0.5f);
						_monsterManager->getVMonster()[i]->set_monster_hp(-(_player_stats._spell_power) + RND->getInt(10));
					}
					_monsterManager->getVMonster()[i]->set_monster_hp(-(_player_stats._att) + _monsterManager->getVMonster()[i]->get_monster_def() + RND->getInt(8));

					if (_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::ORC)
					{
						SOUNDMANAGER->play("orc_damage", 0.5f);
						if (SOUNDMANAGER->isPauseSound("orc_damage")) SOUNDMANAGER->play("orc_damage", 0.5f);
					}
					else if (_monsterManager->getVMonster()[i]->get_monster_form() == monster_form::WOLFMAN)
					{
						SOUNDMANAGER->play("wolf_damage", 0.5f);
						if (SOUNDMANAGER->isPauseSound("wolf_damage")) SOUNDMANAGER->play("wolf_damage", 0.5f);
					}
				}				
			}
		}
		_frame_count = 0;
	}
	if (_player_direct == MIDDLETOP_ATT || _player_direct == LEFTTOP_ATT || _player_direct == RIGHTTOP_ATT || _player_direct == MIDDLELEFT_ATT ||
		_player_direct == MIDDLERIGHT_ATT || _player_direct == LEFTBOTTOM_ATT || _player_direct == MIDDLEBOTTOM_ATT || _player_direct == RIGHTBOTTOM_ATT)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			//_player_direct = START;
			_player_attack_on = false;
			for (int i = 0; i < _monsterManager->getVMonster().size(); i++)
			{
				_monsterManager->getVMonster()[i]->set_player_click(false);
			}
		}
	}
}

void gameScene::tileInitializing() // 타일 속성에 따른 추가 속성(walkable, listOn) 부여.
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j].parent = NULL;	//부모타일
			_tileMap[i][j].F = BIGNUM;		//초기값 F
			_tileMap[i][j].H = 0;			//계산전이므로 0
			_tileMap[i][j].i = i;			// 배열 y 위치
			_tileMap[i][j].j = j;			// 배열 x 위치
			for (int z = 0; z < 1; z++)
			{
				if (_tileMap[i][j].tileKind[z] == TILEKIND_TERRAIN)
				{
					_tileMap[i][j].walkable = true;
					_tileMap[i][j].listOn = false;
				}
				else if (_tileMap[i][j].tileKind[z] == TILEKIND_OBJECT)
				{
					_tileMap[i][j].walkable = false; // 벽이면 walkable->false
					_tileMap[i][j].listOn = false;
				}
				else if (_tileMap[i][j].tileKind[z] == TILEKIND_PLAYER)
				{
					_tileMap[i][j].walkable = true;
					_tileMap[i][j].listOn = true;	  // 시작지점을 클로즈 리스트에 추가.

					_closeList.push_back(&_tileMap[i][j]);
				}
				else if (_tileMap[i][j].tileKind[z] == TILEKIND_NONE)
				{
					_tileMap[i][j].walkable = true;
					_tileMap[i][j].listOn = false;
				}
			}	
		}
	}
}

void gameScene::addOpenList() // 이동이 가능한 지역인지 파악하고 이동이 가능하면 _openList에 추가해주는 함수. 
{
	Ci = _closeList.back()->i; //y값.    //마지막으로 추가된 클로즈리스트 i
	Cj = _closeList.back()->j; //x값. 
	Cg = _closeList.back()->G;

	if (Ci != 0)//0번째 줄이 아니면 상단중간블럭계산
	{
		if (_tileMap[Ci - 1][Cj].walkable)//상단 가운데 타일이 지나갈수 있다면
		{
			if (!_tileMap[Ci - 1][Cj].listOn)//오픈리스트에 포함이 안되어 있는 타일이라면
			{
				_tileMap[Ci - 1][Cj].listOn = true;//오픈리스트에 포함시킴
				_tileMap[Ci - 1][Cj].G = Cg + 10;	//타일의 G값을 클로즈 리스트에 누적 G+10
				_tileMap[Ci - 1][Cj].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
				_openList.push_back(&_tileMap[Ci - 1][Cj]);//오픈리스트에 추가
			}
			else//오픈리스트에 포함이 되어 있던 타일이라면
			{
				if (Cg + 10 < _tileMap[Ci - 1][Cj].G)//기존G값보다 새로 계산한 G값이 작다면
				{
					_tileMap[Ci - 1][Cj].G = Cg + 10;//G값 새롭게 계산
					_tileMap[Ci - 1][Cj].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
				}
			}
		}
		if (Cj != 0)//0번째 열이 아니라면 좌상단블럭계산
		{
			//좌상단 타일의 오른쪽이나 아래에 벽이 없다면
			if (_tileMap[Ci - 1][Cj - 1].walkable) // 좌상단, 좌상단의 오른쪽, 좌상단의 아래쪽.
			{
				if (!_tileMap[Ci - 1][Cj - 1].listOn)//오픈리스트에 포함이 안되어 있는 타일이라면
				{
					_tileMap[Ci - 1][Cj - 1].listOn = true;
					_tileMap[Ci - 1][Cj - 1].G = Cg + 10;//대각선이므로
					_tileMap[Ci - 1][Cj - 1].parent = _closeList.back();
					_openList.push_back(&_tileMap[Ci - 1][Cj - 1]);
				}
				else
				{
					if (Cg + 14 < _tileMap[Ci - 1][Cj - 1].G)
					{
						_tileMap[Ci - 1][Cj - 1].G = Cg + 10;//대각선이므로
						_tileMap[Ci - 1][Cj - 1].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
					}
				}
			}
		}
		if (Cj != TILE_COUNT_X - 1)//우상단: 마지막열이 아니라면
		{
			//우상단 타일의 왼쪽이나 아래에 벽이 없다면
			if (_tileMap[Ci - 1][Cj + 1].walkable) // 우상단, 우상단의 왼쪽, 우상단의 아래.
			{
				if (!_tileMap[Ci - 1][Cj + 1].listOn)
				{
					_tileMap[Ci - 1][Cj + 1].listOn = true;
					_tileMap[Ci - 1][Cj + 1].G = Cg + 10;
					_tileMap[Ci - 1][Cj + 1].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
					_openList.push_back(&_tileMap[Ci - 1][Cj + 1]);
				}
				else
				{
					if (Cg + 14 < _tileMap[Ci - 1][Cj + 1].G)
					{
						_tileMap[Ci - 1][Cj + 1].G = Cg + 10;
						_tileMap[Ci - 1][Cj + 1].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
					}
				}
			}
		}
	}
	if (Cj != 0)//좌측 : 0번째 열이 아니라면
	{
		if (_tileMap[Ci][Cj - 1].walkable)//좌측타일이 이동가능하다면
		{
			if (!_tileMap[Ci][Cj - 1].listOn)
			{
				_tileMap[Ci][Cj - 1].listOn = true;
				_tileMap[Ci][Cj - 1].G = Cg + 10;
				_tileMap[Ci][Cj - 1].parent = _closeList.back();
				_openList.push_back(&_tileMap[Ci][Cj - 1]);
			}
			else
			{
				if (Cg + 10 < _tileMap[Ci][Cj - 1].G)
				{
					_tileMap[Ci][Cj - 1].G = Cg + 10;
					_tileMap[Ci][Cj - 1].parent = _closeList.back();
				}
			}
		}
	}
	if (Cj != TILE_COUNT_X - 1)//우측 :  마지막열이 아니라면
	{

		if (_tileMap[Ci][Cj + 1].walkable)//우측타일이 이동가능하다면
		{
			if (!_tileMap[Ci][Cj + 1].listOn)
			{
				_tileMap[Ci][Cj + 1].listOn = true;
				_tileMap[Ci][Cj + 1].G = Cg + 10;
				_tileMap[Ci][Cj + 1].parent = _closeList.back();
				_openList.push_back(&_tileMap[Ci][Cj + 1]);
			}
			else
			{
				if (Cg + 10 < _tileMap[Ci][Cj + 1].G)
				{
					_tileMap[Ci][Cj + 1].G = Cg + 10;
					_tileMap[Ci][Cj + 1].parent = _closeList.back();
				}
			}
		}
	}
	if (Ci != TILE_COUNT_Y - 1)//마지막행이 아니라면 하단 라인 계산
	{
		if (_tileMap[Ci + 1][Cj].walkable)//하단 가운데 타일이 이동가능하다면
		{
			if (!_tileMap[Ci + 1][Cj].listOn)
			{
				_tileMap[Ci + 1][Cj].listOn = true;
				_tileMap[Ci + 1][Cj].G = Cg + 10;
				_tileMap[Ci + 1][Cj].parent = _closeList.back();
				_openList.push_back(&_tileMap[Ci + 1][Cj]);
			}
			else
			{
				if (Cg + 10 < _tileMap[Ci + 1][Cj].G)
				{
					_tileMap[Ci + 1][Cj].G = Cg + 10;
					_tileMap[Ci + 1][Cj].parent = _closeList.back();
				}
			}
		}
		if (Cj != 0)//좌하단 :  0번째 열이 아니라면
		{
			//좌하단 타일의 오른쪽이나 위에 벽이 없다면
			if (_tileMap[Ci + 1][Cj - 1].walkable)
			{
				if (!_tileMap[Ci + 1][Cj - 1].listOn)
				{
					_tileMap[Ci + 1][Cj - 1].listOn = true;
					_tileMap[Ci + 1][Cj - 1].G = Cg + 10;
					_tileMap[Ci + 1][Cj - 1].parent = _closeList.back();
					_openList.push_back(&_tileMap[Ci + 1][Cj - 1]);
				}
				else
				{
					if (Cg + 14 < _tileMap[Ci + 1][Cj - 1].G)
					{
						_tileMap[Ci + 1][Cj - 1].G = Cg + 10;
						_tileMap[Ci + 1][Cj - 1].parent = _closeList.back();
					}
				}
			}
		}
		if (Cj != TILE_COUNT_X - 1)//우하단 :  마지막 열이 아니라면
		{
			//우하단 타일의 왼쪽이나 위가 이동가능하다면
			if (_tileMap[Ci + 1][Cj + 1].walkable)
			{
				if (!_tileMap[Ci + 1][Cj + 1].listOn)
				{
					_tileMap[Ci + 1][Cj + 1].listOn = true;
					_tileMap[Ci + 1][Cj + 1].G = Cg + 10;
					_tileMap[Ci + 1][Cj + 1].parent = _closeList.back();
					_openList.push_back(&_tileMap[Ci + 1][Cj + 1]);
				}
				else
				{
					if (Cg + 14 < _tileMap[Ci + 1][Cj + 1].G)
					{
						_tileMap[Ci + 1][Cj + 1].G = Cg + 10;
						_tileMap[Ci + 1][Cj + 1].parent = _closeList.back();
					}
				}
			}
		}
	}
}


//H = 사각형으로부터 최종목적지까지의 예상이동비용
//(대각선 이동이 아닌 가로세로 이동에 대한 비용으로 계산, 장애물에 대한 요소는 고려하지 않는다.)
void gameScene::calculateH()
{
	for (int i = 0; i < _openList.size(); i++)//오픈리스트벡터의 모든 요소에 대하여 계산.
	{
		int vertical = (_end_i - _openList[i]->i) * 10;    //가로 H값 . x의 값.  수직변(left) - 해당 rect와 끝점과의 x축 거리차
		int horizontal = (_end_j - _openList[i]->j) * 10;  //세로 H값. y의 값. 수평변(top) - 해당 rect와 끝점과의 y축 거리차

		if (vertical < 0)vertical *= -1;//방향이 반대이면 음수부여(절대값)
		if (horizontal < 0)horizontal *= -1;

		_openList[i]->H = vertical + horizontal;//총 H값 : 가로+세로 H
	}
}


//F = 비용(목적지까지 가는 총 비용 현재까지 이동하는데 걸린 비용과 예상비용을 합침)
void gameScene::calculateF()
{
	for (int i = 0; i < _openList.size(); i++) //오픈리스트벡터의 모든 요소에 대하여 계산.
	{
		_openList[i]->F = _openList[i]->G + _openList[i]->H;//F값계산 F = G + H.
	}
}


//가장 작은 F선택후 클로즈 리스트에 추가
void gameScene::addCloseList()
{
	if (_openList.size() == 0)//검색했는데도 openList의 사이즈가 0이면 더이상 찾을것이 없음
	{
		//_astarState = ASTAR_STATE_NOWAY;//경로없다
		return;
	}
	int index = 0;			//오픈 리스트중 가장 F가 작은 타일의 인덱스를 넣을 변수.
	int lowest = BIGNUM;

	for (int i = 0; i < _openList.size(); i++) // 오픈리스트 벡터 전체를 비교해서 가장 F가 작은 요소를 구하고 그요소의 i값을 index에 저장.
	{
		if (_openList[i]->H < lowest)
		{
			lowest = _openList[i]->H;
			index = i;
		}
	}

	if (_closeList.back()->i == _end_i && _closeList.back()->j == _end_j)
	{
		addPathList(_closeList.back());
		_calcul_on = false;
		return;
	}

	_closeList.push_back(_openList[index]);
	_openList.erase(_openList.begin() + index);//클로즈 리스트에 추가된 타일은 오픈리스트에서 제외
	   	
}

void gameScene::checkArrive()
{
	if (_start_i == _end_i && _start_j == _end_j)
	{
		_openList.clear();
		_closeList.clear();
		_calcul_on = false;
		_pathList.clear();
		_closeList.push_back(&_tileMap[_start_i][_start_j]);
		_pathList_count = 0;
		for (int i = 0; i < TILE_COUNT_X; i++)
		{
			for (int j = 0; j < TILE_COUNT_Y; j++)
			{
				_tileMap[i][j].parent = NULL;	//부모타일
				_tileMap[i][j].F = BIGNUM;		//초기값 F
				_tileMap[i][j].H = 0;			//계산전이므로 0
				_tileMap[i][j].G = 0;			//계산전이므로 0
				_tileMap[i][j].i = i;			// 배열 y 위치
				_tileMap[i][j].j = j;			// 배열 x 위치
				_tileMap[i][j].listOn = false;
			}
		}
		_tileMap[_start_i][_start_j].listOn = true;
		return;
	}
}

void gameScene::addPathList(TagTile* tile)
{
	_pathList.insert(_pathList.begin(), tile);

	if (!(tile->parent == NULL))
		tile = tile->parent;

	if (tile->parent == NULL)	
	{
		_pathList.insert(_pathList.begin(), tile);
		return;
	}
	else
		addPathList(tile);
}