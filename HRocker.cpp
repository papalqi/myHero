#include "HRocker.h"
const double PI = 3.1415;
HRocker::HRocker(void)
{
	rocketRun = true;
}

HRocker::~HRocker(void)
{
}

//����ҡ��(ҡ�˵Ĳ�����ͼƬ��Դ����ҡ�˱���ͼƬ��Դ������ʼ����)
HRocker* HRocker::createHRocker(const char *rockerImageName, const char *rockerBGImageName, Point position)
{
	HRocker *layer = HRocker::create();
	if (layer)
	{
		layer->rockerInit(rockerImageName, rockerBGImageName, position);
		return layer;
	}
	layer->setColor(Color3B(100,100,120));
	layer->setPosition(0,0);
	CC_SAFE_DELETE(layer);
	return NULL;
}

//�Զ����ʼ������
void HRocker::rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position)
{
	Sprite *spRockerBG = Sprite::create(rockerBGImageName);
	spRockerBG->setPosition(position);
	spRockerBG->setScale(0.8);
	spRockerBG->setVisible(false);
	addChild(spRockerBG, 0, tag_rockerBG);

	Sprite *spRocker = Sprite::create(rockerImageName);
	spRocker->setPosition(position);
	spRocker->setScale(0.8);
	spRocker->setVisible(false);
	addChild(spRocker, 1, tag_rocker);

	rockerBGPosition = position;
	rockerBGR = spRockerBG->getContentSize().width*0.5;//
	rocketDirection = -1;//��ʾҡ�˷��򲻱�
}

//����ҡ��(��ʾҡ�ˡ�����ҡ�˴����¼�)
void HRocker::startRocker(bool _isStopOther)
{
	Sprite *rocker = (Sprite*)this->getChildByTag(tag_rocker);
	rocker->setVisible(true);

	Sprite *rockerBG = (Sprite *)this->getChildByTag(tag_rockerBG);
	rockerBG->setVisible(true);

	onEnter();
}

//ֹͣҡ��(����ҡ�ˣ�ȡ��ҡ�˵Ĵ�������)
void HRocker::stopRocker()
{
	Sprite *rocker = (Sprite *)this->getChildByTag(tag_rocker);
	rocker->setVisible(false);

	Sprite * rockerBG = (Sprite *)this->getChildByTag(tag_rockerBG);
	rockerBG->setVisible(false);
	onExit();
	
}

void HRocker::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2( HRocker::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(HRocker::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HRocker::onTouchEnded, this);
	auto * eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

}
void HRocker::onExit()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();


}

//��ȡ��ǰҡ�����û�������ĽǶ�
float HRocker::getRad(Point pos1, Point pos2)
{
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;

	//�õ�����x�ľ���
	float x = px2 - px1;
	//�õ�����y�ľ���
	float y = py1 - py2;
	//���б�߳���
	float xie = sqrt(pow(x, 2) + pow(y, 2));
	//�õ�����Ƕȵ�����ֵ(ͨ�����Ǻ����еĵ���Ƕ�����ֵ=б��/б��)
	float cosAngle = x / xie;
	//ͨ�������Ҷ����ȡ���ڽǶȵĻ���
	float rad = acos(cosAngle);
	//ע�⣺��������λ��Y����<ҡ�˵�Y���꣬����Ҫȥ��ֵ-0~-180
	if (py2 < py1)
	{
		rad = -rad;
	}
	return rad;
}

Point getAngelePosition(float r, float angle) {
	return ccp(r*cos(angle), r*sin(angle));
}

//̧���¼�
bool HRocker::onTouchBegan(Touch *pTouch, Event *pEvent)
{

	Point point = pTouch->getLocation();
	
	auto *rocker = this->getChildByTag(tag_rocker);

	auto tWidth = rocker->getContentSize().height;
	log(tWidth);
	if (ccpDistance(rockerBGPosition,point)<100)
	{
		log("jinlaile");
		isCanMove = true;
		
		return true;
	}
		
	return false;
}
//�ƶ��¼�
void HRocker::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	
	log("  sa");
	Point point = pTouch->getLocation();
	Sprite *rocker = (Sprite *)this->getChildByTag(tag_rocker);
	//�õ�ҡ���봥�������γɵĽǶ�
	float angle = getRad(rockerBGPosition, point);
	//�ж�����Բ��Բ�ľ��Ƿ����ҡ�˱����İ뾶
	if (sqrt(pow((rockerBGPosition.x - point.x), 2) + pow((rockerBGPosition.y - point.y), 2)) >= rockerBGR)
	{

		//��֤�ڲ�СԲ�˶��ĳ�������
		rocker->setPosition(ccpAdd(getAngelePosition(rockerBGR, angle), ccp(rockerBGPosition.x, rockerBGPosition.y)));
	}
	else
		rocker->setPosition(point);
	//�жϷ���
	if (angle >= -PI / 4 && angle<PI / 4)
	{
		rocketDirection = rocker_right;
		rocketRun = true;
	}
	else if (angle >= PI / 4 && angle<3 * PI / 4)
	{
		rocketDirection = rocker_up;
	}
	else if ((angle >= 3 * PI / 4 && angle <= PI) || (angle >= -PI&&angle<-3 * PI / 4))
	{
		rocketDirection = rocker_left;
		rocketRun = false;
	}
	else if (angle >= -3 * PI / 4 && angle<-PI / 4)
	{
		rocketDirection = rocker_down;
	}
}
//�뿪�¼�
void HRocker::onTouchEnded(Touch *pTouch, Event *pEvent)
{

	Sprite *rockerBG = (Sprite*)this->getChildByTag(tag_rockerBG);
	Sprite *rocker = (Sprite*)this->getChildByTag(tag_rocker);
	rocker->stopAllActions();
	rocker->runAction(MoveTo::create(0.08f, rockerBG->getPosition()));
	isCanMove = false;
	rocketDirection = rocker_stay;
}
