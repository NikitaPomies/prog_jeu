 #include "utils.h"
#include "perso.h"
#include "ennemis.h"


// Constantes globales

const double temps_niveau = 120.0; // Donné en secondes
const double temps_ennemis = 15.0; // Donné en seconces
const int espace_apparition = COTE_TERRAIN/8;
const int barre_menu = 100;


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// PROBLEME :
// Le premier ennemi ne s'affiche pas, meme dans cette version ou on a ajoute un fillCricle a la main
// Lorsqu'on rentre pour la deuxieme fois dans la boucle while de la ligne 51, tout l'ecran devient bleu noir
// Cela se voit bien au debuggage
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void jeu(int taille, int menu){

    int niveau = 0;

    // Bords du terrain
    Bords b(taille,taille,menu);
    b.Dessine_bords();

    drawRect(0,0,taille,menu,BLACK,5);

    // Creation du personnage associe au joueur
    point posi_ini_perso = {b.xb/2,b.yb/2+menu};
    int sante_initiale = 100;
    int attaque_balle = 20;
    Perso P(posi_ini_perso,taille/30,6,2,10,sante_initiale,attaque_balle);
    P.Dessine_perso(BLACK);
    P.initBalle({0,0});
    P.init_vie();

    click();

    time_t temps_ini_niv = time(NULL);

    bool t=true;

    do {

        // On rentre dans un niveau
        // Il n'y a, au premier passage dans la boucle, aucun ennemi
        // On cree un vecteur qui va contenir tous les ennemis encore envie
        // Une variable de temps permet de controler la frequence d'apparition d'un nouvel ennemi
        niveau+=1;
        int nmbr_ennemis = 0;
        std::vector<Enm_imb> Liste_ennemis;
        time_t nouvel_ennemi = time(NULL);
        int vie_ennemi = 60;
        int attaque_ennemi_dist = 10;

        // On reste dans un meme niveau tant qu'un certain temps n'est pas ecoule
        while(difftime(time(NULL),temps_ini_niv)<= temps_niveau){

            // Creation d'un nouvel ennemi (il doit toujours y en avoir au moins un)
            if (nmbr_ennemis==0 || difftime(time(NULL),nouvel_ennemi) >= temps_ennemis){

                // On remet a jour la variable de temps si creation il y a
                if(difftime(time(NULL),nouvel_ennemi) >= temps_ennemis)
                    nouvel_ennemi = time(NULL);

                // Un nouvel ennemi ne doit pas se superposer aux autres
                point placement;
                bool occupe = false;
                do{
                    occupe = false;
                    position_aleatoire(taille,taille,espace_apparition,menu,placement);
                    if(nmbr_ennemis>0){
                        for(int i=0;i<nmbr_ennemis;i++)
                            occupe = collision(Liste_ennemis[i].pos_ennemi,Liste_ennemis[i].rayon,placement,5);
                    }
                }while(occupe);

                // Creation et affichage du  nouvel ennemi puis insertion dans le vecteur d'ennemi
                Enm_imb e(nmbr_ennemis,placement,taille/60,3,2,3,vie_ennemi,attaque_ennemi_dist,GREEN);
                e.Dessine_enn();
                e.init_vie();
                e.init_balle(P.position);
                Liste_ennemis.push_back(e);
                nmbr_ennemis+=1;

            }

            // Boucle sur tous les ennemis vivants
            for(int i=0; i<int(Liste_ennemis.size());i++){

                // Ils tirent si leur balle est sortie
                if(Liste_ennemis[i].balle.balle_sortie(taille,taille,menu))
                    Liste_ennemis[i].init_balle(P.position);

                // Le joueur meurt ou perd des vies s'il est touche par la balle d'un des ennemis
                if (Liste_ennemis[i].balle.existe && collision(Liste_ennemis[i].balle.position,Liste_ennemis[i].rayon_balle,P.position,P.rayon)){
                    if(Liste_ennemis[i].dommages>=P.vie)
                        t=false;
                    P.dessine_vie(Liste_ennemis[i].dommages);
                    P.vie-=Liste_ennemis[i].dommages;
                    cout << P.vie << endl;
                    Liste_ennemis[i].balle.meurt();
                    Liste_ennemis[i].init_balle(P.position);
                    P.Dessine_perso(BLACK);
                }

                // Un ennemi perd des vies ou meurt s'il est touche par une balle du joueur
                if(P.balle.existe && t && collision(P.balle.position,P.rayon_balle,Liste_ennemis[i].pos_ennemi,Liste_ennemis[i].rayon)){
                    P.balle.meurt();
                    if(P.puissance_balle>=Liste_ennemis[i].vie){


                        Liste_ennemis[i].efface_enn();
                        Liste_ennemis[i].efface_barre_vie();


                        nmbr_ennemis-=1;
                        Liste_ennemis.erase(Liste_ennemis.begin()+i);
                    }
                    else {
                        Liste_ennemis[i].dessine_vie(P.puissance_balle);
                        Liste_ennemis[i].vie-=P.puissance_balle;
                          }

                }

                // On deplace les balles des ennemis
                Liste_ennemis[i].tirer_balle();
            }


            // Deplacement du joueur
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

            if(P.balle.balle_sortie(taille,taille,menu))
                P.balle.meurt();

            P.tirer_balle();

            milliSleep(5);

        }

    }while(t);


}





int main(){

    srand( (unsigned)time( NULL ) );
    openComplexWindow(COTE_TERRAIN,COTE_TERRAIN+barre_menu);
    jeu(COTE_TERRAIN,barre_menu);

    endGraphics();

    return 0;

}
