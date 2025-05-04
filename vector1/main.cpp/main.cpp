#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел

    std::vector<int> random_vector(100);

    // Заповнення вектора випадковими числами від 0 до 100
    for (int& num : random_vector) {
        num = std::rand() % 101;
    }

    // Виведення вектора
    std::cout << "Випадковий вектор з 100 елементів:\n";
    for (int num : random_vector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}