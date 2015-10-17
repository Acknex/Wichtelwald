#ifndef HUD_C_
#define HUD_C_

void startIngameGUI() {
	panWoodCount.pos_x = screen_size.x - bmap_width(bmapWoodCount) - 20;
	panWoodCount.pos_y = screen_size.y - bmap_height(bmapWoodCount) - 20;
	txtWoodCount = txt_create(1, 13);
	txtWoodCount.font = fontBoogaloo;
	txtWoodCount.pos_x = panWoodCount.pos_x - 40;
	txtWoodCount.pos_y = screen_size.y - bmap_height(bmapWoodCount) - 20;
	vec_set(txtWoodCount.blue, vector(43,221,255));
	
	panSnowballCount.pos_x = screen_size.x - bmap_width(bmapSnowballCount) - 180;
	panSnowballCount.pos_y = screen_size.y - bmap_height(bmapWoodCount) - 20;
	txtSnowballCount = txt_create(1, 13);
	txtSnowballCount.font = fontBoogaloo;
	txtSnowballCount.pos_x = panSnowballCount.pos_x - 40;
	txtSnowballCount.pos_y = screen_size.y - bmap_height(bmapWoodCount) - 20;
	vec_set(txtSnowballCount.blue, vector(43,221,255));
	
	panClock.pos_x = screen_size.x - bmap_width(bmapClock) - 20;
	panClock.pos_y = 10;
	
	set(txtWoodCount, SHOW | OUTLINE);
	set(panWoodCount, SHOW);
	
	set(txtSnowballCount, SHOW | OUTLINE);
	set(panSnowballCount, SHOW);
	
	set(panClock, SHOW);
	
	pan_setneedle(panClock,0, bmap_width(bmapClock) / 2, bmap_height(bmapClock) / 2,
		bmap_fill(bmap_createblack(30,4,32),vector(0,0,0),100),
		4,2,90,12,0, hours);
	
	pan_setneedle(panClock,0, bmap_width(bmapClock) / 2, bmap_height(bmapClock) / 2,
		bmap_fill(bmap_createblack(40,2,32),vector(0,0,0),100),
		4,1,90,60,0, minutes);
}

void endIngameGUI() {
	reset(panWoodCount, SHOW);
	reset(panSnowballCount, SHOW);
	reset(panClock, SHOW);
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