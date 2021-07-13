#include "utils.h"
#include "perso.h"
#include "ennemis.h"
#include "bonus.h"


// Fonctions principales


///////////////////////////////////////////////////////////////////


void init_affichage_niveau(int menu, int taille, int niveau){
    string niv = to_string(niveau);
    drawString(taille-taille/5,menu/2+10,"NIV. " + niv,BLACK,20);
}


void jeu(int taille, int menu){

    int niveau = 0;

    // Bords du terrain
    Bords b(taille,taille,menu);
    b.Dessine_bords();
    drawRect(0,0,taille,menu,BLACK,5);

    // Creation du menu et des trois types de bonus
    // il n'y a en permanence qu'un seul bonus actif a l'ecran que le joeur peut aller recuperer

    int nombre_bonus[3] = {0,0,0};  // compte le nombre de bonus que possède le joueur
    bool absent = true;             // dit si un bonus est present sur le terrain de jeu
    point bonus;                    // position du bonus
    int id_bonus;                   // indice du bonus en cours, pour indiquer son type
    time_t t_bouclier;              // instant d'initialisation du bouclier

    time_t temps_ini_bonus = time(NULL);    // instant d'apparition du bonus en cours
    init_menu_bonus(0,menu,taille);         // initialisation de l'affichage
    init_menu_bonus(1,menu,taille);
    init_menu_bonus(2,menu,taille);
    init_affichage_niveau(menu,taille,niveau+1);

    // Creation du personnage associe au joueur
    point posi_ini_perso = {b.xb/2,b.yb/2+menu};
    int sante_initiale = 100;
    int attaque_balle = 20;
    Perso P(posi_ini_perso,taille/30,6,2,10,sante_initiale,attaque_balle);
    P.Dessine_perso(BLACK);
    P.initBalle({0,0});
    P.init_vie(menu);

    click();

    time_t temps_ini_niv = time(NULL);

    bool t=true;



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
        while(difftime(time(NULL),temps_ini_niv)<= temps_niveau && t ){

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
                    position_aleatoire(taille,taille,espace_apparition,menu,taille/60,placement);
                    if(nmbr_ennemis>0){
                        for(int i=0;i<nmbr_ennemis;i++)
                            occupe = collision(Liste_ennemis[i].pos_ennemi,Liste_ennemis[i].rayon,placement,5);
                    }
                }while(occupe);

                // Creation et affichage du  nouvel ennemi puis insertion dans le vecteur d'ennemi
                Enm_imb e(nmbr_ennemis,placement,taille/60,3,2,3,vie_ennemi,attaque_ennemi_dist,PINK);
                e.Dessine_enn();
                e.init_vie();
                e.init_balle(P.position);
                Liste_ennemis.push_back(e);
                nmbr_ennemis+=1;

            }



            // Boucle sur tous les ennemis vivants
            for(int i=0; i<int(Liste_ennemis.size());i++){

                // On deplace les balles des ennemis
                Liste_ennemis[i].tirer_balle();

                // Ils tirent si leur balle est sortie
                if(Liste_ennemis[i].balle.balle_sortie(taille,taille,menu))
                    Liste_ennemis[i].init_balle(P.position);

                // Le joueur meurt ou perd des vies s'il est touche par la balle d'un des ennemis
                // Il ne perd pas de vie si son bouclier est active
                if (Liste_ennemis[i].balle.existe && collision(Liste_ennemis[i].balle.position,Liste_ennemis[i].rayon_balle,P.position,P.rayon)){
                    if(Liste_ennemis[i].dommages>=P.vie && !P.bouclier){
                        cout<<"mort"<<endl;
                        t=false;
                    }
                    if(P.bouclier){
                        Liste_ennemis[i].balle.meurt();
                        P.Dessine_perso(BLACK);
                    }
                    else {
                        P.dessine_vie_perdue(Liste_ennemis[i].dommages,menu);
                        P.vie-=Liste_ennemis[i].dommages;
                        Liste_ennemis[i].balle.meurt();
                        Liste_ennemis[i].init_balle(P.position);
                        P.Dessine_perso(BLACK);
                    }
                }

                // Un ennemi perd des vies ou meurt s'il est touche par une balle du joueur
                if(P.balle.existe && t && collision(P.balle.position,P.rayon_balle,Liste_ennemis[i].pos_ennemi,Liste_ennemis[i].rayon)){
                    P.balle.meurt();
                    if(P.puissance_balle>=Liste_ennemis[i].vie){

                        Liste_ennemis[i].efface_enn();
                        Liste_ennemis[i].efface_barre_vie();
                        Liste_ennemis[i].balle.efface();

                        nmbr_ennemis-=1;
                        Liste_ennemis.erase(Liste_ennemis.begin()+i);

                    }

                    else {
                        Liste_ennemis[i].dessine_vie(P.puissance_balle);
                        Liste_ennemis[i].vie-=P.puissance_balle;
                          }

                }
            }


            // Gestion des bonus
            if((difftime(time(NULL),temps_ini_bonus)>= temps_bonus || absent) && t){
                temps_ini_bonus = time(NULL);

                // Creation du nouveau bonus, qui ne doit pas se superposer a un ennemi
                bool occupe = false;
                do{
                    occupe = false;
                    position_aleatoire(taille,taille,taille/2,menu,taille/60,bonus);
                    if(nmbr_ennemis>0){
                        for(int i=0;i<nmbr_ennemis;i++)
                            occupe = collision(Liste_ennemis[i].pos_ennemi,Liste_ennemis[i].rayon,bonus,taille_bonus);
                    }
                }while(occupe);
                int id = rand()%3;

                // Remplacement de l'ancien bonus par le nouveau
                if(!absent)
                    efface_bonus(bonus);
                id_bonus=id ;
                absent = false;
                affichage_bonus(id_bonus,bonus);
            }

            // Le joueur peut ramasser un bonus
            if(collision(P.position,P.rayon,bonus,taille_bonus)){
                recup_bonus(id_bonus,nombre_bonus,menu,taille);
                absent = true;
                efface_bonus(bonus);
                P.Dessine_perso(BLACK);
            }

            // Desactivation du bouclier si le temps est depasse
            if(difftime(time(NULL),t_bouclier)>=temps_bouclier)
                P.bouclier=false;


            // Choix du joueur
            int x,y;

            switch(evenement(x,y)) {
            // Deplacement joueur
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
            // Utilisation bonus joueur
            case 32:
                if(nombre_bonus[0]>0){
                    P.dessine_vie_gagnee(bonus_vie,menu);
                    utilise_bonus(0,nombre_bonus,menu,taille);
                }
                break;
            case 16777220:
                if(nombre_bonus[1]>0){
                    P.bouclier = true;
                    P.Dessine_perso(BLACK);
                    t_bouclier = time(NULL);
                    utilise_bonus(1,nombre_bonus,menu,taille);
                }
                break;
            case 16777248:
                if(nombre_bonus[2]>0 && nmbr_ennemis>0){
                    nmbr_ennemis-=1;
                    Liste_ennemis[0].efface_enn();
                    Liste_ennemis[0].efface_barre_vie();
                    Liste_ennemis[0].balle.efface();
                    Liste_ennemis.erase(Liste_ennemis.begin());
                    utilise_bonus(2,nombre_bonus,menu,taille);
                }
                break;
            // Tir du joueur
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
}



// Fonction qui lance le jeu

int main(){

    srand( (unsigned)time( NULL ) );
    openComplexWindow(COTE_TERRAIN,COTE_TERRAIN+barre_menu);

    jeu(COTE_TERRAIN,barre_menu);

    endGraphics();

    return 0;

}
