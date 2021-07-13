#include "ennemis.h"



// Classe ennemi

Enm_imb::Enm_imb(int id, point placement, int r, int rb, int vit, int vb, int sante, int attaque, Color col){
    identifiant = id;
    vie = sante;
    sante_initiale = sante;
    pos_ennemi= placement;
    rayon = r;
    rayon_balle = rb;
    vitesse = vit;
    vitesse_balle = vb;
    couleur = col;
    dommages = attaque;
    balle=Balle();
}

void Enm_imb::Dessine_enn(){
    fillCircle(pos_ennemi.x,pos_ennemi.y,rayon,couleur);
}

void Enm_imb::efface_enn(){
    fillCircle(pos_ennemi.x,pos_ennemi.y,rayon,WHITE);
}


// On initialise une balle en donnant les cosinus et sinus de l'angle qui definit sa direction
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


// Affichage


void Enm_imb::init_vie(){
    fillRect(pos_ennemi.x-rayon,pos_ennemi.y+rayon+ecart_vie,2*rayon,largeur_vie,PINK);
}

void Enm_imb::dessine_vie(int degats){
    int enleve = degats*2*rayon/sante_initiale;
    fillRect(pos_ennemi.x-rayon+vie*2*rayon/sante_initiale,pos_ennemi.y+rayon+ecart_vie,-enleve,largeur_vie,RED);
}
void Enm_imb::efface_barre_vie(){

    fillRect(pos_ennemi.x-rayon,pos_ennemi.y+rayon+ecart_vie,2*rayon,largeur_vie,WHITE);
}








