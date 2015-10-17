#ifndef HUD_C_
#define HUD_C_

void startIngameGUI() {
	panWoodCount.pos_x = screen_size.x - bmap_width(bmapWoodCount) - 20;
	panWoodCount.pos_y = 10;
	txtWoodCount = txt_create(1, 13);
	txtWoodCount.font = fontBoogaloo;
	txtWoodCount.pos_x = panWoodCount.pos_x - 40;
	txtWoodCount.pos_y = 10;
	vec_set(txtWoodCount.blue, vector(43,221,255));
	
	panSnowballCount.pos_x = screen_size.x - bmap_width(bmapSnowballCount) - 20;
	panSnowballCount.pos_y = 80;
	txtSnowballCount = txt_create(1, 13);
	txtSnowballCount.font = fontBoogaloo;
	txtSnowballCount.pos_x = panSnowballCount.pos_x - 40;
	txtSnowballCount.pos_y = 90;
	vec_set(txtSnowballCount.blue, vector(43,221,255));
	
	
	set(txtWoodCount, SHOW | OUTLINE);
	set(panWoodCount, SHOW);
	
	set(txtSnowballCount, SHOW | OUTLINE);
	set(panSnowballCount, SHOW);
}

void endIngameGUI() {
	reset(panWoodCount, SHOW);
}

void updateGui() {
	str_for_num((txtWoodCount.pstring)[0], woodCount);
	str_cat((txtWoodCount.pstring)[0], "/");
	str_cat((txtWoodCount.pstring)[0], str_for_num(NULL, maxWoodCount));
	
	str_for_num((txtSnowballCount.pstring)[0], snowballCount);
	str_cat((txtSnowballCount.pstring)[0], "/");
	str_cat((txtSnowballCount.pstring)[0], str_for_num(NULL, maxSnowballCount));
}

#endif