//
//  Screen.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/05.
//
//

#include "Screen.hpp"

namespace Screen {
    
    Screen& Screen::Get()
    {
        static Screen instance;
        return instance;
    }
    
    void Screen::InitScreen()
    {
        
        //規定サイズと端末サイズを比較,横幅を合わせて,
        //スクリーンサイズを調整.
        cocos2d::Size originSize = cocos2d::Director::getInstance()->getVisibleSize();
        auto magnification = CheckDifferenceSize(originSize,setScreenSize);
        screenSize = cocos2d::Vec2(setScreenSize.width,setScreenSize.height) * magnification;

        
        leftTop = cocos2d::Vec2(0,screenSize.y);
        rightTop = cocos2d::Vec2(screenSize.x,screenSize.y);
        leftBottom  = cocos2d::Vec2(0,0) ;
        rightBottom = cocos2d::Vec2(screenSize.x,0) ;
        
        center = screenSize * 0.5f;
        cocos2d::Vec2 quatervisbleSize = screenSize * 0.25f;
        
        leftCenter   = center - cocos2d::Vec2(quatervisbleSize.x,0) ;
        upCenter     = center + cocos2d::Vec2(0,quatervisbleSize.y) ;
        rightCenter  = center + cocos2d::Vec2(quatervisbleSize.x,0) ;
        downCenter   = center - cocos2d::Vec2(0,quatervisbleSize.y) ;
        topCenter    = center + cocos2d::Vec2(0,center.y) ;
        bottomCenter = center - cocos2d::Vec2(0,center.y) ;
        
        leftTopCenter  = cocos2d::Vec2(quatervisbleSize.x,quatervisbleSize.y * 3);
        rightTopCenter  = cocos2d::Vec2(quatervisbleSize.x * 3,quatervisbleSize.y * 3);
        leftBottomCenter  = cocos2d::Vec2(quatervisbleSize.x,quatervisbleSize.y);
        rightBottomCenter  = cocos2d::Vec2(quatervisbleSize.x * 3,quatervisbleSize.y );
     
    }
    
    float Screen::CheckDifferenceSize(cocos2d::Size originSize, cocos2d::Size setSize)
    {
        
        if(originSize.width == setSize.width &&
           originSize.height == setSize.height){ return 1.0f;}
        
        //横幅を基準に、倍率を求める
        magnifiation = Vec2(originSize.width / setSize.width,originSize.width / setSize.width);
      
        //全表示を優先.小さい方を返す
        return MIN(magnifiation.x,magnifiation.y);

    }
    
    
}