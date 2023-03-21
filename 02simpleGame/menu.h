#ifndef MENU_H
#define MENU_H

#include "OurTypes.h"
#include <stdio.h>
#include "jokoa.h"

int musikaEgoera;
int soinuEgoera;

EGOERA menu();
EGOERA berria();
EGOERA kargatu();
EGOERA errepikapenak();
EGOERA itxi();
EGOERA bots();
EGOERA menuPausa(EGOERA partidaMota);
void popUpEzinezkoa();
void irabaziPantaila(PUNTUAKETA puntuak, int irabazlea);

#endif // !MENU_H