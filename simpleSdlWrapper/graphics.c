#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRAPHICS

#include "SDL_ttf.h"

#include "imagen.h"
#include "graphics.h"
#include "irudiakEtaSoinuak.h"

SDL_Window* window[MAX_SG] = { NULL };//AITOR_EDIT

int colorR, colorG, colorB;

SDL_Renderer* getRenderer(int sg) { return gRenderer[sg]; }//AITOR_EDIT

int sgHasieratu(int sg, int width, int height, Uint32 flags)//AITOR_EDIT
{
  SDL_Surface* iconoa = SDL_LoadBMP(APLIKAZIO_IKONOA);//AITOR_EDIT
  int ret = 0;

 // if (SDL_WasInit(SDL_INIT_EVERYTHING) == 0) {
	  if (SDL_Init(SDL_INIT_VIDEO) < 0)
	  {
		  fprintf(stderr, "ezin SDL hasieratu: %s\n", SDL_GetError());
		  return -1;
	  }

	  atexit(SDL_Quit);
  //}
  window[sg] = SDL_CreateWindow("Xake Jokoa", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);//AITOR_EDIT
  SDL_SetWindowIcon(window[sg], iconoa);//AITOR_EDIT
  if (window[sg] == NULL)//AITOR_EDIT
  {
    fprintf(stderr, "Ezin lehioa sortu: %s\n", SDL_GetError());
    return -1;
  }
  gRenderer[sg] = SDL_CreateRenderer(window[sg], -1, SDL_RENDERER_ACCELERATED);//AITOR_EDIT
  TTF_Init();
  atexit(TTF_Quit);
  return ret;
}

void sgItxi(int sg)
{
  SDL_DestroyWindow(window[sg]);//AITOR_EDIT
  //SDL_Quit();//AITOR_EDIT
}

void arkatzKoloreaEzarri(int red, int green, int blue)
{
  colorR = red;
  colorG = green;
  colorB = blue;
}

void zuzenaMarraztu(int x1, int y1, int x2, int y2, int sg)
{
  SDL_SetRenderDrawColor(gRenderer[sg], colorR, colorG, colorB, SDL_ALPHA_OPAQUE);//AITOR_EDIT
  SDL_RenderDrawLine(gRenderer[sg], x1, y1, x2, y2);//AITOR_EDIT
}

void puntuaMarraztu(int x, int y, int sg)
{
  SDL_SetRenderDrawColor(gRenderer[sg], colorR, colorG, colorB, SDL_ALPHA_OPAQUE);//AITOR_EDIT
  SDL_RenderDrawPoint(gRenderer[sg], x, y);//AITOR_EDIT
}

int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest, int sg)
{
  SDL_Rect src;

  src.x = 0;
  src.y = 0;
  src.w = pDest->w;
  src.h = pDest->h;
  SDL_RenderCopy(gRenderer[sg], texture, &src, pDest);//AITOR_EDIT
  return 0;
}

void pantailaGarbitu(int sg)
{
  SDL_SetRenderDrawColor(gRenderer[sg], 0, 0, 0, SDL_ALPHA_OPAQUE);//AITOR_EDIT
  SDL_RenderClear(gRenderer[sg]);//AITOR_EDIT
}

void pantailaBerriztu(int sg)
{
  SDL_RenderPresent(gRenderer[sg]);//AITOR_EDIT
}

void fullscreenGaitu(int sg, int x, int y) {
	if (fullscreen == 0) {
		fullscreen = 1;
			
		SDL_SetWindowFullscreen(window[sg], SDL_WINDOW_FULLSCREEN);
		/*int screenSizeX, screenSizeY;
		SDL_DisplayMode DM;
		SDL_GetDesktopDisplayMode(0, &DM);
		screenSizeX = DM.w;
		screenSizeY = DM.h;
		printf("SIZE: %i %i\n", screenSizeX, screenSizeY);
		SDL_SetWindowPosition(window[sg], 0, 0);
		SDL_SetWindowSize(window[sg], screenSizeX, screenSizeY);*/
	}
	else {
		fullscreen = 0;
		//SDL_SetWindowBordered(window[sg], 0);
		//sgItxi(sg);
		SDL_QuitSubSystem(sg); 
		//SDL_Quit();
		if (sgHasieratu(sg, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS) == -1)
		{
			fprintf(stderr, "Ezin da %ix%i bideoa gaitu: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
			return ERROREA;
		}
		SDL_SetWindowPosition(window[sg], SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		
	/*	SDL_SetWindowFullscreen(window[sg], 0);
		SDL_SetWindowSize(window[sg], x, y);
		SDL_SetWindowPosition(window[sg], SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		int test1, test2;
		SDL_GetWindowPosition(window[sg], &test1, &test2);
		printf("POSITION0: %i %i\n", test1, test2);*/
	}
}