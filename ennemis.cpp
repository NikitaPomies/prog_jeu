#include "ennemis.h"


Enm_imb::Enm_imb(Bords&b, int r){

    pos_ennemi= {b.xb/2,b.yb};
    r_balle=r;


}

void Enm_imb::Dessine_enn(Color col){

    fillCircle(pos_ennemi.x,pos_ennemi.y,10,col);

}

void Enm_imb::Dessine_balle( Color col){

    fillCircle(pos_balle.x,pos_balle.y,5,col);


}

double Enm_imb::init_balle(){
    pos_balle=pos_ennemi;

    double X=((double)rand()/(double)RAND_MAX);



    double  direction=M_PI*X;

    cout<<direction;
    return M_PI/4;

}
void Enm_imb::dep_balle(double d){


         Dessine_balle(WHITE);
         pos_balle.x+=1;
         pos_balle.y-=tan(d);

         Dessine_balle(BLACK);
         //milliSleep(10);
     }











