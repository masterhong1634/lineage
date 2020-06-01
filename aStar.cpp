#include "stdafx.h"
#include "aStar.h"
aStar::aStar()
{
}


aStar::~aStar()
{
}

HRESULT aStar::init()
{
	IMAGEMANAGER->addImage("rocket", "images/rocket.bmp", _startX, _startY, 20, 20, true, RGB(255, 0, 255));
	_astarState = ASTAR_STATE_END;	//초기상태 =  타일 배치 완료전 ( 타일배치가 완료 되었는지 확인 )
	_selectType = TILE_TYPE_EMPTY;	//초기에 선택되어있는 타일 속성 => 초기 클릭시 빈타일 설치
	_selectedTypeColor = RGB(255, 255, 255);  //배치할 타일 색상 = 흰색

	_startPointSet = false; // 시작지점이 아직 찍히기전이므로
	_endPointSet = false;	// 끝지점이 아직 찍히기 전이므로

	for (int i = 0; i < TILE_Y; i++)
	{
		for (int j = 0; j < TILE_X; j++)
		{
			_tile[i][j].type = TILE_TYPE_EMPTY;		//초기타일 속성 = 빈타일( 전체 빈타일로 시작 )
			_tile[i][j].color = RGB(255, 255, 255); // 흰색. 배치할 타일 색상
			_tile[i][j].parent = NULL;	//부모타일
			_tile[i][j].F = BIGNUM;		//초기값 F
			_tile[i][j].H = 0;			//계산전이므로 0
			_tile[i][j].i = i;			// 배열 y 위치
			_tile[i][j].j = j;			// 배열 x 위치
			_tile[i][j].rc = RectMake(WINSIZEX - (TILE_X + 1)* WIDTH + WIDTH * j,	// 타일x의 최대값만큼 빼준 위치에서 WIDTH * j 만큼 더해줌.
				WINSIZEY - (TILE_Y + 1) * HEIGHT + HEIGHT * i, WIDTH, HEIGHT);		// 타일y의 최대값만큼 빼준 위치에서 HEIGHT * i 만큼 더해줌.
		}
	}

	for (int i = 0; i < 5; i++)
	{
		rc[i] = RectMake(15, 300 + i * 50, 25, 25); // 좌측 색상표기해주는 렉트
	}


	return S_OK;
}

void aStar::release()
{
}

void aStar::update()
{
	//배치가 끝나지 않았다면
	if (_astarState == ASTAR_STATE_END)
	{
		//타일 배치
		tileComposition();
	}
	//시작지점 도착지점이 설치되어 있고 스페이스누르면 검색 시작
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _startPointSet && _endPointSet && _astarState == ASTAR_STATE_END)
	{
		tileInitializing();
	}
	// 5를 누르면 openList, closeList 벡터 클리어, 전체 초기화.
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_openList.clear();
		_closeList.clear();
		init();
	}
	//배치중이거나 발견했거나 길이 없으면 실행하지 마라 
	if (_astarState == ASTAR_STATE_END || _astarState == ASTAR_STATE_FOUND || _astarState == ASTAR_STATE_NOWAY)return;
	
	//_astarState == ASTAR_STATE_SEARCHING 상태일때만 아래의 함수들이 실행됨.

	addOpenList(); // 이동이 가능한 지역인지 파악하고 이동이 가능하면 _openList에 추가해주는 함수. 
	calculateH();  //오픈 리스트내 타일 H값계산
	calculateF();  //오픈 리스트내 타일 F값계산
	addCloseList();//가장 작은 F선택후 클로즈 리스트에 추가
	checkArrive(); //도착했는지 여부 체크
}

