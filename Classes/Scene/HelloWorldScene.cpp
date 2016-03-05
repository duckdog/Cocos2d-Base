#include "HelloWorldScene.hpp"
#include "../Mgr/SpriteMgr.hpp"
#include "../Screen.hpp"
Scene* HelloWorldScene::createScene()
{
    auto scene = Scene::create();   
    auto layer = HelloWorldScene::create();

	scene->addChild(layer);

	return scene;
}

bool HelloWorldScene::init()
{
 
    if ( !Layer::init() )
    {
        return false;
    }
    auto sprite = SpriteMgr::Get().Add
    (spriteFilePath,Resource::SpriteKey::Test);
    auto sprite2 = SpriteMgr::Get().Find(SpriteKey::Test);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //読み込み、位置指定、レイヤーにZ値をしていして追加
    sprite->setPosition(Screen::Screen::Get().leftTop);
    sprite2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y));
    
    
    this->addChild(sprite, 0);
    this->addChild(sprite2, 0);
    
    return true;
}


