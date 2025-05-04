#pragma once
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() const = 0;
    virtual ~Base() {}
};
