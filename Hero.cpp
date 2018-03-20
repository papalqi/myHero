#include "Hero.h";

using namespace cocos2d;

void Hero::initSprite(char *pName, char *dName, char *deadA, float blood)
{
	Role::initSprite(pName, dName, deadA);

	this->blood = blood;
}

bool Hero::judgePosition()
{
	if (this->getPositionX() != VisibleSize.width / 2)
		return false;
	else
		return true;
}

void Hero::hurtAnimation(const char *name)
{
	if (isHurt || isDead)
		return;

	/*受伤优先*/
	if (isRunning || isAttack)
	{
		sprite->stopAllActions(); //停止所有动画
								  /*恢复精灵原来的初始化贴图*/
		this->removeChild(sprite);
		sprite = Sprite::createWithSpriteFrameName(spriteName);
		sprite->setScale(0.5f);
		sprite->setFlipX(spriteDirection);
		this->addChild(sprite);
		isRunning = false;
		isAttack = false;
	}

	auto animation = AnimationCache::getInstance()->getAnimation(name);

	animation->setDelayPerUnit(0.15f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1);

	Animate *act = Animate::create(animation);
	CallFunc *callFunc = CallFunc::create(this, callfunc_selector(Hero::hurtEnd));


	sprite->runAction(Sequence::create(act, callFunc, NULL));
	isHurt = true;
}
void Hero::setAttack(int i, int j, int k)
{
	heroAttack1 = i;
	heroAttack2 = j;
	heroAttack3 = k;
}