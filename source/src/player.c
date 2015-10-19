#ifndef PLAYER_C_
#define PLAYER_C_
#include <particles.c>

void ball_event();
void ball_fade_p(PARTICLE* p);
void p_ball_explode(PARTICLE* p);

SOUND* sndSnowballHit = "snowball_hit.OGG";

void animatePlayer(var _distAhead) {
	if(_distAhead < 0.0)
		return;
	
	animationFactor = abs(_distAhead);
	
	if (animationFactor != 0)	{
		my.ANIMATION_PERCENTAGE += 1.0 * animationFactor;
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
		vec_normalize(vecTemp, (WALK_SPEED/*+key_shiftl*RUN_SPEED*/)*time_step);
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
		camera.pan -= mouse_force.x*4.0;
		camera.tilt += mouse_force.y*4.0;
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
	my->emask |= ENABLE_ENTITY;
	my->event = ball_event;
	
	VECTOR vBallForce;
	vec_for_angle(vBallForce.x, vector(camera.pan, camera.tilt + 3, camera.roll));
	vec_scale(vBallForce.x, 24);
	
	int counter = 100;
	
	while(counter > 0) {
		c_move(me, vBallForce.x, nullvector, ACTIVATE_TRIGGER | IGNORE_ME|IGNORE_PASSENTS|IGNORE_PASSABLE|IGNORE_SPRITES|USE_BOX);
		counter -=1 * time_step;
		if(is(my, did_hit))
		{
			counter = 0;
		}
		wait(1);
	}
		
	set(my, PASSABLE);
	while(my.scale_x > 0) {
		wait(1);
		my.scale_x -=0.1 * time_step;
		my.scale_y -=0.1 * time_step;
		my.scale_z -=0.1 * time_step;
	}
	ptr_remove(me);
}

void ball_fade_p(PARTICLE* p)
{
	p.alpha -= p.skill_a*time_step;
	if (p.alpha <= 0) p.lifespan = 0;
	
	p.size = minv(p.skill_b, p.size+time_step*5);
}

void p_ball_explode(PARTICLE* p)
{
	VECTOR vTemp;
	vec_randomize(vTemp,40);
	vec_normalize(vTemp,5);
	vec_add(p.vel_x,vTemp);
	vec_set(p.blue,vector(240,240, 240));
	set(p, MOVE | BRIGHT | TRANSLUCENT);
	p.alpha = 80;
	p.size = 10;
	p.skill_a = 10;
	p.event = ball_fade_p;
	p.lifespan = 1200+random(600);
	p.skill_b = 10 + random(7);
}

void ball_event()
{
	if(event_type == EVENT_ENTITY && you != NULL)
	{
		set(my, did_hit);	
		effect(p_ball_explode, 40, my->x, nullvector);
		snd_play(sndSnowballHit, soundVolume, 0);
	}
}

void throwSnowball() {
	if (player == NULL) return;
	
	if (hutSnowballCount > 0) {
	
		VECTOR vecSpawnPoint;
		vec_set(vecSpawnPoint, vector(30,0,0));
		vec_rotate(vecSpawnPoint, camera.pan);
		vec_add(vecSpawnPoint, camera.x);
		
		
		ENTITY* entBall = ent_create ("snowball.mdl", vecSpawnPoint, actBall);
		
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