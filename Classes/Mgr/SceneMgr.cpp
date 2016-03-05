#include "SceneMgr.hpp"
#include "../Scene/HelloWorldScene.hpp"

 void SceneMgr::ReplaceScene(SceneType type)
{
	switch (type)
	{
	case Title:
		Director::getInstance()->replaceScene(HelloWorldScene::createScene());
		break;
	case Menu:
		Director::getInstance()->replaceScene(HelloWorldScene::createScene());
		break;
	case Game:
		Director::getInstance()->replaceScene(HelloWorldScene::createScene());
		break;
	default:
		//error
		break;
	}
}