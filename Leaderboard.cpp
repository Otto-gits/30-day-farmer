#include "Leaderboard.h"
#include <iostream>
#include <algorithm>

Leaderboard::Leaderboard() {}

void Leaderboard::addEntry(const std::string& name, int score) {
    entries.push_back(std::make_pair(name, score));
}


void Leaderboard::display() const {
    // Sort the entries based on the scores in descending order
    std::vector<std::pair<std::string, int>> sortedEntries = entries;
    std::sort(sortedEntries.begin(), sortedEntries.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Compare scores in descending order
    });

    // Display the sorted leaderboard
    std::cout << "Leaderboard:" << std::endl;
    for (const auto& entry : sortedEntries) {
        std::cout << "Name: " << entry.first << "    Moneys: " << entry.second << std::endl;
    }
}

