#include "AMap.h"

using namespace cocos2d;

AMap::AMap()
	:map(NULL)
{

}

void AMap::initMap(const char* name)
{
	this->map = Sprite::create(name);
	map->setAnchorPoint(Point::ZERO);
	this->setAnchorPoint(Point::ZERO);
	this->addChild(map);
}
void AMap::initMap1(const char* name)
{

	this->map = Sprite::create(name);
	map->setAnchorPoint(Point::ANCHOR_MIDDLE);
	this->setAnchorPoint(Point::ANCHOR_MIDDLE);

	map->setPosition(VisibleSize.width / 2, VisibleSize.height / 2);
	float winw = VisibleSize.width;
	float winh = VisibleSize.height;
	float spx = map->getTextureRect().getMaxX();
	float spy = map->getTextureRect().getMaxY();
	map->setScaleX(winw / spx);
	map->setScaleY(winh / spy);
	map->getTexture()->setAliasTexParameters();
	this->addChild(map, 0, 1);
}
void AMap::moveMap(Node* hero, bool direction)
{
	if (hero->getPositionX() == VisibleSize.width / 2)
	{
		//if (direction == true && this->getPositionX() >= -(map->getContentSize().width - VisibleSize.width))
		//	this->setPositionX(this->getPositionX() - 1);
		//else if(direction == false && this->getPositionX() <= 0)
		//	this->setPositionX(this->getPositionX() + 1);
		/*ÏòÓÒ×ß+±ßÔµ¼ì²â*/
		if (direction == true && this->getPositionX() >= -(map->getContentSize().width - VisibleSize.width))
			this->setPositionX(this->getPositionX() - speed);
		/*Ïò×ó×ß+±ßÔµ¼ì²â*/
		if (direction == false && this->getPositionX() <= 0)
			this->setPositionX(this->getPositionX() + speed);
	}
}

bool AMap::judgeMap()
{
	/*·ÀÖ¹µØÍ¼ÔË¶¯ºó³¬¹ý±ßÔµ*/
	if (this->getPositionX() >= -(map->getContentSize().width - VisibleSize.width) && this->getPositionX() <=0)
		return false;
	else
		return true;
}