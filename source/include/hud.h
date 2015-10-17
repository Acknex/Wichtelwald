#ifndef HUD_H_
#define HUD_H_

void startIngameGUI();
void endIngameGUI();
void updateGui();

int woodCount = 0;
int maxWoodCount = 3;

int snowballCount = 0;
int maxSnowballCount = 20;

BMAP* bmapWoodCount = "graphics//wood.tga";
PANEL* panWoodCount = { bmap = bmapWoodCount; layer = 12; }
TEXT* txtWoodCount = NULL;

BMAP* bmapSnowballCount = "graphics//snowball.tga";
PANEL* panSnowballCount = { bmap = bmapSnowballCount; layer = 12; }
TEXT* txtSnowballCount = NULL;

#endif