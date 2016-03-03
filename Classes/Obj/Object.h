//
//�I�u�W�F�N�g�icocos2d::Sprite�j�Ǘ��N���X
//
//
#pragma once

#include "cocos2d.h"
#include <memory>
#include <list>
#include <vector> 

class Object;
typedef std::shared_ptr<Object> ObjectPtr;

class Object : public cocos2d::Sprite
{
public:
	enum ObjectTag
	{
		Player = 1,
		Enemy,
		Item,

		Null,
	};
	Object(cocos2d::Vec2 pos, cocos2d::Vec2 scale, cocos2d::Vec2 ancPos, ObjectTag tag);
	~Object();

	void Erase();
	void Clear();
	ObjectPtr FindObjectTag(ObjectTag);
	std::list<ObjectPtr> FindObjectsTag(ObjectTag);

protected:
	//�I�u�W�F�N�g�S�̂��Ǘ�
	std::list<ObjectPtr> objectList_;
	virtual bool init();
	virtual void Create(cocos2d::Vec2 pos, cocos2d::Vec2 scale,cocos2d::Vec2 ancPos,ObjectTag tag);
	virtual void Update(float delta);
	cocos2d::Vec2 pos_;
	cocos2d::Vec2 scale_;
	cocos2d::Vec2 ancPos_;
	ObjectTag tag_;

};