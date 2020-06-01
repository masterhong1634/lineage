#include "stdafx.h"
#include "Monster.h"
#include "gameScene.h"

Monster::Monster()
{
}

Monster::Monster(int x, int y, monster_form _monster)
	: _start_i(x), _start_j(y), _monster_form(_monster)
{
}

Monster::~Monster()
{
}

HRESULT Monster::init()
{
	_start_isoX = _start_i;
	_start_isoY = _start_j;

	_gameScene = new gameScene;

	_startX = _gameScene->getStartX() + (_start_i * RADIUS_WIDTH) - (_start_j * RADIUS_WIDTH);
	_startY = _gameScene->getStartY() + (_start_i * RADIUS_HEIGHT) + (_start_j * RADIUS_HEIGHT);
	_monster_point = { _startX, _startY };

	_monster_direct = monster_direct::MIDDLELEFT;
	_monster_move = false;
	_monster_attack_on = false;
	_player_att_on = false;
	_auto_attack_on = false;
	_player_click = false;
	_calcul_on = true;
	_isArrive = false;
	_start_Arrive = true;
	_changeCount = 0;

	Load(1);

	tileInitializing();

	_closeList.push_back(&_tileMap[_start_i][_start_j]);
	_tileMap[_start_i][_start_j].listOn = true;


	if (_monster_form == monster_form::ORC)
	{
		_monster_stats._monster_name = "��ũ";
		_monster_stats._MaxHP = 150;
		_monster_stats._hp = 150;
		_monster_stats._mp = 20;
		_monster_stats._att = 19;
		_monster_stats._def = 7;
		_monster_stats._magic_def = 12;
	}

	if (_monster_form == monster_form::WOLFMAN)
	{
		_monster_stats._monster_name = "�����ΰ�";
		_monster_stats._MaxHP = 250;
		_monster_stats._hp = 250;
		_monster_stats._mp = 40;
		_monster_stats._att = 24;
		_monster_stats._def = 7;
		_monster_stats._magic_def = 16;
	}

	_maxHP = _monster_stats._MaxHP;
	_currentHP = _monster_stats._hp;
	_hpBar = new progressBar;
	_hpBar->init("images/progressBarFront.bmp", "images/progressBarBack.bmp", 0, 0, 50, 10);
	_hpBar->setGauge(_currentHP, _maxHP);

	return S_OK;
}

void Monster::release()
{
}

