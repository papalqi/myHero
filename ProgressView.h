#pragma once
#include "cocos2d.h";

using namespace cocos2d;

class ProgressView : public Node
{
public:
	ProgressView();

	/*����Ѫ������*/
	void setBackground(const char* pName);

	/*����Ѫ��ǰ��*/
	void setForeground(const char* pName);

	/*������Ѫ��*/
	void setTotalProgress(float total);

	/*���õ�ǰѪ��*/
	void setCurrentProgress(float progress);

	/*�õ���Ѫ��*/
	float getTotalProgress() const;

	/*�õ���ǰѪ��*/
	float getCurrentProgress() const;

private:
	void setForegroundRect(const Rect &rect);

	/*����Ѫ��*/
	Sprite* progressBack;

	/*ǰ��Ѫ��*/
	Sprite* progressFore;

	/*��Ѫ��*/
	float totalProgress;

	/*��ǰѪ��*/
	float currentProgress;

	/*�Ŵ���*/
	float scale;
};