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
	
	pssm_run(4);

	var sunlightFactor = 0;
	
	while(1)
	{
		updateGui();
		
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
			snd_play(sndNightStart, 100, 0);
		}
		
		// Night
		if(sunlightFactor <= 0.0)
		{
			sun_light = -sunlightFactor*30;
		}
		
		// Day start
		if (dayTime == 28800)
		{
			snd_play(sndDayStart, 100, 0);
		}
		
		sun_angle.pan = (dayTime-28800.0)/(60.0*60.0*12.0)*180.0;
		sun_angle.tilt = abs(ang(asinv(sunlightFactor)))*70.0/180.0+10.0;
		
		wait(1);
	}
}

#endif