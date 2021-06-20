#include "utils.h"
#pragma once


class Perso{
public:
    int  vitesse;
    point c;
    int rayon;
    Perso(int xc,int yc, int rayon, int v);
    void Dessine_perso(Color col);
    void bouge(int d, const Bords& b);

};
