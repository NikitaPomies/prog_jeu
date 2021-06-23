#pragma once
#include "utils.h"
#include "perso.h"


class Balle{

public :

    int rayon;
    Color couleur;
    point position;
    double cosinus, sinus;
    double vrai_x, vrai_y;
    int vitesse;

    Balle();
    Balle(double cos, double sin, int rayon, int vit, Color col, point tireur);
    void deplace();
    void dessine();
    void efface();

};


class Enm_imb{

public:

    point pos_ennemi;
    int rayon;
    int vitesse;
    Color couleur;

    Balle B;
    int rayon_balle;
    int vitesse_balle;
    Color couleur_balle;


    Enm_imb (Bords& b, int r, int rb, int v, int vb);
    void Dessine_enn(Color col);
    void init_balle(Perso P);
    void tirer_balle();

};
