#ifndef ITEMS_C_
#define ITEMS_C_

void actWoodpile() {
	my.ENTITY_TYPE = LOGS;
	while(1) {
		my.pan +=1 * time_step;
		wait(1);
	}
}

#endif