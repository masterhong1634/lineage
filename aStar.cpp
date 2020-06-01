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
	_astarState = ASTAR_STATE_END;	//�ʱ���� =  Ÿ�� ��ġ �Ϸ��� ( Ÿ�Ϲ�ġ�� �Ϸ� �Ǿ����� Ȯ�� )
	_selectType = TILE_TYPE_EMPTY;	//�ʱ⿡ ���õǾ��ִ� Ÿ�� �Ӽ� => �ʱ� Ŭ���� ��Ÿ�� ��ġ
	_selectedTypeColor = RGB(255, 255, 255);  //��ġ�� Ÿ�� ���� = ���

	_startPointSet = false; // ���������� ���� ���������̹Ƿ�
	_endPointSet = false;	// �������� ���� ������ ���̹Ƿ�

	for (int i = 0; i < TILE_Y; i++)
	{
		for (int j = 0; j < TILE_X; j++)
		{
			_tile[i][j].type = TILE_TYPE_EMPTY;		//�ʱ�Ÿ�� �Ӽ� = ��Ÿ��( ��ü ��Ÿ�Ϸ� ���� )
			_tile[i][j].color = RGB(255, 255, 255); // ���. ��ġ�� Ÿ�� ����
			_tile[i][j].parent = NULL;	//�θ�Ÿ��
			_tile[i][j].F = BIGNUM;		//�ʱⰪ F
			_tile[i][j].H = 0;			//������̹Ƿ� 0
			_tile[i][j].i = i;			// �迭 y ��ġ
			_tile[i][j].j = j;			// �迭 x ��ġ
			_tile[i][j].rc = RectMake(WINSIZEX - (TILE_X + 1)* WIDTH + WIDTH * j,	// Ÿ��x�� �ִ밪��ŭ ���� ��ġ���� WIDTH * j ��ŭ ������.
				WINSIZEY - (TILE_Y + 1) * HEIGHT + HEIGHT * i, WIDTH, HEIGHT);		// Ÿ��y�� �ִ밪��ŭ ���� ��ġ���� HEIGHT * i ��ŭ ������.
		}
	}

	for (int i = 0; i < 5; i++)
	{
		rc[i] = RectMake(15, 300 + i * 50, 25, 25); // ���� ����ǥ�����ִ� ��Ʈ
	}


	return S_OK;
}

void aStar::release()
{
}

void aStar::update()
{
	//��ġ�� ������ �ʾҴٸ�
	if (_astarState == ASTAR_STATE_END)
	{
		//Ÿ�� ��ġ
		tileComposition();
	}
	//�������� ���������� ��ġ�Ǿ� �ְ� �����̽������� �˻� ����
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _startPointSet && _endPointSet && _astarState == ASTAR_STATE_END)
	{
		tileInitializing();
	}
	// 5�� ������ openList, closeList ���� Ŭ����, ��ü �ʱ�ȭ.
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_openList.clear();
		_closeList.clear();
		init();
	}
	//��ġ���̰ų� �߰��߰ų� ���� ������ �������� ���� 
	if (_astarState == ASTAR_STATE_END || _astarState == ASTAR_STATE_FOUND || _astarState == ASTAR_STATE_NOWAY)return;
	
	//_astarState == ASTAR_STATE_SEARCHING �����϶��� �Ʒ��� �Լ����� �����.

	addOpenList(); // �̵��� ������ �������� �ľ��ϰ� �̵��� �����ϸ� _openList�� �߰����ִ� �Լ�. 
	calculateH();  //���� ����Ʈ�� Ÿ�� H�����
	calculateF();  //���� ����Ʈ�� Ÿ�� F�����
	addCloseList();//���� ���� F������ Ŭ���� ����Ʈ�� �߰�
	checkArrive(); //�����ߴ��� ���� üũ
}

