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
	//빈칸
	temp.itemKind = ITEM_NULL;				// 아이템 종류
	temp.itemImage = NULL;
	temp.itemImageName = NULL;
	temp.itemInfoImage = NULL;			// 아이템 UI이미지
	temp.itemRect;				// 아이템 생성위치
	temp.itemUIRect;			// 아이템 UI위치
	temp.itemName = NULL;				// 아이템 이름
	temp.addAttack;				// 플레이어 공격력 증감
	temp.addDefence;			// 플레이어 방어력 증감
	temp.addMagicDefence;		// 플레이어 마법방어력 증감
	temp.addSpeed;				// 플레이어 속도 증감
	temp.amount;				// 아이템 수량
	temp.weight;				// 아이템 무게
	temp.addHP;			// 현재 HP 증감
	temp.addMP;					// 현재 MP 증감
	temp.price;					// 아이템 가격
	vAllItem.push_back(temp);

	//물약
	//농축 체력 회복제
	small_red_potion.itemKind = ITEM_POTION;				// 아이템 종류
	small_red_potion.itemImage =
		IMAGEMANAGER->addImage("small_red_potion", "images/small_red_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	small_red_potion.itemImageName = "small_red_potion";
	small_red_potion.itemInfoImage;			// 아이템 UI이미지
	small_red_potion.itemRect;				// 아이템 생성위치
	small_red_potion.itemUIRect;			// 아이템 UI위치
	small_red_potion.itemName = "농축 체력 회복제";				// 아이템 이름
	small_red_potion.addAttack;				// 플레이어 공격력 증감
	small_red_potion.addDefence;			// 플레이어 방어력 증감
	small_red_potion.addMagicDefence;		// 플레이어 마법방어력 증감
	small_red_potion.addSpeed;				// 플레이어 속도 증감
	small_red_potion.amount = 1;				// 아이템 수량
	small_red_potion.weight = 1;				// 아이템 무게
	small_red_potion.addHP = 20;			// 현재 HP 증감
	small_red_potion.addMP;					// 현재 MP 증감
	small_red_potion.price = 117;					// 아이템 가격
	vAllItem.push_back(small_red_potion);
	//농축 강력 체력 회복제
	small_white_potion.itemKind = ITEM_POTION;				// 아이템 종류
	small_white_potion.itemImage =
		IMAGEMANAGER->addImage("small_white_potion", "images/small_white_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	small_white_potion.itemImageName = "small_white_potion";
	small_white_potion.itemInfoImage;			// 아이템 UI이미지
	small_white_potion.itemRect;				// 아이템 생성위치
	small_white_potion.itemUIRect;				// 아이템 UI위치
	small_white_potion.itemName = "농축 강력 체력 회복제";				// 아이템 이름
	small_white_potion.addAttack;				// 플레이어 공격력 증감
	small_white_potion.addDefence;				// 플레이어 방어력 증감
	small_white_potion.addMagicDefence;		// 플레이어 마법방어력 증감
	small_white_potion.addSpeed;			// 플레이어 속도 증감
	small_white_potion.amount = 1;					// 아이템 수량
	small_white_potion.weight = 2;					// 아이템 무게
	small_white_potion.addHP = 50;				// 현재 HP 증감
	small_white_potion.addMP;					// 현재 MP 증감
	small_white_potion.price = 521;					// 아이템 가격
	vAllItem.push_back(small_white_potion);
	//농축 속도의 물약
	big_green_potion.itemKind = ITEM_POTION;				// 아이템 종류
	big_green_potion.itemImage =
		IMAGEMANAGER->addImage("big_green_potion", "images/big_green_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	big_green_potion.itemImageName = "big_green_potion";
	big_green_potion.itemInfoImage;			// 아이템 UI이미지
	big_green_potion.itemRect;				// 아이템 생성위치
	big_green_potion.itemUIRect;				// 아이템 UI위치
	big_green_potion.itemName = "농축 속도의 물약";				// 아이템 이름
	big_green_potion.addAttack;				// 플레이어 공격력 증감
	big_green_potion.addDefence;				// 플레이어 방어력 증감
	big_green_potion.addMagicDefence;		// 플레이어 마법방어력 증감
	big_green_potion.addSpeed = 1;				// 플레이어 속도 증감
	big_green_potion.amount = 1;					// 아이템 수량
	big_green_potion.weight = 5;					// 아이템 무게
	big_green_potion.addHP;				// 현재 HP 증감
	big_green_potion.addMP;					// 현재 MP 증감
	big_green_potion.price = 1329;					// 아이템 가격
	vAllItem.push_back(big_green_potion);
	//신속 체력 회복제
	big_red_potion.itemKind = ITEM_POTION;				// 아이템 종류
	big_red_potion.itemImage = 
		IMAGEMANAGER->addImage("big_red_potion", "images/big_red_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	big_red_potion.itemImageName = "big_red_potion";
	big_red_potion.itemInfoImage;			// 아이템 UI이미지
	big_red_potion.itemRect;				// 아이템 생성위치
	big_red_potion.itemUIRect;				// 아이템 UI위치
	big_red_potion.itemName = "신속 체력 회복제";				// 아이템 이름
	big_red_potion.addAttack;				// 플레이어 공격력 증감
	big_red_potion.addDefence;				// 플레이어 방어력 증감
	big_red_potion.addMagicDefence;		// 플레이어 마법방어력 증감
	big_red_potion.addSpeed;			// 플레이어 속도 증감
	big_red_potion.amount = 1;					// 아이템 수량
	big_red_potion.weight = 2;					// 아이템 무게
	big_red_potion.addHP = 25;				// 현재 HP 증감
	big_red_potion.addMP;					// 현재 MP 증감
	big_red_potion.price = 177;					// 아이템 가격
	vAllItem.push_back(big_red_potion);
	//신속 강력 체력 회복제
	big_white_potion.itemKind = ITEM_POTION;				// 아이템 종류
	big_white_potion.itemImage = 
		IMAGEMANAGER->addImage("big_white_potion", "images/big_white_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	big_white_potion.itemImageName = "big_white_potion";
	big_white_potion.itemInfoImage;			// 아이템 UI이미지
	big_white_potion.itemRect;				// 아이템 생성위치
	big_white_potion.itemUIRect;				// 아이템 UI위치
	big_white_potion.itemName = "신속 강력 체력 회복제";				// 아이템 이름
	big_white_potion.addAttack;				// 플레이어 공격력 증감
	big_white_potion.addDefence;				// 플레이어 방어력 증감
	big_white_potion.addMagicDefence;		// 플레이어 마법방어력 증감
	big_white_potion.addSpeed;			// 플레이어 속도 증감
	big_white_potion.amount = 1;					// 아이템 수량
	big_white_potion.weight = 4;					// 아이템 무게
	big_white_potion.addHP = 70;				// 현재 HP 증감
	big_white_potion.addMP;					// 현재 MP 증감
	big_white_potion.price = 782;					// 아이템 가격
	vAllItem.push_back(big_white_potion);
	//농축 마력의 물약
	blue_potion.itemKind = ITEM_POTION;				// 아이템 종류
	blue_potion.itemImage =
		IMAGEMANAGER->addImage("blue_potion", "images/blue_potion.bmp", 50, 50, true, RGB(255, 0, 255));
	blue_potion.itemImageName = "blue_potion";
	blue_potion.itemInfoImage;			// 아이템 UI이미지
	blue_potion.itemRect;				// 아이템 생성위치
	blue_potion.itemUIRect;				// 아이템 UI위치
	blue_potion.itemName = "농축 마력의 물약";				// 아이템 이름
	blue_potion.addAttack;				// 플레이어 공격력 증감
	blue_potion.addDefence;				// 플레이어 방어력 증감
	blue_potion.addMagicDefence;		// 플레이어 마법방어력 증감
	blue_potion.addSpeed;			// 플레이어 속도 증감
	blue_potion.amount = 1;					// 아이템 수량
	blue_potion.weight = 5;					// 아이템 무게
	blue_potion.addHP;				// 현재 HP 증감
	blue_potion.addMP = 100;					// 현재 MP 증감
	blue_potion.price = 1980;					// 아이템 가격
	vAllItem.push_back(blue_potion);

	//주문서
	//순간이동 주문서
	teleport_order.itemKind = ITEM_MAGIC_ORDER;				// 아이템 종류
	teleport_order.itemImage =
		IMAGEMANAGER->addImage("teleport_order", "images/teleport_order.bmp", 50, 50, true, RGB(255, 0, 255));
	teleport_order.itemImageName = "teleport_order";
	teleport_order.itemInfoImage;			// 아이템 UI이미지
	teleport_order.itemRect;				// 아이템 생성위치
	teleport_order.itemUIRect;				// 아이템 UI위치
	teleport_order.itemName = "순간이동 주문서";				// 아이템 이름
	teleport_order.addAttack;				// 플레이어 공격력 증감
	teleport_order.addDefence;				// 플레이어 방어력 증감
	teleport_order.addMagicDefence;		// 플레이어 마법방어력 증감
	teleport_order.addSpeed;			// 플레이어 속도 증감
	teleport_order.amount = 1;					// 아이템 수량
	teleport_order.weight = 1;					// 아이템 무게
	teleport_order.addHP;				// 현재 HP 증감
	teleport_order.addMP;					// 현재 MP 증감
	teleport_order.price = 157;					// 아이템 가격
	vAllItem.push_back(teleport_order);
	//확인 주문서
	identify_order.itemKind = ITEM_MAGIC_ORDER;					// 아이템 종류
	identify_order.itemImage =
		IMAGEMANAGER->addImage("identify_order", "images/identify_order.bmp", 50, 50, true, RGB(255, 0, 255));
	identify_order.itemImageName = "identify_order";
	identify_order.itemInfoImage;			// 아이템 UI이미지
	identify_order.itemRect;				// 아이템 생성위치
	identify_order.itemUIRect;				// 아이템 UI위치
	identify_order.itemName = "확인 주문서";				// 아이템 이름
	identify_order.addAttack;				// 플레이어 공격력 증감
	identify_order.addDefence;				// 플레이어 방어력 증감
	identify_order.addMagicDefence;		// 플레이어 마법방어력 증감
	identify_order.addSpeed;			// 플레이어 속도 증감
	identify_order.amount = 1;					// 아이템 수량
	identify_order.weight = 1;					// 아이템 무게
	identify_order.addHP;				// 현재 HP 증감
	identify_order.addMP;					// 현재 MP 증감
	identify_order.price = 133;					// 아이템 가격
	vAllItem.push_back(identify_order);
	//귀환 주문서
	return_order.itemKind = ITEM_MAGIC_ORDER;					// 아이템 종류
	return_order.itemImage =
		IMAGEMANAGER->addImage("return_order", "images/return_order.bmp", 50, 50, true, RGB(255, 0, 255));
	return_order.itemImageName = "return_order";
	return_order.itemInfoImage;			// 아이템 UI이미지
	return_order.itemRect;				// 아이템 생성위치
	return_order.itemUIRect;				// 아이템 UI위치
	return_order.itemName = "확인 주문서";				// 아이템 이름
	return_order.addAttack;				// 플레이어 공격력 증감
	return_order.addDefence;				// 플레이어 방어력 증감
	return_order.addMagicDefence;		// 플레이어 마법방어력 증감
	return_order.addSpeed;			// 플레이어 속도 증감
	return_order.amount = 1;					// 아이템 수량
	return_order.weight = 1;					// 아이템 무게
	return_order.addHP;				// 현재 HP 증감
	return_order.addMP;					// 현재 MP 증감
	return_order.price = 133;					// 아이템 가격
	vAllItem.push_back(return_order);
	//변신 주문서
	transform_order.itemKind = ITEM_MAGIC_ORDER;					// 아이템 종류
	transform_order.itemImage =
		IMAGEMANAGER->addImage("transform_order", "images/transform_order.bmp", 50, 50, true, RGB(255, 0, 255));
	transform_order.itemImageName = "transform_order";
	transform_order.itemInfoImage;			// 아이템 UI이미지
	transform_order.itemRect;				// 아이템 생성위치
	transform_order.itemUIRect;				// 아이템 UI위치
	transform_order.itemName = "변신 주문서";				// 아이템 이름
	transform_order.addAttack;				// 플레이어 공격력 증감
	transform_order.addDefence;				// 플레이어 방어력 증감
	transform_order.addMagicDefence;		// 플레이어 마법방어력 증감
	transform_order.addSpeed;			// 플레이어 속도 증감
	transform_order.amount = 1;					// 아이템 수량
	transform_order.weight = 1;					// 아이템 무게
	transform_order.addHP;				// 현재 HP 증감
	transform_order.addMP;					// 현재 MP 증감
	transform_order.price = 133;					// 아이템 가격
	vAllItem.push_back(transform_order);

	//수정결정체 지팡이
	cristal_staff.itemKind = ITEM_WEAPON;					// 아이템 종류
	cristal_staff.itemImage =
		IMAGEMANAGER->addImage("cristal_staff", "images/cristal_staff.bmp", 50, 50, true, RGB(255, 0, 255));
	cristal_staff.itemImageName = "cristal_staff";
	cristal_staff.itemInfoImage;			// 아이템 UI이미지
	cristal_staff.itemRect;				// 아이템 생성위치
	cristal_staff.itemUIRect;				// 아이템 UI위치
	cristal_staff.itemName = "수정결정체 지팡이";				// 아이템 이름
	cristal_staff.addAttack = 15;				// 플레이어 공격력 증감
	cristal_staff.addSpell = 15;				// 플레이어 스펠 증감
	cristal_staff.addDefence;				// 플레이어 방어력 증감
	cristal_staff.addMagicDefence;		// 플레이어 마법방어력 증감
	cristal_staff.addSpeed;			// 플레이어 속도 증감
	cristal_staff.amount = 1;					// 아이템 수량
	cristal_staff.weight = 60;					// 아이템 무게
	cristal_staff.addHP;				// 현재 HP 증감
	cristal_staff.addMP;					// 현재 MP 증감
	cristal_staff.price = 188990;					// 아이템 가격
	vAllItem.push_back(cristal_staff);

	//린드비오르의 마력
	lyndbeor_armor.itemKind = ITEM_ARMOR;					// 아이템 종류
	lyndbeor_armor.itemImage =
		IMAGEMANAGER->addImage("lyndbeor_armor", "images/lyndbeor_armor.bmp", 50, 50, true, RGB(255, 0, 255));
	lyndbeor_armor.itemImageName = "lyndbeor_armor";
	lyndbeor_armor.itemInfoImage;			// 아이템 UI이미지
	lyndbeor_armor.itemRect;				// 아이템 생성위치
	lyndbeor_armor.itemUIRect;				// 아이템 UI위치
	lyndbeor_armor.itemName = "린드비오르의 마력";				// 아이템 이름
	lyndbeor_armor.addAttack;				// 플레이어 공격력 증감
	lyndbeor_armor.addDefence;				// 플레이어 방어력 증감
	lyndbeor_armor.addMagicDefence;		// 플레이어 마법방어력 증감
	lyndbeor_armor.addSpeed;			// 플레이어 속도 증감
	lyndbeor_armor.amount = 1;					// 아이템 수량
	lyndbeor_armor.weight = 1;					// 아이템 무게
	lyndbeor_armor.addHP;				// 현재 HP 증감
	lyndbeor_armor.addMP;					// 현재 MP 증감
	lyndbeor_armor.price = 98777;					// 아이템 가격
	vAllItem.push_back(lyndbeor_armor);

	//신성한 지식의 벨트
	Beltofknowledge.itemKind = ITEM_BELT;					// 아이템 종류
	Beltofknowledge.itemImage =
		IMAGEMANAGER->addImage("Beltofknowledge", "images/Beltofknowledge.bmp", 50, 50, true, RGB(255, 0, 255));
	Beltofknowledge.itemImageName = "Beltofknowledge";
	Beltofknowledge.itemInfoImage;			// 아이템 UI이미지
	Beltofknowledge.itemRect;				// 아이템 생성위치
	Beltofknowledge.itemUIRect;				// 아이템 UI위치
	Beltofknowledge.itemName = "신성한 지식의 벨트";				// 아이템 이름
	Beltofknowledge.addAttack;				// 플레이어 공격력 증감
	Beltofknowledge.addDefence;				// 플레이어 방어력 증감
	Beltofknowledge.addMagicDefence;		// 플레이어 마법방어력 증감
	Beltofknowledge.addSpeed;			// 플레이어 속도 증감
	Beltofknowledge.amount = 1;					// 아이템 수량
	Beltofknowledge.weight = 1;					// 아이템 무게
	Beltofknowledge.addHP;				// 현재 HP 증감
	Beltofknowledge.addMP;					// 현재 MP 증감
	Beltofknowledge.price = 17888;					// 아이템 가격
	vAllItem.push_back(Beltofknowledge);

	//흑장로의 샌달
	blackelder_sandal.itemKind = ITEM_BOOTS;					// 아이템 종류
	blackelder_sandal.itemImage =
		IMAGEMANAGER->addImage("blackelder_sandal", "images/blackelder_sandal.bmp", 50, 50, true, RGB(255, 0, 255));
	blackelder_sandal.itemImageName = "blackelder_sandal";
	blackelder_sandal.itemInfoImage;			// 아이템 UI이미지
	blackelder_sandal.itemRect;				// 아이템 생성위치
	blackelder_sandal.itemUIRect;				// 아이템 UI위치
	blackelder_sandal.itemName = "흑장로의 샌달";				// 아이템 이름
	blackelder_sandal.addAttack;				// 플레이어 공격력 증감
	blackelder_sandal.addDefence;				// 플레이어 방어력 증감
	blackelder_sandal.addMagicDefence;		// 플레이어 마법방어력 증감
	blackelder_sandal.addSpeed;			// 플레이어 속도 증감
	blackelder_sandal.amount = 1;					// 아이템 수량
	blackelder_sandal.weight = 1;					// 아이템 무게
	blackelder_sandal.addHP;				// 현재 HP 증감
	blackelder_sandal.addMP;					// 현재 MP 증감
	blackelder_sandal.price = 13533;					// 아이템 가격
	vAllItem.push_back(blackelder_sandal);

	//마왕의 반지1
	Devils_ring1.itemKind = ITEM_RING1;					// 아이템 종류
	Devils_ring1.itemImage =
		IMAGEMANAGER->addImage("Devils_ring", "images/Devils_ring.bmp", 50, 50, true, RGB(255, 0, 255));
	Devils_ring1.itemImageName = "Devils_ring";
	Devils_ring1.itemInfoImage;			// 아이템 UI이미지
	Devils_ring1.itemRect;				// 아이템 생성위치
	Devils_ring1.itemUIRect;				// 아이템 UI위치
	Devils_ring1.itemName = "마왕의 반지";				// 아이템 이름
	Devils_ring1.addAttack;				// 플레이어 공격력 증감
	Devils_ring1.addDefence;				// 플레이어 방어력 증감
	Devils_ring1.addMagicDefence;		// 플레이어 마법방어력 증감
	Devils_ring1.addSpeed;			// 플레이어 속도 증감
	Devils_ring1.amount = 1;					// 아이템 수량
	Devils_ring1.weight = 1;					// 아이템 무게
	Devils_ring1.addHP;				// 현재 HP 증감
	Devils_ring1.addMP;					// 현재 MP 증감
	Devils_ring1.price = 28990;					// 아이템 가격
	vAllItem.push_back(Devils_ring1);

	//마왕의 반지2
	Devils_ring2.itemKind = ITEM_RING2;					// 아이템 종류
	Devils_ring2.itemImage =
		IMAGEMANAGER->addImage("Devils_ring", "images/Devils_ring.bmp", 50, 50, true, RGB(255, 0, 255));
	Devils_ring2.itemImageName = "Devils_ring";
	Devils_ring2.itemInfoImage;			// 아이템 UI이미지
	Devils_ring2.itemRect;				// 아이템 생성위치
	Devils_ring2.itemUIRect;				// 아이템 UI위치
	Devils_ring2.itemName = "마왕의 반지";				// 아이템 이름
	Devils_ring2.addAttack;				// 플레이어 공격력 증감
	Devils_ring2.addDefence;				// 플레이어 방어력 증감
	Devils_ring2.addMagicDefence;		// 플레이어 마법방어력 증감
	Devils_ring2.addSpeed;			// 플레이어 속도 증감
	Devils_ring2.amount = 1;					// 아이템 수량
	Devils_ring2.weight = 1;					// 아이템 무게
	Devils_ring2.addHP;				// 현재 HP 증감
	Devils_ring2.addMP;					// 현재 MP 증감
	Devils_ring2.price = 28980;					// 아이템 가격
	vAllItem.push_back(Devils_ring2);

	//마법방어 각반
	MagicDefenseGaiters.itemKind = ITEM_LEGGINGS;					// 아이템 종류
	MagicDefenseGaiters.itemImage =
		IMAGEMANAGER->addImage("MagicDefenseGaiters", "images/MagicDefenseGaiters.bmp", 50, 50, true, RGB(255, 0, 255));
	MagicDefenseGaiters.itemImageName = "MagicDefenseGaiters";
	MagicDefenseGaiters.itemInfoImage;			// 아이템 UI이미지
	MagicDefenseGaiters.itemRect;				// 아이템 생성위치
	MagicDefenseGaiters.itemUIRect;				// 아이템 UI위치
	MagicDefenseGaiters.itemName = "마법방어 각반";				// 아이템 이름
	MagicDefenseGaiters.addAttack;				// 플레이어 공격력 증감
	MagicDefenseGaiters.addDefence;				// 플레이어 방어력 증감
	MagicDefenseGaiters.addMagicDefence;		// 플레이어 마법방어력 증감
	MagicDefenseGaiters.addSpeed;			// 플레이어 속도 증감
	MagicDefenseGaiters.amount = 1;					// 아이템 수량
	MagicDefenseGaiters.weight = 1;					// 아이템 무게
	MagicDefenseGaiters.addHP;				// 현재 HP 증감
	MagicDefenseGaiters.addMP;					// 현재 MP 증감
	MagicDefenseGaiters.price = 16799;					// 아이템 가격
	vAllItem.push_back(MagicDefenseGaiters);

	//신성한 마력의 장갑
	MagicalGloves.itemKind = ITEM_GLOVES;					// 아이템 종류
	MagicalGloves.itemImage =
		IMAGEMANAGER->addImage("MagicalGloves", "images/MagicalGloves.bmp", 50, 50, true, RGB(255, 0, 255));
	MagicalGloves.itemImageName = "MagicalGloves";
	MagicalGloves.itemInfoImage;			// 아이템 UI이미지
	MagicalGloves.itemRect;				// 아이템 생성위치
	MagicalGloves.itemUIRect;				// 아이템 UI위치
	MagicalGloves.itemName = "신성한 마력의 장갑";				// 아이템 이름
	MagicalGloves.addAttack;				// 플레이어 공격력 증감
	MagicalGloves.addDefence;				// 플레이어 방어력 증감
	MagicalGloves.addMagicDefence;		// 플레이어 마법방어력 증감
	MagicalGloves.addSpeed;			// 플레이어 속도 증감
	MagicalGloves.amount = 1;					// 아이템 수량
	MagicalGloves.weight = 1;					// 아이템 무게
	MagicalGloves.addHP;				// 현재 HP 증감
	MagicalGloves.addMP;					// 현재 MP 증감
	MagicalGloves.price = 13530;					// 아이템 가격
	vAllItem.push_back(MagicalGloves);

	//예언자의 견갑
	ProphetsPauldrons.itemKind = ITEM_PAULDRON;					// 아이템 종류
	ProphetsPauldrons.itemImage =
		IMAGEMANAGER->addImage("ProphetsPauldrons", "images/ProphetsPauldrons.bmp", 50, 50, true, RGB(255, 0, 255));
	ProphetsPauldrons.itemImageName = "ProphetsPauldrons";
	ProphetsPauldrons.itemInfoImage;			// 아이템 UI이미지
	ProphetsPauldrons.itemRect;				// 아이템 생성위치
	ProphetsPauldrons.itemUIRect;				// 아이템 UI위치
	ProphetsPauldrons.itemName = "예언자의 견갑";				// 아이템 이름
	ProphetsPauldrons.addAttack;				// 플레이어 공격력 증감
	ProphetsPauldrons.addDefence;				// 플레이어 방어력 증감
	ProphetsPauldrons.addMagicDefence;		// 플레이어 마법방어력 증감
	ProphetsPauldrons.addSpeed;			// 플레이어 속도 증감
	ProphetsPauldrons.amount = 1;					// 아이템 수량
	ProphetsPauldrons.weight = 1;					// 아이템 무게
	ProphetsPauldrons.addHP;				// 현재 HP 증감
	ProphetsPauldrons.addMP;					// 현재 MP 증감
	ProphetsPauldrons.price = 21111;					// 아이템 가격
	vAllItem.push_back(ProphetsPauldrons);

	//룸티스의 보랏빛 귀걸이
	Purple_earrings.itemKind = ITEM_EARRING1;					// 아이템 종류
	Purple_earrings.itemImage =
		IMAGEMANAGER->addImage("Purple_earrings", "images/Purple_earrings.bmp", 50, 50, true, RGB(255, 0, 255));
	Purple_earrings.itemImageName = "Purple_earrings";
	Purple_earrings.itemInfoImage;			// 아이템 UI이미지
	Purple_earrings.itemRect;				// 아이템 생성위치
	Purple_earrings.itemUIRect;				// 아이템 UI위치
	Purple_earrings.itemName = "룸티스의 보랏빛 귀걸이";				// 아이템 이름
	Purple_earrings.addAttack;				// 플레이어 공격력 증감
	Purple_earrings.addDefence;				// 플레이어 방어력 증감
	Purple_earrings.addMagicDefence;		// 플레이어 마법방어력 증감
	Purple_earrings.addSpeed;			// 플레이어 속도 증감
	Purple_earrings.amount = 1;					// 아이템 수량
	Purple_earrings.weight = 1;					// 아이템 무게
	Purple_earrings.addHP;				// 현재 HP 증감
	Purple_earrings.addMP;					// 현재 MP 증감
	Purple_earrings.price = 31990;					// 아이템 가격
	vAllItem.push_back(Purple_earrings);

	//거대 여왕 개미의 은빛 날개
	QueenAnts_SilverWings.itemKind = ITEM_CLOAK;					// 아이템 종류
	QueenAnts_SilverWings.itemImage =
		IMAGEMANAGER->addImage("QueenAnts_SilverWings", "images/QueenAnts_SilverWings.bmp", 50, 50, true, RGB(255, 0, 255));
	QueenAnts_SilverWings.itemImageName = "QueenAnts_SilverWings";
	QueenAnts_SilverWings.itemInfoImage;			// 아이템 UI이미지
	QueenAnts_SilverWings.itemRect;				// 아이템 생성위치
	QueenAnts_SilverWings.itemUIRect;				// 아이템 UI위치
	QueenAnts_SilverWings.itemName = "거대 여왕 개미의 은빛 날개";				// 아이템 이름
	QueenAnts_SilverWings.addAttack;				// 플레이어 공격력 증감
	QueenAnts_SilverWings.addDefence = 2;				// 플레이어 방어력 증감
	QueenAnts_SilverWings.addMagicDefence;		// 플레이어 마법방어력 증감
	QueenAnts_SilverWings.addSpeed;			// 플레이어 속도 증감
	QueenAnts_SilverWings.amount = 1;					// 아이템 수량
	QueenAnts_SilverWings.weight = 1;					// 아이템 무게
	QueenAnts_SilverWings.addHP;				// 현재 HP 증감
	QueenAnts_SilverWings.addMP;					// 현재 MP 증감
	QueenAnts_SilverWings.price = 31310;					// 아이템 가격
	vAllItem.push_back(QueenAnts_SilverWings);

	//룸티스의 붉은빛 귀걸이
	Red_earrings.itemKind = ITEM_EARRING2;					// 아이템 종류
	Red_earrings.itemImage =
		IMAGEMANAGER->addImage("Red_earrings", "images/Red_earrings.bmp", 50, 50, true, RGB(255, 0, 255));
	Red_earrings.itemImageName = "Red_earrings";
	Red_earrings.itemInfoImage;			// 아이템 UI이미지
	Red_earrings.itemRect;				// 아이템 생성위치
	Red_earrings.itemUIRect;				// 아이템 UI위치
	Red_earrings.itemName = "룸티스의 붉은빛 귀걸이";				// 아이템 이름
	Red_earrings.addAttack;				// 플레이어 공격력 증감
	Red_earrings.addDefence;				// 플레이어 방어력 증감
	Red_earrings.addMagicDefence;		// 플레이어 마법방어력 증감
	Red_earrings.addSpeed;			// 플레이어 속도 증감
	Red_earrings.amount = 1;					// 아이템 수량
	Red_earrings.weight = 1;					// 아이템 무게
	Red_earrings.addHP;				// 현재 HP 증감
	Red_earrings.addMP;					// 현재 MP 증감
	Red_earrings.price = 19890;					// 아이템 가격
	vAllItem.push_back(Red_earrings);

	//스냅퍼의 지혜 반지1
	Ringofwisdom1.itemKind = ITEM_RING3;					// 아이템 종류
	Ringofwisdom1.itemImage =
		IMAGEMANAGER->addImage("Ringofwisdom", "images/Ringofwisdom.bmp", 50, 50, true, RGB(255, 0, 255));
	Ringofwisdom1.itemImageName = "Ringofwisdom";
	Ringofwisdom1.itemInfoImage;			// 아이템 UI이미지
	Ringofwisdom1.itemRect;				// 아이템 생성위치
	Ringofwisdom1.itemUIRect;				// 아이템 UI위치
	Ringofwisdom1.itemName = "스냅퍼의 지혜 반지";				// 아이템 이름
	Ringofwisdom1.addAttack;				// 플레이어 공격력 증감
	Ringofwisdom1.addDefence;				// 플레이어 방어력 증감
	Ringofwisdom1.addMagicDefence;		// 플레이어 마법방어력 증감
	Ringofwisdom1.addSpeed;			// 플레이어 속도 증감
	Ringofwisdom1.amount = 1;					// 아이템 수량
	Ringofwisdom1.weight = 1;					// 아이템 무게
	Ringofwisdom1.addHP;				// 현재 HP 증감
	Ringofwisdom1.addMP;					// 현재 MP 증감
	Ringofwisdom1.price = 21290;					// 아이템 가격
	vAllItem.push_back(Ringofwisdom1);

	//스냅퍼의 지혜 반지2
	Ringofwisdom2.itemKind = ITEM_RING4;					// 아이템 종류
	Ringofwisdom2.itemImage =
		IMAGEMANAGER->addImage("Ringofwisdom", "images/Ringofwisdom.bmp", 50, 50, true, RGB(255, 0, 255));
	Ringofwisdom2.itemImageName = "Ringofwisdom";
	Ringofwisdom2.itemInfoImage;			// 아이템 UI이미지
	Ringofwisdom2.itemRect;				// 아이템 생성위치
	Ringofwisdom2.itemUIRect;				// 아이템 UI위치
	Ringofwisdom2.itemName = "스냅퍼의 지혜 반지";				// 아이템 이름
	Ringofwisdom2.addAttack;				// 플레이어 공격력 증감
	Ringofwisdom2.addDefence;				// 플레이어 방어력 증감
	Ringofwisdom2.addMagicDefence;		// 플레이어 마법방어력 증감
	Ringofwisdom2.addSpeed;			// 플레이어 속도 증감
	Ringofwisdom2.amount = 1;					// 아이템 수량
	Ringofwisdom2.weight = 1;					// 아이템 무게
	Ringofwisdom2.addHP;				// 현재 HP 증감
	Ringofwisdom2.addMP;					// 현재 MP 증감
	Ringofwisdom2.price = 21290;					// 아이템 가격
	vAllItem.push_back(Ringofwisdom2);

	//시어의 심안
	Seers_Eye.itemKind = ITEM_SHIELD;					// 아이템 종류
	Seers_Eye.itemImage =
		IMAGEMANAGER->addImage("Seers_Eye", "images/Seers_Eye.bmp", 50, 50, true, RGB(255, 0, 255));
	Seers_Eye.itemImageName = "Seers_Eye";
	Seers_Eye.itemInfoImage;			// 아이템 UI이미지
	Seers_Eye.itemRect;				// 아이템 생성위치
	Seers_Eye.itemUIRect;				// 아이템 UI위치
	Seers_Eye.itemName = "시어의 심안";				// 아이템 이름
	Seers_Eye.addAttack;				// 플레이어 공격력 증감
	Seers_Eye.addDefence = 3;				// 플레이어 방어력 증감
	Seers_Eye.addMagicDefence;		// 플레이어 마법방어력 증감
	Seers_Eye.addSpeed;			// 플레이어 속도 증감
	Seers_Eye.amount = 1;					// 아이템 수량
	Seers_Eye.weight = 1;					// 아이템 무게
	Seers_Eye.addHP;				// 현재 HP 증감
	Seers_Eye.addMP;					// 현재 MP 증감
	Seers_Eye.price = 18580;					// 아이템 가격
	vAllItem.push_back(Seers_Eye);

	//현자의 목걸이
	Sages_Necklace.itemKind = ITEM_NECKLACE;					// 아이템 종류
	Sages_Necklace.itemImage =
		IMAGEMANAGER->addImage("Sages_Necklace", "images/Sages_Necklace.bmp", 50, 50, true, RGB(255, 0, 255));
	Sages_Necklace.itemImageName = "Sages_Necklace";
	Sages_Necklace.itemInfoImage;			// 아이템 UI이미지
	Sages_Necklace.itemRect;				// 아이템 생성위치
	Sages_Necklace.itemUIRect;				// 아이템 UI위치
	Sages_Necklace.itemName = "현자의 목걸이";				// 아이템 이름
	Sages_Necklace.addAttack;				// 플레이어 공격력 증감
	Sages_Necklace.addDefence = 1;				// 플레이어 방어력 증감
	Sages_Necklace.addMagicDefence;		// 플레이어 마법방어력 증감
	Sages_Necklace.addSpeed;			// 플레이어 속도 증감
	Sages_Necklace.amount = 1;					// 아이템 수량
	Sages_Necklace.weight = 1;					// 아이템 무게
	Sages_Necklace.addHP;				// 현재 HP 증감
	Sages_Necklace.addMP;					// 현재 MP 증감
	Sages_Necklace.price = 21550;					// 아이템 가격
	vAllItem.push_back(Sages_Necklace);


	//대마법사의 모자
	Wizards_hat.itemKind = ITEM_HELMET;					// 아이템 종류
	Wizards_hat.itemImage =
		IMAGEMANAGER->addImage("Wizards_hat", "images/Wizards_hat.bmp", 50, 50, true, RGB(255, 0, 255));
	Wizards_hat.itemImageName = "Wizards_hat";
	Wizards_hat.itemInfoImage;			// 아이템 UI이미지
	Wizards_hat.itemRect;				// 아이템 생성위치
	Wizards_hat.itemUIRect;				// 아이템 UI위치
	Wizards_hat.itemName = "대마법사의 모자";				// 아이템 이름
	Wizards_hat.addAttack;				// 플레이어 공격력 증감
	Wizards_hat.addDefence = 3;				// 플레이어 방어력 증감
	Wizards_hat.addMagicDefence;		// 플레이어 마법방어력 증감
	Wizards_hat.addSpeed;			// 플레이어 속도 증감
	Wizards_hat.amount = 1;					// 아이템 수량
	Wizards_hat.weight = 1;					// 아이템 무게
	Wizards_hat.addHP;				// 현재 HP 증감
	Wizards_hat.addMP;					// 현재 MP 증감
	Wizards_hat.price = 11550;					// 아이템 가격
	vAllItem.push_back(Wizards_hat);


	//티셔츠
	Tshirts.itemKind = ITEM_TSHIRTS;					// 아이템 종류
	Tshirts.itemImage =
		IMAGEMANAGER->addImage("Tshirts", "images/Tshirts.bmp", 50, 50, true, RGB(255, 0, 255));
	Tshirts.itemImageName = "Tshirts";
	Tshirts.itemInfoImage;			// 아이템 UI이미지
	Tshirts.itemRect;				// 아이템 생성위치
	Tshirts.itemUIRect;				// 아이템 UI위치
	Tshirts.itemName = "티셔츠";				// 아이템 이름
	Tshirts.addAttack;				// 플레이어 공격력 증감
	Tshirts.addDefence = 3;				// 플레이어 방어력 증감
	Tshirts.addMagicDefence;		// 플레이어 마법방어력 증감
	Tshirts.addSpeed;			// 플레이어 속도 증감
	Tshirts.amount = 1;					// 아이템 수량
	Tshirts.weight = 1;					// 아이템 무게
	Tshirts.addHP;				// 현재 HP 증감
	Tshirts.addMP;					// 현재 MP 증감
	Tshirts.price = 16530;					// 아이템 가격
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
