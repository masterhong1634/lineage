#pragma once
#include "singletonBase.h"

enum ItemKind
{
	ITEM_WEAPON,		// 무기
	ITEM_ARMOR,			// 갑옷
	ITEM_LEGGINGS,		// 각반
	ITEM_BOOTS,			// 부츠
	ITEM_TSHIRTS,		// 티셔츠
	ITEM_HELMET,		// 투구
	ITEM_GLOVES,		// 장갑
	ITEM_CLOAK,			// 망토
	ITEM_SHIELD,		// 방패
	ITEM_EARRING1,		// 귀걸이
	ITEM_EARRING2,		// 귀걸이
	ITEM_NECKLACE,		// 귀걸이
	ITEM_RING1,			// 반지
	ITEM_RING2,			// 반지
	ITEM_RING3,			// 반지
	ITEM_RING4,			// 반지
	ITEM_BELT,			// 벨트
	ITEM_ARMS,			// 문장
	ITEM_BADGE,			// 휘장
	ITEM_PAULDRON,		// 견갑
	ITEM_RUNE,			// 룬
	ITEM_POTION,		// 물약
	ITEM_IDENA,			// 아데나
	ITEM_MAGIC_ORDER,	// 주문서
	ITEM_NULL,
};
struct ItemInfo
{
	ItemKind	itemKind;				// 아이템 종류
	image*		itemImage;				// 아이템 이미지
	const char* itemImageName;			// 아이템 이미지 이름
	image*		itemInfoImage;			// 아이템 UI이미지
	RECT		itemRect = { -100, };	// 아이템 생성위치
	RECT		itemUIRect = { -100, };	// 아이템 UI위치
	bool		inven_in = false;		// 인벤에 들어갔는지
	const char* itemName;				// 아이템 이름
	bool		equip_on = false;		// 착용했는지 안했는지
	float		addAttack = 0;;			// 플레이어 공격력 증감
	float		addSpell = 0;;			// 플레이어 스펠 증감
	float		addDefence = 0;;		// 플레이어 방어력 증감
	float		addMagicDefence = 0;;	// 플레이어 마법방어력 증감
	float		addSpeed = 0;;			// 플레이어 속도 증감
	int			amount = 0;;			// 아이템 수량
	int			weight = 0;;			// 아이템 무게
	float		addHP = 0;;				// 현재 HP 증감
	float		addMP = 0;;				// 현재 HP 증감
	int			price;;					// 아이템 가격
};

class itemManager : public singletonBase<itemManager>
{
private:
	vector<ItemInfo> vAllItem; // 모든 아이템
	ItemInfo temp;
	ItemInfo small_red_potion;
	ItemInfo small_white_potion;
	ItemInfo big_green_potion;
	ItemInfo big_red_potion;
	ItemInfo big_white_potion;
	ItemInfo blue_potion;
	ItemInfo teleport_order;
	ItemInfo identify_order;
	ItemInfo return_order;
	ItemInfo transform_order;
	ItemInfo cristal_staff;
	ItemInfo lyndbeor_armor;
	ItemInfo Beltofknowledge;
	ItemInfo blackelder_sandal;
	ItemInfo Devils_ring1;
	ItemInfo Devils_ring2;
	ItemInfo MagicDefenseGaiters;
	ItemInfo MagicalGloves;
	ItemInfo ProphetsPauldrons;
	ItemInfo Purple_earrings;
	ItemInfo QueenAnts_SilverWings;
	ItemInfo Red_earrings;
	ItemInfo Ringofwisdom1;
	ItemInfo Ringofwisdom2;
	ItemInfo Sages_Necklace;
	ItemInfo Seers_Eye;
	ItemInfo Wizards_hat;
	ItemInfo Tshirts;

public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();

	ItemInfo get_temp() { return temp; }
	ItemInfo get_small_red_potion() { return small_red_potion; }
	ItemInfo get_small_white_potion() { return small_white_potion; }
	ItemInfo get_big_green_potion() { return big_green_potion; }
	ItemInfo get_big_red_potion() { return big_red_potion; }
	ItemInfo get_big_white_potion() { return big_white_potion; }
	ItemInfo get_blue_potion() { return blue_potion; }
	ItemInfo get_teleport_order() { return teleport_order; }
	ItemInfo get_identify_order() { return identify_order; }
	ItemInfo get_return_order() { return return_order; }
	ItemInfo get_transform_order() { return transform_order; }
	ItemInfo get_cristal_staff() { return cristal_staff; }
	ItemInfo get_lyndbeor_armor() { return lyndbeor_armor; }
	ItemInfo get_Beltofknowledge() { return Beltofknowledge; }
	ItemInfo get_blackelder_sandal() { return blackelder_sandal; }
	ItemInfo get_Devils_ring1() { return Devils_ring1; }
	ItemInfo get_Devils_ring2() { return Devils_ring2; }
	ItemInfo get_MagicDefenseGaiters() { return MagicDefenseGaiters; }
	ItemInfo get_MagicalGloves() { return MagicalGloves; }
	ItemInfo get_ProphetsPauldrons() { return ProphetsPauldrons; }
	ItemInfo get_Purple_earrings() { return Purple_earrings; }
	ItemInfo get_QueenAnts_SilverWings() { return QueenAnts_SilverWings; }
	ItemInfo get_Red_earrings() { return Red_earrings; }
	ItemInfo get_Ringofwisdom1() { return Ringofwisdom1; }
	ItemInfo get_Ringofwisdom2() { return Ringofwisdom2; }
	ItemInfo get_Seers_Eye() { return Seers_Eye; }
	ItemInfo get_Wizards_hat() { return Wizards_hat; }
	ItemInfo get_Sages_Necklace() { return Sages_Necklace; }
	ItemInfo get_Tshirts() { return Tshirts; }
};

