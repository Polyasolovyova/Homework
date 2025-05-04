#include "Container.h"
#include "Numberitem.h"
#include <iostream>

using namespace std;

void menu() {
    cout << "\nMENU:\n";
    cout << "1. Add number\n";
    cout << "2. Insert number at index\n";
    cout << "3. Remove number\n";
    cout << "4. Display all numbers\n";
    cout << "5. Display one number\n";
    cout << "6. Clear container\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Container container;
    int choice, index, value;

    while (true) {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter number: ";
            cin >> value;
            container.add(new NumberItem(value));
            break;
        case 2:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter number: ";
            cin >> value;
            container.insert(index, new NumberItem(value));
            break;
        case 3:
            cout << "Enter index: ";
            cin >> index;
            container.remove(index);
            break;
        case 4:
            container.display_all();
            break;
        case 5:
            cout << "Enter index: ";
            cin >> index;
            container.display_one(index);
            break;
        case 6:
            container.clear();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
