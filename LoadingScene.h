#pragma once

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "WelcomeScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

class LoadingScene :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void update(float dt);

	CREATE_FUNC(LoadingScene);

private:

	void light1(float);

	void light2(float);

	void light3(float);

	void toFight(float);

	char* FontToUTF8(const char* font);
};