//
//  Button.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/16.
//
//

#include "Button.hpp"



Button::Button()
       :GameObject()
{
    
}
Button::~Button()
{
}

/*
Button* Button::Create(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
                       cocos2d::Vec2 ancPos, GameObject::ObjectTag tag)
{
    
        //生成
        Button* pRet = new Button();
    
        //メモリ確保、初期化の可否チェック
        if(pRet && pRet->init(pos,scale,ancPos,tag)){
            //cocos2d::Refに定義されてるリファレンスカウンタ適用のautorelease関数適用
            pRet->autorelease();
            return pRet;
        }
        else{
            //失敗した場合NULL返却
            delete  pRet;
            pRet = NULL;
            return NULL;
        }
}
*/
bool Button::init(cocos2d::Vec2 pos,cocos2d::Vec2 scale,cocos2d::Vec2 ancPos,ObjectTag tag)
{
    
    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    pos_ = pos;
    scale_ = scale;
    ancPos_ = ancPos;
    tag_ = tag;
    spritePath_ = buttonSpritePath;
    
    sprite_ = SpriteMgr::Get().Add(spritePath_,Resource::SpriteKey::UIButton);
    sprite_->setScale(scale_.x,scale_.y);
    sprite_->setPosition(pos_);
    sprite_->setAnchorPoint(ancPos_);
    this->addChild(sprite_);
    this->schedule(schedule_selector(Button::Update));
    
    return true;
}
void Button::Update(float delta)
{
    //test: 右に移動
     pos_.x ++;
    //位置とスケールを更新
    UpdatePosScale(sprite_);
   
}


