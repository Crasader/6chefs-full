#ifndef _BASE_TITLE_MENU_H_
#define _BASE_TITLE_MENU_H_
#include "Common.h"

class BaseTitleMenu{
	public:
		BaseTitleMenu();
		~BaseTitleMenu();

	private:
		void init();
		int mainCursorPosition;
		int loadCursorPosition;
		map<int, string> mainMenu;
		map<int, string> loadMenu;
		vector<string> mainMenuString = {"�͂��߂���", "��������", "�I��"};
};

#endif //_BASE_TITLE_MENU_H_