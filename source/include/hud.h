#ifndef HUD_H_
#define HUD_H_

void startIngameGUI();
void endIngameGUI();
void updateGui();

BMAP* bmapWoodCount = "graphics//wood.tga";
PANEL* panWoodCount = { bmap = bmapWoodCount; layer = 12; }
TEXT* txtWoodCount = NULL;

BMAP* bmapSnowballCount = "graphics//snowball.tga";
PANEL* panSnowballCount = { bmap = bmapSnowballCount; layer = 12; }
TEXT* txtSnowballCount = NULL;

BMAP* bmapClock = "graphics//clock.tga";

PANEL* panClock = { bmap = bmapClock; layer = 13; }

#endif