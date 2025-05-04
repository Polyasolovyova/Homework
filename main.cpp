#include <iostream>
#include "Planner.h"

using namespace std;

int main() {
    Planner app;
    app.importFromFile("notes.txt");

    int cmd;
    do {
        cout << "\n=== Меню ===\n"
             << "1. Створити нотатку\n"
             << "2. Позначити як виконану\n"
             << "3. Переглянути список\n"
             << "4. Змінити нотатку\n"
             << "5. Зберегти у файл\n"
             << "0. Завершити програму\n"
             << "Ваш вибір: ";
        cin >> cmd;
        cin.ignore();

        if (cmd == 1) {
            string name, info;
            int lvl;
            cout << "Назва: "; getline(cin, name);
            cout << "Опис: "; getline(cin, info);
            cout << "Рівень важливості (1 - терміновий, 2 - звичайний, 3 - додатковий): ";
            cin >> lvl;
            cin.ignore();
            app.createNote(name, info, levelFromInput(lvl));
        } else if (cmd == 2) {
            app.markAsDone();
        } else if (cmd == 3) {
            app.listNotes();
        } else if (cmd == 4) {
            int id;
            cout << "Номер нотатки (починаючи з 0): ";
            cin >> id;
            cin.ignore();
            app.modifyNote(id);
        } else if (cmd == 5) {
            app.exportToFile("notes.txt");
        }

    } while (cmd != 0);

    app.exportToFile("notes.txt");
    return 0;
}
