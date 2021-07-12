#pragma once
#include "utils.h"
#include "ennemis.h"


const int barre_vie = COTE_TERRAIN/5;
const double temps_bouclier = 5.0;

class Perso{

public:

    point position;
    int  vitesse;
    int rayon;
    int sante_initiale;
    int vie;
    int puissance_balle;
    bool bouclier;

    Balle balle;
    int rayon_balle;
    int vitesse_balle;
    int dommages;
    Color couleur_balle = BLACK;


    Perso (point ini, int r, int v, int rb, int vb, int sante, int dommages_balle);
    Perso();
    void Dessine_perso(Color col);
    void bouge(int d, const Bords& b);
    void initBalle(point objectif);
    void tirer_balle();
    void init_vie(int menu);
    void dessine_vie_perdue(int degats, int menu);
    void dessine_vie_gagnee(int gain, int menu);
};