void Monster::update()
{

	if ((_player_att_on && _monster_move == false) || _auto_attack_on)
	{
		if (_gameScene->get_start_i() < _start_isoX && _gameScene->get_start_j() < _start_isoY)
		{
			_monster_direct = monster_direct::MIDDLETOP_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() == _start_isoX && _gameScene->get_start_j() == _start_isoY)
		{
			_monster_direct = monster_direct::MIDDLETOP_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() < _start_isoX && _gameScene->get_start_j() == _start_isoY)
		{
			_monster_direct = monster_direct::LEFTTOP_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() < _start_isoX && _gameScene->get_start_j() > _start_isoY)
		{
			_monster_direct = monster_direct::MIDDLELEFT_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() == _start_isoX && _gameScene->get_start_j() > _start_isoY)
		{
			_monster_direct = monster_direct::LEFTBOTTOM_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() > _start_isoX && _gameScene->get_start_j() > _start_isoY)
		{
			_monster_direct = monster_direct::MIDDLEBOTTOM_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() > _start_isoX && _gameScene->get_start_j() == _start_isoY)
		{
			_monster_direct = monster_direct::RIGHTBOTTOM_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() > _start_isoX && _gameScene->get_start_j() < _start_isoY)
		{
			_monster_direct = monster_direct::MIDDLERIGHT_ATT;
			_monster_attack_on = true;
		}
		if (_gameScene->get_start_i() == _start_isoX && _gameScene->get_start_j() < _start_isoY)
		{
			_monster_direct = monster_direct::RIGHTTOP_ATT;
			_monster_attack_on = true;
		}
	}

	if (_isArrive || _start_Arrive)
	{
		_changeCount++;
		if (_changeCount >= 40)
		{
			if (abs(_gameScene->get_start_i() - _start_isoX) < 4 && abs(_gameScene->get_start_j() - _start_isoY) < 4)
			{
				//RIGHTTOP_ATT
				if (_gameScene->get_start_i() == _start_isoX && _gameScene->get_start_j() < _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i();
					isoY = _gameScene->get_start_j() + 1;
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
				//MIDDLERIGHT_ATT
				else if (_gameScene->get_start_i() > _start_isoX && _gameScene->get_start_j() < _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i() - 1;
					isoY = _gameScene->get_start_j() + 1;
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
				//RIGHTBOTTOM_ATT
				else if (_gameScene->get_start_i() > _start_isoX && _gameScene->get_start_j() == _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i() - 1;
					isoY = _gameScene->get_start_j();
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
				//MIDDLEBOTTOM_ATT
				else if (_gameScene->get_start_i() > _start_isoX && _gameScene->get_start_j() > _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i() - 1;
					isoY = _gameScene->get_start_j() - 1;
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
				//LEFTBOTTOM_ATT
				else if (_gameScene->get_start_i() == _start_isoX && _gameScene->get_start_j() > _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i();
					isoY = _gameScene->get_start_j() - 1;
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
				//MIDDLELEFT_ATT
				else if (_gameScene->get_start_i() < _start_isoX && _gameScene->get_start_j() > _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i() + 1;
					isoY = _gameScene->get_start_j() - 1;
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
				//LEFTTOP_ATT
				else if (_gameScene->get_start_i() < _start_isoX && _gameScene->get_start_j() == _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i() + 1;
					isoY = _gameScene->get_start_j();
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
				//MIDDLETOP_ATT
				else if (_gameScene->get_start_i() < _start_isoX && _gameScene->get_start_j() < _start_isoY)
				{
					_changeCount = 0;
					isoX = _gameScene->get_start_i() + 1;
					isoY = _gameScene->get_start_j() + 1;
					_isArrive = false;
					_start_Arrive = false;
					_player_att_on = true;
				}
			}
			else
			{
				_changeCount = 0;
				isoX = _start_i + RND->getInt(4);
				isoY = _start_j + RND->getInt(4);
				_isArrive = false;
				_start_Arrive = false;
				_player_att_on = false;
			}

			if (_tileMap[isoX][isoY].walkable)
			{
				_end_i = isoX;
				_end_j = isoY;
			}
			else
				_calcul_on = false;
		}
	}

	if (_monster_move == false)
	{
		_moveDist_x = 0;
		_moveDist_y = 0;

		if (_pathList.size() > 1 && _pathList_count < _pathList.size() - 1)
		{
			//LEFTTOP
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i + 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j)
			{
				_monster_direct = monster_direct::LEFTTOP;
				_monster_move = true;
			}
			//MIDDLETOP
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i + 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j + 1)
			{
				_monster_direct = monster_direct::MIDDLETOP;
				_monster_move = true;
			}
			//RIGHTTOP
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j + 1)
			{
				_monster_direct = monster_direct::RIGHTTOP;
				_monster_move = true;
			}
			//MIDDLELEFT
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i + 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j - 1)
			{
				_monster_direct = monster_direct::MIDDLELEFT;
				_monster_move = true;
			}
			//MIDDLERIGHT
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i - 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j + 1)
			{
				_monster_direct = monster_direct::MIDDLERIGHT;
				_monster_move = true;
			}
			//LEFTBOTTOM
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j - 1)
			{
				_monster_direct = monster_direct::LEFTBOTTOM;
				_monster_move = true;
			}
			//MIDDLEBOTTOM
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i - 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j - 1)
			{
				_monster_direct = monster_direct::MIDDLEBOTTOM;
				_monster_move = true;
			}
			//RIGHTBOTTOM
			if (_pathList[_pathList_count]->i == _pathList[_pathList_count + 1]->i - 1 && _pathList[_pathList_count]->j == _pathList[_pathList_count + 1]->j)
			{
				_monster_direct = monster_direct::RIGHTBOTTOM;
				_monster_move = true;
			}
		}
	}

	_startX = _gameScene->getStartX() + _moveX + (_start_i * RADIUS_WIDTH) - (_start_j * RADIUS_WIDTH) + 20;
	_startY = _gameScene->getStartY() + _moveY + (_start_i * RADIUS_HEIGHT) + (_start_j * RADIUS_HEIGHT) - 40;
	_monster_rect = { _startX + 10, _startY, _startX + 65, _startY + 80 };


	if (_monster_move == true)
	{
		MoveFunction();
	}
	if (_monster_attack_on == true)
	{
		AttackFunction();
	}
	if (_calcul_on)
	{
		addOpenList(); // �̵��� ������ �������� �ľ��ϰ� �̵��� �����ϸ� _openList�� �߰����ִ� �Լ�. 
		calculateH();  //���� ����Ʈ�� Ÿ�� H�����
		calculateF();  //���� ����Ʈ�� Ÿ�� F�����
		addCloseList();//���� ���� F������ Ŭ���� ����Ʈ�� �߰�

	}
	checkArrive(); //�����ߴ��� ���� üũ

	//���α׷���
	if (_monster_form == monster_form::ORC)
	{
		_hpBar->setX(_startX + 5);
		_hpBar->setY(_startY - 15);
	}
	if (_monster_form == monster_form::WOLFMAN)
	{
		_hpBar->setX(_startX + 5);
		_hpBar->setY(_startY - 35);
	}
	_currentHP = _monster_stats._hp;
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();
}

