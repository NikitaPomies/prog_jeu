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


void Enm_imb::init_vie(){
    fillRect(pos_ennemi.x-rayon,pos_ennemi.y+rayon+ecart_vie,2*rayon,largeur_vie,GREEN);
}

void Enm_imb::dessine_vie(int degats){
    int enleve = degats*2*rayon/sante_initiale;
    cout << enleve << endl;
    fillRect(pos_ennemi.x-rayon+vie*2*rayon/sante_initiale,pos_ennemi.y+rayon+ecart_vie,-enleve,largeur_vie,RED);
}
void Enm_imb::efface_barre_vie(){

    fillRect(pos_ennemi.x-rayon,pos_ennemi.y+rayon+ecart_vie,2*rayon,largeur_vie,WHITE);
}



// Fonctions diverses

void position_aleatoire(int W, int H, int espace, int menu, point &placement){

    int x = rand()%(2*espace) - espace;
    if(x<0)
        x+=W;

    int y = rand ()%(2*espace) - espace + menu;
    if(y<menu)
        y+=H;

    placement.x=x;
    placement.y=y;

}







