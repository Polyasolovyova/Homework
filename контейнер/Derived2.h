#pragma once
#include "Base.h"
#include <string>

class Derived2 : public Base {
private:
    string text;
public:
    Derived2(string t);
    void display() const override;
};