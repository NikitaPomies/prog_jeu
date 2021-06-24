#pragma once
#include "utils.h"
#include "balle.h"


class Enm_imb{

public:

    point pos_ennemi;
    int rayon;
    int vitesse;
    Color couleur;

    Balle balle;
    int rayon_balle;
    int vitesse_balle;

    Enm_imb (Bords& b, int r, int rb, int v, int vb, Color col);
    void Dessine_enn();
    void init_balle(point P);
    void tirer_balle();

};
