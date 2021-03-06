#ifndef PLAYER_H_
#define PLAYER_H_

#define WALK_SPEED 20
#define RUN_SPEED 10
#define PLAYER_HEIGHT 3
#define did_hit FLAG4

#define ANIMATION_PERCENTAGE skill1

float animationFactor = 0;

BMAP* bmapCrosshair = "crosshair.tga";

action actPlayerMove();
action actPlayerShoot();
void animatePlayer(VECTOR* _distAhead);

action actBall();
void throwSnowball();

int shakeTime = 0;
void shake();

#endif