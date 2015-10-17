#ifndef MUSIC_H_
#define MUSIC_H_

SOUND* sndMusicMenu = "music//Song1.OGG";
SOUND* sndMusicGameDay = "music//Song2_Tag.OGG";
SOUND* sndMusicGameNight = "music//Song2_Tag.OGG";

var menuMusicHandle = 0;
var gameMusicHandle = 0;

void playMusicMenu();
void playMusicGameDay();
void playMusicGameNight();
void stopMusicMenu();
void stopMusicGame();

#endif