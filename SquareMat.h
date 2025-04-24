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
    };

}
