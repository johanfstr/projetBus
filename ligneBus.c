#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "ligneBus.h"
#include "listeDouble.h"
#include <math.h>  // pour sqrt et pow

int calculerDistance(Tstation* a, Tstation* b) {
    return (int)sqrt(pow(a->posX - b->posX, 2) + pow(a->posY - b->posY, 2));
}



Tbus creeBus( int idBus, TlisteStation start ){
    Tbus myBus = (Tbus)malloc(sizeof(Typebus));
    myBus->idBus = idBus;
    busSurStation( myBus, start, depart_vers_arrivee);
    busSurLigneX ( myBus, getIdLigneTroncon(getPtrData(getNextTroncon(start))));
    return myBus;
}


Tstation *creeArret( int posX, int posY, char* nomStation, int idStation){
    Tstation* newStation = (Tstation*)malloc(sizeof(Tstation));

    newStation->arret_ou_troncon = ARRET;

    //champs utiles si ARRET
    newStation->posX = posX;
    newStation->posY = posY;
    strcpy(newStation->nomStation, nomStation);
    newStation->idStation = idStation;

    //champs non utiles si ARRET
    newStation->depart = NULL;
    newStation->arrivee = NULL;
    newStation->coutTemps = 0;
    newStation->coutDistance = 0;
    newStation->idLigneBus= -1;  //id inexistant
    return newStation;
}

Tstation *creeTroncon(int idLigneBus, Tstation* depart, Tstation *arrivee, int coutTemps, int coutDistance){
    Tstation* newStation = (Tstation*)malloc(sizeof(Tstation));

    newStation->arret_ou_troncon = TRONCON;

    //champs non utiles si TRONCON
    newStation->posX = 0;
    newStation->posY = 0;
    strcpy(newStation->nomStation, "");
    newStation->idStation = -1;  //id inexistant

    //champs utiles si TRONCON
    newStation->idLigneBus=idLigneBus;
    newStation->depart = depart;
    newStation->arrivee = arrivee;
    newStation->coutTemps = coutTemps;
    newStation->coutDistance = coutDistance;
    return newStation;
}
















TlisteStation creeLigneDeBus1(){
    TlisteStation newLigne;
    Tstation *dep,*troncon,*arr;

    initListe(&newLigne);

    //creation en mémoire des stations et troncons
    dep = creeArret(10,10,"Charles de Gaulle",1);
    arr = creeArret(300,400,"Jules Ferry",2);

    int distance = calculerDistance(dep, arr);
    troncon = creeTroncon(1, dep, arr, distance, distance);


    //ajout de ces stations et troncons dans la liste doublement chainée  (champ pdata)
    newLigne = ajoutEnFin(newLigne, dep);  //donc la tête)
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(10,410,"Jacques Brel",3);
    troncon = creeTroncon(1,arr,dep,40,160);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    arr = creeArret(200,350,"Saint Exupery",4);
    troncon = creeTroncon(1,dep,arr,45,200);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(500,410,"Stalingrad",5);
    troncon = creeTroncon(1,arr,dep,40,160);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    return newLigne;
}


TlisteStation creeLigneDeBus2(){
    TlisteStation newLigne;
    Tstation *dep,*troncon,*arr;

    initListe(&newLigne);

    //creation en mémoire des stations et troncons
    dep = creeArret(10,100,"Republique",6);
    arr = creeArret(30,300,"Jules Ferry",7);

    int distance = calculerDistance(dep, arr);
    troncon = creeTroncon(1, dep, arr, distance, distance);


    //ajout de ces stations et troncons dans la liste doublement chainée  (champ pdata)
    newLigne = ajoutEnFin(newLigne, dep);  //donc la tête)
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(100,40,"PLace d'armes",8);
    troncon = creeTroncon(2,arr,dep,40,160);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    arr = creeArret(300,30,"Place de l'etoile",9);
    troncon = creeTroncon(2,dep,arr,45,200);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(400,210,"Bobigny",10);
    troncon = creeTroncon(2,arr,dep,40,160);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    return newLigne;
}

