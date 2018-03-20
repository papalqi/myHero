#pragma once
#include "cocos2d.h";
#include "CommonData.h"
#include "Role.h";
#include "ProgressView.h"

using namespace cocos2d;

class Hero : public Role
{
public:
	
	void initSprite(char* pName, char* dName, char *deadA, float blood);

	void hurtAnimation(const char *name);
	bool judgePosition();
	char* hurtAni;
	char* hurtVoice;
	void setAttack(int i,int j,int k);
	int heroAttack1;
	int heroAttack2;
	void setBlood(int i)
	{
		maxBlood = i;
		blood = i;
	}
	int heroAttack3;
	int maxBlood;
	CREATE_FUNC(Hero);
};