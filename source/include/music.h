#ifndef MUSIC_H_
#define MUSIC_H_

SOUND* sndMusicMenu = "music//Song1.OGG";
SOUND* sndMusicGameDay = "music//Song2_Tag.OGG";
SOUND* sndMusicGameNight = "music//Song2_Tag.OGG";

SOUND* sndThrow1 = "sounds//throw1.ogg";
SOUND* sndThrow2 = "sounds//throw2.ogg";

var menuMusicHandle = 0;
var gameMusicHandle = 0;

void playMusicMenu();
void playMusicGameDay();
void playMusicGameNight();
void stopMusicMenu();
void stopMusicGame();

#endif