#include "ChatScene.h"
#include "tinyxml2\tinyxml2.h"

USING_NS_CC;
extern int count;
extern bool effect;

char* music[26] = { "scene1.wav","scene2.mp3","scene3.wav","scene4.mp3","scene5.wma" ,"scene4.mp3","scene2.mp3" ,"scene8.mp3","" ,"","scene11.mp3" ,"scene8.mp3","scene13.mp3" ,"scene4.mp3","scene13.mp3" ,"scene11.mp3","scene17.mp3" ,"scene17.mp3","scene19.mp3" ,"scene20.wav","scene4.mp3" ,"","" ,"scene3.wav","scene11.mp3","scene2.mp3" };

Scene* ChatScene::createScene()
{
	auto scene = Scene::create();

	auto layer = ChatScene::create();

	scene->addChild(layer);

	return scene;
}

bool ChatScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	m_change = true;

	count++;

	bool anchor;

	auto bg = Sprite::create("bg" + StringUtils::toString(count) + ".jpg");
	bg->setAnchorPoint(Point::ANCHOR_MIDDLE);
	bg->setPosition(VisibleSize.width / 2, VisibleSize.height / 2);
	float winw = VisibleSize.width;
	float winh = VisibleSize.height;
	float spx = bg->getTextureRect().getMaxX();
	float spy = bg->getTextureRect().getMaxY();
	bg->setScaleX(winw / spx);
	bg->setScaleY(winh / spy);
	bg->getTexture()->setAliasTexParameters();
	this->addChild(bg, 0, 1);

	auto itemMusic = Sprite::create("music.png");
	auto menuItemMusic = MenuItemSprite::create(itemMusic, itemMusic, CC_CALLBACK_1(ChatScene::pauseMusic, this));
	menuItemMusic->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuItemMusic->setPosition(Point(VisibleSize) - Point(220, 40));
	menuItemMusic->setScale(0.6f);
	menuItemMusic->setVisible(effect);
	menuItemMusic->setTag(109);

	auto nomusic = Sprite::create("nomusic.png");
	auto menuItemNoMusic = MenuItemSprite::create(nomusic, nomusic, CC_CALLBACK_1(ChatScene::resumeMusic, this));
	menuItemNoMusic->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuItemNoMusic->setPosition(Point(VisibleSize) - Point(220, 40));
	menuItemNoMusic->setScale(0.6f);
	menuItemNoMusic->setVisible(!effect);
	menuItemNoMusic->setTag(110);

	auto pause = Sprite::create("pause.png");
	auto menuItemPause = MenuItemSprite::create(pause, pause, CC_CALLBACK_1(ChatScene::pause, this));
	menuItemPause->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuItemPause->setPosition(Point(VisibleSize) - Point(140, 40));
	menuItemPause->setScale(0.6f);
	menuItemPause->setVisible(true);
	menuItemPause->setTag(111);

	auto resume = Sprite::create("resume.png");
	auto menuItemResume = MenuItemSprite::create(resume, resume, CC_CALLBACK_1(ChatScene::resume, this));
	menuItemResume->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuItemResume->setPosition(Point(VisibleSize) - Point(140, 40));
	menuItemResume->setScale(0.6f);
	menuItemResume->setVisible(false);
	menuItemResume->setTag(112);

	auto restart = Sprite::create("restart.png");
	auto menuItemRestart = MenuItemSprite::create(restart, restart, [](Ref *) {
		count--;

		if (effect)
			SimpleAudioEngine::getInstance()->playBackgroundMusic("sakura.mp3");

		auto scene = WelcomeScene::createScene();
		auto trans = TransitionCrossFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(trans);

		return;
	});
	menuItemRestart->setAnchorPoint(Point::ANCHOR_MIDDLE);
	menuItemRestart->setPosition(Point(VisibleSize) - Point(60, 40));
	menuItemRestart->setScale(0.6f);
	menuItemRestart->setVisible(true);

	tinyxml2::XMLDocument* myDocument = new tinyxml2::XMLDocument();
	myDocument->Parse(FileUtils::getInstance()->getStringFromFile("Scene" + StringUtils::toString(count) + "Dialog.xml").c_str());
	tinyxml2::XMLElement* rootElement = myDocument->RootElement();  //Class SceneContent
	log("%s", rootElement->Name());
	tinyxml2::XMLElement* sceneElement = rootElement->FirstChildElement(("Scene" + StringUtils::toString(count)).c_str());  //Scene1
	talkElement = sceneElement->FirstChildElement("talk");  //talk sentence

	const tinyxml2::XMLAttribute* attributeOfChat = talkElement->FirstAttribute();  //»ñµÃtalkµÄnameÊôÐÔ anchor/icon/name/content

	int intValue;
	if (talkElement->QueryIntAttribute("anchor", &intValue) == tinyxml2::XML_SUCCESS) {
		anchor = intValue;
	}
	else {
		anchor = false;
	}

	icon = talkElement->Attribute("icon");
	log("%s", icon);
	name = talkElement->Attribute("name");
	log("%s", name);
	content = talkElement->Attribute("content");
	log("%s", content);

	Sprite* head;
	Sprite* dialog;
	Sprite* nameDia;
	Sprite* placeDia;

	auto lblIcon = Sprite::create(icon);
	lblIcon->setAnchorPoint(Point::ANCHOR_MIDDLE);
	lblIcon->setScale(1.5f);
	lblIcon->setColor(Color3B::WHITE);
	this->addChild(lblIcon, 99, 90);

	auto lblName = Label::createWithSystemFont(name, "Î¢ÈíÑÅºÚ", 24);
	lblName->setAnchorPoint(Point::ANCHOR_MIDDLE);
	lblName->setColor(Color3B::WHITE);
	this->addChild(lblName, 99, 91);

	auto* chnStrings = Dictionary::createWithContentsOfFile("place.xml");
	const char* str = ((String*)chnStrings->objectForKey("place"+StringUtils::toString(count)))->getCString();

	auto lblPlace = Label::createWithSystemFont(str, "Î¢ÈíÑÅºÚ", 32);
	lblPlace->setAnchorPoint(Point::ANCHOR_MIDDLE);
	lblPlace->setColor(Color3B::WHITE);
	lblPlace->setAlignment(TextHAlignment::CENTER);
	lblPlace->setPosition(110, VisibleSize.height - 40);
	this->addChild(lblPlace, 99, 92);

	auto lblContent = Label::createWithSystemFont(content, "Î¢ÈíÑÅºÚ", 36);
	lblContent->setAnchorPoint(Point::ANCHOR_MIDDLE);
	lblContent->setColor(Color3B::WHITE);
	lblContent->setDimensions(850, 0);
	lblContent->setAlignment(TextHAlignment::CENTER);
	this->addChild(lblContent, 99, 93);

	if (anchor == false)
	{
		head = Sprite::create("bighead1.png");
		head->setPosition(100, 110);

		dialog = Sprite::create("bigdia1.png");
		dialog->setPosition(VisibleSize.width / 2 + 90, 100);

		nameDia = Sprite::create("smalldia1.png");

		placeDia = Sprite::create("smalldia1.png");

	}
	else
	{
		head = Sprite::create("bighead2.png");
		head->setPosition(VisibleSize.width - 100, 110);

		dialog = Sprite::create("bigdia2.png");
		dialog->setPosition(VisibleSize.width / 2 - 90, 100);

		nameDia = Sprite::create("smalldia2.png");

		placeDia = Sprite::create("smalldia2.png");

	}

	head->setAnchorPoint(Point::ANCHOR_MIDDLE);
	dialog->setAnchorPoint(Point::ANCHOR_MIDDLE);
	nameDia->setAnchorPoint(Point::ANCHOR_MIDDLE);
	placeDia->setAnchorPoint(Point::ANCHOR_MIDDLE);

	dialog->setScaleX(1.82f);
	nameDia->setPosition(head->getPositionX(), head->getPositionY() - 60);
	nameDia->setScale(0.5f);
	lblName->setPosition(nameDia->getPosition());
	placeDia->setPosition(lblPlace->getPosition());

	head->getTexture()->setAliasTexParameters();
	dialog->getTexture()->setAliasTexParameters();
	nameDia->getTexture()->setAliasTexParameters();
	placeDia->getTexture()->setAliasTexParameters();

	this->addChild(dialog, 1, 2);
	this->addChild(head, 2, 3);
	this->addChild(nameDia, 98, 4);
	this->addChild(placeDia, 4, 5);

	lblIcon->setPosition(head->getPosition());
	lblContent->setPosition(dialog->getPosition());

	auto menu1 = Menu::create();
	menu1->addChild(menuItemResume);
	menu1->addChild(menuItemPause);
	menu1->addChild(menuItemMusic);
	menu1->addChild(menuItemNoMusic);
	menu1->addChild(menuItemRestart);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1, 99, 110);

	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [=](Touch *touch, Event *event)
	{
		if (m_change)
		{
			if (talkElement->NextSiblingElement())
			{
				talkElement = talkElement->NextSiblingElement();

				icon = talkElement->Attribute("icon");

				if (effect)
					SimpleAudioEngine::getInstance()->playEffect("click.wav");

				bool anchor;
				int intValue;
				if (talkElement->QueryIntAttribute("anchor", &intValue) == tinyxml2::XML_SUCCESS) {
					anchor = intValue;
				}
				else {
					anchor = false;
				}

				auto dialog = (Sprite *)this->getChildByTag(2);
				auto head = (Sprite *)this->getChildByTag(3);
				auto nameDia = (Sprite *)this->getChildByTag(4);
				auto lblIcon = (Sprite *)this->getChildByTag(90);
				auto placeDia = (Sprite*) this->getChildByTag(5);
				auto lblName = (Label *)this->getChildByTag(91);
				auto lblPlace = (Label *)this->getChildByTag(92);
				auto lblContent = (Label *)this->getChildByTag(93);

				head->removeFromParent();
				dialog->removeFromParent();
				nameDia->removeFromParent();
				lblIcon->removeFromParent();
				placeDia->removeFromParent();

				if (anchor == false)
				{
					head = Sprite::create("bighead1.png");
					head->setPosition(100, 110);

					dialog = Sprite::create("bigdia1.png");
					dialog->setPosition(VisibleSize.width / 2 + 90, 100);

					nameDia = Sprite::create("smalldia1.png");

					placeDia = Sprite::create("smalldia1.png");

				}
				else
				{
					head = Sprite::create("bighead2.png");
					head->setPosition(VisibleSize.width - 100, 110);

					dialog = Sprite::create("bigdia2.png");
					dialog->setPosition(VisibleSize.width / 2 - 90, 100);

					nameDia = Sprite::create("smalldia2.png");

					placeDia = Sprite::create("smalldia2.png");

				}

				head->setAnchorPoint(Point::ANCHOR_MIDDLE);
				dialog->setAnchorPoint(Point::ANCHOR_MIDDLE);
				nameDia->setAnchorPoint(Point::ANCHOR_MIDDLE);
				placeDia->setAnchorPoint(Point::ANCHOR_MIDDLE);

				dialog->setScaleX(1.82f);
				nameDia->setPosition(head->getPositionX(), head->getPositionY() - 60);
				nameDia->setScale(0.5f);
				lblName->setPosition(nameDia->getPosition());
				placeDia->setPosition(lblPlace->getPosition());

				head->getTexture()->setAliasTexParameters();
				dialog->getTexture()->setAliasTexParameters();
				nameDia->getTexture()->setAliasTexParameters();
				placeDia->getTexture()->setAliasTexParameters();

				this->addChild(dialog, 1, 2);
				this->addChild(head, 2, 3);
				this->addChild(nameDia, 98, 4);
				this->addChild(placeDia, 4, 5);

				lblIcon = Sprite::create(icon);
				lblIcon->setScale(1.5f);
				lblIcon->setPosition(head->getPosition());
				lblIcon->setAnchorPoint(Point::ANCHOR_MIDDLE);
				lblIcon->setColor(Color3B::WHITE);
				this->addChild(lblIcon, 80, 90);

				name = talkElement->Attribute("name");
				lblName->setString(name);
				content = talkElement->Attribute("content");
				lblContent->setString(content);
				lblContent->setPosition(dialog->getPosition());

			}

			else
			{
				if (count == 3 || count == 6 || count == 10 || count == 14 || count == 18 || count == 20 || count == 23 || count == 24)
				{
				
					auto scene = LoadingScene::createScene();
					auto trans = TransitionCrossFade::create(1.0f, scene);
					Director::getInstance()->replaceScene(trans);

					return true;

				}
				if (count == 26)
				{
					if (effect)
						SimpleAudioEngine::getInstance()->playBackgroundMusic("sakura.mp3", true);

					auto scene = WelcomeScene::createScene();
					auto trans = TransitionCrossFade::create(1.0f, scene);
					Director::getInstance()->replaceScene(trans);

					count = 0;

					return true;
				}
				else
				{
					if (effect)
					{
						SimpleAudioEngine::getInstance()->playEffect("turnpage.wav");
						if (music[count] != "")
							SimpleAudioEngine::getInstance()->playBackgroundMusic(music[count], true);
						/*else
						SimpleAudioEngine::getInstance()->stopBackgroundMusic();*/
					}

					auto scene = ChatScene::createScene();
					auto trans = TransitionPageTurn::create(1.0f, scene, false);
					Director::getInstance()->replaceScene(trans);

					return true;
				}

			}

		}
	};

	listener->onTouchMoved = [=](Touch *touch, Event *event)
	{

	};

	listener->onTouchEnded = [=](Touch *touch, Event *event)
	{

	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	listener->setSwallowTouches(true);

	return true;
}

