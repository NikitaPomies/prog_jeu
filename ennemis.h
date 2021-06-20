#pragma once
#include "utils.h"

class Enm_imb{


public:
    point pos_ennemi;
    int r_balle;
    point pos_balle;
    Enm_imb (Bords& b,int r);
    void Dessine_balle( Color col);

    void mvmt_balle();
    void Dessine_enn(Color col);
    double  init_balle();
    void dep_balle( double d);

};
