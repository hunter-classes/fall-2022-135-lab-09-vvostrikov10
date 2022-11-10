#include <iostream>
#include "funcs.h"
#include "coord3d.h"
#include <cmath>

double length(Coord3D *p){
    double ans = 0;
    ans += (p->x)*(p->x); 
    ans += (p->y)*(p->y); 
    ans += (p->z)*(p->z);
    return sqrt(ans);
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    return length(p1) >= length(p2) ? p1 : p2;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x += pvel->x * dt;
    ppos->y += pvel->y * dt;
    ppos->z += pvel->z * dt;
}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *pointer = new Coord3D();
    pointer->x = x;
    pointer->y = y;
    pointer->z = z;
    return pointer;
}

void deleteCoord3D(Coord3D *p){
    delete p;
}
// add functions here

