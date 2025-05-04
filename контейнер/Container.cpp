#include "Container.h"
#include <iostream>

Container::Container() : size(0), capacity(2) {
    items = new Base*[capacity];
}

Container::~Container() {
    clear();
    delete[] items;
}

void Container::resize() {
    capacity++;
    Base** new_items = new Base*[capacity];
    for (int i = 0; i < size; i++) {
        new_items[i] = items[i];
    }
    delete[] items;
    items = new_items;
}

void Container::add(Base* obj) {
    if (size >= capacity) resize();
    items[size++] = obj;
}

void Container::insert(int index, Base* obj) {
    if (index < 0 || index > size) {
        cout << "Invalid index!" << endl;
        return;
    }
    if (size >= capacity) resize();
    for (int i = size; i > index; i--) {
        items[i] = items[i - 1];
    }
    items[index] = obj;
    size++;
}

void Container::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    delete items[index];
    for (int i = index; i < size - 1; i++) {
        items[i] = items[i + 1];
    }
    size--;
}

void Container::clear() {
    for (int i = 0; i < size; i++) {
        delete items[i];
    }
    size = 0;
}

void Container::display_all() const {
    if (size == 0) {
        cout << "No elements in the container!" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] ";
        items[i]->display();
    }
}

void Container::display_one(int index) const {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "[" << index << "] ";
    items[index]->display();
}