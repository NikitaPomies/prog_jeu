#include "utils.h"
#include "perso.h"
#include "ennemis.h"


// Constantes globales

const double temps_niveau = 120.0; // Donné en secondes
const double temps_ennemis = 5.0; // Donné en seconces




void jeu(int w, int h){

    int niveau = 0;

    Bords b(w,h);
    b.Dessine_bords();

    point posi_ini_perso = {200,50};
    Perso P(posi_ini_perso,10,6,2,3);
    P.Dessine_perso(BLACK);


    //nmbr_ennemis +=1;


    click();

    time_t temps_ini_niv = time(NULL);

    bool t=true;




        niveau+=1;
        int nmbr_ennemis = 0;
        std::vector<Enm_imb> Liste_ennemis;
        time_t nouvel_ennemi = time(NULL);

        while(difftime(time(NULL),temps_ini_niv)<= temps_niveau && t ){

            if (nmbr_ennemis==0 || difftime(time(NULL),nouvel_ennemi) >= temps_ennemis){

                if(difftime(time(NULL),nouvel_ennemi) >= temps_ennemis) {
                    nouvel_ennemi = time(NULL);

                    Enm_imb e(nmbr_ennemis,b,5,3,2,3,10,GREEN);
                    e.Dessine_enn();
                    e.init_balle(P.position);
                    e.tirer_balle();
                    Liste_ennemis.push_back(e);
                }

            }



            for(int i=0; i<int(Liste_ennemis.size());i++){

                if(Liste_ennemis[i].balle_sortie(w,h)) {

                    Liste_ennemis[i].init_balle(P.position);

                }

                if (collision(Liste_ennemis[i].balle.position,Liste_ennemis[i].rayon_balle,P.position,P.rayon)){

                    t=false;}

                Liste_ennemis[i].tirer_balle();
            }






            int x,y;

            switch(evenement(x,y)) {

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
            case 1:
                P.balle.efface();
                point objectif_perso = {x,y};
                P.initBalle(objectif_perso);
                break;

            }


            P.tirer_balle();

            milliSleep(5);

        }


}





int main(){

    srand( (unsigned)time( NULL ) );
    openComplexWindow(COTE_TERRAIN,COTE_TERRAIN);
    jeu(COTE_TERRAIN,COTE_TERRAIN);

    endGraphics();
//    time_t init= time(NULL);
//    while(difftime(time(NULL),init)<=temps_ennemis){
//        if (2==2) cout<<"test"<<endl;
//        cout<<"hors_if"<<endl;

//    }

    return 0;

}
