#pragma once
#include "cocos2d.h"
#include<strstream>
#include"SimpleAudioEngine.h"
using namespace cocos2d;
/*请确保动画帧是在plist里，并且是从0开始的，中间没有间断
*/
void createAndAddAnimation(int number,std::string pngName, std::string animationName)
{
	auto animation = Animation::create();
	
	for (int i = 0; i < number; i++)
	{
		if (i <= 9)
		{
			std::strstream s;std::string ss;	s << i;	s >> ss;
			std::string temp = pngName +  "0"+ ss + ".png" ;
			auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);

			animation->addSpriteFrame(spriteFrame);
		}
		else
		{
			std::strstream s; std::string ss;	s << i;	s >> ss;
			std::string temp = pngName  + ss + ".png";
			auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);

			animation->addSpriteFrame(spriteFrame);
		}
	}

	AnimationCache::getInstance()->addAnimation(animation, animationName);
}
void createAndAddAnimation1(int start,int number, std::string pngName, std::string animationName)
{
	auto animation = Animation::create();

	for (int i = start; i < number; i++)
	{
		if (i <= 9)
		{
			std::strstream s; std::string ss;	s << i;	s >> ss;
			std::string temp = pngName + "0" + ss + ".png";
			auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);

			animation->addSpriteFrame(spriteFrame);
		}
		else
		{
			std::strstream s; std::string ss;	s << i;	s >> ss;
			std::string temp = pngName + ss + ".png";
			auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);

			animation->addSpriteFrame(spriteFrame);
		}
	}

	AnimationCache::getInstance()->addAnimation(animation, animationName);
}


void loadPlist()
{
	/*添加必须的plist*/
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Lianguan.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("girl.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("walk.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("rolling.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("softMudHurt.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("consciousflip.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("punch.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heavykick.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("xizi_hurt.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("zetianHurt.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("softMud_scorpion.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("softMud_stab.plist"); 
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wutian_sword.plist");

}


void loadzetian()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("zetian-fall.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("zetian-poke.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("zetian-run.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("zetian-stab2.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("zetian-ordinaryhit.plist");
	createAndAddAnimation(7, "bc252_", "zetian-ordinaryhit");
	createAndAddAnimation(5, "bc070_", "zetian-fall");
	createAndAddAnimation(12, "bc401_", "zetian-poke");
	createAndAddAnimation(9, "bc032_", "zetian-run");
	createAndAddAnimation(19, "bc450_", "zetian-stab");
	
}
void createAndAddAn()
{

	/*创建必要的动画，并且把它放在AnimationCache里
	已经单独创建一个函数实现，在OurFunction里面。
	*/
	createAndAddAnimation(16, "ar070_", "monsterMove");
	createAndAddAnimation(16, "ar070_", "monsterAttack");
	createAndAddAnimation(16, "lc030_", "heroMove");
	createAndAddAnimation(22, "lc601_", "heroAttack");
	createAndAddAnimation(10, "ar110_", "monsterRolling");
	createAndAddAnimation(8, "ar312_", "softMudHurt");
	createAndAddAnimation(2, "lc409_", "consciousflip");
	createAndAddAnimation1(4, 17, "lc404_", "punch");
	createAndAddAnimation1(2,12, "lc311_", "heavykick");
	createAndAddAnimation(3, "lc620_", "xiziHurt"); 
	createAndAddAnimation(6, "ar200_", "softMud_stab");
	createAndAddAnimation(5, "bc063_", "zetianHurt");
	createAndAddAnimation(20, "ar233_", "softMud_scorpion");
	createAndAddAnimation1(1,17, "ha232_", "wutian_sword");
}

void loadQianye()
{
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("qianye_fall.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("qianYeRun.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("qianye_stab.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("qianYeHurt.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("qianye_fan.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("qianye_fancleave.plist"); 
	createAndAddAnimation( 12, "yu077_", "qianye_fall");
	createAndAddAnimation1(1,11, "yu032_", "qianYeRun");
	createAndAddAnimation(5, "yu251_", "qianye_stab");
	createAndAddAnimation(3, "yu050_", "qianYeHurt");
	createAndAddAnimation(12, "yu210_", "qianye_fan");
	createAndAddAnimation(10, "yu211_", "qianye_fancleave");

}
void loadMusic()
{
	using namespace CocosDenshion;
	//预加载背景音乐
	
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("fei.mp3");
	SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);

	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.3f);
	SimpleAudioEngine::getInstance()->setEffectsVolume(0.9f);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("fei.mp3", true);
	//SimpleAudioEngine::sharedEngine()->playEffect();


}
void loadWuTian()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wuTianFall.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wutian_heavyhit.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wutian_hurt.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wutian_kick.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wutian_ordinaryhit.plist");
	createAndAddAnimation(14, "ha060_", "wuTianFall");
	createAndAddAnimation1(1,20, "ha203_", "wutian_heavyhit");
	createAndAddAnimation1(2,4, "ha050_", "wutian_hurt");
	createAndAddAnimation1(1,10, "ha201_", "wutian_kick");
	createAndAddAnimation(8, "ha112_", "wutian_ordinaryhit");
}
void createControl()
{
	loadPlist();
	loadQianye();
	createAndAddAn();
	loadzetian();
	//loadXizi();
	loadWuTian();
	loadMusic();
}
