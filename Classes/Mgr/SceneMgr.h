//
//　シーンマネージャー
//　Tips:FixMe cocos2d::Layer依存.
//
#pragma once

#include<memory>
#include<vector>
#include<list>
#include "cocos2d.h"

USING_NS_CC;
class SceneMgr;
typedef std::shared_ptr<SceneMgr> sceneSptr;
class SceneMgr : public cocos2d::Layer
{
public:
	enum SceneType
	{
		Title,
		Menu,
		Game,

		None,
	};

	SceneMgr();
	~SceneMgr();
	static void ReplaceScene(SceneType type = SceneType::Title);
	
protected:
	

	

};


