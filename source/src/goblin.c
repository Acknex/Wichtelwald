#ifndef GOBLIN_C
#define GOBLIN_C

var goblinSpeed = 5;

var goblinSpawnDist = 1300;
var goblinSpawnTimer = 0;
var goblinLastSpawnAngle = 0;

SOUND* sndGobboRun = "Fussstapfen1.OGG";
SOUND* sndGobboKill = "Wichtel_Tod.OGG";

void goblin_spawn();
void goblin_event();
void goblin();
void goblin_hat();

void goblin_loop()
{

	if (dayOrNight == NIGHT)
	{
		if (goblinSpawnTimer > goblinSpawnDelay)
		{
			goblin_spawn();
			goblinSpawnTimer -= goblinSpawnDelay;
		}
		else
		{
			goblinSpawnTimer += time_step;
		}
	}
}

void goblin_spawn()
{
	ENTITY* gobbo;
	VECTOR spawnPos;
	ANGLE spawnAngle;
	var gobboAngle;
	
	do
	{
		gobboAngle = random(360);
	} while (absv(gobboAngle - goblinLastSpawnAngle) < 30);
	goblinLastSpawnAngle = gobboAngle;
	
	vec_set(&spawnPos, vector(goblinSpawnDist, 0, 300));
	vec_set(&spawnAngle, vector(gobboAngle - 180, 0, 0));
	vec_rotate(&spawnPos, &spawnAngle);
	
	gobbo = ent_create("wichtel_rot.mdl", &spawnPos, goblin);
	gobbo->pan = gobboAngle;
}

void goblin()
{
	c_setminmax(me);
	my->trigger_range = 40;
	set(my, SHADOW);
	my->emask |= ENABLE_TRIGGER | ENABLE_IMPACT;
	my->event = goblin_event;
	my->ENTITY_TYPE = GOBLIN;
	my->ATTACK_POWER = 1;
	ent_playloop(me, sndGobboRun, soundVolume * 10);
	while (dayOrNight == NIGHT && isGameOver == 0 &&(!is(my, is_dead)))
	{
		if (c_trace(&my->x, vector(my->x, my->y, my->z - 1000), IGNORE_ME | IGNORE_PASSABLE | IGNORE_PASSENTS) > 0)
		{
			my->z = hit->z - my->min_z + 2;
		}
		c_move(me,vector(goblinSpeed * time_step,0,0),nullvector, IGNORE_PASSABLE | IGNORE_PASSENTS | GLIDE | ACTIVATE_TRIGGER | IGNORE_FLAG2);
		my->gobboDist += goblinSpeed * time_step;
		ent_animate(me, "walk", (my->gobboDist % 100) * 1, ANM_CYCLE);
		wait (1);
	}
	my->alpha = 100;
	set(my, TRANSLUCENT);
	my->gobboDist = 0;
	if (!is(my, is_collided) && is(my, is_dead))
	{
		snd_play(sndGobboKill, soundVolume,0);
	}
	while (my->alpha > 0)
	{
		wait (1);
		my->alpha -= 5* time_step;
		my->gobboDist += 2 * time_step;
		if (!is(my, is_collided) && is(my, is_dead))
		{
			ent_animate(me, "shake", (my->gobboDist % 20) * 5, ANM_CYCLE);
		}
		else
		{
			ent_animate(me, "victory", (my->gobboDist % 20) * 5, ANM_CYCLE);
		}
	}

	if (!is(my, is_collided) && is(my, is_dead))
	{
		ent_create("hat.mdl", vector(my->x, my->y, my->z+10.0), goblin_hat);
	}
	wait(1);
	ptr_remove(me);
}

void goblin_event()
{

	if (event_type == EVENT_IMPACT)
	{
		if (you != NULL)
		{
			if (your->ENTITY_TYPE == SHOT)
			{	
				set (my, is_dead);
				//shot by snowball
				//wait(1);
				//ent_remove(you);
			}
		}
	}
}

void goblin_hat()
{
	set(my, PASSABLE);
	my->pan = random(360);
	if (c_trace(&my->x, vector(my->x, my->y, my->z - 1000), IGNORE_ME | IGNORE_PASSABLE | IGNORE_PASSENTS) > 0)
	{
		my->z = hit->z - my->min_z;
	}
}

void goblin_stand() {
	while(me) {
		my.ANIMATION_PERCENTAGE += 0.8;
		ent_animate(me, "talk ", my.ANIMATION_PERCENTAGE, ANM_CYCLE);
		wait(1);
	}
}

void goblin_stand2() {
	while(me) {
		my.ANIMATION_PERCENTAGE += 0.8;
		ent_animate(me, "victory ", my.ANIMATION_PERCENTAGE, ANM_CYCLE);
		wait(1);
	}
}
#endif