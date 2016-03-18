#include "GameObject.hpp"
#include <iostream>
#include "../Screen.hpp"
#include "../AnchorPoint.hpp"


GameObject::GameObject()
:pos_(Screen::Screen::Get().center),scale_(1,1),ancPos_(AncPoint::AnchorCenter),
spritePath_(""),tag_(ObjectTag::Null){}


GameObject::~GameObject(){}


//Tips:spriteの位置とスケールの更新だけ頻繁におこなわれるため、定義
//２行だからいらなかったかも。
void GameObject::UpdatePosScale(cocos2d::Sprite* sprite)
{
    sprite->setPosition(pos_);
    sprite->setScale(scale_.x,scale_.y);
    
}