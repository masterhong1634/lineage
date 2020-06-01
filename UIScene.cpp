#include "stdafx.h"
#include "UIScene.h"
#include "gameScene.h"


UIScene::UIScene()
{
}


UIScene::~UIScene()
{
}

HRESULT UIScene::init()
{
	// UI에 필요한 모든 이미지 추가
	IMAGEMANAGER->addFrameImage("hp_num", "images/hp_num.bmp", 70 , 10 , 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("UI_num", "images/UI_num.bmp", 40 * 1.5 , 6 * 1.5, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("restart", "images/restart.bmp", 318 , 169, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("character_tab", "images/character_tab.bmp", 285 , 540, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("slash", "images/slash.bmp", 7, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pulley", "images/pulley.bmp", 13 * 1.5, 17 * 1.5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("equip_on", "images/equip_on.bmp", 21, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("icespike_UI", "images/icespike_UI.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("meteor_UI", "images/meteor_UI.bmp", 50, 50, true, RGB(255, 0, 255));
	
	// 인벤토리에 들어갈 초기 항목 추가
	//vInventory.push_back( ITEMMANAGER->get_big_green_potion());
	//vInventory.push_back( ITEMMANAGER->get_big_red_potion());
	//vInventory.push_back( ITEMMANAGER->get_big_white_potion());
	//vInventory.push_back( ITEMMANAGER->get_blue_potion());
	//vInventory.push_back( ITEMMANAGER->get_return_order());
	//vInventory.push_back( ITEMMANAGER->get_transform_order());
	vInventory.push_back( ITEMMANAGER->get_cristal_staff());
	vInventory.push_back( ITEMMANAGER->get_lyndbeor_armor());
	//vInventory.push_back( ITEMMANAGER->get_Beltofknowledge());
	//vInventory.push_back( ITEMMANAGER->get_blackelder_sandal());
	//vInventory.push_back( ITEMMANAGER->get_Devils_ring1());
	//vInventory.push_back( ITEMMANAGER->get_Devils_ring2());
	//vInventory.push_back( ITEMMANAGER->get_MagicDefenseGaiters());
	//vInventory.push_back( ITEMMANAGER->get_MagicalGloves());
	//vInventory.push_back( ITEMMANAGER->get_ProphetsPauldrons());
	//vInventory.push_back( ITEMMANAGER->get_Purple_earrings());
	//vInventory.push_back( ITEMMANAGER->get_QueenAnts_SilverWings());
	//vInventory.push_back( ITEMMANAGER->get_Red_earrings());
	//vInventory.push_back( ITEMMANAGER->get_Ringofwisdom1());
	//vInventory.push_back( ITEMMANAGER->get_Ringofwisdom2());
	//vInventory.push_back( ITEMMANAGER->get_Seers_Eye());
	//vInventory.push_back( ITEMMANAGER->get_Wizards_hat());
	//vInventory.push_back( ITEMMANAGER->get_Sages_Necklace());
	//vInventory.push_back( ITEMMANAGER->get_Tshirts());
	
	//인벤토리에 추가되면 inven_in 속성을 true로 부여
	for (int i = 0; i < vInventory.size(); i++)
	{
		vInventory[i].inven_in = true;
	}

	//상점에 들어갈 모든 아이템 추가
	vShopItem.push_back(ITEMMANAGER->get_cristal_staff());
	vShopItem.push_back(ITEMMANAGER->get_lyndbeor_armor());
	vShopItem.push_back(ITEMMANAGER->get_Beltofknowledge());
	vShopItem.push_back(ITEMMANAGER->get_blackelder_sandal());
	vShopItem.push_back(ITEMMANAGER->get_Devils_ring1());
	vShopItem.push_back(ITEMMANAGER->get_Devils_ring2());
	vShopItem.push_back(ITEMMANAGER->get_MagicDefenseGaiters());
	vShopItem.push_back(ITEMMANAGER->get_MagicalGloves());
	vShopItem.push_back(ITEMMANAGER->get_ProphetsPauldrons());
	vShopItem.push_back(ITEMMANAGER->get_Purple_earrings());
	vShopItem.push_back(ITEMMANAGER->get_QueenAnts_SilverWings());
	vShopItem.push_back(ITEMMANAGER->get_Tshirts());
	vShopItem.push_back(ITEMMANAGER->get_Red_earrings());
	vShopItem.push_back(ITEMMANAGER->get_Ringofwisdom1());
	vShopItem.push_back(ITEMMANAGER->get_Ringofwisdom2());
	vShopItem.push_back(ITEMMANAGER->get_Seers_Eye());
	vShopItem.push_back(ITEMMANAGER->get_Wizards_hat());
	vShopItem.push_back(ITEMMANAGER->get_Sages_Necklace());
	vShopItem.push_back(ITEMMANAGER->get_small_red_potion());
	vShopItem.push_back(ITEMMANAGER->get_small_white_potion());
	vShopItem.push_back(ITEMMANAGER->get_big_green_potion());
	vShopItem.push_back(ITEMMANAGER->get_big_red_potion());
	vShopItem.push_back(ITEMMANAGER->get_big_white_potion());
	vShopItem.push_back(ITEMMANAGER->get_blue_potion());


	//상점 8칸에 맞춰진 렉트
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			function_key[i * 4 + j] = { 982 + j * 51, 743 + i * 51, 1032 + j * 51, 793 + i * 51 };
		}		
	}

	//상점, 인벤, UI 관련 렉트
	close_rect = { 320, 7, 345, 32 };
	close_rect2 = { 346, 3, 371, 30 };
	buy_rect = { 105, 280, 240, 360 };
	buy_rect2 = { 0, 0, static_cast<int> (248 * 1.5), static_cast<int> (375 * 1.5) };
	inven_rect = { static_cast<int>(WINSIZEX - 181 * 1.5), 0, WINSIZEX, static_cast<int>(275 * 1.5) };
	UI_rect = { 0, WINSIZEY - 203, 1200, WINSIZEY };
	inven_close_rect = { WINSIZEX - 27, 5, WINSIZEX - 2, 30 };

	return S_OK;
}

void UIScene::release()
{
}


void UIScene::update()
{
	//상점주인 - 맵이동에 따라 위치값이 계속 변경하기때문에 update에서 지정
	pandora = { _gameScene->getStartX() + 1050, _gameScene->getStartY() + 3050, _gameScene->getStartX() + 1100, _gameScene->getStartY() + 3150 };
		   
	// hp 0이하시 restart 또는 quit 탭 출력
	if (_gameScene->get_player_hp() <= 0)
	{
		restart_on = true;
	}
	// 플레이어가 종료를 원할시 Q를 눌러 종료탭 출력
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		restart_on = !restart_on;
	}
	// 캐릭터 정보 확인을 위한 스탯창 출력
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		character_tab_on = !character_tab_on;
	}
	// 종료탭이 켜진 상태에서 restart, quit 에 따라 각각 실행.
	if (restart_on)
	{
		if (PtInRect(&quit_rect, m_ptMouse))
		{
			if(KEYMANAGER->isOnceKeyDown(VK_MBUTTON))
				SCENEMANAGER->changeScene("quitScene");
		}
		if (PtInRect(&restart_rect, m_ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_MBUTTON))
			{
				SCENEMANAGER->changeScene("startScene");
				SCENEMANAGER->changeScene("mainScene");
			}
		}
	}
	// 아이소매트리 위치 등 확인
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_isDebug = !_isDebug;
	}

	//각종 렉트들 위치 확인
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		shop_tap = !shop_tap;
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		inven_itemrect = !inven_itemrect;
		funtion_recton = !funtion_recton;
		character_tab_rect = !character_tab_rect;
	}
	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		quit_on = !quit_on;
	}
	//인벤토리 탭 출력
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		inven_on = !inven_on;
	}

	//상점 , 인벤 클릭 관련
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (PtInRect(&pandora, m_ptMouse))
		{
			shop_on = true;
		}			   
		if (shop_on)
		{
			if (PtInRect(&close_rect, m_ptMouse))
			{
				shop_on = false;
			}
			if (PtInRect(&buy_rect, m_ptMouse))
			{
				shop_on = false;
				shop_buy = true;
			}
		}

		if (shop_buy)
		{
			//구매버튼 클릭
			if (PtInRect(&purchase_rect, m_ptMouse))
			{
				purchase_on = true;
			}
			//상점탭이 꺼지면 구매카운트 초기화, 도르래 위치 초기화
			if (PtInRect(&close_rect2, m_ptMouse))
			{
				shop_buy = false;
				shopupdown_count = 0;
				shop_pulley_move = 0;
			}
			//도르래 움직임 관련
			if (PtInRect(&shop_uprect, m_ptMouse))
			{
				if (shopupdown_count > 0)
				{
					shopupdown_count--;
					if (shop_pulley_move >= 25) shop_pulley_move -= 25;
				}
			}
			if (PtInRect(&shop_downrect, m_ptMouse))
			{
				if (shopupdown_count < (vShopItem.size() - 8))
				{
					shopupdown_count++;
					if (shop_pulley_move <= 300) shop_pulley_move += 25;
				}
			}
			//상점 구매 갯수 조절.
			for (int i = 0; i < 8; i++)
			{
				if (PtInRect(&shopUp_click[i + shopupdown_count], m_ptMouse))
				{
					shop_buy_count[i + shopupdown_count]++;
				}
				if (PtInRect(&shopDown_click[i + shopupdown_count], m_ptMouse))
				{
					if(shop_buy_count[i + shopupdown_count] > 0)
					shop_buy_count[i + shopupdown_count]--;
				}
			}
		}
		if (inven_on)
		{
			if (PtInRect(&inven_close_rect, m_ptMouse))
			{
				inven_on = !inven_on;
			}
			//도르래 위아래 이동
			if (PtInRect(&invenup_rect, m_ptMouse))
			{
				if (updown_count > 0)
				{
					updown_count--;
					if (pulley_move >= 25) pulley_move -= 25;
				}
			}
			if (PtInRect(&invendown_rect, m_ptMouse))
			{
				if (updown_count < (vInventory.size() - 1) / 4)
				{
					updown_count++;
					if (pulley_move <= 200) pulley_move += 25;
				}
			}
		}
	}

	//Mini Map 이동
	if ((int)(_gameScene->getStartX() / 10) >= 250) miniMap_x = 250;
	else if ((int)(_gameScene->getStartX() / 10) <= -205) miniMap_x = -205;
	else miniMap_x = (int)(_gameScene->getStartX() / 10);

	if ((int)((3700 + _gameScene->getStartY()) / 10) >= 132) miniMap_y = 132;
	else if ((int)((3700 + _gameScene->getStartY()) / 10) <= -119) miniMap_y = -119;
	else miniMap_y = (int)((3700 + _gameScene->getStartY()) / 10);

	if (purchase_on)
	{
		purchase();
	}
	

	//촐기, 용기시간 제한 2분
	if (_green_on)
	{
		if (TIMEMANAGER->getWorldTime() - _green_starttime >= 50.0f)
		{
			_gameScene->set_player_speed_minus();
			_green_on = false;
		}
	}

	if (_courage_on)
	{
		if (TIMEMANAGER->getWorldTime() - _courage_starttime >= 50.0f)
		{
			_gameScene->set_player_speed_minus();
			_courage_on = false;
		}
	}
	
}