void aStar::render()
{


	TextOut(getMemDC(), 15, 75, "1 :���찳", strlen("1 :���찳"));
	TextOut(getMemDC(), 15, 95, "2 :����", strlen("2 :����"));
	TextOut(getMemDC(), 15, 115, "3 :��", strlen("3 :��"));
	TextOut(getMemDC(), 15, 135, "4 :��ֹ�", strlen("4 :��ֹ�"));
	TextOut(getMemDC(), 15, 155, "5 :�ʱ�ȭ", strlen("5 :�ʱ�ȭ"));

	char str[128];
	if (_astarState == ASTAR_STATE_END)sprintf_s(str, "�����̽� ����");
	else if (_astarState == ASTAR_STATE_FOUND)sprintf_s(str, "ã��");
	else if (_astarState == ASTAR_STATE_NOWAY)sprintf_s(str, "�����");
	else if (_astarState == ASTAR_STATE_SEARCHING)sprintf_s(str, "ã����....");

	TextOut(getMemDC(), 15, 200, str, strlen(str));
	
	newFont = CreateFont(9, 0, 0, 0, FW_NORMAL, false, false, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, "����");
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
			sprintf_s(str, "������");
			DeleteObject(newBrush);
		}
		if (i == 1)
		{
			BeginSolidColor(getMemDC(), &newBrush, RGB(255, 0, 0));
			RectangleMake(getMemDC(), rc[i]);
			sprintf_s(str, "����");
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

void aStar::tileComposition() // Ÿ�� ���� ���ִ� �Լ�(update���� �۵�)
{
	//���찳
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_selectType = TILE_TYPE_EMPTY;
		_selectedTypeColor = RGB(255, 255, 255);
	}
	//��ŸƮ
	else if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_selectType = TILE_TYPE_START;
		_selectedTypeColor = RGB(100, 255, 100);
	}
	//����
	else if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_selectType = TILE_TYPE_END;
		_selectedTypeColor = RGB(255, 0, 0);
	}
	//��ֹ�
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
					if (_tile[i][j].type == TILE_TYPE_START)_startPointSet = false; // �ϴ� �����ϰ� false�ν���.
					if (_tile[i][j].type == TILE_TYPE_END)_endPointSet = false;


					_tile[i][j].type = _selectType; // ��ŸƮ, ���带 ������ �Ӽ��� �׳� ó��.
					_tile[i][j].color = _selectedTypeColor;

					if (_selectType == TILE_TYPE_START) // ��ŸƮ�Ӽ� ���õǾ����� ���.
					{
						if (_startPointSet) // ������ ��ŸƮ �Ӽ��� ���ǵǾ��� ��� ���ο� ��ŸƮ �Ӽ��� ���ǵǸ� ���� ������.
						{
							_tile[_startY][_startX].color = RGB(255, 255, 255);
							_tile[_startY][_startX].type = TILE_TYPE_EMPTY;
						}
						_startPointSet = true; // �ٽ� Ʈ��� �ٲ��ְ� ��ŸƮ������ �ٲ�.
						_startX = j;
						_startY = i;
					}
					if (_selectType == TILE_TYPE_END)
					{
						if (_endPointSet) // ������ ���� �Ӽ��� ���ǵǾ��� ��� ���ο� ��ŸƮ �Ӽ��� ���ǵǸ� ���� ������.
						{
							_tile[_endY][_endX].color = RGB(255, 255, 255);
							_tile[_endY][_endX].type = TILE_TYPE_EMPTY;
						}
						_endPointSet = true; // �ٽ� Ʈ��� �ٲ��ְ� ���������� �ٲ�.
						_endX = j;
						_endY = i;
					}
				}
			}
		}
	}
}

void aStar::tileInitializing() // Ÿ�� �Ӽ��� ���� �߰� �Ӽ�(walkable, listOn) �ο�.
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
				_tile[i][j].walkable = false; // ���̸� walkable->false
				_tile[i][j].listOn = false;
			}
			else if (_tile[i][j].type == TILE_TYPE_START)
			{
				_tile[i][j].walkable = true;
				_tile[i][j].listOn = true;	  

				_closeList.push_back(&_tile[i][j]);		// ���������� Ŭ�����Ʈ�� �߰�.
			}
			else if (_tile[i][j].type == TILE_TYPE_END)
			{
				_tile[i][j].walkable = true;
				_tile[i][j].listOn = false;
			}
		}
	}
	_astarState = ASTAR_STATE_SEARCHING; // ������� �˻���.
	//_lastIndex = 0; // �ʱ�ȭ
}

