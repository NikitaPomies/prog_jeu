#pragma once
#include "utils.h"

const Color BONUS_GRISEE [3] = {AlphaColor(98,95,127),AlphaColor(127,98,95),AlphaColor(95,127,98)};
const Color BONUS [3] = {AlphaColor(28,25,167),AlphaColor(167,28,25),AlphaColor(25,167,28)};

const int bonus_vie = 15;

const double temps_bonus = 20.0;
const int taille_bonus = 15;
const int rayon_bonus = COTE_TERRAIN/28;


void init_menu_bonus(int id, int menu, int taille);
void affichage_bonus(int id, point place);
void efface_bonus(point place);
void recup_bonus(int id, int nombre[], int menu, int taille);
void utilise_bonus(int id, int nombre[], int menu, int taille);


