#include "Triad.h"

int main() {
    int size;
    Triad** data = readDataFromFile("data.txt", size);

    if (!data) return 1;

    std::cout << "Дані після зчитування:\n";
    for (int i = 0; i < size; i++) {
        data[i]->print();
    }

    int targetDay, targetMonth, targetYear;
    std::cout << "\nВведіть цільову дату (день місяць рік): ";
    std::cin >> targetDay >> targetMonth >> targetYear;

    Triad* closest = findClosestDate(data, size, targetDay, targetMonth, targetYear);

    std::cout << "\nНайближча дата до " << targetDay << "/" << targetMonth << "/" << targetYear << ":\n";
    if (closest) closest->print();
    else std::cout << "Не знайдено відповідної дати.\n";

    deleteArray(data, size);

    return 0;
}