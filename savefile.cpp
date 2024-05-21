// #include <iostream>
// #include <fstream>

// #include "Farm.h" // Assuming Farm.h contains the declaration of Farm class

// using namespace std;

// // Overload the << operator for Farm class to enable output
// ostream& operator<<(ostream& os, const Farm& farm) {
//     // Output the farm's data to the ostream os
//     // Example: os << farm.getData();
//     return os;
// }

// // Overload the >> operator for Farm class to enable input
// istream& operator>>(istream& is, Farm& farm) {
//     // Input data from the istream is into the farm object
//     // Example: is >> farm.setData();
//     return is;
// }

// void saveState(const Farm& farm) {
//     ofstream file("state.txt");
//     if (file.is_open()) {
//         file << farm; // Output farm data to file
//         file.close();
//     } else {
//         cout << "Error: Unable to open file for writing." << endl;
//     }
// }

// void loadState(Farm& farm) {
//     ifstream file("state.txt");
//     if (file.is_open()) {
//         file >> farm; // Input farm data from file
//         file.close();
//     } else {
//         cout << "Error: Unable to open file for reading." << endl;
//     }
// }
