#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"
#include <stdexcept>

using namespace matlib;

TEST_CASE("Constructor behavior") {
    SUBCASE("Non-positive size throws") {
        CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
        CHECK_THROWS_AS(SquareMat(-3), std::invalid_argument);
    }
    SUBCASE("Valid size initializes to zeros") {
        SquareMat m(2);
        CHECK(m.getSize() == 2);
        CHECK(m[0][0] == 0.0);
        CHECK(m[0][1] == 0.0);
        CHECK(m[1][0] == 0.0);
        CHECK(m[1][1] == 0.0);
    }
    SUBCASE("Larger size initializes correctly") {
        SquareMat m(3);
        CHECK(m.getSize() == 3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                CHECK(m[i][j] == 0.0);
            }
        }
    }
}

TEST_CASE("Modulo by zero throws") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;
    CHECK_THROWS_AS(m % 0, std::invalid_argument);
    CHECK_THROWS_AS(m %= 0, std::invalid_argument);
}

TEST_CASE("Division by zero throws") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;
    CHECK_THROWS_AS(m / 0, std::invalid_argument);
    CHECK_THROWS_AS(m /= 0, std::invalid_argument);
}

TEST_CASE("Accessing out-of-range row throws") {
    SquareMat m(2);
    CHECK_THROWS_AS(m[-1], std::out_of_range);
    CHECK_THROWS_AS(m[2], std::out_of_range);

    const SquareMat cm(2);
    CHECK_THROWS_AS(cm[-1], std::out_of_range);
    CHECK_THROWS_AS(cm[2], std::out_of_range);
}
TEST_CASE("Accessing out-of-range column throws") {
    SquareMat m(2);

    CHECK_THROWS_AS(m[0][-1], std::out_of_range);
    CHECK_THROWS_AS(m[0][2], std::out_of_range);

    const SquareMat cm(2);
    CHECK_THROWS_AS(cm[0][-1], std::out_of_range);
    CHECK_THROWS_AS(cm[0][2], std::out_of_range);
}

TEST_CASE("Operations on matrices of different sizes throw") {
    SquareMat a(2);
    SquareMat b(3);

    CHECK_THROWS_AS(a + b, std::invalid_argument);
    CHECK_THROWS_AS(a - b, std::invalid_argument);
    CHECK_THROWS_AS(a * b, std::invalid_argument);
    CHECK_THROWS_AS(a % b, std::invalid_argument);
    CHECK_THROWS_AS(a += b, std::invalid_argument);
    CHECK_THROWS_AS(a -= b, std::invalid_argument);
    CHECK_THROWS_AS(a *= b, std::invalid_argument);
    CHECK_THROWS_AS(a %= b, std::invalid_argument);
}

TEST_CASE("Addition and Subtraction Operators") {
    SUBCASE("2x2 matrices") {
        SquareMat a(2), b(2);
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;
        b[0][0] = 5; b[0][1] = 6;
        b[1][0] = 7; b[1][1] = 8;

        SquareMat sum = a + b;
        CHECK(sum[0][0] == 6);
        CHECK(sum[1][1] == 12);

        SquareMat diff = a - b;
        CHECK(diff[0][0] == -4);
        CHECK(diff[1][1] == -4);
    }
    SUBCASE("3x3 matrices") {
        SquareMat a(3), b(3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                a[i][j] = i + j + 1;
                b[i][j] = (i + j + 1) * 2;
            }
        }
        SquareMat sum = a + b;
        CHECK(sum[0][0] == 3); // 1 + 2
        CHECK(sum[2][2] == 15); // 5 + 10

        SquareMat diff = a - b;
        CHECK(diff[0][0] == -1); // 1 - 2
        CHECK(diff[2][2] == -5); // 5 - 10
    }
}

TEST_CASE("Unary minus") {
    SquareMat a(2);
    a[0][0] = 1; a[1][1] = -2;
    SquareMat neg = -a;
    CHECK(neg[0][0] == -1);
    CHECK(neg[1][1] == 2);
}

TEST_CASE("Multiplication") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 2; b[1][0] = 1;
    b[0][1] = 0; b[1][1] = 2;

    SquareMat c = a * b;
    CHECK(c[0][0] == 4);
    CHECK(c[0][1] == 4);
    CHECK(c[1][0] == 10);
    CHECK(c[1][1] == 8);
}

