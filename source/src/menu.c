#ifndef MENU_C_
#define MENU_C_

void startMenu() {
	
	panTitle = pan_create("", 10);
	panTitle.bmap = bmapTitle;
	panTitle.pos_x = 80;
	panTitle.pos_y = 10;
	set(panTitle, SHOW);
	
	panMainMenu = pan_create("", 10);
	panMainMenu.bmap = bmapMainMenu;
	panMainMenu.pos_x = 10;
	panMainMenu.pos_y = 150;
	panMainMenu.alpha = 60;
	
	pan_setbutton(panMainMenu, 0, 0, 10, 10, bmapNewGameButtonOn, bmapNewGameButtonOff, bmapNewGameButtonOn, bmapNewGameButtonOff, startGame, NULL, NULL);
	pan_setbutton(panMainMenu, 0, 0, 10, 50, bmapOptionsButtonOn, bmapOptionsButtonOff, bmapOptionsButtonOn, bmapOptionsButtonOff, startGame, NULL, NULL);
	pan_setbutton(panMainMenu, 0, 0, 10, 90, bmapCreditsButtonOn, bmapCreditsButtonOff, bmapCreditsButtonOn, bmapCreditsButtonOff, startGame, NULL, NULL);
	pan_setbutton(panMainMenu, 0, 0, 10, 130, bmapEndGameButtonOn, bmapEndGameButtonOff, bmapEndGameButtonOn, bmapEndGameButtonOff, startGame, NULL, NULL);
	
	set(panMainMenu, TRANSLUCENT | SHOW);
	
	initMouseMenu();
}


#endif