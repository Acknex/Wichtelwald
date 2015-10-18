#ifndef GAME_H_
#define GAME_H_

#define DAY_TIME_SPEED 150

#define DAY 0
#define NIGHT 1

var dayOrNight = DAY;

var dayTime = 28800;
var hours = 8;
var minutes = 0;
var isGameOver = 0;


void backToMenu();
void startGame();

void startNight();
void startDay();
void fadeWithBlack(void *block);

void gameOver();

#endif