void aStar::addOpenList() // �̵��� ������ �������� �ľ��ϰ� �̵��� �����ϸ� _openList�� �߰����ִ� �Լ�. 
{
	Ci = _closeList.back()->i; //y��.    //���������� �߰��� Ŭ�����Ʈ i
	Cj = _closeList.back()->j; //x��. 
	Cg = _closeList.back()->G;

	if (Ci != 0)//0��° ���� �ƴϸ� ����߰������
	{
		if (_tile[Ci - 1][Cj].walkable)//��� ��� Ÿ���� �������� �ִٸ�
		{
			if (!_tile[Ci - 1][Cj].listOn)//���¸���Ʈ�� ������ �ȵǾ� �ִ� Ÿ���̶��
			{
				_tile[Ci - 1][Cj].listOn = true;//���¸���Ʈ�� ���Խ�Ŵ
				_tile[Ci - 1][Cj].color = RGB(55,155,55);
				_tile[Ci - 1][Cj].G = Cg + 10;	//Ÿ���� G���� Ŭ���� ����Ʈ�� ���� G+10
				_tile[Ci - 1][Cj].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
				_openList.push_back(&_tile[Ci - 1][Cj]);//���¸���Ʈ�� �߰�
			}
			else//���¸���Ʈ�� ������ �Ǿ� �ִ� Ÿ���̶��
			{
				if (Cg + 10 < _tile[Ci - 1][Cj].G)//����G������ ���� ����� G���� �۴ٸ�
				{
					_tile[Ci - 1][Cj].G = Cg + 10;//G�� ���Ӱ� ���
					_tile[Ci - 1][Cj].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
				}
			}
		}
		if (Cj != 0)//0��° ���� �ƴ϶�� �»�ܺ����
		{
			//�»�� Ÿ���� �������̳� �Ʒ��� ���� ���ٸ�
			if (_tile[Ci - 1][Cj - 1].walkable && _tile[Ci - 1][Cj].walkable && _tile[Ci][Cj - 1].walkable) // �»��, �»���� ������, �»���� �Ʒ���.
			{
				if (!_tile[Ci - 1][Cj - 1].listOn)//���¸���Ʈ�� ������ �ȵǾ� �ִ� Ÿ���̶��
				{
					_tile[Ci - 1][Cj - 1].listOn = true;
					_tile[Ci - 1][Cj - 1].color = RGB(55,155,55);
					_tile[Ci - 1][Cj - 1].G = Cg + 14;//�밢���̹Ƿ�
					_tile[Ci - 1][Cj - 1].parent = _closeList.back();
					_openList.push_back(&_tile[Ci - 1][Cj - 1]);
				}
				else
				{
					if (Cg + 14 < _tile[Ci - 1][Cj - 1].G)
					{
						_tile[Ci - 1][Cj - 1].G = Cg + 14;//�밢���̹Ƿ�
						_tile[Ci - 1][Cj - 1].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
					}
				}
			}
		}
		if (Cj != TILE_X - 1)//����: ���������� �ƴ϶��
		{
			//���� Ÿ���� �����̳� �Ʒ��� ���� ���ٸ�
			if (_tile[Ci - 1][Cj + 1].walkable && _tile[Ci - 1][Cj].walkable&& _tile[Ci][Cj + 1].walkable) // ����, ������ ����, ������ �Ʒ�.
			{
				if (!_tile[Ci - 1][Cj + 1].listOn)
				{
					_tile[Ci - 1][Cj + 1].listOn = true;
					_tile[Ci - 1][Cj + 1].color = RGB(55,155,55);
					_tile[Ci - 1][Cj + 1].G = Cg + 14;
					_tile[Ci - 1][Cj + 1].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
					_openList.push_back(&_tile[Ci - 1][Cj + 1]);
				}
				else
				{
					if (Cg + 14 < _tile[Ci - 1][Cj + 1].G)
					{
						_tile[Ci - 1][Cj + 1].G = Cg + 14;
						_tile[Ci - 1][Cj + 1].parent = _closeList.back();//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
					}
				}
			}
		}
	}
	if (Cj != 0)//���� : 0��° ���� �ƴ϶��
	{
		if (_tile[Ci][Cj - 1].walkable)//����Ÿ���� �̵������ϴٸ�
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
	if (Cj != TILE_X - 1)//���� :  ���������� �ƴ϶��
	{

		if (_tile[Ci][Cj + 1].walkable)//����Ÿ���� �̵������ϴٸ�
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
	if (Ci != TILE_Y - 1)//���������� �ƴ϶�� �ϴ� ���� ���
	{
		if (_tile[Ci + 1][Cj].walkable)//�ϴ� ��� Ÿ���� �̵������ϴٸ�
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
		if (Cj != 0)//���ϴ� :  0��° ���� �ƴ϶��
		{
			//���ϴ� Ÿ���� �������̳� ���� ���� ���ٸ�
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
		if (Cj != TILE_X - 1)//���ϴ� :  ������ ���� �ƴ϶��
		{
			//���ϴ� Ÿ���� �����̳� ���� �̵������ϴٸ�
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


//H = �簢�����κ��� ���������������� �����̵����
//(�밢�� �̵��� �ƴ� ���μ��� �̵��� ���� ������� ���, ��ֹ��� ���� ��Ҵ� ������� �ʴ´�.)
void aStar::calculateH() //���� ����Ʈ�� Ÿ�� H�����
{
	for (int i = 0; i < _openList.size(); i++)//���¸���Ʈ������ ��� ��ҿ� ���Ͽ� ���.
	{
		int vertical = (_endX - _openList[i]->j) * 10;    //���� H�� . x�� ��.  ������(left) - �ش� rect�� �������� x�� �Ÿ���
		int horizontal = (_endY - _openList[i]->i) * 10;  //���� H��. y�� ��. ����(top) - �ش� rect�� �������� y�� �Ÿ���

		if (vertical < 0)vertical *= -1;//������ �ݴ��̸� �����ο�(���밪)
		if (horizontal < 0)horizontal *= -1;

		_openList[i]->H = vertical + horizontal;//�� H�� : ����+���� H
	}
}

//F = ���(���������� ���� �� ��� ������� �̵��ϴµ� �ɸ� ���� �������� ��ħ)
void aStar::calculateF()
{
	for (int i = 0; i < _openList.size(); i++) //���¸���Ʈ������ ��� ��ҿ� ���Ͽ� ���.
	{
		_openList[i]->F = _openList[i]->G + _openList[i]->H;//F����� F = G + H.
	}
}

//���� ���� F������ Ŭ���� ����Ʈ�� �߰�
void aStar::addCloseList()
{
	if (_openList.size() == 0)//�˻��ߴµ��� openList�� ����� 0�̸� ���̻� ã������ ����
	{
		_astarState = ASTAR_STATE_NOWAY;//��ξ���
		return;
	}
	int index = 0;			//���� ����Ʈ�� ���� F�� ���� Ÿ���� �ε����� ���� ����.
	int lowest = BIGNUM;

	for (int i = 0; i < _openList.size(); i++) // ���¸���Ʈ ���� ��ü�� ���ؼ� ���� H�� ���� ��Ҹ� ���ϰ� �׿���� i���� index�� ����.
	{
		if (_openList[i]->F < lowest)
		{
			lowest = _openList[i]->F;
			index = i; 
		}
	}

	_openList[index]->color = RGB(255, 0, 255);
	_closeList.push_back(_openList[index]);
	_openList.erase(_openList.begin() + index);//Ŭ���� ����Ʈ�� �߰��� Ÿ���� ���¸���Ʈ���� ����
	//_lastIndex++;//���� ���߿� �߰��� Ŭ������ �ε���
}

//�����ߴ��� ���� üũ
void aStar::checkArrive()
{
	if (_closeList.back()->i == _endY && _closeList.back()->j == _endX)//Ŭ���� ����Ʈ�� i,j�� ���������� ���ٸ�
	{
		_astarState = ASTAR_STATE_FOUND;					// ���°� ����.
		_closeList.back()->color = RGB(255, 100, 100);  // ������ ������ �ٲ���.
		showWay(_closeList.back());					// ã�� �� �����ִ� �Լ� ȣ��. ���ڰ����δ� Ŭ�����Ʈ�� �ֽŰ��� �־���.
	}
}

//ã�� �� �����ֱ�.
void aStar::showWay(aStarTile* tile)
{
	if (!(tile->i == _endY && tile->j == _endX))//���������� �ƴ϶��
	tile->color = RGB(255, 180, 180);

	tile = tile->parent;//Ÿ���� �θ� �����ؼ�showWay�Լ��� �ٽ� �ִ´�.

	if (tile->parent == NULL)//Ÿ���� �θ� ���������̸� �׸� ������
		return;
	else
		showWay(tile);//�ٽ� ȣ��
}
