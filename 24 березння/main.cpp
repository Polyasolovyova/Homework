#include "matrix.h"

void menu() {
    cout << "Оберіть операцію:\n"
         << "1. Множення двох матриць\n"
         << "2. Обчислення норми\n"
         << "3. Максимальний елемент\n"
         << "Ваш вибір: ";
}

void typeMenu() {
    cout << "Оберіть тип матриці:\n"
         << "1. int\n"
         << "2. double\n"
         << "3. char\n"
         << "Ваш вибір: ";
}

void inputMenu() {
    cout << "Оберіть спосіб заповнення:\n"
         << "1. З файлу\n"
         << "2. Випадкові значення\n"
         << "3. Вручну\n"
         << "Ваш вибір: ";
}

template <typename T>
void processMatrix(int rows, int cols, int inputMethod) {
    Matrix<T> A(rows, cols);

    if (inputMethod == 1) {
        string filename;
        cout << "Введіть назву файлу: ";
        cin >> filename;
        if (!A.inputFromFile(filename)) {
            cerr << "Помилка відкриття файлу!\n";
            return;
        }
    } else if (inputMethod == 2) {
        A.fillRandom();
    } else {
        A.inputManual();
    }

    cout << "Матриця A:\n";
    A.print();

    int choice;
    menu();
    cin >> choice;

    if (choice == 1) {
        Matrix<T> B(cols, rows);
        cout << "Введіть матрицю B:\n";
        B.inputManual();
        Matrix<T> C = A * B;
        cout << "Результат множення:\n";
        C.print();
    } else if (choice == 2) {
        cout << "Норма матриці: " << A.norm() << endl;
    } else if (choice == 3) {
        cout << "Максимальний елемент: " << A.maxElement() << endl;
    }
}

int main() {
    int typeChoice, rows, cols, inputChoice;

    typeMenu();
    cin >> typeChoice;

    cout << "Введіть розміри матриці (рядки, стовпці): ";
    cin >> rows >> cols;

    inputMenu();
    cin >> inputChoice;

    if (typeChoice == 1) {
        processMatrix<int>(rows, cols, inputChoice);
    } else if (typeChoice == 2) {
        processMatrix<double>(rows, cols, inputChoice);
    } else if (typeChoice == 3) {
        processMatrix<char>(rows, cols, inputChoice);
    } else {
        cout << "Невірний вибір типу!\n";
    }

    return 0;
}