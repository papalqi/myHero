#pragma once

#include "cocos2d.h"
#include "CommonData.h"
#include "HelloWorldScene.h"
#include "WelcomeScene.h"
#include "SimpleAudioEngine.h"
#include "LoadingScene.h"
#include "tinyxml2\tinyxml2.h"

using namespace CocosDenshion;

class ChatScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void update(float dt);
	
	CREATE_FUNC(ChatScene);

private:
	tinyxml2::XMLElement* talkElement;

	const char* icon;
	const char* name;
	const char* content;

	char* FontToUTF8(const char* font);

	bool m_change;

	void pause(Ref *);
	void resume(Ref *);
	void resumeMusic(Ref *);
	void pauseMusic(Ref *);
};