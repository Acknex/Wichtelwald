#ifndef MOUSE_C_
#define MOUSE_C_

void initMouseMenu() {
	mouse_map = bmapSnowflake;
	mouse_spot.x = bmap_width(bmapSnowflake) / 2;
	mouse_spot.y = bmap_height(bmapSnowflake) / 2;
	mouse_mode = 4;
}

#endif