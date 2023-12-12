
#include "Dynamic_Matrix.h"
#include "Flat_Matrix.h"
#include "XY_Matrix.h"
#include "CRS_Matrix.h"
#include <chrono>
#include <vector>
using namespace chrono;


vector<vector<int>> generateBinaryMatrix(int n) {
   vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 2;  // Генерация случайных значений 0 или 1
        }
    }

    return matrix;
}

// Функция для вывода матрицы в консоль
void printMatrix(const vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout <<endl;
    }
}

int main()
{
    
    int n = 100;

    // Генерация матрицы
    vector<vector<int>> binaryMatrix = generateBinaryMatrix(n);

    // Вывод матрицы в консоль
    printMatrix(binaryMatrix);
    cout << endl << endl << endl << endl;

 
   
   TDynamicMatrix<double> a(n);
   cin >> a;
   cout << a<<endl;
   auto start_1 = steady_clock::now();
    a * a;
   auto end_1 = steady_clock::now();
   auto elapsed_1 = duration_cast<nanoseconds>(end_1 - start_1);
   cout << elapsed_1.count() << " nanoseconds " << endl;
   cout << endl << endl << endl << endl;

   FlatMatrix<double> b(n);
   cin >> b;
   cout << b << endl;
   auto start_2 = steady_clock::now();
   b* b;
   auto end_2 = steady_clock::now();
   auto elapsed_2 = duration_cast<nanoseconds>(end_2 - start_2);
   cout << elapsed_2.count() << " nanoseconds " << endl;
   cout << endl << endl << endl << endl;

   XY_Matrix<double> c(n);
   cin >> c;
   cout << c << endl;
   auto start_3 = steady_clock::now();
   c * c;
   auto end_3 = steady_clock::now();
   auto elapsed_3 = duration_cast<nanoseconds>(end_3 - start_3);
   cout << elapsed_3.count() << " nanoseconds " << endl;
   cout << endl << endl << endl << endl;


    
 

   

    //XY_Matrix<int> a(2);
   // a.set(0, 0, 1);
   // a.set(1, 0, 1);
   // a.set(0, 1, 1);
  //  a.set(1, 1, 1);

  //  cout << a;

   
}

