#ifndef HUT_C
#define HUT_C

var hutSnowballTodo = 0;
var hutWoodTodo = 0;
var hutShake = 0;

BMAP* bmpSmoke = "rauch2.tga";
SOUND* sndTransferHut = "present_counter.OGG";
SOUND* sndLoseHut = "present_counter.OGG";
SOUND* sndHitHut = "present_counter.OGG";

void fade_p(PARTICLE* p);
void smoke_p(PARTICLE* p);
void hut_event();
void hut_count();
void hut_hit();


void fade_p(PARTICLE* p)
{
	p.alpha -= p.skill_a*time_step;
	if (p.alpha <= 0) p.lifespan = 0;
	
	p.size = minv(p.skill_b, p.size+time_step*5);
}

void smoke_p(PARTICLE* p)
{
	p.skill_a = 3;
	p.bmap = bmpSmoke;
	p.lifespan = 1200+random(600);
	p.skill_b = 20 + random(15);
	p.size = 0;
	p.alpha = 40;
	vec_scale(p.vel_x, 0.4);
	set(p, TRANSLUCENT | MOVE/* | BRIGHT*/);
	p.event = fade_p;
}

void hut_event()
{
	if (event_type == EVENT_IMPACT && you != NULL)
	{
		if (your->ENTITY_TYPE == GOBLIN)
		{
			hut_hit();
			if (hutWoodCount <= 0)
			{
				set(my, is_empty);
			}	
		}
		
	}
	
	if (event_type == EVENT_TRIGGER && you != NULL)
	{
		if (you == player)
		{
			hutWoodTodo += woodCount;
			woodCount = 0;

			hutSnowballTodo += snowballCount;
			snowballCount = 0;
		}
	}
}

void hut_count()
{
	var added = 0;
		
	while (!is(my, is_empty))
	{
		added = 0;
		if (hutWoodTodo > 0)
		{
			hutWoodCount++;
			hutWoodTodo--;	
			added = 1;		
		}
	
		if (hutWoodTodo < 0)
		{
			hutWoodCount--;
			hutWoodTodo++;	
			added = -1;		
		}
	
		if (hutSnowballTodo > 0)
		{
			hutSnowballCount++;
			hutSnowballTodo--;	
			added = 1;		
		}	
		
		if (hutSnowballTodo < 0)
		{
			hutSnowballCount--;
			hutSnowballTodo++;	
			added = -11;		
		}	
		
		if (added > 0)
		{
			snd_play(sndTransferHut, soundVolume, 0);
			//show panel	
		}
		
		if (added < 0)
		{
			snd_play(sndLoseHut, soundVolume, 0);
			//show panel	
		}
		
		wait (-0.2);
		//hide panel
	}
}

void hut_hit()
{
	VECTOR vecPos;
	VECTOR vecTemp;
	
	snd_play(sndHitHut, soundVolume, 0);

	if (hutShake > 0)
	{
		hutShake = 0;
		return;
	}	

	vec_set(&vecPos, &my->x);
	while(hutShake < HIT_TIME)
	{
		vec_randomize(&vecTemp, 100);
		vec_normalize(&vecTemp, 20);
		vec_add(&my->x, &vecTemp);
		my->z = vecPos.z;
		wait(-0.15);
		vec_set(&my->x, &vecPos);
		wait(-0.05);
		hutShake += 0.2;
	}
	hutShake = 0;
	hutWoodCount = maxv(hutWoodCount - your->ATTACK_POWER, 0);
}

action smoke()
{
	set(me, PASSABLE | INVISIBLE);
	var partout = 0;
	while (1)
	{
		partout += time_step;
		while(partout > 1)
		{
			effect(smoke_p, 2,
			_vec(me.x+random(10)-5, me.y+random(10)-5, me.z+random(10)-5),
			_vec(-5-random(10), -2-random(4), 2+random(4)));
			partout -= 1;
		}
		wait(1);
	}
}

action woodlog()
{
}

action hut()
{
	my->trigger_range = 200;
	my->emask |= ENABLE_TRIGGER | ENABLE_IMPACT;
	my->event = hut_event;	
	hut_count();
	while(!is(my, is_empty))
	{
		wait (1);
	}
	
	//game over
	error("Nun.. jetzt hab ich wohl verkackt");
}


#endif