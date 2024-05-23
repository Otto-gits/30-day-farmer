#include "Leaderboard.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Constructor: initializes the Leaderboard with a filename to load/save data
Leaderboard::Leaderboard(const std::string& filename) : filename(filename) {}

// Loads the leaderboard data from the file
void Leaderboard::load() {
    std::ifstream file(filename); // Open the file for reading
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    entries.clear(); // Clear existing entries

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }
        size_t pos = line.find(','); // Find the comma separating name and score
        if (pos != std::string::npos) {
            std::string name = line.substr(0, pos); // Extract name
            int score = std::stoi(line.substr(pos + 1)); // Extract score and convert to int
            entries.push_back({name, score}); // Add entry to the list
        }
    }

    file.close(); // Close the file
}

// Saves the leaderboard data to the file
void Leaderboard::save() {
    std::ofstream file(filename); // Open the file for writing
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    for (const auto& entry : entries) {
        file << entry.name << "," << entry.score << std::endl; // Write each entry to the file
    }

    file.close(); // Close the file
}

// Adds a new entry to the leaderboard and sorts the list
void Leaderboard::addEntry(const std::string& name, int score) {
    entries.push_back({name, score}); // Add the new entry
    std::sort(entries.begin(), entries.end()); // Sort the entries
}

// Displays the leaderboard entries to the console
void Leaderboard::display() const {
    for (const auto& entry : entries) {
        std::cout << entry.name << " - " << entry.score << std::endl; // Print each entry
    }
}
