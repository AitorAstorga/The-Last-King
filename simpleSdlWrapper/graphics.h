#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "SDL.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480
#define MAX_SG 15//AITOR_EDIT

SDL_Renderer* gRenderer[MAX_SG];//AITOR_EDIT
int fullscreen;

int sgHasieratu(int sg, int width, int height, Uint32 flags);//AITOR_EDIT
void sgItxi(int sg);//AITOR_EDIT
void arkatzKoloreaEzarri(int red, int green, int blue);//AITOR_EDIT
void puntuaMarraztu(int x, int y, int sg);//AITOR_EDIT
void zuzenaMarraztu(int x1, int y1, int x2, int y2, int sg);//AITOR_EDIT
void pantailaGarbitu(int sg);//AITOR_EDIT
void pantailaBerriztu(int sg);//AITOR_EDIT
void fullscreenGaitu(int sg, int x, int y);

int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest, int sg);//AITOR_EDIT

SDL_Renderer* getRenderer(int sg);//AITOR_EDIT

#endif