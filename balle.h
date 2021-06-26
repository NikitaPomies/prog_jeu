#pragma once
#include "utils.h"

class Balle{

public :

    bool existe;
    int rayon;
    Color couleur;
    point position;
    double cosinus, sinus;
    double vrai_x, vrai_y;
    int vitesse;

    Balle();
    Balle(double cos, double sin, int rayon, int vit, Color col, point tireur, int rayon_tireur);
    void deplace();
    void dessine();
    void efface();

};

