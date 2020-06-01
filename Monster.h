#pragma once
#include"gameNode.h"
#include"IsoTile.h"
#include"progressBar.h"

class gameScene;
enum class monster_form
{
	ORC,
	WOLFMAN,
};
enum class monster_direct
{
	LEFTTOP,
	LEFTTOP_ATT,
	MIDDLETOP,
	MIDDLETOP_ATT,
	RIGHTTOP,
	RIGHTTOP_ATT,
	MIDDLELEFT,
	MIDDLELEFT_ATT,
	MIDDLERIGHT,
	MIDDLERIGHT_ATT,
	LEFTBOTTOM,
	LEFTBOTTOM_ATT,
	MIDDLEBOTTOM,
	MIDDLEBOTTOM_ATT,
	RIGHTBOTTOM,
	RIGHTBOTTOM_ATT,
	STOP,
	START,
};

struct mon_position
{
	int _isoX;
	int _isoY;
};

struct monster_stats
{
	const char* _monster_name = "";
	int _MaxHP = 150;
	int _hp = 150;
	int _mp = 20;
	int _att = 19;
	int _def = 7;
	int _magic_def = 12;
};

class Monster : public gameNode
{
private:

	TagTile _tileMap[TILE_COUNT_X][TILE_COUNT_Y];

	vector<TagTile*> _openList; // astar용 벡터
	vector<TagTile*> _closeList;
	vector<TagTile*> _pathList;

	gameScene* _gameScene;

	monster_form _monster_form;

	int isoX = 0;
	int isoY = 0;
	RECT temp;
	RECT _monster_rect;
	RECT _winsize = { 0,0,WINSIZEX, WINSIZEY };
	bool _mon_hpbar_on = true;

	int _startX;
	int _startY;

	int _start_isoX;
	int _start_isoY;

	int _changeCount;

	bool _isArrive;
	bool _start_Arrive;

	int _moveX;
	int _moveY;

	int _start_i;
	int _start_j;
	int _end_i;
	int _end_j;

	char str1[128];

	int Ci;
	int Cj;
	int Cg;

	//프로그레스바 
	bool _hpbar_on = false;
	progressBar* _hpBar;
	float _maxHP;
	float _currentHP;

	//몬스터 관련
	POINT _monster_point;
	monster_stats _monster_stats;
	mon_position _monster;
	mon_position _monster_dest;
	monster_direct _monster_direct;
	monster_direct _monster_direct_temp;

	int _moveDist_x;
	int _moveDist_y;
	bool _monster_move;
	bool _calcul_on;
	int _pathList_count = 0;

	//플레이어 -> 몬스터 공격 확인
	bool _player_att_on;
	bool _player_click;
	//몬스터 -> 공격
	bool _monster_attack_on;
	bool _auto_attack_on;

	int _monster_speedx = 2;
	int _monster_speedy = 1;
	char* _image_name = "";
	int _current_x = 0;
	int _current_y = 0;
	float _frame_count = 0;

	//
	const char* fileName[10] = { "map1.map","map2.map","map3.map","map4.map","map5.map","map6.map","map7.map","map8.map","map9.map","map10.map" };
	HANDLE file;
	DWORD write;
	DWORD read;

public:
	Monster();
	Monster(int x, int y, monster_form _monster);
	~Monster();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void Load(int loadCount);
	
	void MoveFunction();
	void AttackFunction();

	void tileInitializing();	//배치후 속성에 맞게 타일 초기화
	void addOpenList();			//오픈 리스트 추가
	void calculateH();			//오픈 리스트내 타일 H값계산
	void calculateF();			//오픈 리스트내 타일 F값계산
	void addCloseList();		//가장 작은 F선택후 클로즈 리스트에 추가
	void checkArrive();			//도착했는지 여부 체크
	void addPathList(TagTile* tile);

	void setgameSceneMemoryLink(gameScene* gameScene) { _gameScene = gameScene; }

	RECT get_monster_rect() { return _monster_rect; }
	int get_start_isoX() { return _start_isoX; }
	int get_start_isoY() { return _start_isoY; }
	void set_player_att_on(bool player_att_on) { _player_att_on = player_att_on; }
	bool get_player_att_on() { return _player_att_on; }
	void set_player_click(bool player_click) { _player_click = player_click; }
	bool get_player_click() { return _player_click; }

	monster_stats get_monster_stats() { return _monster_stats; }
	int get_monster_def() { return _monster_stats._def; }
	int get_monster_hp() { return _monster_stats._hp; }
	void set_monster_hp(int x) { _monster_stats._hp += x; }
	void set_mon_hpbar_on(bool onoff) { _mon_hpbar_on = onoff; }
	monster_form get_monster_form() {return _monster_form;}
};

