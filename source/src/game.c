#ifndef GAME_C_
#define GAME_C_

void startGame()
{
	reset_hints();
	endMenu();
	wait(1);
	level_load("mainLevel.wmb");
//	level_load("menuLevel2.wmb");
//wait(1); // wait until last_error becomes valid
	on_esc = NULL;
	gameCameraInit();
	startIngameGUI();
	playMusicGameDay();
	startSnow();
	
	// Start a new day
	dayOrNight = DAY;
	dayTime = 28800;
	
	hut_restart();
	item_restart();
	show_dayhint();

	set(mtl_model, PASS_SOLID);
	random_seed(8);
	
	VECTOR tempVector;
	int i;
	for(i = 0; i < 100; i++)
	{
		vec_set(tempVector, vector(random(6400)-3200, random(6400)-3200, 0));
		if(vec_length(tempVector) < 800)
		{
			i--;
			continue;
		}
		
		tempVector.z = 5000;
		tempVector.z -= c_trace(tempVector, vector(tempVector.x, tempVector.y, -5000), SCAN_TEXTURE|IGNORE_PASSABLE|IGNORE_FLAG2);
		if(hit.nz < 0.5)
		{
			i--;
			continue;
		}
		
//		ENTITY *tree = ent_create("pine_3.mdl", tempVector, 0);
		ENTITY *tree = ent_create("pine_3_reduced.mdl", tempVector, 0);
		set(tree, PASSABLE|SHADOW);
		vec_scale(tree.scale_x, random(0.5) + 0.5);
		tree.pan = random(360);
		tree->emask &= ~DYNAMIC;
		
	}
	
	random_seed(0);
	pssm_run(4);
//wait(1); // fucking wait(1) seems to fix something which breaks everything

	var sunlightFactor = 0;
	var dayCounter = 0;
	while(isGameOver < 2)
	{
		if (isGameOver == 0)
		{
			updateGui();
			goblin_loop();
			item_spawn_loop();
			
			dayTime += DAY_TIME_SPEED * time_step * 1;
			if(dayTime >= 86400)
			{
				dayTime -= 86400;
				dayCounter += 1;
				
				goblinSpawnDelay = maxv(16.0*3.0-dayCounter*2, 1);
			}
			
			hours = integer(dayTime/60.0/60.0);
			minutes = (integer(dayTime)-hours*60.0*60.0)/60.0;
			
			sunlightFactor = sinv((dayTime-28800.0)/(60.0*60.0*12.0)*180.0);
			
			// Day start
			if(dayTime >= 28800 && dayOrNight == NIGHT && dayTime < 72000)
			{
				dayOrNight = 3;
				fadeWithBlack(startDay);
			}
			
			// Day
			if(sunlightFactor > 0.0)
			{
				sun_light = sunlightFactor*60;
			}
			
			// Night start
			if(dayTime >= 72000 && dayOrNight == DAY)
			{
				dayOrNight = 3;
				fadeWithBlack(startNight);
			}
			
			// Night
			if(sunlightFactor <= 0.0)
			{
				sun_light = -sunlightFactor*30;
			}
			
			sun_angle.pan = (dayTime-28800.0)/(60.0*60.0*12.0)*180.0;
			sun_angle.tilt = abs(ang(asinv(sunlightFactor)))*70.0/180.0+10.0;
			
			d3d_fogcolor1.red = sun_light*255.0/100.0;
			d3d_fogcolor1.green = sun_light*255.0/100.0;
			d3d_fogcolor1.blue = sun_light*255.0/100.0;
		}
		
		/*if (key_l) {
			while(key_l) wait(1);
			shake();
		}*/
		
		
		if (key_esc) {
			while(key_esc) wait(1);
			break;
		}
		wait(1);
	}
	isGameOver = 0;	
	backToMenu();
}

void backToMenu() {
	on_space = NULL;
	on_mouse_left = NULL;	
	endIngameGUI();
	stopSnow();
	wait(1);
	//error("loading menu");
	pssm_run(0);
	wait(1);
	level_load("menuLevel2.wmb");
	startMenu();
}

void gameOver() {
	isGameOver = 1;
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
	isGameOver = 2;
	//backToMenu();
}

void startDay()
{
	if(!player)
	{
		return;
	}
	
	dayOrNight = DAY;
	snd_play(sndDayStart, soundVolume, 0);
	on_space = NULL;
	on_mouse_left = NULL;
	ent_remove(player);
	mouse_mode = 0;
	ent_create("player.mdl", vector(-147, -44, 0), actPlayerMove);
	stopMusicGame();
	playMusicGameDay();
	show_dayhint();
}

void startNight()
{
	if(!player)
	{
		return;
	}
	
	dayOrNight = NIGHT;
	snd_play(sndNightStart, soundVolume, 0);
	mouse_mode = 1;
	ent_remove(player);
	ent_create("player.mdl", vector(entHut.x, entHut.y, entHut.z + 200), actPlayerShoot);
	on_space = throwSnowball;
	on_mouse_left = throwSnowball;
	stopMusicGame();
	playMusicGameNight();
	show_nighthint();
}

void fadeWithBlack(void *block)
{
	PANEL *panel = pan_create(NULL, 100);
	panel.bmap = bmap_createblack(screen_size.x, screen_size.y, 24);
	set(panel, SHOW|TRANSLUCENT);
	
	while(panel.alpha < 100)
	{
		panel.alpha += time_step * 8.0;
		wait(1);
	}
	
	void (*blubb)();
	blubb = block;
	blubb();
	
	while(panel.alpha > 0)
	{
		panel.alpha -= time_step * 8.0;
		wait(1);
	}
	
	ptr_remove(panel);
}

#endif