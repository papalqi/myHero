#pragma once
#include "cocos2d.h"
#include "CommonData.h"

using namespace cocos2d;

class AMap : public Node
{
public:
	AMap();

	/*��ʼ����ͼ��nameΪ��ͼ����*/
	void initMap(const char* name);
	void initMap1(const char* name);
	/*���ݾ���λ���ƶ���ͼ*/
	void moveMap(Node* hero, bool direction);

	/*�жϵ�ͼ�Ƿ񵽴��Ե*/
	bool judgeMap();

	CREATE_FUNC(AMap);

private:
	/*��ͼ����*/
	Sprite* map;
};