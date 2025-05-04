#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <type_traits>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <typeinfo>

using namespace std;

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols]();
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    void inputManual() {
        cout << "Введіть елементи матриці (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    #include <type_traits> 

bool inputFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу!\n";
        return false;
    }

    string type;
    string expectedType;
    
    // Визначаємо, який тип матриці ми шукаємо
    if (is_same<T, int>::value) expectedType = "int";
    else if (is_same<T, double>::value) expectedType = "double";
    else if (is_same<T, char>::value) expectedType = "char";

    while (file >> type) { 
        
        if (type == expectedType) {
            int fileRows, fileCols;
            file >> fileRows >> fileCols;

            if (fileRows == rows && fileCols == cols) { 
                
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++)
                        file >> data[i][j];
                file.close();
                return true;
            } else {
                
                for (int i = 0; i < fileRows; i++)
                    for (int j = 0; j < fileCols; j++) {
                        string temp;
                        file >> temp;
                    }
            }
        } else {
            
            string temp;
            getline(file, temp); 
        }
    }

    cerr << "Помилка! Не знайдено відповідної матриці у файлі.\n";
    file.close();
    return false;
}
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cerr << "Помилка! Неможливо помножити матриці\n";
            exit(1);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];

        return result;
    }

    double norm() const {
        double sum = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                sum += data[i][j] * data[i][j];

        return sqrt(sum);
    }

    T maxElement() const {
        T maxVal = data[0][0];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] > maxVal)
                    maxVal = data[i][j];

        return maxVal;
    }

    void fillRandom();
};

template <>
void Matrix<int>::fillRandom() {
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = rand() % 100;
}

template <>
void Matrix<double>::fillRandom() {
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = (rand() % 10000) / 100.0;
}

template <>
void Matrix<char>::fillRandom() {
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = rand() % 26 + 'A';
}

#endif // MATRIX_H

