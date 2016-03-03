#include "SceneMgr.h"
#include "../Scene/HelloWorldScene.h"
SceneMgr::SceneMgr()
{
}

SceneMgr::~SceneMgr()
{
}

 void SceneMgr::ReplaceScene(SceneType type)
{
	switch (type)
	{
	case Title:
		Director::getInstance()->replaceScene(HelloWorld::createScene());
		break;
	case Menu:
		Director::getInstance()->replaceScene(HelloWorld::createScene());
		break;
	case Game:
		Director::getInstance()->replaceScene(HelloWorld::createScene());
		break;
	default:
		//error
		break;
	}
}