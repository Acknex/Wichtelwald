#ifndef MUSIC_H_
#define MUSIC_H_

SOUND* sndMusicMenu = "music//Song1.OGG";
SOUND* sndMusicGameDay = "music//Song2_Tag.OGG";
SOUND* sndMusicGameNight = "music//Song3.OGG";

SOUND* sndThrow1 = "sounds//throw1.ogg";
SOUND* sndThrow2 = "sounds//throw2.ogg";

SOUND* sndDayStart = "sounds//Hahn.OGG";
SOUND* sndNightStart = "sounds//Wolf.OGG";

var menuMusicHandle = 0;
var gameMusicHandle = 0;

var musicVolume = 50;
var soundVolume = 100;

void playMusicMenu();
void playMusicGameDay();
void playMusicGameNight();
void stopMusicMenu();
void stopMusicGame();

#endif