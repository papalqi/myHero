#include "Monster.h"
#include"CommonData.h"
using namespace cocos2d;

Monster::Monster()
{
	isRunning = false;
	spriteDirection = true;
	spriteName = NULL;
	isAttack = false; 
	isHurt = false;
	isDead = false;
	spriteBlood = NULL;
}

void Monster::initSprite(char *pName, char *dName, char *deadA, float blood)
{
	Role::initSprite(pName, dName, deadA);

	this->blood = blood;

	/*怪物血条*/
	spriteBlood = new ProgressView();
	spriteBlood->setPosition(sprite->getPositionX(), sprite->getPositionY() + 100);
	spriteBlood->setBackground("blood_back.png");
	spriteBlood->setForeground("blood_fore.png");
	spriteBlood->setTotalProgress(blood);
	spriteBlood->setCurrentProgress(blood);
	this->addChild(spriteBlood);
}
void Monster::goHero(Vec2 HeroPosition)
{
	
	if ((this->getPosition().x - HeroPosition.x) >= 0)
	{
		auto tt = Vec2(HeroPosition.x+100, HeroPosition.y);
		auto tem_po = ccpNormalize(tt - this->getPosition())*monsterSpeed + this->getPosition();
		this->setPosition(tem_po);
	}
	else
	{
		auto tt = Vec2(HeroPosition.x - 100, HeroPosition.y);
		auto tem_po = ccpNormalize(tt - this->getPosition())*monsterSpeed + this->getPosition();
		this->setPosition(tem_po);
	}
}

void Monster::judgeAttack()
{
	/*srand((int)GetCurrentTime());*/
	int x = rand() % 100;
	if (x > 98)
	{
		this->setAttackAnimation("monsterRolling", true);
	}
}

void Monster::hurtAnimation(const char *name, bool run_direction,int shangHai)
{
	//if (isDead)
		if (blood <=0)
		{
			//播放死亡动画
			deadAnimation(deadAni, spriteDirection);
			return;
		}
		
	isHurt = true;
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
	isHurt = true;
	auto animation = AnimationCache::getInstance()->getAnimation(name);

	animation->setDelayPerUnit(0.15f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1);
	Animate *act = Animate::create(animation);
	CallFunc *callFunc = CallFunc::create(this, callfunc_selector(Role::hurtEnd));
	auto tem = 100*shangHai / maxBlood;
	spriteBlood->setCurrentProgress(spriteBlood->getCurrentProgress() - shangHai);
	blood -= shangHai;
	sprite->runAction(Sequence::create(act, callFunc, NULL));
	
}
void Monster::setMonsterAttack(int i, int j, int k)
{
	monsterAttack1 = i;
	monsterAttack2 = j;
	monsterAttack3 = k;
}