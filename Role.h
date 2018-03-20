#pragma once
#include "cocos2d.h";
#include "ProgressView.h"

using namespace cocos2d;

class Role : public Node
{
public:

	Role();

	/*����ͼƬ��������ɫ����Ѫ��*/
	void initSprite(char* name, char *dName, char* deadAni);

	/*����ͼƬ����Ѫ��ͼƬ������ɫ����Ѫ��*/
	virtual void initSprite(char* name, float blood){};

	/*���ñ��ܶ�����run_directionΪ�����泯�� falseΪ����*/
	void setRunAnimation(const char* name, bool runDirection);

	/*ֹͣ���ܶ���*/
	void stopRunAnimation();

	/*���ù�������*/
	void setAttackAnimation(const char* name, bool runDirection);

	/*ֹͣ��������*/
	void stopAttackAnimation();

	/*���˶���*/
	/*virtual void hurtAnimation(const char *name, bool run_direction);*/
	/*���˶�������*/
	void hurtEnd();
	/*�ж��Ƿ������˶���*/
	bool isHurt;

	/*��������*/
	void deadAnimation(const char *name, bool run_direction);
	/*������������*/
	void deadEnd();
	/*�ж��Ƿ�����*/
	bool isDead;

	/*����������˸����*/
	void blinkEnd();

	/*���ؽ�ɫ����*/
	Sprite* getSprite();

	float getBlood();

	/*�Ƿ��ڱ��ܶ���*/
	bool isRunning;

	/*�Ƿ��ڹ�������*/
	bool isAttack;

	/*�����ƶ�����*/
	bool spriteDirection;
	CREATE_FUNC(Role);

protected:

	/*��ɫ����*/
	Sprite* sprite;

	/*��ʼ״̬����ͼƬ*/
	char* spriteName;

	/*����״̬����ͼƬ*/
	char* deadName;

	/*����״̬����*/
	char* deadAni;

	/*��ɫѪ��*/
	ProgressView* spriteBlood;

	float blood;

};