void ChatScene::update(float dt)
{

}

void ChatScene::pause(Ref *)
{
	if (effect)
		SimpleAudioEngine::getInstance()->playEffect("button.wav");

	auto menu = this->getChildByTag(110);
	auto itemPause = menu->getChildByTag(111);
	auto itemResume = menu->getChildByTag(112);

	itemPause->setVisible(false);
	itemResume->setVisible(true);

	//this->m_canMove = false;
	this->m_change = false;

	//Director::getInstance()->pause();
}

void ChatScene::resume(Ref *)
{
	//SimpleAudioEngine::getInstance()->playEffect("button.mp3");
	if (effect)
		SimpleAudioEngine::getInstance()->playEffect("button.wav");

	auto menu = this->getChildByTag(110);
	auto itemPause = menu->getChildByTag(111);
	auto itemResume = menu->getChildByTag(112);

	itemPause->setVisible(true);
	itemResume->setVisible(false);

	//this->m_canMove = true;
	this->m_change = true;

	Director::getInstance()->resume();
}

void ChatScene::pauseMusic(Ref *)
{
	//SimpleAudioEngine::getInstance()->playEffect("button.mp3");
	if (effect)
		SimpleAudioEngine::getInstance()->playEffect("button.wav");

	auto menu = this->getChildByTag(110);
	auto itemMusic = menu->getChildByTag(109);
	auto itemNoMusic = menu->getChildByTag(110);

	itemMusic->setVisible(false);
	itemNoMusic->setVisible(true);

	SimpleAudioEngine::getInstance()->stopAllEffects();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	effect = false;
}

void ChatScene::resumeMusic(Ref *)
{
	//SimpleAudioEngine::getInstance()->playEffect("button.mp3");
	if (effect)
		SimpleAudioEngine::getInstance()->playEffect("button.wav");

	auto menu = this->getChildByTag(110);
	auto itemMusic = menu->getChildByTag(109);
	auto itemNoMusic = menu->getChildByTag(110);

	itemMusic->setVisible(true);
	itemNoMusic->setVisible(false);

	SimpleAudioEngine::getInstance()->resumeAllEffects();
	if (music[count - 1] != "")
		SimpleAudioEngine::getInstance()->playBackgroundMusic(music[count - 1], true);

	effect = true;
}