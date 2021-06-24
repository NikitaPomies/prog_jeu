#pragma once
#include "utils.h"
#include "ennemis.h"



class Perso{

public:

    point position;
    int  vitesse;
    int rayon;

    Balle balle;
    int rayon_balle;
    int vitesse_balle;
    Color couleur_balle = BLACK;


    Perso (point ini, int r, int v, int rb, int vb);
    Perso();
    void Dessine_perso(Color col);
    void bouge(int d, const Bords& b);
    void initBalle(point objectif);
    void tirer_balle();
};