void aStar::render()
{


	TextOut(getMemDC(), 15, 75, "1 :지우개", strlen("1 :지우개"));
	TextOut(getMemDC(), 15, 95, "2 :시작", strlen("2 :시작"));
	TextOut(getMemDC(), 15, 115, "3 :끝", strlen("3 :끝"));
	TextOut(getMemDC(), 15, 135, "4 :장애물", strlen("4 :장애물"));
	TextOut(getMemDC(), 15, 155, "5 :초기화", strlen("5 :초기화"));

	char str[128];
	if (_astarState == ASTAR_STATE_END)sprintf_s(str, "스페이스 눌러");
	else if (_astarState == ASTAR_STATE_FOUND)sprintf_s(str, "찾음");
	else if (_astarState == ASTAR_STATE_NOWAY)sprintf_s(str, "길없음");
	else if (_astarState == ASTAR_STATE_SEARCHING)sprintf_s(str, "찾는중....");

	TextOut(getMemDC(), 15, 200, str, strlen(str));
	
	newFont = CreateFont(9, 0, 0, 0, FW_NORMAL, false, false, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, "굴림");
	oldFont = (HFONT)SelectObject(getMemDC(), newFont);

	for (int i = 0; i < TILE_Y; i++)
	{
		for (int j = 0; j < TILE_X; j++)
		{
			newBrush = CreateSolidBrush(_tile[i][j].color);
			oldBrush = (HBRUSH)SelectObject(getMemDC(), newBrush);
			RectangleMake(getMemDC(), _tile[i][j].rc);
			SelectObject(getMemDC(), oldBrush);
			DeleteObject(newBrush);

			if (_tile[i][j].parent == NULL)continue;
		}
	}
	SelectObject(getMemDC(), oldFont);
	DeleteObject(newFont);

	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			BeginSolidColor(getMemDC(), &newBrush, RGB(0, 255, 0));
			RectangleMake(getMemDC(), rc[i]);
			sprintf_s(str, "시작점");
			DeleteObject(newBrush);
		}
		if (i == 1)
		{
			BeginSolidColor(getMemDC(), &newBrush, RGB(255, 0, 0));
			RectangleMake(getMemDC(), rc[i]);
			sprintf_s(str, "도착");
			DeleteObject(newBrush);
		}
		if (i == 2)
		{
			BeginSolidColor(getMemDC(), &newBrush, RGB(55,155,55));
			RectangleMake(getMemDC(), rc[i]);
			sprintf_s(str, "openList");
			DeleteObject(newBrush);
		}
		if (i == 3)
		{
			BeginSolidColor(getMemDC(), &newBrush, RGB(255, 0, 255));
			RectangleMake(getMemDC(), rc[i]);
			sprintf_s(str, "closeList");
			DeleteObject(newBrush);
		}
		if (i == 4)
		{
			BeginSolidColor(getMemDC(), &newBrush, RGB(255, 100, 100));
			RectangleMake(getMemDC(), rc[i]);
			sprintf_s(str, "path");
			DeleteObject(newBrush);
		}
		TextOut(getMemDC(), rc[i].right+ 15, rc[i].top + 5, str, strlen(str));
	}
	if (_astarState == ASTAR_STATE_END )return;
	IMAGEMANAGER->render("rocket", getMemDC(), _closeList.back()->rc.left, _closeList.back()->rc.top);
}

void aStar::tileComposition() // 타일 구성 해주는 함수(update에서 작동)
{
	//지우개
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_selectType = TILE_TYPE_EMPTY;
		_selectedTypeColor = RGB(255, 255, 255);
	}
	//스타트
	else if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_selectType = TILE_TYPE_START;
		_selectedTypeColor = RGB(100, 255, 100);
	}
	//엔드
	else if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_selectType = TILE_TYPE_END;
		_selectedTypeColor = RGB(255, 0, 0);
	}
	//장애물
	else if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_selectType = TILE_TYPE_WALL;
		_selectedTypeColor = RGB(255, 255, 0);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < TILE_Y; i++)
		{
			for (int j = 0; j < TILE_X; j++)
			{
				if (PtInRect(&_tile[i][j].rc, m_ptMouse))
				{
					if (_tile[i][j].type == TILE_TYPE_START)_startPointSet = false; // 일단 안전하게 false로시작.
					if (_tile[i][j].type == TILE_TYPE_END)_endPointSet = false;


					_tile[i][j].type = _selectType; // 스타트, 엔드를 제외한 속성은 그냥 처리.
					_tile[i][j].color = _selectedTypeColor;

					if (_selectType == TILE_TYPE_START) // 스타트속성 선택되어있을 경우.
					{
						if (_startPointSet) // 이전에 스타트 속성이 정의되었을 경우 새로운 스타트 속성이 정의되면 값을 삭제함.
						{
							_tile[_startY][_startX].color = RGB(255, 255, 255);
							_tile[_startY][_startX].type = TILE_TYPE_EMPTY;
						}
						_startPointSet = true; // 다시 트루로 바꿔주고 스타트지점을 바꿈.
						_startX = j;
						_startY = i;
					}
					if (_selectType == TILE_TYPE_END)
					{
						if (_endPointSet) // 이전에 엔드 속성이 정의되었을 경우 새로운 스타트 속성이 정의되면 값을 삭제함.
						{
							_tile[_endY][_endX].color = RGB(255, 255, 255);
							_tile[_endY][_endX].type = TILE_TYPE_EMPTY;
						}
						_endPointSet = true; // 다시 트루로 바꿔주고 엔드지점을 바꿈.
						_endX = j;
						_endY = i;
					}
				}
			}
		}
	}
}

