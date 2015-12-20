#include "TwentyFourStartScene.h"
#include "CCDrawNode.h"

USING_NS_CC;
using namespace ui;
using namespace cocos2d;
using namespace std;



Scene* TwentyFourStartScene::createScene() {

	auto scene = Scene::create();

	auto layer = TwentyFourStartScene::create();

	scene->addChild(layer);

	return scene;
}

bool TwentyFourStartScene::init() {

	if (!Layer::init()) {
		return false;
	}
	
	auto winSize = Director::getInstance()->getVisibleSize();

	//******** Choose Button Start ********//
	auto MenuItemButStart = MenuItemImage::create("BeginNormal.png", "BeginSelected.png");
	auto MenuItemButStop = MenuItemImage::create("StopNormal.png", "StopSelected.png");

	MenuItemToggle* ChooseButtonToggle;

	if (isChoosButtonStatus) {
		ChooseButtonToggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(TwentyFourStartScene::ButtonChooseSwitch, this), MenuItemButStart, MenuItemButStop, NULL);
	}
	else {
		ChooseButtonToggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(TwentyFourStartScene::ButtonChooseSwitch, this), MenuItemButStop, MenuItemButStart, NULL);
	}

	auto ChooseButtonMenu = Menu::create(ChooseButtonToggle, NULL);
	ChooseButtonMenu->setAnchorPoint(ccp(0.5, 0.5));
	ChooseButtonMenu->setPosition(Point(winSize.width / 2, winSize.height / 4));
	this->addChild(ChooseButtonMenu);
	//******** Choose Button End ********//

	//******** Choose Shape, Size, inital number Start ********//
	//auto md = DrawNode::create();
	//this->addChild(md);
	//md->drawCircle(Point(winSize.width / 2, (winSize.height / 4) * 3), 100.0f, 1, 720, false, Color4F::YELLOW);

	initSlotMachine(winSize);
	
	//******** Choose Shape, Size, inital number End ********//

	//******** Enable Schedule Start ********//
	this->scheduleUpdate();

	//******** Enable Schedule End ********//

	return true;

}



void TwentyFourStartScene::ButtonChooseSwitch(Ref* pSender) {

	if (isChoosButtonStatus) {

		isChoosButtonStatus = false;
		UserDefault::getInstance()->setBoolForKey("isChoosButtonStatus", false);

	}
	else {

		isChoosButtonStatus = true;
		UserDefault::getInstance()->setBoolForKey("isChoosButtonStatus", true);

	}

	
}

