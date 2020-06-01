#pragma once
#include"gameNode.h"
#include"Player.h"
#include"IsoTile.h"
#include"progressBar.h"

class UIScene;
class Monster;
class monsterManager;
class gameScene : public gameNode
{
private:
	
	HCURSOR mh_scope_cursor, mh_prev_cursor;

	TagTile _tileMap[TILE_COUNT_X][TILE_COUNT_Y];

	vector<TagTile*> _openList; // astar�� ����
	vector<TagTile*> _closeList;
	vector<TagTile*> _pathList;

	Monster* _monster;
	monsterManager* _monsterManager;
	UIScene* _UIScene;

	//��ų ����
	RECT temp; // ��ų �浹��
	bool _skill_meteor = false;
	RECT meteor_rect;
	bool _skill_icespike = false;

	//���α׷�����
	progressBar* _hpBar;
	float _maxHP;
	float _currentHP;
	progressBar* _mpBar;
	float _maxMP;
	float _currentMP;
	int hp_num[3]{ 0, };
	int max_hp_num[3]{ 0, };
	int mp_num[3]{ 0, };
	int max_mp_num[3]{ 0, };

	//�̴ϸʰ���
	int minimap_direction;

	//���θʰ���
	int _isoX, _isoY;
	int _center;
	char str[128];
	char str1[128];
	char str2[128];

	double _startX;
	double _startY;
	double &x = _startX;
	double &y = _startY;

	int isoX, isoY;

	//��������
	RECT pandora;
	RECT close_rect;
	RECT close_rect2;
	RECT buy_rect;
	RECT buy_rect2;
	RECT buy_rect3;
	bool shop_on = false;
	bool shop_buy = false;
	bool shop_tap = false;
	//�κ��丮
	//bool inven_on = false;
	RECT inven_rect;

	//UI
	RECT UI_rect;

	int _start_i;
	int _start_j;
	int _end_i;
	int _end_j;

	int Ci;
	int Cj;
	int Cg;

	//�÷��̾� ����
	player_stats _player_stats;
	position _player;
	position _player_dest;
	player_direct _player_direct;
	player_form _player_form;
	player_direct _player_direct_temp;
	RECT _player_rect;
	BOOL _player_rect_on = false;

	double frame_attack_speed = 12.5;
	double frame_move_speed = 12.5;
		
	int _attack_skill_rnd = 0;
	double _moveDist_x;
	double _moveDist_y;
	bool _player_move;
	bool _calcul_on;
	bool _player_attack_on;
	int _pathList_count = 0;

	double _player_speedx = 2;
	double _player_speedy = 1;
	char* _image_name = "";
	int _current_x = 0;
	int _current_y = 0;
	float _frame_count = 0;

	bool _isDebug;

	RECT _winsize = { -50,-50,WINSIZEX + 50,WINSIZEY + 50 };
	RECT _temp;
	POINT _rhombus;
	POINT _rhombus2;
	//
	const char* fileName[10] = { "map1.map","map2.map","map3.map","map4.map","map5.map","map6.map","map7.map","map8.map","map9.map","map10.map" };
	HANDLE file;
	DWORD write;
	DWORD read;
public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();

	//Ÿ�ϸ� �׸���.
	void DrawTileMap();

	//������ �׸���
	void DrawRhombus(int left, int top);
	//�ڳʰ���(1~4�и�)
	int GetCornerIndex(int isoX, int isoY);

	//������ �ȿ� ����?
	bool IsInRhombus(int corner, int isoX, int isoY);

	void Load(int loadCount);

	void MoveFunction();
	void AttackFunction();

	void tileInitializing();	//��ġ�� �Ӽ��� �°� Ÿ�� �ʱ�ȭ
	void addOpenList();			//���� ����Ʈ �߰�
	void calculateH();			//���� ����Ʈ�� Ÿ�� H�����
	void calculateF();			//���� ����Ʈ�� Ÿ�� F�����
	void addCloseList();		//���� ���� F������ Ŭ���� ����Ʈ�� �߰�
	void checkArrive();			//�����ߴ��� ���� üũ
	void addPathList(TagTile* tile);
	   
	void setMonsterMemoryLink(Monster* monster) { _monster = monster; }
	void setMonsterManagerLink(monsterManager* monsterManager) { _monsterManager = monsterManager; }
	void setUIMemoryLink(UIScene* uiscene) { _UIScene = uiscene; }
	TagTile getTile(int x, int y) { return _tileMap[x][y]; }

	//���θ�
	int getStartX() { return _startX; }
	int getStartY() { return _startY; }
	int get_start_i() { return _start_i; }
	int get_start_j() { return _start_j; }

	//�÷��̾�Ӽ�
	void set_player_attack_on(bool player_attack_on) { _player_attack_on = player_attack_on; }
	int get_player_lawful() { return _player_stats._lawful_score; }
	void set_player_lawful(int addlawful_score) { _player_stats._lawful_score += addlawful_score; }
	int get_player_adena() { return _player_stats._idena; }
	int get_player_spell() { return _player_stats._spell_power; }
	int get_player_def() { return _player_stats._def; }
	void set_player_adena(int x) { _player_stats._idena += x; }
	void set_player_attack(int x) { _player_stats._att += x; }
	void set_player_defence(int x) { _player_stats._def += x; }
	void set_player_spell(int x) { _player_stats._spell_power += x; }

	player_stats get_player_stats() { return _player_stats; }
	int get_player_hp() { return _player_stats._hp; }
	void set_player_hp(int x) { _player_stats._hp += x; }
	void set_player_mp(int x) { _player_stats._mp += x; }
	void set_player_hpMAX() { _player_stats._hp = _player_stats._maxHp; }
	void set_player_mpMAX() { _player_stats._mp = _player_stats._maxMp; }
	void set_player_speed_plus() { frame_attack_speed *= 0.6; frame_move_speed *= 0.6; _player_speedx *= 1.25; _player_speedy *= 1.25; }
	void set_player_speed_minus() { frame_attack_speed /= 0.6; frame_move_speed /= 0.6; _player_speedx /= 1.25; _player_speedy /= 1.25; }

	//�̴ϸ�
	int get_minimap_direction() { return minimap_direction; }

};

