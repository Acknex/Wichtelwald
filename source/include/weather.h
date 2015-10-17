#ifndef WEATHER_H
#define WEATHER_H

BMAP* bmapRainDrop = "graphics//rain.tga";
BMAP* bmapDust = "graphics//dust.tga";

SOUND* sndRain = "sounds//rain.wav";
SOUND* sndWind = "sounds//wind.wav";

var vWeatherSoundHandle;

ENTITY* entTornado;
var vTornadoAngle;

ENTITY* mountain_cube =
{
  type = "skyday+6.tga";
  flags2 = SKY | CUBE | SHOW;
  layer = 2;
  z = 30;
}

int nWeatherType = 0;

function pSnow(PARTICLE* p);
void startSnow();
function pRain(PARTICLE* p);
void startRain();
void cloudsToggle();
function startTornado();
function pTornado(PARTICLE* p);
function pTornadoAlphaFade(PARTICLE* p);


ENTITY* entClouds = {
	type = "graphics//clouds.tga";
	flags2 = SKY | DOME;
	u=1;
	v=1;
	layer = 2;
}

#endif



