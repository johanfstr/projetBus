#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "types.h"

void afficheStation( Tstation *station){
    if (station == NULL){
        printf("\nerreur station non allouée!\n");
    }
    else{
        if (station->arret_ou_troncon == ARRET){
            printf("\nSTATION idStation: %d, Station : %s, posX = %d, posY = %d", station->idStation, station->nomStation, station->posX, station->posY);
        }
        else{ //alors le noeud est un tronçon
            printf("\n\nTRONCON idLigneBus: %d, temps: %d sec, distance à parcourir: %d mètres", station->idLigneBus, station->coutTemps, station->coutDistance);
            afficheStation(station->depart);
            afficheStation(station->arrivee);
            printf("\nfin tronçon\n");
        }
    }
}

// Getteurs

int getIdStation( Tstation *myStation){
    return myStation->idStation;
}

char *getNomStation( Tstation *myStation){
    return myStation->nomStation;
}

int getPosXStation( Tstation *myStation ){
    return myStation->posX;
}
int getPosYStation( Tstation *myStation ){
    return myStation->posY;
}

int getIdLigneTroncon(Tstation *myStation){
    //une station n'est pas liée à une ligne, seulement le troncon
    if (getTypeNoeud(myStation)==TRONCON)
        return myStation->idLigneBus;
    else{
        //printf("\n(getIdLigneTroncon) Erreur algo, vous n etes pas sur un troncon");
        return -1;
    }
}

TypeNoeud getTypeNoeud(Tstation *myStation){
    return myStation->arret_ou_troncon;
}



int getPosXBus( Tbus myBus ){
    return myBus->posXBus;
}
int getPosYBus( Tbus myBus ){
    return myBus->posYBus;
}
int getIdBus( Tbus myBus ){
    return myBus->idBus;
}
int getIdLigneActuelleDuBus( Tbus myBus ){
    return myBus->idLigneBusActuelle;
}

int getIdLigneBus(Tbus myBus){
    return myBus->idLigneBusActuelle;
}

TsensParcours getSensParcours(Tbus myBus){
    return myBus->sensParcours;
}

int getCoutMaintenance(Tstation *myStation){
    return myStation->coutMaintenance;
}

int getDateDerniereMaintenanceJour(Tstation *myStation){
    return myStation->dateDerniereMaintenance.jour;
}

int getDateDerniereMaintenanceMois(Tstation *myStation){
    return myStation->dateDerniereMaintenance.mois;
}

int getDateDerniereMaintenanceAnnee(Tstation *myStation){
    return myStation->dateDerniereMaintenance.annee;
}




// Setteurs

void setActualStation( Tbus myBus, TlisteStation arrivalStation ){
    myBus->positionSurLaLigneDeBus = arrivalStation;
}

TlisteStation getActualStation( Tbus myBus ){
    return myBus->positionSurLaLigneDeBus;
}

void setPosXBus(Tbus myBus, int newX){
    myBus->posXBus = newX;
}

void setPosYBus(Tbus myBus, int newY){
    myBus->posYBus = newY;
}

void setIdLigneBus(Tbus myBus, int idLigne){
    myBus->idLigneBusActuelle = idLigne;
}

void setSensParcours(Tbus myBus, TsensParcours sens ){
    myBus->sensParcours = sens;
}

void setPositionSurLaLigneDeBus( Tbus myBus, TlisteStation myStation){
    myBus->positionSurLaLigneDeBus = myStation;
}

void setCoutMaintenance(Tstation *myStation){
    myStation->coutMaintenance = (rand() % 91) + 10;
}

void setDateDerniereMaintenanceAnnee(Tstation *myStation){
    myStation->dateDerniereMaintenance.annee = (rand() % 26) + 2000;
}

void setDateDerniereMaintenanceMois(Tstation *myStation){
    myStation->dateDerniereMaintenance.mois = rand() % 13;
}

void setDateDerniereMaintenanceJour(Tstation *myStation){
    switch (getDateDerniereMaintenanceMois(myStation)){
        case 2 : myStation->dateDerniereMaintenance.jour = rand() % 29; break;
        default : myStation->dateDerniereMaintenance.jour = rand() % 31; break;
    }
}

//Comparateurs
bool comp_CoupMaintenance_AsupB (Tstation *a, Tstation *b){
    return getCoutMaintenance(a) > getCoutMaintenance(b);
}

bool comp_CoupMaintenance_AinfB (Tstation *a, Tstation *b){
    return getCoutMaintenance(a) < getCoutMaintenance(b);
}

bool comp_CoupMaintenance_AegaleB (Tstation *a, Tstation *b){
    return getCoutMaintenance(a) == getCoutMaintenance(b);
}

bool comp_DateMaintenance_AsupB  (Tstation *a, Tstation *b){
    return (getDateDerniereMaintenanceAnnee(a) > getDateDerniereMaintenanceAnnee(b))
    || ((getDateDerniereMaintenanceAnnee(a) == getDateDerniereMaintenanceAnnee(b)) && (getDateDerniereMaintenanceMois(a) > getDateDerniereMaintenanceMois(b)))
    || ((getDateDerniereMaintenanceAnnee(a) == getDateDerniereMaintenanceAnnee(b)) && (getDateDerniereMaintenanceMois(a) == getDateDerniereMaintenanceMois(b)) && (getDateDerniereMaintenanceJour(a) > getDateDerniereMaintenanceJour(b)));
}

bool comp_DateMaintenance_AinfB (Tstation *a, Tstation *b){
    return (getDateDerniereMaintenanceAnnee(a) < getDateDerniereMaintenanceAnnee(b))
    || ((getDateDerniereMaintenanceAnnee(a) == getDateDerniereMaintenanceAnnee(b)) && (getDateDerniereMaintenanceMois(a) < getDateDerniereMaintenanceMois(b)))
    || ((getDateDerniereMaintenanceAnnee(a) == getDateDerniereMaintenanceAnnee(b)) && (getDateDerniereMaintenanceMois(a) == getDateDerniereMaintenanceMois(b)) && (getDateDerniereMaintenanceJour(a) < getDateDerniereMaintenanceJour(b)));

}

bool comp_DateMaintenance_AegaleB (Tstation *a, Tstation *b){
    return  ((getDateDerniereMaintenanceAnnee(a) == getDateDerniereMaintenanceAnnee(b)) && (getDateDerniereMaintenanceMois(a) == getDateDerniereMaintenanceMois(b)) && (getDateDerniereMaintenanceJour(a) == getDateDerniereMaintenanceJour(b)));
}