TEST_CASE("Scalar Multiplication and Division") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    SUBCASE("Matrix times scalar") {
        SquareMat mult = a * 2;
        CHECK(mult[0][0] == 2);
        CHECK(mult[0][1] == 4);
        CHECK(mult[1][0] == 6);
        CHECK(mult[1][1] == 8);
    }
    SUBCASE("Scalar times matrix") {
        SquareMat mult = 2 * a;
        CHECK(mult[0][0] == 2);
        CHECK(mult[0][1] == 4);
        CHECK(mult[1][0] == 6);
        CHECK(mult[1][1] == 8);
    }
    SUBCASE("Scalar division") {
        SquareMat div = a / 2;
        CHECK(div[0][0] == 0.5);
        CHECK(div[0][1] == 1.0);
        CHECK(div[1][0] == 1.5);
        CHECK(div[1][1] == 2.0);
    }
}

TEST_CASE("Power operator") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 1;

    SquareMat p = a ^ 2;
    CHECK(p[0][0] == 2);
    CHECK(p[1][1] == 2);
}
TEST_CASE("Power operator edge cases") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 1;
    m[1][0] = 1; m[1][1] = 1;
    SUBCASE("Zero exponent") {
        SquareMat result = m ^ 0;
        CHECK(result[0][0] == 1);
        CHECK(result[0][1] == 0);
        CHECK(result[1][0] == 0);
        CHECK(result[1][1] == 1);
    }
    SUBCASE("Negative exponent") {
        CHECK_THROWS_AS(m ^ -1, std::invalid_argument);
    }
}

TEST_CASE("Transpose operator") {
    SquareMat a(2);
    a[0][1] = 5;
    SquareMat t = ~a;
    CHECK(t[1][0] == 5);
}

TEST_CASE("Comparison operators") {
    SUBCASE("Same size matrices") {
        SquareMat a(2), b(2);
        a[0][0] = 1; b[0][0] = 2;

        CHECK(a != b);
        CHECK(b > a);
        CHECK(b >= a);
        CHECK(!(a > b));
        CHECK(!(a >= b));
        CHECK(a <= b);
    }
    SUBCASE("Equal sums different layout") {
        SquareMat a(2), b(2);
        a[0][0] = 5; a[0][1] = 0;
        a[1][0] = 0; a[1][1] = 0;
        b[0][0] = 0; b[0][1] = 0;
        b[1][0] = 0; b[1][1] = 5;
        CHECK(a == b);
    }
    SUBCASE("Different size matrices") {
        SquareMat a(2), b(3);
        a[0][0] = 1; b[0][0] = 1;
        CHECK(a == b); // Both sum to 1
        b[0][1] = 1;
        CHECK(a < b); // a.sum() = 1, b.sum() = 2
        CHECK(a <= b);
        CHECK(b > a);
        CHECK(b >= a);
        CHECK(a != b);
    }
}

TEST_CASE("Determinant operator for different sizes") {
    SUBCASE("1x1 matrix") {
        SquareMat m(1);
        m[0][0] = 5;
        CHECK(!m == 5);
    }
    SUBCASE("2x2 matrix") {
        SquareMat m(2);
        m[0][0] = 1; m[0][1] = 2;
        m[1][0] = 3; m[1][1] = 4;
        CHECK(!m == -2);
    }
    SUBCASE("3x3 matrix") {
        SquareMat m(3);
        m[0][0] = 6; m[0][1] = 1; m[0][2] = 1;
        m[1][0] = 4; m[1][1] = -2; m[1][2] = 5;
        m[2][0] = 2; m[2][1] = 8; m[2][2] = 7;
        CHECK(!m == -306);
    }
    SUBCASE("3x3 singular matrix") {
        SquareMat m(3);
        m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
        m[1][0] = 4; m[1][1] = 5; m[1][2] = 6;
        m[2][0] = 7; m[2][1] = 8; m[2][2] = 9;
        CHECK(!m == 0);
    }
}

TEST_CASE("Increment and Decrement Operators") {
    SquareMat a(2);
    a[0][0] = 1;

    SUBCASE("Pre-increment") {
        SquareMat result = ++a;
        CHECK(a[0][0] == 2);
        CHECK(result[0][0] == 2);
    }
    SUBCASE("Post-increment") {
        SquareMat result = a++;
        CHECK(a[0][0] == 2);
        CHECK(result[0][0] == 1);
    }
    SUBCASE("Pre-decrement") {
        a[0][0] = 3;
        SquareMat result = --a;
        CHECK(a[0][0] == 2);
        CHECK(result[0][0] == 2);
    }
    SUBCASE("Post-decrement") {
        a[0][0] = 3;
        SquareMat result = a--;
        CHECK(a[0][0] == 2);
        CHECK(result[0][0] == 3);
    }
}

