#ifndef LENSFLARE_H
#define LENSFLARE_H

#define LENS_DISTANCE skill1

void initLensFlarePosition();
void initFlare(ENTITY* _entFlare);
void placeFlare(ENTITY* _entFlare);
void createLensFlare();
void startLensFlare();
void stopLensFlare();
void lensFlareToggle();

var vLensFlareState = -1;
var vLensFlareAlpha = 70;
var vLensFlareFadeSpeed = 25;
var vLensFlareVisibility = 0;
var vCameraPan = 0;

VECTOR vecTemp1;
VECTOR vecTemp2;

ENTITY* entFlare1 =  { type = "graphics//lens01.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; alpha = 40;  }
ENTITY* entFlare2 =  { type = "graphics//lens02.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare4 =  { type = "graphics//lens04.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare5 =  { type = "graphics//lens05.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare6 =  { type = "graphics//lens06.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare7 =  { type = "graphics//lens07.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare8 =  { type = "graphics//lens08.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare9 =  { type = "graphics//lens09.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare10 = { type = "graphics//lens10.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare11 = { type = "graphics//lens11.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare12 = { type = "graphics//lens12.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare13 = { type = "graphics//lens13.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare14 = { type = "graphics//lens14.tga"; layer = 8; view = camera; scale_x = 2.5; scale_y = 2.5; 				}
ENTITY* entFlare15 = { type = "graphics//lens15.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare16 = { type = "graphics//lens16.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare17 = { type = "graphics//lens17.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare18 = { type = "graphics//lens18.tga"; layer = 8; view = camera; scale_x = 2;   scale_y = 2; 					}
ENTITY* entFlare19 = { type = "graphics//lens19.tga"; layer = 8; view = camera; scale_x = 2; 	 scale_y = 2; 					}
ENTITY* entFlare20 = { type = "graphics//lens20.tga"; layer = 8; view = camera; scale_x = 2.8; scale_y = 2.8; 				}

#endif