void UIScene::render()
{
	//상점 이미지 온오프
	if (shop_on)
	{
		IMAGEMANAGER->render("shop", getMemDC());
	}	

	if (shop_buy)
	{
		IMAGEMANAGER->render("shop_buy", getMemDC());
	}

	if (inven_on)
	{
		IMAGEMANAGER->render("inventory", getMemDC(), WINSIZEX - 181 * 1.5, 0);
	}

	//구매불가시 멘트 출력.
	if (purchase_reject)
	{
		purchase_count++;
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf_s(str, "아데나가 부족합니다. 거래불가!");
		TextOut(getMemDC(), 500, 250, str, strlen(str));
		if (purchase_count == 120)
		{
			purchase_reject = false;
			purchase_count = 0;
		}
	}

	//동일장비 착용하려 할시 출력.
	if (equip_reject)
	{
		equip_count++;
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf_s(str, "같은 슬롯에 이미 아이템을 착용하고 있습니다.");
		TextOut(getMemDC(), 450, 250, str, strlen(str));
		if (equip_count == 120)
		{
			equip_reject = false;
			equip_count = 0;
		}
	}

	//해당 아이템에 대한 구매갯수를 조절하는 렉트가 계속 바뀌기 때문에 매번 초기화가 필요.
	for (int i = 0; i < vShopItem.size(); i++)
	{
		vShopItem[i].itemUIRect = { -100,-100,-100,-100 };
	}

	//상점 구매갯수 올리고 내리는 렉트
	for (int i = 0; i < 32; i++)
	{
		shopUp_click[i] = { 0, };
		shopDown_click[i] = { 0, };
	}

	//도르래가 위아래로 움직임에 따라 해당 구매갯수를 지정하는 렉트의 vShopitem[i]값에 대응하는 렉트가 달라짐.
	for (int i = 0; i < 8; i++)
	{
		shopUp_click[(i + shopupdown_count)] = { 313, 140 + i * 51, 333, 160 + i * 51 };
		shopDown_click[(i + shopupdown_count)] = { 241, 140 + i * 51, 261, 160 + i * 51 };
	}

	for (int i = 0; i < 8; i++)
	{
		if (i + shopupdown_count < vShopItem.size())
		{
			//도르래 변화에 따른 렉트 수시변경
			vShopItem[(i + shopupdown_count)].itemUIRect = { 33, 114 + 51 * i, 83, 164 + 51 * i };

			if (shop_buy)
			{
				//아이템 이름 출력
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf_s(str, vShopItem[i + shopupdown_count].itemName);
				TextOut(getMemDC(), vShopItem[i + shopupdown_count].itemUIRect.left + 60, vShopItem[i + shopupdown_count].itemUIRect.top + 5, str, strlen(str));
				//아이템 가격 정보 위치 맞추기 위함.
				if (vShopItem[i + shopupdown_count].price > 999)
				{
					int price1 = vShopItem[i + shopupdown_count].price / 1000;
					int price2 = vShopItem[i + shopupdown_count].price - price1 * 1000;
					sprintf_s(str, "%d,%d", price1, price2);
				}
				else sprintf_s(str, "%d", vShopItem[i + shopupdown_count].price);

				if (strlen(str) == 3) TextOut(getMemDC(), vShopItem[i + shopupdown_count].itemUIRect.left + 150, vShopItem[i +
					shopupdown_count].itemUIRect.top + 30, str, strlen(str));
				else if (strlen(str) == 5) TextOut(getMemDC(), vShopItem[i + shopupdown_count].itemUIRect.left + 140, vShopItem[i + shopupdown_count].itemUIRect.top + 30, str, strlen(str));
				else if (strlen(str) == 6) TextOut(getMemDC(), vShopItem[i + shopupdown_count].itemUIRect.left + 130, vShopItem[i + shopupdown_count].itemUIRect.top + 30, str, strlen(str));
				else if (strlen(str) == 7) TextOut(getMemDC(), vShopItem[i + shopupdown_count].itemUIRect.left + 120, vShopItem[i + shopupdown_count].itemUIRect.top + 30, str, strlen(str));
				//해당 칸에 맞는 아이템 이미지 출력
				IMAGEMANAGER->render(vShopItem[i + shopupdown_count].itemImageName, getMemDC(), vShopItem[i + shopupdown_count].itemUIRect.left, vShopItem[i + shopupdown_count].itemUIRect.top);
				//도르래 이미지
				IMAGEMANAGER->render("pulley", getMemDC(), 346, 145 + shop_pulley_move);
				//몇개가 구매될건지 갯수를 보여주는 부분.
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf_s(str, "%d", shop_buy_count[i + shopupdown_count]);
				if(strlen(str) > 1) TextOut(getMemDC(), 280, 140 + i * 51, str, strlen(str));
				else if(strlen(str) <= 1) TextOut(getMemDC(), 290, 140 + i * 51, str, strlen(str));
			}
			//상점탭 각종 렉트
			if (shop_tap)
			{
				Rectangle(getMemDC(), vShopItem[i + shopupdown_count].itemUIRect.left, vShopItem[i + shopupdown_count].itemUIRect.top, vShopItem[i + shopupdown_count].itemUIRect.right, vShopItem[i + shopupdown_count].itemUIRect.bottom);
				Rectangle(getMemDC(), shop_uprect.left, shop_uprect.top, shop_uprect.right, shop_uprect.bottom);
				Rectangle(getMemDC(), shop_downrect.left, shop_downrect.top, shop_downrect.right, shop_downrect.bottom);
				Rectangle(getMemDC(), shopUp_click[i + shopupdown_count].left, shopUp_click[i + shopupdown_count].top, shopUp_click[i + shopupdown_count].right, shopUp_click[i + shopupdown_count].bottom);
				Rectangle(getMemDC(), shopDown_click[i + shopupdown_count].left, shopDown_click[i + shopupdown_count].top, shopDown_click[i + shopupdown_count].right, shopDown_click[i + shopupdown_count].bottom);
			}
		}
	}
	//상점탭 각종 렉트
	if (shop_tap)
	{
		Rectangle(getMemDC(), pandora.left, pandora.top, pandora.right, pandora.bottom);
		Rectangle(getMemDC(), close_rect.left, close_rect.top, close_rect.right, close_rect.bottom);
		Rectangle(getMemDC(), close_rect2.left, close_rect2.top, close_rect2.right, close_rect2.bottom);
		Rectangle(getMemDC(), buy_rect.left, buy_rect.top, buy_rect.right, buy_rect.bottom);
		Rectangle(getMemDC(), inven_close_rect.left, inven_close_rect.top, inven_close_rect.right, inven_close_rect.bottom);
		Rectangle(getMemDC(), purchase_rect.left, purchase_rect.top, purchase_rect.right, purchase_rect.bottom);
	}
	
	//미니맵 관련 이미지 렌더링
	IMAGEMANAGER->render("minimap", getMemDC(), 743, 743, 250 - miniMap_x, 132 - miniMap_y, 205, 153);
	IMAGEMANAGER->frameRender("Direction_indicator", getMemDC(), 840, 805, _gameScene->get_minimap_direction(), 0);

	//UI 이미지 렌더링
	IMAGEMANAGER->render("UI", getMemDC(), 0, WINSIZEY - 203);

	//라우풀 수치 UI 연동
	UI_Lawful_num[4] = _gameScene->get_player_lawful() % 10;
	UI_Lawful_num[3] = (_gameScene->get_player_lawful() / 10) % 10;
	UI_Lawful_num[2] = (_gameScene->get_player_lawful() / 100) % 10;
	UI_Lawful_num[1] = (_gameScene->get_player_lawful() / 1000) % 10;
	UI_Lawful_num[0] = (_gameScene->get_player_lawful() / 10000) % 10;
	if (_gameScene->get_player_lawful() >= 10000) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 47, 846, UI_Lawful_num[0], 0);
	if (_gameScene->get_player_lawful() >= 1000) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 56, 846, UI_Lawful_num[1], 0);
	if (_gameScene->get_player_lawful() >= 100) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 64, 846, UI_Lawful_num[2], 0);
	if (_gameScene->get_player_lawful() >= 10) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 72, 846, UI_Lawful_num[3], 0);
	if (_gameScene->get_player_lawful() > 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 80, 846, UI_Lawful_num[4], 0);
	else if (_gameScene->get_player_lawful() <= 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 80, 846, 0, 0);

	// 보유 아데나 수치 UI 연동
	UI_Adena_num[6] = _gameScene->get_player_adena() % 10;
	UI_Adena_num[5] = (_gameScene->get_player_adena() / 10) % 10;
	UI_Adena_num[4] = (_gameScene->get_player_adena() / 100) % 10;
	UI_Adena_num[3] = (_gameScene->get_player_adena() / 1000) % 10;
	UI_Adena_num[2] = (_gameScene->get_player_adena() / 10000) % 10;
	UI_Adena_num[1] = (_gameScene->get_player_adena() / 100000) % 10;
	UI_Adena_num[0] = (_gameScene->get_player_adena() / 1000000) % 10;
	if (_gameScene->get_player_adena() >= 1000000) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 122, 785, UI_Adena_num[0], 0);
	if (_gameScene->get_player_adena() >= 100000) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 130, 785, UI_Adena_num[1], 0);
	if (_gameScene->get_player_adena() >= 10000) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 138, 785, UI_Adena_num[2], 0);
	if (_gameScene->get_player_adena() >= 1000) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 146, 785, UI_Adena_num[3], 0);
	if (_gameScene->get_player_adena() >= 100) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 154, 785, UI_Adena_num[4], 0);
	if (_gameScene->get_player_adena() >= 10) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 162, 785, UI_Adena_num[5], 0);
	if (_gameScene->get_player_adena() > 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 170, 785, UI_Adena_num[6], 0);
	else if (_gameScene->get_player_adena() <= 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 170, 785, 0, 0);

	// 스펠 수치 UI 연동
	UI_Spell_num[1] = _gameScene->get_player_spell() % 10;
	UI_Spell_num[0] = (_gameScene->get_player_spell() / 10) % 10;
	if (_gameScene->get_player_spell() >= 10) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 157, 846, UI_Spell_num[0], 0);
	if (_gameScene->get_player_spell() > 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 165, 846, UI_Spell_num[1], 0);

	// 방어력 수치 UI 연동
	UI_Def_num[1] = _gameScene->get_player_def() % 10;
	UI_Def_num[0] = (_gameScene->get_player_def() / 10) % 10;
	if (_gameScene->get_player_def() >= 10) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 72, 818, UI_Def_num[0], 0);
	if (_gameScene->get_player_def() > 0) IMAGEMANAGER->frameRender("hp_num", getMemDC(), 80, 818, UI_Def_num[1], 0);

	//캐릭터 정보창 출력
	if (character_tab_on)
	{
		IMAGEMANAGER->render("character_tab", getMemDC());
	}

	// 인벤토리	
	for (int i = 0; i < vInventory.size(); i++)
	{
		vInventory[i].itemUIRect = { -100,-100,-100,-100 };
	}
	// 인벤창이 켜지면
	if (inven_on)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//인벤토리벡터의 범위 안에서
				if ((i + updown_count) * 4 + j < vInventory.size())
				{
					//도르래의 움직임에따라 렉트를 변경.
					vInventory.at((i + updown_count) * 4 + j).itemUIRect = { 962 + 51 * j, 31 + i * 51, 1012 + 51 * j, 81 + i * 51 };
					//초기화된 값의 변경이 일어난 렉트에만 출력. (6*4칸안에 현재 보여져야 할 아이템만 렌더링)
					if (vInventory.at((i + updown_count) * 4 + j).itemUIRect.left > 0)
					{
						IMAGEMANAGER->render(vInventory.at((i + updown_count) * 4 + j).itemImageName, getMemDC(),
							vInventory.at((i + updown_count) * 4 + j).itemUIRect.left, vInventory.at((i + updown_count) * 4 + j).itemUIRect.top);
					}
					//장비가 착용된 상태이면 인벤토리 안에 On 이미지 출력
					if (vInventory.at((i + updown_count) * 4 + j).equip_on == true)
					{
						IMAGEMANAGER->render("equip_on", getMemDC(), vInventory.at((i + updown_count) * 4 + j).itemUIRect.left,
							vInventory.at((i + updown_count) * 4 + j).itemUIRect.top);
					}
				}
			}
		}
		//도르래 이미지.
		IMAGEMANAGER->render("pulley", getMemDC(), 1172, 68 + pulley_move);

		for (int i = 0; i < vInventory.size(); i++)
		{
			//아이템마다 이미지렉트 위에 마우스가 올라가 있으면 해당 아이템의 이름 정보를 가져와서 렌더링
			if (PtInRect(&vInventory[i].itemUIRect, m_ptMouse))
			{
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf_s(str, vInventory[i].itemName);
				if (i % 4 == 3)
				{
					// 이름이 길고 가장 끝자리에 위치한 아이템의 이름은 조금 왼쪽으로 옮겨서 출력. 그냥 출력시 화면에 잘려 보이지 않음.
					if(strlen(str) > 12) TextOut(getMemDC(), vInventory[i].itemUIRect.left - 100, vInventory[i].itemUIRect.top + 5, str, strlen(str));
					else TextOut(getMemDC(), vInventory[i].itemUIRect.left - 50, vInventory[i].itemUIRect.top + 5, str, strlen(str));
				}
				//일반 이름 출력
				else TextOut(getMemDC(), vInventory[i].itemUIRect.left - 50, vInventory[i].itemUIRect.top + 5, str, strlen(str));
			}
		}

		if (inven_itemrect)
		{
			for (int i = 0; i < vInventory.size(); i++)
			{
				if(vInventory.at(i).inven_in == true)
				Rectangle(getMemDC(), vInventory.at(i).itemUIRect.left, vInventory.at(i).itemUIRect.top, vInventory.at(i).itemUIRect.right, vInventory.at(i).itemUIRect.bottom);
			}
			Rectangle(getMemDC(), invenup_rect.left, invenup_rect.top, invenup_rect.right, invenup_rect.bottom);
			Rectangle(getMemDC(), invendown_rect.left, invendown_rect.top, invendown_rect.right, invendown_rect.bottom);
		}
	}
	//리스타트 및 종료 이미지
	if (restart_on)
	{
		IMAGEMANAGER->render("restart", getMemDC(), 500, 250);
	}

	//리스타트 및 종료 렉트
	if (quit_on)
	{
		Rectangle(getMemDC(), restart_rect.left, restart_rect.top, restart_rect.right, restart_rect.bottom);
		Rectangle(getMemDC(), quit_rect.left, quit_rect.top, quit_rect.right, quit_rect.bottom);
	}

	//캐릭터 탭이 켜진 상태에서
	if (character_tab_on)
	{
		// 인벤내 더블클릭시 -> 캐릭터 스탯창 변경 관련 
		for (int i = 0; i < vInventory.size(); i++)
		{
			if (vInventory[i].equip_on == true)
			{
				if (vInventory[i].itemKind == ITEM_WEAPON)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), weapon_rect.left, weapon_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_ARMOR)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), armor_rect.left, armor_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_LEGGINGS)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), leggings_rect.left, leggings_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_BOOTS)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), boots_rect.left, boots_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_TSHIRTS)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), tshirts_rect.left, tshirts_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_HELMET)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), helmet_rect.left, helmet_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_GLOVES)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), glove_rect.left, glove_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_CLOAK)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), cloak_rect.left, cloak_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_SHIELD)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), shield_rect.left, shield_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_EARRING1)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), earring1_rect.left, earring1_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_EARRING2)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), earring2_rect.left, earring2_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_NECKLACE)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), necklace_rect.left, necklace_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_RING1)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), ring1_rect.left, ring1_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_RING2)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), ring2_rect.left, ring2_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_RING3)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), ring3_rect.left, ring3_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_RING4)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), ring4_rect.left, ring4_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_BELT)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), belt_rect.left, belt_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_ARMS)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), arms_rect.left, arms_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_BADGE)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), badge_rect.left, badge_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_PAULDRON)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), pauldron_rect.left, pauldron_rect.top);
				}
				if (vInventory[i].itemKind == ITEM_RUNE)
				{
					IMAGEMANAGER->render(vInventory[i].itemImageName, getMemDC(), rune_rect.left, rune_rect.top);
				}
			}
		}
	}

	// 확인용 렉트
	if (character_tab_rect)
	{
		Rectangle(getMemDC(), weapon_rect.left, weapon_rect.top, weapon_rect.right, weapon_rect.bottom);
		Rectangle(getMemDC(), ring1_rect.left, ring1_rect.top, ring1_rect.right, ring1_rect.bottom);
		Rectangle(getMemDC(), ring2_rect.left, ring2_rect.top, ring2_rect.right, ring2_rect.bottom);
		Rectangle(getMemDC(), rune_rect.left, rune_rect.top, rune_rect.right, rune_rect.bottom);
		Rectangle(getMemDC(), glove_rect.left, glove_rect.top, glove_rect.right, glove_rect.bottom);
		Rectangle(getMemDC(), badge_rect.left, badge_rect.top, badge_rect.right, badge_rect.bottom);
		Rectangle(getMemDC(), earring1_rect.left, earring1_rect.top, earring1_rect.right, earring1_rect.bottom);

		Rectangle(getMemDC(), helmet_rect.left, helmet_rect.top, helmet_rect.right, helmet_rect.bottom);
		Rectangle(getMemDC(), necklace_rect.left, necklace_rect.top, necklace_rect.right, necklace_rect.bottom);
		Rectangle(getMemDC(), tshirts_rect.left, tshirts_rect.top, tshirts_rect.right, tshirts_rect.bottom);
		Rectangle(getMemDC(), armor_rect.left, armor_rect.top, armor_rect.right, armor_rect.bottom);
		Rectangle(getMemDC(), belt_rect.left, belt_rect.top, belt_rect.right, belt_rect.bottom);
		Rectangle(getMemDC(), leggings_rect.left, leggings_rect.top, leggings_rect.right, leggings_rect.bottom);
		Rectangle(getMemDC(), boots_rect.left, boots_rect.top, boots_rect.right, boots_rect.bottom);

		Rectangle(getMemDC(), earring2_rect.left, earring2_rect.top, earring2_rect.right, earring2_rect.bottom);
		Rectangle(getMemDC(), pauldron_rect.left, pauldron_rect.top, pauldron_rect.right, pauldron_rect.bottom);
		Rectangle(getMemDC(), cloak_rect.left, cloak_rect.top, cloak_rect.right, cloak_rect.bottom);
		Rectangle(getMemDC(), shield_rect.left, shield_rect.top, shield_rect.right, shield_rect.bottom);
		Rectangle(getMemDC(), ring3_rect.left, ring3_rect.top, ring3_rect.right, ring3_rect.bottom);
		Rectangle(getMemDC(), ring4_rect.left, ring4_rect.top, ring4_rect.right, ring4_rect.bottom);
		Rectangle(getMemDC(), arms_rect.left, arms_rect.top, arms_rect.right, arms_rect.bottom);
	}

	//function rect 관련
	IMAGEMANAGER->render("small_red_potion", getMemDC(), function_key[0].left, function_key[0].top);
	IMAGEMANAGER->render("small_white_potion", getMemDC(), function_key[1].left, function_key[1].top);
	IMAGEMANAGER->render("meteor_UI", getMemDC(), function_key[2].left, function_key[2].top);
	IMAGEMANAGER->render("icespike_UI", getMemDC(), function_key[3].left, function_key[3].top);
	IMAGEMANAGER->render("blue_potion", getMemDC(), function_key[4].left, function_key[4].top);
	IMAGEMANAGER->render("big_green_potion", getMemDC(), function_key[5].left, function_key[5].top);


	if (funtion_recton)
	{
		for (int i = 0; i < 8; i++)
		{
			Rectangle(getMemDC(), function_key[i].left, function_key[i].top, function_key[i].right, function_key[i].bottom);
		}
	}
}

