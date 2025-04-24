#pragma once
#include <iostream>

namespace matlib {

    class SquareMat {
    private:
        int size;       // גודל המטריצה (n x n)
        double** data;  // מערך דו-ממדי (בהמשך נבנה דינאמית)

        //helper functions
        double sum() const;

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
        SquareMat operator~() const;
        double* operator[](int i);
        const double* operator[](int i) const;
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        double operator!() const;
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(double num);
        SquareMat& operator/=(double num);
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int num);






    };
}
