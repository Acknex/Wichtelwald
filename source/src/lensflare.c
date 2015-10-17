#ifndef LENSFLARE_C
#define LENSFLARE_C

// Initialisiere den Abstand der einzelnen Reflektionen zueinander.
void initLensFlarePosition() {
	entFlare1.LENS_DISTANCE = 1.278;
	entFlare2.LENS_DISTANCE = 1.200;
	//flare3_ent.LENS_DISTANCE = 1.000;
   entFlare4.LENS_DISTANCE = 0.522;
	entFlare5.LENS_DISTANCE = 0.434;
	entFlare6.LENS_DISTANCE = 0.348;
	entFlare7.LENS_DISTANCE = 0.306;
	entFlare8.LENS_DISTANCE = 0.262;	
	entFlare9.LENS_DISTANCE = 0.174;
	entFlare10.LENS_DISTANCE = 0.114;
	entFlare11.LENS_DISTANCE = 0.044;
	entFlare12.LENS_DISTANCE = 0.002;
	entFlare13.LENS_DISTANCE = -0.128;
   entFlare14.LENS_DISTANCE = -0.258;
	entFlare15.LENS_DISTANCE = -0.304;
	entFlare16.LENS_DISTANCE = -0.372;
	entFlare17.LENS_DISTANCE = -0.390;
   entFlare18.LENS_DISTANCE = -0.432;
	entFlare19.LENS_DISTANCE = -0.654;
	entFlare20.LENS_DISTANCE = -1.000;
}

// Setze initiale Flags
void initFlare(ENTITY* _entFlare) {
	_entFlare.flags2 &= ~SHOW;
	set(_entFlare, BRIGHT | PASSABLE | TRANSLUCENT);
}

// Platziere die Linsen relativ zur Kameraposition
void placeFlare(ENTITY* _entFlare) {

	_entFlare.flags2 |= SHOW;
	
	// Sicherstellen, dass der Pan-Winkel der Kamera immer zwischen
	// 0 und 360 liegt.
	vCameraPan = camera.pan;
	while (vCameraPan < 0) vCameraPan +=360;
	while (vCameraPan > 360) vCameraPan -=360;

	// Platziere die Linsen mittig zum Bildschirm
	_entFlare.x = vecTemp1.x*_entFlare.LENS_DISTANCE + 0.5*screen_size.x;
	_entFlare.y = vecTemp1.y*_entFlare.LENS_DISTANCE + 0.5*screen_size.y;
	_entFlare.z = 1000;

	// Drehe die Linsen relativ zur Sonne
	vec_set(vecTemp2,sun_pos);

	
	you = player;
	c_trace(camera.x,vecTemp2.x,IGNORE_ME | IGNORE_YOU | IGNORE_PASSABLE | IGNORE_SPRITES | SCAN_TEXTURE);

	// Wenn eine Entity zwischen den Linsen ist, blende diese aus
	if(HIT_TARGET) {
		if(_entFlare.alpha > 0) {
			_entFlare.alpha -= vLensFlareFadeSpeed * time_step;
		} else {
			_entFlare.alpha = 0;
		}
	}
	else {
		
		// Wenn der Kamerawinkel die Sonne nicht sieht, blende die Linsen langsam aus
		if((vCameraPan > sun_angle.pan + 25) || (vCameraPan < sun_angle.pan - 25) || (camera.tilt < sun_angle.tilt - 20) || (camera.tilt > sun_angle.tilt + 20)) {
			if(_entFlare.alpha > 0){
				_entFlare.alpha -= vLensFlareFadeSpeed * time_step;
			} else{
				_entFlare.alpha = 0;
			}
		}
		else {
		// Wenn die Kamera die Linsen sehen kann, blende diese langsam ein
		
			vecTemp2.x = sqrt(abs(((_entFlare.x - (0.5*screen_size.x))*(_entFlare.x - (0.5*screen_size.x)))+((_entFlare.y - (0.5*screen_size.y))*(_entFlare.y - (0.5*screen_size.y)))));
			if(abs(vecTemp2.x) > (0.5*screen_size.x)) {
				_entFlare.alpha = vLensFlareAlpha - (abs(vecTemp2.x) - (0.5*screen_size.x));
				if(_entFlare.alpha < 0){
					_entFlare.alpha = 0;
				}
			} else {
				if(_entFlare.alpha < vLensFlareAlpha)
				{
					_entFlare.alpha += vLensFlareFadeSpeed * time_step;
				} else {
					_entFlare.alpha = vLensFlareAlpha;
				}
			}
		}
	}
	
	// Alpha der Linse muss zwischen 0 und vLensFlareAlpha liegen
	_entFlare.alpha = clamp(_entFlare.alpha, 0, vLensFlareAlpha);

	// Richte die Linse an der Position der camera-View aus
	rel_for_screen(_entFlare.x,camera);
}


