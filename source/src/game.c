#ifndef GAME_C_
#define GAME_C_

void startGame()
{
	endMenu();
	level_load("maps//mainLevel.wmb");
	gameCameraInit();
	startIngameGUI();
	playMusicGameDay();
	on_space = throwSnowball;
	startSnow();
	
	sun_light = 100;
	
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
	
	pssm_run(4);

	while(1)
	{
		updateGui();
		dayTime +=DAY_TIME_SPEED;
		if (dayTime >= 24000) {
			dayTime = 0;
		}
		
		// Day
		if ((dayTime > 8000) && (dayTime < 20000)) {
		}
		
		// Night start
		if (dayTime == 20000) {
			snd_play(sndNightStart, 100, 0);
			camera.ambient = 0;
			vec_set(sun_color.blue, vector(0,0,0));
		}
		
		// Night
		if ((dayTime > 20000) && (dayTime < 8000)) {
			
		}
		
		// Day start
		if (dayTime == 8000) {
			snd_play(sndDayStart, 100, 0);
			camera.ambient = 50;
			vec_set(sun_color.blue, vector(128,128,128));
		}
		
		hours = dayTime / 1000;
		minutes = (dayTime - (hours * 1000)) / 16.6;
		
		// Calculate ambient from 0 - 50
		
		
		wait(1);
	}
}

#endif