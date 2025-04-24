#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"
using namespace matlib;

TEST_CASE("Matrix addition") {
    SquareMat m1(2), m2(2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 4; m2[0][1] = 3;
    m2[1][0] = 2; m2[1][1] = 1;

    SquareMat result = m1 + m2;
    CHECK(result[0][0] == 5);
    CHECK(result[1][1] == 5);
}

TEST_CASE("Matrix multiplication") {
    SquareMat m1(2), m2(2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 2; m2[0][1] = 0;
    m2[1][0] = 1; m2[1][1] = 2;

    SquareMat result = m1 * m2;
    CHECK(result[0][0] == 4);
    CHECK(result[1][1] == 8);
}

TEST_CASE("Scalar division") {
    SquareMat m(2);
    m[0][0] = 4; m[0][1] = 6;
    m[1][0] = 8; m[1][1] = 2;

    SquareMat result = m / 2;
    CHECK(result[0][0] == 2);
    CHECK(result[1][1] == 1);
}

TEST_CASE("Matrix transpose") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    SquareMat t = ~m;
    CHECK(t[0][1] == 3);
    CHECK(t[1][0] == 2);
}

TEST_CASE("Matrix determinant") {
    SquareMat m(2);
    m[0][0] = 4; m[0][1] = 6;
    m[1][0] = 3; m[1][1] = 8;

    CHECK((int)!m == 14);
}

TEST_CASE("Matrix equality") {
    SquareMat m1(2), m2(2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 4; m2[0][1] = 3;
    m2[1][0] = 2; m2[1][1] = 1;

    CHECK((m1 == m2) == true);
}