// Initiales Erstellen der Linsen
void createLensFlare() {

	// Setzen der Flags für die Linsen
	initFlare(entFlare1);
	initFlare(entFlare2);
	initFlare(entFlare4);
	initFlare(entFlare5);
	initFlare(entFlare6);
	initFlare(entFlare7);
	initFlare(entFlare8);
	initFlare(entFlare9);
	initFlare(entFlare10);
	initFlare(entFlare11);
	initFlare(entFlare12);
	initFlare(entFlare13);
	initFlare(entFlare14);
	initFlare(entFlare15);
	initFlare(entFlare16);
	initFlare(entFlare17);
	initFlare(entFlare18);
	initFlare(entFlare19);
	initFlare(entFlare20);

	// Linsen sind erstellt aber inaktiv
	vLensFlareState = 0;
}

// Anschalten der Lensflare-Effekte
void	startLensFlare() {

	// Wenn die Linsen nicht erstellt sind, erstelle sie
	if(vLensFlareState == -1) {
		initLensFlarePosition();
		createLensFlare();
	}

	// Wenn die Linsen bereits sichtbar sind, brich ab
	if(vLensFlareState == 1) {
		return;
	}

	// Linsen sind aktiv
	wait(1);
	vLensFlareState = 1;

	// Solange Linsen aktiv sind bewege sie
	while(vLensFlareState == 1)
	{
		
		vec_set(vecTemp1,sun_pos);		
		vec_to_screen(vecTemp1,camera);
		
		vecTemp1.x -= 0.5 * screen_size.x;
		vecTemp1.y -= 0.5 * screen_size.y;
		
		placeFlare(entFlare1);
		placeFlare(entFlare2);
		placeFlare(entFlare4);
		placeFlare(entFlare5);
		placeFlare(entFlare6);
		placeFlare(entFlare7);
		placeFlare(entFlare8);
		placeFlare(entFlare9);
		placeFlare(entFlare10);
		placeFlare(entFlare11);
		placeFlare(entFlare12);
		placeFlare(entFlare13);
		placeFlare(entFlare14);
		placeFlare(entFlare15);
		placeFlare(entFlare16);
		placeFlare(entFlare17);
		placeFlare(entFlare18);
		placeFlare(entFlare19);
		placeFlare(entFlare20);
		
		// entFlare1 wird beim Erstellen initialisiert
		entFlare2.alpha = entFlare1.alpha;
		entFlare4.alpha = entFlare1.alpha;
		entFlare5.alpha = entFlare1.alpha;
		entFlare6.alpha = entFlare1.alpha;
		entFlare7.alpha = entFlare1.alpha;
		entFlare8.alpha = entFlare1.alpha;
		entFlare9.alpha = entFlare1.alpha;
		entFlare10.alpha = entFlare1.alpha;
		entFlare11.alpha = entFlare1.alpha;
		entFlare12.alpha = entFlare1.alpha;
		entFlare13.alpha = entFlare1.alpha;
		entFlare14.alpha = entFlare1.alpha;
		entFlare15.alpha = entFlare1.alpha;
		entFlare16.alpha = entFlare1.alpha;
		entFlare17.alpha = entFlare1.alpha;
		entFlare18.alpha = entFlare1.alpha;
		entFlare19.alpha = entFlare1.alpha;
		entFlare20.alpha = entFlare1.alpha;
		wait(1);
	}

	// Bricht die Schleife ab, schalte den Effekt aus
	vLensFlareVisibility = 0;

	// Verstecke Linsen
	stopLensFlare();
}

void stopLensFlare() {
	entFlare1.flags2 &=~SHOW;
	entFlare2.flags2 &=~SHOW;	
	entFlare4.flags2 &=~SHOW;
	entFlare5.flags2 &=~SHOW;
	entFlare6.flags2 &=~SHOW;
	entFlare7.flags2 &=~SHOW;
	entFlare8.flags2 &=~SHOW;
	entFlare9.flags2 &=~SHOW;
	entFlare10.flags2 &=~SHOW;
	entFlare11.flags2 &=~SHOW;
	entFlare12.flags2 &=~SHOW;
	entFlare13.flags2 &=~SHOW;
	entFlare14.flags2 &=~SHOW;
	entFlare15.flags2 &=~SHOW;
	entFlare16.flags2 &=~SHOW;
	entFlare17.flags2 &=~SHOW;
	entFlare18.flags2 &=~SHOW;
	entFlare19.flags2 &=~SHOW;
	entFlare20.flags2 &=~SHOW;
}

// Schalte den Effekt ein und aus
void lensFlareToggle() {
	snd_stop(vWeatherSoundHandle);
	fog_color = 0;
	nWeatherType = 4;
	switch(vLensFlareState) {
		case -1:
			startLensFlare();
		break;
		case 0:
			startLensFlare();
		break;
		case 1:
			vLensFlareState = 0;
		break;
	}
}

#endif