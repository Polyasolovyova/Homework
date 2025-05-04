#include <iostream>
#include "matrix.h"

using namespace std;

int main() {
    int rows, cols, choice1, choice2;
    string filename1, filename2;

    cout << "Виберіть тип матриці (1 - int, 2 - double, 3 - char): ";
    int type;
    cin >> type;

    cout << "Введіть розмірність матриці (рядки і стовпці): ";
    cin >> rows >> cols;

    // Запит для першої матриці
    cout << "Оберіть спосіб заповнення ПЕРШОЇ матриці (1 - з файлу, 2 - випадково, 3 - вручну): ";
    cin >> choice1;
    if (choice1 == 1) {
        if (type == 1) filename1 = "matrix_int.txt";
        else if (type == 2) filename1 = "matrix_double.txt";
        else filename1 = "matrix_char.txt";
    }

    // Запит для другої матриці
    cout << "Оберіть спосіб заповнення ДРУГОЇ матриці (1 - з файлу, 2 - випадково, 3 - вручну): ";
    cin >> choice2;
    if (choice2 == 1) {
        if (type == 1) filename2 = "matrix_int.txt";
        else if (type == 2) filename2 = "matrix_double.txt";
        else filename2 = "matrix_char.txt";
    }

    // Обробка типу матриці
    if (type == 1) {  // int
        Matrix<int> A(rows, cols), B(rows, cols);

        if (choice1 == 1) A = Matrix<int>(filename1);
        else if (choice1 == 2) A.fillRandom();
        else A.fillManual();

        if (choice2 == 1) B = Matrix<int>(filename2);
        else if (choice2 == 2) B.fillRandom();
        else B.fillManual();

        cout << "Перша матриця:\n"; A.print();
        cout << "Друга матриця:\n"; B.print();
        cout << "Добуток матриць:\n"; Matrix<int> C = A.multiply(B); C.print();
        cout << "Максимальний елемент добутку: " << C.maxElement() << endl;
        cout << "Норма добутку: " << C.norm() << endl;
    } 
    else if (type == 2) {  // double
        Matrix<double> A(rows, cols), B(rows, cols);

        if (choice1 == 1) A = Matrix<double>(filename1);
        else if (choice1 == 2) A.fillRandom();
        else A.fillManual();

        if (choice2 == 1) B = Matrix<double>(filename2);
        else if (choice2 == 2) B.fillRandom();
        else B.fillManual();

        cout << "Перша матриця:\n"; A.print();
        cout << "Друга матриця:\n"; B.print();
        cout << "Добуток матриць:\n"; Matrix<double> C = A.multiply(B); C.print();
        cout << "Максимальний елемент добутку: " << C.maxElement() << endl;
        cout << "Норма добутку: " << C.norm() << endl;
    } 
    else {  // char (без множення)
        Matrix<char> A(rows, cols), B(rows, cols);

        if (choice1 == 1) A = Matrix<char>(filename1);
        else if (choice1 == 2) A.fillRandom();
        else A.fillManual();

        if (choice2 == 1) B = Matrix<char>(filename2);
        else if (choice2 == 2) B.fillRandom();
        else B.fillManual();

        cout << "Матриця символів (перша):\n"; A.print();
        cout << "Матриця символів (друга):\n"; B.print();
        cout << "Максимальний символ в першій матриці: " << A.maxElement() << endl;
        cout << "Максимальний символ в другій матриці: " << B.maxElement() << endl;
    }

    return 0;
}