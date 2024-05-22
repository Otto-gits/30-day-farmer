#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <vector>
#include <utility>

class Leaderboard {
public:
    Leaderboard(); // Constructor

    void addEntry(const std::string& name, int score); // Add a new entry to the leaderboard
    void display() const; // Display the leaderboard

private:
    std::vector<std::pair<std::string, int>> entries; // Vector of pairs to store name-score pairs
};

#endif // LEADERBOARD_H
