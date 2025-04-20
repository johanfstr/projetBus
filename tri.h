#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED

#include <stdbool.h>

#include "types.h"
#define DEBUG 1

void swapPtrDataStation(TlisteStation source, TlisteStation destination);
void tri_selection_liste_station(TlisteStation l, bool(*fcomp)(Tstation A, Tstation B));
