#pragma once
#include"Hero.h"
#include"CommonData.h"
#include"ProgressView.h"
#include"Monster.h"
#include"WelcomeScene.h"
#include"ChatScene.h"
#include"LoadingScene.h"
#include "HelloWorldScene.h"

class PlayerControl
{
	
public:
	static Hero* createPlayer(char *pName, char *dName, char *deadA, Vec2 position)
	{
		auto hero = Hero::create();
		hero->initSprite(pName, dName, deadA, 100.0f);
		hero->setPosition(position);
		return hero;
	}

	static ProgressView* createPlayerHeroBlood(Hero* hero)
	{
		ProgressView* heroBlood = new ProgressView();
		heroBlood->setPosition(150, VisibleSize.height - 50);
		heroBlood->setScale(2.2f);
		heroBlood->setBackground("blood_back.png");
		heroBlood->setForeground("blood_fore.png");
		heroBlood->setTotalProgress(hero->getBlood());
		heroBlood->setCurrentProgress(hero->getBlood());
		return heroBlood;
	}

	static Sprite*createBloodRect(ProgressView* heroBlood)
	{
		Sprite* bloodRect = Sprite::create("bloodRect.png");
		bloodRect->setPosition(heroBlood->getPosition());
		return bloodRect;
	}

	static Sprite*createBloodHead(ProgressView* heroBlood,char*s )
	{
		Sprite* bloodHead = Sprite::create(s);
		bloodHead->setFlipX(true);
		bloodHead->setScale(0.6f);
		bloodHead->setPosition(heroBlood->getPositionX() - 120, heroBlood->getPositionY() + 10);
		return bloodHead;
	}
	static void attackMonster(Hero* hero, Vector<Monster*> vectorMonster,char* hurt,char* voice,int shangHai, Layer* scene)
	{
		SimpleAudioEngine::getInstance()->playEffect(voice, false);
		for (auto monster : vectorMonster)
		{
				if (!monster->isDead)
				{

					if (abs(hero->getPositionY() - monster->getPositionY()) < 30)

					{
						
						/*检测是否碰撞到怪物*/
						if (PlayerControl::isRectCollision(CCRectMake(hero->getPositionX(), hero->getPositionY(), hero->getSprite()->getContentSize().width - 70, hero->getSprite()->getContentSize().height - 30),
							CCRectMake(monster->getPositionX(), monster->getPositionY(), monster->getSprite()->getContentSize().width - 30, monster->getSprite()->getContentSize().height - 20)))
						{
							monster->hurtAnimation(hurt, monster->spriteDirection, shangHai);
							SimpleAudioEngine::getInstance()->playEffect(monster->monsterHurtVoice, false);
	
						}
					}
				}
				else
				{
					vectorMonster.clear();
					SimpleAudioEngine::getInstance()->playEffect(monster->monsterDeadVoice, false);
					SimpleAudioEngine::getInstance()->stopBackgroundMusic();

					auto callFunc = CallFunc::create([&]() {
						auto scene = ChatScene::createScene();
						Director::getInstance()->replaceScene(scene);
					});
					scene->removeAllChildren();
					scene->runAction(Sequence::create(callFunc, NULL));
					
				 return;
				}
			
		}
	}
	static Menu* createMenuAttack(Hero* hero,char* pngName, char* pug,char*attackAnimation,Vector<Monster*> vectorMonster,int x,int y,char *attack,char*voice,int shangHai, Layer* scene)
	{
		auto spriteAttack = Sprite::create(pngName);
		auto spriteAttack1 = Sprite::create(pug);
		auto menuItemAttack = MenuItemSprite::create(spriteAttack, spriteAttack1, [=](Ref*) {
			if (hero->isAttack == false)
			{
				hero->setAttackAnimation(attackAnimation, true);
				attackMonster(hero, vectorMonster,attack,voice, shangHai, scene);
			}
			

		});
		menuItemAttack->setPosition(x, y);

		menuItemAttack->setAnchorPoint(Point::ANCHOR_MIDDLE);
		menuItemAttack->setScale(0.7);
		auto menu1 = Menu::create();
		menu1->setPosition(Point::ZERO);
		menu1->addChild(menuItemAttack, 99);
		return menu1;
	}

	static bool isRectCollision(CCRect rect1, CCRect rect2)
	{
		float x1 = rect1.origin.x;	//矩形1中心点的横坐标
		float y1 = rect1.origin.y;	//矩形1中心店的纵坐标
		float w1 = rect1.size.width;//矩形1的宽度
		float h1 = rect1.size.height;//矩形1的高度
		float x2 = rect2.origin.x;
		float y2 = rect2.origin.y;
		float w2 = rect2.size.width;
		float h2 = rect2.size.height;

		if (x1 + w1*0.5 < x2 - w2*0.5)
			return false;//矩形1在矩形2左方，两者无碰撞
		else if (x1 - w1*0.5 > x2 + w2*0.5)
			return false;//矩形1在矩形2右方，两者无碰撞
		else if (y1 + h1*0.5 < y2 - h2*0.5)
			return false;//矩形1在举行2下方，两者无碰撞
		else if (y1 - h1*0.5 > y2 + h2*0.5)
			return false;//矩形1在矩形2上方，两者无碰撞

		return true;

	}

};