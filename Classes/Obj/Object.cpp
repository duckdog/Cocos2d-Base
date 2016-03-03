#include "Object.h"
#include <iostream>

Object::Object(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
			   cocos2d::Vec2 ancPos, ObjectTag tag) 
	: pos_(pos),scale_(scale),ancPos_(ancPos_),tag_(tag) {}
Object::~Object() {}
	
void Object::Create(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
					cocos2d::Vec2 ancPos, ObjectTag tag)
{
	auto obj =  ObjectPtr(new Object(pos,scale,ancPos,tag));
	objectList_.push_back(obj);
}

void Object::Erase()
{
}

void Object::Clear()
{
}

//タグの種類が同じものを返します.
ObjectPtr Object::FindObjectTag(ObjectTag tag)
{
	for (auto obj : objectList_)
	{
		if (obj->tag_ == tag)
			return obj;
	}
	//
	std::cout<< "何も見つかりませんでした,nullptrを返します" << std::endl;
	return nullptr;
}
//タグの種類が同じものを"全て"返します.
std::list<ObjectPtr> Object::FindObjectsTag(ObjectTag tag)
{
	std::list<ObjectPtr> objs;
	for (auto obj : objectList_)
	{
		if (obj->tag_ == tag)
		   objs.push_back(obj);
	}
	return objs;

}

bool Object::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	this->schedule(schedule_selector(Object::Update));
	return true;
}

void Object::Update(float delta)
{
	
}




