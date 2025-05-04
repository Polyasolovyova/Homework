#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>
#include <fstream>

class Triad {
protected:
    int a, b, c;
public:
    Triad(int x, int y, int z) : a(x), b(y), c(z) {}
    virtual void increment() = 0;
    virtual void decrement() = 0;
    virtual void print() const;
    int getA() const { return a; }
    int getB() const { return b; }
    int getC() const { return c; }
};

class Date : public Triad {
public:
    Date(int day, int month, int year) : Triad(day, month, year) {}
    void increment() override;
    void decrement() override;
};

Triad** readDataFromFile(const std::string& filename, int& size);
Triad* findClosestDate(Triad** data, int size, int targetDay, int targetMonth, int targetYear);
void deleteArray(Triad** data, int size);

#endif 