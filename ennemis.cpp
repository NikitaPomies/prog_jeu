#include "ennemis.h"


// Classe Balle


// Modifier le coefficient 3 de l'initialisation pour l'adapter à la taille du tireur
// Permet de ne pas effacer le cercle du tireur

Balle::Balle(double cos, double sin, int ray, int vit, Color col, point tireur){

    rayon = ray;
    vitesse = vit;
    couleur = col;
    cosinus = cos;
    sinus = sin;

    vrai_x = tireur.x + 3*rayon*cos;
    vrai_y = tireur.y + 3*rayon*sin;

    position.x = int(vrai_x);
    position.y = int(vrai_y);

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
    position.x=int(vrai_x);
    position.y=int(vrai_y);
    vrai_x += vitesse*cosinus;
    vrai_y += vitesse*sinus;
    dessine();
}


// Classe ennemi

Enm_imb::Enm_imb(Bords &b, int r, int rb, int v, int vb){
    pos_ennemi= {b.xb/2,b.yb/2};
    rayon = r;
    rayon_balle = rb;
    vitesse = v;
    vitesse_balle = vb;
}

void Enm_imb::Dessine_enn(Color col){
    fillCircle(pos_ennemi.x,pos_ennemi.y,10,col);
}

void Enm_imb::init_balle(Perso P){

    double delta_x = P.c.x - pos_ennemi.x;
    double delta_y = P.c.y - pos_ennemi.y;
    double dist = P.c.euler_dist(pos_ennemi);

    double cos = delta_x/dist;
    double sin = delta_y/dist;

    B = Balle(cos,sin,rayon_balle,vitesse_balle,couleur_balle,pos_ennemi);

}


void Enm_imb::tirer_balle(){
    B.deplace();
}











