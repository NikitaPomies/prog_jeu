
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
    int dist=e.B.rayon+p.rayon;
    return p.c.euler_dist(e.B.position)<=dist;
}





void jeu(int w, int h){

    Bords b(w,h);
    Perso p(50,50,10,6);
    Enm_imb e(b,5,3,2,1);
    e.Dessine_enn(BLACK);
    e.init_balle(p);
    b.Dessine_bords();
    p.Dessine_perso(BLACK);
    click();

    cout<<"oui"<<endl;

    bool t=true;

    do {

       if (e.B.position.y==0 || e.B.position.y==h || e.B.position.x==0 || e.B.position.x==w )
          e.init_balle(p);
       e.tirer_balle();
       if (collision(e,p))
           t=false;

        switch(keyboard()) {

        case KEY_RIGHT:
            p.bouge(droite,b);
            break;
        case KEY_DOWN:
            p.bouge(bottom,b);
            break;
        case KEY_LEFT:
            p.bouge(gauche,b);
            break;
        case KEY_UP:
            p.bouge(up,b);
            break;
        }

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
