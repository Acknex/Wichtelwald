#ifndef PLAYER_H_
#define PLAYER_H_

#define WALK_SPEED 2
#define RUN_SPEED 4
#define PLAYER_HEIGHT 6

#define ANIMATION_PERCENTAGE skill1

float animationFactor = 0;

action actPlayerMove();
void animatePlayer(VECTOR* _distAhead);

void throwSnowball();

#endif