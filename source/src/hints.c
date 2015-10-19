#ifndef HINTS_C
#define HINTS_C

var dayhintshown = 0;
var nighthintshown = 0;

TEXT* txtDayHint = 
{
	string("Die Ruhe vor dem Sturm", "", "Sorge für eine gut beheizte Hütte.", "Sammle soviel Brennholz und Schneebälle wie möglich", "und bring alles bis 20 Uhr abends zur Hütte!", "Steuere mit WASD.");
	red = 255;
	green = 255;
	blue = 255;
	alpha = 0;
	flags |= LIGHT | FILTER | TRANSLUCENT | WWRAP | SHADOW | CENTER_X;
}

TEXT* txtNightHint = 
{
	string("Die Terrorwichtel", "", "Sie wollen verhindern, dass Deine Hütte beheizt wird.", "Verteidige Dich bis 8 Uhr morgens!", "Steuere mit Maus, Schieße mit Space oder linker Maustaste.");
	red = 255;
	green = 255;
	blue = 255;
	alpha = 0;
	flags |= LIGHT | FILTER | TRANSLUCENT | WWRAP | SHADOW | CENTER_X;
}

void reset_hints()
{
	dayhintshown = 0;
	nighthintshown = 0;
	txtDayHint->pos_x = screen_size.x * 0.5;
	txtDayHint->pos_y = screen_size.y * 0.1;
	txtDayHint->font = fontBoogaloo;
	txtNightHint->pos_x = screen_size.x * 0.5;
	txtNightHint->pos_y = screen_size.y * 0.1;
	txtNightHint->font = fontBoogaloo;
	txtDayHint->alpha = 0;
	txtNightHint->alpha = 0;
}

void show_dayhint()
{
	if (dayhintshown != 0) return;
	dayhintshown = 1;
	txtNightHint->alpha = 0;
	reset(txtNightHint, SHOW);
	
	set(txtDayHint, SHOW);
	while (is(txtDayHint, SHOW) && txtDayHint->alpha < 100)
	{
		wait(1);
		txtDayHint->alpha += 5* time_step;
	}
	txtDayHint->alpha = 100;
	if (!is(txtDayHint, SHOW)) return;
	wait (-10);
	while (is(txtDayHint, SHOW) && txtDayHint->alpha > 0)
	{
		wait(1);
		txtDayHint->alpha -= 5* time_step;
	}
	txtDayHint->alpha = 0;
	reset(txtDayHint, SHOW);
	
}

void show_nighthint()
{
	if (nighthintshown != 0) return;
	nighthintshown = 1;
	txtDayHint->alpha = 0;
	reset(txtDayHint, SHOW);

	set(txtNightHint, SHOW);
	while (is(txtNightHint, SHOW) && txtNightHint->alpha < 100)
	{
		wait(1);
		txtNightHint->alpha += 5* time_step;
	}
	txtNightHint->alpha = 100;
	if (!is(txtNightHint, SHOW)) return;
	wait (-10);
	while (is(txtNightHint, SHOW) && txtNightHint->alpha > 0)
	{
		wait(1);
		txtNightHint->alpha -= 5* time_step;
	}
	txtNightHint->alpha = 0;
	reset(txtNightHint, SHOW);
	
}

void hide_hints()
{
	reset(txtDayHint, SHOW);
	reset(txtNightHint, SHOW);
	txtDayHint->alpha = 0;
	txtNightHint->alpha = 0;
}
#endif
