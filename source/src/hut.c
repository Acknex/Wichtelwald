#ifndef HUT_C
#define HUT_C


void fade_p(PARTICLE* p);
void smoke_p(PARTICLE* p);

void fade_p(PARTICLE* p)
{
	p.alpha -= p.skill_a*time_step;
	if (p.alpha <= 0) p.lifespan = 0;
	
	p.size = minv(p.skill_b, p.size+time_step*5);
}

BMAP* bmp_smoke = "rauch2.tga";

void smoke_p(PARTICLE* p)
{
	p.skill_a = 3;
	p.bmap = bmp_smoke;
	p.lifespan = 1200+random(600);
	p.skill_b = 20 + random(15);
	p.size = 0;
	p.alpha = 40;
	vec_scale(p.vel_x, 0.4);
	set(p, TRANSLUCENT | MOVE/* | BRIGHT*/);
	p.event = fade_p;
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
}

#endif