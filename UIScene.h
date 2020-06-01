#pragma once
#include "gameNode.h"
#include "itemManager.h"

class UIScene : public gameNode
{
private:
	gameScene* _gameScene;

	vector<ItemInfo> vInventory; // 인벤토리
	vector<ItemInfo> vShopItem;  // 상점아이템

	//상점관련
	RECT pandora;
	RECT close_rect;
	RECT close_rect2;
	RECT buy_rect;
	RECT buy_rect2;
	bool shop_on = false;
	bool shop_buy = false;
	bool shop_tap = false;
	int  shop_buy_count[100]{ 0, };
	RECT shopUp_click[100] = { 0, };
	RECT shopDown_click[100] = { 0, };
	RECT purchase_rect = { 265, 530, 343, 555 };
	bool purchase_on = false;
	bool purchase_reject = false;
	int  purchase_count = 0;
	const RECT shop_uprect = { 345, 125, 365, 145 };
	const RECT shop_downrect = { 345, 490, 365, 510 };
	int  shopupdown_count = 0;
	int  shop_pulley_move = 0;

	//인벤토리
	const RECT  invenup_rect{1173, 45, 1190, 68};
	const RECT  invendown_rect{ 1173, 312, 1190, 335 };
	int  updown_count = 0;
	int  pulley_move = 0;
	bool inven_on = false;
	bool inven_itemrect = false;
	RECT inven_rect;
	RECT inven_close_rect;
	char str[128];
	bool equip_reject = false;
	int  equip_count = 0;

	//단축키창
	RECT function_key[8];
	bool funtion_recton = false;

	//UI
	RECT UI_rect;

	//미니맵관련
	int miniMap_x;
	int miniMap_y;

	//캐릭터 장비/스탯창
	bool character_tab_on = false;
	bool character_tab_rect = false;
	RECT earring1_rect	{ 51, 56, 101, 106 };
	RECT badge_rect		{ 51, 113, 101, 163 };
	RECT glove_rect		{ 51, 170, 101, 220 };
	RECT weapon_rect	{ 51, 227, 101, 277 };
	RECT ring1_rect		{ 51, 284, 101, 334 };
	RECT ring2_rect		{ 51, 341, 101, 391 };
	RECT rune_rect		{ 51, 398, 101, 448 };

	RECT helmet_rect	{ 120, 56,  170, 106 };
	RECT necklace_rect	{ 120, 113, 170, 163 };
	RECT tshirts_rect	{ 120, 170, 170, 220 };
	RECT armor_rect		{ 120, 227, 170, 277 };
	RECT belt_rect		{ 120, 284, 170, 334 };
	RECT leggings_rect	{ 120, 341, 170, 391 };
	RECT boots_rect		{ 120, 398, 170, 448 };

	RECT earring2_rect	{ 189, 56,  239, 106 };
	RECT pauldron_rect	{ 189, 113, 239, 163 };
	RECT cloak_rect		{ 189, 170, 239, 220 };
	RECT shield_rect	{ 189, 227, 239, 277 };
	RECT ring3_rect		{ 189, 284, 239, 334 };
	RECT ring4_rect		{ 189, 341, 239, 391 };
	RECT arms_rect		{ 189, 398, 239, 448 };


	//무기 장착 관련
	bool earring1_on = false;
	bool badge_on = false;
	bool glove_on = false;
	bool weapon_on = false;
	bool ring1_on = false;
	bool ring2_on = false;
	bool rune_on = false;
 
	bool helmet_on = false;
	bool necklace_on = false;
	bool tshirts_on = false;
	bool armor_on = false;
	bool belt_on = false;
	bool leggings_on = false;
	bool boots_on = false;
 
	bool earring2_on = false;
	bool pauldron_on = false;
	bool cloak_on = false;
	bool shield_on = false;
	bool ring3_on = false;
	bool ring4_on = false;
	bool arms_on = false;

	//속도의 물약, 용기의 물약
	bool _green_on = false;
	float _green_starttime = 0;
	bool _courage_on = false;
	float _courage_starttime = 0;

	//라우풀관련
	int UI_Lawful_num[5]{ 0, };
	//스펠파워관련
	int UI_Spell_num[2]{ 0, };
	//방어력 관련
	int UI_Def_num[2]{ 0, };
	bool _isDebug;
	//아데나 관련
	int UI_Adena_num[7]{ 0, };
	//종료관련
	bool restart_on = false;
	bool quit_on = false;
	RECT restart_rect{555, 320, 680, 370};
	RECT quit_rect{708, 320, 760, 370};

public:
	UIScene();
	~UIScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void setgameSceneMemoryLink(gameScene* gameScene) { _gameScene = gameScene; }

	bool getShop_on() { return shop_on; }
	void setShop_on(bool onoff) { shop_on = onoff; }
	bool getShop_buy() { return shop_buy; }
	bool getinven_on() { return inven_on; }
	void setinven_on(bool onoff) { inven_on = onoff; }
	bool get_restart_on() { return restart_on; }

	//아이템 착용관련
	bool get_weapon_on() { return weapon_on; }

	//인벤토리내 더블클릭
	void itemDBClick();
	void purchase();
};

