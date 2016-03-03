#include "ResourceMgr.h"


//�e�N�X�`�����L���b�V���̈�ɒǉ�.
cocos2d::Sprite* ResourceMgr::Add(const char * spriteFileName)
{
	Director::getInstance()
		->getTextureCache()->addImage(spriteFileName);

	return ResourceMgr::Get(spriteFileName);
}

//�L���b�V������Ă�����̂���擾.
cocos2d::Sprite* ResourceMgr::Get(const char * spriteFileName)
{
	//���ꕨ������
	cocos2d::Sprite* sprite = Sprite::create();
	sprite->setTexture(Director::getInstance()->
			getTextureCache()->getTextureForKey(spriteFileName));
	
	//�L���b�V���ɒǉ�����Ă��Ȃ�������A�ǉ����Ă��
	if (sprite == nullptr) {sprite = ResourceMgr::Add(spriteFileName);}

	return sprite;
}

//���ړ���ւ�.
cocos2d::Sprite * ResourceMgr::RePlace(cocos2d::Sprite * base, const char * spriteFileName)
{
	base->setTexture(Director::getInstance()->
		  getTextureCache()->getTextureForKey(spriteFileName));
	
}

void ResourceMgr::Erase(const char * spriteFileName)
{
}

void ResourceMgr::Clear(const char * spriteFileName)
{
}
