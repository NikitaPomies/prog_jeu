
#include "perso.h"


void Perso::Dessine_perso(Color col){


    fillCircle(c.x,c.y,rayon,col);

}

Perso::Perso(int x,int y,int r, int v){
    c.x=x;
    c.y=y;
    rayon=r;
    vitesse=v;




}

void Perso::bouge(int d, const Bords& b ){
    Dessine_perso(WHITE);
    point dir_new={dir[d].x*vitesse,dir[d].y*vitesse};
    point p=c+dir_new;

    bool cbsup= p.y-rayon >0;
    bool cbinf=p.y+rayon<b.yb;
    bool cbdroit=p.x+rayon<b.xb;
    bool cbgauche=p.x-rayon>0;
    if (cbsup & cbinf & cbdroit & cbgauche){

       c=p;
    }

    Dessine_perso(RED);
}
