#include "utils.h"


point point::operator+(point b) const {
    point p = {x+b.x,y+b.y};
    return p;
}

bool point::operator==(point b) const{
    return ((x==b.x) && (y==b.y));
}
int point::euler_dist(point b) const{
    return int(sqrt((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y)));
}

void Bords::Dessine_bords(){

    drawRect(0,0,xb,yb,BLACK);

}
Bords::Bords(int x,int y){

    xb=x;
    yb=y;
}


int keyboard() {
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
    } while (e.type!=EVT_NONE);
    return 0;
}