TlisteStation creeLigneDeBus3(){
    TlisteStation newLigne;
    Tstation *dep,*troncon,*arr;

    initListe(&newLigne);

    //creation en mémoire des stations et troncons
    dep = creeArret(150,10,"Clemenceau",11);
    arr = creeArret(300,100,"Montmartre",12);

    int distance = calculerDistance(dep, arr);
    troncon = creeTroncon(1, dep, arr, distance, distance);


    //ajout de ces stations et troncons dans la liste doublement chainée  (champ pdata)
    newLigne = ajoutEnFin(newLigne, dep);  //donc la tête)
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(600,610,"Tour eiffel",13);
    troncon = creeTroncon(3,arr,dep,40,160);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    arr = creeArret(70,350,"Les invalides",14);
    troncon = creeTroncon(3,dep,arr,45,200);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, arr);

    dep = creeArret(150,510,"Gare du nord",15);
    troncon = creeTroncon(3,arr,dep,40,160);
    newLigne = ajoutEnFin(newLigne, troncon);
    newLigne = ajoutEnFin(newLigne, dep);

    return newLigne;
}


void afficheConsoleLigneBus( TlisteStation l){
    afficheListe(l);
}

TlisteStation getNextStation( TlisteStation l){
    if (ligneBusVide(l)) return NULL;
    else {
            if (getTypeNoeud(getPtrData(l))==ARRET) {
                    if (ligneBusVide( getNextCell(l) )) return NULL;  //nous sommes sur un terminus
                    else return getNextCell( getNextCell( l ) );  //le prochain arret est dans 2 cellules dans la liste, la cellule suivaante étant un TRONCON
            }
            else return getNextCell( l );  //si on est sur un TRONCON alors la prochaine cellule est la prochaine station (ARRET)
    }
}

TlisteStation getNextTroncon( TlisteStation l){
    if (ligneBusVide(l)) return NULL;
    else {
            if (getTypeNoeud(getPtrData(l))==ARRET) {
                return getNextCell(l);  //la prochaine cellule est un TRONCON, peut être égale à NULL si on est sur un terminus
            }
            else{
                    //printf("\n(getNextTroncon) erreur algo, on est deja sur un troncon");
                    return l;  //on retourne le troncon actuel
            }
    }
}

TlisteStation getPreviousStation( TlisteStation l){
    if (ligneBusVide(l)) return NULL;
    else {
            if (getTypeNoeud(getPtrData(l))==ARRET) {
                    if (ligneBusVide( getPrevCell(l) )) return NULL;  //nous sommes sur un terminus
                    return getPrevCell( getPrevCell( l ) );  //le prochain arret est dans 2 cellules dans la liste, la cellule suivaante étant un TRONCON
            }
            else return getPrevCell( l );  //si on est sur un TRONCON alors la prochaine cellule est la prochaine station (ARRET)
    }
}

bool ligneBusVide( TlisteStation l){
    return listeVide( l );
}

int getPosXListeStation( TlisteStation myStationInListe ){
    return getPosXStation(getPtrData(myStationInListe));
}

int getPosYListeStation( TlisteStation myStationInListe ){
    return getPosYStation(getPtrData(myStationInListe));
}

