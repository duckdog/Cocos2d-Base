//
//  Button.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/16.
//
//

#pragma once
#include "GameObject.hpp"

class Button : public GameObject
{
    
public:
    
    Button();
    ~Button();
    virtual bool init(cocos2d::Vec2 pos,cocos2d::Vec2 scale,
                      cocos2d::Vec2 ancPos,ObjectTag tag);
    virtual void Update(float delta);
    
    static Button* Create(cocos2d::Vec2 pos,cocos2d::Vec2 scale,
                          cocos2d::Vec2 ancPos,ObjectTag tag);
    
    
private:
    
    const char* buttonSpritePath = "button.png";
    
    
    
};