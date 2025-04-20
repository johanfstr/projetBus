#ifndef JEU2048_H_INCLUDED
#define JEU2048_H_INCLUDED

#define LARGEURJEU 11
#define HAUTEURJEU 19

typedef enum{tour, tourRoi, archer, chevalier, dragon, gargouille} TuniteDuJeu;
typedef enum{sol, solEtAir, air } Tcible;


typedef struct {
    TuniteDuJeu nom;
    Tcible cibleAttaquable;	//indique la position des unit�s que l�on peut attaquer
    Tcible maposition;		//indique soit � air � soit � sol �, utile pour savoir
                            //qui peut nous attaquer
    int pointsDeVie;
    float vitesseAttaque;	//en seconde, plus c�est petit plus c�est rapide
    int degats;
    int portee ;			//en m�tre, distance sur laquelle on peut atteindre une
                            //cible

    float vitessedeplacement;	//en m/s
    int posX, posY;			//position sur le plateau de jeu
    int peutAttaquer;		//permet de g�rer le fait que chaque unit� attaque une
                            //seule fois par tour ;
                            //0 = a d�j� attaqu�, 1 = peut attaquer ce tour-ci
                            // � remettre � 1 au d�but de chaque tour
    int coutEnElixir;
} Tunite;

typedef struct T_cell{
    struct T_cell *suiv;
    Tunite *pdata; //pointeur vers une unit�
} *TListePlayer;


typedef Tunite* ** TplateauJeu;  ////tableau a deux dimensions de largeur 11 et hauteur 19 contenant des pointeurs (Tunite*)


TplateauJeu AlloueTab2D(int largeur, int hauteur);
void initPlateauAvecNULL(TplateauJeu jeu,int largeur, int hauteur);
void affichePlateauConsole(TplateauJeu jeu, int largeur, int hauteur);


Tunite *creeTour(int posx, int posy);
Tunite *creeTourRoi(int posx, int posy);

/*
Bool tourRoiDetruite(TListePlayer player);
void PositionnePlayerOnPlateau(TListePlayer player, TplateauJeu jeu)

TListePlayer quiEstAPortee(TListePlayer player, Tunite *uneUniteDeLautreJoueur);
TListePlayer combat(TListePlayer player, Tunite *uneUniteDeLautreJoueur);


Tunite *creeArcher(int posx, int posy);
Tunite *creeGargouille(int posx, int posy);
Tunite *creeDragon(int posx, int posy);
Tunite *creeChevalier(int posx, int posy);

Void supprimerUnite(TListePlayer *player, Tunite *UniteDetruite);
Tunite AcheteUnite(int *elixirEnStockduJoueur);
Void AjouterUnite(TListePlayer *player, Tunite *nouvelleUnite);

*/

#endif // JEU2048_H_INCLUDED
