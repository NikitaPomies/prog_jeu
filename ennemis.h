#pragma once
#include "utils.h"
#include "balle.h"


// Pour l'affichage
const int ecart_vie = 5;
const int largeur_vie = 5;


class  Enm_imb{

public:

    int identifiant; // inutile finalement
    point pos_ennemi;
    int rayon;
    int vitesse;
    Color couleur;
    int vie;
    int sante_initiale;

    int barre_vie;

    Balle balle;
    int rayon_balle;
    int vitesse_balle;
    int dommages;

    Enm_imb (int id, point placement, int r, int rb, int vit, int vb, int sante, int attaque, Color col);
    void Dessine_enn();
    void init_balle(point P);
    void tirer_balle();
    void efface_enn();
    void efface_barre_vie();
    void init_vie();
    void dessine_vie(int degats);

};


