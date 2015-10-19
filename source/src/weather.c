#ifndef WEATHER_C
#define WEATHER_C

function pSnow(PARTICLE* p) {
	p.size = 4;
	p.alpha = 100;
	p.red = 128;
	p.green = 128;
	p.blue = 128;
	p.skill_c = 0.5;
	vec_add(p.x,vector(random(1000)-500, random(1000)-500,0));
	p.lifespan = 60;
	p.gravity = 0.2;
	p.flags = BRIGHT | TRANSLUCENT | MOVE;
	p.event = NULL;
}

function pRain(PARTICLE* p) {
	p.bmap = bmapRainDrop;
	p.alpha = 100;
	vec_add(p.x,vector(random(1000)-500, random(1000)-500,0));
	p.lifespan = 30;
	p.gravity = 7;
	p.flags = BRIGHT | TRANSLUCENT | MOVE;
	p.event = NULL;
}

void startSnow() {
	entClouds.u = 1;
	entClouds.v = 1;
	fog_color = 1;
	camera.fog_start = 600;
	camera.fog_end = 1100;
	camera.ambient = -30;

	snd_stop(vWeatherSoundHandle);
	vWeatherSoundHandle = snd_loop(sndWind, 20, 0);
	
	VECTOR vecTemp;
	nWeatherType = 0;
	while(nWeatherType == 0) {
		
		vecTemp.x = -1000 + random(2000);
		vecTemp.y = -1000 + random(2000);
		vecTemp.z = camera.z + 100;
		if (player != NULL) vec_add(&vecTemp, &player->x);
		effect(pSnow,maxv(1,random(10)),vecTemp,vector(0,0,-4));
		wait(1);
	}
}

void stopSnow() {
	nWeatherType = -1;
}

void startRain() {
	
	entClouds.u = 1;
	entClouds.v = 1;

	fog_color = 5;
	camera.fog_start = 100;
	camera.fog_end = 1000;
	camera.ambient = -60;

	snd_stop(vWeatherSoundHandle);
	vWeatherSoundHandle = snd_loop(sndRain, 20, 0);
	VECTOR vecTemp;
	nWeatherType = 1;

	while(nWeatherType == 1) {
		vecTemp.x = camera.x + random(2)+(-1);
		vecTemp.y = camera.y + random(2)+(-1);
		vecTemp.z = camera.z + 100;
		effect(pRain,maxv(1,random(40)),vecTemp,vector(0,0,-4));
		wait(1);
	}
}

function pTornadoAlphaFade(PARTICLE* p) {
	p.size += 1*time_step;
	p.alpha -= 0.5*time_step;
	if(p.alpha < 0) {
		p.lifespan = 0;
	}
}

function pTornado(PARTICLE* p) {
	p.bmap = bmapDust;
	p.vel_x = random(-8) - (-8 /2);
	p.vel_y = random(-8) - (-8 /2);
	p.vel_z = 5;
	p.size = 1;
	set(p, MOVE | TRANSLUCENT);
	p.alpha = 30 ;
	p.gravity = -0.5;
	p.event = pTornadoAlphaFade;
}

function startTornado() {

	entClouds.u = 8;
	entClouds.v = 12;

	fog_color = 0;
	camera.ambient = 0;

	snd_stop(vWeatherSoundHandle);
	vWeatherSoundHandle = snd_loop(sndWind, 70, 0);

	VECTOR vecOffset;
	vec_set(vecOffset, vector(10,10,0));
	nWeatherType = 2;

	VECTOR vecTemp3;

	while(nWeatherType == 2) {
		vTornadoAngle += 15*time_step;
		vecTemp3.x =vecOffset.x + 30*sin(vTornadoAngle);
		vecTemp3.y =vecOffset.y + 30*cos(vTornadoAngle);
		vecTemp3.z =vecOffset.z + 0;
		effect(pTornado,4 ,vecTemp3,normal);
		wait(1);
	}
}

void cloudsToggle() {
	if (entClouds.flags2 & SHOW) {
		entClouds.flags2 &=~SHOW;		
	} else {
		entClouds.flags2 |=SHOW;
	}
}

#endif