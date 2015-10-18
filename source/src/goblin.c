#ifndef GOBLIN_C
#define GOBLIN_C

var goblinSpawnDelay = 16;
var goblinSpeed = 10;

var goblinSpawnDist = 1000;
var goblinSpawnTimer = 0;
var goblinLastSpawnAngle = 0;

SOUND* sndGobboRun = "Fussstapfen1.OGG";

void goblin_spawn();
void goblin_event();
void goblin();
void goblin_hat();

void goblin_loop()
{

	//if (dayOrNight == NIGHT)
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
	my->emask |= ENABLE_TRIGGER | ENABLE_IMPACT;
	my->event = goblin_event;
	my->ENTITY_TYPE = GOBLIN;
	my->ATTACK_POWER = 1;
	ent_playloop(me, sndGobboRun, soundVolume * 10);
	while (dayOrNight == NIGHT && (!is(my, is_dead)))
	{
		wait (1);
		if (c_trace(&my->x, vector(my->x, my->y, my->z - 1000), IGNORE_ME | IGNORE_PASSABLE | IGNORE_PASSENTS) > 0)
		{
			my->z = hit->z - my->min_z + 2;
		}
		c_move(me,vector(goblinSpeed * time_step,0,0),nullvector, IGNORE_PASSABLE | IGNORE_PASSENTS | GLIDE | ACTIVATE_TRIGGER);
		my->gobboDist += goblinSpeed * time_step;
		ent_animate(me, "walk", (my->gobboDist % 100) * 1, ANM_CYCLE);
	}
	my->alpha = 100;
	set(my, TRANSLUCENT);
	my->gobboDist = 0;
	while (my->alpha > 0)
	{
		wait (1);
		my->alpha -= 5* time_step;
		my->gobboDist += 2 * time_step;
		ent_animate(me, "victory", (my->gobboDist % 20) * 5, 0);
	}

	if (!is(my, is_collided))
	{
		ent_create("hat.mdl", my->x, goblin_hat);
	}

	ptr_remove(me);
}

void goblin_event()
{

	if (event_type == EVENT_IMPACT)
	{
		if (you != NULL)
		{
			if (your->ENTITY_TYPE == SNOWBALL)
			{	
				set (my, is_dead);
				//shot by snowball
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
#endif