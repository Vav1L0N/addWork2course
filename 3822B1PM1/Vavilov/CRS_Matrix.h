#pragma once
#include "Dynamic_Matrix.h"

template<typename T>
class CRS_Matrix {
private:
    int n;
    TDynamicVector<T> val;
    TDynamicVector<int> col;
    TDynamicVector<int> row_id;
public:

    CRS_Matrix() : n(1) {};

    CRS_Matrix(int _n, TDynamicVector<T> _val, TDynamicVector<int> _col, TDynamicVector<int> _row_id) :n(_n), val(_val), col(_col), row_id(_row_id) {};

    CRS_Matrix(int dim = 1) : n(dim) {
        if (n <= 0 || n > MAX_MATRIX_SIZE)
            throw out_of_range("Matrix dimension out of range");
        TDynamicVector<int> a(n);
        row_id = a;
    };


    CRS_Matrix(const CRS_Matrix& matrix) : n(matrix.n) {
        
        val = matrix.val;
        col = matrix.col;
        row_id = matrix.row_id;
    }

    ~CRS_Matrix() = default;

    CRS_Matrix& operator=(const CRS_Matrix& matrix) {
        n = matrix.n;
        val = matrix.val;
        col = matrix.col;
        row_id = matrix.row_id;
        return *this;
    }




    friend ostream& operator<<(ostream& os, const CRS_Matrix<T>& matrix) {
        int currentValIndex = 0;
        for (int row = 0; row < matrix.n; row++) {
            for (int col = 0; col < matrix.n; col++) {
                if (currentValIndex < matrix.row_id[row + 1] && matrix.col[currentValIndex] == col) {
                    os << matrix.val[currentValIndex] << " ";
                    currentValIndex++;
                }
                else {
                    os << "0 ";
                }
            }
            os << endl;
        }

        return os;
    }



};