void TwentyFourStartScene::initSlotMachine(Size winSize) {

	//Background
	auto slotFrame = Sprite::create("slot_frame.png");
	auto slotFrameCover = Sprite::create("Slot_Bg_Cover.png");
	//Display Area
	auto shapeArea = Sprite::create("Display_frame2.png");
	auto sizeArea = Sprite::create("Display_frame2.png");
	auto numberArea = Sprite::create("Display_frame2.png");
	//Display Background
	auto shapeAreaBg = Sprite::create("Display_Area.png");
	auto sizeAreaBg = Sprite::create("Display_Area.png");
	auto numAreaBg = Sprite::create("Display_Area.png");
	//Display Cover
	auto shapeAreaCoverUp = Sprite::create("CoverUp.png");
	auto sizeAreaCoverUp = Sprite::create("CoverUp.png");
	auto numberAreaCoverUp = Sprite::create("CoverUp.png");
	auto shapeAreaCoverDown = Sprite::create("CoverDown.png");
	auto sizeAreaCoverDown = Sprite::create("CoverDown.png");
	auto numberAreaCoverDown = Sprite::create("CoverDown.png");

	slotFrame->setName("slotFrame");
	slotFrameCover->setName("Slot_Bg_Cover");
	shapeArea->setName("shapeArea");
	sizeArea->setName("sizeArea");
	numberArea->setName("numberArea");

	slotFramePoint = Point(winSize.width / 2, (winSize.height / 4) * 3);
	shapeAreaPoint = Point(slotFramePoint.x - (shapeArea->getContentSize().width * 1.5), slotFramePoint.y);
	sizeAreaPoint = slotFramePoint;
	numberAreaPoint = Point(slotFramePoint.x + (numberArea->getContentSize().width * 1.5),slotFramePoint.y);
		
	slotFrame->setAnchorPoint(ccp(0.5, 0.5));
	slotFrame->setPosition(slotFramePoint);
	this->addChild(slotFrame);
		
	shapeArea->setAnchorPoint(ccp(0.5, 0.5));
	shapeArea->setPosition(shapeAreaPoint);	

	sizeArea->setAnchorPoint(ccp(0.5, 0.5));
	sizeArea->setPosition(sizeAreaPoint);	

	numberArea->setAnchorPoint(ccp(0.5, 0.5));
	numberArea->setPosition(numberAreaPoint);

	//Display Area Cover
	shapeAreaCoverUp->setAnchorPoint(Point(0.5,0.5));
	sizeAreaCoverUp->setAnchorPoint(ccp(0.5, 0.5));
	numberAreaCoverUp->setAnchorPoint(Point(0.5, 0.5));
	shapeAreaCoverDown->setAnchorPoint(Point(0.5, 0.5));
	sizeAreaCoverDown->setAnchorPoint(ccp(0.5, 0.5));
	numberAreaCoverDown->setAnchorPoint(Point(0.5, 0.5));
	
	shapeAreaCoverUp->setPosition(Point(shapeAreaPoint.x, shapeAreaPoint.y + shapeAreaCoverUp->getContentSize().height * 1.5));
	sizeAreaCoverUp->setPosition(Point(sizeAreaPoint.x, sizeAreaPoint.y + sizeAreaCoverUp->getContentSize().height * 1.5));
	numberAreaCoverUp->setPosition(Point(numberAreaPoint.x, numberAreaPoint.y + numberAreaCoverUp->getContentSize().height * 1.5));
	shapeAreaCoverDown->setPosition(Point(shapeAreaPoint.x, shapeAreaPoint.y - shapeAreaCoverDown->getContentSize().height * 1.5));
	sizeAreaCoverDown->setPosition(Point(sizeAreaPoint.x, sizeAreaPoint.y - sizeAreaCoverDown->getContentSize().height * 1.5));
	numberAreaCoverDown->setPosition(Point(numberAreaPoint.x, numberAreaPoint.y - numberAreaCoverDown->getContentSize().height * 1.5));

	shapeAreaCoverUp->setOpacity(COVER_OPACITY);
	sizeAreaCoverUp->setOpacity(COVER_OPACITY);
	numberAreaCoverUp->setOpacity(COVER_OPACITY);
	shapeAreaCoverDown->setOpacity(COVER_OPACITY);
	sizeAreaCoverDown->setOpacity(COVER_OPACITY);
	numberAreaCoverDown->setOpacity(COVER_OPACITY);

	//Display Area Bg
	shapeAreaBg->setAnchorPoint(Point(0.5, 0.5));
	sizeAreaBg->setAnchorPoint(Point(0.5, 0.5));
	numAreaBg->setAnchorPoint(Point(0.5, 0.5));

	shapeAreaBg->setPosition(shapeAreaPoint);
	sizeAreaBg->setPosition(sizeAreaPoint);
	numAreaBg->setPosition(numberAreaPoint);

	this->addChild(shapeAreaBg);
	this->addChild(sizeAreaBg);
	this->addChild(numAreaBg);

	//**** Initial Numbers Begin ****//
	for (int i = 1; i <= TOTAL_NUMBER_COUNTS; i++) {

		CCString* numImg = CCString::createWithFormat("num%d.png",i);
		CCString* numSpriteName = CCString::createWithFormat("num%d", i);

		auto numSp = Sprite::create(numImg->getCString());
		numSp->setName(numSpriteName->getCString());
		numSp->setAnchorPoint(ccp(0.5, 0.5));
		
		this->addChild(numSp);

		//滚动的效果初始化
		if (i != TOTAL_NUMBER_COUNTS) {
			numSp->setPosition(Point(numberAreaPoint.x, numberAreaPoint.y + (i - 1) * numSp->getContentSize().height));

			if (i > 2) {
				numSp->setVisible(false);
			}

		}
		else {
			numSp->setPosition(Point(numberAreaPoint.x, numberAreaPoint.y - 1 * numSp->getContentSize().height));
		}
		
	}
	//**** Initial Numbers End ****//

	//**** Initial Shapes Begin ****//
	for (int iShape = 1; iShape <= TOTAL_SHAPE_COUNTS; iShape++) {

		//shape1 = circle; shape2 = Six-Sides; shape3 = Square;
		CCString* shapeImg = CCString::createWithFormat("shape%d.png",iShape);
		CCString* shapeName = CCString::createWithFormat("shape%d.png", iShape);

		auto shapeSp = Sprite::create(shapeImg->getCString());
		shapeSp->setName(shapeName->getCString());
		shapeSp->setAnchorPoint(Point(0.5, 0.5));
		this->addChild(shapeSp);
		
		if (iShape != TOTAL_SHAPE_COUNTS) {

			shapeSp->setPosition(Point(shapeAreaPoint.x, shapeAreaPoint.y + (iShape - 1) * shapeSp->getContentSize().height));
			
			if (iShape > 2) {
				shapeSp->setVisible(false);
			}

		}
		else {
			shapeSp->setPosition(Point(shapeAreaPoint.x, shapeAreaPoint.y - 1 * shapeSp->getContentSize().height));
		}

	}

	//**** Initial Shapes End ****//
	
	
	slotFrameCover->setAnchorPoint(ccp(0.5, 0.5));
	slotFrameCover->setPosition(slotFramePoint);
	this->addChild(slotFrameCover);

	//半透明Cover
	this->addChild(shapeAreaCoverUp);
	this->addChild(sizeAreaCoverUp);
	this->addChild(numberAreaCoverUp);
	this->addChild(shapeAreaCoverDown);
	this->addChild(sizeAreaCoverDown);
	this->addChild(numberAreaCoverDown);

	this->addChild(shapeArea);
	this->addChild(sizeArea);
	this->addChild(numberArea);

	
}


