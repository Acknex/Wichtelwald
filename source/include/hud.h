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

BMAP* bmapHut = "graphics//hut.tga";
PANEL* panHut = { bmap = bmapHut; layer = 13; }
TEXT* txtHutWoodCount = NULL;
TEXT* txtHutSnowballCount = NULL;
PANEL* panSmallSnowballCount = { bmap = bmapSnowballCount; layer = 14; scale_x = 0.5; scale_y = 0.5; }
PANEL* panSmallWoodCount = { bmap = bmapWoodCount; layer = 14; scale_x = 0.5; scale_y = 0.5; }

#endif