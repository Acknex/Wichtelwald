#ifndef GOBLIN_C
#define GOBLIN_C

var goblinSpawnDelay = 80;
var goblinSpawnTimer = 0;

void goblin_spawn();

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
}
#endif