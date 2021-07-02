
#include "perso.h"


// Classe perso

void Perso::Dessine_perso(Color col){
    fillCircle(position.x,position.y,rayon,col);
}

Perso::Perso(point ini, int r, int v, int rb, int vb, int sante, int dommages_balle){
    position = ini;
    rayon=r;
    vitesse=v;
    vitesse_balle = vb;
    rayon_balle =rb;
    vie = sante;
    sante_initiale = sante;
    dommages=0;
    puissance_balle=dommages_balle;
    balle=Balle();
}

Perso::Perso(){
}


void Perso::bouge(int d, const Bords& b ){

    Dessine_perso(WHITE);
    point dir_new={dir[d].x*vitesse,dir[d].y*vitesse};
    point p=position+dir_new;

    bool cbsup= p.y-rayon >b.menu;
    bool cbinf=p.y+rayon<b.yb+b.menu;
    bool cbdroit=p.x+rayon<b.xb;
    bool cbgauche=p.x-rayon>0;

    if (cbsup & cbinf & cbdroit & cbgauche){
       position=p;
    }

    Dessine_perso(BLACK);
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


void Perso::init_vie(){
    drawRect(20,20,barre_vie+1,21,BLACK);
    fillRect(21,21,barre_vie,20,GREEN);
}

void Perso::dessine_vie(int degats){
    int enleve = degats*barre_vie/sante_initiale;
    fillRect(21+vie*barre_vie/sante_initiale,21,-enleve,20,RED);
}







