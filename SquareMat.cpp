#include "SquareMat.h"
#include <stdexcept>

namespace matlib
{
    SquareMat::SquareMat(int size) : size(size) {
        if (size <= 0) throw std::invalid_argument("Matrix size must be positive.");
        data = new double*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new double[size];
            for (int j = 0; j < size; ++j)
                data[i][j] = 0.0;
        }
    }

    SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
        data = new double*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new double[size];
            for (int j = 0; j < size; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this == &other) return *this;
        // ניקוי קיים
        for (int i = 0; i < size; ++i)
            delete[] data[i];
        delete[] data;

        // העתקה
        size = other.size;
        data = new double*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new double[size];
            for (int j = 0; j < size; ++j)
                data[i][j] = other.data[i][j];
        }
        return *this;
    }

    SquareMat::~SquareMat() {
        for (int i = 0; i < size; ++i)
            delete[] data[i];
        delete[] data;
    }

    void SquareMat::print() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }

    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j)
                os << mat.data[i][j] << " ";
            os << std::endl;
        }
        return os;
    }

    //operators:
    SquareMat SquareMat::operator+(const SquareMat& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Cannot add matrices of different sizes.");
        }

        SquareMat result(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    SquareMat SquareMat::operator-(const SquareMat& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Cannot add matrices of different sizes.");
        }

        SquareMat result(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    SquareMat SquareMat::operator-() const {
        SquareMat result(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = -data[i][j];
            }
        }

        return result;
    }
    SquareMat SquareMat::operator*(const SquareMat& other) const {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes must match for multiplication.");

        SquareMat result(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < size; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    SquareMat SquareMat::operator*(const double num) const {
        SquareMat result(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] *num;
            }
        }

        return result;
    }
    SquareMat operator*(const double num, const SquareMat& mat) {
        return mat * num;
    }
    SquareMat SquareMat::operator%(const SquareMat& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Cannot mult matrices of different sizes.");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return result;
    }
    SquareMat SquareMat::operator%(int scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Cannot perform modulo by zero.");
        }

        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = static_cast<int>(data[i][j]) % scalar;
            }
        }

        return result;
    }


}
