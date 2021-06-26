
#include "perso.h"


// Classe perso

void Perso::Dessine_perso(Color col){
    fillCircle(position.x,position.y,rayon,col);
}

Perso::Perso(point ini, int r, int v, int rb, int vb){
    position = ini;
    rayon=r;
    vitesse=v;
    vitesse_balle = vb;
    rayon_balle =rb;
}

Perso::Perso(){
}


void Perso::bouge(int d, const Bords& b ){

    Dessine_perso(WHITE);
    point dir_new={dir[d].x*vitesse,dir[d].y*vitesse};
    point p=position+dir_new;

    bool cbsup= p.y-rayon >0;
    bool cbinf=p.y+rayon<b.yb;
    bool cbdroit=p.x+rayon<b.xb;
    bool cbgauche=p.x-rayon>0;

    if (cbsup & cbinf & cbdroit & cbgauche){
       position=p;
    }

    Dessine_perso(RED);
}


void Perso::initBalle(point objectif){

    double delta_x = objectif.x - position.x;
    double delta_y = objectif.y - position.y;
    double dist = objectif.euler_dist(position);

    double cos = delta_x/dist;
    double sin = delta_y/dist;

    balle = Balle(cos,sin,rayon_balle,vitesse_balle,couleur_balle,position,rayon);
}


void Perso::tirer_balle(){
    balle.deplace();
}








