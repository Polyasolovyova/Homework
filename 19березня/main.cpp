#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void rotateMatrix(T** matrix, int n) {
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            T temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

template <typename T>
void printMatrix(T** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int** intMatrix = new int*[n];
    double** doubleMatrix = new double*[n];
    char** charMatrix = new char*[n];

    for (int i = 0; i < n; ++i) {
        intMatrix[i] = new int[n];
        doubleMatrix[i] = new double[n];
        charMatrix[i] = new char[n];
        for (int j = 0; j < n; ++j) {
            intMatrix[i][j] = rand() % 100; 
            doubleMatrix[i][j] = (rand() % 1000) / 10.0; 
            charMatrix[i][j] = 'A' + (rand() % 26); 
        }
    }

    cout << "Original Integer Matrix:\n";
    printMatrix(intMatrix, n);
    rotateMatrix(intMatrix, n);
    cout << "Rotated Integer Matrix:\n";
    printMatrix(intMatrix, n);

    cout << "\nOriginal Double Matrix:\n";
    printMatrix(doubleMatrix, n);
    rotateMatrix(doubleMatrix, n);
    cout << "Rotated Double Matrix:\n";
    printMatrix(doubleMatrix, n);

    cout << "\nOriginal Char Matrix:\n";
    printMatrix(charMatrix, n);
    rotateMatrix(charMatrix, n);
    cout << "Rotated Char Matrix:\n";
    printMatrix(charMatrix, n);

    for (int i = 0; i < n; ++i) {
        delete[] intMatrix[i];
        delete[] doubleMatrix[i];
        delete[] charMatrix[i];
    }
    delete[] intMatrix;
    delete[] doubleMatrix;
    delete[] charMatrix;

    return 0;
}