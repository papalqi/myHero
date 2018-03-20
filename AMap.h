#pragma once
#include "cocos2d.h"
#include "CommonData.h"

using namespace cocos2d;

class AMap : public Node
{
public:
	AMap();

	/*初始化地图，name为地图名称*/
	void initMap(const char* name);
	void initMap1(const char* name);
	/*根据精灵位置移动地图*/
	void moveMap(Node* hero, bool direction);

	/*判断地图是否到达边缘*/
	bool judgeMap();

	CREATE_FUNC(AMap);

private:
	/*地图精灵*/
	Sprite* map;
};