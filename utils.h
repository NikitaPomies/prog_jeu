#include <Imagine/Images.h>
#pragma once
#include <math.h>
#include <iostream>
#include <ctime>
#include <time.h>
using namespace Imagine;
using namespace std;
#include <vector>

const int droite = 0;
const int bottom = 1;
const int gauche = 2;
const int up = 3;


// Constantes globales

const int COTE_TERRAIN = 700;
const double temps_niveau = 120.0; // Donné en secondes
const double temps_ennemis = 15.0; // Donné en seconces
const int espace_apparition = COTE_TERRAIN/8;
const int barre_menu = 100;

const Color PINK = AlphaColor(243,23,255);

struct point {

    int x;
    int y;

    point operator+(point b) const;
    point operator*(int lambda) const;
    bool operator==(point b) const;
    int euler_dist(point b) const;

};

const point dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};



class Bords{

public:

    int menu;
    int xb,yb;
    void Dessine_bords();
    Bords(int xb,int yb,int taille_menu);

};


int evenement(int &x, int &y);
float random_perso();
void fillDiamond(point P, int size, Color COL);
void fillTriangle(point P, int size, Color COL);
bool collision(point A, int rayonA, point B, int rayonB);
