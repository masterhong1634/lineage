#pragma once
#include "gameNode.h"

class quitScene :public gameNode
{
public:
	quitScene();
	~quitScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

