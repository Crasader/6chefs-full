﻿//
//  TitleMenu.h
//  LastSupper
//
//  Created by 猪野凌也 on 2015/03/15.
//
//
#ifndef  _TITLE_MENU_H_
#define _TITLE_MENU_H_
#include "cocos2d.h"
#include "Common.h"
#include "model/BaseTitleMenu.h"

class TitleMenu : public cocos2d::Layer
{
public:
	virtual bool init();
    TitleMenu();
	CREATE_FUNC(TitleMenu);

private:
	BaseTitleMenu baseTitleMenu;
	cocos2d::FileUtils * fu;
};

#endif // _TITLE_MENU_H_
