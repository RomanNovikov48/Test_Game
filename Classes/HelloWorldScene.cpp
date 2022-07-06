#include "HelloWorldScene.h"

USING_NS_CC; // макрос использования пространства имён cocos2d::


Scene* HelloWorld::createScene()
{
	// все указатели, которые порождает Cocos - 2dx уже находятся под контролем выделенной памяти. Поэтому они не требуют явного удаления через delete или обертки в интеллектуальный указатель
	auto scene = Scene::create(); // создаем сцену
	auto layer = HelloWorld::create(); // создаем слой сцены

	scene->addChild(layer); // добавляем слой как ребенка на сцену


	return scene;
}



bool HelloWorld::init()
{
	if (!Layer::init()) // если мы не можем проинициализировать - просто выходим
	{
		return false;
	}


	//auto label = Label::createWithSystemFont("Hello Cocos 2dx", "Arial", 48); // создаем метку для вывода текста. 
	Vec2 origin = Director::getInstance()->getVisibleOrigin(); // получаем вектор смещения, для рисования на разных координатах
		
	
	//label->setPosition(cocos2d::Vec2(400, 230)); // рисуем по заданным координатам. По - умолчанию у всех компонентов Cocos - 2dx точка отрисовки находится в середине, не слева сверху!
	//this->addChild(label, 1);
	// наконец добавляем метку как ребенка. второй параметр - это z - последовательность
	
	
	this->scheduleUpdate();
	
	
	auto touchListener = EventListenerTouchOneByOne::create();


	touchListener->onTouchEnded = [this](Touch* _touch, Event* event) {
		onTouchEnded(_touch, event);
	};
	touchListener->onTouchMoved = [this](Touch* _touch, Event* event) {
		onTouchMoved(_touch, event);
	};
	touchListener->onTouchBegan = [this](Touch* _touch, Event* event)-> bool {
		return onTouchBegan(_touch, event);
	};
	touchListener->onTouchCancelled = [this](Touch* _touch, Event* event) {
		onTouchCancelled(_touch, event);
	};

	 // вторым параметром указывается контрол, принимающий этот ввод


	return true;
}

void HelloWorld::update(float delta)
{
	time += delta;
	if (time >= 1.f)
	{
		removeAllChildren();

		int rnd = rand() % 11;

		Sprite* exp = Sprite::create("character" + std::to_string(rnd) + ".png");
		this->addChild(exp, 0);

		int x = rand() % 400 + 10;
		int y = rand() % 400 + 20;

		exp->setPosition(Vec2(x, y));

		auto label = Label::createWithSystemFont("character" + std::to_string(rnd) + ".png" + " x:" + std::to_string(x) + " y:" + std::to_string(y), "Arial", 20);
		label->setPosition(Vec2(150, 13));
		this->addChild(label, 0);

		time = 0.f;
	}
}
