#include "balle.h"



// Classe Balle

Balle::Balle(double cos, double sin, int ray, int vit, Color col, point tireur, int rayon_tireur){

    rayon = ray;
    vitesse = vit;
    couleur = col;
    cosinus = cos;
    sinus = sin;

    vrai_x = tireur.x + rayon_tireur*rayon*cos;
    vrai_y = tireur.y + rayon_tireur*rayon*sin;

    position.x = int(vrai_x);
    position.y = int(vrai_y);
    existe = true;

}

Balle::Balle(){
}

void Balle::dessine(){
    fillCircle(position.x,position.y,rayon,couleur);
}


void Balle::efface(){
    fillCircle(position.x,position.y,rayon,WHITE);
}


// On est contraint d'utiliser deux variables pour la coordonnee en x et en y
// car les pixels ne prennent que des valeurs entieres, ce qui limite enormement les directions prises
// par la balle au moment de son initialisation notamment (9 directions au total)
// la vraie direction est sotckee dans vrai_x et vrai_y, et la direction suivie par la balle est stockee directement
// dans position.x / .y, corrigee a chaque pas de temps
void Balle::deplace(){
    if (existe){
        efface();
        position.x=int(vrai_x);
        position.y=int(vrai_y);
        vrai_x += vitesse*cosinus;
        vrai_y += vitesse*sinus;
        dessine();
    }
}


bool Balle::balle_sortie(int w, int h, int menu){
    return (position.y<=menu + rayon || position.y>=h + menu || position.x<=0 || position.x>=w);
}


void Balle::meurt(){
    existe = false;
    efface();
}
