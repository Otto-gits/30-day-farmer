#include "Leaderboard.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Leaderboard::Leaderboard(const std::string& filename) : filename(filename) {}

void Leaderboard::load() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    entries.clear();

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            std::string name = line.substr(0, pos);
            int score = std::stoi(line.substr(pos + 1));
            entries.push_back({name, score});
        }
    }

    file.close();
}


void Leaderboard::save() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    for (const auto& entry : entries) {
        file << entry.name << "," << entry.score << std::endl;
    }

    file.close();
}

void Leaderboard::addEntry(const std::string& name, int score) {
    entries.push_back({name, score});
    std::sort(entries.begin(), entries.end());
}

void Leaderboard::display() const {
    for (const auto& entry : entries) {
        std::cout << entry.name << " - " << entry.score << std::endl;
    }
}