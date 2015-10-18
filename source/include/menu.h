#ifndef MENU_H_
#define MENU_H_

FONT* fontBoogaloo = NULL;
FONT* fontBoogalooSmall = NULL;

BMAP* bmapNewGameButtonOn = "graphics//newGameButtonUp.bmp";
BMAP* bmapNewGameButtonOff = "graphics//newGameButtonDown.bmp";
BMAP* bmapCreditsButtonOn = "graphics//creditsButtonUp.bmp";
BMAP* bmapCreditsButtonOff = "graphics//creditsButtonDown.bmp";
BMAP* bmapEndGameButtonOn = "graphics//endGameButtonUp.bmp";
BMAP* bmapEndGameButtonOff = "graphics//endGameButtonDown.bmp";
BMAP* bmapOptionsButtonOn = "graphics//optionsButtonUp.bmp";
BMAP* bmapOptionsButtonOff = "graphics//optionsButtonDown.bmp";
BMAP* bmapOkButtonOn = "graphics//okButtonUp.bmp";
BMAP* bmapOkButtonOff = "graphics//okButtonDown.bmp";
BMAP* bmapCancelButtonOn = "graphics//cancelButtonUp.bmp";
BMAP* bmapCancelButtonOff = "graphics//cancelButtonDown.bmp";

BMAP* bmapTitle = "graphics//titleLarge.tga";
BMAP* bmapMainMenu = "graphics//mainMenu.bmp";

BMAP* bmapRedDot = "graphics//redDot.tga";
BMAP* bmapYellowDot = "graphics//yellowDot.tga";
BMAP* bmapGreenDot = "graphics//greenDot.tga";
BMAP* bmapBlueDot = "graphics//blueDot.tga";

PANEL* panMainMenu = NULL;
PANEL* panTitle = NULL;

PANEL* panOptions = NULL;
BMAP* bmapOptionsMenu = "graphics//optionsBg.bmp";
BMAP* bmapSlider = "graphics//slider.bmp";
BMAP* bmapKnob = "graphics//knob.bmp";
TEXT* txtSoundOption = { strings = 1; layer = 13; }
TEXT* txtMusicOption = { strings = 1; layer = 13; }

ENTITY* entGreenDot = { type = "graphics//greenDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 12; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }
ENTITY* entRedDot = { type = "graphics//redDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 9; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }
ENTITY* entBlueDot = { type = "graphics//blueDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 12; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }
ENTITY* entYellowDot = { type = "graphics//yellowDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 12; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }

void startMenu();
void endMenu();

void showOptions();
void closeOptions();

#endif