#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ProgressView.h"
#include "Role.h"
#include "Hero.h"
#include "Monster.h"
#include "AMap.h"
#include "HRocker.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void update(float dt);
	void pause(Ref *);
 
	void resume(Ref *);
	void  setHeroHead(char * headPng);
	void  creatRocker();
	void creatPause();
	void createBackGroud(char* s);
	void initHero(char * heroPng, char * deadHero, char *move, Vec2 pos, char*hurtAni, char*hurtVoice);

	void addJiNeng(char* zt1, char* zt2, char* attack1, int x, int y, char* voice, int ShangHai);

	void createZeTian();
    CREATE_FUNC(HelloWorld);
	void heroRun(char *str);
	void createXiZi();
	//void HelloWorld::addRuanNiMonster();
	//void HelloWorld::addQianYE();
	void addQianYE(int blood);
	void addWuTian(int blood);
	void addRuanNiMonster(int blood);
	void createLowBG1(char* s);
	void zetianjineng();
	void XIZIJINNEG();
	//void HelloWorld::addWuTian();
private:
	ProgressView* heroBlood;
	HRocker* rocker;
	AMap* myMap; 
	Hero* hero;
	char* run;
	char * MonsterRun;
	char * MonsterA;
	char *  monsterHurt;
	int activeWith;

};

#endif // __HELLOWORLD_SCENE_H__
