#ifndef WEATHER_H
#define WEATHER_H

BMAP* bmapRainDrop = "rain.tga";
BMAP* bmapDust = "dust.tga";

SOUND* sndRain = "rain.wav";
SOUND* sndWind = "wind.wav";

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
void stopSnow();
function pRain(PARTICLE* p);
void startRain();
void cloudsToggle();
function startTornado();
function pTornado(PARTICLE* p);
function pTornadoAlphaFade(PARTICLE* p);


ENTITY* entClouds = {
	type = "clouds.tga";
	flags2 = SKY | DOME;
	u=1;
	v=1;
	layer = 2;
}

#endif



