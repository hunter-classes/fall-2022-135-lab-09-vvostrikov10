#include <iostream>


#include "funcs.h"
#include "coord3d.h"

int main() {
    double x, y, z;
    std::cout << "Enter position: ";
    std::cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    std::cout << "Enter velocity: ";
    std::cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    std::cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}
