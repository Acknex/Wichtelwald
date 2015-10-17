#ifndef GAME_C_
#define GAME_C_

void startGame() {
	endMenu();
	level_load("maps//mainLevel.wmb");
	gameCameraInit();
	startIngameGUI();
	playMusicGameDay();
	on_space = throwSnowball;
	
	while(1) {
		updateGui();
		wait(1);
	}
}

#endif