void UIScene::itemDBClick()
{
	if (inven_on)
	{
		for (int i = 0; i < vInventory.size(); i++)
		{
			if (PtInRect(&vInventory[i].itemUIRect, m_ptMouse))
			{
				if (vInventory[i].itemKind == ITEM_POTION)
				{
					if (vInventory[i].itemName == "농축 체력 회복제" || vInventory[i].itemName == "농축 강력 체력 회복제" ||
						vInventory[i].itemName == "신속 체력 회복제" || vInventory[i].itemName == "신속 강력 체력 회복제")
					{
						_gameScene->set_player_hp(vInventory[i].addHP + RND->getInt(15));
						if (_gameScene->get_player_stats()._hp > _gameScene->get_player_stats()._maxHp)
							_gameScene->set_player_hpMAX();
						EFFECTMANAGER->play("white_potion_effect", 300, 300);
					}

					else if (vInventory[i].itemName == "농축 마력의 물약")
					{
						_gameScene->set_player_mp(vInventory[i].addMP + RND->getInt(15));
						if (_gameScene->get_player_stats()._mp > _gameScene->get_player_stats()._maxMp)
							_gameScene->set_player_mpMAX();
						_gameScene->set_player_speed_plus();
						_courage_on = true;
						_courage_starttime = TIMEMANAGER->getWorldTime();
					}

					else if (vInventory[i].itemName == "농축 속도의 물약")
					{
						_gameScene->set_player_speed_plus();
						_green_on = true;
						_green_starttime = TIMEMANAGER->getWorldTime();
					}
				}
				else if (vInventory[i].itemKind == ITEM_WEAPON || vInventory[i].itemKind == ITEM_ARMOR || vInventory[i].itemKind == ITEM_LEGGINGS ||
					vInventory[i].itemKind == ITEM_BOOTS || vInventory[i].itemKind == ITEM_TSHIRTS || vInventory[i].itemKind == ITEM_HELMET ||
					vInventory[i].itemKind == ITEM_GLOVES || vInventory[i].itemKind == ITEM_CLOAK || vInventory[i].itemKind == ITEM_SHIELD ||
					vInventory[i].itemKind == ITEM_EARRING1 || vInventory[i].itemKind == ITEM_RING1 || vInventory[i].itemKind == ITEM_BELT || 
					vInventory[i].itemKind == ITEM_ARMS || vInventory[i].itemKind == ITEM_BADGE || vInventory[i].itemKind == ITEM_PAULDRON ||
					vInventory[i].itemKind == ITEM_RUNE || vInventory[i].itemKind == ITEM_RING2 || vInventory[i].itemKind == ITEM_RING3 ||
					vInventory[i].itemKind == ITEM_RING4 || vInventory[i].itemKind == ITEM_EARRING2 || vInventory[i].itemKind == ITEM_NECKLACE)
				{
					// 장비가 착용된 상태
					if (vInventory[i].equip_on)
					{						
						switch (vInventory[i].itemKind)
						{
						case ITEM_WEAPON:	weapon_on = false; vInventory[i].equip_on = false; _gameScene->set_player_attack(-10); _gameScene->set_player_spell(-8);  break;
						case ITEM_ARMOR:	armor_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-12); break;
						case ITEM_LEGGINGS: leggings_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-8); break;
						case ITEM_BOOTS:	boots_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-8); break;
						case ITEM_TSHIRTS:	tshirts_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-9); break;
						case ITEM_HELMET:	helmet_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-7); break;
						case ITEM_GLOVES:	glove_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-8); break;
						case ITEM_CLOAK:	cloak_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-6); break;
						case ITEM_SHIELD:	shield_on = false; vInventory[i].equip_on = false; _gameScene->set_player_defence(-10); break;
						case ITEM_EARRING1: earring1_on = false; vInventory[i].equip_on = false; break;
						case ITEM_EARRING2: earring2_on = false; vInventory[i].equip_on = false; break;
						case ITEM_NECKLACE: necklace_on = false; vInventory[i].equip_on = false; break;
						case ITEM_RING1:	ring1_on = false; vInventory[i].equip_on = false; _gameScene->set_player_attack(-5); _gameScene->set_player_spell(-3); break;
						case ITEM_RING2:	ring2_on = false; vInventory[i].equip_on = false; _gameScene->set_player_attack(-5); _gameScene->set_player_spell(-3); break;
						case ITEM_RING3:	ring3_on = false; vInventory[i].equip_on = false; _gameScene->set_player_attack(-5); _gameScene->set_player_spell(-3); break;
						case ITEM_RING4:	ring4_on = false; vInventory[i].equip_on = false; _gameScene->set_player_attack(-5); _gameScene->set_player_spell(-3); break;
						case ITEM_BELT:		belt_on = false; vInventory[i].equip_on = false; break;
						case ITEM_ARMS:		arms_on = false; vInventory[i].equip_on = false; break;
						case ITEM_BADGE:	badge_on = false; vInventory[i].equip_on = false; break;
						case ITEM_PAULDRON: pauldron_on = false; vInventory[i].equip_on = false; break;
						case ITEM_RUNE:		rune_on = false; vInventory[i].equip_on = false; break;
						default:break;
						}
					}
					//장비가 착용되지 않은 상태
					else
					{
						switch (vInventory[i].itemKind)
						{
						case ITEM_WEAPON:	if (weapon_on) { equip_reject = true; break; }		else { weapon_on = true; vInventory[i].equip_on = true; _gameScene->set_player_attack(+10); _gameScene->set_player_spell(+8); break; }
						case ITEM_ARMOR:	if (armor_on) { equip_reject = true; break; }		else { armor_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+12); break; }
						case ITEM_LEGGINGS: if (leggings_on) { equip_reject = true; break; }	else { leggings_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+8); break; }
						case ITEM_BOOTS:	if (boots_on) { equip_reject = true; break; }		else { boots_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+8); break; }
						case ITEM_TSHIRTS:	if (tshirts_on) { equip_reject = true; break; }		else { tshirts_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+9); break; }
						case ITEM_HELMET:	if (helmet_on) { equip_reject = true; break; }		else { helmet_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+7); break; }
						case ITEM_GLOVES:	if (glove_on) { equip_reject = true; break; }		else { glove_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+8); break; }
						case ITEM_CLOAK:	if (cloak_on) { equip_reject = true; break; }		else { cloak_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+6); break; }
						case ITEM_SHIELD:	if (shield_on) { equip_reject = true; break; }		else { shield_on = true; vInventory[i].equip_on = true; _gameScene->set_player_defence(+10); break; }
						case ITEM_EARRING1:	if (earring1_on) { equip_reject = true; break; }	else { earring1_on = true; vInventory[i].equip_on = true; break; }
						case ITEM_EARRING2: if (earring2_on) { equip_reject = true; break; }	else { earring2_on = true; vInventory[i].equip_on = true; break; } 
						case ITEM_NECKLACE: if (necklace_on) { equip_reject = true; break; }	else { necklace_on = true; vInventory[i].equip_on = true; break; } 
						case ITEM_RING1:	if (ring1_on) { equip_reject = true; break; }		else { ring1_on = true; vInventory[i].equip_on = true; _gameScene->set_player_attack(+5); _gameScene->set_player_spell(+3); break; }
						case ITEM_RING2:	if (ring2_on) { equip_reject = true; break; }		else { ring2_on = true; vInventory[i].equip_on = true; _gameScene->set_player_attack(+5); _gameScene->set_player_spell(+3); break; }
						case ITEM_RING3:	if (ring3_on) { equip_reject = true; break; }		else { ring3_on = true; vInventory[i].equip_on = true; _gameScene->set_player_attack(+5); _gameScene->set_player_spell(+3); break; }
						case ITEM_RING4:	if (ring4_on) { equip_reject = true; break; }		else { ring4_on = true; vInventory[i].equip_on = true; _gameScene->set_player_attack(+5); _gameScene->set_player_spell(+3); break; }
						case ITEM_BELT:		if (belt_on) { equip_reject = true; break; }		else { belt_on = true; vInventory[i].equip_on = true; break; }
						case ITEM_ARMS:		if (arms_on) { equip_reject = true; break; }		else { arms_on = true; vInventory[i].equip_on = true; break; }
						case ITEM_BADGE:	if (badge_on) { equip_reject = true; break; }		else { badge_on = true; vInventory[i].equip_on = true; break; }
						case ITEM_PAULDRON:	if (pauldron_on) { equip_reject = true; break; }	else { pauldron_on = true; vInventory[i].equip_on = true; break; }
						case ITEM_RUNE:		if (rune_on) { equip_reject = true; break; }		else { rune_on = true; vInventory[i].equip_on = true; break; }
						default:break;
						}						
					}
				}
			}
		}
	}
}

void UIScene::purchase()
{
	int sum = 0;
	for (int i = 0; i < vShopItem.size(); i++)
	{
		for (int j = 0; j < shop_buy_count[i]; j++)
		{
			sum += vShopItem[i].price;
		}
	}
	if (_gameScene->get_player_adena() < sum)
	{
		purchase_reject = true;
		purchase_on = false;
		shop_buy = false;
		for (int i = 0; i < 100; i++) shop_buy_count[i] = 0;
		shopupdown_count = 0;
		shop_pulley_move = 0;
	}
	else if (_gameScene->get_player_adena() >= sum)
	{
		for (int i = 0; i < vShopItem.size(); i++)
		{
			for (int j = 0; j < shop_buy_count[i]; j++)
			{
				vInventory.push_back(vShopItem[i]);
			}
			shop_buy_count[i] = 0;
		}
		_gameScene->set_player_adena(-sum);
		purchase_on = false;
		shop_buy = false;
		shopupdown_count = 0;
		shop_pulley_move = 0;
		for (int i = 0; i < vInventory.size(); i++)
		{
			vInventory[i].inven_in = true;
		}
	}
}
