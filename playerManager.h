#pragma once
#include "singletonBase.h"
#include "Player.h"

class playerManager : public singletonBase<playerManager>
{
private:
public:
	playerManager();
	~playerManager();
};

