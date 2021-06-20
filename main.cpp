
#include "utils.h"



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

const point dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};


class Bords{
public:
    int xb,yb;
    void Dessine_bords();
    Bords(int xb,int yb);



        };

void Bords::Dessine_bords(){

    drawRect(0,0,xb,yb,BLACK);

}
Bords::Bords(int x,int y){

    xb=x;
    yb=y;
}



class Perso{
public:
    int  vitesse;
    point c;
    int rayon;
    Perso(int xc,int yc, int rayon, int v);
    void Dessine_perso(Color col);
    void bouge(int d, const Bords& b);

};

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



void jeu(int w, int h){
    Bords b(w,h);
    Perso p(50,50,10,6);
    b.Dessine_bords();
    p.Dessine_perso(BLACK);
    click();
    cout<<"oui"<<endl;

    do {
        switch(keyboard()) {
        case KEY_RIGHT:
                 p.bouge(droite,b); break;
        case KEY_DOWN:
            p.bouge(bottom,b); break;
        case KEY_LEFT:
           p.bouge(gauche,b); break;
        case KEY_UP:
            p.bouge(up,b); break;
        }
        milliSleep(10);

        }while(true);




}




int main(){

    openComplexWindow(300,300);
    //fillCircle(10,10,20,RED);
    jeu(200,200);



    endGraphics();



    return 0;

}
