#include <Imagine/Images.h>

using namespace Imagine;
using namespace std;




int Clavier() {
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
    int xc,yc;
    int rayon;
    void Dessine_perso();

};

void Perso::Dessine_perso(){

    fillCircle(xc,yc,rayon,RED);
}




class Bords{
public:
    int xb,yb;
    void Dessine_bords();



        };

void Bords::Dessine_bords(){

    drawRect(0,0,xb,yb,BLACK);

}



int main(){



    return 0;

}
