#pragma once
#include "cocos2d.h"
#include "Role.h"
#include "ProgressView.h"
#include "Hero.h"
USING_NS_CC;
using namespace cocos2d;

class Monster : public Role
{
public:
	Monster();

	/*根据图片名、血条图片创建怪物，带血条*/
	void initSprite(char *pName, char *dName,char *deadA, float blood);
	void goHero(Vec2 HeroPosition);
	void stopAllAction() { stopRunAnimation(); }
	void setBlood(int i)
	{
		blood = i;
		spriteBlood->setTotalProgress(blood);
		spriteBlood->setCurrentProgress(blood);
		
	}
	void judgeAttack();

	/*受伤动画*/
	
	void hurtAnimation(const char *name, bool run_direction, int shangHai);
	CREATE_FUNC(Monster);
	char * monsterHurtVoice;
	char * monsterDeadVoice;
	void setMonsterAttack(int i,int j,int k);
	int monsterAttack1;
	int monsterAttack2;
	int monsterAttack3;
	int maxBlood;
	char* monsterAttackS1;
	char* monsterAttackS2;
	char* monsterAttackS3;


private:

};