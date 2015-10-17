#ifndef MENU_C_
#define MENU_C_

void startMenu() {
	
	if (panTitle == NULL) {
		panTitle = pan_create("", 10);
		panTitle.bmap = bmapTitle;
		panTitle.pos_x = screen_size.x / 2 - bmap_width(bmapTitle) / 2;
		panTitle.pos_y = 10;
	}
	
	if (panMainMenu == NULL) {
		panMainMenu = pan_create("", 10);
		panMainMenu.bmap = bmapMainMenu;
		panMainMenu.pos_x = 10;
		panMainMenu.pos_y = 150;
		panMainMenu.alpha = 60;
		
		pan_setbutton(panMainMenu, 0, 0, 10, 10, bmapNewGameButtonOn, bmapNewGameButtonOff, bmapNewGameButtonOn, bmapNewGameButtonOff, startGame, NULL, NULL);
		pan_setbutton(panMainMenu, 0, 0, 10, 50, bmapOptionsButtonOn, bmapOptionsButtonOff, bmapOptionsButtonOn, bmapOptionsButtonOff, startGame, NULL, NULL);
		pan_setbutton(panMainMenu, 0, 0, 10, 90, bmapCreditsButtonOn, bmapCreditsButtonOff, bmapCreditsButtonOn, bmapCreditsButtonOff, startGame, NULL, NULL);
		pan_setbutton(panMainMenu, 0, 0, 10, 130, bmapEndGameButtonOn, bmapEndGameButtonOff, bmapEndGameButtonOn, bmapEndGameButtonOff, startGame, NULL, NULL);
		
	}
	
	vec_set(entGreenDot.x, vector(200, 60, 80));
	vec_set(entRedDot.x, vector(200, 20, 55));
	vec_set(entYellowDot.x, vector(200, -10, 80));
	vec_set(entBlueDot.x, vector(200, -50, 60));
	
	entGreenDot.flags2 |=SHOW;
	entRedDot.flags2 |=SHOW;
	entYellowDot.flags2 |=SHOW;
	entBlueDot.flags2 |=SHOW;
	
	
	set(panTitle, SHOW);
	set(panMainMenu, TRANSLUCENT | SHOW);
	
	initMouseMenu();
	playMusicMenu();
	startSnow();
	
	float greenDotSize = 1;
	float redDotSize = 0;
	float yellowDotSize = 1;
	float blueDotSize = 0;
	
	while(1) {
		
		if (greenDotSize == 1) {
			entGreenDot.scale_x -=1 * time_step;
			entGreenDot.scale_y -=1 * time_step;
			if (entGreenDot.scale_x <= 0.2) {
				greenDotSize = 0;
			}
		} else {
			entGreenDot.scale_x +=1 * time_step;
			entGreenDot.scale_y +=1 * time_step;
			if (entGreenDot.scale_x >= 0.7) {
				greenDotSize = 1;
			}
		}
		
		if (redDotSize == 1) {
			entRedDot.scale_x -=1 * time_step;
			entRedDot.scale_y -=1 * time_step;
			if (entRedDot.scale_x <= 0.2) {
				redDotSize = 0;
			}
		} else {
			entRedDot.scale_x +=1 * time_step;
			entRedDot.scale_y +=1 * time_step;
			if (entRedDot.scale_x >= 0.7) {
				redDotSize = 1;
			}
		}
		
		if (yellowDotSize == 1) {
			entYellowDot.scale_x -=1 * time_step;
			entYellowDot.scale_y -=1 * time_step;
			if (entYellowDot.scale_x <= 0.3) {
				yellowDotSize = 0;
			}
		} else {
			entYellowDot.scale_x +=1 * time_step;
			entYellowDot.scale_y +=1 * time_step;
			if (entYellowDot.scale_x >= 0.6) {
				yellowDotSize = 1;
			}
		}
		
		if (blueDotSize == 1) {
			entBlueDot.scale_x -=1 * time_step;
			entBlueDot.scale_y -=1 * time_step;
			if (entBlueDot.scale_x <= 0.3) {
				blueDotSize = 0;
			}
		} else {
			entBlueDot.scale_x +=1 * time_step;
			entBlueDot.scale_y +=1 * time_step;
			if (entBlueDot.scale_x >= 0.6) {
				blueDotSize = 1;
			}
		}
		
		wait(45);
	}
	
}

void endMenu() {
	if (panTitle != NULL) {
		reset(panTitle, SHOW);
	}
	
	if (panMainMenu != NULL) {
		reset(panMainMenu, SHOW);
	}
	
	entGreenDot.flags2 &=~SHOW;
	entRedDot.flags2 &=~SHOW;
	entYellowDot.flags2 &=~SHOW;
	entBlueDot.flags2 &=~SHOW;
	
	mouse_mode = 0;
}

void startIngameGUI() {
	panWoodCount.pos_x = screen_size.x - bmap_width(bmapWoodCount) - 20;
	panWoodCount.pos_y = 10;
	txtWoodCount = txt_create(1, 13);
	txtWoodCount.font = fontBoogaloo;
	txtWoodCount.pos_x = panWoodCount.pos_x - 40;
	txtWoodCount.pos_y = 10;
	vec_set(txtWoodCount.blue, vector(43,221,255));
	
	panSnowballCount.pos_x = screen_size.x - bmap_width(bmapSnowballCount) - 20;
	panSnowballCount.pos_y = 80;
	txtSnowballCount = txt_create(1, 13);
	txtSnowballCount.font = fontBoogaloo;
	txtSnowballCount.pos_x = panSnowballCount.pos_x - 40;
	txtSnowballCount.pos_y = 90;
	vec_set(txtSnowballCount.blue, vector(43,221,255));
	
	
	set(txtWoodCount, SHOW | OUTLINE);
	set(panWoodCount, SHOW);
	
	set(txtSnowballCount, SHOW | OUTLINE);
	set(panSnowballCount, SHOW);
}

void endIngameGUI() {
	reset(panWoodCount, SHOW);
}

void updateGui() {
	str_for_num((txtWoodCount.pstring)[0], woodCount);
	str_cat((txtWoodCount.pstring)[0], "/");
	str_cat((txtWoodCount.pstring)[0], str_for_num(NULL, maxWoodCount));
	
	str_for_num((txtSnowballCount.pstring)[0], snowballCount);
	str_cat((txtSnowballCount.pstring)[0], "/");
	str_cat((txtSnowballCount.pstring)[0], str_for_num(NULL, maxSnowballCount));
}


#endif