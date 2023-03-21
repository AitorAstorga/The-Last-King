#ifndef JOKOMOTAK_H
#define JOKOMOTAK_H

#include "jokoa.h"

int moduIntercambio;

void botSimetriko(LAUKIA* clickatua, LAUKIA *laukiak, int* beltzPuntuaketa);
void mugimenduAleatorio(LAUKIA* laukiak);
int intercambio(LAUKIA* laukiak, int* aldaketaGaitua, int* aleatorio, time_t* t1);
void botIA(LAUKIA* laukiak, int* beltzPuntuaketa);
void luckyBlock(LAUKIA* laukiak);

#endif