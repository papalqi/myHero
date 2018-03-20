#include "WelcomeScene.h"

USING_NS_CC;
extern int count;
extern bool effect;
extern char* music[25];
Scene* WelcomeScene::createScene()
{
	auto scene = Scene::create();

	auto layer = WelcomeScene::create();

	scene->addChild(layer);

	return scene;
}

bool WelcomeScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	change = false;

	/*if (effect)
		SimpleAudioEngine::getInstance()->playBackgroundMusic("sakura.mp3");*/

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("petal.plist");
	auto animation = Animation::create();

	for (int i = 1; i <= 9; i++)
	{
		std::string fileName = StringUtils::format("petal_0%d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(fileName));
	}
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("petal_10.png"));
	animation->setDelayPerUnit(0.15f);
	animation->setLoops(-1);

	AnimationCache::getInstance()->addAnimation(animation, "petal");

	auto bg = Sprite::create("bg0.png");
	bg->setAnchorPoint(Point::ANCHOR_MIDDLE);
	bg->setPosition(VisibleSize.width / 2, VisibleSize.height / 2);
	float winw = VisibleSize.width;
	float winh = VisibleSize.height;
	float spx = bg->getTextureRect().getMaxX();
	float spy = bg->getTextureRect().getMaxY();
	bg->setScaleX(winw / spx);
	bg->setScaleY(winh / spy);
	bg->getTexture()->setAliasTexParameters();
	this->addChild(bg, 0, 99);

	auto start_nor = Sprite::create("startBut_nor.png");
	start_nor->setAnchorPoint(Point::ANCHOR_MIDDLE);
	auto start_pus = Sprite::create("startBut_pus.png");

	auto menuItemStart = MenuItemSprite::create(start_nor, start_pus, [](Ref *) {
		

		if (effect)
		{
			SimpleAudioEngine::getInstance()->playEffect("starteffect.wav");
			SimpleAudioEngine::getInstance()->playBackgroundMusic(music[count], true);
		}

		auto scene = ChatScene::createScene();
		auto trans = TransitionCrossFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(trans);
	});
	menuItemStart->setPosition(VisibleSize.width / 2, 100);
	menuItemStart->setAnchorPoint(Point::ANCHOR_MIDDLE);

	auto logo = Sprite::create("logo.png");
	logo->setPosition(VisibleSize.width-260, VisibleSize.height-235);
	logo->setAnchorPoint(Point::ANCHOR_MIDDLE);
	this->addChild(logo);

	auto actor_1 = Sprite::create("nan1.png");
	actor_1->setPosition(VisibleSize.width-215, 126);
	actor_1->setAnchorPoint(Point::ANCHOR_MIDDLE);
	this->addChild(actor_1, 1, 1);

	auto actor_2 = Sprite::create("nv1.png");
	actor_2->setPosition(300, 135);
	actor_2->setAnchorPoint(Point::ANCHOR_MIDDLE);
	this->addChild(actor_2, 1, 2);

	auto actor_3 = Sprite::create("nv2.png");
	actor_3->setPosition(433, 105);
	actor_3->setAnchorPoint(Point::ANCHOR_MIDDLE);
	this->addChild(actor_3, 1, 3);

	auto menu = Menu::create();
	menu->addChild(menuItemStart);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 99);

	auto fadeIn = FadeTo::create(3.0f, 255);
	auto fadeOut = FadeTo::create(3.0f, 125);

	start_nor->runAction(RepeatForever::create(Sequence::create(fadeOut, fadeIn, NULL)));

	actor_1->runAction(FadeOut::create(3.0f));
	actor_2->runAction(FadeOut::create(3.0f));
	actor_3->runAction(FadeOut::create(3.0f));

	this->schedule(schedule_selector(WelcomeScene::createSakura), 1, -1, 1);
	this->schedule(schedule_selector(WelcomeScene::actor1In), 6, -1, 3);
	this->schedule(schedule_selector(WelcomeScene::actor2In), 12, -1, 3);
	this->schedule(schedule_selector(WelcomeScene::actor3In), 12, -1, 9);
	return true;
}

void WelcomeScene::update(float dt)
{

}

void WelcomeScene::createSakura(float)
{
	srand(time(NULL));

	//auto sakura = Sprite::create("sakura" + StringUtils::toString(rand()%3+1)+".png");
	//sakura->setScale(0.25f);

	auto sakura = Sprite::createWithSpriteFrameName("petal_01.png");
	sakura->setScale(0.2f);
	sakura->setAnchorPoint(Point::ANCHOR_MIDDLE);
	sakura->getTexture()->setAliasTexParameters();
	/*this->addChild(sakura, 98);*/

	sakura->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("petal")));

	auto minX = sakura->getContentSize().width / 2;
	auto maxX = VisibleSize.width - minX;

	float x = rand() % (int)(maxX - minX) + minX;

	//sakura->setPosition(VisibleSize.width/2, VisibleSize.height / 2);
	//this->addChild(sakura, 99);

	sakura->setPosition(x, VisibleSize.height + sakura->getContentSize().height / 2);
	this->addChild(sakura, 99);

	auto move3 = MoveTo::create(5.0f, Point(rand()%(int)(VisibleSize.width), -sakura->getContentSize().height / 2));
	auto callFunc = CallFuncN::create([](Node *node) {
		node->removeFromParentAndCleanup(true);
	});

	sakura->runAction(Sequence::create(move3, callFunc, NULL));
}

void WelcomeScene::actor1In(float)
{
	auto actor_1 = (Sprite *)getChildByTag(1);

	actor_1->runAction(Sequence::create(FadeIn::create(3.0f) , FadeOut::create(3.0f), NULL));
}

void WelcomeScene::actor2In(float)
{
	
	auto actor_2 = (Sprite *)getChildByTag(2);

	actor_2->runAction(Sequence::create(FadeIn::create(3.0f), FadeOut::create(3.0f), NULL));
}

void WelcomeScene::actor3In(float)
{

	auto actor_3 = (Sprite *)getChildByTag(3);

	actor_3->runAction(Sequence::create(FadeIn::create(3.0f), FadeOut::create(3.0f), NULL));
}