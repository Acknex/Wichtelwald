#ifndef GAME_C_
#define GAME_C_

void startGame()
{
	endMenu();
	level_load("maps//mainLevel.wmb");
	on_esc = NULL;
	gameCameraInit();
	startIngameGUI();
	playMusicGameDay();
	startSnow();
	
	// Start a new day
	dayOrNight = DAY;
	dayTime = 28800;
	
	sun_light = 20;
	
	random_seed(8);
	
	VECTOR tempVector;
	int i;
	for(i = 0; i < 150; i++)
	{
		vec_set(tempVector, vector(random(6400)-3200, random(6400)-3200, 0));
		if(vec_length(tempVector) < 800)
		{
			i--;
			continue;
		}
		
		tempVector.z = 5000;
		tempVector.z -= c_trace(tempVector, vector(tempVector.x, tempVector.y, -5000), SCAN_TEXTURE|IGNORE_PASSABLE);
		if(hit.nz < 0.5)
		{
			i--;
			continue;
		}
		
		ENTITY *tree = ent_create("models//pine_3.mdl", tempVector, 0);
		set(tree, PASSABLE|SHADOW);
		vec_scale(tree.scale_x, random(0.5) + 0.5);
		tree.pan = random(360);
	}
	
	// pssm_run(4);

	var sunlightFactor = 0;
	
	while(1)
	{
		updateGui();
		goblin_loop();
//		wait(1);
//dayOrNight = NIGHT; continue;
		dayTime += DAY_TIME_SPEED;
		if(dayTime >= 86400)
		{
			dayTime = 0;
		}
		
		hours = dayTime/60/60;
		minutes = (dayTime-hours*60*60)/60;
		
		sunlightFactor = sinv((dayTime-28800.0)/(60.0*60.0*12.0)*180.0);
		
		// Day
		if(sunlightFactor > 0.0)
		{
			sun_light = sunlightFactor*100;
		}
		
		// Night start
		if(dayTime == 72000)
		{
			dayOrNight = NIGHT;
			snd_play(sndNightStart, soundVolume, 0);
			mouse_mode = 1;
			ent_remove(player);
			ent_create("models//player.mdl", vector(entHut.x, entHut.y, entHut.z + 200), actPlayerShoot);
			on_mouse_left = throwSnowball;
			stopMusicGame();
			playMusicGameNight();
		}
		
		// Night
		if(sunlightFactor <= 0.0)
		{

			sun_light = -sunlightFactor*30;
		}
		
		// Day start
		if (dayTime == 28800)
		{
			dayOrNight = DAY;
			snd_play(sndDayStart, soundVolume, 0);
			on_mouse_left = NULL;
			ent_remove(player);
			mouse_mode = 0;
			ent_create("models//player.mdl", vector(-147, -44, 0), actPlayerMove);
			stopMusicGame();
			playMusicGameDay();
		}
		
		sun_angle.pan = (dayTime-28800.0)/(60.0*60.0*12.0)*180.0;
		sun_angle.tilt = abs(ang(asinv(sunlightFactor)))*70.0/180.0+10.0;
		
		d3d_fogcolor1.red = sun_light*255.0/100.0;
		d3d_fogcolor1.green = sun_light*255.0/100.0;
		d3d_fogcolor1.blue = sun_light*255.0/100.0;
		
		if (key_l) {
			while(key_l) wait(1);
			shake();
		}
		
		
		if (key_esc) {
			while(key_esc) wait(1);
			break;
		}
		wait(1);
	}
	
	backToMenu();
}

void backToMenu() {	
	reset(panGameOver, SHOW);
	isGameOver = 0;
	endIngameGUI();
	level_load("maps//menuLevel.wmb");
	startMenu();
}

void gameOver() {
	isGameOver = 1;
	on_mouse_left = NULL;
	endIngameGUI();
	ent_remove(player);
	panGameOver.pos_x = screen_size.x / 2 - bmap_width(bmapGameOver) / 2;
	panGameOver.pos_y = screen_size.y / 2 - bmap_height(bmapGameOver) / 2;
	set(panGameOver, SHOW);
	
	vec_set(vecCamTmp, entHut.x);
	int counter = 1000;
	while(counter > 0) {
		cam_angle +=0.005 * time_step;
		camera.x = cos(cam_angle) * 768;
		camera.y = sin(cam_angle) * 768;
		vec_diff(vecCamTmp.x, nullvector, camera.x);
		vec_to_angle(camera.pan, vecCamTmp);
		counter--;
		wait(1);
	}
	
	reset(panGameOver, SHOW);
	isGameOver = 0;
	backToMenu();
}

#endif