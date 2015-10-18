#ifndef MENU_H_
#define MENU_H_

var digitDummy = 0;

FONT* fontBoogaloo = NULL;
FONT* fontBoogalooSmall = NULL;
FONT* fontBoogalooMini = NULL;

BMAP* bmapNewGameButtonOn = "newGameButtonUp.bmp";
BMAP* bmapNewGameButtonOff = "newGameButtonDown.bmp";
BMAP* bmapCreditsButtonOn = "creditsButtonUp.bmp";
BMAP* bmapCreditsButtonOff = "creditsButtonDown.bmp";
BMAP* bmapEndGameButtonOn = "endGameButtonUp.bmp";
BMAP* bmapEndGameButtonOff = "endGameButtonDown.bmp";
BMAP* bmapOptionsButtonOn = "optionsButtonUp.bmp";
BMAP* bmapOptionsButtonOff = "optionsButtonDown.bmp";
BMAP* bmapOkButtonOn = "okButtonUp.bmp";
BMAP* bmapOkButtonOff = "okButtonDown.bmp";
BMAP* bmapCancelButtonOn = "cancelButtonUp.bmp";
BMAP* bmapCancelButtonOff = "cancelButtonDown.bmp";

BMAP* bmapTitle = "titleLarge.tga";
BMAP* bmapMainMenu = "mainMenu.bmp";

BMAP* bmapRedDot = "redDot.tga";
BMAP* bmapYellowDot = "yellowDot.tga";
BMAP* bmapGreenDot = "greenDot.tga";
BMAP* bmapBlueDot = "blueDot.tga";

PANEL* panMainMenu = NULL;
PANEL* panTitle = NULL;

PANEL* panOptions = NULL;
BMAP* bmapOptionsMenu = "optionsBg.bmp";
BMAP* bmapSlider = "slider.bmp";
BMAP* bmapKnob = "knob.bmp";
TEXT* txtSoundOption = { strings = 1; layer = 13; }
TEXT* txtMusicOption = { strings = 1; layer = 13; }

PANEL* panCredits = NULL;

ENTITY* entGreenDot = { type = "greenDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 12; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }
ENTITY* entRedDot = { type = "redDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 12; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }
ENTITY* entBlueDot = { type = "blueDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 12; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }
ENTITY* entYellowDot = { type = "yellowDot.tga"; flags2 = SHOW; flags = BRIGHT; layer = 12; scale_x = 0.5; scale_y = 0.5; scale_z = 0.5; }

void startMenu();
void endMenu();

void showOptions();
void closeOptions();

void showCredits();
void closeCredits();

#endif