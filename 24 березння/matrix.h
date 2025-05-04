#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

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

bool inputFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу: " << filename << endl;
        return false;
    }

    string type;
    bool found = false;
    
    while (file >> type) { // Читаємо тип матриці
        if (type != "int" && type != "double" && type != "char") {
            cerr << "Помилка! Невідомий тип у файлі: " << type << endl;
            continue;
        }

        int fileRows, fileCols;
        if (!(file >> fileRows >> fileCols)) {
            cerr << "Помилка читання розмірів матриці з файлу.\n";
            break;
        }

        cout << "Знайдено у файлі: тип " << type << ", розміри " << fileRows << "x" << fileCols << endl;

        if (fileRows == rows && fileCols == cols) { // Якщо розміри збігаються
            found = true;
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++) {
                    if (!(file >> data[i][j])) {
                        cerr << "Помилка читання елемента матриці з файлу.\n";
                        return false;
                    }
                }
            break;
        } else {
            // Пропустити непідходящу матрицю
            string temp;
            for (int i = 0; i < fileRows; i++)
                for (int j = 0; j < fileCols; j++)
                    file >> temp;
        }
    }

    file.close();

    if (!found) {
        cerr << "Помилка! Не знайдено відповідної матриці у файлі.\n";
        return false;
    }

    return true;
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

// Спеціалізація для int
template <>
void Matrix<int>::fillRandom() {
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = rand() % 100;
}

// Спеціалізація для double
template <>
void Matrix<double>::fillRandom() {
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = (rand() % 10000) / 100.0;
}

// Спеціалізація для char
template <>
void Matrix<char>::fillRandom() {
    srand(time(0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = rand() % 26 + 'A';
}

#endif // MATRIX_H