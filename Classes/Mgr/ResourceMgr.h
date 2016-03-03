//
//�摜�̒ǉ��͑S�������ōs�� 
//
//
#pragma once

#include "cocos2d.h"
#include <list>

USING_NS_CC;

class ResourceMgr
{
public:

	//�����ւ��̓v���O������G�炸�ɂ�肽��...
	//������csv,xls�œǂݍ��݂ł����炢���ȂƎv��
	enum ResKey
	{
		//���݃e�X�g�p
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
