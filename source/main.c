#include <acknex.h>

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

#include "menu.c"
#include "game.c"
#include "camera.c"
#include "mouse.c"
#include "player.c"

void main() {
	level_load("maps//menuLevel.wmb");
	startMenu();
}