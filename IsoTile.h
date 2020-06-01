#pragma once

#define BIGNUM 5000		//초기값(F)

//크기
#define CELL_WIDTH 100
#define CELL_HEIGHT 50

#define RADIUS_WIDTH (CELL_WIDTH / 2)
#define RADIUS_HEIGHT (CELL_HEIGHT / 2)
//초기좌표
#define INIT_X 0
#define INIT_Y -3700
//타일 갯수
#define TILE_COUNT_X 160
#define TILE_COUNT_Y 160

//타일 이미지
#define TILE_SIZE_X 8
#define TILE_SIZE_Y 10

#define TILE_MAX 1
enum TILEKIND
{
	TILEKIND_OBJECT,
	TILEKIND_TERRAIN,
	TILEKIND_NONE,
	TILEKIND_PLAYER,
};

struct TagTile
{
	int left, top;
	RECT rc;
	int index;
	int tileNum[TILE_MAX];
	TILEKIND tileKind[TILE_MAX];
	POINT tilePos[TILE_MAX];
	bool walkable;			//지나갈수 있는지 여부
	bool listOn;			//openlist에 추가 되었는지 여부
	int i, j;
	int F, G, H;
	TagTile* parent;	//부모 타일 주소
};