void deplaceBus(Tbus myBus, TsensParcours sens_deplacement, int *incXSprite, int *incYSprite){
    TlisteStation dest;
    int xdep, ydep, xarr, yarr, pas;
    float ratio;
    pas = 2;  //équivalent au parametre d'erreur dans le tracé de Segment de Bresenham
    //https://fr.wikipedia.org/wiki/Algorithme_de_trac%C3%A9_de_segment_de_Bresenham


    if (sens_deplacement == depart_vers_arrivee) dest = getNextStation(getActualStation(myBus));
        else dest = getPreviousStation(getActualStation(myBus));

    //par défaut: pas de déplacement du bus
    *incXSprite = 0; *incYSprite = 0;

    //si un prochain arret existe?
    if (ligneBusVide(dest)){
        //printf("\nBus id%d est au terminus de la ligne %d sur la station id=%d %s", getIdBus(myBus), getIdLigneActuelleDuBus(myBus),getIdStation(getPtrData(getActualStation(myBus))),getNomStation(getPtrData(getActualStation(myBus))));
    }
    else //s'il existe:
    {
        //soit on est arrivé, soit on est en cours de trajet
        //récupération des coordonnées
        xdep = getPosXBus(myBus);
        ydep = getPosYBus(myBus);
        xarr = getPosXListeStation(dest);
        yarr = getPosYListeStation(dest);

        //sommes-nous arrivés?
        if ((abs(xdep-xarr)<=pas) && (abs(ydep-yarr)<=pas)){
            //alors mise à jour de la station actuelle du bus
            setActualStation( myBus, dest );
            printf("\nLe Bus id%d arrive sur la station id%d %s",getIdBus(myBus),getIdStation(getPtrData(getActualStation(myBus))),getNomStation(getPtrData(getActualStation(myBus))));
        }
        else{
            //sinon on calcule les offsets de déplacements pour la boucle main qui réalise les affichages
            ratio = (float)(abs(yarr-ydep))/(float)(abs(xarr-xdep)); //div euclydienne

            //algo de Bresenham "simplifié de façon ad hoc" et non optimisé (à cause des floats)
            if (xarr>xdep) *incXSprite = pas;
            else if (xarr<xdep) *incXSprite = -pas;

            if (yarr>ydep) *incYSprite = (int)((float)(pas) * ratio);             //pour un déplacement proportionnel en Y selon Y/X
            else if (yarr<ydep) *incYSprite = (int)((float)(-pas) * ratio);

            //remmarque: si xarr==ydep alors *incXSprite reste à 0, idem en Y

            //maj des coord du bus
            setPosXBus(myBus, getPosXBus(myBus) + *incXSprite);
            setPosYBus(myBus, getPosYBus(myBus) + *incYSprite);
        }
    }
}

//Setteurs
void setActualStation( Tbus myBus, TlisteStation arrivalStation );
void setPosXBus(Tbus myBus, int newX);
void setPosYBus(Tbus myBus, int newY);
void setIdLigneBus(Tbus myBus, int idLigne);
void setSensParcours(Tbus myBus, TsensParcours sens );

void setPositionSurLaLigneDeBus( Tbus myBus, TlisteStation myStation);


void busSurStation( Tbus myBus, TlisteStation myStation, TsensParcours sens){

    //Exemple encapsulation: on a préféré les fonctions setteurs à un accés direct aux champs

    setPositionSurLaLigneDeBus( myBus, myStation);
    //myBus->positionSurLaLigneDeBus = myStation;  //interdit

    setSensParcours( myBus, sens);
    //myBus->sensParcours = sens;

    setPosXBus( myBus, getPosXListeStation( myStation ) );
    //myBus->posXBus = getPosXListeStation( myStation );

    setPosYBus( myBus, getPosYListeStation( myStation ) );
    //myBus->posYBus = getPosYListeStation( myStation );

    //idem : on passe ci-dessous par les getteurs et non par un accés direct via les champs
    printf("\nBus id%d est en (x = %d, y = %d) sur la ligne %d, station %s", getIdBus(myBus), getPosXBus(myBus), getPosYBus(myBus), getIdLigneActuelleDuBus(myBus), getNomStation(getPtrData(myStation)));
}

void busSurLigneX( Tbus myBus, int idLigneX ){
    setIdLigneBus(myBus, idLigneX);
}

TlisteStation stationSuivantePourLeBus(Tbus myBus){
    TlisteStation prochaineStation;
    if (getSensParcours(myBus)==depart_vers_arrivee) prochaineStation = getNextStation(getActualStation(myBus));
    else prochaineStation = getPreviousStation(getActualStation(myBus));
    return prochaineStation;
}

void afficheCoordonneesBus( Tbus myBus ){
    char *nomProchaineStation;
    TlisteStation prochaineStation = stationSuivantePourLeBus(myBus);

    if (ligneBusVide(prochaineStation)) printf("\nBus id: %d est en (x = %d, y = %d) ligne %d, derniere station %s (Terminus)", getIdBus(myBus), getPosXBus(myBus), getPosYBus(myBus), getIdLigneActuelleDuBus(myBus), getNomStation(getPtrData(getActualStation(myBus))));
    else {
            nomProchaineStation = getNomStation(getPtrData(prochaineStation));
            printf("\nBus id: %d est en (x = %d, y = %d) ligne %d, derniere station %s, prochaine station %s", getIdBus(myBus), getPosXBus(myBus), getPosYBus(myBus), getIdLigneActuelleDuBus(myBus), getNomStation(getPtrData(getActualStation(myBus))), nomProchaineStation);
    }
}



