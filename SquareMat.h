#pragma once
#include <iostream>

namespace matlib {

    class SquareMat {
    private:
        int size;       // גודל המטריצה (n x n)
        double** data;  // מערך דו-ממדי (בהמשך נבנה דינאמית)

    public:
        // בונים
        SquareMat(int size);
        SquareMat(const SquareMat& other); // copy constructor
        SquareMat& operator=(const SquareMat& other); // copy assignment
        ~SquareMat(); // destructor

        // פונקציות עזר
        void print() const;

        // אופרטור פלט
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat& other) const;
        SquareMat operator*(double num) const;
        friend SquareMat operator*(double num, const SquareMat& mat);
        SquareMat operator%(const SquareMat& other) const;
        SquareMat operator%(int num) const;
        SquareMat operator/(double num) const;
        SquareMat operator^(int power) const;
        // Pre-increment
        SquareMat& operator++();
        SquareMat& operator--();

        // Post-increment
        SquareMat operator++(int);
        SquareMat operator--(int);


    };
}
