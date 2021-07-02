#include "utils.h"


// Structure point

point point::operator+(point b) const {
    point p = {x+b.x,y+b.y};
    return p;
}

point point::operator*(int lambda) const{
    point p = {lambda*x,lambda*y};
    return p;
}

bool point::operator==(point b) const{
    return ((x==b.x) && (y==b.y));
}
int point::euler_dist(point b) const{
    return int(sqrt((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y)));
}



// Classe bords

void Bords::Dessine_bords(){
    drawRect(0,menu,xb,yb,BLACK);
}

Bords::Bords(int x, int y, int taille_menu){
    xb=x;
    yb=y;
    menu=taille_menu;
}




// Fonctions diverses

int evenement(int &x, int &y){
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
        else if (e.type==EVT_BUT_ON){

            x = e.pix[0];
            y = e.pix[1];
            return e.button;
       }
    } while (e.type!=EVT_NONE);
    return 0;
}


float random_perso(){
        return (float) rand()/RAND_MAX;
}



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

bool collision(point A, int rayonA, point B, int rayonB){
    int dist=rayonA + rayonB;
    return A.euler_dist(B)<=dist;
}


