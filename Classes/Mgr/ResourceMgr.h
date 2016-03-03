//
//画像の追加は全部ここで行う 
//
//
#pragma once

#include "cocos2d.h"
#include <list>

USING_NS_CC;

class ResourceMgr
{
public:

	//差し替えはプログラムを触らずにやりたい...
	//ここをcsv,xlsで読み込みできたらいいなと思う
	enum ResKey
	{
		//現在テスト用
		Player,		
		Enemy,
		Item,
		TitleBG,
		MenuBG,
		GameBG,

	};
	


		cocos2d::Sprite* Add(const char* spriteFileName);
		cocos2d::Sprite* Get(const char* spriteFileName);
		cocos2d::Sprite* RePlace(cocos2d::Sprite* base, const char* spriteFileName);
		void Erase(const char* spriteFileName);
		void Clear(const char* spriteFileName);
	

};