void aStar::tileInitializing() // 타일 속성에 따른 추가 속성(walkable, listOn) 부여.
{
	for (int i = 0; i < TILE_Y; i++)
	{
		for (int j = 0; j < TILE_X; j++)
		{
			if (_tile[i][j].type == TILE_TYPE_EMPTY)
			{
				_tile[i][j].walkable = true;
				_tile[i][j].listOn = false;
			}
			else if (_tile[i][j].type == TILE_TYPE_WALL)
			{
				_tile[i][j].walkable = false; // 벽이면 walkable->false
				_tile[i][j].listOn = false;
			}
			else if (_tile[i][j].type == TILE_TYPE_START)
			{
				_tile[i][j].walkable = true;
				_tile[i][j].listOn = true;	  

				_closeList.push_back(&_tile[i][j]);		// 시작지점을 클로즈리스트에 추가.
			}
			else if (_tile[i][j].type == TILE_TYPE_END)
			{
				_tile[i][j].walkable = true;
				_tile[i][j].listOn = false;
			}
		}
	}
	_astarState = ASTAR_STATE_SEARCHING; // 현재상태 검색중.
	//_lastIndex = 0; // 초기화
}

void aStar::addOpenList() // 이동이 가능한 지역인지 파악하고 이동이 가능하면 _openList에 추가해주는 함수. 
{
	Ci = _closeList.back()->i; //y값.    //마지막으로 추가된 클로즈리스트 i
	Cj = _closeList.back()->j; //x값. 
	Cg = _closeList.back()->G;

	if (Ci != 0)//0번째 줄이 아니면 상단중간블럭계산
	{
		if (_tile[Ci - 1][Cj].walkable)//상단 가운데 타일이 지나갈수 있다면
		{
			if (!_tile[Ci - 1][Cj].listOn)//오픈리스트에 포함이 안되어 있는 타일이라면
			{
				_tile[Ci - 1][Cj].listOn = true;//오픈리스트에 포함시킴
				_tile[Ci - 1][Cj].color = RGB(55,155,55);
				_tile[Ci - 1][Cj].G = Cg + 10;	//타일의 G값을 클로즈 리스트에 누적 G+10
				_tile[Ci - 1][Cj].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
				_openList.push_back(&_tile[Ci - 1][Cj]);//오픈리스트에 추가
			}
			else//오픈리스트에 포함이 되어 있던 타일이라면
			{
				if (Cg + 10 < _tile[Ci - 1][Cj].G)//기존G값보다 새로 계산한 G값이 작다면
				{
					_tile[Ci - 1][Cj].G = Cg + 10;//G값 새롭게 계산
					_tile[Ci - 1][Cj].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
				}
			}
		}
		if (Cj != 0)//0번째 열이 아니라면 좌상단블럭계산
		{
			//좌상단 타일의 오른쪽이나 아래에 벽이 없다면
			if (_tile[Ci - 1][Cj - 1].walkable && _tile[Ci - 1][Cj].walkable && _tile[Ci][Cj - 1].walkable) // 좌상단, 좌상단의 오른쪽, 좌상단의 아래쪽.
			{
				if (!_tile[Ci - 1][Cj - 1].listOn)//오픈리스트에 포함이 안되어 있는 타일이라면
				{
					_tile[Ci - 1][Cj - 1].listOn = true;
					_tile[Ci - 1][Cj - 1].color = RGB(55,155,55);
					_tile[Ci - 1][Cj - 1].G = Cg + 14;//대각선이므로
					_tile[Ci - 1][Cj - 1].parent = _closeList.back();
					_openList.push_back(&_tile[Ci - 1][Cj - 1]);
				}
				else
				{
					if (Cg + 14 < _tile[Ci - 1][Cj - 1].G)
					{
						_tile[Ci - 1][Cj - 1].G = Cg + 14;//대각선이므로
						_tile[Ci - 1][Cj - 1].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
					}
				}
			}
		}
		if (Cj != TILE_X - 1)//우상단: 마지막열이 아니라면
		{
			//우상단 타일의 왼쪽이나 아래에 벽이 없다면
			if (_tile[Ci - 1][Cj + 1].walkable && _tile[Ci - 1][Cj].walkable&& _tile[Ci][Cj + 1].walkable) // 우상단, 우상단의 왼쪽, 우상단의 아래.
			{
				if (!_tile[Ci - 1][Cj + 1].listOn)
				{
					_tile[Ci - 1][Cj + 1].listOn = true;
					_tile[Ci - 1][Cj + 1].color = RGB(55,155,55);
					_tile[Ci - 1][Cj + 1].G = Cg + 14;
					_tile[Ci - 1][Cj + 1].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
					_openList.push_back(&_tile[Ci - 1][Cj + 1]);
				}
				else
				{
					if (Cg + 14 < _tile[Ci - 1][Cj + 1].G)
					{
						_tile[Ci - 1][Cj + 1].G = Cg + 14;
						_tile[Ci - 1][Cj + 1].parent = _closeList.back();//타일의 부모를 클로즈 리스트의 마지막으로 추가
					}
				}
			}
		}
	}
	if (Cj != 0)//좌측 : 0번째 열이 아니라면
	{
		if (_tile[Ci][Cj - 1].walkable)//좌측타일이 이동가능하다면
		{
			if (!_tile[Ci][Cj - 1].listOn)
			{
				_tile[Ci][Cj - 1].listOn = true;
				_tile[Ci][Cj - 1].color = RGB(55,155,55);
				_tile[Ci][Cj - 1].G = Cg + 10;
				_tile[Ci][Cj - 1].parent = _closeList.back();
				_openList.push_back(&_tile[Ci][Cj - 1]);
			}
			else
			{
				if (Cg + 10 < _tile[Ci][Cj - 1].G)
				{
					_tile[Ci][Cj - 1].G = Cg + 10;
					_tile[Ci][Cj - 1].parent = _closeList.back();
				}
			}
		}
	}
	if (Cj != TILE_X - 1)//우측 :  마지막열이 아니라면
	{

		if (_tile[Ci][Cj + 1].walkable)//우측타일이 이동가능하다면
		{
			if (!_tile[Ci][Cj + 1].listOn)
			{
				_tile[Ci][Cj + 1].listOn = true;
				_tile[Ci][Cj + 1].color = RGB(55,155,55);
				_tile[Ci][Cj + 1].G = Cg + 10;
				_tile[Ci][Cj + 1].parent = _closeList.back();
				_openList.push_back(&_tile[Ci][Cj + 1]);
			}
			else
			{
				if (Cg + 10 < _tile[Ci][Cj + 1].G)
				{
					_tile[Ci][Cj + 1].G = Cg + 10;
					_tile[Ci][Cj + 1].parent = _closeList.back();
				}
			}
		}
	}
	if (Ci != TILE_Y - 1)//마지막행이 아니라면 하단 라인 계산
	{
		if (_tile[Ci + 1][Cj].walkable)//하단 가운데 타일이 이동가능하다면
		{
			if (!_tile[Ci + 1][Cj].listOn)
			{
				_tile[Ci + 1][Cj].listOn = true;
				_tile[Ci + 1][Cj].color = RGB(55,155,55);
				_tile[Ci + 1][Cj].G = Cg + 10;
				_tile[Ci + 1][Cj].parent = _closeList.back();
				_openList.push_back(&_tile[Ci + 1][Cj]);
			}
			else
			{
				if (Cg + 10 < _tile[Ci + 1][Cj].G)
				{
					_tile[Ci + 1][Cj].G = Cg + 10;
					_tile[Ci + 1][Cj].parent = _closeList.back();
				}
			}
		}
		if (Cj != 0)//좌하단 :  0번째 열이 아니라면
		{
			//좌하단 타일의 오른쪽이나 위에 벽이 없다면
			if (_tile[Ci + 1][Cj - 1].walkable && _tile[Ci + 1][Cj].walkable && _tile[Ci][Cj - 1].walkable)
			{
				if (!_tile[Ci + 1][Cj - 1].listOn)
				{
					_tile[Ci + 1][Cj - 1].listOn = true;
					_tile[Ci + 1][Cj - 1].color = RGB(55,155,55);
					_tile[Ci + 1][Cj - 1].G = Cg + 14;
					_tile[Ci + 1][Cj - 1].parent = _closeList.back();
					_openList.push_back(&_tile[Ci + 1][Cj - 1]);
				}
				else
				{
					if (Cg + 14 < _tile[Ci + 1][Cj - 1].G)
					{
						_tile[Ci + 1][Cj - 1].G = Cg + 14;
						_tile[Ci + 1][Cj - 1].parent = _closeList.back();
					}
				}
			}
		}
		if (Cj != TILE_X - 1)//우하단 :  마지막 열이 아니라면
		{
			//우하단 타일의 왼쪽이나 위가 이동가능하다면
			if (_tile[Ci + 1][Cj + 1].walkable && _tile[Ci + 1][Cj].walkable&& _tile[Ci][Cj + 1].walkable)
			{
				if (!_tile[Ci + 1][Cj + 1].listOn)
				{
					_tile[Ci + 1][Cj + 1].listOn = true;
					_tile[Ci + 1][Cj + 1].color = RGB(55,155,55);
					_tile[Ci + 1][Cj + 1].G = Cg + 14;
					_tile[Ci + 1][Cj + 1].parent = _closeList.back();
					_openList.push_back(&_tile[Ci + 1][Cj + 1]);
				}
				else
				{
					if (Cg + 14 < _tile[Ci + 1][Cj + 1].G)
					{
						_tile[Ci + 1][Cj + 1].G = Cg + 14;
						_tile[Ci + 1][Cj + 1].parent = _closeList.back();
					}
				}
			}
		}
	}
}


