#include "ennemis.h"


Enm_imb::Enm_imb(Bords&b, int r){

    pos_ennemi= {b.xb/2,b.yb/2};
    r_balle=r;


}

void Enm_imb::Dessine_enn(Color col){

    fillCircle(pos_ennemi.x,pos_ennemi.y,10,col);

}

void Enm_imb::Dessine_balle( Color col){

    fillCircle(pos_balle.x,pos_balle.y,5,col);


}

double Enm_imb::init_balle(){

    //c içi qu'il faut modifier la direction de tir de la balle
    pos_balle=pos_ennemi;

    float X=random_perso();
    cout<<X<<endl;



    float  direction=3.14*X;


    return direction;

}
void Enm_imb::dep_balle(float d){


         Dessine_balle(WHITE);
         pos_balle.x+=2*cos(d);
         pos_balle.y-=2*sin(d);

         Dessine_balle(BLACK);
         //milliSleep(10);
     }











