#pragma once
#include "gameNode.h"

class startScene : public gameNode
{
private:
	effect * _startpage;
	effect * _startpage2;
	int _index_x = 0;
	int count = 0;
public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

