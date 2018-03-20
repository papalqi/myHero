#include"MonsterControl.h"
extern int count;
Vector<Monster*> MonsterControl::vectorMonster;
float MonsterControl::viewDistance=500;
 void MonsterControl:: monsterAllAiConstruct(Hero*hero, ProgressView* heroBlood, char * run)
{
	for (auto monster : vectorMonster)
	{

		//获得距离
		auto temDistance = ccpDistance(hero->getPosition(), monster->getPosition());

		if (!monster->isDead && !monster->isHurt)
		{
			bool st;
			if ((hero->getPositionX() - monster->getPositionX()) > 0)
				st = true;
			else
				st = false;
			//当小于我们怪物的警示范围大于攻击范围，怪物就朝我们的英雄移动
			if (temDistance < viewDistance && temDistance>150)
			{

				monster->goHero(hero->getPosition());
				monster->setRunAnimation(run, st);

			}
			//如果在警示范围外，则巡逻（还没有完成）
			else
			{
				monster->stopRunAnimation();

			}
			/*srand((int)GetCurrentTime());*/
			int x = rand() % 10000;
			//如果怪物小于攻击范围的话，我们就让怪物做攻击动作
			if (temDistance <= 150 && !monster->isAttack&&x>0)
			{

				//怪物攻击技能一
				if (x > 9400)
					monsterAttack2(monster, hero, heroBlood, monster->monsterAttackS1);
				if (x < 7000 && x>6000)
					monsterAttack2(monster, hero, heroBlood, monster->monsterAttackS2);
				if (x < 400)
					monsterAttack3(monster, hero, heroBlood, monster->monsterAttackS3);
			}
		}

	}
}

  void MonsterControl::monsterAttack1(Monster* monster, Hero* hero, ProgressView* heroBlood, char * attack)
 {
	 monster->setAttackAnimation(attack, true);
	 //按照百分比计算一下

	 auto tem = 100 * monster->monsterAttack1 / hero->maxBlood;
	 heroBlood->setCurrentProgress(heroBlood->getCurrentProgress() - tem);
	 hero->hurtAnimation(hero->hurtAni);
	 SimpleAudioEngine::getInstance()->playEffect(hero->hurtVoice, false);
	 //判断是否死亡英雄死亡，死亡则跳转
	 if (heroBlood->getCurrentProgress() <= 0)
	 {
		 hero->isDead == true;
		 count = 0;
		 auto scene = WelcomeScene::createScene();
		 auto trans = TransitionCrossFade::create(1.0f, scene);
		 Director::getInstance()->replaceScene(trans);
		 SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		 return;
	 }
	 return;
 }
 void MonsterControl::monsterAttack2(Monster* monster, Hero* hero, ProgressView* heroBlood, char * attack2)
 {
	 monster->setAttackAnimation(attack2, true);
	 //按照百分比计算一下
	 auto tem = 100 * monster->monsterAttack2 / hero->getBlood();
	 heroBlood->setCurrentProgress(heroBlood->getCurrentProgress() - tem);
	 hero->hurtAnimation(hero->hurtAni);
	 SimpleAudioEngine::getInstance()->playEffect(hero->hurtVoice, false);
	 //判断是否死亡英雄死亡，死亡则跳转
	 if (heroBlood->getCurrentProgress() <= 0)
	 {
		 hero->isDead == true;
		 count = 0;
		 auto scene = WelcomeScene::createScene();
		 auto trans = TransitionCrossFade::create(1.0f, scene);
		 Director::getInstance()->replaceScene(trans);
		 SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		 return;
	 }
	 return;
 }
 void MonsterControl::monsterAttack3(Monster* monster, Hero* hero, ProgressView* heroBlood, char * attack3)
 {
	 monster->setAttackAnimation(attack3, true);
	 //按照百分比计算一下
	 auto tem = 100 * monster->monsterAttack2 / hero->getBlood();
	 heroBlood->setCurrentProgress(heroBlood->getCurrentProgress() - tem);
	 hero->hurtAnimation(hero->hurtAni);
	 SimpleAudioEngine::getInstance()->playEffect(hero->hurtVoice, false);
	 //判断是否死亡英雄死亡，死亡则跳转
	 if (heroBlood->getCurrentProgress() <= 0)
	 {
		 hero->isDead == true;
		 count = 0;
		 auto scene = WelcomeScene::createScene();
		 auto trans = TransitionCrossFade::create(1.0f, scene);
		 Director::getInstance()->replaceScene(trans);
		 SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		 return;
	 }
	 return;
 }