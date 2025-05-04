#include "Container.h"
#include "Derived1.h"
#include "Derived2.h"
#include <iostream>
#include <string>

using namespace std;

void menu() {
    cout << "\nMENU:\n";
    cout << "1. Add element\n";
    cout << "2. Insert element at index\n";
    cout << "3. Remove element\n";
    cout << "4. Display all elements\n";
    cout << "5. Display one element\n";
    cout << "6. Clear container\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Container container;
    int choice, index, value;
    string text;
    
    while (true) {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter 1 for Derived1 or 2 for Derived2: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter value: ";
                cin >> value;
                container.add(new Derived1(value));
            } else {
                cout << "Enter text: ";
                cin >> text;
                container.add(new Derived2(text));
            }
            break;
        case 2:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter 1 for Derived1 or 2 for Derived2: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter value: ";
                cin >> value;
                container.insert(index, new Derived1(value));
            } else {
                cout << "Enter text: ";
                cin >> text;
                container.insert(index, new Derived2(text));
            }
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
