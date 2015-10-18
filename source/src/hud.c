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
	
	panHutBg.pos_x = screen_size.x / 2 - panHutBg.size_x / 2;
	panHutBg.pos_y = screen_size.y / 2 - panHutBg.size_y / 2;
	panHut.pos_x = screen_size.x / 2 - bmap_width(bmapHut) / 2;
	panHut.pos_y = screen_size.y / 2 - bmap_height(bmapHut) / 2;
	txtHutWoodCount = txt_create(1, 15);
	txtHutWoodCount.font = fontBoogalooSmall;
	txtHutWoodCount.pos_x = panHut.pos_x - 5;
	txtHutWoodCount.pos_y = panHut.pos_y + bmap_height(bmapHut) - 10;
	vec_set(txtHutWoodCount.blue, vector(43,221,255));
	set(txtHutWoodCount,OUTLINE | TRANSLUCENT);
	txtHutSnowballCount = txt_create(1, 15);
	txtHutSnowballCount.font = fontBoogalooSmall;
	txtHutSnowballCount.pos_x = panHut.pos_x + 60;
	txtHutSnowballCount.pos_y = panHut.pos_y + bmap_height(bmapHut) - 10;
	vec_set(txtHutSnowballCount.blue, vector(43,221,255));
	set(txtHutSnowballCount,OUTLINE | TRANSLUCENT);
	panSmallSnowballCount.pos_x = txtHutSnowballCount.pos_x + 25;
	panSmallSnowballCount.pos_y = txtHutSnowballCount.pos_y;
	panSmallWoodCount.pos_x = txtHutWoodCount.pos_x + 20;
	panSmallWoodCount.pos_y = txtHutWoodCount.pos_y;
	
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
	reset(panHut, SHOW);
	reset(txtSnowballCount, SHOW);
	reset(txtWoodCount, SHOW);
}

void updateGui() {
	str_for_num((txtWoodCount.pstring)[0], woodCount);
	str_cat((txtWoodCount.pstring)[0], "/");
	str_cat((txtWoodCount.pstring)[0], str_for_num(NULL, maxWoodCount));
	
	str_for_num((txtSnowballCount.pstring)[0], snowballCount);
	str_cat((txtSnowballCount.pstring)[0], "/");
	str_cat((txtSnowballCount.pstring)[0], str_for_num(NULL, maxSnowballCount));
	
	str_for_num((txtHutSnowballCount.pstring)[0], hutSnowballCount);
	str_for_num((txtHutWoodCount.pstring)[0], hutWoodCount);
	
	if (key_l) {
		while(key_l) wait(1);
		showHutItems();
	}
	
	if (key_k) {
		while(key_k) wait(1);
		hideHutItems();
	}
}

void showHutItems() {
	
	txtHutSnowballCount.alpha = 0;
	txtHutWoodCount.alpha = 0;
	panHut.alpha = 0;
	panSmallWoodCount.alpha = 0;
	panSmallSnowballCount.alpha = 0;
	panHutBg.alpha = 0;
	
	set(txtHutSnowballCount, SHOW);
	set(txtHutWoodCount, SHOW);
	set(panHut, SHOW);
	set(panSmallWoodCount, SHOW);
	set(panSmallSnowballCount, SHOW);
	set(panHutBg, SHOW);
	
	while(panHut.alpha < 100) {
		txtHutSnowballCount.alpha += 4 * time_step;
		txtHutWoodCount.alpha += 4 * time_step;
		panHut.alpha += 4 * time_step;
		panSmallWoodCount.alpha += 4 * time_step;
		panSmallSnowballCount.alpha += 4 * time_step;
		if (panHutBg.alpha <= 60) {
			panHutBg.alpha +=4 * time_step;
		}
		wait(1);
	}
}

void hideHutItems() {
	
	while(panHut.alpha > 0) {
		txtHutSnowballCount.alpha -= 4 * time_step;
		txtHutWoodCount.alpha -= 4 * time_step;
		panHut.alpha -= 4 * time_step;
		panSmallWoodCount.alpha -= 4 * time_step;
		panSmallSnowballCount.alpha -= 4 * time_step;
		if (panHutBg.alpha > 0)	panHutBg.alpha -=4 * time_step;
		wait(1);
	}
	
	reset(panHutBg,SHOW);
	reset(txtHutSnowballCount, SHOW);
	reset(txtHutWoodCount, SHOW);
	reset(panHut, SHOW);
	reset(panSmallWoodCount, SHOW);
	reset(panSmallSnowballCount, SHOW);	
}

var isHutItemsVisible() {
	return is(panHut, SHOW);
}

#endif