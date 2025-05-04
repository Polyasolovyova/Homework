#include <iostream>
#include <ctime>
#include "function.h"
using namespace std;

int main() {
    vector<vector<int> > matrix;
    vector<int> vval, vpos, vptr;
    int rows, cols;

    srand((unsigned int)time(0));

    int choice;
    cout << "Choose matrix input method:\n";
    cout << "1 - Enter sparse matrix manually (vval, vpos, vptr)\n";
    cout << "2 - Read matrix from file (supports both full and sparse)\n";
    cout << "3 - Enter full matrix manually\n";
    cout << "4 - Generate random matrix.\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        readSparseManualDirect(vval, vpos, vptr, rows, cols);
        sparseToFullMatrix(vval, vpos, vptr, rows, cols, matrix);
    } else {
        if (choice == 2) {
            readMatrixFromFile("matrix.txt", matrix, rows, cols);
        } else if (choice == 3) {
            readFullMatrixManual(matrix, rows, cols);
        } else if (choice == 4) {
            cout << "Enter number of rows and columns: ";
            cin >> rows >> cols;
            generateRandomMatrix(matrix, rows, cols);
        } else {
            cout << "Invalid choice.\n";
            return 1;
        }
        convertToSparse(matrix, vval, vpos, vptr);
    }

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrix);

    cout << "\nSparse representation:\n";
    printVector("vval", vval);
    printVector("vpos", vpos);
    printVector("vptr", vptr);

    int num;
    cout << "\nEnter number to subtract from diagonal: ";
    cin >> num;

    subtractFromDiagonalSparse(vval, vpos, vptr, rows, cols, num);

    cout << "\nUpdated sparse representation:\n";
    printVector("vval", vval);
    printVector("vpos", vpos);
    printVector("vptr", vptr);

    sparseToFullMatrix(vval, vpos, vptr, rows, cols, matrix);
    cout << "\nMatrix after subtracting from diagonal:\n";
    printMatrix(matrix);

    return 0;
}
