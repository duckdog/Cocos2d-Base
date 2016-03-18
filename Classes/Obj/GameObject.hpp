//
//オブジェクトのベースを定義
//一括管理もしたかったがココスだとあまりにもやりづらかったので、断念
//素敵なやり方教えていただけたら嬉しい...

#pragma once

#include "cocos2d.h"
#include <memory>
#include <list>
#include <vector> 
#include "../Mgr/SpriteMgr.hpp"


class GameObject: public cocos2d::Sprite
{
public:
    
	enum ObjectTag
	{
		Player = 1,
		Enemy,
		Item,
        Button,
        
		Null,
	};
    
	GameObject();
	~GameObject();
    
    cocos2d::Vec2 GetPos(){return pos_;}
    cocos2d::Sprite* GetSprite(){return sprite_;}

protected:
    
    void UpdatePosScale(cocos2d::Sprite*);
    
	cocos2d::Vec2 pos_;
	cocos2d::Vec2 scale_;
	cocos2d::Vec2 ancPos_;
    cocos2d::Sprite* sprite_;
    const char*   spritePath_;
	
    ObjectTag tag_;
    

};