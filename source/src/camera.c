#ifndef CAMERA_C_
#define CAMERA_C_
    
// Rotates the camera around the "me" target
void actCameraRotateMenu() {
	vec_set(vecCamTmp, my.x);
	while(1) {
		cam_angle +=0.05 * time_step;
		camera.x = cos(cam_angle) * 768;
		camera.y = sin(cam_angle) * 768;
		vec_diff(vecCamTmp.x, nullvector, camera.x);
		vec_to_angle(camera.pan, vecCamTmp);
		wait(1);
	}
}

void gameCameraInit() {
	//set(camera, ISOMETRIC);
	camera.tilt = 310;
}

// Follows the player (top)
void cameraTopPlayer() {
	
	//set(camera, ISOMETRIC);
	if (player == NULL) return;
	camera.x = player.x - 400;
	camera.y = player.y - 20;
	camera.z = player.z + 500;
}

#endif