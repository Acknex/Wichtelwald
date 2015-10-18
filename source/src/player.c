#ifndef PLAYER_C_
#define PLAYER_C_

void animatePlayer(var _distAhead) {
	if(_distAhead < 0.0)
		return;
	
	animationFactor = abs(_distAhead);
	
	if (animationFactor != 0)	{
		my.ANIMATION_PERCENTAGE += 1.2 * animationFactor;
		ent_animate(me, "walk", my.ANIMATION_PERCENTAGE, ANM_CYCLE);
	}
}

void actPlayerMove() {
	
	player = me;
	my->trigger_range = 40;
	c_setminmax(me);
	camera.tilt = 310;
	camera.pan = 0;
	
	float traceDown = 0;
	VECTOR vecPlayerMoveSpeed;
	VECTOR vecPlayerRotation;
	VECTOR vecTemp;
	float cycleRotation = 0;
	
	while(me) {
		traceDown = c_trace(my.x, vector(my.x,my.y,my.z-500), IGNORE_ME|IGNORE_PASSENTS|IGNORE_PASSABLE|IGNORE_SPRITES|USE_BOX );
		
		vec_set(vecTemp, vector((key_w - key_s), (key_a - key_d), 0.0));
		vec_normalize(vecTemp, (WALK_SPEED+key_shiftl*RUN_SPEED)*time_step);
		vec_to_angle(vecPlayerRotation, vecTemp);
		vec_set(vecPlayerMoveSpeed, vector(vecTemp.x, vecTemp.y, -(traceDown - PLAYER_HEIGHT)));
		
		player.pan = vecPlayerRotation.x;
		
		var dist = c_move(me, nullvector, vecPlayerMoveSpeed.x, IGNORE_PASSABLE | IGNORE_PASSENTS | GLIDE | ACTIVATE_TRIGGER);
		animatePlayer(dist);
		cameraTopPlayer();
		wait(1);
	}
}

void actPlayerShoot() {
	player = me;
	
	set(me, INVISIBLE);
	cameraShooter();
	mouse_map = bmapCrosshair;
	
	while(me) {
		camera.pan -=mouse_force.x;
		camera.tilt += mouse_force.y;
		if (camera.tilt > 20) camera.tilt = 20;
		if (camera.tilt < -35) camera.tilt = -35;
		mouse_pos.x = screen_size.x / 2;
		mouse_pos.y = screen_size.y / 2;
		wait(1);
	}
	
}

void actBall() {
	my->ENTITY_TYPE = SHOT;
	my->trigger_range = 40;
	
	VECTOR vBallForce;
	vec_for_angle(vBallForce.x, vector(camera.pan, camera.tilt + 3, camera.roll));
	vec_scale(vBallForce.x, 24);
	
	int counter = 1000;
	
	while(counter > 0) {
		c_move(me, vBallForce.x, nullvector, ACTIVATE_TRIGGER | IGNORE_ME|IGNORE_PASSENTS|IGNORE_PASSABLE|IGNORE_SPRITES|USE_BOX);
		counter -=1 * time_step;
		wait(1);
	}
		
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
	
	if (hutSnowballCount > 0) {
	
		VECTOR vecSpawnPoint;
		vec_set(vecSpawnPoint, vector(30,0,0));
		vec_rotate(vecSpawnPoint, camera.pan);
		vec_add(vecSpawnPoint, camera.x);
		
		
		ENTITY* entBall = ent_create ("models//snowball.mdl", vecSpawnPoint, actBall);
		
		//pXent_settype (entBall, PH_RIGID, PH_SPHERE);
		//pXent_addforcelocal (entBall, vBallForce, entBall.x);
		
		int sound = 1 + integer(random(2));
		switch(sound) {
			case 1: snd_play(sndThrow1, 100, 0); break;
			case 2: snd_play(sndThrow2, 100, 0); break;
		}
		
		hutSnowballCount--;
	}
}

void shake() {
	proc_kill(shake);
	shakeTime +=20;
	while(shakeTime > 0) {
		camera.roll = random(10);
		shakeTime--;
		wait(1);
	}
	camera.roll = 0;
}

#endif