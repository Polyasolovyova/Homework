#pragma once
#include "Base.h"

class Derived1 : public Base {
private:
    int value;
public:
    Derived1(int v);
    void display() const override;
};