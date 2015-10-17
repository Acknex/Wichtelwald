#include <acknex.h>
#include <ackphysx.h>

#define DEBUG
#ifdef DEBUG
#include <default.c>
#endif

#define PRAGMA_PATH "src";
#define PRAGMA_PATH "include";
#define PRAGMA_PATH "models";
#define PRAGMA_PATH "textures";

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

void main() {
	sysInit();
	/*level_load("maps//menuLevel.wmb");
	startMenu();*/
	startGame();
}