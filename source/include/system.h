#ifndef SYSTEM_H_
#define SYSTEM_H_


#define PLAYER 1
#define GOBLIN 2
#define SNOWBALL 3
#define LOGS 4
#define WOODPILE 5
#define HUT 6
#define SHOT 7

#define ENTITY_TYPE skill10
#define ATTACK_POWER skill11

void sysInit();
void cleanUpGame();

void (*exitFunction)();

#endif