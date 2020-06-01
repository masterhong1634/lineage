#pragma once
#include"gameNode.h"
#include"IsoTile.h"

enum player_form
{
	MAGICIAN,
	ORC,
	WOLFMAN,
};
enum player_direct
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

struct position
{
	int _isoX;
	int _isoY;
};

struct player_stats
{
	const char* _player_name = "케레니스";
	int _maxHp = 856;
	int _maxMp = 783;
	int _hp = 856;
	int _mp = 783;
	int _str = 16;
	int _dex = 14;
	int _con = 16;
	int _wis = 18;
	int _cha = 12;
	int _int = 18;
	int _att = 17;
	int _def = 8;
	int _magic_def = 10;
	int _spell_power = 16;
	int _idena = 1200000;
	int _exp = 0;
	int _hunger_gauge = 0;
	int _weight_gauge = 0;
	int _lawful_score = 0;
};
class Player
{
private:
	vector<TagTile*> _openList; // astar용 벡터
	vector<TagTile*> _closeList;
	vector<TagTile*> _pathList;
public:
	Player();
	~Player();

	HRESULT init();
	void release();
	void update();
	void render();
};

