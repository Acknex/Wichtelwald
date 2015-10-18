#ifndef HUD_H_
#define HUD_H_

void startIngameGUI();
void endIngameGUI();
void updateGui();

void showHutItems();
void hideHutItems();
var isHutItemsVisible();

BMAP* bmapWoodCount = "graphics//wood.tga";
PANEL* panWoodCount = { bmap = bmapWoodCount; layer = 12; }
TEXT* txtWoodCount = NULL;

BMAP* bmapSnowballCount = "graphics//snowball.tga";
PANEL* panSnowballCount = { bmap = bmapSnowballCount; layer = 12; }
TEXT* txtSnowballCount = NULL;

BMAP* bmapClock = "graphics//clock.tga";

PANEL* panClock = { bmap = bmapClock; layer = 13; }

PANEL* panHutBg = { flags = LIGHT | TRANSLUCENT; red = 0; blue = 0; green = 0; size_x = 150; size_y = 130; alpha = 60; layer = 12;}
BMAP* bmapHut = "graphics//hut.tga";
PANEL* panHut = { bmap = bmapHut; layer = 13; flags = TRANSLUCENT; }
TEXT* txtHutWoodCount = NULL;
TEXT* txtHutSnowballCount = NULL;
PANEL* panSmallSnowballCount = { bmap = bmapSnowballCount; layer = 14; scale_x = 0.5; scale_y = 0.5; flags = TRANSLUCENT; }
PANEL* panSmallWoodCount = { bmap = bmapWoodCount; layer = 14; scale_x = 0.5; scale_y = 0.5; flags = TRANSLUCENT; }

BMAP* bmapGameOver = "graphics//gameOver.tga";
PANEL* panGameOver = { bmap = bmapGameOver; layer = 20; }

#endif