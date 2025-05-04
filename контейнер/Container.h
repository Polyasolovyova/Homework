#pragma once
#include "Base.h"

class Container {
private:
    Base** items;
    int size;
    int capacity;
    void resize();
public:
    Container();
    ~Container();
    void add(Base* obj);
    void insert(int index, Base* obj);
    void remove(int index);
    void clear();
    void display_all() const;
    void display_one(int index) const;
};
