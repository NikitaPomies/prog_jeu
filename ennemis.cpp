#include "ennemis.h"


// Classe ennemi

Enm_imb::Enm_imb(Bords &b, int r, int rb, int v, int vb, Color col){
    pos_ennemi= {b.xb/2,b.yb/2};
    rayon = r;
    rayon_balle = rb;
    vitesse = v;
    vitesse_balle = vb;
    couleur = col;
}

void Enm_imb::Dessine_enn(){
    fillCircle(pos_ennemi.x,pos_ennemi.y,10,couleur);
}

void Enm_imb::init_balle(point P){

    double delta_x = P.x - pos_ennemi.x;
    double delta_y = P.y - pos_ennemi.y;
    double dist = P.euler_dist(pos_ennemi);

    double cos = delta_x/dist;
    double sin = delta_y/dist;

    balle = Balle(cos,sin,rayon_balle,vitesse_balle,couleur,pos_ennemi,rayon);

}


void Enm_imb::tirer_balle(){
    balle.deplace();
}