//H = 사각형으로부터 최종목적지까지의 예상이동비용
//(대각선 이동이 아닌 가로세로 이동에 대한 비용으로 계산, 장애물에 대한 요소는 고려하지 않는다.)
void aStar::calculateH() //오픈 리스트내 타일 H값계산
{
	for (int i = 0; i < _openList.size(); i++)//오픈리스트벡터의 모든 요소에 대하여 계산.
	{
		int vertical = (_endX - _openList[i]->j) * 10;    //가로 H값 . x의 값.  수직변(left) - 해당 rect와 끝점과의 x축 거리차
		int horizontal = (_endY - _openList[i]->i) * 10;  //세로 H값. y의 값. 수평변(top) - 해당 rect와 끝점과의 y축 거리차

		if (vertical < 0)vertical *= -1;//방향이 반대이면 음수부여(절대값)
		if (horizontal < 0)horizontal *= -1;

		_openList[i]->H = vertical + horizontal;//총 H값 : 가로+세로 H
	}
}

//F = 비용(목적지까지 가는 총 비용 현재까지 이동하는데 걸린 비용과 예상비용을 합침)
void aStar::calculateF()
{
	for (int i = 0; i < _openList.size(); i++) //오픈리스트벡터의 모든 요소에 대하여 계산.
	{
		_openList[i]->F = _openList[i]->G + _openList[i]->H;//F값계산 F = G + H.
	}
}

