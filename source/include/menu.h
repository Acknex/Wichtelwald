#ifndef MENU_H_
#define MENU_H_

BMAP* bmapNewGameButtonOn = "graphics//newGameButtonUp.bmp";
BMAP* bmapNewGameButtonOff = "graphics//newGameButtonDown.bmp";
BMAP* bmapCreditsButtonOn = "graphics//creditsButtonUp.bmp";
BMAP* bmapCreditsButtonOff = "graphics//creditsButtonDown.bmp";
BMAP* bmapEndGameButtonOn = "graphics//endGameButtonUp.bmp";
BMAP* bmapEndGameButtonOff = "graphics//endGameButtonDown.bmp";
BMAP* bmapOptionsButtonOn = "graphics//optionsButtonUp.bmp";
BMAP* bmapOptionsButtonOff = "graphics//optionsButtonDown.bmp";

BMAP* bmapTitle = "graphics//titleLarge.tga";
BMAP* bmapMainMenu = "graphics//mainMenu.bmp";

PANEL* panMainMenu = NULL;
PANEL* panTitle = NULL;

void startMenu();
void endMenu();

#endif