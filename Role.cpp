#include "Role.h";


Role::Role()
	:isRunning(false)
	, spriteDirection(true)
	, spriteName(NULL)
	, deadName(NULL)
	, deadAni(NULL)
	, isAttack(false)
	, spriteBlood(NULL)
{};

void Role::initSprite(char *pName, char *dName, char* deadA)
{
	spriteName = pName;
	deadName = dName;
	deadAni = deadA;
	sprite = Sprite::createWithSpriteFrameName(pName);
	sprite->setFlipX(spriteDirection);
	sprite->setScale(0.5f);
	this->addChild(sprite);
}

void Role::setRunAnimation(const char *name, bool runDirection)
{
	if (spriteDirection != runDirection)
	{
		spriteDirection = runDirection;
		sprite->setFlipX(runDirection);
	}
	if (isRunning || isAttack)
		return;
	auto animation = AnimationCache::getInstance()->getAnimation(name);

	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(-1);

	sprite->runAction(Animate::create(animation));
	isRunning = true;
}

void Role::stopRunAnimation()
{
	if (!isRunning)
		return;
	sprite->stopAllActions();

	this->removeChild(sprite, true);
	sprite = Sprite::createWithSpriteFrameName(spriteName);
	sprite->setFlipX(spriteDirection);
	sprite->setScale(0.5f);
	this->addChild(sprite);
	isRunning = false;
}

void Role::setAttackAnimation(const char *name, bool runAction)
{
	if (isRunning || isAttack)
		return;
	auto animation = AnimationCache::getInstance()->getAnimation(name);

	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1);

	auto callFunc = CCCallFunc::create(this, callfunc_selector(Role::stopAttackAnimation));
	sprite->runAction(Sequence::create(Animate::create(animation),callFunc, NULL));
	isAttack = true;
}

void Role::stopAttackAnimation()
{
	this->removeChild(sprite, true);
	sprite = Sprite::createWithSpriteFrameName(spriteName);
	sprite->setScale(0.5f);
	sprite->setFlipX(spriteDirection);
	this->addChild(sprite);
	isAttack = false;
}

void Role::hurtEnd()
{
	isHurt = false;

	//char szName[100] = { 0 };
	//sprintf(szName, "-%d", 10);
	////��ѪƮ��
	//FlyWord *wen_zi = FlyWord::create(szName, 30, CCPointMake(0, 0));//���ڵ�ǰ����ģ�0��0��λ��,����ģ�0��0�����������ģ�������Կ���ê��
	//this->addChild(wen_zi, 2);

	if (blood < 0)
	{
		//������������
		deadAnimation(deadAni, spriteDirection);
	}
}

void Role::deadAnimation(const char *name, bool run_direction)
{
	
	isDead = true;
	auto animation = AnimationCache::getInstance()->getAnimation(name);

	animation->setDelayPerUnit(0.15f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(1);

	CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Role::deadEnd));

	sprite->runAction(Sequence::create(Animate::create(animation), callFunc, NULL));
}

void Role::deadEnd()
{
	/*�ָ�����������*/
	this->removeChild(sprite, true); //��ԭ���ľ���ɾ����
	sprite = Sprite::createWithSpriteFrameName(deadName); //�ָ�����������
	sprite->setScale(0.5f);
	sprite->setFlipX(spriteDirection);
	this->addChild(sprite);

	Blink* blinkact = Blink::create(3, 6);

	CallFunc* callfunc = CallFunc::create(this, callfunc_selector(Role::blinkEnd));

	sprite->runAction(Sequence::create(blinkact, callfunc, NULL));
}

void Role::blinkEnd()
{
	//this->removeAllChildren();
}

Sprite* Role::getSprite()
{
	return sprite;
}

float Role::getBlood()
{
	return blood;
}