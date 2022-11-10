#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "coord3d.h"
#include <cmath>

// add your tests here
TEST_CASE("<createCoord3D tests>"){
    Coord3D *p = createCoord3D(0, 1, 2);
    CHECK(p -> x == 0);
    CHECK(p -> y == 1);
    CHECK(p -> z == 2);
    deleteCoord3D(p);
    p = createCoord3D(3.1, -4.2, 5.3);
    CHECK(p -> x == 3.1);
    CHECK(p -> y == -4.2);
    CHECK(p -> z == 5.3);
    deleteCoord3D(p);
}

TEST_CASE("<length tests>"){
    Coord3D *p = createCoord3D(2, 7, 26);
    CHECK(length(p) == 27);
    deleteCoord3D(p);
    p = createCoord3D(5, 6, 7);
    CHECK(abs(length(p) - 10.4880884817) < 0.001);
    deleteCoord3D(p);
    p = createCoord3D(-5, 7, -6);
    CHECK(abs(length(p) - 10.4880884817) < 0.001);
    deleteCoord3D(p);
    p = createCoord3D(0, 1, -1);
    CHECK(length(p) == sqrt(2));
    deleteCoord3D(p);
}

TEST_CASE("<fartherFromOrigin tests>"){
    Coord3D *p = createCoord3D(2, 7, 26);
    Coord3D *q = createCoord3D(2, 8, 26);
    CHECK(fartherFromOrigin(p, q) == q);
    deleteCoord3D(p);
    p = createCoord3D(-3.5, 8, 26);
    CHECK(fartherFromOrigin(p, q) == p);
    deleteCoord3D(p);
    deleteCoord3D(q);
    p = createCoord3D(1, 1.5, 1);
    q = createCoord3D(1, -1.5, 1);
    CHECK(fartherFromOrigin(p, q) == p);
    deleteCoord3D(p);
    deleteCoord3D(q);
}

TEST_CASE("<move tests>"){
    Coord3D *p = createCoord3D(2, 7, 26);
    Coord3D *v = createCoord3D(1, -1.0, 3.5);
    move(p, v, 10);
    CHECK(p -> x == 12);
    CHECK(p -> y == -3);
    CHECK(p -> z == 61);
    move(p, v, -5);
    CHECK(p -> x == 7);
    CHECK(p -> y == 2);
    CHECK(p -> z == 43.5);

    delete(p);
    delete(v);
}
