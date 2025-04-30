/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#pragma once
#include <iostream>

namespace matlib {

    class SquareMat {
    private:
        int size;       // גודל המטריצה (n x n)
        double** data;  // מערך דו-ממדי (בהמשך נבנה דינאמית)

        //helper functions
        double sum() const;


        class RowProxy {
        public:
            RowProxy(double* row, int size) : row_(row), size_(size) {}

            double& operator[](int col) {
                if (col < 0 || col >= size_)
                    throw std::out_of_range("Column index out of range");
                return row_[col];
            }

            const double& operator[](int col) const {
                if (col < 0 || col >= size_)
                    throw std::out_of_range("Column index out of range");
                return row_[col];
            }

        private:
            double* row_;
            int size_;
        };

    public:

        // בונים
        SquareMat(int size);
        SquareMat(const SquareMat& other); // copy constructor
        SquareMat& operator=(const SquareMat& other); // copy assignment
        ~SquareMat(); // destructor

        // פונקציות עזר
        void print() const;
        int getSize() const;

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
        RowProxy operator[](int row);
        const RowProxy operator[](int row) const;
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