void Monster::render()
{
	if (IntersectRect(&temp, &_monster_rect, &_winsize))
	{
		switch (_monster_direct)
		{
		case monster_direct::LEFTTOP:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_lefttop"; break;
			case monster_form::WOLFMAN:_image_name = "wol_lefttop"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLETOP:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_up"; break;
			case monster_form::WOLFMAN:_image_name = "wol_up"; break;
			default:break;
			}
			break;
		case monster_direct::RIGHTTOP:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_righttop"; break;
			case monster_form::WOLFMAN:_image_name = "wol_righttop"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLELEFT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_left"; break;
			case monster_form::WOLFMAN:_image_name = "wol_left"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLERIGHT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_right"; break;
			case monster_form::WOLFMAN:_image_name = "wol_right"; break;
			default:break;
			}
			break;
		case monster_direct::LEFTBOTTOM:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_leftbottom"; break;
			case monster_form::WOLFMAN:_image_name = "wol_leftbottom"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLEBOTTOM:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_down"; break;
			case monster_form::WOLFMAN:_image_name = "wol_down"; break;
			default:break;
			}
			break;
		case monster_direct::RIGHTBOTTOM:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_rightbottom"; break;
			case monster_form::WOLFMAN:_image_name = "wol_rightbottom"; break;
			default:break;
			}
			break;
		case monster_direct::LEFTTOP_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_lefttop"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_lefttop"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLETOP_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_middletop"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_middletop"; break;
			default:break;
			}
			break;
		case monster_direct::RIGHTTOP_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_righttop"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_righttop"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLELEFT_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_middleleft"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_middleleft"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLERIGHT_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_middleright"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_middleright"; break;
			default:break;
			}
			break;
		case monster_direct::LEFTBOTTOM_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_leftbottom"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_leftbottom"; break;
			default:break;
			}
			break;
		case monster_direct::MIDDLEBOTTOM_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_middlebottom"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_middlebottom"; break;
			default:break;
			}
			break;
		case monster_direct::RIGHTBOTTOM_ATT:
			switch (_monster_form)
			{
			case monster_form::ORC:_image_name = "orc_att_rightbottom"; break;
			case monster_form::WOLFMAN:_image_name = "wol_att_rightbottom"; break;
			default:break;
			}
			break;
		}

		switch (_monster_form)
		{
		case monster_form::ORC: IMAGEMANAGER->frameRender(_image_name, getMemDC(), _startX - 10, _startY - 10, _current_x, _current_y); break;
		case monster_form::WOLFMAN: IMAGEMANAGER->frameRender(_image_name, getMemDC(), _startX - 10, _startY - 30, _current_x, _current_y); break;
		}
		if(_mon_hpbar_on) _hpBar->render();
	}
}

void Monster::Load(int loadCount)
{
	file = CreateFile(fileName[loadCount], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tileMap, sizeof(TagTile) * TILE_COUNT_X * TILE_COUNT_Y, &read, NULL);
	CloseHandle(file);
}

