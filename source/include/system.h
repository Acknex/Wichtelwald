#ifndef SYSTEM_H_
#define SYSTEM_H_


#define PLAYER 1
#define WICHTEL 2
#define SCHNEEBALL 3
#define HOLZSCHEIT 4
#define HOLZHAUFEN 5
#define HUETTE 6
#define SCHUSS 7

#define ENTITY_TYPE skill10

void sysInit();
void cleanUpGame();

void (*exitFunction)();

#endif