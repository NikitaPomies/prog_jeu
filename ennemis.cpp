#include "ennemis.h"


// Classe Balle


Balle::Balle(double cos, double sin, int ray, Color col, point tireur){

    rayon = ray;
    couleur = col;
    position  = tireur;

    if (-sin>=0)
        direction = acos(cos);
    else if (-sin<=0 && cos>=0)
        direction = asin(sin);
    else
        direction = acos(cos) + M_PI;

    //point ini = {int(4*rayon*cos),int(4*rayon*(-sin))};
    //position = tireur + ini;
}

Balle::Balle(){
}

void Balle::dessine(){
    fillCircle(position.x,position.y,rayon,couleur);
}


void Balle::efface(){
    fillCircle(position.x,position.y,rayon,WHITE);
}


void Balle::deplace(){
    efface();
    position.x+=2*cos(direction);
    position.y-=2*sin(direction);
    dessine();
}


// Classe ennemi

Enm_imb::Enm_imb(Bords &b, int r){
    pos_ennemi= {b.xb/2,b.yb/2};
    rayon_balle = r;
    B.rayon = r;
}

void Enm_imb::Dessine_enn(Color col){
    fillCircle(pos_ennemi.x,pos_ennemi.y,10,col);
}



void Enm_imb::init_balle(Perso P){

    float delta_x = P.c.x - pos_ennemi.x;
    float delta_y = P.c.x - pos_ennemi.y;
    float dist = P.c.euler_dist(pos_ennemi);

    float cos = delta_x/dist;
    float sin = delta_y/dist;

    B = Balle(cos,sin,rayon_balle,couleur_balle,pos_ennemi);

}


void Enm_imb::tirer_balle(){
    B.deplace();
}











