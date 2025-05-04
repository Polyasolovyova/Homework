#include "Derived2.h"
#include <iostream>

Derived2::Derived2(string t) : text(t) {}
void Derived2::display() const {
    cout << "Derived2: " << text << endl;
}