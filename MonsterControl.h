#pragma once
#include"Hero.h"
#include"CommonData.h"
#include"Monster.h"
#include"Hero.h"
#include"ProgressView.h"
#include"ChatScene.h"

class MonsterControl
{
public:
	static Vector <Monster*>vectorMonster;
	static float viewDistance;
	static Monster*addMonster(char *pName,char *dName,char *deadA,Vec2 position,float HP)
	{
		auto monster = Monster::create();
		monster->initSprite(pName, dName, deadA, HP);
		monster->setPosition(position);
		return monster;
	}
	static void moveAllMonsterDueToHero(float sped)
	{
		for (auto monster : vectorMonster)
		{
			monster->setPositionX(monster->getPositionX()+ sped);
		}
	}
	static void monsterAllAiConstruct(Hero*hero, ProgressView* heroBlood, char * run);
	static void monsterAttack1(Monster* monster, Hero* hero, ProgressView* heroBlood, char * attack);
	static void monsterAttack2(Monster* monster, Hero* hero, ProgressView* heroBlood, char * attack2);
	static void monsterAttack3(Monster* monster, Hero* hero, ProgressView* heroBlood, char * attack3);

};