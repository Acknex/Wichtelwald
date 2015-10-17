#ifndef MUSIC_C_
#define MUSIC_C_

void playMusicMenu() {
	if (gameMusicHandle != 0) {
		stopMusicGame();
	}
	menuMusicHandle = snd_loop(sndMusicMenu, 100, 0);
}

void playMusicGameDay() {
	snd_stop(gameMusicHandle);
	snd_stop(menuMusicHandle);
	
	gameMusicHandle = snd_loop(sndMusicGameDay, 100, 0);	
}

void playMusicGameNight() {
	snd_stop(gameMusicHandle);
	snd_stop(menuMusicHandle);
	
	gameMusicHandle = snd_loop(sndMusicGameNight, 100, 0);	
}

void stopMusicMenu() {
	snd_stop(menuMusicHandle);
}

void stopMusicGame() {
	snd_stop(gameMusicHandle);
}

#endif