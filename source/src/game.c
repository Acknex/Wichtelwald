#ifndef GAME_C_
#define GAME_C_

void startGame() {
	endMenu();
	level_load("maps//mainLevel.wmb");
	gameCameraInit();
}

#endif