#include "ProgressView.h";

using namespace cocos2d;

ProgressView::ProgressView()
	:progressBack(NULL)
	, progressFore(NULL)
	, totalProgress(0.0f)
	, currentProgress(0.0f)
	, scale(1.0f)
{

}

void ProgressView::setBackground(const char* pName)
{
	progressBack = Sprite::create(pName);
	this->addChild(progressBack);
}

void ProgressView::setForeground(const char* pName)
{
	progressFore = Sprite::create(pName);
	progressFore->setAnchorPoint(Vec2(0.0f, 0.5f));
	progressFore->setPosition(-progressFore->getContentSize().width / 2, 0);
	this->addChild(progressFore);
}

void ProgressView::setTotalProgress(float total)
{
	if (progressFore == NULL)
	{
		return;
	}
	scale = progressFore->getContentSize().width / total;
	totalProgress = total;
}

void ProgressView::setCurrentProgress(float progress)
{
	if (progressFore == NULL)
	{
		return;
	}
	if (progress < 0.0f)
	{
		progress = 0.0f;
	}
	if (progress > totalProgress)
	{
		progress = totalProgress;
	}
	currentProgress = progress;
	float rectWidth = progress * scale;
	const Point from = progressFore->getTextureRect().origin;
	const Rect rect = CCRectMake(from.x, from.y, rectWidth, progressFore->getContentSize().height);
	setForegroundRect(rect);
}

void ProgressView::setForegroundRect(const Rect &rect)
{
	progressFore->setTextureRect(rect);
}

float ProgressView::getCurrentProgress() const
{
	return currentProgress;
}

float ProgressView::getTotalProgress() const
{
	return totalProgress;
}