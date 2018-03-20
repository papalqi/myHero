//#include "HelloWorldScene.h"
#include"HelloWorldScene.h"
#include"OurFunction.h"
#include"playerControl.h"
#include"MonsterControl.h"
#include"SimpleAudioEngine.h"
USING_NS_CC;
int count = 0;

bool effect = true;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool HelloWorld::init()
{
	
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	creatRocker();
	/*this->removeAllChildren();*/

	createControl();
	MonsterControl::vectorMonster.clear();
	if (count == 3)
	{
		createZeTian();
		hero->setBlood(400);
		hero->setAttack(10, 15, 17);
		createLowBG1("changJing1.jpg");
		addQianYE(100);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10, 20, 30);
		zetianjineng();
		activeWith = (VisibleSize.height / 2) + 10;
		
	}
	else if (count == 6)
	{
		createZeTian();
		hero->setBlood(400);
		hero->setAttack(10, 15, 17);
		createLowBG1("changJing2.jpg");
		activeWith = (VisibleSize.height / 2) - 30;
		addRuanNiMonster(100);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10, 20, 30);
		zetianjineng();
	}
	else if (count == 10)
	{
		createZeTian();
		hero->setBlood(400);
		hero->setAttack(10, 15, 17);
		createLowBG1("changJing3.jpg");
		activeWith = (VisibleSize.height / 2) - 30;
		addWuTian(200);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10, 20, 30);
		zetianjineng();
	}
	else if (count == 14)
	{
		createXiZi();
		hero->setBlood(400);
		hero->setAttack(10, 15, 17);
		createLowBG1("changJing2.jpg");
		activeWith = (VisibleSize.height / 2) - 30;
		
		addRuanNiMonster(200);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10, 20, 30);
		XIZIJINNEG();

	}
	else if (count == 18)
	{
		//di5ge 
		createZeTian();
		hero->setBlood(400);
		hero->setAttack(10, 15, 17);
		createLowBG1("changJing5.jpg");
		activeWith = (VisibleSize.height / 2) +10;
		addRuanNiMonster(200);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10, 20, 30);
		zetianjineng();
	}
	else if (count == 20)
	{
		//di6ge
		createZeTian();
		hero->setBlood(400);
		hero->setAttack(10, 15, 17);
		createLowBG1("changJing6.jpg");
		activeWith = (VisibleSize.height / 2) - 30;
		addQianYE(300);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10, 20, 30);
		zetianjineng();
	}
	else if (count == 23)
	{
		createXiZi();
		hero->setBlood(400);
		hero->setAttack(400, 15, 17);
		createLowBG1("changJing7.jpg");
		activeWith = (VisibleSize.height / 2) - 150;
		addRuanNiMonster(400);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10, 20, 30);
		XIZIJINNEG();
	}
	else
	{
		//��ʼ��Ӣ��
		createZeTian();
		//��ʼ��Ӣ��Ѫ��
		hero->setBlood(500);
		//��ʼ��Ӣ�ۼ����˺�
		hero->setAttack(100,50,20);
		//��ʼ������ͼ
		createLowBG1("changJing7.jpg");
		//�������¾����������
		activeWith = (VisibleSize.height / 2) +30;
		//��ӹ��ﲢ����Ѫ��
		addWuTian(1500);
		//���ù��﹥��
		MonsterControl::vectorMonster.at(0)->setMonsterAttack(10,20,30);
		//����Ӣ�ۼ���
		zetianjineng();
		//
		auto monster = Monster::create();
		monster->initSprite("yu077_10.png", "yu077_10.png", "qianye_fall", 10);
		monster->setPosition(Vec2(VisibleSize.width - 150, (VisibleSize.height / 2)-100));
		this->addChild(monster);
		//zetianjineng();
	}

	//SimpleAudioEngine::getInstance()->playBackgroundMusic("bodou.wav", true);
		creatPause();
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("bodou.mp3");
		if (effect)
		{
			SimpleAudioEngine::getInstance()->playBackgroundMusic("bodou.wav", true);
		}
		this->scheduleUpdate();
	return true;

}
/*���ݲ����˽��н�ɫ�ƶ���Ŀǰֻ�����������ƶ�������û��ʵ�ֹ涨�����ƶ����䡪��3.24
*/
void HelloWorld::addQianYE(int blood)
{
	auto monster = MonsterControl::addMonster("yu050_00.png", "yu050_00.png", "qianye_fall", Vec2(VisibleSize.width - 150, VisibleSize.height / 2), 300.0f);
	monster->setBlood(blood);
	this->addChild(monster, 99);
	MonsterControl::vectorMonster.pushBack(monster);
	MonsterA = "qianye_stab";
	monster->monsterAttackS1 = "qianye_stab";
	monster->monsterAttackS2 = "qianye_fan";
	monster->monsterAttackS3 = "qianye_fancleave";
	MonsterRun = "qianYeRun";
	monsterHurt = "qianYeHurt";
	monster->monsterDeadVoice = "grilDead.wav";
	monster->monsterHurtVoice = "grilhurt.wav";

}

