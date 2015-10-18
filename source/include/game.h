#ifndef GAME_H_
#define GAME_H_

#define DAY_TIME_SPEED 20

#define DAY 0
#define NIGHT 1

var dayOrNight = DAY;

int dayTime = 28800; // 1000 = 1 hour
var hours = 12;
var minutes = 0;
var isGameOver = 0;


void backToMenu();
void startGame();

void gameOver();

#endif