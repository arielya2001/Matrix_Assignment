#include "SquareMat.h"
#include <stdexcept>
#include <cmath>

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
    double SquareMat::sum() const {
        double total = 0;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                total += data[i][j];
        return total;
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
    SquareMat SquareMat::operator%(int num) const {
        if (num == 0) {
            throw std::invalid_argument("Cannot perform modulo by zero.");
        }

        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = std::fmod(data[i][j],num);
            }
        }
        return result;
    }
    SquareMat SquareMat::operator/(double num) const {
        if (num == 0) {
            throw std::invalid_argument("Cannot perform div by zero.");
        }

        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] / num;
            }
        }

        return result;
    }
    SquareMat SquareMat::operator^(int power) const {
        if (power < 0) {
            throw std::invalid_argument("Negative powers not supported.");
        }

        SquareMat result(size);

        for (int i = 0; i < size; ++i)
            result.data[i][i] = 1;

        SquareMat base = *this;
        for (int p = 0; p < power; ++p) {
            result = result * base;
        }

        return result;
    }
    SquareMat& SquareMat::operator++() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] += 1;
        return *this;
    }
    SquareMat& SquareMat::operator--() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] -= 1;
        return *this;
    }
    SquareMat SquareMat::operator++(int) {
        SquareMat temp = *this;
        ++(*this);
        return temp;
    }
    SquareMat SquareMat::operator--(int) {
        SquareMat temp = *this;
        --(*this);
        return temp;
    }
    SquareMat SquareMat::operator~() const{
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }
    double* SquareMat::operator[](int i) {
        if (i < 0 || i >= size)
            throw std::out_of_range("Row index out of range.");
        return data[i];
    }
    const double* SquareMat::operator[](int i) const {
        if (i < 0 || i >= size)
            throw std::out_of_range("Row index out of range.");
        return data[i];
    }
    bool SquareMat::operator==(const SquareMat& other) const {
        return size == other.size && sum() == other.sum();
    }

    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }
    bool SquareMat::operator>(const SquareMat& other) const {
        return size == other.size && sum() > other.sum();
    }

    bool SquareMat::operator>=(const SquareMat& other) const {
        return size == other.size && sum() >= other.sum();
    }

    bool SquareMat::operator<(const SquareMat& other) const {
        return size == other.size && sum() < other.sum();
    }

    bool SquareMat::operator<=(const SquareMat& other) const {
        return size == other.size && sum() <= other.sum();
    }
    double SquareMat::operator!() const {
        if (size == 1) {
            return data[0][0];
        }

        if (size == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }

        double det = 0;

        for (int j = 0; j < size; ++j) {
            SquareMat minor(size - 1);

            int minor_row = 0;
            for (int i = 1; i < size; ++i) {
                int minor_col = 0;
                for (int k = 0; k < size; ++k) {
                    if (k == j) continue;
                    minor[minor_row][minor_col] = data[i][k];
                    ++minor_col;
                }
                ++minor_row;
            }
            //sign
            double sign;
            if (j % 2 == 0)
                sign = 1.0;
            else
                sign = -1.0;

            //recursive
            det += sign * data[0][j] * !minor;
        }

        return det;
    }
    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Cannot add matrices of different sizes.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] += other.data[i][j];

        return *this;
    }
    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Cannot subtract matrices of different sizes.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] -= other.data[i][j];

        return *this;
    }
    SquareMat& SquareMat::operator*=(double num) {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] *= num;

        return *this;
    }
    SquareMat& SquareMat::operator/=(double num) {
        if (num == 0)
            throw std::invalid_argument("Cannot divide by zero.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] /= num;

        return *this;
    }
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes must match for multiplication.");

        *this = *this * other;
        return *this;
    }


    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Cannot perform element-wise modulo on matrices of different sizes.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                this->data[i][j] *= other.data[i][j];
        return *this;
    }
    SquareMat& SquareMat::operator%=(int num) {
        if (num == 0)
            throw std::invalid_argument("Cannot perform modulo by zero.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] = std::fmod(data[i][j],num);

        return *this;
    }


















}
