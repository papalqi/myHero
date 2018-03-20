#pragma once
#include "cocos2d.h";

using namespace cocos2d;

class ProgressView : public Node
{
public:
	ProgressView();

	/*设置血条背景*/
	void setBackground(const char* pName);

	/*设置血条前景*/
	void setForeground(const char* pName);

	/*设置总血量*/
	void setTotalProgress(float total);

	/*设置当前血量*/
	void setCurrentProgress(float progress);

	/*得到总血量*/
	float getTotalProgress() const;

	/*得到当前血量*/
	float getCurrentProgress() const;

private:
	void setForegroundRect(const Rect &rect);

	/*背景血条*/
	Sprite* progressBack;

	/*前景血条*/
	Sprite* progressFore;

	/*总血量*/
	float totalProgress;

	/*当前血量*/
	float currentProgress;

	/*放大倍数*/
	float scale;
};