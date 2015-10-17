#ifndef CAMERA_C_
#define CAMERA_C_
    
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

#endif