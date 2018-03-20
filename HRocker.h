#pragma once
#include "cocos2d.h"
using namespace cocos2d;

//���ڱ�ʶҡ����ҡ�˵ı���
typedef enum {
	tag_rocker,
	tag_rockerBG,
}tagForHRocker;
//���ڱ�ʶҡ�˷���
typedef enum {
	rocker_stay,
	rocker_right,
	rocker_up,
	rocker_left,
	rocker_down,
}tagDirecton;

class HRocker :public Layer
{
public:
	HRocker(void);
	~HRocker(void);

	//����ҡ��(ҡ�˵Ĳ�����ͼƬ��Դ����ҡ�˱���ͼƬ��Դ������ʼ����)
	static HRocker* createHRocker(const char *rockerImageName, const char *rockerBGImageName, Point position);
	//����ҡ��(��ʾҡ�ˡ�����ҡ�˴����¼�)
	void startRocker(bool _isStopOther);
	//ֹͣҡ��(����ҡ�ˣ�ȡ��ҡ�˵Ĵ�������)
	void stopRocker();
	//�жϿ��Ƹ˷��������жϾ����ϡ��¡������˶�
	int rocketDirection;
	//��ǰ�������߷���,�����жϾ���ĳ��򣬾��������һ��ǳ���
	bool rocketRun;
	CREATE_FUNC(HRocker);
private:
	//�Զ����ʼ������
	void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);
	//�Ƿ�ɲ���ҡ��
	bool isCanMove;
	//��ȡ��ǰҡ�����û�������ĽǶ�
	float getRad(Point pos1, Point pos2);
	//ҡ�˱���������
	Point rockerBGPosition;
	//ҡ�˱����İ뾶
	float rockerBGR;

	void onEnter();
	void onExit();
	//�����¼�
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

};

