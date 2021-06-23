#include <Imagine/Images.h>
#pragma once
#include <math.h>
#include <ctime>
#include <time.h>
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
    point operator*(int lambda) const;
    bool operator==(point b) const;
    int euler_dist(point b) const;

};

const point dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

class Bords{
public:
    int xb,yb;
    void Dessine_bords();
    Bords(int xb,int yb);
        };



int keyboard();
float random_perso();
