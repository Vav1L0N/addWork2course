#pragma once
#include "Dynamic_Matrix.h"


template<typename T>
class FlatMatrix {
protected:
    int n;
    TDynamicVector<T> v;
public:

    FlatMatrix(int dim = 1) : n(dim), v(n* n) {
        if (n <= 0 || n > MAX_MATRIX_SIZE)
            throw std::out_of_range("Matrix dimension out of range");
    }


    FlatMatrix(const FlatMatrix& matrix) : n(matrix.n), v(matrix.v) {};


    FlatMatrix(FlatMatrix&& matrix) noexcept : n(1), v(move(matrix.v)) {
        swap(n, matrix.n);
    }

    ~FlatMatrix() = default;

    T get(int i, int j) const {
        if (i < 0 || i >= n || j < 0 || j >= n)
            throw std::out_of_range("Matrix index out of range");
        return v[i * n + j];
    }

    void set(int i, int j, int val) {
        v[i * n + j] = val;
    }

    FlatMatrix& operator=(const FlatMatrix& matrix) {
        if (this == &matrix)
            return *this;
        if (n != matrix.n) {
            n = matrix.n;
            v = matrix.v;
        }
        v = matrix.v;
        return *this;
    }



    FlatMatrix operator*(FlatMatrix& matrix) {
        if (n != matrix.n) {
            throw "Matrices dimensions are different ";
        }
        FlatMatrix res(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                T tmp = 0;
                for (int k = 0; k < n; k++)
                    tmp += get(i, k) * matrix.get(k, j);
                res.set(i, j, tmp);
            }
        return res;
    }



    friend ostream& operator<<(ostream& ostr, const FlatMatrix& matrix) {
        for (int i = 0; i < matrix.n; i++) {
            for (int j = 0; j < matrix.n; j++) {
                ostr << matrix.get(i, j) << " ";
            }
            ostr << endl;
        }
        return ostr;
    }


    friend istream& operator>>(istream& istr, FlatMatrix& matrix)
    {
        for (int i = 0; i < matrix.n; i++)
            for (int j = 0; j < matrix.n; j++)
                istr >> matrix.v[i * matrix.n + j];
        return istr;
    }

};
