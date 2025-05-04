#pragma once
#include <string>
#include <queue>
#include <vector>

enum class Level { URGENT, NORMAL, OPTIONAL };

struct Note {
    std::string name;
    std::string info;
    Level level;
};

class Planner {
public:
    void createNote(const std::string& name, const std::string& info, Level level);
    void markAsDone();
    void listNotes() const;
    void modifyNote(int id);
    void exportToFile(const std::string& filename) const;
    void importFromFile(const std::string& filename);
private:
    std::queue<Note> urgent;
    std::queue<Note> normal;
    std::queue<Note> optional;
    std::vector<Note> storage;
    void printQueue(std::queue<Note> q) const;
    std::string levelToString(Level l) const;
};

Level levelFromInput(int input);
Level levelFromString(const std::string& str);
