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
    drawRect(0,0,xb,yb,BLACK);
}

Bords::Bords(int x,int y){
    xb=x;
    yb=y;
}


// Fonctions diverses

int keyboard() {
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
    } while (e.type!=EVT_NONE);
    return 0;
}


// Celle là qui ne fonctionne pas
// On ne rentre jamais dans le if que j'ai commente
// Je ne sais pas si ça vient de ma souris

int mouse(int &x, int &y){
    //cout << "souris_0" << endl;
    Event e;
    do {
        getEvent(0,e);
        if (e.type==2){ // C'est dans ce if qu'on ne rentre pas
            cout << "souris_1" << endl;
            x = e.pix[0];
            y = e.pix[1];
            return e.button;
        }
    }while (e.type!=EVT_NONE);
    return 0;
}



float random_perso(){

        return (float) rand()/RAND_MAX;
}