int lignesBus() {
    FILE *f = fopen("Stations_et_lignesDeBus.data", "w");
    if (!f) {
        printf("Erreur création fichier\n");
        return 1;
    }

    fprintf(f, "ARRET;10;10;Charles de Gaulle;1\n");
    fprintf(f, "TRONCON;1;1;2;412;412\n");
    fprintf(f, "ARRET;300;400;Jules Ferry;2\n");
    fprintf(f, "TRONCON;1;1;2;412;412\n");
    fprintf(f, "ARRET;10;410;Jacques Brel;3\n");
    fprintf(f, "TRONCON;1;2;3;40;160\n");
    fprintf(f, "ARRET;200;350;Saint Exupery;4\n");
    fprintf(f, "TRONCON;1;3;4;45;200\n");
    fprintf(f, "ARRET;500;410;Stalingrad;5\n");
    fprintf(f, "TRONCON;1;4;5;40;160\n");

    fclose(f);
    printf("Fichier créé avec succès.\n");
    return 0;
}

TlisteStation chargerLignes(Tbus monBus) {
    FILE *f = fopen("Stations_et_lignesDeBus.data", "r");
    TlisteStation newLigne;
    initListe(&newLigne);
    char ligne[256];
    Tstation *tabStations[100] = {NULL};
    int idStationBus = -1;

    if (!f) {
        return newLigne;
    }

    while (fgets(ligne, sizeof(ligne), f)) {
        if (strncmp(ligne, "ARRET", 5) == 0) {
            int x, y, id;
            char nom[100];
            sscanf(ligne, "ARRET;%d;%d;%[^;];%d", &x, &y, nom, &id);

            Tstation *arret = creeArret(x, y, nom, id);
            tabStations[id] = arret;
            newLigne = ajoutEnFin(newLigne, arret);
        }
        else if (strncmp(ligne, "TRONCON", 7) == 0) {
            int idLigne, idDep, idArr, distance, duree;
            sscanf(ligne, "TRONCON;%d;%d;%d;%d;%d", &idLigne, &idDep, &idArr, &distance, &duree);

            Tstation *dep = tabStations[idDep];
            Tstation *arr = tabStations[idArr];

            if (dep != NULL && arr != NULL) {
                distance = calculerDistance(dep, arr);
                duree = distance;

                Tstation *troncon = creeTroncon(idLigne, dep, arr, distance, duree);
                newLigne = ajoutEnFin(newLigne, troncon);
            } else {
                printf("Erreur : station %d ou %d introuvable pour le tronçon.\n", idDep, idArr);
            }
        }
        else if (strncmp(ligne, "BUS", 3) == 0) {
            sscanf(ligne, "BUS;%d", &idStationBus);
        }
    }

    fclose(f);

    if (idStationBus != -1) {
        TlisteStation temp = newLigne;
        while (temp != NULL) {
            Tstation *s = getPtrData(temp);
            if (getIdStation(s) == idStationBus) {
                setActualStation(monBus, temp);
                setPosXBus(monBus, getPosXStation(s));
                setPosYBus(monBus, getPosYStation(s));
                break;
            }
            temp = temp->suiv;
        }
    } else {
        printf("Aucune station de départ spécifiée pour le bus.\n");
    }

    return newLigne;
}

void sauvegarderLignes(TlisteStation ligne, Tbus monBus) {
    FILE *f = fopen("Stations_et_lignesDeBus.data", "w");
    if (!f) {
        return;
    }
    // Sauvegarde de la position du bus
    TlisteStation posBus = getActualStation(monBus);
    if (posBus && posBus->pdata) {
        fprintf(f, "BUS;%d\n", getIdStation(posBus->pdata));
    } else {
        printf("Position du bus inconnue ou invalide\n");
    }

    fclose(f);
}


