#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include <string>

struct LeaderboardEntry {
    std::string name;
    int score;

    // Overload the < operator for sorting
    bool operator<(const LeaderboardEntry& other) const {
        return score > other.score; // Sort in descending order
    }
};

class Leaderboard {
private:
    std::vector<LeaderboardEntry> entries;
    std::string filename;

public:
    Leaderboard(const std::string& filename);

    // Load leaderboard data from Excel file
    void load();

    // Save leaderboard data to Excel file
    void save();

    // Add a new entry to the leaderboard
    void addEntry(const std::string& name, int score);

    // Display the leaderboard
    void display() const;
};

#endif // LEADERBOARD_H