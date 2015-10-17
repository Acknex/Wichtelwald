#ifndef PLAYER_C_
#define PLAYER_C_

void animatePlayer(VECTOR* _distAhead) {
	
	if (abs(_distAhead.x) > abs(_distAhead.y)) {
		animationFactor = abs(_distAhead.x)*0.32;
	} else {
		animationFactor = abs(_distAhead.y)*0.32;
	}
	
	if (animationFactor != 0)	{
		my.ANIMATION_PERCENTAGE += 60 * time_step * animationFactor;
		ent_animate(me,"walk",my.ANIMATION_PERCENTAGE,ANM_CYCLE);
	} else { 
		my.ANIMATION_PERCENTAGE += 5 * time_step;
		ent_animate(me,"stand",my.ANIMATION_PERCENTAGE,ANM_CYCLE);
	}
}

void actPlayerMove_2() {
	
	player = me;
	c_setminmax(me);
	
	float traceDown = 0;
	VECTOR vecPlayerMoveSpeed;
	
	while(1) {
		traceDown = c_trace(my.x, vector(my.x,my.y,my.z-500), IGNORE_ME|IGNORE_PASSENTS|IGNORE_PASSABLE|IGNORE_SPRITES|USE_BOX );
		vec_set(vecPlayerMoveSpeed, vector((key_w - key_s) * (WALK_SPEED+key_shiftl*RUN_SPEED) * time_step, 0, -(traceDown - PLAYER_HEIGHT)));
		my.pan += (key_a - key_d) * time_step * 10;
		c_move(me, vecPlayerMoveSpeed.x, nullvector, IGNORE_PASSABLE | IGNORE_PASSENTS | GLIDE);
		animatePlayer(vecPlayerMoveSpeed.x);
		cameraTopPlayer();
		wait(1);
	}
}

void actPlayerMove() {
	
	player = me;
	c_setminmax(me);
	
	float traceDown = 0;
	VECTOR vecPlayerMoveSpeed;
	VECTOR vecPlayerRotation;
	VECTOR vecTemp;
	float cycleRotation = 0;
	
	while(1) {
		traceDown = c_trace(my.x, vector(my.x,my.y,my.z-500), IGNORE_ME|IGNORE_PASSENTS|IGNORE_PASSABLE|IGNORE_SPRITES|USE_BOX );
		
		vec_set(vecTemp, vector((key_w - key_s), (key_a - key_d), 0.0));
		vec_normalize(vecTemp, (WALK_SPEED+key_shiftl*RUN_SPEED)*time_step);
		vec_set(vecPlayerMoveSpeed, vector(vecTemp.x, vecTemp.y, -(traceDown - PLAYER_HEIGHT)));
		
		vec_to_angle(vecPlayerRotation, vecPlayerMoveSpeed);
		
		player.pan = vecPlayerRotation.x;
		
		c_move(me, nullvector, vecPlayerMoveSpeed.x, IGNORE_PASSABLE | IGNORE_PASSENTS | GLIDE);
		animatePlayer(vecPlayerMoveSpeed);
		cameraTopPlayer();
		wait(1);
	}
}

void actBall() {
	wait(-5);
	pXent_settype(me, 0, 0);
	while(my.scale_x > 0) {
		my.scale_x -=0.1;
		my.scale_y -=0.1;
		my.scale_z -=0.1;
		wait(7);
	}
	ptr_remove(me);
}

void throwSnowball() {
	if (player == NULL) return;
	
	VECTOR vecSpawnPoint;
	vec_set(vecSpawnPoint, vector(30,0,10));
	vec_rotate(vecSpawnPoint, player.pan);
	vec_add(vecSpawnPoint, player.x);
	
	
	ENTITY* entBall = ent_create ("models//snowball.mdl", vecSpawnPoint, actBall);
	VECTOR vBallForce;
	vec_for_angle(vBallForce.x, vector(player.pan, player.tilt + 3, player.roll));
	vec_scale(vBallForce.x, 24);
	pXent_settype (entBall, PH_RIGID, PH_SPHERE);
	pXent_addforcelocal (entBall, vBallForce, entBall.x);
	
	int sound = 1 + integer(random(2));
	switch(sound) {
		case 1: snd_play(sndThrow1, 100, 0); break;
		case 2: snd_play(sndThrow2, 100, 0); break;
	}
}

#endif