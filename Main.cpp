#include "SquareMat.h"
#include <iostream>
using namespace matlib;

int main() {
    SquareMat m1(2);
    SquareMat m2(2);

    // Initialize m1 and m2 with some values
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;

    m2[0][0] = 5; m2[0][1] = 6;
    m2[1][0] = 7; m2[1][1] = 8;

    std::cout << "m1:\n" << m1;
    std::cout << "m2:\n" << m2;

    std::cout << "m1 + m2:\n" << (m1 + m2);
    std::cout << "m1 - m2:\n" << (m1 - m2);
    std::cout << "-m1:\n" << (-m1);
    std::cout << "m1 * m2:\n" << (m1 * m2);
    std::cout << "m1 * 2:\n" << (m1 * 2);
    std::cout << "2 * m1:\n" << (2 * m1);
    std::cout << "m1 % m2 (element-wise multiply):\n" << (m1 % m2);
    std::cout << "m1 % 3 (modulo):\n" << (m1 % 3);
    std::cout << "m1 / 2:\n" << (m1 / 2);
    std::cout << "m1 ^ 2:\n" << (m1 ^ 2);
    std::cout << "Transpose of m1 (~m1):\n" << (~m1);
    std::cout << "Determinant of m1 (!m1):\n" << !m1 << "\n";

    std::cout << "m1 == m2: " << (m1 == m2) << "\n";
    std::cout << "m1 != m2: " << (m1 != m2) << "\n";
    std::cout << "m1 > m2: " << (m1 > m2) << "\n";
    std::cout << "m1 >= m2: " << (m1 >= m2) << "\n";
    std::cout << "m1 < m2: " << (m1 < m2) << "\n";
    std::cout << "m1 <= m2: " << (m1 <= m2) << "\n";

    ++m1;
    std::cout << "After ++m1:\n" << m1;
    m1++;
    std::cout << "After m1++:\n" << m1;
    --m1;
    std::cout << "After --m1:\n" << m1;
    m1--;
    std::cout << "After m1--:\n" << m1;

    m1 += m2;
    std::cout << "After m1 += m2:\n" << m1;
    m1 -= m2;
    std::cout << "After m1 -= m2:\n" << m1;
    m1 *= 2;
    std::cout << "After m1 *= 2:\n" << m1;
    m1 /= 2;
    std::cout << "After m1 /= 2:\n" << m1;
    m1 *= m2;
    std::cout << "After m1 *= m2:\n" << m1;
    m1 %= m2;
    std::cout << "After m1 %= m2:\n" << m1;
    m1 %= 3;
    std::cout << "After m1 %= 3:\n" << m1;

    //determinant of a 3x3 matrix
    SquareMat m3(3);
    m3[0][0] = 6; m3[0][1] = 1; m3[0][2] = 1;
    m3[1][0] = 4; m3[1][1] = -2; m3[1][2] = 5;
    m3[2][0] = 2; m3[2][1] = 8; m3[2][2] = 7;

    std::cout << "\nm3 (3x3 matrix):\n" << m3;
    std::cout << "Determinant of m3 (!m3): " << !m3 << "\n";

    // usage of getSize() - det should be 0
    SquareMat m4(3);
    int counter = 1;
    for (int i = 0; i < m4.getSize(); ++i) {
        for (int j = 0; j < m4.getSize(); ++j) {
            m4[i][j] = counter++;
        }
    }

    std::cout << "\nm4 (3x3 filled with getSize loop):\n" << m4;
    std::cout << "Determinant of m4: " << !m4 << "\n";



    return 0;
}