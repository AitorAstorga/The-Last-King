#include <stdio.h>
#include "SDL_video.h"
#include "irudiakEtaSoinuak.h"
#include "graphics.h"
#include "imagen.h"
#include "ebentoak.h"
#include "OurTypes.h"

#include "text.h"
#include <Windows.h>

#include "partidak.h"
#include "menu.h"
#include "soinua.h"
#include "jokoa.h"

EGOERA menu() {
	EGOERA aukera = MENU;
	POSIZIOA pos;
	int imageIdMenu = 0;
	int imageIdSoinua;
	int imageIdMusika;
	int ebentuMenu = 0;
	int kurtsoreaBotoietan = 0;

	int soinuaClick = loadSound(SOINUA_CLICK);
	int soinuaBotoia = loadSound(SOINUA_BOTOIA);

	if (sgHasieratu(MENU, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS) == -1)
	{
		fprintf(stderr, "Ezin da %ix%i bideoa gaitu: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		return ERROREA;
	}

	imageIdMenu = irudiaKargatu(MENU_FONDO, MENU);
	imageIdMusika = irudiaKargatu(MUSIKA_ON, MENU);
	imageIdSoinua = irudiaKargatu(SOINUA_ON, MENU);
	irudiaMugitu(imageIdMusika, 520, 420);
	irudiaMugitu(imageIdSoinua, 580, 420);
	irudiakMarraztu(MENU);
	pantailaBerriztu(MENU);

	do {
		ebentuMenu = ebentuaJasoGertatuBada();
		pos = saguarenPosizioa();
		if (ebentuMenu == SAGU_BOTOIA_EZKERRA) {
			playSound(soinuaClick);
		}
		if (pos.x > 160 && pos.x < 480) {
			if (pos.y > 80 && pos.y < 140) {
				if (kurtsoreaBotoietan == 0) {
					irudiaKendu(imageIdMenu);
					imageIdMenu = irudiaKargatu(MENU_BERRIA, MENU);
					playSound(soinuaBotoia);
				}
				if (ebentuMenu == SAGU_BOTOIA_EZKERRA) aukera = berria();
				kurtsoreaBotoietan++;
			}
			else if (pos.y > 160 && pos.y < 220) {
				if (kurtsoreaBotoietan == 0) {
					irudiaKendu(imageIdMenu);
					imageIdMenu = irudiaKargatu(MENU_KARGATU, MENU);
					playSound(soinuaBotoia);
				}
				if (ebentuMenu == SAGU_BOTOIA_EZKERRA) aukera = kargatu();
				kurtsoreaBotoietan++;
			}
			else if (pos.y > 240 && pos.y < 300) {
				if (kurtsoreaBotoietan == 0) {
					irudiaKendu(imageIdMenu);
					imageIdMenu = irudiaKargatu(MENU_ERREPIKAPENAK, MENU);
					playSound(soinuaBotoia);
				}
				if (ebentuMenu == SAGU_BOTOIA_EZKERRA) aukera = errepikapenak();
				kurtsoreaBotoietan++;
			}
			else if (pos.y > 320 && pos.y < 380) {
				if (kurtsoreaBotoietan == 0) {
					irudiaKendu(imageIdMenu);
					imageIdMenu = irudiaKargatu(MENU_ITXI_tmpIzena, MENU);
					playSound(soinuaBotoia);
				}
				if (ebentuMenu == SAGU_BOTOIA_EZKERRA) aukera = itxi();
				kurtsoreaBotoietan++;
			}
			else {
				irudiaKendu(imageIdMenu);
				imageIdMenu = irudiaKargatu(MENU_FONDO, MENU);
				kurtsoreaBotoietan = 0;
			}
		}
		else {
			irudiaKendu(imageIdMenu);
			imageIdMenu = irudiaKargatu(MENU_FONDO, MENU);
			kurtsoreaBotoietan = 0;
		}
		if (ebentuMenu == SAGU_BOTOIA_EZKERRA) {
			if (pos.x > 520 && pos.x < 560 && pos.y > 420 && pos.y < 453) {
				musikaEgoera *= -1;
				if (musikaEgoera == -1) {
					musicUnload();
				}
				else {
					loadTheMusic(MUSIKA_O_FORTUNA);
					playMusic();
				}
			}
			else if (pos.x > 580 && pos.x < 620 && pos.y > 420 && pos.y < 453) {
				soinuEgoera *= -1;
			}
		}
		/*Work in progress*/
		
		if (ebentuMenu == TECLA_SPACE) {
			printf("TECLA_SPACE\n");
			irudiaKendu(imageIdMenu);
			fullscreenGaitu(MENU, SCREEN_WIDTH, SCREEN_HEIGHT);
			imageIdMenu = irudiaKargatu(MENU_FONDO, MENU);

			irudiakMarraztu(MENU);
			pantailaBerriztu(MENU);
		}
		irudiaKendu(imageIdMusika);
		irudiaKendu(imageIdSoinua);
		if (musikaEgoera == 1) {
			imageIdMusika = irudiaKargatu(MUSIKA_ON, MENU);
		}
		else {
			imageIdMusika = irudiaKargatu(MUSIKA_OFF, MENU);
		}
		if (soinuEgoera == 1) {
			imageIdSoinua = irudiaKargatu(SOINUA_ON, MENU);
		}
		else imageIdSoinua = irudiaKargatu(SOINUA_OFF, MENU);
		irudiaMugitu(imageIdMusika, 520, 420);
		irudiaMugitu(imageIdSoinua, 580, 420);
		irudiakMarraztu(MENU);
		pantailaBerriztu(MENU);
	} while (aukera == MENU);
	soundsUnload();
	irudiaKendu(imageIdMenu);
	irudiaKendu(imageIdMusika);
	irudiaKendu(imageIdSoinua);
	sgItxi(MENU);
	return aukera;
}

EGOERA berria() {
	EGOERA aukera = -1;
	POSIZIOA pos;
	int imageIdBerria;
	int ebentuBerria = 0;

	int soinuaClick = loadSound(SOINUA_CLICK);
	
	imageIdBerria = irudiaKargatu(MENU_JOKATU, MENU);
	irudiaMugitu(imageIdBerria, 170, 140);
	irudiakMarraztu(MENU);
	pantailaBerriztu(MENU);

	do {
		ebentuBerria = ebentuaJasoGertatuBada();
		pos = saguarenPosizioa();
		if (ebentuBerria == SAGU_BOTOIA_EZKERRA) {
			playSound(soinuaClick);
			if (pos.x > 170 && pos.x < 470) {
				if (pos.y > 140 && pos.y < 240) aukera = JOKOA;
				else if (pos.y > 240 && pos.y < 340) aukera = bots();
				else aukera = MENU;
			}
			else aukera = MENU;
		}
	} while (aukera == -1);
	irudiaKendu(imageIdBerria);
	pantailaGarbitu(MENU);
	irudiakMarraztu(MENU);
	pantailaBerriztu(MENU);
	Sleep(500);
	soundsUnload();

	return aukera;
}

EGOERA kargatu() {
	EGOERA aukera;

	if (partidaAukeratu(MENU) != "\0") aukera = KARGATU;
	else aukera = MENU;

	return aukera;
}

EGOERA errepikapenak() {
	errepikapenaPantailaratu();
	return MENU;
}

EGOERA itxi() {
	POSIZIOA pos;
	int imageIdFondoa;
	int ebentuItxi = 0;

	imageIdFondoa = irudiaKargatu(MENU_ITXI, MENU);
	irudiaMugitu(imageIdFondoa, 170, 140);
	irudiakMarraztu(MENU);
	pantailaBerriztu(MENU);

	do {
		ebentuItxi = ebentuaJasoGertatuBada();
		pos = saguarenPosizioa();
		if (ebentuItxi == SAGU_BOTOIA_EZKERRA) {
			if (pos.x < 170 || pos.x > 470 || pos.y < 140 || pos.y > 240) {
				irudiaKendu(imageIdFondoa);
				return MENU;
			}
		}
	} while (ebentuItxi != TECLA_RETURN);
	irudiaKendu(imageIdFondoa);

	return ITXI;
}

EGOERA bots() {
	EGOERA aukera = -1;
	POSIZIOA pos;
	int imageIdBots;
	int ebentuBots = 0;

	imageIdBots = irudiaKargatu(MENU_BOTS, MENU);
	irudiakMarraztu(MENU);
	pantailaBerriztu(MENU);

	do {
		ebentuBots = ebentuaJasoGertatuBada();
		pos = saguarenPosizioa();
		if (ebentuBots == SAGU_BOTOIA_EZKERRA) {
			if (pos.x > 0 && pos.x < 320) {
				if (pos.y > 0 && pos.y < 240) aukera = IA;
				else if (pos.y > 240 && pos.y < 480) aukera = INTERCAMBIO;
			}
			else if (pos.x > 320 && pos.x < 640) {
				if (pos.y > 0 && pos.y < 240) aukera = SIMETRIKO;
				else if (pos.y > 240 && pos.y < 480) aukera = LUCKY_BLOCK;
			}
		}
		else if (ebentuBots == TECLA_ESCAPE) aukera = MENU;
	} while (aukera == -1);
	irudiaKendu(imageIdBots);
	pantailaGarbitu(MENU);
	irudiakMarraztu(MENU);
	pantailaBerriztu(MENU);

	return aukera;
}

EGOERA menuPausa(EGOERA partidaMota) {
	EGOERA aukera = PAUSA;
	POSIZIOA pos;
	int ebentuPausa = 0;
	int imageIdPausa;
	int imageIdMusika;
	int imageIdSoinua;
	int imageIdTaulaBiratu;
	int kurtsoreaBotoietan = 0;

	int soinuaClick = loadSound(SOINUA_CLICK);
	int soinuaBotoia = loadSound(SOINUA_BOTOIA);

	imageIdPausa = irudiaKargatu(MENU_PAUSA, JOKOA);
	imageIdTaulaBiratu = irudiaKargatu(TAULA_BIRATU, JOKOA);
	if (musikaEgoera == 1) {
		imageIdMusika = irudiaKargatu(MUSIKA_ON, JOKOA);
	}
	else {
		imageIdMusika = irudiaKargatu(MUSIKA_OFF, JOKOA);
	}
	if (soinuEgoera == 1) {
		imageIdSoinua = irudiaKargatu(SOINUA_ON, JOKOA);
	}
	else {
		imageIdSoinua = irudiaKargatu(SOINUA_OFF, JOKOA);
	}
	irudiaMugitu(imageIdPausa, 170, 140);
	irudiaMugitu(imageIdTaulaBiratu, 297, 148);
	irudiaMugitu(imageIdMusika, 357, 148);
	irudiaMugitu(imageIdSoinua, 417, 148);
	irudiakMarraztu(JOKOA);
	pantailaBerriztu(JOKOA);

	do {
		ebentuPausa = ebentuaJasoGertatuBada();
		pos = saguarenPosizioa();
		if (pos.y > 224 && pos.y < 251 && pos.x > 195 && pos.x < 446) {
			if (kurtsoreaBotoietan == 0) {
				irudiaKendu(imageIdPausa);
				imageIdPausa = irudiaKargatu(MENU_PAUSA_GORDE, JOKOA);
				irudiaMugitu(imageIdPausa, 170, 140);
				playSound(soinuaBotoia);
			}
			kurtsoreaBotoietan++;
		}
		else if (pos.y > 274 && pos.y < 301 && pos.x > 275 && pos.x < 362) {
			if (kurtsoreaBotoietan == 0) {
				irudiaKendu(imageIdPausa);
				imageIdPausa = irudiaKargatu(MENU_PAUSA_MENU, JOKOA);
				irudiaMugitu(imageIdPausa, 170, 140);
				playSound(soinuaBotoia);
			}
			kurtsoreaBotoietan++;
		}
		else {
			irudiaKendu(imageIdPausa);
			imageIdPausa = irudiaKargatu(MENU_PAUSA, JOKOA);
			irudiaMugitu(imageIdPausa, 170, 140);
			kurtsoreaBotoietan = 0;
		}
		if (ebentuPausa == SAGU_BOTOIA_EZKERRA) {
			playSound(soinuaClick);
			if (pos.y > 140 && pos.y < 340 && pos.x > 170 && pos.x < 470) {
				if (pos.y > 148 && pos.y < 181) {
					if ((pos.x >= 298 && pos.x < 331)) {
						aukera = GIRATU;
					}
					if (pos.x > 357 && pos.x < 390) {
						aukera = MUSIKA;
						musikaEgoera *= -1;
					}
					else if (pos.x > 417 && pos.x < 450) {
						aukera = SOINUA;
						soinuEgoera *= -1;
					}
				}
				else if (pos.y > 224 && pos.y < 251 && pos.x > 195 && pos.x < 446) {
					aukera = GORDE;
				}
				else if (pos.y > 274 && pos.y < 301 && pos.x > 275 && pos.x < 362) {
					aukera = MENU;
				}
			}
			else aukera = partidaMota;
		}
		else if (ebentuPausa == TECLA_p) aukera = partidaMota;
		irudiaKendu(imageIdTaulaBiratu);
		irudiaKendu(imageIdMusika);
		irudiaKendu(imageIdSoinua);
		imageIdTaulaBiratu = irudiaKargatu(TAULA_BIRATU, JOKOA);
		if (musikaEgoera == 1) {
			imageIdMusika = irudiaKargatu(MUSIKA_ON, JOKOA);
		}
		else {
			imageIdMusika = irudiaKargatu(MUSIKA_OFF, JOKOA);
		}
		if (soinuEgoera == 1) {
			imageIdSoinua = irudiaKargatu(SOINUA_ON, JOKOA);
		}
		else {
			imageIdSoinua = irudiaKargatu(SOINUA_OFF, JOKOA);
		}
		irudiaMugitu(imageIdTaulaBiratu, 297, 148);
		irudiaMugitu(imageIdMusika, 357, 148);
		irudiaMugitu(imageIdSoinua, 417, 148);
		irudiakMarraztu(JOKOA);
		pantailaBerriztu(JOKOA);
	} while (aukera == PAUSA && ebentuPausa != TECLA_p);

	soundsUnload();
	irudiaKendu(imageIdPausa);
	irudiaKendu(imageIdMusika);
	irudiaKendu(imageIdSoinua);
	irudiaKendu(imageIdTaulaBiratu);
	pantailaGarbitu(JOKOA);
	irudiakMarraztu(JOKOA);
	pantailaBerriztu(JOKOA);

	return aukera;
}

void popUpEzinezkoa() {
	int imageIdEzinezkoa = irudiaKargatu(IRUDI_MUGIMENDU_EZINEZKOA, JOKOA);
	irudiaMugitu(imageIdEzinezkoa, 170, 140);
	irudiakMarraztu(JOKOA);
	pantailaBerriztu(JOKOA);
	Sleep(1000);
	irudiaKendu(imageIdEzinezkoa);
	irudiakMarraztu(JOKOA);
	pantailaBerriztu(JOKOA);
}

void irabaziPantaila(PUNTUAKETA puntuak, int irabazlea) {
	SDL_Color textColor = { 0XFF, 0XFF, 0XFF };
	int ebentuIrabazi;
	int imageIdIrabazi;
	char txuria[128];
	char beltza[128];

	if (irabazlea == ZURI) {
		textColor.r = 0XFF;
		textColor.g = 0XFF;
		textColor.b = 0XFF;
		imageIdIrabazi = irudiaKargatu(IRUDI_IRABAZI_ZURI, JOKOA);
	}
	else {
		textColor.r = 0;
		textColor.g = 0;
		textColor.b = 0;
		imageIdIrabazi = irudiaKargatu(IRUDI_IRABAZI_BELTZ, JOKOA);
	}
	irudiakMarraztu(JOKOA);
	textuaGaitu(30);
	sprintf_s(txuria, 128, "PUNTUAKETA ZURIA: %i", puntuak.zuri);
	sprintf_s(beltza, 128, "PUNTUAKETA BELTZA: %i", puntuak.beltz);
	textuaIdatzi(100, 150, txuria, JOKOA, textColor);
	textuaIdatzi(100, 190, beltza, JOKOA, textColor);
	pantailaBerriztu(JOKOA);
	do {
		ebentuIrabazi = ebentuaJasoGertatuBada();
	} while (ebentuIrabazi != TECLA_RETURN);
	irudiaKendu(imageIdIrabazi);
}