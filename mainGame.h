#pragma once
#include"gameNode.h"
#include"startScene.h"
#include"mainScene.h"
#include"quitScene.h"
#include"SubIsoMap.h"
#include"IsoMap.h"

#define SUBWINOPEN 1
class mainGame : public gameNode
{
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

