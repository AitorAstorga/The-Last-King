#include "graphics.h"
#include "imagen.h"
#include "ebentoak.h"
#include <stdio.h>
#include "ourTypes.h"
#include "jokoa.h"
#include "menu.h"
#include "SDL.h"
#include "irudiakEtaSoinuak.h"
#include "soinua.h"

/*
MENU -> (BERRIA / KARGATU / ERREPIKAPENAK) [MUSIKA / SOINUA]
	BERRIA -> (1 VS 1 / PVE)
		PVE -> (SIMETRIKO / INTERCAMBIO / IA / LUCKY_BLOCK)
	KARGATU -> (PARTIDA 1 / PARTIDA 2 / PARTIDA 3) {Rename option for slots xD}
	ERREPIKAPENAK -> (PARTIDA 1 / PARTIDA 2 / PARTIDA 3)

*/

int main(int argc, char* argv[]) {
  EGOERA mainEgoera = MENU;

  musikaEgoera = 1;
  soinuEgoera = 1;
  fullscreen = 0;

  audioInit();
  loadTheMusic(MUSIKA_O_FORTUNA);
  //playMusic();

  do {
	  if (mainEgoera == MENU) {
		  mainEgoera = menu();
	  }

	  /*if (mainEgoera == JOKOA) {
		  jokoa(mainEgoera);
		  mainEgoera = MENU;
	  }
	  */
	  if (mainEgoera == KARGATU || mainEgoera == JOKOA || mainEgoera == SIMETRIKO || mainEgoera == INTERCAMBIO || mainEgoera == IA || mainEgoera == LUCKY_BLOCK) {
		 jokoa(mainEgoera);
		 mainEgoera = MENU;
	  }
  } while (mainEgoera != ITXI);
  toggleMusic();
  audioTerminate();
  SDL_Quit();
  
  return 0;
}