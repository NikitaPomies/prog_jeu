#include  "bonus.h"


// Pas de classe a ete cree a cause des trois differents types de bonus, que nous ne savions pas comment gere avec une classe

void init_menu_bonus(int id, int menu, int taille){
    fillCircle(taille/2+3*id*rayon_bonus,menu/3+10,rayon_bonus,BONUS_GRISEE[id]);
    drawCircle(taille/2+3*id*rayon_bonus,menu/3+10,rayon_bonus+3,BLACK,3);
    drawString(taille/2+3*id*rayon_bonus-10,menu/3+10+rayon_bonus+18,"x 0",BONUS_GRISEE[id],8);
}


void affichage_bonus(int id, point place){
    fillDiamond(place,taille_bonus,BONUS[id]);
}


void efface_bonus(point place){
    fillDiamond(place,taille_bonus,WHITE);
}


void recup_bonus(int id, int nombre [3], int menu, int taille){
    fillCircle(taille/2+3*id*rayon_bonus,menu/3+10,rayon_bonus-1,BONUS[id]);
    nombre [id] +=1;
    string nmbr = to_string(nombre[id]);
    fillRect(taille/2+3*id*rayon_bonus-10-10,menu/3+10+rayon_bonus+18-12,35,20,WHITE);
    drawString(taille/2+3*id*rayon_bonus-10,menu/3+10+rayon_bonus+18,"x " + nmbr,BONUS[id],8);
}

void utilise_bonus(int id, int nombre [], int menu, int taille){
    nombre [id] -=1;
    if(nombre[id]<=0){
        fillCircle(taille/2+3*id*rayon_bonus,menu/3+10,rayon_bonus,BONUS_GRISEE[id]);
        drawCircle(taille/2+3*id*rayon_bonus,menu/3+10,rayon_bonus+3,BLACK,3);
        drawString(taille/2+3*id*rayon_bonus-10,menu/3+10+rayon_bonus+18,"x 0",BONUS_GRISEE[id],8);
    }
    string nmbr = to_string(nombre[id]);
    fillRect(taille/2+3*id*rayon_bonus-10-10,menu/3+10+rayon_bonus+18-12,35,20,WHITE);
    drawString(taille/2+3*id*rayon_bonus-10,menu/3+10+rayon_bonus+18,"x " + nmbr,BONUS[id],8);
}
