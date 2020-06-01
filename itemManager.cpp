#include "stdafx.h"
#include "itemManager.h"

itemManager::itemManager()
{
}

itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	//��ĭ
	temp.itemKind = ITEM_NULL;				// ������ ����
	temp.itemImage = NULL;
	temp.itemImageName = NULL;
	temp.itemInfoImage = NULL;			// ������ UI�̹���
	temp.itemRect;				// ������ ������ġ
	temp.itemUIRect;			// ������ UI��ġ
	temp.itemName = NULL;				// ������ �̸�
	temp.addAttack;				// �÷��̾� ���ݷ� ����
	temp.addDefence;			// �÷��̾� ���� ����
	temp.addMagicDefence;		// �÷��̾� �������� ����
	temp.addSpeed;				// �÷��̾� �ӵ� ����
	temp.amount;				// ������ ����
	temp.weight;				// ������ ����
	temp.addHP;			// ���� HP ����
	temp.addMP;					// ���� MP ����
	temp.price;					// ������ ����
	vAllItem.push_back(temp);

	//����
	//���� ü�� ȸ����
	small_red_potion.itemKind = ITEM_POTION;				// ������ ����
	small_red_potion.itemImage =
		IMAGEMANAGER->addImage("small_red_potion", "images/small_red_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	small_red_potion.itemImageName = "small_red_potion";
	small_red_potion.itemInfoImage;			// ������ UI�̹���
	small_red_potion.itemRect;				// ������ ������ġ
	small_red_potion.itemUIRect;			// ������ UI��ġ
	small_red_potion.itemName = "���� ü�� ȸ����";				// ������ �̸�
	small_red_potion.addAttack;				// �÷��̾� ���ݷ� ����
	small_red_potion.addDefence;			// �÷��̾� ���� ����
	small_red_potion.addMagicDefence;		// �÷��̾� �������� ����
	small_red_potion.addSpeed;				// �÷��̾� �ӵ� ����
	small_red_potion.amount = 1;				// ������ ����
	small_red_potion.weight = 1;				// ������ ����
	small_red_potion.addHP = 20;			// ���� HP ����
	small_red_potion.addMP;					// ���� MP ����
	small_red_potion.price = 117;					// ������ ����
	vAllItem.push_back(small_red_potion);
	//���� ���� ü�� ȸ����
	small_white_potion.itemKind = ITEM_POTION;				// ������ ����
	small_white_potion.itemImage =
		IMAGEMANAGER->addImage("small_white_potion", "images/small_white_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	small_white_potion.itemImageName = "small_white_potion";
	small_white_potion.itemInfoImage;			// ������ UI�̹���
	small_white_potion.itemRect;				// ������ ������ġ
	small_white_potion.itemUIRect;				// ������ UI��ġ
	small_white_potion.itemName = "���� ���� ü�� ȸ����";				// ������ �̸�
	small_white_potion.addAttack;				// �÷��̾� ���ݷ� ����
	small_white_potion.addDefence;				// �÷��̾� ���� ����
	small_white_potion.addMagicDefence;		// �÷��̾� �������� ����
	small_white_potion.addSpeed;			// �÷��̾� �ӵ� ����
	small_white_potion.amount = 1;					// ������ ����
	small_white_potion.weight = 2;					// ������ ����
	small_white_potion.addHP = 50;				// ���� HP ����
	small_white_potion.addMP;					// ���� MP ����
	small_white_potion.price = 521;					// ������ ����
	vAllItem.push_back(small_white_potion);
	//���� �ӵ��� ����
	big_green_potion.itemKind = ITEM_POTION;				// ������ ����
	big_green_potion.itemImage =
		IMAGEMANAGER->addImage("big_green_potion", "images/big_green_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	big_green_potion.itemImageName = "big_green_potion";
	big_green_potion.itemInfoImage;			// ������ UI�̹���
	big_green_potion.itemRect;				// ������ ������ġ
	big_green_potion.itemUIRect;				// ������ UI��ġ
	big_green_potion.itemName = "���� �ӵ��� ����";				// ������ �̸�
	big_green_potion.addAttack;				// �÷��̾� ���ݷ� ����
	big_green_potion.addDefence;				// �÷��̾� ���� ����
	big_green_potion.addMagicDefence;		// �÷��̾� �������� ����
	big_green_potion.addSpeed = 1;				// �÷��̾� �ӵ� ����
	big_green_potion.amount = 1;					// ������ ����
	big_green_potion.weight = 5;					// ������ ����
	big_green_potion.addHP;				// ���� HP ����
	big_green_potion.addMP;					// ���� MP ����
	big_green_potion.price = 1329;					// ������ ����
	vAllItem.push_back(big_green_potion);
	//�ż� ü�� ȸ����
	big_red_potion.itemKind = ITEM_POTION;				// ������ ����
	big_red_potion.itemImage = 
		IMAGEMANAGER->addImage("big_red_potion", "images/big_red_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	big_red_potion.itemImageName = "big_red_potion";
	big_red_potion.itemInfoImage;			// ������ UI�̹���
	big_red_potion.itemRect;				// ������ ������ġ
	big_red_potion.itemUIRect;				// ������ UI��ġ
	big_red_potion.itemName = "�ż� ü�� ȸ����";				// ������ �̸�
	big_red_potion.addAttack;				// �÷��̾� ���ݷ� ����
	big_red_potion.addDefence;				// �÷��̾� ���� ����
	big_red_potion.addMagicDefence;		// �÷��̾� �������� ����
	big_red_potion.addSpeed;			// �÷��̾� �ӵ� ����
	big_red_potion.amount = 1;					// ������ ����
	big_red_potion.weight = 2;					// ������ ����
	big_red_potion.addHP = 25;				// ���� HP ����
	big_red_potion.addMP;					// ���� MP ����
	big_red_potion.price = 177;					// ������ ����
	vAllItem.push_back(big_red_potion);
	//�ż� ���� ü�� ȸ����
	big_white_potion.itemKind = ITEM_POTION;				// ������ ����
	big_white_potion.itemImage = 
		IMAGEMANAGER->addImage("big_white_potion", "images/big_white_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	big_white_potion.itemImageName = "big_white_potion";
	big_white_potion.itemInfoImage;			// ������ UI�̹���
	big_white_potion.itemRect;				// ������ ������ġ
	big_white_potion.itemUIRect;				// ������ UI��ġ
	big_white_potion.itemName = "�ż� ���� ü�� ȸ����";				// ������ �̸�
	big_white_potion.addAttack;				// �÷��̾� ���ݷ� ����
	big_white_potion.addDefence;				// �÷��̾� ���� ����
	big_white_potion.addMagicDefence;		// �÷��̾� �������� ����
	big_white_potion.addSpeed;			// �÷��̾� �ӵ� ����
	big_white_potion.amount = 1;					// ������ ����
	big_white_potion.weight = 4;					// ������ ����
	big_white_potion.addHP = 70;				// ���� HP ����
	big_white_potion.addMP;					// ���� MP ����
	big_white_potion.price = 782;					// ������ ����
	vAllItem.push_back(big_white_potion);
	//���� ������ ����
	blue_potion.itemKind = ITEM_POTION;				// ������ ����
	blue_potion.itemImage =
		IMAGEMANAGER->addImage("blue_potion", "images/blue_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	blue_potion.itemImageName = "blue_potion";
	blue_potion.itemInfoImage;			// ������ UI�̹���
	blue_potion.itemRect;				// ������ ������ġ
	blue_potion.itemUIRect;				// ������ UI��ġ
	blue_potion.itemName = "���� ������ ����";				// ������ �̸�
	blue_potion.addAttack;				// �÷��̾� ���ݷ� ����
	blue_potion.addDefence;				// �÷��̾� ���� ����
	blue_potion.addMagicDefence;		// �÷��̾� �������� ����
	blue_potion.addSpeed;			// �÷��̾� �ӵ� ����
	blue_potion.amount = 1;					// ������ ����
	blue_potion.weight = 5;					// ������ ����
	blue_potion.addHP;				// ���� HP ����
	blue_potion.addMP = 100;					// ���� MP ����
	blue_potion.price = 1980;					// ������ ����
	vAllItem.push_back(blue_potion);

	//�ֹ���
	//�����̵� �ֹ���
	teleport_order.itemKind = ITEM_MAGIC_ORDER;				// ������ ����
	teleport_order.itemImage =
		IMAGEMANAGER->addImage("teleport_order", "images/teleport_order.bmp", 50, 50, true, RGB(255, 0, 255));
	teleport_order.itemImageName = "teleport_order";
	teleport_order.itemInfoImage;			// ������ UI�̹���
	teleport_order.itemRect;				// ������ ������ġ
	teleport_order.itemUIRect;				// ������ UI��ġ
	teleport_order.itemName = "�����̵� �ֹ���";				// ������ �̸�
	teleport_order.addAttack;				// �÷��̾� ���ݷ� ����
	teleport_order.addDefence;				// �÷��̾� ���� ����
	teleport_order.addMagicDefence;		// �÷��̾� �������� ����
	teleport_order.addSpeed;			// �÷��̾� �ӵ� ����
	teleport_order.amount = 1;					// ������ ����
	teleport_order.weight = 1;					// ������ ����
	teleport_order.addHP;				// ���� HP ����
	teleport_order.addMP;					// ���� MP ����
	teleport_order.price = 157;					// ������ ����
	vAllItem.push_back(teleport_order);
	//Ȯ�� �ֹ���
	identify_order.itemKind = ITEM_MAGIC_ORDER;					// ������ ����
	identify_order.itemImage =
		IMAGEMANAGER->addImage("identify_order", "images/identify_order.bmp", 50, 50, true, RGB(255, 0, 255));
	identify_order.itemImageName = "identify_order";
	identify_order.itemInfoImage;			// ������ UI�̹���
	identify_order.itemRect;				// ������ ������ġ
	identify_order.itemUIRect;				// ������ UI��ġ
	identify_order.itemName = "Ȯ�� �ֹ���";				// ������ �̸�
	identify_order.addAttack;				// �÷��̾� ���ݷ� ����
	identify_order.addDefence;				// �÷��̾� ���� ����
	identify_order.addMagicDefence;		// �÷��̾� �������� ����
	identify_order.addSpeed;			// �÷��̾� �ӵ� ����
	identify_order.amount = 1;					// ������ ����
	identify_order.weight = 1;					// ������ ����
	identify_order.addHP;				// ���� HP ����
	identify_order.addMP;					// ���� MP ����
	identify_order.price = 133;					// ������ ����
	vAllItem.push_back(identify_order);
	//��ȯ �ֹ���
	return_order.itemKind = ITEM_MAGIC_ORDER;					// ������ ����
	return_order.itemImage =
		IMAGEMANAGER->addImage("return_order", "images/return_order.bmp", 50, 50, true, RGB(255, 0, 255));
	return_order.itemImageName = "return_order";
	return_order.itemInfoImage;			// ������ UI�̹���
	return_order.itemRect;				// ������ ������ġ
	return_order.itemUIRect;				// ������ UI��ġ
	return_order.itemName = "Ȯ�� �ֹ���";				// ������ �̸�
	return_order.addAttack;				// �÷��̾� ���ݷ� ����
	return_order.addDefence;				// �÷��̾� ���� ����
	return_order.addMagicDefence;		// �÷��̾� �������� ����
	return_order.addSpeed;			// �÷��̾� �ӵ� ����
	return_order.amount = 1;					// ������ ����
	return_order.weight = 1;					// ������ ����
	return_order.addHP;				// ���� HP ����
	return_order.addMP;					// ���� MP ����
	return_order.price = 133;					// ������ ����
	vAllItem.push_back(return_order);
	//���� �ֹ���
	transform_order.itemKind = ITEM_MAGIC_ORDER;					// ������ ����
	transform_order.itemImage =
		IMAGEMANAGER->addImage("transform_order", "images/transform_order.bmp", 50, 50, true, RGB(255, 0, 255));
	transform_order.itemImageName = "transform_order";
	transform_order.itemInfoImage;			// ������ UI�̹���
	transform_order.itemRect;				// ������ ������ġ
	transform_order.itemUIRect;				// ������ UI��ġ
	transform_order.itemName = "���� �ֹ���";				// ������ �̸�
	transform_order.addAttack;				// �÷��̾� ���ݷ� ����
	transform_order.addDefence;				// �÷��̾� ���� ����
	transform_order.addMagicDefence;		// �÷��̾� �������� ����
	transform_order.addSpeed;			// �÷��̾� �ӵ� ����
	transform_order.amount = 1;					// ������ ����
	transform_order.weight = 1;					// ������ ����
	transform_order.addHP;				// ���� HP ����
	transform_order.addMP;					// ���� MP ����
	transform_order.price = 133;					// ������ ����
	vAllItem.push_back(transform_order);

	//��������ü ������
	cristal_staff.itemKind = ITEM_WEAPON;					// ������ ����
	cristal_staff.itemImage =
		IMAGEMANAGER->addImage("cristal_staff", "images/cristal_staff.bmp", 50, 50, true, RGB(255, 0, 255));
	cristal_staff.itemImageName = "cristal_staff";
	cristal_staff.itemInfoImage;			// ������ UI�̹���
	cristal_staff.itemRect;				// ������ ������ġ
	cristal_staff.itemUIRect;				// ������ UI��ġ
	cristal_staff.itemName = "��������ü ������";				// ������ �̸�
	cristal_staff.addAttack = 15;				// �÷��̾� ���ݷ� ����
	cristal_staff.addSpell = 15;				// �÷��̾� ���� ����
	cristal_staff.addDefence;				// �÷��̾� ���� ����
	cristal_staff.addMagicDefence;		// �÷��̾� �������� ����
	cristal_staff.addSpeed;			// �÷��̾� �ӵ� ����
	cristal_staff.amount = 1;					// ������ ����
	cristal_staff.weight = 60;					// ������ ����
	cristal_staff.addHP;				// ���� HP ����
	cristal_staff.addMP;					// ���� MP ����
	cristal_staff.price = 188990;					// ������ ����
	vAllItem.push_back(cristal_staff);

	//���������� ����
	lyndbeor_armor.itemKind = ITEM_ARMOR;					// ������ ����
	lyndbeor_armor.itemImage =
		IMAGEMANAGER->addImage("lyndbeor_armor", "images/lyndbeor_armor.bmp", 50, 50, true, RGB(255, 0, 255));
	lyndbeor_armor.itemImageName = "lyndbeor_armor";
	lyndbeor_armor.itemInfoImage;			// ������ UI�̹���
	lyndbeor_armor.itemRect;				// ������ ������ġ
	lyndbeor_armor.itemUIRect;				// ������ UI��ġ
	lyndbeor_armor.itemName = "���������� ����";				// ������ �̸�
	lyndbeor_armor.addAttack;				// �÷��̾� ���ݷ� ����
	lyndbeor_armor.addDefence;				// �÷��̾� ���� ����
	lyndbeor_armor.addMagicDefence;		// �÷��̾� �������� ����
	lyndbeor_armor.addSpeed;			// �÷��̾� �ӵ� ����
	lyndbeor_armor.amount = 1;					// ������ ����
	lyndbeor_armor.weight = 1;					// ������ ����
	lyndbeor_armor.addHP;				// ���� HP ����
	lyndbeor_armor.addMP;					// ���� MP ����
	lyndbeor_armor.price = 98777;					// ������ ����
	vAllItem.push_back(lyndbeor_armor);

	//�ż��� ������ ��Ʈ
	Beltofknowledge.itemKind = ITEM_BELT;					// ������ ����
	Beltofknowledge.itemImage =
		IMAGEMANAGER->addImage("Beltofknowledge", "images/Beltofknowledge.bmp", 50, 50, true, RGB(255, 0, 255));
	Beltofknowledge.itemImageName = "Beltofknowledge";
	Beltofknowledge.itemInfoImage;			// ������ UI�̹���
	Beltofknowledge.itemRect;				// ������ ������ġ
	Beltofknowledge.itemUIRect;				// ������ UI��ġ
	Beltofknowledge.itemName = "�ż��� ������ ��Ʈ";				// ������ �̸�
	Beltofknowledge.addAttack;				// �÷��̾� ���ݷ� ����
	Beltofknowledge.addDefence;				// �÷��̾� ���� ����
	Beltofknowledge.addMagicDefence;		// �÷��̾� �������� ����
	Beltofknowledge.addSpeed;			// �÷��̾� �ӵ� ����
	Beltofknowledge.amount = 1;					// ������ ����
	Beltofknowledge.weight = 1;					// ������ ����
	Beltofknowledge.addHP;				// ���� HP ����
	Beltofknowledge.addMP;					// ���� MP ����
	Beltofknowledge.price = 17888;					// ������ ����
	vAllItem.push_back(Beltofknowledge);

	//������� ����
	blackelder_sandal.itemKind = ITEM_BOOTS;					// ������ ����
	blackelder_sandal.itemImage =
		IMAGEMANAGER->addImage("blackelder_sandal", "images/blackelder_sandal.bmp", 50, 50, true, RGB(255, 0, 255));
	blackelder_sandal.itemImageName = "blackelder_sandal";
	blackelder_sandal.itemInfoImage;			// ������ UI�̹���
	blackelder_sandal.itemRect;				// ������ ������ġ
	blackelder_sandal.itemUIRect;				// ������ UI��ġ
	blackelder_sandal.itemName = "������� ����";				// ������ �̸�
	blackelder_sandal.addAttack;				// �÷��̾� ���ݷ� ����
	blackelder_sandal.addDefence;				// �÷��̾� ���� ����
	blackelder_sandal.addMagicDefence;		// �÷��̾� �������� ����
	blackelder_sandal.addSpeed;			// �÷��̾� �ӵ� ����
	blackelder_sandal.amount = 1;					// ������ ����
	blackelder_sandal.weight = 1;					// ������ ����
	blackelder_sandal.addHP;				// ���� HP ����
	blackelder_sandal.addMP;					// ���� MP ����
	blackelder_sandal.price = 13533;					// ������ ����
	vAllItem.push_back(blackelder_sandal);

	//������ ����1
	Devils_ring1.itemKind = ITEM_RING1;					// ������ ����
	Devils_ring1.itemImage =
		IMAGEMANAGER->addImage("Devils_ring", "images/Devils_ring.bmp", 50, 50, true, RGB(255, 0, 255));
	Devils_ring1.itemImageName = "Devils_ring";
	Devils_ring1.itemInfoImage;			// ������ UI�̹���
	Devils_ring1.itemRect;				// ������ ������ġ
	Devils_ring1.itemUIRect;				// ������ UI��ġ
	Devils_ring1.itemName = "������ ����";				// ������ �̸�
	Devils_ring1.addAttack;				// �÷��̾� ���ݷ� ����
	Devils_ring1.addDefence;				// �÷��̾� ���� ����
	Devils_ring1.addMagicDefence;		// �÷��̾� �������� ����
	Devils_ring1.addSpeed;			// �÷��̾� �ӵ� ����
	Devils_ring1.amount = 1;					// ������ ����
	Devils_ring1.weight = 1;					// ������ ����
	Devils_ring1.addHP;				// ���� HP ����
	Devils_ring1.addMP;					// ���� MP ����
	Devils_ring1.price = 28990;					// ������ ����
	vAllItem.push_back(Devils_ring1);

	//������ ����2
	Devils_ring2.itemKind = ITEM_RING2;					// ������ ����
	Devils_ring2.itemImage =
		IMAGEMANAGER->addImage("Devils_ring", "images/Devils_ring.bmp", 50, 50, true, RGB(255, 0, 255));
	Devils_ring2.itemImageName = "Devils_ring";
	Devils_ring2.itemInfoImage;			// ������ UI�̹���
	Devils_ring2.itemRect;				// ������ ������ġ
	Devils_ring2.itemUIRect;				// ������ UI��ġ
	Devils_ring2.itemName = "������ ����";				// ������ �̸�
	Devils_ring2.addAttack;				// �÷��̾� ���ݷ� ����
	Devils_ring2.addDefence;				// �÷��̾� ���� ����
	Devils_ring2.addMagicDefence;		// �÷��̾� �������� ����
	Devils_ring2.addSpeed;			// �÷��̾� �ӵ� ����
	Devils_ring2.amount = 1;					// ������ ����
	Devils_ring2.weight = 1;					// ������ ����
	Devils_ring2.addHP;				// ���� HP ����
	Devils_ring2.addMP;					// ���� MP ����
	Devils_ring2.price = 28980;					// ������ ����
	vAllItem.push_back(Devils_ring2);

	//������� ����
	MagicDefenseGaiters.itemKind = ITEM_LEGGINGS;					// ������ ����
	MagicDefenseGaiters.itemImage =
		IMAGEMANAGER->addImage("MagicDefenseGaiters", "images/MagicDefenseGaiters.bmp", 50, 50, true, RGB(255, 0, 255));
	MagicDefenseGaiters.itemImageName = "MagicDefenseGaiters";
	MagicDefenseGaiters.itemInfoImage;			// ������ UI�̹���
	MagicDefenseGaiters.itemRect;				// ������ ������ġ
	MagicDefenseGaiters.itemUIRect;				// ������ UI��ġ
	MagicDefenseGaiters.itemName = "������� ����";				// ������ �̸�
	MagicDefenseGaiters.addAttack;				// �÷��̾� ���ݷ� ����
	MagicDefenseGaiters.addDefence;				// �÷��̾� ���� ����
	MagicDefenseGaiters.addMagicDefence;		// �÷��̾� �������� ����
	MagicDefenseGaiters.addSpeed;			// �÷��̾� �ӵ� ����
	MagicDefenseGaiters.amount = 1;					// ������ ����
	MagicDefenseGaiters.weight = 1;					// ������ ����
	MagicDefenseGaiters.addHP;				// ���� HP ����
	MagicDefenseGaiters.addMP;					// ���� MP ����
	MagicDefenseGaiters.price = 16799;					// ������ ����
	vAllItem.push_back(MagicDefenseGaiters);

	//�ż��� ������ �尩
	MagicalGloves.itemKind = ITEM_GLOVES;					// ������ ����
	MagicalGloves.itemImage =
		IMAGEMANAGER->addImage("MagicalGloves", "images/MagicalGloves.bmp", 50, 50, true, RGB(255, 0, 255));
	MagicalGloves.itemImageName = "MagicalGloves";
	MagicalGloves.itemInfoImage;			// ������ UI�̹���
	MagicalGloves.itemRect;				// ������ ������ġ
	MagicalGloves.itemUIRect;				// ������ UI��ġ
	MagicalGloves.itemName = "�ż��� ������ �尩";				// ������ �̸�
	MagicalGloves.addAttack;				// �÷��̾� ���ݷ� ����
	MagicalGloves.addDefence;				// �÷��̾� ���� ����
	MagicalGloves.addMagicDefence;		// �÷��̾� �������� ����
	MagicalGloves.addSpeed;			// �÷��̾� �ӵ� ����
	MagicalGloves.amount = 1;					// ������ ����
	MagicalGloves.weight = 1;					// ������ ����
	MagicalGloves.addHP;				// ���� HP ����
	MagicalGloves.addMP;					// ���� MP ����
	MagicalGloves.price = 13530;					// ������ ����
	vAllItem.push_back(MagicalGloves);

	//�������� �߰�
	ProphetsPauldrons.itemKind = ITEM_PAULDRON;					// ������ ����
	ProphetsPauldrons.itemImage =
		IMAGEMANAGER->addImage("ProphetsPauldrons", "images/ProphetsPauldrons.bmp", 50, 50, true, RGB(255, 0, 255));
	ProphetsPauldrons.itemImageName = "ProphetsPauldrons";
	ProphetsPauldrons.itemInfoImage;			// ������ UI�̹���
	ProphetsPauldrons.itemRect;				// ������ ������ġ
	ProphetsPauldrons.itemUIRect;				// ������ UI��ġ
	ProphetsPauldrons.itemName = "�������� �߰�";				// ������ �̸�
	ProphetsPauldrons.addAttack;				// �÷��̾� ���ݷ� ����
	ProphetsPauldrons.addDefence;				// �÷��̾� ���� ����
	ProphetsPauldrons.addMagicDefence;		// �÷��̾� �������� ����
	ProphetsPauldrons.addSpeed;			// �÷��̾� �ӵ� ����
	ProphetsPauldrons.amount = 1;					// ������ ����
	ProphetsPauldrons.weight = 1;					// ������ ����
	ProphetsPauldrons.addHP;				// ���� HP ����
	ProphetsPauldrons.addMP;					// ���� MP ����
	ProphetsPauldrons.price = 21111;					// ������ ����
	vAllItem.push_back(ProphetsPauldrons);

	//��Ƽ���� ������ �Ͱ���
	Purple_earrings.itemKind = ITEM_EARRING1;					// ������ ����
	Purple_earrings.itemImage =
		IMAGEMANAGER->addImage("Purple_earrings", "images/Purple_earrings.bmp", 50, 50, true, RGB(255, 0, 255));
	Purple_earrings.itemImageName = "Purple_earrings";
	Purple_earrings.itemInfoImage;			// ������ UI�̹���
	Purple_earrings.itemRect;				// ������ ������ġ
	Purple_earrings.itemUIRect;				// ������ UI��ġ
	Purple_earrings.itemName = "��Ƽ���� ������ �Ͱ���";				// ������ �̸�
	Purple_earrings.addAttack;				// �÷��̾� ���ݷ� ����
	Purple_earrings.addDefence;				// �÷��̾� ���� ����
	Purple_earrings.addMagicDefence;		// �÷��̾� �������� ����
	Purple_earrings.addSpeed;			// �÷��̾� �ӵ� ����
	Purple_earrings.amount = 1;					// ������ ����
	Purple_earrings.weight = 1;					// ������ ����
	Purple_earrings.addHP;				// ���� HP ����
	Purple_earrings.addMP;					// ���� MP ����
	Purple_earrings.price = 31990;					// ������ ����
	vAllItem.push_back(Purple_earrings);

	//�Ŵ� ���� ������ ���� ����
	QueenAnts_SilverWings.itemKind = ITEM_CLOAK;					// ������ ����
	QueenAnts_SilverWings.itemImage =
		IMAGEMANAGER->addImage("QueenAnts_SilverWings", "images/QueenAnts_SilverWings.bmp", 50, 50, true, RGB(255, 0, 255));
	QueenAnts_SilverWings.itemImageName = "QueenAnts_SilverWings";
	QueenAnts_SilverWings.itemInfoImage;			// ������ UI�̹���
	QueenAnts_SilverWings.itemRect;				// ������ ������ġ
	QueenAnts_SilverWings.itemUIRect;				// ������ UI��ġ
	QueenAnts_SilverWings.itemName = "�Ŵ� ���� ������ ���� ����";				// ������ �̸�
	QueenAnts_SilverWings.addAttack;				// �÷��̾� ���ݷ� ����
	QueenAnts_SilverWings.addDefence = 2;				// �÷��̾� ���� ����
	QueenAnts_SilverWings.addMagicDefence;		// �÷��̾� �������� ����
	QueenAnts_SilverWings.addSpeed;			// �÷��̾� �ӵ� ����
	QueenAnts_SilverWings.amount = 1;					// ������ ����
	QueenAnts_SilverWings.weight = 1;					// ������ ����
	QueenAnts_SilverWings.addHP;				// ���� HP ����
	QueenAnts_SilverWings.addMP;					// ���� MP ����
	QueenAnts_SilverWings.price = 31310;					// ������ ����
	vAllItem.push_back(QueenAnts_SilverWings);

	//��Ƽ���� ������ �Ͱ���
	Red_earrings.itemKind = ITEM_EARRING2;					// ������ ����
	Red_earrings.itemImage =
		IMAGEMANAGER->addImage("Red_earrings", "images/Red_earrings.bmp", 50, 50, true, RGB(255, 0, 255));
	Red_earrings.itemImageName = "Red_earrings";
	Red_earrings.itemInfoImage;			// ������ UI�̹���
	Red_earrings.itemRect;				// ������ ������ġ
	Red_earrings.itemUIRect;				// ������ UI��ġ
	Red_earrings.itemName = "��Ƽ���� ������ �Ͱ���";				// ������ �̸�
	Red_earrings.addAttack;				// �÷��̾� ���ݷ� ����
	Red_earrings.addDefence;				// �÷��̾� ���� ����
	Red_earrings.addMagicDefence;		// �÷��̾� �������� ����
	Red_earrings.addSpeed;			// �÷��̾� �ӵ� ����
	Red_earrings.amount = 1;					// ������ ����
	Red_earrings.weight = 1;					// ������ ����
	Red_earrings.addHP;				// ���� HP ����
	Red_earrings.addMP;					// ���� MP ����
	Red_earrings.price = 19890;					// ������ ����
	vAllItem.push_back(Red_earrings);

	//�������� ���� ����1
	Ringofwisdom1.itemKind = ITEM_RING3;					// ������ ����
	Ringofwisdom1.itemImage =
		IMAGEMANAGER->addImage("Ringofwisdom", "images/Ringofwisdom.bmp", 50, 50, true, RGB(255, 0, 255));
	Ringofwisdom1.itemImageName = "Ringofwisdom";
	Ringofwisdom1.itemInfoImage;			// ������ UI�̹���
	Ringofwisdom1.itemRect;				// ������ ������ġ
	Ringofwisdom1.itemUIRect;				// ������ UI��ġ
	Ringofwisdom1.itemName = "�������� ���� ����";				// ������ �̸�
	Ringofwisdom1.addAttack;				// �÷��̾� ���ݷ� ����
	Ringofwisdom1.addDefence;				// �÷��̾� ���� ����
	Ringofwisdom1.addMagicDefence;		// �÷��̾� �������� ����
	Ringofwisdom1.addSpeed;			// �÷��̾� �ӵ� ����
	Ringofwisdom1.amount = 1;					// ������ ����
	Ringofwisdom1.weight = 1;					// ������ ����
	Ringofwisdom1.addHP;				// ���� HP ����
	Ringofwisdom1.addMP;					// ���� MP ����
	Ringofwisdom1.price = 21290;					// ������ ����
	vAllItem.push_back(Ringofwisdom1);

	//�������� ���� ����2
	Ringofwisdom2.itemKind = ITEM_RING4;					// ������ ����
	Ringofwisdom2.itemImage =
		IMAGEMANAGER->addImage("Ringofwisdom", "images/Ringofwisdom.bmp", 50, 50, true, RGB(255, 0, 255));
	Ringofwisdom2.itemImageName = "Ringofwisdom";
	Ringofwisdom2.itemInfoImage;			// ������ UI�̹���
	Ringofwisdom2.itemRect;				// ������ ������ġ
	Ringofwisdom2.itemUIRect;				// ������ UI��ġ
	Ringofwisdom2.itemName = "�������� ���� ����";				// ������ �̸�
	Ringofwisdom2.addAttack;				// �÷��̾� ���ݷ� ����
	Ringofwisdom2.addDefence;				// �÷��̾� ���� ����
	Ringofwisdom2.addMagicDefence;		// �÷��̾� �������� ����
	Ringofwisdom2.addSpeed;			// �÷��̾� �ӵ� ����
	Ringofwisdom2.amount = 1;					// ������ ����
	Ringofwisdom2.weight = 1;					// ������ ����
	Ringofwisdom2.addHP;				// ���� HP ����
	Ringofwisdom2.addMP;					// ���� MP ����
	Ringofwisdom2.price = 21290;					// ������ ����
	vAllItem.push_back(Ringofwisdom2);

	//�þ��� �ɾ�
	Seers_Eye.itemKind = ITEM_SHIELD;					// ������ ����
	Seers_Eye.itemImage =
		IMAGEMANAGER->addImage("Seers_Eye", "images/Seers_Eye.bmp", 50, 50, true, RGB(255, 0, 255));
	Seers_Eye.itemImageName = "Seers_Eye";
	Seers_Eye.itemInfoImage;			// ������ UI�̹���
	Seers_Eye.itemRect;				// ������ ������ġ
	Seers_Eye.itemUIRect;				// ������ UI��ġ
	Seers_Eye.itemName = "�þ��� �ɾ�";				// ������ �̸�
	Seers_Eye.addAttack;				// �÷��̾� ���ݷ� ����
	Seers_Eye.addDefence = 3;				// �÷��̾� ���� ����
	Seers_Eye.addMagicDefence;		// �÷��̾� �������� ����
	Seers_Eye.addSpeed;			// �÷��̾� �ӵ� ����
	Seers_Eye.amount = 1;					// ������ ����
	Seers_Eye.weight = 1;					// ������ ����
	Seers_Eye.addHP;				// ���� HP ����
	Seers_Eye.addMP;					// ���� MP ����
	Seers_Eye.price = 18580;					// ������ ����
	vAllItem.push_back(Seers_Eye);

	//������ �����
	Sages_Necklace.itemKind = ITEM_NECKLACE;					// ������ ����
	Sages_Necklace.itemImage =
		IMAGEMANAGER->addImage("Sages_Necklace", "images/Sages_Necklace.bmp", 50, 50, true, RGB(255, 0, 255));
	Sages_Necklace.itemImageName = "Sages_Necklace";
	Sages_Necklace.itemInfoImage;			// ������ UI�̹���
	Sages_Necklace.itemRect;				// ������ ������ġ
	Sages_Necklace.itemUIRect;				// ������ UI��ġ
	Sages_Necklace.itemName = "������ �����";				// ������ �̸�
	Sages_Necklace.addAttack;				// �÷��̾� ���ݷ� ����
	Sages_Necklace.addDefence = 1;				// �÷��̾� ���� ����
	Sages_Necklace.addMagicDefence;		// �÷��̾� �������� ����
	Sages_Necklace.addSpeed;			// �÷��̾� �ӵ� ����
	Sages_Necklace.amount = 1;					// ������ ����
	Sages_Necklace.weight = 1;					// ������ ����
	Sages_Necklace.addHP;				// ���� HP ����
	Sages_Necklace.addMP;					// ���� MP ����
	Sages_Necklace.price = 21550;					// ������ ����
	vAllItem.push_back(Sages_Necklace);


	//�븶������ ����
	Wizards_hat.itemKind = ITEM_HELMET;					// ������ ����
	Wizards_hat.itemImage =
		IMAGEMANAGER->addImage("Wizards_hat", "images/Wizards_hat.bmp", 50, 50, true, RGB(255, 0, 255));
	Wizards_hat.itemImageName = "Wizards_hat";
	Wizards_hat.itemInfoImage;			// ������ UI�̹���
	Wizards_hat.itemRect;				// ������ ������ġ
	Wizards_hat.itemUIRect;				// ������ UI��ġ
	Wizards_hat.itemName = "�븶������ ����";				// ������ �̸�
	Wizards_hat.addAttack;				// �÷��̾� ���ݷ� ����
	Wizards_hat.addDefence = 3;				// �÷��̾� ���� ����
	Wizards_hat.addMagicDefence;		// �÷��̾� �������� ����
	Wizards_hat.addSpeed;			// �÷��̾� �ӵ� ����
	Wizards_hat.amount = 1;					// ������ ����
	Wizards_hat.weight = 1;					// ������ ����
	Wizards_hat.addHP;				// ���� HP ����
	Wizards_hat.addMP;					// ���� MP ����
	Wizards_hat.price = 11550;					// ������ ����
	vAllItem.push_back(Wizards_hat);


	//Ƽ����
	Tshirts.itemKind = ITEM_TSHIRTS;					// ������ ����
	Tshirts.itemImage =
		IMAGEMANAGER->addImage("Tshirts", "images/Tshirts.bmp", 50, 50, true, RGB(255, 0, 255));
	Tshirts.itemImageName = "Tshirts";
	Tshirts.itemInfoImage;			// ������ UI�̹���
	Tshirts.itemRect;				// ������ ������ġ
	Tshirts.itemUIRect;				// ������ UI��ġ
	Tshirts.itemName = "Ƽ����";				// ������ �̸�
	Tshirts.addAttack;				// �÷��̾� ���ݷ� ����
	Tshirts.addDefence = 3;				// �÷��̾� ���� ����
	Tshirts.addMagicDefence;		// �÷��̾� �������� ����
	Tshirts.addSpeed;			// �÷��̾� �ӵ� ����
	Tshirts.amount = 1;					// ������ ����
	Tshirts.weight = 1;					// ������ ����
	Tshirts.addHP;				// ���� HP ����
	Tshirts.addMP;					// ���� MP ����
	Tshirts.price = 16530;					// ������ ����
	vAllItem.push_back(Tshirts);

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
}

void itemManager::render()
{
}
