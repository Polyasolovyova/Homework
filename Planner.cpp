#include "Planner.h"
#include <iostream>
#include <fstream>

using namespace std;

void Planner::createNote(const string& name, const string& info, Level level) {
    Note n{ name, info, level };
    storage.push_back(n);
    switch (level) {
        case Level::URGENT: urgent.push(n); break;
        case Level::NORMAL: normal.push(n); break;
        case Level::OPTIONAL: optional.push(n); break;
    }
}

void Planner::markAsDone() {
    if (!urgent.empty()) {
        cout << "Виконано: " << urgent.front().name << endl;
        urgent.pop();
    } else if (!normal.empty()) {
        cout << "Виконано: " << normal.front().name << endl;
        normal.pop();
    } else if (!optional.empty()) {
        cout << "Виконано: " << optional.front().name << endl;
        optional.pop();
    } else {
        cout << "Жодних нотаток не знайдено.\n";
    }
}

void Planner::listNotes() const {
    cout << "\n[!] Термінові:\n";
    printQueue(urgent);
    cout << "\n[~] Поточні:\n";
    printQueue(normal);
    cout << "\n[-] Додаткові:\n";
    printQueue(optional);
}

void Planner::printQueue(queue<Note> q) const {
    int i = 1;
    while (!q.empty()) {
        const Note& n = q.front();
        cout << i++ << ") " << n.name << " — " << n.info << endl;
        q.pop();
    }
}

void Planner::modifyNote(int id) {
    if (id < 0 || id >= storage.size()) {
        cout << "Невірний номер нотатки.\n";
        return;
    }

    Note& note = storage[id];

    cout << "Редагування \"" << note.name << "\"\n";
    cout << "Нова назва (залиш порожньо, щоб не змінювати): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) note.name = newName;

    cout << "Новий опис (залиш порожньо, щоб не змінювати): ";
    string newInfo;
    getline(cin, newInfo);
    if (!newInfo.empty()) note.info = newInfo;

    cout << "Новий рівень важливості (1 - терміновий, 2 - звичайний, 3 - додатковий, 0 - без змін): ";
    int levelInput;
    cin >> levelInput;
    cin.ignore();
    if (levelInput >= 1 && levelInput <= 3) {
        note.level = levelFromInput(levelInput);
    }

    cout << "Нотатку оновлено.\n";
}

void Planner::exportToFile(const string& filename) const {
    ofstream file(filename);
    for (const auto& n : storage) {
        file << levelToString(n.level) << '\n'
             << n.name << '\n'
             << n.info << '\n';
    }
    cout << "Дані записано у файл.\n";
}

void Planner::importFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;
    string lvl, name, info;
    while (getline(file, lvl) && getline(file, name) && getline(file, info)) {
        createNote(name, info, levelFromString(lvl));
    }
}

string Planner::levelToString(Level l) const {
    switch (l) {
        case Level::URGENT: return "URGENT";
        case Level::NORMAL: return "NORMAL";
        case Level::OPTIONAL: return "OPTIONAL";
    }
    return "";
}

Level levelFromInput(int input) {
    switch (input) {
        case 1: return Level::URGENT;
        case 2: return Level::NORMAL;
        default: return Level::OPTIONAL;
    }
}

Level levelFromString(const string& str) {
    if (str == "URGENT") return Level::URGENT;
    if (str == "NORMAL") return Level::NORMAL;
    return Level::OPTIONAL;
}
