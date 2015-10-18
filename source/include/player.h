#ifndef PLAYER_H_
#define PLAYER_H_

#define WALK_SPEED 10
#define RUN_SPEED 10
#define PLAYER_HEIGHT 3

#define ANIMATION_PERCENTAGE skill1

float animationFactor = 0;

action actPlayerMove();
void animatePlayer(VECTOR* _distAhead);

action actBall();
void throwSnowball();

#endif