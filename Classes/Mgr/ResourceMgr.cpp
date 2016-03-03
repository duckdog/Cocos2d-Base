#include "ResourceMgr.h"


//テクスチャをキャッシュ領域に追加.
cocos2d::Sprite* ResourceMgr::Add(const char * spriteFileName)
{
	Director::getInstance()
		->getTextureCache()->addImage(spriteFileName);

	return ResourceMgr::Get(spriteFileName);
}

//キャッシュされているものから取得.
cocos2d::Sprite* ResourceMgr::Get(const char * spriteFileName)
{
	//入れ物初期化
	cocos2d::Sprite* sprite = Sprite::create();
	sprite->setTexture(Director::getInstance()->
			getTextureCache()->getTextureForKey(spriteFileName));
	
	//キャッシュに追加されていなかったら、追加してやる
	if (sprite == nullptr) {sprite = ResourceMgr::Add(spriteFileName);}

	return sprite;
}

//直接入れ替え.
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