//가장 작은 F선택후 클로즈 리스트에 추가
void aStar::addCloseList()
{
	if (_openList.size() == 0)//검색했는데도 openList의 사이즈가 0이면 더이상 찾을것이 없음
	{
		_astarState = ASTAR_STATE_NOWAY;//경로없다
		return;
	}
	int index = 0;			//오픈 리스트중 가장 F가 작은 타일의 인덱스를 넣을 변수.
	int lowest = BIGNUM;

	for (int i = 0; i < _openList.size(); i++) // 오픈리스트 벡터 전체를 비교해서 가장 H가 작은 요소를 구하고 그요소의 i값을 index에 저장.
	{
		if (_openList[i]->F < lowest)
		{
			lowest = _openList[i]->F;
			index = i; 
		}
	}

	_openList[index]->color = RGB(255, 0, 255);
	_closeList.push_back(_openList[index]);
	_openList.erase(_openList.begin() + index);//클로즈 리스트에 추가된 타일은 오픈리스트에서 제외
	//_lastIndex++;//가장 나중에 추가된 클로즈의 인덱스
}

//도착했는지 여부 체크
void aStar::checkArrive()
{
	if (_closeList.back()->i == _endY && _closeList.back()->j == _endX)//클로즈 리스트의 i,j가 도착지점과 같다면
	{
		_astarState = ASTAR_STATE_FOUND;					// 상태값 변경.
		_closeList.back()->color = RGB(255, 100, 100);  // 끝점의 색상을 바꿔줌.
		showWay(_closeList.back());					// 찾은 길 보여주는 함수 호출. 인자값으로는 클로즈리스트의 최신값을 넣어줌.
	}
}

//찾은 길 보여주기.
void aStar::showWay(aStarTile* tile)
{
	if (!(tile->i == _endY && tile->j == _endX))//도착지점이 아니라면
	tile->color = RGB(255, 180, 180);

	tile = tile->parent;//타일의 부모를 참조해서showWay함수에 다시 넣는다.

	if (tile->parent == NULL)//타일의 부모가 시작지점이면 그만 끝내라
		return;
	else
		showWay(tile);//다시 호출
}
