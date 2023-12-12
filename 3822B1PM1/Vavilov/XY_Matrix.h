#pragma once
#include "Dynamic_Matrix.h"

template<typename T>
struct MartixElem {
    int row;
    int col;
    T val;
    MartixElem() {
        row = 0;
        col = 0;
        val = 0;
    }
    MartixElem(int _row, int _col, const T& _val) :  row(_row), col(_col), val(_val) {}
    MartixElem(const MartixElem& str) {
        row = str.row;
        col = str.col;
        val = str.val;
    }
};


template<typename T>
class XY_Matrix {
protected:
    int n;
   TDynamicVector<MartixElem<T>> v;
public:

    XY_Matrix(int dim = 1) : n(dim), v(n* n) {
        if (n <= 0 || n > MAX_MATRIX_SIZE)
            throw out_of_range("Matrix dimension out of range");
    }

    XY_Matrix(const  XY_Matrix& matrix) : n(matrix.n), v(matrix.v) {};


    XY_Matrix(XY_Matrix&& matrix) noexcept : n(1), v(move(matrix.v)) {
        swap(n, matrix.n);
    }


    ~XY_Matrix() = default;

    void set(int row, int col, T val) {
        if (row < 0 || row >= n || col < 0 || col >= n) {
            throw out_of_range("Matrix index out of range");
        }
        int id= row * n + col;
        v[id] = { row, col, val };
    }


    T get(int row, int col) const {
        if (row < 0 || row >= n || col < 0 || col >= n) {
            throw out_of_range("Matrix index out of range");
        }
        int id = row * n + col;
        return v[id].val;
    }

    void remove(int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n) {
            throw out_of_range("Matrix index out of range");
        }

        int id = row * n + col;
        v[id].val = 0;
    }



    XY_Matrix& operator=(const XY_Matrix& matrix) {
        if (this == &matrix)
            return *this;
        if (n != matrix.n) {
            n = matrix.n;
            v = matrix.v;
        }
        v = matrix.v;
        return *this;
    }


    XY_Matrix operator*(XY_Matrix& matrix) {
        if (n != matrix.n) {
            throw "Matrices dimensions are different ";
        }
        XY_Matrix<T> res(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                T tmp = 0;
                for (int k = 0; k < n; k++)
                    tmp += get(i, k) * matrix.get(k, j);
                res.set(i, j, tmp);
            }
        return res;
    }



    friend ostream& operator<<(ostream& os, const XY_Matrix& matrix) {
        for (int i = 0; i < matrix.n; i++) {
            for (int j = 0; j < matrix.n; j++) {
                os << matrix.get(i, j) << " ";
            }
            os << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& istr, XY_Matrix& matrix)
    {
        for (int i = 0; i < matrix.n; i++)
            for (int j = 0; j < matrix.n; j++) {
                T value;
                istr >> value;
                matrix.set(i, j, value);
            }
        return istr;
    }

  
};