void Monster::MoveFunction()
{
	_frame_count++;
	if (_frame_count > 12.5)
	{
		_current_x++;
		if (_current_x >= 4)
			_current_x = 0;
		_frame_count = 0;
	}
	if (_monster_direct == monster_direct::LEFTTOP)
	{
		_monster_direct_temp = monster_direct::LEFTTOP;
		_moveX -= _monster_speedx;
		_moveY -= _monster_speedy;
		_moveDist_y += _monster_speedy;
		if (RADIUS_HEIGHT == _moveDist_y)
		{
			_start_isoX--;
			_monster_move = false;
			_pathList_count++;
		}
	}
	if (_monster_direct == monster_direct::MIDDLETOP)
	{
		_monster_direct_temp = monster_direct::MIDDLETOP;
		_moveY -= _monster_speedy;
		_moveDist_y += _monster_speedy;
		if (CELL_HEIGHT == _moveDist_y)
		{
			_start_isoX--;
			_start_isoY--;
			_monster_move = false;
			_pathList_count++;
		}
	}
	if (_monster_direct == monster_direct::RIGHTTOP)
	{
		_monster_direct_temp = monster_direct::RIGHTTOP;
		_moveX += _monster_speedx;
		_moveY -= _monster_speedy;
		_moveDist_y += _monster_speedy;
		if (RADIUS_HEIGHT == _moveDist_y)
		{
			_start_isoY--;
			_monster_move = false;
			_pathList_count++;
		}
	}
	if (_monster_direct == monster_direct::MIDDLELEFT)
	{
		_monster_direct_temp = monster_direct::MIDDLELEFT;
		_moveX -= _monster_speedx;
		_moveDist_x += _monster_speedx;
		if (CELL_WIDTH == _moveDist_x)
		{
			_start_isoX--;
			_start_isoY++;
			_monster_move = false;
			_pathList_count++;
		}
	}
	if (_monster_direct == monster_direct::MIDDLERIGHT)
	{
		_monster_direct_temp = monster_direct::MIDDLERIGHT;
		_moveX += _monster_speedx;
		_moveDist_x += _monster_speedx;
		if (CELL_WIDTH == _moveDist_x)
		{
			_start_isoX++;
			_start_isoY--;
			_monster_move = false;
			_pathList_count++;
		}
	}
	if (_monster_direct == monster_direct::LEFTBOTTOM)
	{
		_monster_direct_temp = monster_direct::LEFTBOTTOM;
		_moveX -= _monster_speedx;
		_moveY += _monster_speedy;
		_moveDist_y += _monster_speedy;
		if (RADIUS_HEIGHT == _moveDist_y)
		{
			_start_isoY++;
			_monster_move = false;
			_pathList_count++;
		}
	}
	if (_monster_direct == monster_direct::MIDDLEBOTTOM)
	{
		_monster_direct_temp = monster_direct::MIDDLEBOTTOM;
		_moveY += _monster_speedy;
		_moveDist_y += _monster_speedy;
		if (CELL_HEIGHT == _moveDist_y)
		{
			_start_isoX++;
			_start_isoY++;
			_monster_move = false;
			_pathList_count++;
		}
	}
	if (_monster_direct == monster_direct::RIGHTBOTTOM)
	{
		_monster_direct_temp = monster_direct::RIGHTBOTTOM;
		_moveX += _monster_speedx;
		_moveY += _monster_speedy;
		_moveDist_y += _monster_speedy;
		if (RADIUS_HEIGHT == _moveDist_y)
		{
			_start_isoX++;
			_monster_move = false;
			_pathList_count++;
		}
	}
}

void Monster::AttackFunction()
{
	_frame_count++;
	if (_frame_count > 12.5)
	{
		_current_x++;
		if (_current_x >= 4)
		{
			_current_x = 0;
			_gameScene->set_player_hp(-(_monster_stats._att) + _gameScene->get_player_stats()._def / 7 + RND->getInt(5));
		}
		_frame_count = 0;
	}
	if (_monster_direct == monster_direct::MIDDLETOP_ATT || _monster_direct == monster_direct::LEFTTOP_ATT ||
		_monster_direct == monster_direct::RIGHTTOP_ATT || _monster_direct == monster_direct::MIDDLELEFT_ATT ||
		_monster_direct == monster_direct::MIDDLERIGHT_ATT || _monster_direct == monster_direct::LEFTBOTTOM_ATT || 
		_monster_direct == monster_direct::MIDDLEBOTTOM_ATT || _monster_direct == monster_direct::RIGHTBOTTOM_ATT)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_monster_attack_on = false;
			_player_att_on = false;
		}
	}
}

