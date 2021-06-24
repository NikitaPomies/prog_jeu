
#include "utils.h"
#include "perso.h"
#include "ennemis.h"



void fillTriangle(point P, int size, Color COL){
    int x[]={P.x+size,P.x-size,P.x};
    int y[]={P.y-size,P.y-size,P.y+size};
    fillPoly(x,y,3,COL);
}

void fillDiamond(point P, int size, Color COL){
    int x[]={P.x-size/2,P.x,P.x+size/2,P.x};
    int y[]={P.y,P.y-size,P.y,P.y+size};
    fillPoly(x,y,4,COL);
}

bool collision(const Enm_imb& e,const Perso& p){
    int dist=e.balle.rayon+p.rayon;
    return p.position.euler_dist(e.balle.position)<=dist;
}





void jeu(int w, int h){

    Bords b(w,h);
    point posi_ini_perso = {50,50};
    Perso P(posi_ini_perso,10,6,2,3);
    Enm_imb e(b,5,3,2,3,GREEN);

    b.Dessine_bords();

    e.Dessine_enn();
    e.init_balle(P.position);

    P.Dessine_perso(BLACK);

    click();

    cout<<"oui"<<endl;

    bool t=true;

    do {

       if (e.balle.position.y==0 || e.balle.position.y==h || e.balle.position.x==0 || e.balle.position.x==w )
          e.init_balle(P.position);

       e.tirer_balle();

       if (collision(e,P))
           t=false;

        switch(keyboard()) {

        case KEY_RIGHT:
            P.bouge(droite,b);
            break;
        case KEY_DOWN:
            P.bouge(bottom,b);
            break;
        case KEY_LEFT:
            P.bouge(gauche,b);
            break;
        case KEY_UP:
            P.bouge(up,b);
            break;
        }

        int x,y;
        if (mouse(x,y)==1){
            cout << "souris" << endl;
            point objectif_perso = {x,y};
            P.initBalle(objectif_perso);
        }

        P.tirer_balle();

        milliSleep(5);

        }while(t);

}





int main(){

    srand( (unsigned)time( NULL ) );
    openComplexWindow(500,500);
    jeu(500,500);

    endGraphics();

    return 0;

}
