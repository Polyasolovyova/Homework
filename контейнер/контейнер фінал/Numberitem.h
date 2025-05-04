#pragma once
#include "Base.h"

class NumberItem : public Base {
private:
    int value;
public:
    NumberItem(int v);
    void display() const override;
};
