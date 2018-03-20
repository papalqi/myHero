#pragma once

#include "cocos2d.h"
#include "CommonData.h"
#include "ChatScene.h"

class WelcomeScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void update(float dt);

	CREATE_FUNC(WelcomeScene);

private:
	bool change;
	
	void createSakura(float);

	void actor1In(float);

	void actor2In(float);

	void actor3In(float);

};