TEST_CASE("Compound assignment operators") {
    SquareMat a(2), b(2);
    a[0][0] = 2; b[0][0] = 3;
    a += b; CHECK(a[0][0] == 5);
    a -= b; CHECK(a[0][0] == 2);
    a *= 2; CHECK(a[0][0] == 4);
    a /= 2; CHECK(a[0][0] == 2);
    a %= 3; CHECK(a[0][0] == 2);
    a %= b; CHECK(a[0][0] == 6);
}
TEST_CASE("getSize returns correct matrix size") {
    SquareMat mat(4);
    CHECK(mat.getSize() == 4);
}
TEST_CASE("Copy constructor creates independent copy") {
    SquareMat a(2);
    a[0][0] = 42;
    SquareMat b(a);
    CHECK(b[0][0] == 42);
    a[0][0] = 99;
    CHECK(b[0][0] == 42); // Verify deep copy
}

TEST_CASE("Assignment operator creates independent copy") {
    SquareMat a(2);
    a[0][0] = 10; a[1][1] = 20;
    SquareMat b(3); // Different size initially
    b = a;
    CHECK(b.getSize() == 2);
    CHECK(b[0][0] == 10);
    CHECK(b[1][1] == 20);
    a[0][0] = 99; // Modify original
    CHECK(b[0][0] == 10); // Verify deep copy
}
TEST_CASE("Output operator formats matrix correctly") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;
    std::ostringstream oss;
    oss << m;
    CHECK(oss.str() == "1 2 \n3 4 \n");
}
TEST_CASE("Element-wise multiplication") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;
    SquareMat result = a % b;
    CHECK(result[0][0] == 5);
    CHECK(result[0][1] == 12);
    CHECK(result[1][0] == 21);
    CHECK(result[1][1] == 32);
}
TEST_CASE("Scalar modulo operator") {
    SquareMat m(2);
    m[0][0] = 5; m[0][1] = 22.5;
    m[1][0] = 3; m[1][1] = 4;
    SUBCASE("Modulo with integer scalar") {
        SquareMat result = m % 3;
        CHECK(result[0][0] == 2);
        CHECK(result[1][0] == 0);
    }
    SUBCASE("Modulo with floating-point") {
        SquareMat result = m % 2;
        CHECK(result[0][1] == doctest::Approx(0.5));
    }
}
TEST_CASE("Compound matrix multiplication") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;
    a *= b;
    CHECK(a[0][0] == 19);
    CHECK(a[0][1] == 22);
    CHECK(a[1][0] == 43);
    CHECK(a[1][1] == 50);
}
TEST_CASE("Comparison operators with equal sums") {
    SquareMat a(2), b(2);
    a[0][0] = 5; a[0][1] = 0;
    a[1][0] = 0; a[1][1] = 0;
    b[0][0] = 0; b[0][1] = 0;
    b[1][0] = 0; b[1][1] = 5;
    CHECK(a == b);
}
TEST_CASE("Operations with 3x3 matrices") {
    SquareMat a(3), b(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = i + j + 1;
            b[i][j] = (i + j + 1) * 2;
        }
    }
    SquareMat sum = a + b;
    CHECK(sum[0][0] == 3);
    CHECK(sum[2][2] == 15);
    SquareMat prod = a * b;
    CHECK(prod[0][0] == 28);
}
TEST_CASE("Operations with zero and identity matrices") {
    SquareMat zero(2);
    SquareMat identity(2);
    identity[0][0] = 1; identity[1][1] = 1;
    SUBCASE("Zero matrix addition") {
        SquareMat a(2);
        a[0][0] = 1; a[1][1] = 2;
        SquareMat result = a + zero;
        CHECK(result[0][0] == 1);
        CHECK(result[1][1] == 2);
    }
    SUBCASE("Identity matrix multiplication") {
        SquareMat a(2);
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;
        SquareMat result = a * identity;
        CHECK(result[0][0] == 1);
        CHECK(result[0][1] == 2);
        CHECK(result[1][0] == 3);
        CHECK(result[1][1] == 4);
    }
}
TEST_CASE("Floating-point operations") {
    SquareMat a(2);
    a[0][0] = 1.1; a[0][1] = 2.2;
    a[1][0] = 3.3; a[1][1] = 4.4;
    SquareMat result = a / 2.0;
    CHECK(result[0][0] == doctest::Approx(0.55));
    CHECK(result[1][1] == doctest::Approx(2.2));
}
TEST_CASE("Const matrix read-only operations") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    const SquareMat m = a;

    SquareMat result = m * 2;
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 4);

    CHECK(!m == -2);
}

