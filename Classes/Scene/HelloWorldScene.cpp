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
 
    if ( !Layer::init())
    {
        return false;
    }
    
    auto sprite = SpriteMgr::Get().Add
    (spriteFilePath,Resource::SpriteKey::Test);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //読み込み、位置指定、レイヤーにZ値をしていして追加
    sprite->setPosition(Screen::Screen::Get().center);
    float ajustMag = Screen::Screen::Get().Maginification().y;
    sprite->setScale(1 * ajustMag,1 * ajustMag);
    this->addChild(sprite,0);
    
    //button
    std::vector<Sprite*> buttonSprites;
    buttonSprites.push_back(SpriteMgr::Get().Add
                            (buttonFP,Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    buttonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::BUtton));
    
    
    
    for(auto button : buttonSprites)
    {
        
        if(ajustMag < 1){
            button->setScale(0.265f * ajustMag,0.265f * ajustMag);
        }
        else {
            button->setScale(0.265f,0.265f);
        }
    }

    buttonSprites[0]->setPosition((Screen::Screen::Get().rightBottom));
    buttonSprites[1]->setPosition((Screen::Screen::Get().rightTop));
    buttonSprites[2]->setPosition((Screen::Screen::Get().rightCenter));
    buttonSprites[3]->setPosition((Screen::Screen::Get().rightTopCenter));
    buttonSprites[4]->setPosition((Screen::Screen::Get().right));
    
    buttonSprites[5]->setPosition((Screen::Screen::Get().leftBottom));
    buttonSprites[6]->setPosition((Screen::Screen::Get().leftTop));
    buttonSprites[7]->setPosition((Screen::Screen::Get().leftCenter));
    buttonSprites[8]->setPosition((Screen::Screen::Get().leftTopCenter));
    buttonSprites[9]->setPosition((Screen::Screen::Get().left));
    buttonSprites[10]->setPosition((Screen::Screen::Get().center));
    buttonSprites[11]->setPosition((Screen::Screen::Get().leftBottomCenter));
    buttonSprites[12]->setPosition((Screen::Screen::Get().rightBottomCenter));
    
    buttonSprites[13]->setPosition((Screen::Screen::Get().top));
    buttonSprites[14]->setPosition((Screen::Screen::Get().upCenter));
    buttonSprites[15]->setPosition((Screen::Screen::Get().bottom));
    buttonSprites[16]->setPosition((Screen::Screen::Get().downCenter));

    
    for(auto button : buttonSprites)
    {
        this->addChild(button,0);
    }
    
    return true;
}


