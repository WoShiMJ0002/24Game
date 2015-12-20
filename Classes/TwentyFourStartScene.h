#pragma once

#include "cocos2d.h"

using namespace cocos2d;

//宏定义（可以定义一些常量，可以简化代码）
#define MAIN_WIDTH (640)
#define TOTAL_NUMBER_COUNTS (9)     //slot 数字精灵的个数
#define TOTAL_SHAPE_COUNTS (4)      //slot 形状精灵的个数
#define SLOT_OFFSET (20)            //slot 精灵每次的位移量（精灵大小为60 * 60）
#define COVER_OPACITY (255 * 0.9)   //slot 模拟阴影的透明度

class TwentyFourStartScene : public cocos2d::Layer
{
public:
	
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TwentyFourStartScene);

	//********************* Functions *************************//
	void ButtonChooseSwitch(Ref* pSender);
	
	//初始化旋转盒
	void initSlotMachine(Size winSize);

	//每一帧更新
	void update(float dt);


	//********************* Parameters *************************//
	bool isChoosButtonStatus = true;   // true - Start ; false - Stop

	//三个参数的初始值
	int displayNum = 1;
	int displaySize = 30;
	int displayShape = 1;

	//基础点(水果机窗口的位置、shape、size和number的初始位置)
	Point slotFramePoint;
	Point shapeAreaPoint;
	Point sizeAreaPoint;
	Point numberAreaPoint;

	//控制运动速度的参数(将每秒60帧转换为每秒执行几次)
	int NumSpeedFrame = 1;         //刷新的帧数，即每多少帧改变一次Sprite的位置
	int NumTurnningCounter = 1;    //计数器，每一帧加1

	int ShapeSpeedFrame = 2;
	int ShapeTurnningCounter = 1;

	int SizeSpeedFrame = 1;
	int SizeTurnningCounter = 1;

	//老虎机滚筒的结果
	int numResult;
	int shapeResult;
	int sizeResult;

	//控制滚筒滚动的参数
	bool isSlotTurnning = false;
};
