#include "Crop.h"
#include <iostream>

int main() {
    Crop crop;

    char input;
    std::cout << "Press Enter to age the plant ('q' to quit): ";
    while ((input = std::cin.get()) != 'q') {
        if (input == '\n') {
            // Age the plant by one day
            crop.ageOneDay();

            // Print the updated age
            std::cout << "Plant age: " << crop.getAge() << std::endl;

            // Prompt for next action
            std::cout << "Press Enter to age the plant ('q' to quit): ";
        }
    }

    return 0;
}

