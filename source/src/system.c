#ifndef SYSTEM_C_
#define SYSTEM_C_

#include <windows.h>

void sysInit() {
	video_mode = 12;
	video_screen = 1;
	fps_max = 30;
	max_particles = 25000;
	AddFontResource("fonts//Boogaloo-Regular.otf");

	var scale = screen_size.y / 1200;
	STRING* strTemp = "#64";	

	str_printf(strTemp, "Boogaloo#%i", (int)(100 * scale));
	ptr_remove(fontBoogaloo);
	fontBoogaloo = font_create(strTemp);
	
	fontBoogalooSmall = font_create("Boogaloo#30");
	fontBoogalooMini = font_create("Boogaloo#20");
	
	exitFunction = on_exit;
	
	on_exit = cleanUpGame;
}

void cleanUpGame() {
	RemoveFontResource("fonts//Boogaloo-Regular.otf");
	exitFunction();
}

void exitGame() {
	sys_exit("");
}

#endif