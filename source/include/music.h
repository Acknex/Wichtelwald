#ifndef MUSIC_H_
#define MUSIC_H_

SOUND* sndMusicMenu = "Song1.OGG";
SOUND* sndMusicGameDay = "Song2_Tag.OGG";
SOUND* sndMusicGameNight = "Song3.OGG";

SOUND* sndThrow1 = "throw1.ogg";
SOUND* sndThrow2 = "throw2.ogg";

SOUND* sndDayStart = "Hahn.OGG";
SOUND* sndNightStart = "Wolf.OGG";

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