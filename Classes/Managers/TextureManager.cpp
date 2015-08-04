//
//  TextureManager.cpp
//  LastSupper
//
//  Created by Kohei on 2015/07/20.
//
//

#include "TextureManager.h"

const string TextureManager::basePath = "img/texture/";
const string TextureManager::characterPath = basePath + "character/";

// 唯一のインスタンスを初期化
static TextureManager* _instance = nullptr;

// 唯一のインスタンスを取得
TextureManager* TextureManager::getInstance()
{
	if(!_instance) _instance = new TextureManager();
	return _instance;
}

// インスタンスを破棄
void TextureManager::destory()
{
	delete _instance;
	return;
}

// コンストラクタ
TextureManager::TextureManager()
{FUNCLOG}

// デストラクタ
TextureManager::~TextureManager()
{FUNCLOG}

// 指定パスのテクスチャをプリロード
void TextureManager::preloadTexture(const string& filePath, const function<void()> callback)
{
	FUNCLOG
	Director::getInstance()->getTextureCache()->addImageAsync(filePath + ".pvr.ccz",
															  [=](Texture2D* loaded_texture){
																  SpriteFrameCache::getInstance()->addSpriteFramesWithFile(filePath + ".plist", loaded_texture);
																  this->texturePaths.push_back(filePath);
																  callback();
															  });
	return;
}

// すべてのテクスチャをアンロード
void TextureManager::unloadAllTectures()
{
	FUNCLOG
	for(string filePath : this->texturePaths)
	{
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile(filePath + ".plist");
		Director::getInstance()->getTextureCache()->removeTextureForKey(filePath + ".pvr.ccz");
	}
	this->texturePaths.clear();
}