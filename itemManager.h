#pragma once
#include "singletonBase.h"

enum ItemKind
{
	ITEM_WEAPON,		// ����
	ITEM_ARMOR,			// ����
	ITEM_LEGGINGS,		// ����
	ITEM_BOOTS,			// ����
	ITEM_TSHIRTS,		// Ƽ����
	ITEM_HELMET,		// ����
	ITEM_GLOVES,		// �尩
	ITEM_CLOAK,			// ����
	ITEM_SHIELD,		// ����
	ITEM_EARRING1,		// �Ͱ���
	ITEM_EARRING2,		// �Ͱ���
	ITEM_NECKLACE,		// �Ͱ���
	ITEM_RING1,			// ����
	ITEM_RING2,			// ����
	ITEM_RING3,			// ����
	ITEM_RING4,			// ����
	ITEM_BELT,			// ��Ʈ
	ITEM_ARMS,			// ����
	ITEM_BADGE,			// ����
	ITEM_PAULDRON,		// �߰�
	ITEM_RUNE,			// ��
	ITEM_POTION,		// ����
	ITEM_IDENA,			// �Ƶ���
	ITEM_MAGIC_ORDER,	// �ֹ���
	ITEM_NULL,
};
struct ItemInfo
{
	ItemKind	itemKind;				// ������ ����
	image*		itemImage;				// ������ �̹���
	const char* itemImageName;			// ������ �̹��� �̸�
	image*		itemInfoImage;			// ������ UI�̹���
	RECT		itemRect = { -100, };	// ������ ������ġ
	RECT		itemUIRect = { -100, };	// ������ UI��ġ
	bool		inven_in = false;		// �κ��� ������
	const char* itemName;				// ������ �̸�
	bool		equip_on = false;		// �����ߴ��� ���ߴ���
	float		addAttack = 0;;			// �÷��̾� ���ݷ� ����
	float		addSpell = 0;;			// �÷��̾� ���� ����
	float		addDefence = 0;;		// �÷��̾� ���� ����
	float		addMagicDefence = 0;;	// �÷��̾� �������� ����
	float		addSpeed = 0;;			// �÷��̾� �ӵ� ����
	int			amount = 0;;			// ������ ����
	int			weight = 0;;			// ������ ����
	float		addHP = 0;;				// ���� HP ����
	float		addMP = 0;;				// ���� HP ����
	int			price;;					// ������ ����
};

class itemManager : public singletonBase<itemManager>
{
private:
	vector<ItemInfo> vAllItem; // ��� ������
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