void HelloWorld::addWuTian(int blood)
{
	auto monster = MonsterControl::addMonster("ha201_10.png", "ha060_13.png", "wuTianFall", Vec2(VisibleSize.width - 150, VisibleSize.height / 2), 300.0f);
	monster->setBlood(blood);
	this->addChild(monster, 99);
	MonsterControl::vectorMonster.pushBack(monster);

	monster->monsterAttackS1 = "wutian_ordinaryhit";
	monster->monsterAttackS2 = "wutian_heavyhit";
	monster->monsterAttackS3 = "wutian_sword";
	MonsterRun = "wutian_kick";
	monsterHurt = "wutian_hurt";
	monster->monsterDeadVoice = "boyHurt.wav";
	monster->monsterHurtVoice = "boyHurt.wav";
}
void HelloWorld::addRuanNiMonster(int blood)
{
	auto monster = MonsterControl::addMonster("ar070_00.png", "ar070_10.png", "softMudHurt", Vec2(VisibleSize.width - 150, VisibleSize.height / 2), 300.0f);
	
	monster->setBlood(blood);
	this->addChild(monster, 99);
	MonsterControl::vectorMonster.pushBack(monster);
	MonsterA = "monsterRolling";
	monster->monsterAttackS1 = "monsterRolling";
	monster->monsterAttackS2 = "softMud_stab";
	monster->monsterAttackS3 = "softMud_scorpion";
	MonsterRun = "monsterMove";
	monsterHurt = "softMudHurt";
	monster->monsterDeadVoice = "monsterHurt.wav";
	monster->monsterHurtVoice = "monsterHurt.wav";
}
void HelloWorld::update(float dt)
{
	
	MonsterControl::monsterAllAiConstruct(hero, heroBlood, MonsterRun);
	
	switch (rocker->rocketDirection)
	{
	case 1:
		hero->setRunAnimation(run, rocker->rocketRun);
		if (hero->getPositionX() <= VisibleSize.width - 8)
		{
			if (!hero->judgePosition() || myMap->judgeMap())
				hero->setPositionX(hero->getPositionX() + speed);
			else
				MonsterControl::moveAllMonsterDueToHero(-speed);
			myMap->moveMap(hero, rocker->rocketRun);

		}
		break;
	case 2:
		if (hero->getPositionY() > activeWith)
			break;
		hero->setRunAnimation(run, rocker->rocketRun);
		hero->setPositionY(hero->getPositionY() + speed);
		
		break;
	case 3:
		hero->setRunAnimation(run, rocker->rocketRun);
		if (hero->getPositionX() >= 8)
		{
			if (!hero->judgePosition() || myMap->judgeMap())
				hero->setPositionX(hero->getPositionX() - speed);
			else
				MonsterControl::moveAllMonsterDueToHero(speed);
			myMap->moveMap(hero, rocker->rocketRun);
		}
		break;
	case 4:
		if (hero->getPositionY() <hero->getContentSize().height+10)
			break;
		hero->setRunAnimation(run, rocker->rocketRun);
		hero->setPositionY(hero->getPositionY() - speed);
		break;
	default:
		hero->stopRunAnimation();
		break;
	}



}
void HelloWorld::pause(Ref *) {
	/*SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	SimpleAudioEngine::getInstance()->pauseAllEffects();*/

	auto menu = this->getChildByTag(110);
	auto itemPause = menu->getChildByTag(111);
	auto itemResume = menu->getChildByTag(112);
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("game_music.wav", false);
	itemPause->setVisible(false);
	itemResume->setVisible(true);
	//this->m_canMove = false;	//���ô����ı���

	Director::getInstance()->pause();
}

void HelloWorld::resume(Ref *) {
	//SimpleAudioEngine::getInstance()->playEffect("button.wav", true);
	//SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	//SimpleAudioEngine::getInstance()->resumeAllEffects();
	auto menu = this->getChildByTag(110);
	auto itemPause = menu->getChildByTag(111);
	auto itemResume = menu->getChildByTag(112);
	itemPause->setVisible(true);
	itemResume->setVisible(false);
	//this->m_canMove = true;

	Director::getInstance()->resume();

}


