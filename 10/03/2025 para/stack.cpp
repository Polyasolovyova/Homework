#include <iostream>
#include "stack.h"

Stack::Stack(int size) {
    capacity = size > 0 ? size : 10; 
    data = new int[capacity];
    topIndex = -1;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(int value) {
    if (full()) {
        std::cout << "Стек повний! Не можна додати елемент.\n";
        return;
    }
    data[++topIndex] = value;
}

void Stack::pop() {
    if (empty()) {
        std::cout << "Стек порожній! Неможливо видалити елемент.\n";
        return;
    }
    topIndex--;
}

int Stack::top() {
    return empty() ? -1 : data[topIndex]; 
}

bool Stack::empty() {
    return topIndex == -1;
}

bool Stack::full() {
    return topIndex + 1 == capacity;
}

int Stack::size() {
    return topIndex + 1;
}
