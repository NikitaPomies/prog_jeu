#include <Imagine/Images.h>

using namespace Imagine;
using namespace std;

const int droite = 0;
const int bottom = 1;
const int gauche = 2;
const int up = 3;


struct point {
    int x;
    int y;
    point operator+(point b) const;

};

point point::operator+(point b) const {
    point p = {x+b.x,y+b.y};
    return p;
}
const point dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};




int keyboard() {
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
    } while (e.type!=EVT_NONE);
    return 0;
}

class Perso{
public:

    point c;
    int rayon;
    Perso(int xc,int yc, int rayon);
    void Dessine_perso(Color col);
    void bouge(int d);

};

void Perso::Dessine_perso(Color col){


    fillCircle(c.x,c.y,rayon,col);

}

Perso::Perso(int x,int y,int r){
    c.x=x;
    c.y=y;
    rayon=r;




}






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

void Perso::bouge(int d){
    Dessine_perso(WHITE);

    c=c+dir[d];
    Dessine_perso(RED);
}



void jeu(int w, int h){
    Bords b(w,h);
    Perso p(50,50,10);
    b.Dessine_bords();
    p.Dessine_perso(BLACK);
    click();
    cout<<"oui"<<endl;

    do {
        switch(keyboard()) {
        case KEY_RIGHT:
                 p.bouge(droite); break;
        case KEY_DOWN:
            p.bouge(bottom); break;
        case KEY_LEFT:
           p.bouge(gauche); break;
        case KEY_UP:
            p.bouge(up); break;
        }
        milliSleep(5);

        }while(true);




}




int main(){

    openComplexWindow(300,300);
    //fillCircle(10,10,20,RED);
    jeu(200,200);



    endGraphics();



    return 0;

}
