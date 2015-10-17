#ifndef MUSIC_H_
#define MUSIC_H_

SOUND* sndMusicMenu = "music//Song1.OGG";
SOUND* sndMusicGame = "music//Song1.OGG";

var menuMusicHandle = 0;
var gameMusicHandle = 0;

void playMusicMenu();
void playMusicGame();
void stopMusicMenu();
void stopMusicGame();

#endif