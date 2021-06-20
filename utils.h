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
    bool operator==(point b) const;
    int euler_dist(point b) const;

};

int keyboard();
