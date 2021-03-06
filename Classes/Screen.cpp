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
        //端末画面サイズを取得
        cocos2d::Size originSize = cocos2d::Director::getInstance()->getVisibleSize();
        cocos2d::Vec2 visibleoriginPoint = cocos2d::Director::getInstance()->getVisibleOrigin();
        screenSize = cocos2d::Vec2(originSize);
        //端末サイズと、ベースのサイズとの画面比を計算、取得,
        magnification = CheckDifferenceSize(originSize,setScreenSize);
        
        //(0,0)の位置を調整.
        Vec2 zeroPoint =  (originSize - (setScreenSize * magnification.y)) * 0.5f;
        
        //画面中央を　原点と仮定,　上下左右
        center = screenSize * 0.5f + visibleoriginPoint;
        left   = center - cocos2d::Vec2(screenSize.x * 0.5f,0) + zeroPoint;
        right  = center + cocos2d::Vec2(screenSize.x * 0.5f,0) - zeroPoint;
        top    = center + cocos2d::Vec2(0,screenSize.y * 0.5f);
        bottom = center - cocos2d::Vec2(0,screenSize.y * 0.5f);
        
        //左右上端、左右下端
        leftTop     = left  + cocos2d::Vec2(0,screenSize.y * 0.5f);
        rightTop    = right + cocos2d::Vec2(0,screenSize.y * 0.5f);
        leftBottom  = left  - cocos2d::Vec2(0,screenSize.y * 0.5f);
        rightBottom = right - cocos2d::Vec2(0,screenSize.y * 0.5f);
        
        //
        cocos2d::Vec2 quatervisbleSize = center * 0.5f;
        
        //左側中央、右側中央、等
        leftCenter   = (cocos2d::Vec2((center.x + left.x) * 0.5f,center.y));
        rightCenter  = (cocos2d::Vec2((center.x + right.x) * 0.5f,center.y));
        upCenter     =  center + cocos2d::Vec2(0,quatervisbleSize.y) ;
        downCenter   =  center - cocos2d::Vec2(0,quatervisbleSize.y) ;
       
        
        leftTopCenter     = leftCenter  + cocos2d::Vec2(0,quatervisbleSize.y);
        rightTopCenter    = rightCenter + cocos2d::Vec2(0,quatervisbleSize.y);
        leftBottomCenter  = rightCenter - cocos2d::Vec2(0,quatervisbleSize.y);
        rightBottomCenter = leftCenter  - cocos2d::Vec2(0,quatervisbleSize.y);

//        leftTop = cocos2d::Vec2(0,screenSize.y) + visibleoriginPoint;
//        rightTop = cocos2d::Vec2(screenSize.x,screenSize.y) + visibleoriginPoint;
//        leftBottom  = cocos2d::Vec2(0,0)+ visibleoriginPoint;
//        rightBottom = cocos2d::Vec2(screenSize.x,0)+ visibleoriginPoint;
//        
//        
//        center = screenSize * 0.5f + visibleoriginPoint;
//        left = center - cocos2d::Vec2(screenSize.x * 0.5f,0);
//        right = center + cocos2d::Vec2(screenSize.x * 0.5f,0);
//        
//        
//        cocos2d::Vec2 quatervisbleSize = screenSize * 0.25f  + visibleoriginPoint;
//        
//        leftCenter   = center - cocos2d::Vec2(quatervisbleSize.x,0) ;
//        upCenter     = center + cocos2d::Vec2(0,quatervisbleSize.y) ;
//        rightCenter  = center + cocos2d::Vec2(quatervisbleSize.x,0) ;
//        downCenter   = center - cocos2d::Vec2(0,quatervisbleSize.y) ;
//        topCenter    = center + cocos2d::Vec2(0,center.y) ;
//        bottomCenter = center - cocos2d::Vec2(0,center.y) ;
//        
//        leftTopCenter  = cocos2d::Vec2(quatervisbleSize.x,quatervisbleSize.y * 3);
//        rightTopCenter  = cocos2d::Vec2(quatervisbleSize.x * 3,quatervisbleSize.y * 3);
//        leftBottomCenter  = cocos2d::Vec2(quatervisbleSize.x,quatervisbleSize.y);
//        rightBottomCenter  = cocos2d::Vec2(quatervisbleSize.x * 3,quatervisbleSize.y );
     
    }
    
    //基底サイズと端末サイズの差を調整
    const cocos2d::Vec2 Screen::CheckDifferenceSize(cocos2d::Size originSize, cocos2d::Size setSize)
    {
        
        if(originSize.width == setSize.width &&
           originSize.height == setSize.height){ return Vec2().ONE;}
        
        //横幅を基準に、倍率を求める
        return Vec2(originSize.width / setSize.width,
                    originSize.height / setSize.height);
      
       

    }
    
    
}