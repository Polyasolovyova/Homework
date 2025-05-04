#include "Numberitem.h"
#include <iostream>

NumberItem::NumberItem(int v) : value(v) {}

void NumberItem::display() const {
    cout << "Number: " << value << endl;
}
