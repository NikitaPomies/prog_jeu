#pragma once
#include "utils.h"
#include "balle.h"


class  Enm_imb{

public:

    int identifiant;
    point pos_ennemi;
    int rayon;
    int vitesse;
    Color couleur;
    int vie;

    Balle balle;
    int rayon_balle;
    int vitesse_balle;
    int dommages;

    Enm_imb (int id, Bords& b, int r, int rb, int vit, int vb, int sante, Color col);
    void Dessine_enn();
    void init_balle(point P);
    void tirer_balle();
    bool balle_sortie(int w , int h);

};
