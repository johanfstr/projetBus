#ifndef LISTEDOUBLE_H_INCLUDED
#define LISTEDOUBLE_H_INCLUDED

#include <stdbool.h>
#include "types.h"

/*  défini dans types.h
typedef struct T_cell{
    struct T_cell *suiv;
    struct T_cell *prec;
    Tstation *pdata;              //attention à faire un malloc sur ce champ avant de s'en servir
} T_cellule;
typedef T_cellule* T_liste;
*/

void initListe(T_liste *l);
bool listeVide( T_liste l);

void afficheListe( T_liste l);


T_liste ajoutEnTete(T_liste l, Tstation* mydata);
T_liste ajoutEnFin(T_liste l, Tstation* mydata);

Tstation* getPtrData(T_liste l);
T_liste getNextCell(T_liste l);
T_liste getPrevCell(T_liste l);


#endif // LISTEDOUBLE_H_INCLUDED

