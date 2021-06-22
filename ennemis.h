#pragma once
#include "utils.h"
#include "perso.h"


class Balle{

public :

    int rayon;
    Color couleur;
    point position;
    double direction;
    float vitesse;

    Balle();
    Balle(double cos, double sin, int rayon, Color col, point tireur);
    void deplace();
    void dessine();
    void efface();

};


class Enm_imb{

public:

    point pos_ennemi;
    Balle B;
    int rayon_balle;
    Color couleur_balle;

    Enm_imb (Bords& b,int r);
    void Dessine_enn(Color col);
    void init_balle(Perso P);
    void tirer_balle();

};
