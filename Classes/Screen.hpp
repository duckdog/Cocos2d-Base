//
//  Screen.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/05.
//
//

#pragma once
#include "cocos2d.h"
#include <map>

USING_NS_CC;

namespace Screen {
    
    enum Key
    {
        LeftTop = 0,
        RightTop = 1,
        LeftBottom = 2,
        RightBottom = 3,
        
        Left,
        Right,
        Top,
        Bottom,
        Center,
        Last,
    };

    const cocos2d::Size setScreenSize = cocos2d::Size(640,1136);
    
    
    class Screen{
        
    public:
        
        cocos2d::Vec2 leftTop;
        cocos2d::Vec2 rightTop;
        cocos2d::Vec2 leftBottom;
        cocos2d::Vec2 rightBottom;
        
        cocos2d::Vec2 center ;
        cocos2d::Vec2 leftCenter;
        cocos2d::Vec2 rightCenter;
        cocos2d::Vec2 upCenter;
        cocos2d::Vec2 downCenter;
        cocos2d::Vec2 topCenter;
        cocos2d::Vec2 bottomCenter;
        
        cocos2d::Vec2 leftTopCenter;
        cocos2d::Vec2 rightTopCenter;
        cocos2d::Vec2 leftBottomCenter;
        cocos2d::Vec2 rightBottomCenter;
        
        //画面サイズの初期化
        void InitScreen();
        float CheckDifferenceSize(cocos2d::Size reSize,cocos2d::Size originSize);
        static Screen& Get();
        
        const cocos2d::Vec2 ScreenSize(){return screenSize;}
        const cocos2d::Vec2 Maginification(){return magnifiation;}
        

    private:
        
        Screen() = default;
        cocos2d::Vec2 screenSize;
        cocos2d::Vec2 magnifiation;
        
        
    
    };

}



