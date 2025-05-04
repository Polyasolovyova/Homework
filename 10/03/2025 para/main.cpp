#include <iostream>
#include "stack.h"

int main() {
    int size;
    std::cout << "Введіть розмір стеку: ";
    std::cin >> size;

    Stack stack(size);
    int choice, value;

    while (true) {
        std::cout << "\n1. Додати (push)\n2. Видалити (pop)\n3. Показати верхній (top)\n4. Розмір (size)\n5. Чи порожній?\n6. Чи повний?\n7. Вийти\nВаш вибір: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Введіть число: ";
            std::cin >> value;
            stack.push(value);
        } 
        else if (choice == 2) {
            stack.pop();
        } 
        else if (choice == 3) {
            std::cout << "Верхній елемент: " << stack.top() << "\n";
        } 
        else if (choice == 4) {
            std::cout << "Розмір стеку: " << stack.size() << "\n";
        } 
        else if (choice == 5) {
            std::cout << (stack.empty() ? "Стек порожній\n" : "Стек НЕ порожній\n");
        } 
        else if (choice == 6) {
            std::cout << (stack.full() ? "Стек повний\n" : "Стек НЕ повний\n");
        } 
        else if (choice == 7) {
            break;
        } 
        else {
            std::cout << "Невірний вибір!\n";
        }
    }

    return 0;
}