//����Ϊ����ֹ.png ||����.png||��·�Ķ���||  ���ֵ�λ��
void HelloWorld::initHero( char * heroPng, char * deadHero,  char *move,Vec2 pos,char*hurtAni,char*hurtVoice)
{
	//��ʼ��������hero
	
	hero = PlayerControl::createPlayer(heroPng, deadHero, move, pos);
	this->addChild(hero, 99);
	hero->hurtAni = hurtAni;
	hero->hurtVoice = hurtVoice;
}
void HelloWorld::createLowBG1(char* s)
{
	myMap = AMap::create();
	myMap->initMap1(s);
	myMap->setScaleY(1.1f);
	this->addChild(myMap, 0);
}
void HelloWorld::addJiNeng(char* zt1,char* zt2, char* attack1,int x,int y,char* voice,int ShangHai)
{
	auto menu1 = PlayerControl::createMenuAttack(hero, zt1, zt2, attack1,MonsterControl::vectorMonster, x,y,monsterHurt, voice, ShangHai,this);
	this->addChild(menu1, 99);
}
void  HelloWorld::setHeroHead(char * headPng)
{
	//��ʼ��������Ѫ��
	heroBlood = PlayerControl::createPlayerHeroBlood(hero);
	this->addChild(heroBlood, 2);
	//����Ѫ����
	Sprite* bloodRect = PlayerControl::createBloodRect(heroBlood);
	this->addChild(bloodRect, 2);
	//����ͷ��
	Sprite* bloodHead = PlayerControl::createBloodHead(heroBlood, headPng);
	this->addChild(bloodHead, 2);
}
void  HelloWorld::creatRocker()
{
	//��ʼ��������������
	rocker = HRocker::createHRocker("TranslationalContrlbt.png", "TranslationalControl.png", Vec2(VisibleSize.width*0.1, VisibleSize.width*0.1));
	this->addChild(rocker, 2);
	rocker->startRocker(true);
	//��������menu
}
void HelloWorld::creatPause()
{
	auto pauseNor = Sprite::createWithSpriteFrameName("game_pause_nor.png");
	auto pausePressed = Sprite::createWithSpriteFrameName("game_pause_pressed.png");
	auto menuItemPause = MenuItemSprite::create(pauseNor, pausePressed, CC_CALLBACK_1(HelloWorld::pause, this));
	menuItemPause->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
	menuItemPause->setPosition(Point(VisibleSize) - Point(20, 20));
	menuItemPause->setTag(111);
	auto resumeNor = Sprite::createWithSpriteFrameName("game_resume_nor.png");
	auto resumePressed = Sprite::createWithSpriteFrameName("game_resume_pressed.png");
	auto menuItemResume = MenuItemSprite::create(resumeNor, resumePressed, CC_CALLBACK_1(HelloWorld::resume, this));
	menuItemResume->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
	menuItemResume->setPosition(Point(VisibleSize) - Point(20, 20));
	menuItemResume->setVisible(false);
	menuItemResume->setTag(112);
	auto Pmenu = Menu::create();
	Pmenu->setPosition(Point::ZERO);
	Pmenu->addChild(menuItemPause);
	Pmenu->addChild(menuItemResume);
	this->addChild(Pmenu, 99, 110);
}
void HelloWorld::createBackGroud(char* s)
{
	myMap = AMap::create();
	myMap->initMap(s);
	myMap->setScaleY(1.1f);
	this->addChild(myMap, 0);
}
void HelloWorld::createXiZi()
{
	//��ҪԤ������

	//��ʼ��hero
	initHero("lc030_00.png", "lc030_10.png", "heroMove", Vec2(150, (VisibleSize.height / 2)-150),"xiziHurt","grilhurt.wav");
	//����Ӣ��ͷ��
	setHeroHead("girlHead2.png");
	//���Ӣ�۹�������

}
void HelloWorld::createZeTian()
{
	//��ҪԤ������
	//��ʼ��hero
	initHero("bc032_00.png", "bc070_04.png", "zetian-run", Vec2(150, (VisibleSize.height / 2)-150),"zetianHurt","boyHurt.wav");
	//����Ӣ��ͷ��
	setHeroHead("qingmu5.png");

}
void HelloWorld::heroRun(char *str)
{
	run = str;
}
void HelloWorld::XIZIJINNEG()
{
	addJiNeng("swootb.png", "baijian.png", "heroAttack", VisibleSize.width - 100, 100, "qunVoice.wav",hero->heroAttack1);
	addJiNeng("xiaoqiao_sk2.png", "xiaoqiao_sk2.png", "punch", VisibleSize.width - 200, 200, "qunVoice.wav", hero->heroAttack2);
	heroRun("heroMove");
	addJiNeng("xiaoqiao_sk3.png", "xiaoqiao_sk2.png", "heavykick", VisibleSize.width - 100, 200, "qunVoice.wav", hero->heroAttack3);
}
void HelloWorld::zetianjineng()
{

	//���Ӣ�۹�������
	addJiNeng("swootb.png", "baijian.png","zetian-poke", VisibleSize.width - 100, 100,"jianVoice2.wav", hero->heroAttack1);
	addJiNeng("yase_sk3.png", "yase_sk3.png", "zetian-ordinaryhit", VisibleSize.width - 200, 200, "jianVoice.wav", hero->heroAttack2);
	addJiNeng("yase_sk4.png", "yase_sk4.png","zetian-stab", VisibleSize.width - 100, 220, "jianVoice2.wav", hero->heroAttack3);
	heroRun("zetian-run");
}