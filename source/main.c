#include <acknex.h>

#define DEBUG
#ifdef DEBUG
#include <default.c>
#endif

#define PRAGMA_LEVEL "maps\\mainLevel.wmp"
#define PRAGMA_LEVEL "maps\\menuLevel2.wmp"
#define PRAGMA_BIND "shadows\\default.fx"

#define PRAGMA_PATH "src";
#define PRAGMA_PATH "include";
#define PRAGMA_PATH "models";
#define PRAGMA_PATH "textures";
#define PRAGMA_PATH "shadows";
#define PRAGMA_PATH "fonts";
#define PRAGMA_PATH "sounds";
#define PRAGMA_PATH "music";
#define PRAGMA_PATH "maps";
#define PRAGMA_PATH "graphics";

#include "shadows.c"
#include "menu.h"
#include "game.h"
#include "camera.h"
#include "mouse.h"
#include "player.h"
#include "music.h"
#include "lensflare.h"
#include "weather.h"
#include "system.h"
#include "items.h"
#include "hud.h"
#include "hut.h"
#include "goblin.h"
#include "hints.h"

#include "menu.c"
#include "game.c"
#include "camera.c"
#include "mouse.c"
#include "player.c"
#include "music.c"
#include "lensflare.c"
#include "weather.c"
#include "system.c"
#include "items.c"
#include "hud.c"
#include "hut.c"
#include "goblin.c"
#include "hints.c"

void main() {
	sysInit();
	wait(1);
	level_load("menuLevel2.wmb");
	startMenu();
}