#include "Derived1.h"
#include <iostream>

Derived1::Derived1(int v) : value(v) {}
void Derived1::display() const {
    cout << "Derived1: " << value << endl;
}