#ifndef ITEMS_C_
#define ITEMS_C_

#include <particles.c>

SOUND* sndLogCollect = "holzscheit1.ogg";
SOUND* sndSnowballCollect = "schneeball1.ogg";

int woodCount = 0;
int maxWoodCount = 3;

int snowballCount = 0;
int maxSnowballCount = 20;

void item_loop();
void item_fade();
void item_wood_evt();
void item_snowball_evt();
void item_particleFader(PARTICLE *p);
void item_particle (PARTICLE *p);

action item_wood()
{
	vec_set(my->scale_x, vector(10, 10, 10));
	my->ENTITY_TYPE = LOGS;
	my->event = item_wood_evt;
	item_loop();	
}

action item_snowball()
{
	my->ENTITY_TYPE = SNOWBALL;
	my->event = item_snowball_evt;
	item_loop();
}

void item_loop()
{
	my->emask |= ENABLE_TRIGGER; 
	my->trigger_range = 30;
	set (me, PASSABLE);
	my->pan = random(360);
	var vZ = my->z;
	var vOffset = random(500);
	var vParticles = 0;
	if (c_trace(&my->x, vector(my->x, my->y, my->z - 1000), IGNORE_ME | IGNORE_PASSABLE) > 0)
	{
		my->z = hit->z + ITEM_HEIGHT;
	}
	
	while(!is(me, is_collected))
	{
		vParticles += time_step;
		while (vParticles > 1)
		{
			effect(item_particle, 1, &my->x, nullvector);
			vParticles -= 1;
		}
		my->z = vZ + 10 * sinv(total_ticks * 20 + vOffset);
		my->pan -= 5 * time_step;
		if (dayOrNight == DAY)
		{
			reset(my, INVISIBLE);
			my->emask |= ENABLE_TRIGGER; 
		}
		else
		{
			set(my, INVISIBLE);
			my->emask &= ~ENABLE_TRIGGER; 
		}
		wait(1);
	}
	item_fade();
}

void item_fade()
{
	var vTicks = total_ticks;
	VECTOR vecDist;
	
	var fadeScale = my->scale_x;
	vec_set(&vecDist, &my->x);
	vec_sub(&vecDist, &player->x);
	while (my->scale_x > 0)
	{
		//scale down item
		my->scale_x = maxv(my->scale_x - 0.1 * time_step * fadeScale, 0);
		my->scale_y = my->scale_x;
		my->scale_z = my->scale_x;
		my->pan += (total_ticks - vTicks) * 10 * time_step;

		//move item towards player
		vec_set(&my->x, &vecDist);
		vec_scale(&my->x, my->scale_x / fadeScale);
		vec_add(&my->x, &player->x);
		wait(1);
	}
	ptr_remove(me);
}

void item_wood_evt()
{
	if (event_type == EVENT_TRIGGER)
	{
		if (player != NULL && woodCount < maxWoodCount) 
		{
			woodCount++;	
			my->event = NULL;
			set (me, is_collected);
			ent_playsound(me, sndLogCollect, 1000);
		}
	}
}

void item_snowball_evt()
{
	if (event_type == EVENT_TRIGGER)
	{
		if (player != NULL && snowballCount < maxSnowballCount) 
		{
			snowballCount++;
			my->event = NULL;
			set (me, is_collected);
			ent_playsound(me, sndSnowballCollect, 1000);
		}
	}
}



void item_particleFader(PARTICLE *p) 
{
	p->alpha -= 5 * time_step;
	p->size += time_step;
	if (p->alpha <= 0) 
	{
		p->lifespan = 0;
	}
}

void item_particle (PARTICLE *p) 
{
	VECTOR vecTemp;
	vec_randomize(&vecTemp, 10);
	vec_normalize(&vecTemp, 1);
	vec_add (&p->vel_x, &vecTemp);
	vec_set(&p->blue, vector(0, 150, 150));
	set(p, MOVE | TRANSLUCENT /*| BRIGHT*/);
	p->lifespan = 80;
	p->size  = 15 + random(5);
	p->event = item_particleFader;
}



#endif