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
		panMainMenu.pos_y = screen_size.y / 2 - bmap_height(bmapMainMenu) / 2;
		panMainMenu.alpha = 60;
		
		pan_setbutton(panMainMenu, 0, 0, 10, 10, bmapNewGameButtonOn, bmapNewGameButtonOff, bmapNewGameButtonOn, bmapNewGameButtonOff, startGame, NULL, NULL);
		pan_setbutton(panMainMenu, 0, 0, 10, 50, bmapOptionsButtonOn, bmapOptionsButtonOff, bmapOptionsButtonOn, bmapOptionsButtonOff, showOptions, NULL, NULL);
		pan_setbutton(panMainMenu, 0, 0, 10, 90, bmapCreditsButtonOn, bmapCreditsButtonOff, bmapCreditsButtonOn, bmapCreditsButtonOff, startGame, NULL, NULL);
		pan_setbutton(panMainMenu, 0, 0, 10, 130, bmapEndGameButtonOn, bmapEndGameButtonOff, bmapEndGameButtonOn, bmapEndGameButtonOff, exitGame, NULL, NULL);
		
	}
	
	vec_set(entGreenDot.x, vector(200, 35, 55));
	vec_set(entRedDot.x, vector(200, 10, 55));
	vec_set(entYellowDot.x, vector(200, -20, 60));
	vec_set(entBlueDot.x, vector(200, -35, 50));
	
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
	
	stopSnow();
	
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

void showOptions() {
	if (panMainMenu != NULL) {
		reset(panMainMenu, SHOW);
	}
	
	if (panOptions == NULL) {
		panOptions = pan_create("", 12);
		panOptions.bmap = bmapOptionsMenu;
		panOptions.pos_x = screen_size.x / 2 - bmap_width(bmapOptionsMenu) / 2;
		panOptions.pos_y = 150;
		panOptions.alpha = 60;
		pan_setslider(panOptions, 0, 150, 25, bmapSlider, bmapKnob, 0, 100, musicVolume);
		pan_setslider(panOptions, 0, 150, 60, bmapSlider, bmapKnob, 0, 100, soundVolume);
		
		pan_setbutton(panOptions, 0, 0, 320, 200, bmapOkButtonOn, bmapOkButtonOff, bmapOkButtonOn, bmapOkButtonOff, closeOptions, NULL, NULL);
	}
	
	txtSoundOption.font = fontBoogalooSmall;
	txtMusicOption.font = fontBoogalooSmall;
	
	txtSoundOption.pos_x = panOptions.pos_x + 10;
	txtSoundOption.pos_y = panOptions.pos_y + 44;
	txtMusicOption.pos_x = panOptions.pos_x + 10;
	txtMusicOption.pos_y = panOptions.pos_y + 10;
	
	str_cpy((txtSoundOption.pstring)[0], "Sound volume:");
	str_cpy((txtMusicOption.pstring)[0], "Music volume:");
	
	set(panOptions, SHOW | TRANSLUCENT);
	set(txtSoundOption, SHOW);
	set(txtMusicOption, SHOW);
}

void closeOptions() {
	
	snd_tune(menuMusicHandle, musicVolume, 0, 0);
	if (panOptions != NULL) {
		reset(panOptions, SHOW);
		reset(txtSoundOption, SHOW);
		reset(txtMusicOption, SHOW);
		set(panMainMenu, SHOW);
	}
}


#endif