void TwentyFourStartScene::update(float dt) {

	if (isSlotTurnning) {
		//******** number滚动效果 Begin ********//
		if (NumTurnningCounter <= NumSpeedFrame) {
			NumTurnningCounter++;
		}
		else {

			for (int i = 1; i <= TOTAL_NUMBER_COUNTS; i++) {

				CCString* numSpName = CCString::createWithFormat("num%d", i);
				auto numCurPos = this->getChildByName(numSpName->getCString())->getPosition();

				if (numCurPos.y - SLOT_OFFSET < numberAreaPoint.y - (this->getChildByName(numSpName->getCString())->getContentSize().height * 1.5)) {

					this->getChildByName(numSpName->getCString())->setPosition(Point(numCurPos.x, numberAreaPoint.y + this->getChildByName(numSpName->getCString())->getContentSize().height * (TOTAL_NUMBER_COUNTS - 2 + 0.5) - SLOT_OFFSET));
					this->getChildByName(numSpName->getCString())->setVisible(false);

				}
				else {
					this->getChildByName(numSpName->getCString())->setPosition(Point(numCurPos.x, numCurPos.y - SLOT_OFFSET));

					if (numCurPos.y < numberAreaPoint.y + (this->getChildByName(numSpName->getCString())->getContentSize().height * 1.5)) {

						this->getChildByName(numSpName->getCString())->setVisible(true);

					}
				}

			}

			NumTurnningCounter = 1;

		}
		//******** number滚动效果 End ********//

		//******** shape 滚动效果 Begin ********//
		if (ShapeTurnningCounter <= ShapeSpeedFrame) {
			ShapeTurnningCounter++;
		}
		else {

			for (int iShape = 1; iShape <= TOTAL_SHAPE_COUNTS; iShape++) {

				CCString* shapeSpName = CCString::createWithFormat("shape%d.png", iShape);
				auto shapeCurPoint = this->getChildByName(shapeSpName->getCString())->getPosition();

				//超出下限的位置后，怎转到最上层，重新开始循环
				if (shapeCurPoint.y - SLOT_OFFSET < shapeAreaPoint.y - (this->getChildByName(shapeSpName->getCString())->getContentSize().height * 1.5)) {
					this->getChildByName(shapeSpName->getCString())->setPosition(Point(shapeCurPoint.x, shapeAreaPoint.y + this->getChildByName(shapeSpName->getCString())->getContentSize().height * (TOTAL_SHAPE_COUNTS - 2 + 0.5) - SLOT_OFFSET));
					this->getChildByName(shapeSpName->getCString())->setVisible(false);
				}
				else {

					this->getChildByName(shapeSpName->getCString())->setPosition(Point(shapeCurPoint.x, shapeCurPoint.y - SLOT_OFFSET));

					if (shapeCurPoint.y < shapeAreaPoint.y + (this->getChildByName(shapeSpName->getCString())->getContentSize().height * 1.5)) {

						this->getChildByName(shapeSpName->getCString())->setVisible(true);

					}

				}

			}

			ShapeTurnningCounter = 1;
		}

		//******** shape 滚动效果 End ********//
	}

	
}