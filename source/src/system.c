#ifndef SYSTEM_C_
#define SYSTEM_C_

#include <windows.h>

void sysInit() {
	max_particles = 25000;
	physX_open();
	AddFontResource("fonts//Boogaloo-Regular.otf");

	var scale = screen_size.y / 1200;
	STRING* strTemp = "#64";	

	str_printf(strTemp, "Boogaloo#%i", (int)(100 * scale));
	ptr_remove(fontBoogaloo);
	fontBoogaloo = font_create(strTemp);
	
	exitFunction = on_exit;
	
	on_exit = cleanUpGame;
	
}

void cleanUpGame() {
	physX_destroy();
	RemoveFontResource("fonts//Boogaloo-Regular.otf");
	exitFunction();
}

#endif