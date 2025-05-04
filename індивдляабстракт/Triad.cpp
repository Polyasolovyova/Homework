#include "Triad.h"

void Triad::print() const {
    std::cout << a << "/" << b << "/" << c << std::endl;
}

void Date::increment() {
    a++;  
}

void Date::decrement() {
    a--;  
}

Triad** readDataFromFile(const std::string& filename, int& size) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Помилка відкриття файлу!\n";
        size = 0;
        return nullptr;
    }

    size = 0;
    int x, y, z;
    Triad** data = new Triad*[100];  // Динамічний масив

    while (file >> x >> y >> z) {
        data[size] = new Date(x, y, z);
        size++;
    }

    return data;
}

int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    return (y2 - y1) * 365 + (m2 - m1) * 30 + (d2 - d1);
}

Triad* findClosestDate(Triad** data, int size, int targetDay, int targetMonth, int targetYear) {
    Triad* closest = nullptr;
    int minDiff = 999999;

    for (int i = 0; i < size; i++) {
        Date* date = static_cast<Date*>(data[i]);
        int diff = dateDifference(date->getA(), date->getB(), date->getC(), targetDay, targetMonth, targetYear);
        if (diff < 0) diff = -diff;
        if (diff < minDiff) {
            minDiff = diff;
            closest = date;
        }
    }
    return closest;
}

void deleteArray(Triad** data, int size) {
    for (int i = 0; i < size; i++) {
        delete data[i];
    }
    delete[] data;
}