void Monster::tileInitializing()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j].parent = NULL;	//�θ�Ÿ��
			_tileMap[i][j].F = BIGNUM;		//�ʱⰪ F
			_tileMap[i][j].H = 0;			//������̹Ƿ� 0
			_tileMap[i][j].i = i;			// �迭 y ��ġ
			_tileMap[i][j].j = j;			// �迭 x ��ġ
			for (int z = 0; z < 1; z++)
			{
				if (_tileMap[i][j].tileKind[z] == TILEKIND_TERRAIN)
				{
					_tileMap[i][j].walkable = true;
					_tileMap[i][j].listOn = false;
				}
				else if (_tileMap[i][j].tileKind[z] == TILEKIND_OBJECT)
				{
					_tileMap[i][j].walkable = false; // ���̸� walkable->false
					_tileMap[i][j].listOn = false;
				}
				else if (_tileMap[i][j].tileKind[z] == TILEKIND_PLAYER)
				{
					_tileMap[i][j].walkable = true;
					_tileMap[i][j].listOn = true;	  // ���������� Ŭ���� ����Ʈ�� �߰�.

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

void Monster::addOpenList()
{
	Ci = _closeList.back()->i; //y��.    //���������� �߰��� Ŭ�����Ʈ i
	Cj = _closeList.back()->j; //x��. 
	Cg = _closeList.back()->G;

	if (Ci != 0)//0��° ���� �ƴϸ� ����߰������
	{
		if (_tileMap[Ci - 1][Cj].walkable)//��� ��� Ÿ���� �������� �ִٸ�
		{
			if (!_tileMap[Ci - 1][Cj].listOn)//���¸���Ʈ�� ������ �ȵǾ� �ִ� Ÿ���̶��
			{
				_tileMap[Ci - 1][Cj].listOn = true;//���¸���Ʈ�� ���Խ�Ŵ
				_tileMap[Ci - 1][Cj].G = Cg + 10;	//Ÿ���� G���� Ŭ���� ����Ʈ�� ���� G+10
				_tileMap[Ci - 1][Cj].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
				_openList.push_back(&_tileMap[Ci - 1][Cj]);//���¸���Ʈ�� �߰�
			}
			else//���¸���Ʈ�� ������ �Ǿ� �ִ� Ÿ���̶��
			{
				if (Cg + 10 < _tileMap[Ci - 1][Cj].G)//����G������ ���� ����� G���� �۴ٸ�
				{
					_tileMap[Ci - 1][Cj].G = Cg + 10;//G�� ���Ӱ� ���
					_tileMap[Ci - 1][Cj].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
				}
			}
		}
		if (Cj != 0)//0��° ���� �ƴ϶�� �»�ܺ����
		{
			//�»�� Ÿ���� �������̳� �Ʒ��� ���� ���ٸ�
			if (_tileMap[Ci - 1][Cj - 1].walkable) // �»��, �»���� ������, �»���� �Ʒ���.
			{
				if (!_tileMap[Ci - 1][Cj - 1].listOn)//���¸���Ʈ�� ������ �ȵǾ� �ִ� Ÿ���̶��
				{
					_tileMap[Ci - 1][Cj - 1].listOn = true;
					_tileMap[Ci - 1][Cj - 1].G = Cg + 10;//�밢���̹Ƿ�
					_tileMap[Ci - 1][Cj - 1].parent = _closeList.back();
					_openList.push_back(&_tileMap[Ci - 1][Cj - 1]);
				}
				else
				{
					if (Cg + 14 < _tileMap[Ci - 1][Cj - 1].G)
					{
						_tileMap[Ci - 1][Cj - 1].G = Cg + 10;//�밢���̹Ƿ�
						_tileMap[Ci - 1][Cj - 1].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
					}
				}
			}
		}
		if (Cj != TILE_COUNT_X - 1)//����: ���������� �ƴ϶��
		{
			//���� Ÿ���� �����̳� �Ʒ��� ���� ���ٸ�
			if (_tileMap[Ci - 1][Cj + 1].walkable) // ����, ������ ����, ������ �Ʒ�.
			{
				if (!_tileMap[Ci - 1][Cj + 1].listOn)
				{
					_tileMap[Ci - 1][Cj + 1].listOn = true;
					_tileMap[Ci - 1][Cj + 1].G = Cg + 10;
					_tileMap[Ci - 1][Cj + 1].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
					_openList.push_back(&_tileMap[Ci - 1][Cj + 1]);
				}
				else
				{
					if (Cg + 14 < _tileMap[Ci - 1][Cj + 1].G)
					{
						_tileMap[Ci - 1][Cj + 1].G = Cg + 10;
						_tileMap[Ci - 1][Cj + 1].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
					}
				}
			}
		}
	}
	if (Cj != 0)//���� : 0��° ���� �ƴ϶��
	{
		if (_tileMap[Ci][Cj - 1].walkable)//����Ÿ���� �̵������ϴٸ�
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
	if (Cj != TILE_COUNT_X - 1)//���� :  ���������� �ƴ϶��
	{

		if (_tileMap[Ci][Cj + 1].walkable)//����Ÿ���� �̵������ϴٸ�
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
	if (Ci != TILE_COUNT_Y - 1)//���������� �ƴ϶�� �ϴ� ���� ���
	{
		if (_tileMap[Ci + 1][Cj].walkable)//�ϴ� ��� Ÿ���� �̵������ϴٸ�
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
		if (Cj != 0)//���ϴ� :  0��° ���� �ƴ϶��
		{
			//���ϴ� Ÿ���� �������̳� ���� ���� ���ٸ�
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
		if (Cj != TILE_COUNT_X - 1)//���ϴ� :  ������ ���� �ƴ϶��
		{
			//���ϴ� Ÿ���� �����̳� ���� �̵������ϴٸ�
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

void Monster::calculateH()
{
	for (int i = 0; i < _openList.size(); i++)//���¸���Ʈ������ ��� ��ҿ� ���Ͽ� ���.
	{
		int vertical = (_end_i - _openList[i]->i) * 10;    //���� H�� . x�� ��.  ������(left) - �ش� rect�� �������� x�� �Ÿ���
		int horizontal = (_end_j - _openList[i]->j) * 10;  //���� H��. y�� ��. ����(top) - �ش� rect�� �������� y�� �Ÿ���

		if (vertical < 0)vertical *= -1;//������ �ݴ��̸� �����ο�(���밪)
		if (horizontal < 0)horizontal *= -1;

		_openList[i]->H = vertical + horizontal;//�� H�� : ����+���� H
	}
}

void Monster::calculateF()
{
	for (int i = 0; i < _openList.size(); i++) //���¸���Ʈ������ ��� ��ҿ� ���Ͽ� ���.
	{
		_openList[i]->F = _openList[i]->G + _openList[i]->H;//F����� F = G + H.
	}
}

void Monster::addCloseList()
{
	if (_openList.size() == 0)//�˻��ߴµ��� openList�� ����� 0�̸� ���̻� ã������ ����
	{
		//_astarState = ASTAR_STATE_NOWAY;//��ξ���
		return;
	}
	int index = 0;			//���� ����Ʈ�� ���� F�� ���� Ÿ���� �ε����� ���� ����.
	int lowest = BIGNUM;

	for (int i = 0; i < _openList.size(); i++) // ���¸���Ʈ ���� ��ü�� ���ؼ� ���� F�� ���� ��Ҹ� ���ϰ� �׿���� i���� index�� ����.
	{
		if (_openList[i]->F < lowest)
		{
			lowest = _openList[i]->F;
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
	_openList.erase(_openList.begin() + index);//Ŭ���� ����Ʈ�� �߰��� Ÿ���� ���¸���Ʈ���� ����

}

void Monster::checkArrive()
{
	if (_start_isoX == _end_i && _start_isoY == _end_j)
	{
		_openList.clear();
		_closeList.clear();
		_calcul_on = false;
		_pathList.clear();
		_closeList.push_back(&_tileMap[_start_isoX][_start_isoY]);
		_pathList_count = 0;
		for (int i = 0; i < TILE_COUNT_X; i++)
		{
			for (int j = 0; j < TILE_COUNT_Y; j++)
			{
				_tileMap[i][j].parent = NULL;	//�θ�Ÿ��
				_tileMap[i][j].F = BIGNUM;		//�ʱⰪ F
				_tileMap[i][j].H = 0;			//������̹Ƿ� 0
				_tileMap[i][j].G = 0;			//������̹Ƿ� 0
				_tileMap[i][j].i = i;			// �迭 y ��ġ
				_tileMap[i][j].j = j;			// �迭 x ��ġ
				_tileMap[i][j].listOn = false;
			}
		}
		_tileMap[_start_isoX][_start_isoY].listOn = true;

		_isArrive = true;
		_calcul_on = true;
		return;
	}
}

void Monster::addPathList(TagTile * tile)
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
