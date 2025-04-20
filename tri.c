#include <stdio.h>
#include <stdlib.h>

#include "tri.h"
#include "listeDouble.h"
//
void swapPtrDataStation(TlisteStation source, TlisteStation destination) {
    if (listeVide(source) || listeVide(destination)) {
        if (DEBUG) printf("Erreur swapPtrDataStation ptr = NULL");
    } else {
        Tstation* tmp = source -> pdata;
        source -> pdata = destination -> pdata;
        destination -> pdata = tmp;
    }
}


void tri_selection_liste_station(TlisteStation l, bool(*fcomp)(Tstation A, Tstation B))
{
    TlisteStation en_cours, plus_petit, j, fin;  //pointeurs sur cellule donc TlisteStation

    fin = getptrLastCell (l); //pour ne faire qu'un seul appel de cette fonction en O(n)

    //nous ne faisons ici que des branchements et déplacements de pointeurs
    for (en_cours = l; en_cours != fin; en_cours = getptrNextCell(en_cours)) //avec "en_cours != fin", nous nous arrêtons bien sur l'avant dernière cellule
    {
        plus_petit = en_cours;
        for (j = en_cours ; j != fin; j = getptrNextCell(j))
        {
            if (fcomp(*getPtrData(plus_petit),*getPtrData(j)))  //MAJ fcomp
                plus_petit = j;  //branchement de "plus_petit" sur la cellule ayant une valeur point�e par data plus petite que celle point�e par plus_petit
        }
        //comparaison avec la cellule fin non compar�e dans le FOR ci-dessus
        if (fcomp(*getPtrData(plus_petit), *getPtrData(fin))) plus_petit = fin;  //MAJ fcomp

        //swap
        swapPtrDataStation(en_cours, plus_petit);
    }
}