//Fusionne station en ayant pour depart la premiere et comme arrivé la seconde
TlisteStation fusionnerLignes(TlisteStation ligne1, TlisteStation ligne2) {
    TlisteStation nouvelleLigne;
    initListe(&nouvelleLigne);

    TlisteStation temp1 = ligne1;

    while (temp1 && temp1->suiv) {
        Tstation *station = temp1->pdata;
        nouvelleLigne = ajoutEnFin(nouvelleLigne, station);
        temp1 = temp1->suiv;
    }

    TlisteStation temp2 = ligne2;
    while (temp2) {
        Tstation *station = temp2->pdata;
        nouvelleLigne = ajoutEnFin(nouvelleLigne, station);
        temp2 = temp2->suiv;
    }

    return nouvelleLigne;
}

TlisteStation supprimerStation(TlisteStation ligne, int idStationASupprimer) {
    if (ligne == NULL) {
        return NULL;
    }
    TlisteStation courant = ligne;
    while (courant != NULL) {
        Tstation* station = courant->pdata;

        if (station != NULL && station->arret_ou_troncon == ARRET && station->idStation == idStationASupprimer) {
            //Supprimer tronçons liés avant de supprimer la station
            TlisteStation temp = ligne;
            while (temp != NULL) {
                Tstation* troncon = temp->pdata;
                if (troncon != NULL && troncon->arret_ou_troncon == TRONCON) {
                    if ((troncon->depart != NULL && troncon->depart->idStation == idStationASupprimer) ||
                        (troncon->arrivee != NULL && troncon->arrivee->idStation == idStationASupprimer)) {

                        TlisteStation aSupprimer = temp;
                        temp = temp->suiv;

                        // Mise à jour des liens
                        if (aSupprimer->prec != NULL)
                            aSupprimer->prec->suiv = aSupprimer->suiv;
                        if (aSupprimer->suiv != NULL)
                            aSupprimer->suiv->prec = aSupprimer->prec;

                        // Si le tronçon supprimé est la tête
                        if (aSupprimer == ligne) ligne = aSupprimer->suiv;

                        free(aSupprimer->pdata);
                        free(aSupprimer);
                        continue;
                    }
                }
                temp = temp->suiv;
            }

            //Après avoir supprimé les tronçons, supprimer la station elle-même
            if (courant->prec != NULL) courant->prec->suiv = courant->suiv;
            if (courant->suiv != NULL) courant->suiv->prec = courant->prec;

            if (courant == ligne) ligne = courant->suiv;

            free(courant->pdata);
            free(courant);

            return ligne;
        }
        courant = courant->suiv;
    }
    return ligne;
}

//Rend la ligne circulaire
void rendreLigneCirculaire(TlisteStation *ligne) {
    if (*ligne == NULL) {
        return;
    }
    TlisteStation temp = *ligne;

    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }
    temp->suiv = *ligne;
    (*ligne)->prec = temp;
}

//Permet de savoir si le bus est au terminus
int busSurTerminus(Tbus bus) {
    if (bus == NULL) {
        return 0;
    }
    TlisteStation position = bus->positionSurLaLigneDeBus;

    if (position == NULL) {
        return 0;
    }
    Tstation *premiereStation = position->pdata;
    TlisteStation premierNoeud = bus->positionSurLaLigneDeBus->prec;

    // On vérifie que la station actuel est la première ou la dernière
    if (premierNoeud != NULL && getIdStation(premiereStation) == getIdStation(premierNoeud->pdata)) {
        return 1;
    }
    TlisteStation temp = bus->positionSurLaLigneDeBus;

    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }
    Tstation *derniereStation = temp->pdata;

    if (getIdStation(premiereStation) == getIdStation(derniereStation)) {
        printf("Le bus est au terminus (arrivée).\n");
        return 1;
    }

    return 0;
}

//Gère le compteur de tours
void incrementerCompteur(int *compteur) {
    (*compteur)++;
    printf("Compteur de tours: %d\n", *compteur);
}

//Remet le bus au point de depart de la ligne
void resetBusToStart(Tbus bus) {
    if (bus == NULL) {
        return;
    }
    //Position du bus sur la ligne
    TlisteStation ligne = bus->positionSurLaLigneDeBus;

    if (ligne == NULL) {
        return;
    }
    Tstation *premiereStation = ligne->pdata;
    setPositionSurLaLigneDeBus(bus, premiereStation);
}

