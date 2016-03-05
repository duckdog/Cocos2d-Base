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
        
        
        //スクリーンサイズを調整.
        cocos2d::Size originSize = cocos2d::Director::getInstance()->getVisibleSize();
        cocos2d::Vec2 visibleoriginPoint = cocos2d::Director::getInstance()->getVisibleOrigin();
        screenSize = cocos2d::Vec2(originSize);
        magnification = CheckDifferenceSize(originSize,setScreenSize);
        
        
        
        
        leftTop = cocos2d::Vec2(0,screenSize.y) + visibleoriginPoint;
        rightTop = cocos2d::Vec2(screenSize.x,screenSize.y) + visibleoriginPoint;
        leftBottom  = cocos2d::Vec2(0,0)+ visibleoriginPoint;
        rightBottom = cocos2d::Vec2(screenSize.x,0)+ visibleoriginPoint;
        
        center = screenSize * 0.5f + visibleoriginPoint;
        cocos2d::Vec2 quatervisbleSize = screenSize * 0.25f  + visibleoriginPoint;
        
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
    
    const cocos2d::Vec2 Screen::CheckDifferenceSize(cocos2d::Size originSize, cocos2d::Size setSize)
    {
        
        if(originSize.width == setSize.width &&
           originSize.height == setSize.height){ return Vec2().ONE;}
        
        //横幅を基準に、倍率を求める
        return Vec2(originSize.width / setSize.width,
                    originSize.height / setSize.height);
      
       

    }
    
    
}