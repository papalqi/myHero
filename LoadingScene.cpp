#include "LoadingScene.h"

USING_NS_CC;
extern int count;
extern bool effect;
Scene* LoadingScene::createScene()
{
	auto scene = Scene::create();

	auto layer = LoadingScene::create();

	scene->addChild(layer);

	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("circle.plist");

	auto name = Sprite::create("name.png");
	name->setAnchorPoint(Point::ANCHOR_MIDDLE);
	name->setPosition(VisibleSize.width / 2, VisibleSize.height / 2);
	name->getTexture()->setAliasTexParameters();
	this->addChild(name, 99);

	auto circle = Sprite::createWithSpriteFrameName("circle_00.png");
	circle->setAnchorPoint(Point::ANCHOR_MIDDLE);
	circle->setPosition(name->getPosition());
	circle->getTexture()->setAliasTexParameters();
	this->addChild(circle, 98);

	auto animation = Animation::create();

	for (int i = 0; i <= 5; i++)
	{
		std::string fileName = StringUtils::format("circle_0%d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(fileName));
	}
	animation->setDelayPerUnit(0.15f);
	animation->setLoops(-1);

	circle->runAction(Animate::create(animation));

	auto* chnStrings = Dictionary::createWithContentsOfFile("task.xml");
	const char* str = ((String*)chnStrings->objectForKey("task" + StringUtils::toString(count)))->getCString();

	auto lblTask = Label::createWithSystemFont(str, "Î¢ÈíÑÅºÚ", 24);
	lblTask->setAnchorPoint(Point::ANCHOR_MIDDLE);
	lblTask->setColor(ccc3(222, 185, 202));
	lblTask->setPosition(VisibleSize.width / 2, VisibleSize.height / 2 + 200);
	this->addChild(lblTask, 99, 91);

	auto sakura1 = Sprite::create("sakura1.png");
	sakura1->setScale(0.4f);
	sakura1->setVisible(false);
	sakura1->setAnchorPoint(Point::ANCHOR_MIDDLE);
	sakura1->setPosition(VisibleSize.width / 2 - 100, VisibleSize.height / 2 - 200);
	sakura1->getTexture()->setAliasTexParameters();
	this->addChild(sakura1, 99, 1);

	auto sakura2 = Sprite::create("sakura2.png");
	sakura2->setScale(0.4f);
	sakura2->setVisible(false);
	sakura2->setAnchorPoint(Point::ANCHOR_MIDDLE);
	sakura2->setPosition(VisibleSize.width / 2, VisibleSize.height / 2 - 200);
	sakura2->getTexture()->setAliasTexParameters();
	this->addChild(sakura2, 99, 2);

	auto sakura3 = Sprite::create("sakura3.png");
	sakura3->setScale(0.4f);
	sakura3->setVisible(false);
	sakura3->setAnchorPoint(Point::ANCHOR_MIDDLE);
	sakura3->setPosition(VisibleSize.width / 2 + 100, VisibleSize.height / 2 - 200);
	sakura3->getTexture()->setAliasTexParameters();
	this->addChild(sakura3, 99, 3);

	this->schedule(schedule_selector(LoadingScene::light1), 3, -1, 1);
	this->schedule(schedule_selector(LoadingScene::light2), 3, -1, 2);
	this->schedule(schedule_selector(LoadingScene::light3), 3, -1, 3);
	this->schedule(schedule_selector(LoadingScene::toFight), 3, -1, 4);

	return true;
}

void LoadingScene::update(float dt)
{
}

void LoadingScene::light1(float)
{
	auto sakura1 = (Sprite *)getChildByTag(1);

	sakura1->setVisible(true);

	/*sakura1->runAction(FadeIn::create(1.0f));*/

}

void LoadingScene::light2(float)
{
	auto sakura2 = (Sprite *)getChildByTag(2);

	sakura2->setVisible(true);

	/*sakura2->runAction(FadeIn::create(1.0f));*/

}

void LoadingScene::light3(float)
{
	auto sakura3 = (Sprite *)getChildByTag(3);

	sakura3->setVisible(true);

	/*sakura3->runAction(FadeIn::create(1.0f));*/
}

void LoadingScene::toFight(float)
{

	if (count == 0)
	{
		if (effect)
			SimpleAudioEngine::getInstance()->playBackgroundMusic("sakura.mp3", true);

		auto scene = WelcomeScene::createScene();
		auto trans = TransitionCrossFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(trans);

		return;
	}
	else
	{

		auto scene = HelloWorld::createScene();
		auto trans = TransitionCrossFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(trans);

		return;
	}

}