#pragma once
#include "cocos2d.h";
#include "ProgressView.h"

using namespace cocos2d;

class Role : public Node
{
public:

	Role();

	/*根据图片名创建角色，无血条*/
	void initSprite(char* name, char *dName, char* deadAni);

	/*根据图片名、血条图片创建角色，带血条*/
	virtual void initSprite(char* name, float blood){};

	/*设置奔跑动画，run_direction为精灵面朝向， false为向右*/
	void setRunAnimation(const char* name, bool runDirection);

	/*停止奔跑动画*/
	void stopRunAnimation();

	/*设置攻击动画*/
	void setAttackAnimation(const char* name, bool runDirection);

	/*停止攻击动画*/
	void stopAttackAnimation();

	/*受伤动画*/
	/*virtual void hurtAnimation(const char *name, bool run_direction);*/
	/*受伤动画结束*/
	void hurtEnd();
	/*判断是否在受伤动画*/
	bool isHurt;

	/*死亡动画*/
	void deadAnimation(const char *name, bool run_direction);
	/*死亡动画结束*/
	void deadEnd();
	/*判断是否死亡*/
	bool isDead;

	/*怪物死亡闪烁结束*/
	void blinkEnd();

	/*返回角色精灵*/
	Sprite* getSprite();

	float getBlood();

	/*是否在奔跑动画*/
	bool isRunning;

	/*是否在攻击动画*/
	bool isAttack;

	/*精灵移动方向*/
	bool spriteDirection;
	CREATE_FUNC(Role);

protected:

	/*角色精灵*/
	Sprite* sprite;

	/*初始状态精灵图片*/
	char* spriteName;

	/*死亡状态精灵图片*/
	char* deadName;

	/*死亡状态动画*/
	char* deadAni;

	/*角色血条*/
	ProgressView* spriteBlood;

	float blood;

};